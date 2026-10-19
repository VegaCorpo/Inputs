#pragma once

#include <unordered_map>
#include <queue>
// #include "types/types.hpp"

#include "../../Common/interfaces/IInputEngine.hpp"
#include "types/types.hpp"
#include <gainput/gainput.h>
#include <GLFW/glfw3.h>
#include "./Commands.hpp"

namespace inputs {
    class InputsEngine : public common::IInputEngine {
        public:
            InputsEngine();
            ~InputsEngine() = default;

            // init gets window context.
            void init() override;

            void update() override;

            // // setKeyCallback sets function for key event.
            // void setKeyCallback() override;

            // // updateActions adds actions in queue.
            // void updateActions();
        private:
            gainput::InputManager _manager;
            gainput::InputDevice* _keyboard;

            // // _keyCallback handles key event.
            // static void _keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

            // // _hasAction checks if action exists for a specific key event.
            // static bool _hasAction(std::unordered_map<int, common::Action> &listActions, int status);

            GLFWwindow* _glfwWin;
            std::queue<common::Action> _actions;

        // static const std::unordered_map<int, std::unordered_map<int, common::Action>> _listActions = {
        //     {GLFW_KEY_Z,
        //     {
        //         {GLFW_PRESS, common::Action::MOVE_CAMERA_FORWARD},
        //         {GLFW_RELEASE, common::Action::MOVE_CAMERA_FORWARD},
        //     }},
        //     {GLFW_KEY_S,
        //     {
        //         {GLFW_PRESS, common::Action::MOVE_CAMERA_BACKWARD},
        //         {GLFW_RELEASE, common::Action::MOVE_CAMERA_BACKWARD},
        //     }},
        //     {GLFW_KEY_Q,
        //     {
        //         {GLFW_PRESS, common::Action::MOVE_CAMERA_LEFT},
        //         {GLFW_RELEASE, common::Action::MOVE_CAMERA_LEFT},
        //     }},
        //     {GLFW_KEY_D,
        //     {
        //         {GLFW_PRESS, common::Action::MOVE_CAMERA_RIGHT},
        //         {GLFW_RELEASE, common::Action::MOVE_CAMERA_RIGHT},
        //     }}
        // };

        static const std::unordered_map<gainput::Key, common::Action> _listActions;

        static const std::unordered_map<common::Action, std::shared_ptr<inputs::ICommand>> _commands;

        std::vector<gainput::Key> _keysHandler = {gainput::KeyA, gainput::KeyQ, gainput::KeyD, gainput::KeyS, gainput::KeyW};

    };  
} // namespace inputs
