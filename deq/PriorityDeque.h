#pragma once

#include <utility>
#include <string>
#include <cstddef>

const size_t MIN_PRIORITY = 0;
const size_t MAX_PRIORITY = 1000;

/**
 * @class PriorityDeque
 * @brief Класс двусторонней очереди с приоритетом на основе динамического массива.
 */
class PriorityDeque {
private:
    std::pair<size_t, size_t>* data; 
    size_t count;                    

    /**
     * @brief Выводит сообщение об ошибке и завершает программу.
     * @param message Сообщение об ошибке
     */
    void error_message(const std::string& message) const;

    /**
     * @brief Проверяет допустимость заданного приоритета.
     * @param priority Приоритет элемента
     * @return true, если приоритет корректный
     */
    bool is_valid_priority(size_t priority) const;

    /**
     * @brief Вставляет элемент в очередь по приоритету.
     * @param value Значение элемента
     * @param priority Приоритет элемента
     */
    void insert_by_priority(size_t value, size_t priority);

public:
    /**
     * @brief Конструктор по умолчанию. Создаёт пустую очередь.
     */
    PriorityDeque();

    /**
     * @brief Конструктор с указанием максимального размера.
     * @param maxSize Максимальное количество элементов
     */
    explicit PriorityDeque(size_t maxSize);

    /**
     * @brief Конструктор с инициализацией из списка.
     * @param init Список пар (значение, приоритет)
     */
    PriorityDeque(std::initializer_list<std::pair<size_t, size_t>> init);

    /**
     * @brief Конструктор копирования.
     * @param other Объект, из которого копируются данные
     */
    PriorityDeque(const PriorityDeque& other);

    /**
     * @brief Оператор присваивания.
     * @param other Объект, из которого копируются данные
     * @return Ссылка на текущий объект
     */
    PriorityDeque& operator=(const PriorityDeque& other);

    /**
     * @brief Конструктор перемещения.
     * @param other Объект, из которого перемещаются данные
     */
    PriorityDeque(PriorityDeque&& other);

    /**
     * @brief Оператор присваивания с перемещением.
     * @param other Объект, из которого перемещаются данные
     * @return Ссылка на текущий объект
     */
    PriorityDeque& operator=(PriorityDeque&& other);

    /**
     * @brief Деструктор. Освобождает выделенную память.
     */
    ~PriorityDeque();

    /**
     * @brief Добавляет элемент в начало очереди.
     * @param value Значение элемента
     * @param priority Приоритет элемента
     */
    void push_front(size_t value, size_t priority);

    /**
     * @brief Добавляет элемент в конец очереди.
     * @param value Значение элемента
     * @param priority Приоритет элемента
     */
    void push_back(size_t value, size_t priority);

    /**
     * @brief Удаляет элемент из начала очереди.
     */
    void pop_front();

    /**
     * @brief Удаляет элемент из конца очереди.
     */
    void pop_back();

    /**
     * @brief Проверяет, является ли очередь пустой.
     * @return true, если очередь пустая
     */
    bool is_empty() const;

    /**
     * @brief Возвращает текущее количество элементов в очереди.
     * @return Размер очереди
     */
    size_t get_size() const;

    /**
     * @brief Находит элемент с минимальным приоритетом.
     * @return Пара (значение, приоритет)
     */
    std::pair<size_t, size_t> find_min_priority_element() const;

    /**
     * @brief Находит элемент с максимальным приоритетом.
     * @return Пара (значение, приоритет)
     */
    std::pair<size_t, size_t> find_max_priority_element() const;

    /**
     * @brief Возвращает строковое представление очереди.
     * @return Строка формата [(значение, pr=приоритет), ...]
     */
    std::string to_string() const;
};