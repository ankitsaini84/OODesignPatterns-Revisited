// Meyer's Singleton pattern

#include <iostream>

class Singleton {
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;               // delete copy constructor
    Singleton& operator=(const Singleton&) = delete;    // delete assignment operator
    public:
    static Singleton& getInstance () {
        static Singleton instance;                      // blocked static object creation is always thread safe - happens at compile-time.
        return instance;
    }
};

int main() {
    Singleton& s = Singleton::getInstance();            // Since, there's no copy-constructor -- We can only have the reference of the original static object.
    return 0;
}