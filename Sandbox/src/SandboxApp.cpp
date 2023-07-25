#include "Kite.h"


class Sandbox : public Kite::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Kite::Application* Kite::CreateApplication()
{
    return new Sandbox();
}