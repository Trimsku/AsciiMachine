#pragma once
#include "Observer.hpp"

namespace ascii { namespace Listener {
    class ISubject {
        public:
            virtual ~ISubject() noexcept;
            virtual void attach(ascii::Observer *observer) noexcept = 0;
            virtual void detach(ascii::Observer *observer) noexcept = 0;
            virtual void Notify() noexcept = 0;
    };
}} // namespace ascii::Listener