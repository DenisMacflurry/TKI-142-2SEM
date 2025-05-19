#include <iostream>
#include <cstdlib>
#include "tetrader.h"

Point inputPoint(int num) {
    double x, y, z;
    std::cout << "Введите координаты точки " << num << " (x y z): ";
    std::cin >> x >> y >> z;
    
    if (std::cin.fail()) {
        std::cerr << "Ошибка: некорректный ввод!" << std::endl;
        std::exit(1);
    }
    
    return Point(x, y, z);
}

int main() {
    Tetrader tetra;
    std::cout << "Площадь основания (по умолчанию): " 
              << tetra.calculate_area() << std::endl;

    std::array<Point, 4> points;
    for (int i = 0; i < 4; ++i) {
        points[i] = inputPoint(i + 1);
    }

    tetra.set_vertices(points);
    std::cout << "Площадь основания (пользовательская): " 
              << tetra.calculate_area() << std::endl;

    return 0;
}