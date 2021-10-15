#include <iostream>

#include "Brain.h"

Brain::Brain()
{
    // const ushort numLetters = letters.size();
    // const char *ch = letters.c_str();
    // ushort j;
    // for (ushort i = 0; i < numLetters; i++)
    // {
    //     j = (ushort)ch[i];
    //     letterMap[j] = i;
    //     // std::cout << i << " => " << ch[i] << " => " << j << " => " << letterMap[j] << std::endl;
    // }
}

Brain::~Brain()
{

}

bool Brain::getUserInput()
{
    getline(std::cin, inputStr);    
    
    // if(inputStr == "quit") {
    //     std::cout << "\nQuittint... " << std::endl;
    //     return false;
    // }

    std::cout << "\nuser input is: " << inputStr << std::endl;

    const ushort numLetters = inputStr.size();
    std::cout << "num letters in input = " << numLetters << std::endl;
    for (ushort i = 0; i < numLetters; i++)
    {
        letterCells.add(Letter(inputStr[i]));
    }

    return true;
}

void Brain::updateNeurons()
{
    std::cout << "Updated Neurons\n";    
}

void Brain::showMap()
{
    std::cout << "Showing Map\n";
    // const ushort n = inputStr.size();
    // if (n < 0)
    // {
    //     std::cout << "No input\n";
    //     return;
    // }

    // const char *ch = inputStr.c_str();
    // for (ushort i = 0; i < n; i++)
    // {
    //     ushort pos = letterMap[(ushort)ch[i]];
    //     std::cout << i << " => " << ch[i] << " => " << pos << std::endl;
    // }

    letterCells.print();
}