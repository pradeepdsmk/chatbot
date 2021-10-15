#include <sstream>

#ifndef LETTER_H
#define LETTER_H

class Letter
{
    char c;

public:
    Letter();
    Letter(const Letter &l);
    Letter(char);
    ~Letter();

    bool operator==(const Letter &other) const;

    bool operator==(const char &other) const;

    virtual void setValue(const Letter &l);

    char getC() const;

    inline friend std::ostream &operator<<(std::ostream &os, const Letter &l)
    {
        os << l.c;
        return os;
    }

    inline std::string to_string(const Letter& l) const {
        std::ostringstream ss;
        ss << l;
        return ss.str();
    }
};

#endif