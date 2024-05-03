/*
    Processor : It is a hardware device based on silicon(at least till now) which executed instructions given
    e.g : Intel i5 12 gen 12300U

    Core : It is  section of the processor which is capible or executing one whole process
    -----------------
    [   c1  |   c2  ]
    [   c3  |   c4  ]
    -----------------

    Single thread, single process, synchronous programs!

*/

/*
    Delays : IO delay, CPU-Bound Delay
*/

#include <iostream>
#include <array>
#include <thread>

void square(std::array<int, 5> &num)
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // atrificial 1 sec delay
        std::cout << "Square of :- " << num[i] << " is " << num[i] * num[i] << '\n';
    }
}

void Cube(std::array<int, 5> &num)
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // atrificial 1 sec delay
        std::cout << "Cube of :- " << num[i] << " is " << num[i] * num[i] * num[i] << '\n';
    }
}

int main(){
    std::array<int,5> data {1,2,3,4,5};
    square(data);
    Cube(data);
}