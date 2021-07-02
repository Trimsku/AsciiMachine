#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include "uniprint.hpp"
#include <algorithm>

namespace astd {
    template <typename T> 
    class container
    {
    private:
        T* arr;
        int capacity;
        int length;
    public:
        container();
 
        void push(T data);
        void pop();
        int size();
        T &operator[](const int index);
    };


    template<typename T>
    T &container<T>::operator[](const int index) {
        if(0 <= index && index <= length-1) {
            return arr[index];
        } else {
            astd::print("Error: wrong index, index is %s, index: %d, in %s\n", (index <= 0?"less than 0":"more than size()"), index, __BASE_FILE__);
            exit(1);
        }
    }

    template<typename T>
    int container<T>::size() { return length; }

    template<typename T>
    void container<T>::pop() { 
        arr[length] = NULL;
        length--; 
    }
    
    template <typename T> 
    container<T>::container()
    {
        arr = new T[1];
        capacity = 1;
        length = 0;
    }

    template <typename T> 
    void container<T>::push(T data)
    {
        if (length == capacity) {
            T* temp = new T[2 * capacity];
            std::copy(arr, arr + length, temp);

            delete[] arr;
            capacity *= 2;
            arr = temp;
            //delete[] temp;
        }
        // Insert data
        arr[length] = data;
        length++;
    }
};

#endif // CONTAINER_HPP