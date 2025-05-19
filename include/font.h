#pragma once
#include "color.h"
#include <string>
 
 /**
  * @class Font
  * @brief Класс для представления шрифта текста
  */
 class Font {
 private:
     std::string name; ///< Название шрифта
     Color color;      ///< Цвет шрифта
     int size;        ///< Размер шрифта (должен быть > 0)
 
 public:
     /**
      * @brief Конструктор класса Font
      * @param name Название шрифта
      * @param color Цвет шрифта
      * @param size Размер шрифта
      * @throw std::invalid_argument Если размер <= 0
      */
     Font(const std::string& name, const Color& color, int size);
     
     /**
      * @brief Получить название шрифта
      * @return Название шрифта
      */
     std::string getName() const;
     
     /**
      * @brief Получить цвет шрифта
      * @return Цвет шрифта
      */
     Color getColor() const;
     
     /**
      * @brief Получить размер шрифта
      * @return Размер шрифта
      */
     int getSize() const;
     
     /**
      * @brief Установить новый размер шрифта
      * @param newSize Новый размер шрифта
      * @throw std::invalid_argument Если newSize <= 0
      */
     void setSize(int newSize);
 
     /**
      * @brief Оператор вывода шрифта
      * @param os Поток вывода
      * @param font Шрифт для вывода
      * @return Поток вывода
      */
     friend std::ostream& operator<<(std::ostream& os, const Font& font);
 };
 