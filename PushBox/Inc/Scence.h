#pragma once
#include<Object.h>
#include<MapObject.h>
#include<Player.h>
#include<Wall.h>
#include<Space.h>
#include<Destination.h>
#include<Box.h>
#include<Map.h>

class Scence{
private:
    MapObject* map[10][15];
    Box* box;
    Player* player;
public:
    Scence(int _map[][COL], int _player[], int _box[][2]);
    ~Scence();
    void CreateMap(int _map[][COL]);
    void ResetMap(int _map[][COL]);
    void SetBox(int _box[][2]);
    void SetPlayer(int _player[]);
    void InitialScence(int _map[][COL], int _player[], int _box[][2]);
    MapObject** GetMap(){return (MapObject**)map;}
    void Run();
    void Display(); 
};