#include "Calculator.h"

int main (int argc, char * argv [])
{
    std::string infix;

    Calculator c;

    while (infix != "QUIT")
    {
        //get input
        std::getline(std::cin, infix);
        
        c.start(infix);
    }
    
    return 0;
}
