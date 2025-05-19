#pragma once 
 
#include <iostream>
#include <string>
 
/**
  * @class Figure
  * @brief Абстрактный базовый класс для геометрических фигур
  */
 class Figure {
 public:
     virtual ~Figure() = default; //< Виртуальный деструктор
     
     /**
      * @brief Чисто виртуальный метод отрисовки фигуры
      */
     virtual void draw() const = 0;
     
     /**
      * @brief Чисто виртуальный метод чтения данных из ввода
      */
     virtual void readFromInput() = 0;
     
     /**
      * @brief Чисто виртуальный метод получения строкового представления
      * @return Строковое представление фигуры
      */
     virtual std::string toString() const = 0;
 };
 