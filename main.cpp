#include <iostream>

#include "Factory.h"
#include "Editor.h"

Editor graphic_editor;

void menu() {
    std::cout << "menu" << std::endl;
    std::cout << "create_doc" << std::endl;
    std::cout << "load_doc" << std::endl;
    std::cout << "save_doc" << std::endl;
    std::cout << "add_figure" << std::endl;
    std::cout << "remove_figure" << std::endl;
    std::cout << "print_doc" << std::endl;
    std::cout << "undo" << std::endl;
    std::cout << "exit" << std::endl;
}

void create() {
    std::string tmp;
    std::cout << "enter name of new document" << std::endl;
    std::cin >> tmp;
    graphic_editor.create_document(tmp);
    std::cout << "document create" << std::endl;
}

void load() {
    std::string tmp;
    std::cout << "enter path to the file" << std::endl;
    std::cin >> tmp;
    graphic_editor.load_document(tmp);
    std::cout << "document loaded" << std::endl;
}

void save() {
    std::string tmp;
    graphic_editor.save_document();
    std::cout << "save document" << std::endl;
}

void add() {
    std::shared_ptr<Figure> newElem = Factory::figure_create(std::cin);
    graphic_editor.insert_in_document(newElem);
    std::cout << "was added" << std::endl;
}

void remove() {
    size_t index;
    std::cout << "enter index" << std::endl;
    std::cin >> index;
    graphic_editor.delete_in_document(index);
    std::cout << "was removed" << std::endl;
}

int main() {
    std::string cmd;
    while (1) {
        std::cin >> cmd;
        if (cmd == "menu") {
            menu();
        }
        else if (cmd == "create_doc") {
            create();
        }
        else if (cmd == "load_doc") {
            load();
        }
        else if (cmd == "save_doc") {
            save();
        }
        else if (cmd == "exit") {
            break;
        }
        else if (cmd == "add_figure") {
            add();
        }
        else if (cmd == "remove_figure") {
            remove();
        }
        else if (cmd == "print_doc") {
            graphic_editor.print_document();
        }
        else if (cmd == "undo") {
            graphic_editor.undo();
        }
        else {
            std::cout << "unknown cmd" << std::endl;
        }
    }
    return 0;
}
