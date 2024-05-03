#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player
{
private:
    /* data */
    int _id{0};
    char* _name;
    int _age {0};
    int _noOfMatchedPlayed{0};
    int _rank{0};
    int* _score = new int[3]{0};

public:
    Player()=default;
    Player(Player&)=delete;
    Player(Player&&)=delete;
    Player &operator=(Player&)=delete;
    Player &operator=(Player&&)=delete;
    ~Player(){
        delete _name;
        delete [] _score;
    }

    void accept();
    float calculateAverageScore();
    bool operator<(Player& p);
    bool operator==(Player& p);
    float operator+(Player& p);

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    char* name() const { return _name; }
    void setName(char* name) {_name = name; }

    int getAge() const { return _age; }
    void setAge(int age) { _age = age; }

    int noOfMatchedPlayed() const { return _noOfMatchedPlayed; }
    void setNoOfMatchedPlayed(int noOfMatchedPlayed) { _noOfMatchedPlayed = noOfMatchedPlayed; }

    int rank() const { return _rank; }
    void setRank(int rank) { _rank = rank; }

    int* score() const { return _score; }
    void setScore(int* score) { for(int i=0;i<3;i++) _score[i]=score[i]; }

    friend std::ostream &operator<<(std::ostream &os, const Player &rhs);
    
};

#endif // PLAYER_H
