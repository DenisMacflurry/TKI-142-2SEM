#pragma once

 #include <cstdint>
 #include <iostream>
 #include <stdexcept>
 
 /**
  * @class Color
  * @brief Класс для представления цвета в формате RGB
  */
 class Color {
 private:
     uint8_t red;    ///< Красная компонента (0-255)
     uint8_t green;  ///< Зеленая компонента (0-255)
     uint8_t blue;   ///< Синяя компонента (0-255)
 
 public:
     /**
      * @brief Конструктор класса Color
      * @param r Красная компонента (0-255)
      * @param g Зеленая компонента (0-255)
      * @param b Синяя компонента (0-255)
      * @throw std::out_of_range Если значения вне диапазона 0-255
      */
     Color(int r, int g, int b);
     
     /**
      * @brief Получить красную компоненту
      * @return Значение красной компоненты
      */
     uint8_t getRed() const;
     
     /**
      * @brief Получить зеленую компоненту
      * @return Значение зеленой компоненты
      */
     uint8_t getGreen() const;
     
     /**
      * @brief Получить синюю компоненту
      * @return Значение синей компоненты
      */
     uint8_t getBlue() const;
 
     /**
      * @brief Оператор вывода цвета
      * @param os Поток вывода
      * @param color Цвет для вывода
      * @return Поток вывода
      */
     friend std::ostream& operator<<(std::ostream& os, const Color& color);
     
     /**
      * @brief Оператор ввода цвета
      * @param is Поток ввода
      * @param color Цвет для ввода
      * @return Поток ввода
      */
     friend std::istream& operator>>(std::istream& is, Color& color);
 };
 