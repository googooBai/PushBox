#pragma once
#include<Space.h>

class Destination:public Space
{
private:
    /* data */
public:
    Destination(){}
    virtual ~Destination(){}
    bool IsBoxOccpuy(){
        return (this->GetThingOfOccupy())->GetString()=="BOX";
    }
    virtual void Display(){
        auto thing=this->GetThingOfOccupy();
        if(thing)
            thing->Display();
        else
            std::cout<<"H";
    }
    virtual std::string GetString(){
        return "Destination";
    }
};

