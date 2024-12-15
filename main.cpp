#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#include <unistd.h>


#include "Person.hpp"

int main()
{
    std::srand(std::time(nullptr));
    int JohnState = 0;
    int DavidState = 0;
    Person david("David",15,10,100), john("John", 20, 5,200);
    while (david.isAlive() && john.isAlive() )
    {
        david.update();
        john.update();
        JohnState=std::rand()%20;
        DavidState=std::rand()%20;
        switch (DavidState)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            david.attack(john);
            break;
        case 13:
        case 14:
            david.heal();
            break;
        case 15:
        case 16:
        case 17:
            david.evade();
            break;
        case 18:
        case 19:
            david.defend();
        default:
            break;
        }
        
        switch (JohnState)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            john.attack(david);
            break;
        case 13:
        case 14:
            john.heal();
            break;
        case 15:
        case 16:
        case 17:
            john.evade();
            break;
        case 18:
        case 19:
            john.defend();
        default:
            break;
        }

        david.status();
        john.status();
        usleep(1000000);
    }
    
    

}