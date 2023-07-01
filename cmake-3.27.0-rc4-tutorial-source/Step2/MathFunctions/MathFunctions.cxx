#include "MathFunctions.h"

#include "mysqrt.h"  // TODO 10: Wrap the mysqrt include in a precompiled ifdef based on USE_MYMATH

// TODO 11: include cmath

namespace mathfunctions {

double sqrt(double x) {
    // TODO 9: If USE_MYMATH is defined, use detail::mysqrt.
    // Otherwise, use std::sqrt.
    return detail::mysqrt(x);
}

}  // namespace mathfunctions
