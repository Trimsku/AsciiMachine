#ifndef MATH_HPP
#define MATH_HPP

namespace astd
{
    template<typename T>
    T abs(T object) {
        return object < 0 ? -object : object;
    }
} // namespace ascii


#endif // MATH_HPP