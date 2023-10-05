
#include <iostream>
#include <vector>

class IObserver {
public:
    virtual void update(double) = 0;
    virtual ~IObserver() {}
};

class IMarket {
public:
    virtual void addAbserver(IObserver*) = 0;
    virtual void removeObserver(IObserver*) = 0;
    virtual void notify() = 0;
    virtual ~IMarket() {}
};

class MarketFood : public IMarket {
private:
    std::vector<IObserver*> observers;
    double price;
public:
    void setPrice(double p) { 
        price = p;
        notify();
    }
    virtual void addAbserver(IObserver* o) {
        observers.push_back(o);
    }
    virtual void removeObserver(IObserver * o) {
      observers.erase( std::remove(observers.begin(), observers.end(), o ), observers.end());
    }
    virtual void notify() {
        for (auto a : observers) {
            a->update(price);
        }
    }

};

class Shop : public IObserver {
    IMarket* market;
public:
    Shop(IMarket* m) :market(m) {
        m->addAbserver(this);
    }

    void update(double price) {
        if (price < 300) {
            std::cout << "Shop by food for " << price << std::endl;
            market->removeObserver(this);
        }
    }
    ~Shop() {};
};

class Custemer : public IObserver{
    IMarket * market;
public:
    Custemer(IMarket* m) :market(m) {
        m->addAbserver(this);
    }

    void update(double price) {
        if (price < 350) {
            std::cout << "Custemer by food for " << price << std::endl;
            market->removeObserver(this);
        }
    }
    ~Custemer() {};
};
int main()
{

    MarketFood* market = new MarketFood();
    Custemer* cust = new Custemer(market);
    Shop* shop = new Shop(market);

    market->setPrice(230);


}
