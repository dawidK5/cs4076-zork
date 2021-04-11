#ifndef NODESCRIPTIONEXCPT_H
#define NODESCRIPTIONEXCPT_H

#include <exception>
#include <QString>
namespace nde {


class NoDescriptionExcpt : public std::exception
{
private:
    QString err;
public:
    NoDescriptionExcpt(QString err);
    const char * what () const noexcept;
};
}

#endif // NODESCRIPTIONEXCPT_H
