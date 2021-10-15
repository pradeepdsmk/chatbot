#include <iostream>
#include <algorithm>
#include <vector>
#include "Letter.h"
#include "Block.hpp"

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
    for (std::vector<Block<Letter> *>::iterator it = letterBlocks.begin(); it != letterBlocks.end();)
    {
        delete (*it);
        it = letterBlocks.erase(it);
    }
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
        std::vector<Block<Letter> *>::iterator it;
        for (it = letterBlocks.begin(); it != letterBlocks.end(); it++)
        {
            if ((*it)->isValueEquals(l))
            {
                std::cout << "letter block for '" << c << "' already present, skipping insert" << std::endl;
                (*it)->updateConnection(l);

                break;
            }
        }
        if (it == letterBlocks.end())
        {
            Block<Letter> *b = new Block<Letter>(l);
            letterBlocks.push_back(b);
            std::cout << "inserted letter block for '" << c << "'" << std::endl;
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