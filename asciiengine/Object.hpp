#ifndef OBJECT_H
#define OBJECT_H

#include "IObject.hpp"
#include "Event/Subject.hpp"

namespace ascii
{
    
    class Object : public ascii::IObject {
        public:
            ~Object();
            Object(const char* name);
            void Update(const char* event_type);
            void RemoveFromTheList();

        private:
            const char* name;
            const char* event_;
            Listener::Subject *subject_ = Listener::Subject::GetInstance();
    };

} // namespace ascii

#endif