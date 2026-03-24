#pragma once

#include <unordered_map>
#include "GLFW/glfw3.h"
#include "../../Common/types/types.hpp"

namespace inputs {
    static const std::unordered_map<int, std::unordered_map<int, common::Action>> commands = {
        {GLFW_KEY_Z,
         {
             {GLFW_PRESS, common::Action::MOVE_CAMERA_FORWARD},
             {GLFW_RELEASE, common::Action::MOVE_CAMERA_BACKWARD},
         }},
        {GLFW_KEY_S,
         {
             {GLFW_PRESS, common::Action::MOVE_CAMERA_BACKWARD},
             {GLFW_RELEASE, common::Action::MOVE_CAMERA_FORWARD},
         }},
        {GLFW_KEY_Q,
         {
             {GLFW_PRESS, common::Action::MOVE_CAMERA_LEFT},
             {GLFW_RELEASE, common::Action::MOVE_CAMERA_RIGHT},
         }},
        {GLFW_KEY_D,
         {
             {GLFW_PRESS, common::Action::MOVE_CAMERA_RIGHT},
             {GLFW_RELEASE, common::Action::MOVE_CAMERA_LEFT},
         }},
        {GLFW_KEY_SPACE,
         {
             {GLFW_PRESS, common::Action::MOVE_CAMERA_UP},
             {GLFW_RELEASE, common::Action::MOVE_CAMERA_DOWN},
         }},
        {GLFW_KEY_LEFT_CONTROL,
         {
             {GLFW_PRESS, common::Action::MOVE_CAMERA_DOWN},
             {GLFW_RELEASE, common::Action::MOVE_CAMERA_UP},
         }},
        {GLFW_KEY_UP,
         {
             {GLFW_PRESS, common::Action::ROTATE_CAMERA_UP},
             {GLFW_RELEASE, common::Action::ROTATE_CAMERA_DOWN},
         }},
        {GLFW_KEY_DOWN,
         {
             {GLFW_PRESS, common::Action::ROTATE_CAMERA_DOWN},
             {GLFW_RELEASE, common::Action::ROTATE_CAMERA_UP},
         }},
        {GLFW_KEY_LEFT,
         {
             {GLFW_PRESS, common::Action::ROTATE_CAMERA_LEFT},
             {GLFW_RELEASE, common::Action::ROTATE_CAMERA_RIGHT},
         }},
        {GLFW_KEY_RIGHT,
         {
             {GLFW_PRESS, common::Action::ROTATE_CAMERA_RIGHT},
             {GLFW_RELEASE, common::Action::ROTATE_CAMERA_LEFT},
         }},
    };
} // namespace inputs
