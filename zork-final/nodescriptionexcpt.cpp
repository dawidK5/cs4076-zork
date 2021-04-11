#include "nodescriptionexcpt.h"
using nde::NoDescriptionExcpt;

NoDescriptionExcpt::NoDescriptionExcpt(QString err) : err(err) {};
const char * NoDescriptionExcpt::what () const noexcept {
    return err.toLatin1();
}
