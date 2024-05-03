#include<cstring>
#include "Player.h"
std::ostream &operator<<(std::ostream &os, const Player &rhs)
{
    os << "\n _id: " << rhs._id
       << "\n _name: " << rhs._name
       << "\n age: " << rhs._age
       << "\n _noOfMatchedPlayed: " << rhs._noOfMatchedPlayed
       << "\n _rank: " << rhs._rank
       << "\n _score: ";
    for (int i = 0; i < 3; i++)
        os << " " << rhs._score[i];
    return os;
}

void Player::accept()
{
    std::cout<<"Enter the following details \nId : ";
    std::cin>>_id;
    std::cout<<"Name : ";
    char* name = new char[100];
    std::cin>>name;
    _name = new char[strlen(name)+1];
    strcpy(_name,name);
    std::cout<<"Age : ";
    std::cin>>_age;
    std::cout<<"Matches Played : ";
    std::cin>>_noOfMatchedPlayed;
    std::cout<<"Rank : ";
    std::cin>>_rank;
    std::cout<<"Score of the last 3 matches : ";
    for(int i=0;i<3;i++)
    std::cin>>_score[i];
    std::cout<<"\n";
}

float Player::calculateAverageScore()
{
    float sum{0};
    for(int i=0;i<3;i++)
        sum+=_score[i];
    return sum/3;
}

bool Player::operator<(Player &p)
{
    if(this->calculateAverageScore()<p.calculateAverageScore()) return true;
    else return false;
}

bool Player::operator==(Player &p)
{
    if(rank()==p.rank()) return true;
    else return false;
}

float Player::operator+(Player &p)
{
    float ans = this->calculateAverageScore()+p.calculateAverageScore();
    return ans;
}
