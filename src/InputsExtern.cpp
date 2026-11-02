#include <memory>
#include "bindings/DefaultKeyBindings.hpp"
#include "InputsEngine.hpp"

extern "C" {
    std::unique_ptr<common::IInputsEngine> get_engine()
    {
        return std::make_unique<inputs::InputsEngine>(inputs::DEFAULT_KEY_BINDINGS);
    }
}
