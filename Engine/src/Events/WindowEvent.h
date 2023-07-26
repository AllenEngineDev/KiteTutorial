#include "Event.h"

namespace Kite  {
    class KITE_API WindowResizeEvent : public Event 
    {
    public:
        WindowResizeEvent(float width, float height)
            : m_Width(width), m_Height(height) { }

        inline float GetWidth() { return m_Width; }
        inline float GetHeight() { return m_Height; }

        EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryInput)
        EVENT_CLASS_TYPE(WindowResize)
    private:
        float m_Width, m_Height;
    };  

    class KITE_API WindowCloseEvent : public Event 
    {
    public:
        WindowCloseEvent() { }
        EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryInput)
        EVENT_CLASS_TYPE(WindowClose)
    };
}