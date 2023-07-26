#pragma once
#include "Event.h"

namespace Kite {
    class KITE_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) { }

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString()
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: Position: (" << m_MouseX << ", " << m_MouseY << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;
    };


    class KITE_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)    
            : m_XOffset(xOffset), m_YOffset(yOffset) { }

        inline float GetXOffset() const { return m_XOffset; }
        inline float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: Scroll offset -> (" << m_XOffset << ", " << m_YOffset << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_XOffset, m_YOffset;
    };


    class KITE_API MouseButtonEvent : public Event
    {
    public:
        MouseButtonEvent(int button)
            : m_Button(button) { }

        inline int GetButtonCode() { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)
    protected:
        int m_Button;
    };


    class KITE_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) { }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonPressed: Button -> " << m_Button;
            return ss.str(); 
        }
        
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };


    class KITE_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) { }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonReleased: Button -> " << m_Button;
            return ss.str(); 
        }
        
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}