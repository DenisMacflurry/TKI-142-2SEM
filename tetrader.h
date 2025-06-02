#pragma once

#include "point.h"
#include <array>
#include <cstdlib>
#include <limits>
#include <cmath>

class Tetrader //класс тетрайдер
{ 
    private:
        std::array<Point, 4> vertices; //вершины тетрайдера
    public:
        /**
         * @brief конструктор по умолчанию
         */
        Tetrader();
        
        /**
         * @brief конструктор с параметрами
         * @param points массив из 4 точек
         */
        Tetrader(const std::array<Point, 4>& points);
        
        /**
         * @brief функция для установки вершин массива
         * @param points Массив из 4 точек
         */
        void set_vertices(const std::array<Point, 4> &points);

        /**
         * @brief функция для вычисления площади основания
         * @return рассчитанная площадь основания
         */
        double calculate_area() const;
};
