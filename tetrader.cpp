#include "tetrader.h"
#include <iostream>

Tetrader::Tetrader()
{
    vertices =
    {
        Point (0, 0, 0),
        Point (1, 0, 0),
        Point (0, 1, 0),
        Point (0, 0, 1) 
    };
}

void Tetrader::set_vertices(const std::array<Point, 4>& points) {
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = i + 1; j < 4; ++j) {
            if (std::fabs(points[i].calculating_the_distance(points[j])) < std::numeric_limits<double>::epsilon() * 100) {
                std::cerr << "Ошибка: совпадающие точки!" << std::endl;
                exit(1);
            }
        }
    }
    vertices = points;
}

double Tetrader::calculate_area() const {
    const Point& A = vertices[0];
    const Point& B = vertices[1];
    const Point& C = vertices[2];

    double a = A.calculating_the_distance(B);
    double b = B.calculating_the_distance(C);
    double c = C.calculating_the_distance(A);

    if ((a + b - c) < std::numeric_limits<double>::epsilon() * 100 ||
        (a + c - b) < std::numeric_limits<double>::epsilon() * 100 || 
        (b + c - a) < std::numeric_limits<double>::epsilon() * 100) {
        std::cerr << "Ошибка: вырожденный треугольник!" << std::endl;
        exit(1);
    }

    double p = (a + b + c) / 2;
    double area = p * (p - a) * (p - b) * (p - c);
    
    if (area < 0 && !(std::fabs(area) < std::numeric_limits<double>::epsilon() * 100)) {
        std::cerr << "Ошибка: некорректная площадь!" << std::endl;
        exit(1);
    }

    return std::sqrt(std::fmax(0, area));
}