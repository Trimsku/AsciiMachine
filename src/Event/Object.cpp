#include "../../asciiengine/IObject.hpp"

ascii::IObject::~IObject() {
    printDebug(LogLevel::Log, "IObject is destroyed\n");
}

#include "../../asciiengine/Object.hpp"

ascii::Object::~Object() 
{ 
    printDebug(LogLevel::Log ,"Normal observer: %s%s\n", name, " is destroyed"); 
}
ascii::Object::Object(const char* name){ 
    subject_->Attach(this); 
    this->name = name;
}

void ascii::Object::Update(const char* event_type) {
    event_ = event_type;
    printDebug(LogLevel::Dev, "%s: new message : %s\n", name, event_); 
}

void ascii::Object::RemoveFromTheList() {
    subject_->Detach(this);
}