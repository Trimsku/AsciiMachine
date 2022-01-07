#pragma once

namespace ascii
{
    class IObserver {
        public:
            virtual ~IObserver() noexcept;
            virtual void update(const char* event_type) noexcept = 0;
    };

} // namespace ascii