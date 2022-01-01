#ifndef OBJECT_H
#define OBJECT_H

#include "IObject.hpp"
#include "Subject.hpp"
#include "../../astd/String.hpp"

namespace ascii
{
    
    class Object : public ascii::IObject {
        public:
            ~Object() noexcept;
            Object(const char* name) noexcept;
            void update(const char* event_type) noexcept;
            void removeFromTheList() noexcept;
            bool isGotNewEvent();
            astd::string getEventName();
        private:
            bool markAsReceivedNewEvent = false;
            const char* name;
            astd::string event;
    };

} // namespace ascii

#endif
