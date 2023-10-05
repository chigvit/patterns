// PatternComposit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Item {
protected:
    std::string name;
    std::string oner;
public:
    Item(std::string nm) :name(nm) {}
    virtual void add(Item* iptr) = 0;
    virtual void remove(Item * iptr) = 0;
    virtual void display() = 0;
    void setOner(std::string o)
    {
        oner = o;
    }
};

class Clicable : public Item {
public:
    Clicable(std::string name) :Item(name) {}
    void add(Item* itm) { std::exception(); }
    void remove(Item* item) { std::exception(); }
    void display() { std::cout << name << std::endl; }
};

class MenuItem : public Item
{
    std::vector<Item*> items;
public:
    MenuItem(std::string name) :Item(name) {}

    void add(Item* item) {
        item->setOner(this->name);
        items.push_back(item);
    }
    void remove(Item* iptr){
        items.erase(std::remove(items.begin(), items.end(), iptr), items.end());
    }

    void display() {
        for (const auto& a : items)
        {
           // std::cout << "lll";
           if(oner != "")
                std::cout << oner <<"  "<<name;
            a->display();
        }
    }
};

int main()
{
    Item* file = new MenuItem("File -> ");
    Item* create = new MenuItem("Create -> ");
    Item* open = new MenuItem("Open -> ");
    Item* close = new Clicable("Close");
    Item* exit = new Clicable("Exit");
    file->add(create);
    file->add(open);
    file->add(close);
    file->add(exit);

    Item* project = new Clicable("Project...");
    Item* repository = new Clicable("Repository...");
    create->add(project);
    create->add(repository);

    Item* solution = new Clicable("Solution");
    Item* folder = new Clicable("Folder");
    open->add(solution);
    open->add(folder);

    //file->remove(open);

    file->display();

}


