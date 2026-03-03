#include <iostream>
#include <memory>
#include "InputsEngine.hpp"

extern "C++" {
    std::unique_ptr<inputs::InputsEngine> get_inputs_engine()
    {
        std::cout << "Hello from inputs engine" << std::endl;
        return std::make_unique<inputs::InputsEngine>();
    }
}
