#pragma once

#include <unordered_map>
#include <queue>
#include "types/types.hpp"
#define GLFW_DLL
#include "GLFW/glfw3.h"

namespace common {
    class IInput {
        public:
            virtual ~IInput() = default;

            virtual void init() = 0;

            virtual void setKeyCallback() = 0;
            virtual void updateActions() = 0;
    };
}

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
            // keyCallback handles key event.
            static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

            // hasAction checks if action exists for a specific key event.
            static bool hasAction(std::unordered_map<int, common::Action> listActions, int status);

            GLFWwindow* glfwWin;
            std::queue<common::Action> actions;
    };
} // namespace inputs
