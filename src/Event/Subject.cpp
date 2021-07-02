#include "../../asciiengine/Event/Subject.hpp"

ascii::Listener::ISubject::~ISubject(){
    printf("INFO : ISubject is created\n");
};

//! Init

ascii::Listener::Subject *ascii::Listener::Subject::singleton_{nullptr};

//! Functions

ascii::Listener::Subject::Subject() {}
ascii::Listener::Subject::~Subject() {}

ascii::Listener::Subject *ascii::Listener::Subject::GetInstance() {
    if(singleton_ == nullptr){
        singleton_ = new Subject();
    }
    return singleton_;
}

void ascii::Listener::Subject::Notify() {
    for(auto observer : observers) {
        observer->Update(message_);
    }
}
void ascii::Listener::Subject::Attach(ascii::IObject *observer) {
    observers.push_back(observer);
}
void ascii::Listener::Subject::Detach(ascii::IObject *observer) {
    observers.remove(observer);
}
void ascii::Listener::Subject::CreateMessage(const char* message) {
    this->message_ = message;
    Notify();
}