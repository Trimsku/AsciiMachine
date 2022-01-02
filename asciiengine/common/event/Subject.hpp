#ifndef SUBJECT_H
#define SUBJECT_H

#include "ISubject.hpp"
#include "Observer.hpp"
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

            static Subject &getInstance() noexcept;

            void Notify() noexcept;
            void attach(ascii::Observer *observer) noexcept;
            void detach(ascii::Observer *observer) noexcept;
            void createMessage(const char* message = "NoneEvent") noexcept;

            private:
                ascii::Observer* head = NULL;
                const char* message_;
        };
    } // namespace Listener
} // namespace ascii
#endif // SUBJECT_H