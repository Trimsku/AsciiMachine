#ifndef ISUBJECT_H
#define ISUBJECT_H
#include "IObject.hpp"

namespace ascii
{
    namespace Listener
    {
        class ISubject {
            public:
                virtual ~ISubject() noexcept;
                virtual void attach(ascii::IObject *observer) noexcept = 0;
                virtual void detach(ascii::IObject *observer) noexcept = 0;
                virtual void Notify() noexcept = 0;
        };
    } // namespace Listener
} // namespace ascii

#endif // ISUBJECT_H