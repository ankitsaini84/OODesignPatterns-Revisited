// Link: https://www.modernescpp.com/index.php/thread-safe-initialization-of-data

#include <iostream>
#include <mutex>

std::mutex MyMutex;

class Singleton {
    Singleton() = default;
    ~Singleton() = default;
    Singleton (const Singleton&) = delete;              // Delete Copy Constructor
    Singleton& operator= (const Singleton&) = delete;   // Delete Assignment Operator
    static Singleton* instance;

    public:
    static Singleton* getInstance() {
        if(instance == nullptr) {                       // OPTIMIZATION: Adding this additional check will avoid expensive mutex call everytime getInstance is called.
            std::lock_guard<std::mutex> myLock(MyMutex);// Take lock
            if(instance == nullptr) {                   // Actual null check
                instance = new Singleton();
                /**
                 * IMP: NOTE:
                 * What is the problem? The call instance = new Singleton() in line 20 consists of at least three steps.
                 * 1. Allocate memory for MySingleton
                 * 2. Create the MySingleton object in the memory
                 * 3. Let instance refer to the MySingleton object
                 * 
                 * The problem: there is no guarantee about  the sequence of these steps. 
                 * For example, out of optimization reasons, the processor can reorder the steps to the sequence 1, 3 and 2. 
                 * So, in the first step the memory will be allocated and in the second step, instance refers to an 
                 * incomplete singleton. If at that time another thread tries to access the singleton, it compares the pointer 
                 * and gets the answer true. So, the other thread has the illusion that it's dealing with a complete singleton.
                 * 
                 * The consequence is simple: program behaviour is undefined.
                 */
            }
        }                                               // lock_guard's scope is over. lock_guard is destroyed.
        return instance;
    }
};

Singleton* Singleton::instance {nullptr};

int main() {
    Singleton* s = Singleton::getInstance();
    return 0;
}