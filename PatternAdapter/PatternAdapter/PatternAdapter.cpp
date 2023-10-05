// PatternAdapter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class IWeight
{
public:
    virtual float get_weight() = 0;
};

class WeghtKilogram : public IWeight {
    float weight{0};
public:
    WeghtKilogram(float wt):weight (wt){}

    float get_weight()
    {
        return weight;
    }
};

class WeightPaund {
    float weight{ 0 };
public:
    WeightPaund(float wt):weight(wt){}

    float get_weight()
    {
        return weight;
    }
};

class Adapter : public IWeight{
    WeightPaund* wpnd;
public:
    Adapter(WeightPaund* wp) :wpnd(wp) 
    {}

    float get_weight()
    {
        return wpnd->get_weight() * 0.45;
    }
};
int main()
{
 
    WeightPaund wp( 55.5);
    std::cout<<wp.get_weight()<<std::endl; //pn

    Adapter ad(&wp);
    std::cout<<ad.get_weight()<<std::endl; //kg



}


