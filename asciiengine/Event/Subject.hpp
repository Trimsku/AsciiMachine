#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
#include "ISubject.hpp"
#include "../IObject.hpp"
#include <stdio.h>

namespace ascii
{
    namespace Listener {
        //! ***********************
        //!     Singleton class
        //! ***********************
        class Subject : ISubject { 
            private:
                Subject();
                ~Subject();
                static Subject* singleton_;
            public:

            static Subject *GetInstance();

            void Notify();
            void Attach(ascii::IObject *observer);
            void Detach(ascii::IObject *observer);
            void CreateMessage(const char* message = "NoneEvent");

            private:
                std::list<ascii::IObject*> observers;
                const char* message_;
        };
    } // namespace Listener
} // namespace ascii
#endif // SUBJECT_H