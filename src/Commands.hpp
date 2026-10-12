// #pragma once

// #include <unordered_map>
// #include "GLFW/glfw3.h"
// #include "types/types.hpp"
// #include <iostream>
// #include <memory>

// namespace inputs {
//     class ICommand {
//         public:
//             virtual ~ICommand() {};
//             virtual void execute() = 0;
//     };

//     class ACommand : public ICommand {
//         public:
//             ACommand(std::string toremove) {
//                 this->temp = toremove;
//             };
//             void execute() {
//                 std::cout << this->temp << std::endl;
//             }
//         private:
//             std::string temp;
//     };

    // static const std::unordered_map<int, std::unordered_map<int, std::unique_ptr<inputs::ICommand>>> commands = {
//         {GLFW_KEY_Z,
//          {
//              {GLFW_PRESS, ACommand("GLFW_KEY_Z => GLFW_PRESS")},
//              {GLFW_RELEASE, ACommand("GLFW_KEY_Z => GLFW_RELEASE")},
//          }},
//         {GLFW_KEY_S,
//          {
//              {GLFW_PRESS, ACommand("GLFW_KEY_S => GLFW_PRESS")},
//              {GLFW_RELEASE, ACommand("GLFW_KEY_S => GLFW_RELEASE")},
//          }},
//         {GLFW_KEY_Q,
//          {
//              {GLFW_PRESS, ACommand("GLFW_KEY_Q => GLFW_PRESS")},
//              {GLFW_RELEASE, ACommand("GLFW_KEY_Q => GLFW_RELEASE")},
//          }},
//         {GLFW_KEY_D,
//          {
//              {GLFW_PRESS, ACommand("GLFW_KEY_D => GLFW_PRESS")},
//              {GLFW_RELEASE, ACommand("GLFW_KEY_D => GLFW_RELEASE")},
//          }}
//     };
// } // namespace inputs
