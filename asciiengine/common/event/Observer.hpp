#ifndef OBSERVER_H
#define OBSERVER_H

#include "IObserver.hpp"
#include "../../astd/String.hpp"

namespace ascii { namespace Listener {
    class Subject;
}}

namespace ascii
{
    class Observer : public ascii::IObserver {
        public:
            friend class ascii::Listener::Subject;
            ~Observer() noexcept;
            Observer(const char* name) noexcept;
            void update(const char* event_type) noexcept;
            void removeFromTheList() noexcept;
            inline bool isGotNewEvent() noexcept;
            inline void setEventChecked() noexcept;
            inline astd::string getEventName() noexcept;
        private:
            Observer *next = NULL;
            bool markAsReceivedNewEvent = false;
            const char* name;
            astd::string event;
    };
    bool ascii::Observer::isGotNewEvent() noexcept {
        return markAsReceivedNewEvent;
    }
    void ascii::Observer::setEventChecked() noexcept {
        markAsReceivedNewEvent = false;
    }
    astd::string ascii::Observer::getEventName() noexcept {
        return event;
    }
} // namespace ascii

#endif
