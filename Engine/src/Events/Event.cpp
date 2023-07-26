#include "Event.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include "WindowEvent.h"

std::ostream& operator<<(std::ostream& os, const Kite::Event& event)
{
    os << event.ToString();
    return os;
}