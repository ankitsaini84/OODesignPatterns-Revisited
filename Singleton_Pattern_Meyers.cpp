// Link: https://www.modernescpp.com/index.php/thread-safe-initialization-of-data

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
    Singleton& s = Singleton::getInstance();            // If getInstance() is not called, memory to 'instance' is never allocated.
    return 0;
}