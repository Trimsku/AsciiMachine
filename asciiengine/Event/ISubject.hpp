#ifndef ISUBJECT_H
#define ISUBJECT_H
#include "../IObject.hpp"

namespace ascii
{
    namespace Listener
    {
        class ISubject {
            public:
                virtual ~ISubject();
                virtual void Attach(ascii::IObject *observer) = 0;
                virtual void Detach(ascii::IObject *observer) = 0;
                virtual void Notify() = 0;
        };
    } // namespace Listener
} // namespace ascii

#endif // ISUBJECT_H