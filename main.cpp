#include <iostream>
#include <cstdlib>
#include "tetrader.h"

/**
 * @brief Запрашивает у пользователя координаты точки
 * @param num Номер точки (для отображения в приглашении)
 * @return Объект Point с введенными координатами
 * @throws std::runtime_error При ошибке ввода
 */
Point inputPoint(int num);

/**
 * @brief Основная функция программы
 * @return 0 в случае успешного выполнения
 */
int main() {
    try {
        Tetrader default_tetra;
        std::cout << "Площадь основания (по умолчанию): " 
                 << default_tetra.calculate_area() << std::endl;

        std::array<Point, 4> points;
        for (size_t i = 0; i < 4; ++i) {
            points[i] = inputPoint(i + 1);
        }

        Tetrader custom_tetra(points);
        std::cout << "Площадь основания (пользовательская): " 
                 << custom_tetra.calculate_area() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

Point inputPoint(int num) {
    double x, y, z;
    std::cout << "Введите координаты точки " << num << " (x y z): ";
    std::cin >> x >> y >> z;
    
    if (std::cin.fail()) {
        std::cerr << "Ошибка: некорректный ввод!" << std::endl;
        throw std::runtime_error("Input error");
    }
    
    return Point(x, y, z);
}
