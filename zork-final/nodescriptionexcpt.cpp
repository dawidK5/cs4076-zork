#include "nodescriptionexcpt.h"
using nde::NoDescriptionExcpt;

NoDescriptionExcpt::NoDescriptionExcpt(std::string error) : err(error) {};
const char * NoDescriptionExcpt::what () const noexcept {
    return err.c_str();
}
