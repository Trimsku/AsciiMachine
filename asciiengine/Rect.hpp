#ifndef COLLISION_HPP
#define COLLISION_HPP
#include "Vector2.hpp"
#include "astd/math.hpp"

namespace ascii
{
    template<typename T>
    class RectObj{
        public:
            /*
first(x,y)-->********
             *      *
             *      *
             ********<--last(x,y)
            */
            // First(upper than last). Has got x,y.
            Vector2i firstObj;
            // Last(under than first). Has got x,y.
            Vector2i lastObj; 
            RectObj(T x1_, T y1_, T x2_, T y2_) : firstObj(x1_, y1_), lastObj(x2_, y2_) {}
            RectObj<T> operator=(RectObj<T> rhs) {
                firstObj = rhs.firstObj;
                lastObj = rhs.lastObj;
                return *this;
            }
            ~RectObj() {}

            // Check objects.
    };
    template<typename T> 
    bool isCollision(const RectObj<T>& lhs, const RectObj<T>& rhs) {
        if( lhs.firstObj.x <= rhs.firstObj.x && rhs.firstObj.x <= lhs.lastObj.x ){
            if( lhs.firstObj.y <= rhs.firstObj.y && rhs.firstObj.y <= lhs.lastObj.y ) return true;
        } else if( rhs.firstObj.x <= lhs.firstObj.x && lhs.firstObj.x <= rhs.lastObj.x ) {
            if( lhs.firstObj.y <= rhs.firstObj.y && rhs.firstObj.y <= lhs.lastObj.y ) return true;
        }
        /*if(lhs.firstObj.x < rhs.firstObj.x + rhs.lastObj.x &&
           lhs.firstObj.x + lhs.lastObj.x > rhs.firstObj.x &&
           lhs.firstObj.y < rhs.firstObj.y + rhs.lastObj.y &&
           lhs.firstObj.y + lhs.lastObj.y > rhs.firstObj.y) return true;*/
        return false;
    }
    template<typename T> 
    RectObj<T> operator+(RectObj<T> lhs, Vector2<T> rhs) {
        return RectObj<T>(lhs.firstObj.x + rhs.x, lhs.firstObj.y + rhs.y, lhs.lastObj.x + rhs.x, lhs.lastObj.y + rhs.y);
    }
    template<typename T> 
    RectObj<T> operator-(RectObj<T> lhs, Vector2<T> rhs) {
        return RectObj<T>(lhs.firstObj.x - rhs.x, lhs.firstObj.y - rhs.y, lhs.lastObj.x - rhs.x, lhs.lastObj.y - rhs.y);
    }
    using Rect_i = RectObj<int>;
    using Rect_f = RectObj<float>;
} // namespace ascii
#endif // COLLISION_HPP