#include <iostream>
#include "Brain.h"
#include <string.h>

Brain::Brain()
{
    const ushort numLetters = letters.size();
    const char *ch = letters.c_str();
    ushort j;
    for (ushort i = 0; i < numLetters; i++)
    {
        j = (ushort)ch[i];
        letterMap[j] = i;
        // std::cout << i << " => " << ch[i] << " => " << j << " => " << letterMap[j] << std::endl;
    }
}

Brain::~Brain() {
    
}

void Brain::getUserInput()
{
    getline(std::cin, inputStr);
    std::cout << "\nuser input is: " << inputStr << std::endl;
}

void Brain::updateNeurons()
{
    std::cout << "Updated Neurons\n";
}

void Brain::showMap()
{
    std::cout << "Showing Map\n";
    const ushort n = inputStr.size();
    if(n < 0) {
        std::cout << "No input\n";
        return;        
    }

    const char *ch = inputStr.c_str();
    for (ushort i = 0; i < n; i++) {
        ushort pos = letterMap[(ushort)ch[i]];
        std::cout << i << " => " << ch[i] << " => " << pos << std::endl;
    }
}