#include "../include/text.h"
#include <iostream>

int main() {
    Text text({10, 20}, "Hello, World!", Font("Arial", Color(255, 0, 0), 12));
    text.draw();

    std::cout << "\nEnter new text:\n";
    Text userText = Text::readFromConsole();
    userText.draw();

    return 0;
}