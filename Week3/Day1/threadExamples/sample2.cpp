/* 
How it runs --->
                                                                                -------------------> cube ends 
                                                                                |                       |
                                                                                |                       |
                                                                                |                       |
                                                                                |                       |
    program starts                                                              |                       |
0-------------------->Square()                     -----------------------> Cube start                  -----------------> 1
                        |                          |                                                                  program ends
                        |                          |
                        |                          |
                        |                          |
                        |                          |
                        --------------------->square ends



How we want --->

                         -------------square starts--------------------------
                        /                                                   
                       /                                                      
                      / 
                     /                            
                    /   
----------> start                                                      
                    \
                     \                                                    
                      \
                       \                             
                        \
                         -------------cube starts-----------------------------

*/


/* Asynchrous code of sample 1 */

#include <iostream>
#include <array>
#include <thread>
#include<functional>

void Square(std::array<int, 5> &num)
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // atrificial 1 sec delay
        std::cout << '\n' << "Square of :- " << num[i] << " is " << num[i] * num[i] << '\n';
    }
}

void Cube(std::array<int, 5> &num)
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // atrificial 1 sec delay
        std::cout << '\n' << "Cube of :- " << num[i] << " is " << num[i] * num[i] * num[i] << '\n';
    }
}

int main(){
    // main thread start create a local array object in local stack
    std::array<int,5> data {1,2,3,4,5};

    /* we launch a new thread
        A thread is a mini program. as the developer, t1 object is a "handle" for me to interact with the thread in some way. This t1 is attached to square mini program we have also passed "data" by referance which is required by the square function
     */
    std::thread t1(&Square,std::ref(data));
    
    /* 
        This t2 is attached to Cube mini program we have also passed "data" by referance which is required by the Cube function
    */
    std::thread t2(&Cube,std::ref(data));

    // Signal as a result/summary/satisfaction
    
    // join : wait for a thread
    // main will not terminate the the t1 and t2 will not get join
    t1.join();
    t2.join();

    std::cout<<"\nGood Bye\n";
}

/* 
    Thread is a mini program 
        once we create a thread we are creating a new program!!!!
        once we create a thread we loose control over the program now it is in OS hand!!
        ~koi masti nhi jiss se os kharab ho jaye

    Either write the simple code and don't get benifit or write thread code and get the maximum benifit but little efforts

*/