// class Letter;
// #include "Word.h"
//#include "Node.h"

class Letter //: public Node<int>
{
    char c;

public:
    Letter();
    Letter(const Letter &l);
    Letter(char);
    ~Letter();

    bool operator==(const Letter &other) const;

    bool operator==(const char &other) const;

    virtual void setValue(const Letter& l);

    char getC() const;
};