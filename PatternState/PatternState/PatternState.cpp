#include <iostream>

class  Trafficlight;

class IState {
protected:
    Trafficlight* trafficlight;
public:
    void SetTrafficlight(Trafficlight* tr) {
        trafficlight = tr;
    }
    virtual void NextState() = 0;
    virtual void PreviosState() = 0;
};



class Trafficlight {
private:
    IState* state;
public:
    Trafficlight(IState* st) :state(nullptr) {
        SetState(st);
    }

    void SetState(IState* st) {
        if (state != nullptr) delete state;

        state = st;
        state->SetTrafficlight(this);

    }

    void NextState(){
        state->NextState();
    }
     
    void PreviosState() {
        state->PreviosState();
    }
};


class Green : public IState {
public:
    void NextState();
    void PreviosState() {
        std::cout << "Green State" <<std::endl;
    }
};
class Yello : public IState {
public:
    void NextState();
    void PreviosState() {
        std::cout << "From Yello to Green" << std::endl;
        trafficlight->SetState(new Green() );
    }
};

void Green::NextState() {
    std::cout << "From Green to Yello" << std::endl;
    trafficlight->SetState(new Yello());
}
class Red : public IState {
public:
    void NextState() {
        std::cout << "Red State" << std::endl;
    }

    void PreviosState() {
        std::cout << "From Red to Yello" << std::endl;
        trafficlight->SetState(new Yello());
    }
};

void Yello::NextState() {
    std::cout << "From Yello to Red" << std::endl;
    trafficlight->SetState(new Red());
}

int main()
{
    
    Trafficlight trafl(new Yello);
    trafl.NextState();
    trafl.NextState();
    trafl.PreviosState();
    trafl.PreviosState();
    trafl.PreviosState();
    trafl.NextState();
    trafl.NextState();
    
}


