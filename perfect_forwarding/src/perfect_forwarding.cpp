#include <utility>
#include <iostream>

// Receives an non-const lvalue
void foo(int unit) {
    std::cout << "passed by value" << std::endl;
}

// Receives an const lvalue
void cfoo(const int unit) {
    std::cout << "passed by const value" << std::endl;
}

// Receives a non-const lvalue reference
void bar(int& unit) {
    std::cout << "passed by reference" << std::endl;
}

// Receives a const lvalue reference
void cbar(const int& unit) {
    std::cout << "passed by const reference" << std::endl;
}

// Receives a universal reference
template<typename T>
void wrapper(T&& unit) {
    foo(std::forward<T>(unit));
    cfoo(std::forward<T>(unit));
    // bar(std::forward<T>(unit)); Cannot bind non-const lvalue reference of type `int&` to an rvalue of type `int`
    cbar(std::forward<T>(unit));
}

int compute() {
    return 6;
}

void auto_universal_reference() {
    // Using auto&& assigns the type of the return value 
    // and when forwarding that value with std::forward,
    // the return value type is preserved.
    auto && val = compute();

    auto& v = compute();

    foo(std::forward<decltype(val)>(val));
    cfoo(std::forward<decltype(val)>(val));
    //bar(std::forward<decltype(val)>(val));
    cbar(std::forward<decltype(val)>(val));
}

int main() {
    std::cout << "Perfect forwarding" << std::endl;
    wrapper(5); // Passes an rvalue 
    auto_universal_reference();
    return 0;
}

