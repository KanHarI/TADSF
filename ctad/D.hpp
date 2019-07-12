#ifndef D_HPP
#define D_HPP

#include "Canonical.hpp"

namespace CTAD {

template <class T>
using D = Canonical<typename T::derivative>;

}

#endif
