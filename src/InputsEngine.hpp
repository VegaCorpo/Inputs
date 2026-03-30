#pragma once

#include <unordered_map>
#include <queue>
#include "types/types.hpp"
#define GLFW_DLL
#include "GLFW/glfw3.h"

namespace inputs {
    class InputsEngine : public common::IInput {
        public:
            InputsEngine();
            ~InputsEngine() = default;

            // init gets window context.
            void init() override;

            // setKeyCallback sets function for key event.
            void setKeyCallback() override;

            // updateActions adds actions in queue.
            void updateActions() override;
        private:
            // _keyCallback handles key event.
            static void _keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

            // _hasAction checks if action exists for a specific key event.
            static bool _hasAction(std::unordered_map<int, common::Action> listActions, int status);

            GLFWwindow* _glfwWin;
            std::queue<common::Action> _actions;
    };
} // namespace inputs
