#ifndef IOBJECT_H
#define IOBJECT_H
#include "util/DebugPrint.hpp"

namespace ascii
{
    class IObject {
        public:
            virtual ~IObject();
            virtual void Update(const char* event_type) = 0;
    };

} // namespace ascii

#endif // IOBJECT_H