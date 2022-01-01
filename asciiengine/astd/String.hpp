#ifndef ASTD_STRING_H
#define ASTD_STRING_H

//#include <cstring>
//#include <cstdint>
//#include <stdlib.h>
//#include <cassert>
//#include <algorithm>
//#include <memory>
#include <string>

namespace astd
{
    using string = std::string;
/*class string
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
};*/
} // namespace astd

#endif //ASTD_STRING_H