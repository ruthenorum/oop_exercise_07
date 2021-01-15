#ifndef OOP7_DOCUMENT_H
#define OOP7_DOCUMENT_H

#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>

#include "Factory.h"
#include "Figure.h"

class Document {
public:
    void print() const ;
    explicit Document(std::string& newName);
    void insert(std::shared_ptr<Figure>& ptr);
    void save(const std::string& filename) const;
    void load(const std::string& filename);
    std::shared_ptr<Figure> get_figure(size_t index);
    void remove_at(size_t index);
    std::string get_name();
    size_t size();
    void remove_last();
    void insert_index(std::shared_ptr<Figure>& newFigure, size_t index);

private:
    friend class InsertCommand;
    friend class RemoveCommand;
    std::string name_;
    std::vector<std::shared_ptr<Figure>> buffer_;
};

#include "Document.cpp"
#endif //OOP7_DOCUMENT_H