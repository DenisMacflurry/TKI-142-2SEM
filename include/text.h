#pragma once

#include "figure.h"
#include "point.h"
#include "font.h"
 
 /**
  * @class Text
  * @brief Класс текстовой фигуры, наследуемый от Figure
  */
 class Text : public Figure {
 private:
     Point position;  ///< Позиция текста (левый нижний угол)
     std::string content; ///< Содержимое текста
     Font font;      ///< Шрифт текста
 
 public:
     /**
      * @brief Конструктор класса Text
      * @param position Позиция текста
      * @param content Содержимое текста
      * @param font Шрифт текста
      */
     Text(const Point& position, const std::string& content, const Font& font);
     
     /**
      * @brief Установить новый шрифт
      * @param newFont Новый шрифт
      */
     void setFont(const Font& newFont);
     
     /**
      * @brief Отрисовка текста (вывод в консоль)
      */
     void draw() const override;
     
     /**
      * @brief Чтение данных текста из консоли
      */
     void readFromInput() override;
     
     /**
      * @brief Получить строковое представление текста
      * @return Строковое представление
      */
     std::string toString() const override;
 
     /**
      * @brief Оператор вывода текста
      * @param os Поток вывода
      * @param text Текст для вывода
      * @return Поток вывода
      */
     friend std::ostream& operator<<(std::ostream& os, const Text& text);
     
     /**
      * @brief Оператор ввода текста
      * @param is Поток ввода
      * @param text Текст для ввода
      * @return Поток ввода
      */
     friend std::istream& operator>>(std::istream& is, Text& text);
     
     /**
      * @brief Статический метод для чтения текста из консоли
      * @return Объект Text с введенными данными
      */
     static Text readFromConsole();
 };
 