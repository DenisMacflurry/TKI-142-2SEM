#include "../include/point.h"


std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}


std::istream& operator>>(std::istream& is, Point& point) {
    char sep1, sep2, sep3;
    is >> sep1 >> point.x >> sep2 >> point.y >> sep3;
    
    if (sep1 != '(' || sep2 != ',' || sep3 != ')') {
        is.setstate(std::ios::failbit);
        std::cerr << "Error: Invalid point format. Use (x, y)\n";
    }
    
    return is;
}