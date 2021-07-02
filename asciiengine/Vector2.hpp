#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace ascii {
    // Vector2 - small vector class
    // with +,-,*,/ operations,
    // Has got +=, -=, *= and /=;
    // Vector2_i - int;
    // Vector2_f - float;
    // Vector2_uint - unsigned int;
    // Vector2 suffixes:
    // _ll - long long;
    // _s - short;
    // _l - long;
    template<typename T> 
    class Vector2
    {
    public:
        T x;
        T y;
        Vector2() : x(0), y(0) {}
        ~Vector2() {}
        Vector2(T x, T y) {
            this->x = x;
            this->y = y;
        }

        template<typename AT> // Another Template - AT
        Vector2(const Vector2<AT>& vec) :
            x(static_cast<T>(vec.x)),
            y(static_cast<T>(vec.y)) {}

        Vector2(const Vector2<T>& vec) :
            x(vec.x), y(vec.y) {}

        Vector2<T> operator=(Vector2<T> rhs) {
            x = rhs.x;
            y = rhs.y;
            return *this;
        }
    };
    // operator-
    template<typename T>
    Vector2<T> operator-(const Vector2<T>& vector) {
        return Vector2<T>(-vector.x, -vector.y);
    }

    template<typename T>
    Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    
    template<typename T>
    Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    // operator*
    template<typename T>
    Vector2<T> operator*(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
    }

    template<typename T>
    Vector2<T> operator*(const Vector2<T>& lhs, T number) {
        return Vector2<T>(lhs.x * number, lhs.y * number);
    }
    
    // operator /
    template<typename T>
    Vector2<T> operator/(const Vector2<T>& lhs, T number) {
        return Vector2<T>(lhs.x / number, lhs.y / number);
    }

    // operator +=
    template<typename T>
    Vector2<T> operator+=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }

    // operator -=
    template<typename T>
    Vector2<T> operator-=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        return lhs;
    }

    // operator *=
    template<typename T>
    Vector2<T> operator*=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        lhs.x *= rhs.x;
        lhs.y *= rhs.y;
        return lhs;
    }

    // operator /=
    template<typename T>
    Vector2<T> operator/=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        lhs.x /= rhs.x;
        lhs.y /= rhs.y;
        return lhs;
    }

    template<typename T>
    inline bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs){ 
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    template<typename T>
    inline bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs){
        return !(lhs==rhs);
    }
    using Vector2i = Vector2<int>;
    using Vector2_int_s = Vector2<short int>;
    using Vector2_uint_s = Vector2<unsigned short int>;
    using Vector2_uint = Vector2<unsigned int>;
    using Vector2_int_l = Vector2<long int>;
    using Vector2_uint_l = Vector2<unsigned long int>;
    using Vector2_int_ll = Vector2<long long int>;
    using Vector2_uint_ll = Vector2<unsigned long long int>;
    using Vector2f = Vector2<float>;
    using Vector2d = Vector2<double>;
    using Vector2_d_l = Vector2<long double>;
}
#endif // VECTOR2_HPP