#include <string>
#include <vector>

#include "Letter.h"
#include "CellGroup.hpp"

#ifndef BRAIN_H
#define BRAIN_H

class Brain
{
private:
    // uint a[100][100][100];
    std::string inputStr;
    // const std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 `~!@#$%^&*()-_=+\\|[]{};':\",./<>?\r\n";
    bool isEnglish = true;
    // ushort letterMap[128] = {0};

    // std::vector<Cell<Letter> *> letterCells;

    CellGroup<Letter> letterCells;

public:
    Brain();
    ~Brain();
    bool getUserInput();
    void updateNeurons();
    void showMap();
    // void addLetterToLetterCells(char c);
};

#endif