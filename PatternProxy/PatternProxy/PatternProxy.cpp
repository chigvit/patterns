// PatternProxy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
class ISite {
public:
    virtual std::string getPage(int numb) = 0;
    ~ISite() {}
};

class Site : public ISite {
public:

    std::string getPage(int numb)
    {
       std::string page =  "this is page number" + std::to_string(numb);
       return page;
    }
    ~Site() {}
};

class Wrapper : public ISite {
    std::map<int, std::string>pages;
    ISite* site;
public:
    Wrapper(ISite* _site) :site(_site)
    {}
    ~Wrapper() { delete site; }
    std::string getPage(int numb)
    {
        std::string page;
        if (pages.find(numb) == pages.end())
        {
            page = site->getPage(numb);
            pages[numb] =  page; 
        }
        else
        {
            page = pages[numb];
            page.insert(0, "from cache");
        }
        return page;
    }
};

int main()
{
    ISite *site = new Site();
    ISite* wraper = new Wrapper(site);
    std::cout<<wraper->getPage(1) << std::endl;
    std::cout<<wraper->getPage(2) << std::endl;
    std::cout<<wraper->getPage(3) << std::endl;
    std::cout<<wraper->getPage(2) << std::endl;

}
