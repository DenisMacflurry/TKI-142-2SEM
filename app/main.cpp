#include <iostream>
#include "Queue.h"

/**
 * @brief Демонстрация работы двусторонней очереди с приоритетом.
 * 
 * Инициализирует очередь PriorityDeque с несколькими элементами,
 * выводит минимальный и максимальный приоритет, выполняет несколько
 * операций изменения очереди, выводит состояние очереди после изменений.
 */
void run_application();

/**
 * @brief Точка входа в программу.
 * 
 * Вызывает функцию run_application().
 * 
 * @return int Код завершения (0 при успешном завершении).
 */
int main() {
    run_application();
    return 0;
}

void run_application() {
    PriorityDeque q = {
        {10, 3},
        {5, 1},
        {20, 7}
    };

    std::cout << "Начальная очередь: " << q.toString() << "\n";

    auto min = q.get_minimal_priority();
    auto max = q.get_maximum_priority();
    std::cout << "Минимальный приоритет: " << min.first << " (pr=" << min.second << ")\n";
    std::cout << "Максимальный приоритет: " << max.first << " (pr=" << max.second << ")\n";

    q.pop_front();
    q.push_back(100, 500);
    q.push_front(200, 900);

    std::cout << "После изменений: " << q.toString() << "\n";
    std::cout << "Очередь " << (q.isEmpty() ? "пуста" : "не пуста") << "\n";
    std::cout << "Размер очереди: " << q.size() << "\n";
}
