#include <iostream>
#include <memory>
#include <vector>

class Sensor{
public:
    Sensor() {
        std::cout << "Constructor" << std::endl;
    }

    Sensor(const Sensor&) {
        std::cout << "Copy constructor" << std::endl;
    }

    Sensor(Sensor && sensor) {
        std::cout << "Move constructor" << std::endl;
    }

    ~Sensor() {
        std::cout << "Destructor" << std::endl;
    }

};

class SensorDeleter{
public:

    SensorDeleter() {
        std::cout << "SensorDeleter constructor" << std::endl;
    }

    SensorDeleter(const Sensor&) {
        std::cout << "SensorDeleter copy constructor" << std::endl;
    }

    SensorDeleter(Sensor &&) {
        std::cout << "SensorDeleter move constructor" << std::endl;
    }

    void operator()(Sensor* sensor) {
        std::cout << "Deleting sensor" << std::endl;
        delete sensor;      
    }
};

class MySensorDeleter{
public:

    /*MySensorDeleter() {
        std::cout << "MySensorDeleter constructor" << std::endl;
    }

    MySensorDeleter(const MySensorDeleter&) {
        std::cout << "MySensorDeleter copy constructor" << std::endl;
    }

    MySensorDeleter(MySensorDeleter &&) {
        std::cout << "MySensorDeleter move constructor" << std::endl;
    }*/

    void operator()(Sensor* sensor) {
        std::cout << "Deleting sensor" << std::endl;
        delete sensor;      
    }
};

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
        std::cout << "Deleting sensor" << std::endl;
        delete value;
    }
};

int main() {
    //std::vector<std::shared_ptr<Sensor>> pointers;
    // This is bad!!! It creates a temporary and then move constructs
    auto deleter = CustomDeleter{};
    std::shared_ptr<int> sptr(new int, deleter);
    std::cout  << "unique" << std::endl;
    std::unique_ptr<int, CustomDeleter> uptr(new int, deleter);
    //std::shared_ptr<Sensor> my_sensor_ptr2(new Sensor, SensorDeleter{});
    //std::shared_ptr<Sensor> my_sensor_ptr(new Sensor, MySensorDeleter{});

    /*std::cout << "Use count " << my_sensor_ptr.use_count() << std::endl;
    pointers.push_back(my_sensor_ptr);
    std::cout << "Use count " << my_sensor_ptr.use_count() << std::endl;

    std::cout << "Temporary" << std::endl;
    pointers.push_back(std::move(my_sensor_ptr));
*/

    return 0;
}
