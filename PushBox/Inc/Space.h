#pragma once
#include<MapObject.h>

class Space:public MapObject
{
private:

public:
    Space(){}
    virtual ~Space(){}
    virtual std::string GetString(){
        return "Space";
    }
    
    virtual void Display(){
        auto thing=this->GetThingOfOccupy();
        if(thing)
            thing->Display();
        else
            std::cout<<" ";
    }
};