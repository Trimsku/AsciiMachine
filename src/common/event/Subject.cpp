#include "../../../asciiengine/common/event/Subject.hpp"

ascii::Listener::ISubject::~ISubject() noexcept {
}

//! Init

ascii::Listener::Subject *ascii::Listener::Subject::singleton_{nullptr};

//! Functions

ascii::Listener::Subject::Subject() noexcept {}
ascii::Listener::Subject::~Subject() noexcept {}

ascii::Listener::Subject *ascii::Listener::Subject::getInstance() noexcept {
    if(singleton_ == nullptr){
        singleton_ = new Subject();
    }
    return singleton_;
}

void ascii::Listener::Subject::Notify() noexcept {
    for(auto observer : observers) {
        observer->update(message_);
    }
}
void ascii::Listener::Subject::attach(ascii::IObject *observer) noexcept {
    observers.push_back(observer);
}
void ascii::Listener::Subject::detach(ascii::IObject *observer) noexcept {
    observers.remove(observer);
}
void ascii::Listener::Subject::createMessage(const char* m_message) noexcept {
    message_ = m_message;
    Notify();
}