#include <iostream>
#include <stack>

class Momento {
public:
    virtual int GetDollar() = 0;
    virtual int GetEuro() = 0;
    ~Momento() {}
};

class ExchengeMemory : public Momento {
    int euro;
    int dollar;
public:
    ExchengeMemory(int e, int d) :euro(e), dollar(d) {}
    int GetDollar() { return dollar; }
    int GetEuro() { return euro; }
};

class Exchange {
    int euro;
    int dollar;
public:
    Exchange(int e, int d):euro(e), dollar(d) {}
    void Dollars() { std::cout << dollar << " Dollars" << std::endl; }
    void Euro() { std::cout << euro << " Euro" << std::endl; }

    void Sell() {  (dollar) ? --dollar : 0; }
    void Buy() { ++euro; }
    ~Exchange() {}

    ExchengeMemory* save() {
        return new ExchengeMemory(euro, dollar);
    }

    void load(Momento* ex) {
        dollar = ex->GetDollar();
        euro = ex->GetEuro();
    }
};

class Saver{
public:
    Saver(Exchange* ex) :exch(ex) {}

    Exchange* exch;
    std::stack<Momento*> saver;

    void seve() {
        
        saver.push(exch->save());
    }

    void restor() {
        if (saver.empty()) return;

        exch->load(saver.top());
        saver.pop();
    }
};

int main()
{
    Exchange exch(10, 10);
    Saver saver(&exch);

    exch.Dollars();
    exch.Euro();

    exch.Buy();
    exch.Sell();

    exch.Dollars();
    exch.Euro();

    saver.seve();

    exch.Buy();
    exch.Sell();

    exch.Dollars();
    exch.Euro();

    saver.restor();

    exch.Dollars();
    exch.Euro();


    return 0;
}

