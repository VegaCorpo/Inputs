#pragma once

#include <array>
#include <GLFW/glfw3.h>
#include "bindings/KeyBinding.hpp"

namespace inputs {
    inline constexpr auto DEFAULT_KEY_BINDINGS = std::to_array<KeyBinding>({
        {GLFW_KEY_W, onPress, common::Action::MOVE_CAMERA_FORWARD},
        {GLFW_KEY_W, onRelease, common::Action::MOVE_CAMERA_BACKWARD},
        {GLFW_KEY_S, onPress, common::Action::MOVE_CAMERA_BACKWARD},
        {GLFW_KEY_S, onRelease, common::Action::MOVE_CAMERA_FORWARD},
        {GLFW_KEY_A, onPress, common::Action::MOVE_CAMERA_LEFT},
        {GLFW_KEY_A, onRelease, common::Action::MOVE_CAMERA_RIGHT},
        {GLFW_KEY_D, onPress, common::Action::MOVE_CAMERA_RIGHT},
        {GLFW_KEY_D, onRelease, common::Action::MOVE_CAMERA_LEFT},
        {GLFW_KEY_SPACE, onPress, common::Action::MOVE_CAMERA_UP},
        {GLFW_KEY_SPACE, onRelease, common::Action::MOVE_CAMERA_DOWN},
        {GLFW_KEY_LEFT_CONTROL, onPress, common::Action::MOVE_CAMERA_DOWN},
        {GLFW_KEY_LEFT_CONTROL, onRelease, common::Action::MOVE_CAMERA_UP},
        {GLFW_KEY_UP, onPress, common::Action::ROTATE_CAMERA_UP},
        {GLFW_KEY_UP, onRelease, common::Action::ROTATE_CAMERA_DOWN},
        {GLFW_KEY_DOWN, onPress, common::Action::ROTATE_CAMERA_DOWN},
        {GLFW_KEY_DOWN, onRelease, common::Action::ROTATE_CAMERA_UP},
        {GLFW_KEY_LEFT, onPress, common::Action::ROTATE_CAMERA_LEFT},
        {GLFW_KEY_LEFT, onRelease, common::Action::ROTATE_CAMERA_RIGHT},
        {GLFW_KEY_RIGHT, onPress, common::Action::ROTATE_CAMERA_RIGHT},
        {GLFW_KEY_RIGHT, onRelease, common::Action::ROTATE_CAMERA_LEFT},
        {GLFW_KEY_H, onRelease, common::Action::CHANGE_RESCALE_MODE},
    });
} // namespace inputs
