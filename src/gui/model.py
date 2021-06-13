import os


class Model:

    def __init__(self) -> None:
        self.clear_file()

    def set_file(self, file_path, file_content):
        self.file_path = file_path
        self.file_content = file_content
        self.file_name = os.path.basename(self.file_path)

    def set_file_from_path(self, file_path):
        self.file_path = file_path
        file = open(self.file_path, mode='r')
        self.file_content = file.read()
        self.file_name = os.path.basename(self.file_path)
        file.close()

    def save_file(self, content):
        file = open(self.file_path, mode='w')
        file.write(content)
        file.close()

    def clear_file(self):
        self.file_path = None
        self.file_content = None
        self.file_name = None

    def file_exists(file_name):
        return os.path.isfile(file_name)
