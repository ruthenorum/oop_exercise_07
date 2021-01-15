#ifndef OOP7_SQUARE_H
#define OOP7_SQUARE_H

#include <cmath>

#include "Point.h"
#include "Figure.h"

class Square : public Figure {
public:
    Point a1, a2, a3, a4;

    Point center() const override{
        double x, y;
        x = (a1.x + a2.x + a3.x + a4.x) / 4;
        y = (a1.y + a2.y + a3.y + a4.y) / 4;
        Point p(x, y);
        return p;
    }

    void print(std::ostream &os) const override{
        os << "square" << std::endl;
        os << a1 << std::endl;
        os << a2 << std::endl;
        os << a3 << std::endl;
        os << a4 << std::endl;
    }
    void print_file(std::ofstream &of) const override{
        of << "square" << std::endl;
        of << a1 << std::endl;
        of << a2 << std::endl;
        of << a3 << std::endl;
        of << a4 << std::endl;
    }

    double area() const override{
        std::vector<Point> points = {a1,a2,a3,a4};
        return gauss_area(points);
    }

    Square(std::istream &is) {
        is >> a1 >> a2 >> a3 >> a4;
    }

};
#endif //OOP7_SQUARE_H
