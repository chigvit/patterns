// PatternDecorator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Processor {
public:
    virtual void process() = 0;
};

class Transmiter : public Processor {
    std::string data;
public:
    Transmiter(std::string dt) :data(dt) {}
    void process()
    {
        std::cout << " Send data " << data;
    }
};

class Shell : public Processor
{
protected:
    Processor* proc;
public:
    Shell(Processor* pr) : proc(pr) {}
    void process()
    {
        proc->process();
    }
};

class HammingCoder : public Shell
{
public:
    HammingCoder(Processor* proc) : Shell(proc) {}
    void process()
    {
        std::cout << " Updated Hamming Code";
        proc->process();
    }
};

class Encrypt : public Shell
{
public:
    Encrypt(Processor* proc) : Shell(proc) {}
    void process() {
        std::cout << " Data Encrypted ";
        proc->process();
    }
};

int main()
{
    Processor* proc = new Transmiter("My Message");
    proc->process();
    std::cout << "\n";
    Processor* hamg = new HammingCoder(proc);
    hamg->process();
    std::cout << "\n";
    Processor* encr = new Encrypt(hamg);
    encr->process();
    std::cout << "\n";

}

