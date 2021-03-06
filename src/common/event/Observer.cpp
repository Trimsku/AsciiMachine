#include "../../../asciiengine/common/event/IObserver.hpp"
#include "../../../asciiengine/common/event/Observer.hpp"
#include "../../../asciiengine/common/event/Subject.hpp"

ascii::IObserver::~IObserver() noexcept {
}

ascii::Observer::~Observer() noexcept
{ 
    printf("Observer `%s` is destroyed\n", name); 
}
ascii::Observer::Observer(const char* name_) noexcept { 
    ascii::Listener::Subject::getInstance().attach(this); 
    name = name_;
}
void ascii::Observer::update(const char* event_type) noexcept {
    event = event_type;
    markAsReceivedNewEvent = true;
}

void ascii::Observer::removeFromTheList() noexcept {
    ascii::Listener::Subject::getInstance().detach(this);
}