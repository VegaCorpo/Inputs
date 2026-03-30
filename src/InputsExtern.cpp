#include <memory>

extern "C" {
    std::unique_ptr<inputs::InputsEngine> get_inputs_engine()
    {
        return std::make_unique<inputs::InputsEngine>();
    }
}
