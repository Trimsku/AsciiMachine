#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <vector>
#include <string>
#include <stdio.h>

namespace astd {
    /*
    template <typename T> 
    class container
    {
    private:
        T* arr;
        int capacity;
        int length;

        void add(int *counter, T data);
        template<typename... Args>
        void add(int *counter, T data, Args... args) {
            arr[*counter] = data;
            *counter = *counter + 1;
            add(counter, args...);
        }
    public:
        container();
        ~container();

        template<typename... Args>
        container(Args... args) : capacity(1){
            length = sizeof...(args);
            while(capacity < length) capacity *= 2;
            arr = new T[capacity];
            int counter = 0;
            add(&counter, args...);
        }
        void push(T data);
        void pop();
        int size();
        inline T &operator[](const int index);
    };

    template<typename T>
    inline T &container<T>::operator[](const int index) {
        if(0 <= index && index <= length-1) {
            return arr[index];
        } else {
            printf("Error: wrong index, index is %s, index: %d, in %s\n", (index <= 0?"less than 0":"more than size()"), index, __BASE_FILE__);
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
    container<T>::container() : arr(new T[1]), capacity(1), length(0) {}

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

    template <typename T> 
    void container<T>::add(int *counter, T data) {
        arr[*counter] = data;
        *counter = *counter + 1;
    }

    template<typename T>
    container<T>::~container() {
        delete[] arr;
    }
    */
    std::string asString(std::vector<std::string> &container);
    std::vector<std::string> split(std::string str, char splitter);
};

#endif // CONTAINER_HPP