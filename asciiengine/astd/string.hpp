#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <cstdint>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
#include <memory>


namespace astd
{
class string
{
private:
    char* current_data;
    size_t length;
public:
    string(const char *data); // \/
    string(size_t size_ = 0); // \/
    ~string(); // \/
    string &operator+=(char ch); // \/
    string &operator+=(const char* ch); // \/
    string &operator+=(string &str); // X
    string &operator=(string str); // X
    char &operator[](const int index); // \/
    char *data() const; // \/
    int len() const; // \/
    const char* c_str() const; // \/
};
} // namespace astd

#endif //STRING_H