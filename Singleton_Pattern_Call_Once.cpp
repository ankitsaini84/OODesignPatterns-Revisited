// Link: https://www.modernescpp.com/index.php/thread-safe-initialization-of-data

#include <iostream>
#include <mutex>

class Singleton {
    Singleton() = default;
    ~Singleton() = default;
    Singleton (const Singleton&) = delete;              // Delete Copy Constructor
    Singleton& operator= (const Singleton&) = delete;   // Delete Assignment Operator
    static Singleton* m_instance;
    static std::once_flag m_instanceFlag;               // Instance flag

    public:
    static Singleton* getInstance() {
        // IMP: Singleton will be initialized in thread safe way & only once.
        std::call_once(m_instanceFlag, []() { m_instance = new Singleton(); });
        return m_instance;
    }
};

Singleton* Singleton::m_instance {nullptr};
std::once_flag Singleton::m_instanceFlag;

int main() {
    Singleton* s = Singleton::getInstance();
    return 0;
}