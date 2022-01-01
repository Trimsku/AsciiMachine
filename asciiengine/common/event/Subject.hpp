#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
#include "ISubject.hpp"
#include "IObject.hpp"
#include <stdio.h>

namespace ascii
{
    namespace Listener {
        //! ***********************
        //!     Singleton class
        //! ***********************
        class Subject : ISubject { 
            private:
                Subject() noexcept;
                ~Subject() noexcept;
                static Subject* singleton_;
            public:

            static Subject *getInstance() noexcept;

            void Notify() noexcept;
            void attach(ascii::IObject *observer) noexcept;
            void detach(ascii::IObject *observer) noexcept;
            void createMessage(const char* message = "NoneEvent") noexcept;

            private:
                std::list<ascii::IObject*> observers;
                const char* message_;
        };
    } // namespace Listener
} // namespace ascii
#endif // SUBJECT_H