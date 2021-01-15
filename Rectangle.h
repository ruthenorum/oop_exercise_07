#ifndef OOP7_RECTANGLE_H
#define OOP7_RECTANGLE_H

#include <cmath>

#include "Point.h"
#include "Figure.h"

class Rectangle : public Figure {
public:
    Point a1, a2, a3, a4;

    Point center() const override{
        double x, y;
        x = (a1.x + a2.x + a3.x + a4.x) / 4;
        y = (a1.y + a2.y + a3.y + a4.y) / 4;
        Point p(x, y);
        return p;
    }

    void print(std::ostream& os) const override{
        os << "rectangle" << std::endl;
        os << a1 << std::endl;
        os << a2 << std::endl;
        os << a3 << std::endl;
        os << a4 << std::endl;
    }

    void print_file(std::ofstream& of) const override{
        of << "rectangle" << std::endl;
        of << a1 << std::endl;
        of << a2 << std::endl;
        of << a3 << std::endl;
        of << a4 << std::endl;
    }

    double area() const override{
        std::vector<Point> points = {a1,a2,a3,a4};
        return gauss_area(points);
    }

    Rectangle(std::istream& is) {
        is >> a1 >> a2 >> a3 >> a4;
    }
};

#endif //OOP7_RECTANGLE_H
