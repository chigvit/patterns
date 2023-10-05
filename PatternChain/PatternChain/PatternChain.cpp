
#include <iostream>

class Item {
public:
    virtual std::string  process(std::string) = 0;
    virtual Item* add_woker(Item* item) = 0;
    ~Item() {}
};

class AbstractBuilder : public Item {
protected:
    Item* next{nullptr};
    AbstractBuilder() :next(nullptr) {}
public:

    std::string process(std::string str) {
        if(next)
            return next->process(str);
        return {};
    }

    Item* add_woker(Item* item) {
        next = item;
        return item;
    }
};

class Architect : public AbstractBuilder {
private:
    std::string type{ "architector" };
public:
    std::string process(std::string proc) {
        std::string res;
        if (proc == type)
            res = "Arcitect made project ";
        else
        {
            if (next != nullptr)
                res = AbstractBuilder::process(proc);
        }
        return res;
    }
};

class Builder : public AbstractBuilder {
private:
    std::string type{ "builder" };
public:
   
    std::string process(std::string proc) {
       
        std::string res;
        if (proc == type) {
            res = "Builder made home ";
        }
        else
        {
            res = AbstractBuilder::process(proc);
        }
        return res;
    }
};

class Decorator : public AbstractBuilder {
private:
    std::string type{ "decor" };
public:
   
    std::string process(std::string proc) {
        std::string res;
        if (proc == type) {
            res = "Decorator made decor ";
        }
        else{
            if (next != nullptr)
               res = AbstractBuilder::process(proc);
        }
        return res;
    }
};


void make_process(std::string process, Item* item)
{
    std::string res = item->process(process);
    if (res.empty())
    {
        std::cout << "No builder for command " << process << std::endl;
    }
    else
    {
        std::cout << res << std::endl;
    }
}
int main()
{
    Item* arch = new Architect();
    Item* decor = new Decorator();
    Item* builder = new Builder();

    builder->add_woker(decor)->add_woker(arch);

    make_process("architectore", builder);
    make_process("decor", builder);
    make_process("architector", builder);
    make_process("builder", builder);
}

