#include <iostream>

// A reference is an alias to an existing object or function
// An lvalue reference alias an existing object
// An rvalue reference extends the lifefime of a temporary object


void foo(int& value) {
    std::cout << "foo argument passed by reference" << std::endl;
}

/*void foo(const int& value) {
    std::cout << "foo argument passed by const reference" << std::endl;
}*/

void boo(int& value) {
    std::cout << "boo argument passed by reference" << std::endl;
}

void boo(const int& value) {
    std::cout << "boo argument passed by const reference" << std::endl;
}

void has_move(int& value) {
    std::cout << "has_move argument passed by reference" << std::endl;
}

void has_move(const int& value) {
    std::cout << "has_move argument passed by const reference" << std::endl;
}

void has_move(int&& value) {
    std::cout << "has_move argument passed by rvalue reference" << std::endl;
}

void lvalues() {
    int a = 10;
    int& lvr = a; 
    // int& lvr2 = 4; non-const lvalue references can't bind to a an rvalue of type int
    const int& lvr2 = 4;
}

void rvalues() {
    int a;
    // int&& rvr = a; Rvalue references can't be bind to lvalues
    int&& rvr = 25+32;
}

int main() {
    std::cout << "References" << std::endl;
    lvalues();
    rvalues();

    int v = 5; 
    const int c = 6;
    int &&rvr = 6;
    // foo(5); cannot bind to an rvalue of type `int`
    foo(v);
    // foo(std::move(4)); cannot bind to an rvalue of type `int`
    // foo(std::move(v)); cannot bind to an rvalue of type `int`
    boo(v);
    boo(5);
    boo(std::move(4)); // fallsback to the const reference overload
    boo(std::move(v)); // fallsback to the const reference overload

    has_move(v);
    has_move(c);
    has_move(5); // calls overload with move semantics!!!
    has_move(std::move(4)); // calls overload with move semantics
    has_move(std::move(v)); // calls overload with move semantics
    has_move(rvr); // calls overlad with passed by reference
    return 0;
}