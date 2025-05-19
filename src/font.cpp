#include "../include/font.h"

Font::Font(const std::string& name, const Color& color, int size) 
    : name(name), color(color), size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Font size must be positive");
    }
}

std::string Font::getName() const { return name; }
Color Font::getColor() const { return color; }
int Font::getSize() const { return size; }

void Font::setSize(int newSize) {
    if (newSize <= 0) {
        throw std::invalid_argument("Font size must be positive");
    }
    size = newSize;
}

std::ostream& operator<<(std::ostream& os, const Font& font) {
    os << "Font{name: \"" << font.name << "\", color: " << font.color 
       << ", size: " << font.size << "}";
    return os;
}