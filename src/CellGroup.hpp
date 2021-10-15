#include "Cell.hpp"

#ifndef CELL_GROUP_H
#define CELL_GROUP_H

template <class T>
class CellGroup
{
    typedef Cell<T> *CellPtr;

    std::vector<CellPtr> cells;

    CellPtr previousCell;

public:
    CellGroup()
    {
        previousCell = NULL;
    }

    ~CellGroup()
    {
        for (auto it = cells.begin(); it != cells.end();)
        {
            delete (*it);
            it = cells.erase(it);
        }

        std::cout << "Deleted all cells" << std::endl;
    }

    CellPtr findCellByValue(const T &value)
    {
        for (auto it = cells.begin(); it != cells.end(); it++)
        {
            if ((*it)->isValueEquals(value))
            {
                return (*it);
            }
        }
        return NULL;
    }

    typename std::vector<CellPtr>::iterator end()
    {
        return cells.end();
    }

    void add(const T &value)
    {
        auto cell = findCellByValue(value);
        if (cell == NULL)
        {
            cell = new Cell<T>(value);
            cells.push_back(cell);
            // std::cout << "inserted '" << value << "'" << std::endl;
        }

        unsigned int numConnectionsWithPrevious = cell->updatePreviousConnection(previousCell);
        // if (previousCell)
        // {
        //     std::cout << (*(previousCell->getValue())) << " has " << numConnectionsWithPrevious << " connections with '" << value << "'" << std::endl;
        // }
        // else
        // {
        //     std::cout << "NULL "
        //               << " has " << numConnectionsWithPrevious << " connections with '" << value << "'" << std::endl;
        // }

        previousCell = cell;
    }

    void print() const {
        for(auto it = cells.begin(); it != cells.end(); it++) {
            (*it)->print();
        }
    }
};

#endif
