#include "../include/text.h"
#include <iostream>
#include <sstream>

Text::Text(const Point& position, const std::string& content, const Font& font)
    : position(position), content(content), font(font) {}

void Text::setFont(const Font& newFont) { font = newFont; }

void Text::draw() const {
    std::cout << toString() << std::endl;
}

void Text::readFromInput() {
    std::cout << "Enter position (x y): ";
    std::cin >> position.x >> position.y;

    std::cout << "Enter text: ";
    std::cin.ignore();
    std::getline(std::cin, content);

    std::string fontName;
    int r, g, b, size;

    std::cout << "Enter font name: ";
    std::getline(std::cin, fontName);

    std::cout << "Enter font color (r g b): ";
    std::cin >> r >> g >> b;

    std::cout << "Enter font size: ";
    std::cin >> size;

    font = Font(fontName, Color(r, g, b), size);
}

std::string Text::toString() const {
    std::ostringstream oss;
    oss << "Text{position: (" << position.x << ", " << position.y 
        << "), content: \"" << content << "\", font: " << font << "}";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Text& text) {
    os << text.toString();
    return os;
}

Text Text::readFromConsole() {
    Text text({0, 0}, "", Font("Arial", Color(0, 0, 0), 12));
    text.readFromInput();
    return text;
}