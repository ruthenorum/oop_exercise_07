#ifndef OOP7_EDITOR_H
#define OOP7_EDITOR_H

#include <stack>

#include "Figure.h"
#include "Document.h"
#include "Command.h"

class Editor {
public:
    Editor();
    void print_document();
    void create_document(std::string& newName);
    void insert_in_document(std::shared_ptr<Figure>& newFigure);
    void delete_in_document(size_t index);
    void save_document();
    void load_document(std::string& name);
    void undo();
private:
    std::shared_ptr<Document> doc_;
    std::stack<std::shared_ptr<ICommand>> history_;
};

#include "Editor.cpp"
#endif //OOP7_EDITOR_H
