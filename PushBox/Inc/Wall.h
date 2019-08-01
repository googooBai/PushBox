#pragma once
#include<MapObject.h>

class Wall:public MapObject
{
private:
public:
    Wall(){}
    virtual ~Wall(){}
    std::string GetString(){
        return "Wall";
    }
    void Display(){
        std::cout<<"#";
    }
};