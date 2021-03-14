#include <iostream>

// Behaviour (Interface)
class IFlyBehaviour {
    public:
    virtual void fly() = 0;
};

// Algorithm implements the behaviour
class JetPackFly : public IFlyBehaviour {
    public:
    void fly() {
        std::cout << "Jet Pack Flying\n";
    }
};

// Algorithm implements the behaviour
class CantFly : public IFlyBehaviour {
    public:
    void fly() {
        std::cout << "Wish I could Fly\n";
    }
};

// Duck has a behaviour - fly
class IDuck {
    IFlyBehaviour* flyBehaviour;    // NOTE: Duck HAS-A (composition) fly behaviour.
    public:
    IDuck(IFlyBehaviour* fb) : flyBehaviour(fb) {}
    void fly() {
        flyBehaviour->fly();
    }
};

// Concrete class defines a type of Duck
class RubberDuck : public IDuck {
    public:
    RubberDuck() : IDuck(new CantFly()) {   // Class defines its own fly behaviour
        std::cout << "I'm a Rubber Duck -- ";
    }
};

// Concrete class defines a type of Duck
class CartoonDuck : public IDuck {
    public:
    CartoonDuck() : IDuck(new JetPackFly()) {   // Class defines its own fly behaviour
        std::cout << "I'm a Cartoon Duck -- ";
    }
};



int main() {
    IDuck* duck = new RubberDuck();
    duck->fly();
    duck = new CartoonDuck();
    duck->fly();
    return 0;
}