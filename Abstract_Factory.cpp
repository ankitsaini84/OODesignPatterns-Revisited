#include <iostream>

// Interface defining speach of an Animal
class ISpeak {
    public:
    virtual void intro() = 0;
};

class Bark : public ISpeak {
    public:
    void intro() {
        std::cout << "I bark.\n";
    }
};

class Chirp : public ISpeak {
    public:
    void intro() {
        std::cout << "I chirp.\n";
    }
};

class Blab : public ISpeak {
    public:
    void intro() {
        std::cout << "I blab.\n";
    }
};


// Interface defining limbs of an Animal
class ILimbs {
    public:
    virtual void intro() = 0;
};

class MuscularVentralFoot : public ILimbs {
    public:
    void intro() {
        std::cout << "I glide over my slime.\n";
    }
};

class Wings_Legs : public ILimbs {
    public:
    void intro() {
        std::cout << "I've 2 wings. I fly.\n";
    }
};

class Arms_Legs : public ILimbs {
    public:
    void intro() {
        std::cout << "I've 2 arms & 2 legs. I use them to drive.\n";
    }
};


// Animal class -- defines an Animal with various attributes - limbs & speach
class Animal {
    protected:
    ILimbs* limbs {nullptr};
    ISpeak* speach {nullptr};
    public:
    Animal(ILimbs* limbs, ISpeak* speach) : limbs(limbs), speach(speach) {}
    void intro() {
        if(limbs) limbs->intro();
        if(speach) speach->intro();
    }
};


// Abstract Factory -- Interface defining factory type
class IAnimalFactory {
    public:
    virtual Animal* create() = 0;
};

// Concrete Factory - Human
class Human : public IAnimalFactory {
    Animal* create() {
        // Hidden is the logic from the outer world 
        // -- Type of attributes a Human comprises of!
        return new Animal(new Arms_Legs(), new Blab());
    }
};

// Concrete Factory - Bird
class Bird : public IAnimalFactory {
    Animal* create() {
        // Hidden is the logic from the outer world 
        // -- Type of attributes a Bird comprises of!
        return new Animal(new Wings_Legs(), new Chirp());
    }
};

// Concrete Factory - Snail
class Snail : public IAnimalFactory {
    Animal* create() {
        // Hidden is the logic from the outer world 
        // -- Type of attributes a Dog comprises of!
        return new Animal(new MuscularVentralFoot(), nullptr);
    }
};


// Client -- 
int main() {
    IAnimalFactory* factory;
    Animal* animal;

    std::cout << "Bird -- \n";
    factory = new Bird();
    animal = factory->create();
    animal->intro();
    std::cout << "--------------------------\n";

    std::cout << "Snail -- \n";
    factory = new Snail();
    animal = factory->create();
    animal->intro();
    std::cout << "--------------------------\n";

    std::cout << "Human -- \n";
    factory = new Human();
    animal = factory->create();
    animal->intro();
    std::cout << "--------------------------\n";

    return 0;
}