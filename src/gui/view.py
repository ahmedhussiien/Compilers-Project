from tkinter import *
from tkinter import filedialog
from tkinter.scrolledtext import ScrolledText
from tkinter.filedialog import *
from tkinter.messagebox import *


class View:
    PROGRAM_NAME = "Compilers IDE"

    def __init__(self, controller):
        self.controller = controller

        # create the window
        self.window = Tk()
        self.set_window_title("New File")
        self.window.geometry("1000x600")
        self.window.resizable(False, False)

        # create top menus
        self.__create_menu()

        # create text editing area
        self.text_area = ScrolledText(
            self.window, background='#1B1B1B',
            foreground="white", insertbackground="white", padx=20,
            undo=True, wrap="none")
        self.text_area.pack(fill="x")

        # add label to output text area
        Label(text="OUTPUT", bg="#131313", anchor=W, pady=10, padx=15,
              foreground="white").pack(fill="x")

        # add output text widget
        self.output_text_area = ScrolledText(
            self.window, background='#131313', height=9,
            foreground="white", insertbackground="white", state=DISABLED, padx=20)
        self.output_text_area.pack(fill="x")

        # create status bar
        self.status_bar = Label(
            text="READY", foreground="white", anchor=E, bg='#0078CF', padx=20)
        self.status_bar.pack(fill="both", expand=True)

        # set shortcut bindings
        self.text_area.bind('<Control-N>', self.controller.new_file)
        self.text_area.bind('<Control-O>', self.controller.open_file)
        self.text_area.bind('<Control-S>', self.controller.save_file)
        self.text_area.bind('<Control-n>', self.controller.new_file)
        self.text_area.bind('<Control-o>', self.controller.open_file)
        self.text_area.bind('<Control-s>', self.controller.save_file)
        self.text_area.bind('<Control-Key-6>', self.controller.compile)
        self.text_area.bind('<Control-Key-5>', self.controller.run)
        self.text_area.bind('<Control-slash>', self.toggle_comment)

    def start_ide(self):
        # run the main loop of the window (start the window)
        self.window.mainloop()

    def show_dependency_warning(self, dependency):
        showwarning(
            "Warning", f"{dependency} is missing from current directory.")

    def toggle_comment(self, _=None):
        if self.text_area.get("insert linestart", "insert linestart + 2 chars") == "//":
            self.text_area.delete("insert linestart",
                                  "insert linestart + 2 chars")
        else:
            self.text_area.insert("insert linestart", "//")
        return "break"

    def __create_menu(self):
        menus = {
            "File": {
                "New (Ctrl + N)": self.controller.new_file,
                "Open (Ctrl + O)": self.controller.open_file,
                "Save (Ctrl + S)": self.controller.save_file,
                "Compile (Ctrl + 6)": self.controller.compile,
                "Run (Ctrl + 5)": self.controller.run,
                "": None,
                "Exit (Alt + f4)": self.window.quit
            },
            "Edit": {
                "Cut (Ctrl + X)": self.__cut_handler,
                "Copy (Ctrl + C)": self.__copy_handler,
                "Paste (Ctrl + V)": self.__paste_handler,
                "Comment/Uncomment line (Ctrl + /)": self.toggle_comment,
                "Undo (Ctrl + Z)": self.__undo_handler,
                "Redo (Ctrl + Y)": self.__redo_handler
            }
        }
        self.main_menu = Menu(self.window)
        self.window.config(menu=self.main_menu)
        for menu_label in menus:
            new_menu = Menu(self.main_menu, tearoff=False)
            self.main_menu.add_cascade(label=menu_label, menu=new_menu)
            for sub_item in menus[menu_label]:
                if sub_item == "":
                    new_menu.add_separator()
                else:
                    new_menu.add_command(
                        label=sub_item, command=menus[menu_label][sub_item])

    def __copy_handler(self):
        try:
            selection = self.text_area.selection_get()
            if selection:
                self.window.clipboard_clear()
                self.window.clipboard_append(selection)
        except:
            pass

    def __paste_handler(self):
        selection = self.window.clipboard_get()
        if selection:
            position = self.text_area.index(INSERT)
            self.text_area.insert(position, selection)

    def __cut_handler(self):
        self.__copy_handler()
        self.text_area.delete("sel.first", "sel.last")

    def __undo_handler(self):
        self.text_area.edit_undo()

    def __redo_handler(self):
        self.text_area.edit_redo()

    def clear_text(self):
        self.text_area.delete(1.0, END)
        self.output_text_area.delete(1.0, END)

    def set_window_title(self, title: str):
        self.window.title(f"{self.PROGRAM_NAME} - {title}")

    def set_status_text(self, text: str):
        self.status_bar.config(text=text)

    def open_file_dialog(self):
        return filedialog.askopenfilename(title="Open File", filetypes=[("Cpp Files", "*.cpp")])

    def set_text(self, content):
        self.text_area.insert(END, content)

    def get_text(self):
        return self.text_area.get(1.0, END)

    def save_file_dialog(self):
        return filedialog.asksaveasfilename(title="Save As", defaultextension=".cpp", filetypes=[("Cpp Files", "*.cpp")])

    def set_output_text(self, content):
        self.output_text_area.config(state=NORMAL)
        self.output_text_area.delete(1.0, END)
        self.output_text_area.insert(END, content)
        self.output_text_area.config(state=DISABLED)
