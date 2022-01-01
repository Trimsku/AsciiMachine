#include "../../../asciiengine/common/event/IObject.hpp"
#include "../../../asciiengine/common/event/Object.hpp"

ascii::IObject::~IObject() noexcept {
}

ascii::Object::~Object() noexcept
{ 
    printf("Observer `%s` is destroyed\n", name); 
}
ascii::Object::Object(const char* name_) noexcept { 
    ascii::Listener::Subject::getInstance()->attach(this); 
    name = name_;
}

bool ascii::Object::isGotNewEvent() {
    if(markAsReceivedNewEvent) {
        markAsReceivedNewEvent = false;
        return true;
    }
    return false;
}

astd::string ascii::Object::getEventName() {
    return event;
}

void ascii::Object::update(const char* event_type) noexcept {
    event = event_type;
    markAsReceivedNewEvent = true;
}

void ascii::Object::removeFromTheList() noexcept {
    ascii::Listener::Subject::getInstance()->detach(this);
}