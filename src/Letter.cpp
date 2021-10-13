
#include "Letter.h"

Letter::Letter() {
    c = '\0';
}

Letter::Letter(const Letter& l) {
    c = l.c;
}

Letter::Letter(char ch)
{
    c = ch;
}

Letter::~Letter() {}

bool Letter::operator==(const Letter &other) const
{
    return (c == other.c);
}

bool Letter::operator==(const char &other) const
{
    return (c == other);
}

void Letter::setValue(const Letter& l) {
    c = l.c;
}

char Letter::getC() const {
    return c;
}