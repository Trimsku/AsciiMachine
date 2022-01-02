#ifndef OBSERVER_H
#define OBSERVER_H

#include "IObserver.hpp"
#include "../../astd/String.hpp"

namespace ascii::Listener {
    class Subject;
}

namespace ascii
{
    
    class Observer : public ascii::IObserver {
        public:
            friend class ascii::Listener::Subject;
            ~Observer() noexcept;
            Observer(const char* name) noexcept;
            void update(const char* event_type) noexcept;
            void removeFromTheList() noexcept;
            bool isGotNewEvent() noexcept;
            void setEventChecked() noexcept;
            astd::string getEventName() noexcept;
        private:
            Observer *next = NULL;
            bool markAsReceivedNewEvent = false;
            const char* name;
            astd::string event;
    };

} // namespace ascii

#endif
