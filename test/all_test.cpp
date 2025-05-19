#define CATCH_CONFIG_MAIN
#include "../include/catch_amalgamated.hpp"
#include "../include/color.h"
#include "../include/font.h"
#include "../include/point.h"
#include "../include/text.h"
#include <sstream>

// Тесты для Point
TEST_CASE("Point Class Tests", "[point]") {
  SECTION("Конструктор и доступ к полям") {
    Point p{1.5, 2.5};
    REQUIRE(p.x == Approx(1.5));
    REQUIRE(p.y == Approx(2.5));
  }

  SECTION("Оператор вывода") {
    Point p{3.0, 4.0};
    std::stringstream ss;
    ss << p;
    REQUIRE(ss.str() == "(3, 4)");
  }

  SECTION("Оператор ввода (корректные данные)") {
    Point p;
    std::stringstream ss("(1.2, 3.4)");
    ss >> p;
    REQUIRE(p.x == Approx(1.2));
    REQUIRE(p.y == Approx(3.4));
  }

  SECTION("Оператор ввода (некорректные данные)") {
    Point p;
    std::stringstream ss("invalid_data");
    ss >> p;
    REQUIRE(ss.fail());
  }
}

// Тесты для Color
TEST_CASE("Color Class Tests", "[color]") {
  SECTION("Создание с валидными значениями") {
    Color c(255, 128, 64);
    REQUIRE(c.getRed() == 255);
    REQUIRE(c.getGreen() == 128);
    REQUIRE(c.getBlue() == 64);
  }

  SECTION("Создание с невалидными значениями") {
    REQUIRE_THROWS_AS(Color(256, 0, 0), std::out_of_range);
    REQUIRE_THROWS_AS(Color(0, -1, 0), std::out_of_range);
  }

  SECTION("Оператор вывода") {
    Color c(10, 20, 30);
    std::stringstream ss;
    ss << c;
    REQUIRE(ss.str() == "RGB(10, 20, 30)");
  }
}

// Тесты для Font
TEST_CASE("Font Class Tests", "[font]") {
  Color black(0, 0, 0);

  SECTION("Создание шрифта") {
    Font f("Arial", black, 12);
    REQUIRE(f.getName() == "Arial");
    REQUIRE(f.getSize() == 12);
  }

  SECTION("Некорректный размер шрифта") {
    REQUIRE_THROWS_AS(Font("Arial", black, 0), std::invalid_argument);
  }

  SECTION("Изменение размера шрифта") {
    Font f("Arial", black, 12);
    f.setSize(14);
    REQUIRE(f.getSize() == 14);
    REQUIRE_THROWS_AS(f.setSize(-1), std::invalid_argument);
  }

  SECTION("Оператор вывода") {
    Font f("Roboto", black, 16);
    std::stringstream ss;
    ss << f;
    REQUIRE(ss.str().find("Roboto") != std::string::npos);
  }
}

// Тесты для Text
TEST_CASE("Text Class Tests", "[text]") {
  Point pos{10, 20};
  Font font("Arial", Color(0, 0, 255), 12);
  Text text(pos, "Test String", font);

  SECTION("Создание текста") {
    REQUIRE(text.toString().find("Test String") != std::string::npos);
  }

  SECTION("Изменение шрифта") {
    Font newFont("Times New Roman", Color(255, 0, 0), 14);
    text.setFont(newFont);
    REQUIRE(text.toString().find("Times New Roman") != std::string::npos);
  }

  SECTION("Метод draw()") {
    std::stringstream buffer;
    auto old_buf = std::cout.rdbuf(buffer.rdbuf());
    
    text.draw();
    
    std::cout.rdbuf(old_buf);
    REQUIRE(buffer.str().find("Test String") != std::string::npos);
  }

  SECTION("Статический метод readFromConsole()") {
    Text t = Text::readFromConsole();
    REQUIRE_FALSE(t.toString().empty());
  }
}