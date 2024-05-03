#include "Player.h"

int main(){
    Player* p = new Player[2];
    p[0].accept();
    p[1].accept();
    for(int i=0;i<2;i++)
    std::cout<<p[i];

}