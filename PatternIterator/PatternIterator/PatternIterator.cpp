// PatternIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

class DataStack{
    int length{-1};
    int array[100];
public:
    friend class StackIterator;
    DataStack() {}
    void push(int value) {
        array[++length] = value;
    }
    int pop(){
        return array[length--];
    }
};

class StackIterator {
    int index;
    const DataStack& data;
public:
    StackIterator(const DataStack& ds) :data(ds) {
        index = 0;
    }
    
    void operator++() { index++; }
    int operator*() { return data.array[index]; }
    bool operator()() {
        return index != data.length + 1;
    }
};

bool operator ==(const DataStack& ds1, const DataStack& ds2) {
    StackIterator si1(ds1), si2(ds2);
    for(; si1(); ++si1, ++si2)
    {
        if (*si1 != *si2) break;
    }
    return !si1() && !si2();
}
int main()
{
    DataStack ds1;
    for (int i = 0; i < 20; i++)
    {
        ds1.push(i);
    }

    DataStack ds2(ds1);

    std::cout << (ds1 == ds2);
    //ds1.push(99);
    std::cout << (ds1 == ds2);
}

