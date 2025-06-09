// tetrader.h
#ifndef TETRADER_H
#define TETRADER_H

#include <array>
#include "point.h"

/**
 * @class Tetrader
 * @brief Класс, представляющий тетраэдр в трехмерном пространстве
 */
class Tetrader {
public:    
    /**
     * @brief Конструктор с пользовательскими вершинами
     * @param points Массив из 4 точек - вершин тетраэдра
     * @throws std::invalid_argument Если точки совпадают или образуют вырожденную фигуру
     */
    explicit Tetrader(const std::array<Point, 4>& points);
    
    /**
     * @brief Вычисляет площадь основания тетраэдра
     * @return Площадь треугольника-основания
     */
    double calculate_area() const;
    
private:
    std::array<Point, 4> vertices;
    
    /**
     * @brief Проверяет валидность вершин тетраэдра
     * @param points Массив точек для проверки
     * @throw std::invalid_argument Если точки не образуют тетраэдр
     */
    void validate_vertices(const std::array<Point, 4>& points) const;
};

#endif // TETRADER_H
