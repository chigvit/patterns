// PatternPrototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class IAnimal {
public:
    virtual void set_name(std::string*name) = 0;
    virtual std::string get_name() = 0;
    virtual IAnimal* clone() = 0;
};

class Sheep : public IAnimal {
    std::string* name;
    Sheep(const Sheep& sheep)
    {
        this->name = sheep.name;
    }
public:
    Sheep() {}
    ~Sheep() {}

    void set_name(std::string *name) override {
        this->name = name;
    }
    virtual std::string get_name()
    {
        return *name;
    }
    virtual IAnimal* clone()
    {
        return new Sheep(*this);
    }
};

int main()
{
    IAnimal* sheep = new Sheep;
    std::string name = "Dolle";
    sheep->set_name(&name);
    std::cout << sheep->get_name() << std::endl;

    IAnimal* clone = sheep->clone();
    std::cout << clone->get_name();
    

}

