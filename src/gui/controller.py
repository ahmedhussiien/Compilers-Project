from view import View
from model import Model


class Controller:

    def __init__(self):
        self.view = View(self)
        self.model = Model()
        pass

    def start_ide(self):
        self.view.start_ide()

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
                return
            self.view.set_status_text(file_path+"(Saved Successfully)")


controller = Controller()
controller.start_ide()