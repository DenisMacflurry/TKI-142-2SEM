#include "point.h"

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}


double Point::getX() const 
{ 
    return x;
}

double Point::getY() const 
{ 
    return y;
}

double Point::getZ() const
{ 
    return z;
}

double Point::calculating_the_distance(const Point &other) const
{ 
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;

    double distance = (pow(dx, 2) + pow(dy, 2) + pow(dz, 2));

    if (distance < 0)
    { 
        std::cerr << "Имеем ошибочку, отрицательное расстрояние между точками, такого быть не может\n";
        exit(1);
    }

    return sqrt(distance);
}