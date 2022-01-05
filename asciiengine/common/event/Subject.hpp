#ifndef SUBJECT_H
#define SUBJECT_H

#include "ISubject.hpp"
#include "Observer.hpp"
#include <stdio.h>

namespace ascii { namespace Listener {
    //! ***********************
    //!     Singleton class
    //! ***********************
    class Subject : ISubject { 
        private:
            Subject() noexcept;
            ~Subject() noexcept;
            static Subject* singleton_;
        public:
            inline static Subject &getInstance() noexcept;

            void Notify() noexcept;
            void attach(ascii::Observer *observer) noexcept;
            void detach(ascii::Observer *observer) noexcept;
            inline void createMessage(const char* message = "NoneEvent") noexcept;

        private:
            ascii::Observer* head = NULL;
            const char* message_;
    };
    void Subject::createMessage(const char* message) noexcept {
        message_ = message;
        Notify();
    }
    Subject &Subject::getInstance() noexcept {
        static Subject *instance = new Subject();
        return *instance;
    }
}} // namespace ascii::Listener
#endif // SUBJECT_H