#include "../../asciiengine/astd/string.hpp"
#include "../../asciiengine/astd/uniprint.hpp"

namespace astd {
    //Constructors:
    // Constructor with size:
    string::string(size_t size) : current_data(new char[size]), length(size)
    {
        current_data[0] = '\0'; // Only setting the first char
    }
    // Constructor with str.
    string::string(const char* data) {
        length = strlen(data);
        current_data = new char[length + 1];
        std::move(data, data + length + 1, current_data);
    }

    // Operators
    // Operator =, swap to "this", str.
    string& string::operator=(string str)
    {
        std::swap(str.current_data, current_data);
        length  = str.length;
        return *this;
    }
    // Operator +=(char)
    string &string::operator+=(char ch) {
        char *str = new char[length + 2];
        std::move(current_data, current_data + length + 1, str);
        str[length] = ch;
        str[length + 1] = '\0';

        length++;
        delete[] current_data;
        current_data = new char[length + 2];
        std::move(str, str + length + 1, current_data);
        delete[] str;
        return *this;
    }
    // Operator +=(const char*)
    string &string::operator+=(const char* data) {
        for(int i = 0; i < strlen(data); i++) {
            *this += data[i];
        }
        return *this;
    }
    // Operator +=(astd::string)
    string &string::operator+=(string &data) {
        for(int i = 0; i < data.len(); i++) {
            *this += data[i];
        }
        return *this;
    }

    // Operator []. Return char on the string index.
    char &string::operator[](const int index) {
        if(0 <= index && index <= length) {
            return current_data[index];
        } else {
            astd::print("Your index is not correct. Error: %s", __FILE__);
            exit(1);
        }
    }
    // Utils 
    // Return char*, i.e current_data.
    char *string::data() const {
        return current_data;
    }
    // Return int, without null-terminated char(\0).
    int string::len() const {
        return length;
    }
    // Return const char*, i.e (const char*)current_data.
    const char* string::c_str() const{
        return (const char*)current_data;
    }
    
    // Destructor
    string::~string() {
        delete[] current_data;
    }
}