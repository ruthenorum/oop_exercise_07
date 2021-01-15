#ifndef OOP7_TRIANGLE_H
#define OOP7_TRIANGLE_H

#include <cmath>
#include <iostream>

#include "Point.h"
#include "Figure.h"

class Triangle : public Figure{
public:
    Point a1, a2, a3;

    Point center() const override{
        double x,y;
        x = (a1.x + a2.x + a3.x) / 3;
        y = (a1.y + a2.y + a3.y) / 3;
        Point p(x,y);
        return p;
    }
    void print(std::ostream& os) const override{
        os << "triangle " << std::endl;
        os << a1 << std::endl;
        os << a2 << std::endl;
        os << a3 << std::endl;
    }

    void print_file(std::ofstream &of) const override{
        of << "triangle " << std::endl;
        of << a1 << std::endl;
        of << a2 << std::endl;
        of << a3 << std::endl;
    }

    double area() const override{
        std::vector<Point> points = {a1,a2,a3};
        return gauss_area(points);
    }

    Triangle(std::istream& is) {
        is >> a1 >> a2 >> a3;
    }
};


#endif //OOP7_TRIANGLE_H
