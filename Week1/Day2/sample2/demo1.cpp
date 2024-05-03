#include <bits/stdc++.h>
using namespace std;

enum Rank
{
    FIRST,
    SECOND,
    THIRD
};

enum Gear
{
    FIRST,
    SECOND,
    THIRD
};

void Magic(int n)
{
    std::cout << n * n << endl;
}

// correct code

enum class Rank1
{
    FIRST,
    SECOND,
    THIRD
};

enum class Gear1
{
    FIRST,
    SECOND,
    THIRD
}


int main()
{
    // we cann't force the user to use enum name as a prifix
    enum Rank r1 = FIRST;
    enum Gear g1 = FIRST;

    // compiler should block comparision of different enums
    if (r1 == g1)
    {
        std::cout << "OOPS\n";
    }

    // implicit conversion of enum to int is bad
    Magic(r1);
    
    
    //correct code
    // user have to specify the class now
    enum Rank1 r2 = Rank1::FIRST;
    enum Gear1 g2 = Gear1::FIRST;

    // compiler will genrate the error
    if (r2 == g2)
    {
        std::cout << "OOPS\n";
    }

    // implicit conversion of enum to int is bad
    Magic(r1);

    return 0;
}

