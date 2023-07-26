#pragma once
#include "ktpch.h"

#include "Core.h"
#include "Log.h"

namespace Kite {
    enum class EventType
    {
        WindowClose, WindowResize, WindowMoved,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved 
    };

    // This are to be used as flags
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryMouse          = BIT(1),
        EventCategoryInput          = BIT(2),
        EventCategoryKeyboard       = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    // Defines some common member functions for each class derived from Event
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; } \

    #define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override { return category; } \


    class KITE_API Event 
    {   
    public:
        virtual EventType GetType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags()  const= 0;

        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            // Bit masking -> checking if the bit for the category is "turned on" in our category
            // Always define the category of an event class using the EVENT_CLASS_CATEGORY macro
            return GetCategoryFlags() & (int)category;
        }
    protected:
        bool m_Handled = false;
    };

    template<typename T>
    class KITE_API EventDispatcher
    {
    public:
        using EventFn = std::function<bool(T&)>;
        EventDispatcher(Event& event)
            : m_Event(event) { }

        bool Dispatch(EventFn func)
        {
            if (m_Event.GetType() == T::GetStaticType())
            {
                bool isHandled = func(*((T*)&m_Event));
                return isHandled;
            }
            else 
            {

                return false;
            }
        }   
    private:
        Event& m_Event;   
    };
}

std::ostream& operator<<(std::ostream& os, const Kite::Event& event);
