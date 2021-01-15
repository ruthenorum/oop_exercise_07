#ifndef OOP7_FACTORY_H
#define OOP7_FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"

class Factory {
public:
    static std::shared_ptr<Figure> figure_create(std::istream& is);
    static std::shared_ptr<Figure> figure_create_file(std::ifstream& is);
};

#include "Factory.cpp"
#endif //OOP7_FACTORY_H
