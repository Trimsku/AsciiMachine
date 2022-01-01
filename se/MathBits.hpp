#ifndef MATH_OPTIMIZED_HPP
#define MATH_OPTIMIZED_HPP
#include <limits.h>

namespace math
{
inline int max(int a, int b) noexcept {
    return a - ((a - b) & ((a - b) >> (sizeof(int) * CHAR_BIT - 1))); 
}
inline int min(int a, int b) noexcept {
    return b + ((a - b) & ((a - b) >> (sizeof(int) * CHAR_BIT - 1)));
}
} // namespace math
#endif 