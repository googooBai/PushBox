#include<Scence.h>
#include<Map.h>

int main()
{
    Scence* scence=new Scence(map1,player1,box1);
    scence->Run();
    delete scence;
    // MapObject* mt;
    // Wall w;
    // Space s;
    // Destination d;
    // std::cout<<w.GetString()<<std::endl;
    // std::cout<<s.GetString()<<std::endl;
    // std::cout<<d.GetString()<<std::endl;
    // mt=&w;
    // std::cout<<mt->GetString()<<std::endl;
    // mt=&s;
    // std::cout<<mt->GetString()<<std::endl;
    // mt=&d;
    // std::cout<<mt->GetString()<<std::endl;

    system("pause"); 
    return 0;
}