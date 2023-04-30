#include "pch.h"
#include "framework.h"
#include "Core.h"
#include <memory>

namespace AmpStudio
{
    struct Base
    {
        virtual int Testing()
        {
            return 999;
        }
        virtual ~Base() = default;
    };

    struct Derived : public Base
    {
        int Testing() override
        {
            return 789;
        }
    };

    std::unique_ptr<Base> MakeDerived()
    {
        return std::make_unique<Derived>();
    }
    int Testing()
    {
        return MakeDerived()->Testing();
    }
}
