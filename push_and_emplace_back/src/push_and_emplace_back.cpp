#include <iostream>
#include <vector>


class Smartphone {
public:
    Smartphone() {
        std::cout << "Call to constructor" << std::endl;
    }

    Smartphone(const Smartphone& other) {
        std::cout << "Call to copy constructor" << std::endl;
    }

    Smartphone(Smartphone&& other) {
        std::cout << "Call to move constructor" << std::endl;
    }

};

void CheckSmartphone(Smartphone && other) {
    Smartphone smartphone = Smartphone(std::move(other));

}

int main() {
    std::cout << "push and emplace back" << std::endl;
    Smartphone smartphone;
    std::vector<Smartphone> smartphone_list;
    smartphone_list.reserve(1000);
    //smartphone_list.push_back(smartphone);
    smartphone_list.push_back(smartphone);
    smartphone_list.push_back(std::move(smartphone));
    // smartphohe_list.push_back();
    
    std::cout << "emplace_back" << std::endl;
    Smartphone other_smartphone;
    smartphone_list.emplace_back(other_smartphone);
    smartphone_list.emplace_back(std::move(other_smartphone));
    smartphone_list.emplace_back();

    std::cout << "move semantics" << std::endl;
    Smartphone another_smartphone;
    CheckSmartphone(std::move(another_smartphone));


    return 0;
}