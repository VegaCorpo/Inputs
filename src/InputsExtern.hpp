#pragma once

#include <memory>
#include <string>
// #include <interfaces/IInputEngine.hpp>
#include "../../Common/interfaces/IInputEngine.hpp"

extern "C" {
    std::unique_ptr<common::IInputEngine> get_engine();
}
