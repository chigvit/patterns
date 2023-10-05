// PaternBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Phone {
    std::string data;
public:
    Phone() {
        data = "";
    }

    void addData(std::string str)
    {
        data += str;
    }
    std::string aboutPhone()
    {
        return data;
    }
};

class IDeveloper {
 public:

    virtual void SetModel() = 0;
    virtual void SetupOS() = 0;
    virtual Phone * GetPphone() = 0;

};

class SmartAndroid : public IDeveloper
{
private:
    std::unique_ptr< Phone> phone;
public:
    SmartAndroid() {
        phone = std::make_unique<Phone>();
    }
    ~SmartAndroid() {
    }
    void SetModel() {
        phone->addData ("Samsung SM");
    }
    void SetupOS(){
        phone->addData( "Android OS ");
    }
    Phone *GetPphone()
    {
        return phone.get();
    }
};
class SmartApple : public IDeveloper
{
private:
    std::unique_ptr< Phone> phone;
public:
    SmartApple() {
        phone = std::make_unique<Phone>();
    }
    ~SmartApple()
    {
    }
    void SetModel() {
        phone->addData("Appl SM");
    }
    void SetupOS() {
        phone->addData("Appl OS ");
    }
    Phone* GetPphone()
    {
        return phone.get();
    }
};
class Director {
public:
    std::unique_ptr<IDeveloper> developer;
public:
    Director(IDeveloper* prod) :developer(prod) {}
    void SetProduct(IDeveloper* prod) { developer.reset( prod); }
    void BuildProducr()
    {
        developer->SetModel();
        developer->SetupOS();
    }
    Phone* gepProduct()
    {
        return developer->GetPphone();
    }
};
int main()
{
    IDeveloper* dev = new SmartAndroid();
    Director direc (dev);
    direc.BuildProducr();
    Phone* phone = direc.gepProduct();
    std::cout<<phone->aboutPhone()<<std::endl;

    IDeveloper* deva = new  SmartApple();
    direc.SetProduct(deva);
    direc.BuildProducr();
    phone = direc.gepProduct();
    std::cout << phone->aboutPhone() << std::endl;
}

