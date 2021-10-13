#include <iostream>
// #include <string.h>
// #include <vector>
#include <algorithm>

#include "Brain.h"

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

Brain::~Brain()
{
}

void Brain::getUserInput()
{
    getline(std::cin, inputStr);
    std::cout << "\nuser input is: " << inputStr << std::endl;

    const ushort numLetters = inputStr.size();
    std::cout << "num letters in input = " << numLetters << std::endl;
    for (ushort i = 0; i < numLetters; i++)
    {
        char c = inputStr[i];
        Letter l(c);
        std::vector<Block<Letter>>::iterator it = std::find(letterBlocks.begin(), letterBlocks.end(), l);
        if(it == letterBlocks.end()) {
            Block<Letter> b(l);
            letterBlocks.push_back(b);
            std::cout << "inserted letter block for '" << c << "'" << std::endl;
        } else {
            std::cout << "letter block for '" << c << "' already present, skipping insert" << std::endl;
        }
    }
}

void Brain::updateNeurons()
{
    std::cout << "Updated Neurons\n";
}

void Brain::showMap()
{
    std::cout << "Showing Map\n";
    const ushort n = inputStr.size();
    if (n < 0)
    {
        std::cout << "No input\n";
        return;
    }

    const char *ch = inputStr.c_str();
    for (ushort i = 0; i < n; i++)
    {
        ushort pos = letterMap[(ushort)ch[i]];
        std::cout << i << " => " << ch[i] << " => " << pos << std::endl;
    }
}