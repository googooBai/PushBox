#pragma once
#include<Object.h>
#include<MapObject.h>
#include<Map.h>

class Player:public Object
{
private:
    MapObject** place;
    MapObject** Detect(int x,int y);
public:
    Player():
        place(nullptr){};
    virtual ~Player(){}
    std::string GetString(){
        return "Player";
    }
    void Getinput_(int& input_x,int& input_y){
        char ch=getchar();
        switch(ch)
        {
            case 'w':
                input_x=0;input_y=-1;
                break;
            case 's':
                input_x=0;input_y=1;
                break;
            case 'a':
                input_x=-1;input_y=0;
                break;
            case 'd':
                input_x=1;input_y=0;
                break;
            case 'q':
                input_x=-1;input_y=-1;
                break;
            case 'r':
                input_x=1;input_y=1;
                break;
            default:
                input_x=0;input_y=0;
                break;
        }
    }
    void PushOrMove(int mov_x,int mov_y);
    void SetPlace(MapObject** _place){
        place=_place;
    }
    void Display(){
        std::cout<<"P";
    }  
};