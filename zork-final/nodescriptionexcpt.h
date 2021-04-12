#ifndef NODESCRIPTIONEXCPT_H
#define NODESCRIPTIONEXCPT_H

#include <exception>
#include <string>
namespace nde {


class NoDescriptionExcpt : public std::exception
{
private:
    std::string err;
public:
    NoDescriptionExcpt(std::string err);
    const char * what () const noexcept;
};
}

#endif // NODESCRIPTIONEXCPT_H
