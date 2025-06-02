#include "point.h"

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

double Point::calculating_the_distance(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}
