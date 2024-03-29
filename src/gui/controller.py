from view import View
from model import Model
import subprocess


class Controller:

    def __init__(self):
        self.view = View(self)
        self.model = Model()
        pass

    def start_ide(self):
        self.view.start_ide()

    def check_dependencies(self):
        dependencies = ["interpreter.exe", "compiler.exe"]
        for dependency in dependencies:
            if not self.check_dependency(dependency):
                return

    def check_dependency(self, dependency):
        if not Model.file_exists(dependency):
            self.view.show_dependency_warning(dependency)
            return False
        return True

    def open_file(self, _=None):
        file_path = self.view.open_file_dialog()
        if file_path:
            self.model.set_file_from_path(file_path)
            self.view.clear_text()
            self.view.set_status_text(file_path)
            self.view.set_window_title(self.model.file_name)
            self.view.set_text(self.model.file_content)

    def new_file(self, _=None):
        self.model.clear_file()
        self.view.clear_text()
        self.view.set_window_title("New File")
        self.view.set_status_text("New File")

    def save_file(self, _=None):
        if self.model.file_path:
            self.model.save_file(self.view.get_text())
        else:
            file_path = self.view.save_file_dialog()
            if file_path:
                file_content = self.view.get_text()
                self.model.set_file(file_path, file_content)
                self.model.save_file(file_content)
                self.view.set_window_title(self.model.file_name)
            else:
                return False
            self.view.set_status_text(file_path+" (Saved Successfully)")
        return True

    def compile(self, _=None):
        # first check for compiler.exe
        if not self.check_dependency("compiler.exe"):
            return

        if self.save_file():
            process = subprocess.run(
                ["compiler.exe", self.model.file_path], capture_output=True, text=True)
            compiled_output = process.stdout
            err_output = Model.get_file_contents("errors.txt")
            output = "Compiled Output:\n\n" + compiled_output
            if err_output:
                output += "\n\nERRORS written to errors.txt:\n" + err_output
            else:
                output += "\n\nCompiled with no errors\n"
            self.view.set_output_text(output)

    def run(self, _=None):
        # first check for interpreter.exe
        if not self.check_dependency("interpreter.exe"):
            return

        if self.save_file():
            process = subprocess.run(
                ["interpreter.exe", self.model.file_path], capture_output=True, text=True)
            output = process.stdout
            self.view.set_output_text(output)


controller = Controller()
controller.start_ide()
