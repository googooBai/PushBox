#include<Scence.h>

using std::cout;
using std::endl;

void Scence::CreateMap(int _map[][COL])
{
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            switch (_map[i][j])
            {
            case 0:
                map[i][j]=new Space();
                break;
            case 1:
                map[i][j]=new Wall();
                break;
            case 2:
                map[i][j]=new Destination();
                break;
            }
}

void Scence::SetBox(int _box[][2])
{
    for(int i=0;i<COUNT_BOX;i++)
    {
        map[_box[i][0]][_box[i][1]]->SetThingOfOccupy(box+i);
        this->box[i].SetPlace(&map[_box[i][0]][_box[i][1]]);
    }
}

void Scence::SetPlayer(int _player[]){
    map[_player[0]][_player[1]]->SetThingOfOccupy(player);
    player->SetPlace(&map[_player[0]][_player[1]]);
}

void Scence::ResetMap(int _map[][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            delete map[i][j];
        }
    }
    CreateMap(_map);
}

Scence::Scence(int _map[][COL], int _player[], int _box[][2]){
    box=new Box[COUNT_BOX];
    player=new Player();
    CreateMap(_map);
    SetBox(_box);
    SetPlayer(_player);
}

Scence::~Scence(){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            delete map[i][j];
        }
    }
}

void Scence::InitialScence(int _map[][COL], int _player[], int _box[][2])
{
    ResetMap(_map);
    SetBox(_box);
    SetPlayer(_player);
}

void Scence::Display(){
    cout<<"------------------[PUSH BOX]-------------------"<<endl;
    cout<<"-----------w,a,s,d Move the Actor.-------------"<<endl;
    cout<<"-----------Press r reset the game.-------------"<<endl;
    cout<<"-----------Press q quit the game.--------------"<<endl;
    cout<<endl;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++)
            map[i][j]->Display();
        cout<<endl;
    }
}

void Scence::Run()
{
    while(1){
        Display();
        int mov_x=0,mov_y=0;
        player->Getinput_(mov_x,mov_y);
        if(mov_x==1&&mov_y==1){
            this->InitialScence(map1,player1,box1);//暂时这么设置
            continue;
        }
        if(mov_x==-1&&mov_y==-1){
            cout<<"-------------[Thanks for playing!]--------------"<<endl;
            system("pause");
            break;
        }
        this->player->PushOrMove(mov_x,mov_y);
        system("cls");
        int count=0;
        for(int i=0;i<COUNT_BOX;i++)
            count=(*(box+i)->GetPlace())->GetString()=="Destination"?
                count+1:count;
        if(count==COUNT_BOX){
            cout<<"---------------[You win the game!]-----------------"<<endl;
            break;
        }
    }
}
