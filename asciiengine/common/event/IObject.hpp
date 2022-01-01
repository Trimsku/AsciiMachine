#ifndef IOBJECT_H
#define IOBJECT_H

namespace ascii
{
    class IObject {
        public:
            virtual ~IObject();
            virtual void update(const char* event_type) noexcept = 0;
    };

} // namespace ascii

#endif // IOBJECT_H