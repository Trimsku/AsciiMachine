#include "../../../asciiengine/common/util/StringUtil.hpp"

namespace ascii { namespace util {

astd::string getFileResources(const char *path_to_file) noexcept {
    FILE *fstr = fopen(path_to_file, "r");
    if(fstr == NULL) {
        printf("File \"%s\" is not found. Check your filename or path.", path_to_file);
        exit(1);
    }
    astd::string str;
    int c;
    while ((c = fgetc(fstr)) != EOF) {
        str+=char(c);
    }
    fclose(fstr);
    return str;
}

}}