#pragma once
#include<Object.h>
#include<MapObject.h>
#include<Map.h>

class Box:public Object
{
private:
    MapObject** place;
public:
    Box():place(nullptr){}
    virtual ~Box(){}
    std::string GetString(){
        return "Box";
    }
    void Move(int mov_x,int mov_y);
    bool Moveable(int mov_x,int mov_y);
    void Display(){
        std::cout<<"O";
    }
    void SetPlace(MapObject** _place){
        place=_place;
    }
    MapObject** GetPlace(){
        return place;
    }
};