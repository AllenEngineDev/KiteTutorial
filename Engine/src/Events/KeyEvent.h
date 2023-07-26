#pragma once
#include "Event.h"

namespace Kite {

    // This is a KeyEvent base class for KeyPressed and KeyReleased Events
    // This is not meant to be directly instantiated. It has a protected constructor.
    class KITE_API KeyEvent : public Event 
    {
    public:
        inline int GetKeyCode() { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode) { }
        int m_KeyCode;
    };

    // Instantiate with keycode and repeat count
    class KITE_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) { }
        
        inline int GetRepeatCount() { return m_RepeatCount; }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: Keycode -> " << m_KeyCode << ", Repeat count -> " << m_RepeatCount;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_RepeatCount;
    };

    class KITE_API KeyReleasedEvent : public KeyEvent 
    {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) { }
        
        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: Keycode -> " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}