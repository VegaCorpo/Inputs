#pragma once

#include <unordered_map>
#include <queue>
// #include "types/types.hpp"

#include "../../Common/interfaces/IInputEngine.hpp"
#include "types/types.hpp"
#include <gainput/gainput.h>
#include <GLFW/glfw3.h>
#include "./Commands.hpp"

#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <X11/Xlib.h> 

namespace inputs {
    class InputsEngine : public common::IInputEngine {
        public:
            InputsEngine();
            ~InputsEngine() = default;

            // init gets window context.
            void init() override;

            void update() override;

        private:
            static void _keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

            gainput::InputManager _manager;
            gainput::InputDevice* _keyboard;

            GLFWwindow* _glfwWin;
            std::queue<common::Action> _actions;

        static const std::unordered_map<gainput::Key, common::Action> _listActions;

        static const std::unordered_map<common::Action, std::shared_ptr<inputs::ICommand>> _commands;

        std::vector<gainput::Key> _keysHandler = {gainput::KeyA, gainput::KeyQ, gainput::KeyD, gainput::KeyS, gainput::KeyW};

    };  
} // namespace inputs
