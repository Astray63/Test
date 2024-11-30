#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    // Test deep copy
    Dog basic;
    {
        Dog tmp = basic;
    }

    // Array of animals
    const int arraySize = 4;
    Animal* animals[arraySize];

    // Fill array with half dogs and half cats
    for (int i = 0; i < arraySize / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++) {
        animals[i] = new Cat();
    }

    // Make some sounds and delete all animals
    for (int i = 0; i < arraySize; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }

    // Test deep copy of brain
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I love bones!");
    
    Dog* dog2 = new Dog(*dog1);
    delete dog1;
    
    std::cout << "Dog2's first idea: " << dog2->getBrain()->getIdea(0) << std::endl;
    delete dog2;

    return 0;
}
