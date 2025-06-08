// tetrader.cpp
#include "tetrader.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>

Tetrader::Tetrader() : vertices{
    Point(0, 0, 0),
    Point(1, 0, 0),
    Point(0, 1, 0),
    Point(0, 0, 1)
} {}

Tetrader::Tetrader(const std::array<Point, 4>& points) {
    validate_vertices(points);
    vertices = points;
}

void Tetrader::validate_vertices(const std::array<Point, 4>& points) const {
    // Проверка на совпадающие точки
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            if (points[i] == points[j]) {
                throw std::invalid_argument("Duplicate points detected");
            }
        }
    }
    
}

double Tetrader::calculate_area() const {
    const Point& A = vertices[0];
    const Point& B = vertices[1];
    const Point& C = vertices[2];

    double a = A.calculating_the_distance(B);
    double b = B.calculating_the_distance(C);
    double c = C.calculating_the_distance(A);

    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
