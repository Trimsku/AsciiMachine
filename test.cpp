#include "include/Collision.hpp"
#include "include/astd/container.hpp"

int main()
{
    /*std::vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);*/
    astd::container<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    //a.push(40);a.push(40);a.push(40);a.push(40);a.push(40);a.push(40);a.push(40);a.push(40);a.push(40);a.push(40);
    for(int i = 0; i < a.size(); i++) {
        astd::print("%d\n", a[i]);
    }

    ascii::Rect_i rect1(10, 10, 20, 20);
    ascii::Rect_i rect2(15, 15, 16,16);
    /*/if(ascii::isCollision(rect1, rect2)) {
        astd::print("jdljdlsjf");
    }*/
    return 0;
}