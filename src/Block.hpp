template <typename T>
class Block
{
    struct Connection
    {
        T *node;
        unsigned int count;

        Connection()
        {
            node = new T();
            count = 0;
        }

        ~Connection()
        {
            delete node;
        }
    };

    const std::vector<Connection *> *previous;
    const T *current;
    const std::vector<Connection *> *next;
    const unsigned int id;

    static unsigned int ID_COUNTER;

public:
    Block() : id(ID_COUNTER++),
              previous(new std::vector<Connection *>()),
              current(new T()),
              next(new std::vector<Connection *>())
    {
    }

    Block(const T& node) : id(ID_COUNTER++),
              previous(new std::vector<Connection *>()),
              current(new T(node)),
              next(new std::vector<Connection *>())
    {
       
    }

    bool operator==(const Block<T> &other) const
    {
        return (other.id == id);
    }

    bool operator==(const T &other) const
    {
        return ((*current) == other);
    }

    ~Block()
    {
        delete previous;
        delete current;
        delete next;
    }

    void setValue(const T& node) const
    {
        // current->setValue(node);
    }

};

template <typename T>
unsigned int Block<T>::ID_COUNTER = 0;
