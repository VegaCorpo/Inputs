#include "InputsExtern.hpp"
#include "InputsEngine.hpp"

extern "C" {
    std::unique_ptr<common::IInputEngine> get_engine()
    {
        return std::make_unique<inputs::InputsEngine>();
    }
}