#include <vector>
#include <algorithm>

#ifndef CELL_HPP
#define CELL_HPP

template <typename T>
class Cell
{
    struct Connection
    {
        unsigned int count = 0;

        /** 
         * node never holds new pointers,  
         * only points to existing blocks. so no new and delete 
        */
        Cell *from;
        Cell *to;

        void print() const
        {
            std::cout << "[";

            if (from)
            {
                from->printValue();
            }
            else
            {
                std::cout << " NULL";
            }

            std::cout << "-" << count << "-";

            if (to)
            {
                to->printValue();
            }
            else
            {
                std::cout << " NULL";
            }

            std::cout << "] ";
        }
    };

    std::vector<Connection *> *inward;
    const T *value;
    std::vector<Connection *> *outward;
    const unsigned int id;

    static unsigned int ID_COUNTER;

    const bool forgetConnection(std::vector<Cell<T>::Connection *> *vec, const Cell<T>::Connection *c)
    {
        auto it = std::find(vec->begin(), vec->end(), c);
        if (it != vec->end())
        {
            vec->erase(it);
            return true;
        }
        return false;
    }

    Connection *getInwardConnectionFrom(const Cell<T> *previousCell)
    {
        if (previousCell == NULL)
        {
            return NULL;
        }

        Connection *c = NULL;
        for (auto it = inward->begin(); it != inward->end(); it++)
        {
            if ((*it)->from == previousCell)
            {
                c = (*it);
                break;
            }
        }
        return c;
    }

public:
    Cell(const T &_value) : id(++ID_COUNTER),
                            value(new T(_value))
    {
        inward = new std::vector<Connection *>();
        outward = new std::vector<Connection *>();
    }

    // const bool operator==(const Cell<T> &other) const
    // {
    //     return (other.id == id);
    // }

    ~Cell()
    {

        for (auto iti = inward->begin(); iti != inward->end(); iti++)
        {
            Connection *c = (*iti);
            if (c->from != NULL)
            {
                c->from->forgetOutwardConnection(c);
                c->from = NULL;
            }
            c->to = NULL; // actually, to is ourselves (this Cell)

            delete (*iti);
            // iti = inward.erase(iti);
        }

        inward->clear();
        delete inward;
        inward = NULL;

        delete value;
        value = NULL;

        for (auto ito = outward->begin(); ito != outward->end(); ito++)
        {
            Connection *c = (*ito);
            if (c->to != NULL)
            {
                c->to->forgetInwardConnection(c);
                c->to = NULL;
            }
            c->from = NULL; // actually, from is ourselves (this Cell)

            delete (*ito);
            // ito = outward.erase(ito);
        }

        outward->clear();
        delete outward;
        outward = NULL;
    }

    const bool isValueEquals(const T &otherValue) const
    {
        return (*value == otherValue);
    }

    const T *getValue() const
    {
        return value;
    }

    unsigned int updatePreviousConnection(Cell<T> *previousCell)
    {
        Connection *c = getInwardConnectionFrom(previousCell);
        if (c == NULL)
        {
            c = new Connection();

            c->from = previousCell;
            c->to = this;

            if (previousCell != NULL)
            {
                previousCell->addOutwardConnection(c);
            }

            addInwardConnection(c);
        }
        c->count++;
        return c->count;
    }

    void addOutwardConnection(Connection *c)
    {
        outward->push_back(c);
    }

    void addInwardConnection(Connection *c)
    {
        inward->push_back(c);
    }

    const bool forgetOutwardConnection(const Connection *c)
    {
        return forgetConnection(outward, c);
    }

    const bool forgetInwardConnection(const Connection *c)
    {
        return forgetConnection(inward, c);
    }

    void print() const
    {
        for (auto iti = inward->begin(); iti != inward->end(); iti++)
        {
            (*iti)->print();
        }

        std::cout << " <- inward : ";

        printValue();

        std::cout << " : outward -> ";

        for (auto ito = outward->begin(); ito != outward->end(); ito++)
        {
            (*ito)->print();
        }

        std::cout << std::endl;
    }

    void printValue() const
    {
        std::cout << (*value);
    }
};

template <typename T>
unsigned int Cell<T>::ID_COUNTER = 0;

#endif