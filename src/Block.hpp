template <typename T>
class Block
{
    struct Connection
    {
        unsigned int count = 0;
        /** 
         * node never holds new pointers,  
         * only points to existing blocks. so no new and delete 
        */
        Block *from;
        Block *to;
    };

    std::vector<Connection *> *inward;
    const T *value;
    std::vector<Connection *> *outward;
    const unsigned int id;

    static unsigned int ID_COUNTER;

    const bool forgetConnection(std::vector<Block<T>::Connection *> *vec, const Block<T>::Connection *c)
    {
        auto it = std::find(vec->begin(), vec->end(), c);
        if (it != vec->end())
        {
            vec->erase(it);
            return true;
        }
        return false;
    }

public:
    Block(const T &_value) : id(ID_COUNTER++),
                             value(new T(_value))
    {
        inward = new std::vector<Connection *>();
        outward = new std::vector<Connection *>();
    }

    const bool operator==(const Block<T> &other) const
    {
        return (other.id == id);
    }

    ~Block()
    {

        for (auto iti = inward->begin(); iti != inward->end(); iti++)
        {
            Connection *c = (*iti);
            if (c->from != NULL)
            {
                c->from->forgetOutwardConnection(c);
                c->from = NULL;
            }
            c->to = NULL; // actually, to is ourselves (this Block)

            delete (*iti);
            // iti = inward.erase(iti);
            iti++;
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
            c->from = NULL; // actually, from is ourselves (this Block)

            delete (*ito);
            // ito = outward.erase(ito);
        }

        outward->clear();
        delete outward;
        outward = NULL;
    }

    const bool isValueEquals(const T &node) const
    {
        return (*value == node);
    }

    void updateConnection(const T &node)
    {
        std::cout << "Block: Updated connection" << std::endl;
    }

    const bool forgetOutwardConnection(const Connection *c)
    {
        return forgetConnection(outward, c);
    }

    const bool forgetInwardConnection(const Connection *c)
    {
        return forgetConnection(inward, c);
    }
};

template <typename T>
unsigned int Block<T>::ID_COUNTER = 0;
