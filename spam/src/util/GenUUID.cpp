#include "GenUUID.hpp"

namespace astd
{

    std::string createUUID() {
        char uuid[38];
	    unsigned char bytes[16];
        int result;
        FILE* rnd = fopen("/dev/urandom", "rb");
	    result = fread(bytes, 16, 1, rnd);
	    fclose(rnd);
        sprintf(uuid, "%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X",
		    bytes[0], bytes[1], bytes[2], bytes[3],
		    bytes[4], bytes[5],
		    bytes[6], bytes[7],
		    bytes[8], bytes[9],
		    bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]);
        return uuid;
    }
} // namespace astd
