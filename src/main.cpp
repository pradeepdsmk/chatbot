#include <iostream>
#include "Brain.h"

int main()
{
    std::cout << "Hello ! Press Ctrl+C to terminate program\n";

    Brain b;
    while (1)
    {
        b.getUserInput();
        b.updateNeurons();
        b.showMap();
    }

    return 0;
}
