#pragma once

 #include <iostream>
 
 /**
  * @struct Point
  * @brief Хранит координаты точки (x, y)
  */
 struct Point {
     double x; ///< Координата по оси X
     double y; ///< Координата по оси Y
 
     /**
      * @brief Оператор вывода точки в поток
      * @param os Поток вывода
      * @param point Точка для вывода
      * @return Поток вывода
      */
     friend std::ostream& operator<<(std::ostream& os, const Point& point);
 
     /**
      * @brief Оператор ввода точки из потока
      * @param is Поток ввода
      * @param point Точка для ввода
      * @return Поток ввода
      */
     friend std::istream& operator>>(std::istream& is, Point& point);
 };
 
