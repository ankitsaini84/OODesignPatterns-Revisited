#include <iostream>

// Interface class for an Animal
class IAnimal {
    public:
    virtual void intro() = 0;
};

// Concrete class which defines a type of Animal
class Dog : public IAnimal {
    public:
    void intro() {
        std::cout << "I'm a Dog\n";
    }
};

// Concrete class which defines a type of Animal
class Cat : public IAnimal {
    public:
    void intro() {
        std::cout << "I'm a Cat\n";
    }
};

// Concrete class which defines a type of Animal
class Human : public IAnimal {
    public:
    void intro() {
        std::cout << "I'm a Human\n";
    }
};

// Factory responsible for creating objects of Animal
// -- Decouples creation logic from client
class AnimalFactory {
    enum {
        DOG,
        CAT,
        HUMAN
    };
    public:
    IAnimal* create(int type) {
        switch(type) {
            case DOG:
                return new Dog();
            break;
            case CAT:
                return new Cat();
            break;
            case HUMAN:
                return new Human();
            break;
        }
        return nullptr;
    }
};

// Client -- Oblivious of the creation logic for either type of Animal
int main() {
    AnimalFactory factory;
    IAnimal* animal;
    animal = factory.create(0); // create DOG
    animal->intro();
    animal = factory.create(2); // create HUMAN
    animal->intro();
    return 0;
}