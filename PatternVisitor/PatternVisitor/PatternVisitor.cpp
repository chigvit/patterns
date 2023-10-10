#include <iostream>
class Zoo;
class Sinema;
class Circ;

class Visitor {

public:
    std::string str;
    void visit(Circ& place)
    {

        str = " Viseted to cirk ";
    }
    void visit(Sinema& place)
    {
        str = " In sinema film";
    }
    void visit(Zoo& place)
    {
        str = " In zoo slon";
    }
};

class IPlace {
public:
    virtual void accept(Visitor &v) = 0;
};



class Zoo : public IPlace {
public:
    void accept(Visitor& v) {
        std::cout << " Elephant in zoo ";
    }
};

class Circ : public IPlace {
public:
    void accept(Visitor& v)
    {
        v.visit(*this);
        //std::cout << " Clouns circ ";
    }
};

class Sinema : public IPlace {
public:
    void accept(Visitor& v) {
        std::cout << " Godd doc ";
    }
};


int main()
{
    Zoo zoo;
    Sinema sinem;
    Circ circ;
    IPlace * arr[] = { &zoo, &sinem, &circ };
    Visitor visit;
    for (auto a : arr )
    {
        a->accept(visit);
        std::cout<<visit.str;
    }

}


