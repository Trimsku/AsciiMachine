#include "../../../asciiengine/common/event/Subject.hpp"

ascii::Listener::ISubject::~ISubject() noexcept {
}

//! Functions

ascii::Listener::Subject::Subject() noexcept {}
ascii::Listener::Subject::~Subject() noexcept {}

ascii::Listener::Subject &ascii::Listener::Subject::getInstance() noexcept {
    static Subject *instance = new Subject();
    return *instance;
}

void ascii::Listener::Subject::Notify() noexcept {
    Observer* observer = head;
    while (observer != NULL) {
        observer->update(message_);
        observer = observer->next;
    }
}
void ascii::Listener::Subject::attach(ascii::Observer *observer) noexcept {
    observer->next = head;
    head = observer;
}
void ascii::Listener::Subject::detach(ascii::Observer *observer) noexcept {
    if (head == observer) {
    head = observer->next;
    observer->next = NULL;
    return;
  }

  Observer* current = head;
  while (current != NULL) {
    if (current->next == observer) {
      current->next = observer->next;
      observer->next = NULL;
      return;
    }

    current = current->next;
  }
}
void ascii::Listener::Subject::createMessage(const char* message) noexcept {
    message_ = message;
    Notify();
}