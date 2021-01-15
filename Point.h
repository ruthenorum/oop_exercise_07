#ifndef OOP7_POINT_H
#define OOP7_POINT_H

#include <iostream>

class Point {
public:
    double x, y;
    Point() = default;
    Point (double f,double s) {
        x = f;
        y = s;
    }
};

std::istream& operator >> (std::istream& is,Point& p ) {
    return  is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os,const Point& p) {
    return os << p.x <<' '<< p.y;
}
#endif //OOP7_POINT_H
