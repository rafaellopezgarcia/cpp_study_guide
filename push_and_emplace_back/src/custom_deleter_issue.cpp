#include <iostream>
#include <memory>

class CustomDeleter {
public:
    CustomDeleter() {
        std::cout << "CustomDeleter constructor" << std::endl;
    }

    CustomDeleter(const CustomDeleter&) {
        std::cout << "CustomDeleter copy constructor" << std::endl;
    }

    CustomDeleter(CustomDeleter&&) noexcept {
        std::cout << "CustomDeleter move constructor" << std::endl;
    }

    void operator()(int* value) {
        std::cout << "Deleting pointer" << std::endl;
        delete value;
    }
};

int main() {
    auto deleter = CustomDeleter{};
    std::shared_ptr<int> ptr(new int, deleter);
    return 0;
}
