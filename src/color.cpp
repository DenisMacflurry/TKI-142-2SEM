 #include "../include/color.h"

 Color::Color(int r, int g, int b) {
     if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
         throw std::out_of_range("Color values must be between 0 and 255");
     }
     red = static_cast<uint8_t>(r);
     green = static_cast<uint8_t>(g);
     blue = static_cast<uint8_t>(b);
 }

 uint8_t Color::getRed() const { return red; }
 uint8_t Color::getGreen() const { return green; }
 uint8_t Color::getBlue() const { return blue; }
 
 std::ostream& operator<<(std::ostream& os, const Color& color) {
     os << "RGB(" << static_cast<int>(color.red) << ", " 
        << static_cast<int>(color.green) << ", " 
        << static_cast<int>(color.blue) << ")";
     return os;
 }

 std::istream& operator>>(std::istream& is, Color& color) {
     int r, g, b;
     char sep1, sep2, sep3, sep4, sep5, sep6, sep7;
     
     is >> sep1 >> sep2 >> sep3 >> sep4 >> r >> sep5 >> g >> sep6 >> b >> sep7;
     
     if (sep1 != 'R' || sep2 != 'G' || sep3 != 'B' || sep4 != '(' || 
         sep5 != ',' || sep6 != ',' || sep7 != ')') {
         is.setstate(std::ios::failbit);
         return is;
     }
     
     try {
         color = Color(r, g, b);
     } catch (const std::out_of_range& e) {
         is.setstate(std::ios::failbit);
     }
     
     return is;
 }