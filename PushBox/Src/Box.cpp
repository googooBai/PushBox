#include<Box.h>

void Box::Move(int mov_x,int mov_y){
    auto neibour=place
           +(mov_x+mov_y*COL);
    (*neibour)->SetThingOfOccupy(this);
    (*place)->SetThingOfOccupy(nullptr);
    place=neibour;
}

bool Box::Moveable(int mov_x,int mov_y){
    auto neibour=place
           +(mov_x+mov_y*COL);
    if((*neibour)->GetString()=="Wall")
        return false;
    auto thing_in_neibour = (*neibour)->GetThingOfOccupy();
    if(thing_in_neibour==nullptr)
        return true;
    return false;
}