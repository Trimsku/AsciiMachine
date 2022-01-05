#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <algorithm>
#include <stdio.h>

namespace astd {
    template <typename T> 
    class container
    {
    private:
        T* arr;
        int capacity;
        int length;
    public:
        container() noexcept;
 
        void push(T data) noexcept;
        void pop() noexcept;
        inline int size() noexcept;
        T &operator[](const int index) noexcept;
    };


    template<typename T>
    T &container<T>::operator[](const int index) noexcept {
        if(0 <= index && index <= length-1) {
            return arr[index];
        } else {
            printf("Error: wrong index, index is %s, index: %d, in %s\n", (index <= 0?"less than 0":"more than size()"), index, __BASE_FILE__);
            exit(1);
        }
    }

    template<typename T>
    int container<T>::size() noexcept { return length; }

    template<typename T>
    void container<T>::pop() noexcept { 
        arr[length] = NULL;
        length--; 
    }
    
    template <typename T> 
    container<T>::container() noexcept
    {
        arr = new T[1];
        capacity = 1;
        length = 0;
    }

    template <typename T> 
    void container<T>::push(T data) noexcept
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