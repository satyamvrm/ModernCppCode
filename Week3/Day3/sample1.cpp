/*
    Threads :
        1. std::threads :
            - They can be used for parallel/concurrent task. they need to be joined or detached.
            They do not catch the return value.

        2. std::Condtiion_variable :
            - In situation where one thread has to wait for an event to happen beacuse of some other thread befor completing its activity dur to other operations such thread may do some work before the event hance are launched simantanuslly.

        3. Continer of std::thread :
            - To manage multiple instacses std::thread efficiently.(map to function, join, etc).

        4. std::mutex vs std::lock_gaurd/std::unique_lock :
            - std::mutex can be locked and unlocked manually only.
            - std::lock_gaurd : (Mutex who completed masters!)
                - scope based (or RAII principle) mutex. No manual lock/unlock.
            - std::unique_lock :
                -scope-based as well as manual lock/unlock.
        
        // synchronizarion premitive

        5. Real-Life
            - Mercedes : Navigation / Music
            --> unlock --> start the accessories / electronics -->



               ----> Map --> [load surrounding/favourites/emergency alert] --> input:Destination (future promise)
              |
            --|
              |
               ---> Music


            I want to launch threads that perform task A and task B.
            task A does not delpend on input parameter but task B needs an input we need to launch thread that wants a parameter even without the parameter

            std::future and std::async


*/      