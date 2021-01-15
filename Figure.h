#ifndef OOP7_FIGURE_H
#define OOP7_FIGURE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Point.h"


double get_det(const double x1, const double y1,
               const double x2, const double y2){
    return x1 * y2 - x2 * y1;
}

double gauss_area(const std::vector<Point>& nodes){
    double out = 0.0;
    auto count = nodes.size();
    for(size_t i = 0; i < (count - 1); i++){
        out += get_det(static_cast<double>(nodes[i].x),static_cast<double>(nodes[i].y),
                       static_cast<double>(nodes[i+1].x),static_cast<double>(nodes[i+1].y));
    }
    out += get_det(static_cast<double>(nodes[count-1].x),static_cast<double>(nodes[count-1].y),
                   static_cast<double>(nodes[0].x),static_cast<double>(nodes[0].y));
    return fabs(0.5 * out);
}


class Figure {
public:
    virtual Point center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual void print_file(std::ofstream&) const = 0 ;
    virtual double area() const = 0;
};


#endif //OOP7_FIGURE_H
