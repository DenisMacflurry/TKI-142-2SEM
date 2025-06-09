#include "tetrader.h"
#include <cmath>
#include <stdexcept>
Tetrader::Tetrader(const std::array<Point, 4>& points) : vertices(points) {
    // Проверка на дубликаты точек
    for (size_t i = 0; i < vertices.size(); ++i) {
        for (size_t j = i + 1; j < vertices.size(); ++j) {
            if (vertices[i] == vertices[j]) {
                throw std::invalid_argument("Тетраэдр не может иметь одинаковых точек");
            }
        }
    }

    // Проверка всех 4 граней через неравенство треугольников
    const auto check_triangle = [](const Point& p1, const Point& p2, const Point& p3) {
        double a = p1.calculating_the_distance(p2);
        double b = p2.calculating_the_distance(p3);
        double c = p3.calculating_the_distance(p1);
        
        return (a + b > c) && (a + c > b) && (b + c > a);
    };

    // ABC, ABD, ACD, BCD
    if (!check_triangle(vertices[0], vertices[1], vertices[2]) ||
        !check_triangle(vertices[0], vertices[1], vertices[3]) ||
        !check_triangle(vertices[0], vertices[2], vertices[3]) ||
        !check_triangle(vertices[1], vertices[2], vertices[3])) {
        throw std::invalid_argument("Неправильный тетраэдр — одна или несколько граней не удовлетворяют неравенству треугольника");
    }
}

double Tetrader::calculate_area() const {
    // Расчет площади первой грани ABC
    double a = vertices[0].calculating_the_distance(vertices[1]);
    double b = vertices[1].calculating_the_distance(vertices[2]);
    double c = vertices[2].calculating_the_distance(vertices[0]);

    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
