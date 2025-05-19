#pragma once
#include <cstdlib>
#include <iostream>
#include <cmath>

class Point //класс точка
{ 
    private:
        double x, y, z; // задаем три точки так как работаем в 3х мерном пространстве
    public:
        /**
         * @brief конструктор по умолчанию
         * @param x координата точки x 
         * @param y координата точки y
         * @param z координата точки z
         * @return параметры по умолчанию 0
         */
        Point(double x = 0, double y = 0, double z = 0);

        // геттеры (методы чтения для приватного поля) 
        double getX() const; 
        double getY() const;
        double getZ() const;

        /**
         * @brief функция для вычисления расстояние между точками
         * @param other ссылка на точку (const для избежания изменений)
         * @return расстояние между точками
         */
        double calculating_the_distance(const Point &other) const;
};