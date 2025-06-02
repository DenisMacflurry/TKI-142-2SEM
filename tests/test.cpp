#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PriorityDeque.h"

TEST_CASE("Проверка начального состояния", "[empty]") {
    PriorityDeque q;
    REQUIRE(q.is_empty());
    REQUIRE(q.get_size() == 0);
}

TEST_CASE("Добавление элементов", "[insert]") {
    PriorityDeque q;
    q.push_front(10, 5);
    q.push_back(20, 3);

    auto min = q.find_min_priority_element();
    auto max = q.find_max_priority_element();

    REQUIRE(q.get_size() == 2);
    REQUIRE(min.second == 3);
    REQUIRE(max.second == 5);
}

TEST_CASE("Удаление элементов", "[remove]") {
    PriorityDeque q = {{1, 1}, {2, 2}, {3, 3}};

    q.pop_front();
    REQUIRE(q.get_size() == 2);

    q.pop_back();
    REQUIRE(q.get_size() == 1);

    auto val = q.find_min_priority_element();
    REQUIRE(val.first == 2);
    REQUIRE(val.second == 2);
}

TEST_CASE("Поиск минимального и максимального приоритета", "[minmax]") {
    PriorityDeque q = {{10, 5}, {20, 1}, {30, 9}};
    auto min = q.find_min_priority_element();
    auto max = q.find_max_priority_element();

    REQUIRE(min.first == 20);
    REQUIRE(min.second == 1);
    REQUIRE(max.first == 30);
    REQUIRE(max.second == 9);
}

TEST_CASE("Строковое представление", "[to_string]") {
    PriorityDeque q = {{5, 2}, {8, 3}};
    REQUIRE(q.to_string() == "[(5, pr=2), (8, pr=3)]");
}

TEST_CASE("Исключение при недопустимом приоритете", "[invalid-priority]") {
    REQUIRE_THROWS_AS({
        PriorityDeque q;
        q.push_back(42, static_cast<size_t>(-1)); // Неверный приоритет
    }, std::runtime_error);
}

TEST_CASE("Исключение при удалении из пустой очереди", "[pop-empty]") {
    REQUIRE_THROWS_AS({
        PriorityDeque q;
        q.pop_front(); // попытка удалить из пустой
    }, std::runtime_error);
}