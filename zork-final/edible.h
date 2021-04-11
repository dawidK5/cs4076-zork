#ifndef EDIBLE_H
#define EDIBLE_H


class Edible
{
public:
    ~Edible() {};
    virtual int eat() = 0;
protected:
    Edible();

};

#endif // EDIBLE_H
