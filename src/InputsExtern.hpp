#pragma once

#include <memory>
#include <string>
#include <interfaces/IInputEngine.hpp>

extern "C" {
    std::unique_ptr<common::IInputEngine> get_engine();
}
