#include<Player.h>
#include<Box.h>

void Player::PushOrMove(int mov_x,int mov_y){
    MapObject** neibour=Detect(mov_x,mov_y);
    if((*neibour)->GetString()=="Wall")
        return;
    auto thing_in_neibour=(*neibour)->GetThingOfOccupy();
    if((*neibour)->GetString()=="Space"||(*neibour)->GetString()=="Destination"){
        if(thing_in_neibour==nullptr){
            (*neibour)->SetThingOfOccupy(this);
            (*this->place)->SetThingOfOccupy(nullptr);
            this->place=neibour;
        }
        else if(thing_in_neibour->GetString()=="Box"){
            auto b=(Box*)thing_in_neibour;
            if(b->Moveable(mov_x,mov_y))
            {
                b->Move(mov_x,mov_y);
                (*neibour)->SetThingOfOccupy(this);
                (*this->place)->SetThingOfOccupy(nullptr);
                this->place=neibour;
            }           
        }
    }            
} 

MapObject** Player::Detect(int mov_x,int mov_y){
    return (place
           +(mov_x+mov_y*COL));   
}