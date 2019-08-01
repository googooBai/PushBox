#pragma once
#include<Object.h>

class MapObject:public Object
{
private:
    Object* thing_of_occupy;
protected:
public:
    MapObject():thing_of_occupy(nullptr){}
    virtual ~MapObject(){}
    virtual std::string GetString()=0;
    virtual void Display()=0;
    Object* GetThingOfOccupy(){
        return this->thing_of_occupy;        
    }
    void SetThingOfOccupy(Object* obj){
        thing_of_occupy=obj;
    }
};