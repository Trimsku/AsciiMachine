#include "include/util/string.hpp"
//#include "include/util/str.hpp"
#include "include/util/uniprint.hpp"

astd::string getFileResources(astd::string path_to_file) {
    FILE *fstr = fopen(path_to_file.c_str(), "r");
    if(fstr == NULL) {
        astd::print("File \"%s\" is not found. Check your filename or path.", path_to_file);
        exit(1);
    }
    astd::string str("");
    int c;
    while ((c = fgetc(fstr)) != EOF) {
        str+=char(c);
    }
    fclose(fstr);
    return str;
}


int main() {
    getFileResources("std.txt");
    astd::string newString("");

    astd::print("%s", newString);
    return 0;
}