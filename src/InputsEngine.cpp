#include "InputsEngine.hpp"
#include <iostream>
// #include "Commands.hpp"

inputs::InputsEngine::InputsEngine()
{
    // this->_glfwWin = nullptr;
    // this->_actions = {};

    gainput::DeviceId keyboardId = this->_manager.CreateDevice<gainput::InputDeviceKeyboard>(
        gainput::InputDevice::AutoIndex, gainput::InputDevice::DV_RAW);
    this->_keyboard = this->_manager.GetDevice(keyboardId);
}

// static std::unordered_map<int, int> actionsTemp = {};

// void inputs::InputsEngine::_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     actionsTemp[key] = action;
// }

void inputs::InputsEngine::init()
{
    this->_glfwWin = glfwGetCurrentContext();
    std::cout << "Hello from inputs engine" << std::endl;
    std::cout << "Ca a bien init !" << std::endl;
    if (!this->_keyboard || !this->_keyboard->IsAvailable())
       std::cerr << "Clavier gainput indisponible" << std::endl;
}

void inputs::InputsEngine::update()
{
    // std::cout << "Update appelé" << std::endl;
    this->_manager.Update();

    if (this->_keyboard->GetBool(gainput::KeyA))
    {
        std::cout << "A click !" << std::endl;
    }

    if (this->_keyboard->GetBool(gainput::KeyQ))
    {
        std::cout << "Q click !" << std::endl;
    }

    if (this->_keyboard->GetBool(gainput::KeyS))
    {
        std::cout << "S click !" << std::endl;
    }

    if (this->_keyboard->GetBool(gainput::KeyZ))
    {
        std::cout << "Z click !" << std::endl;
    }

    if (this->_keyboard->GetBool(gainput::KeyD))
    {
        std::cout << "D click !" << std::endl;
    }
    // std::cout << "Update finished" << std::endl;
}

// void inputs::InputsEngine::setKeyCallback()
// {
//     if (this->_glfwWin != nullptr) {
//         glfwSetKeyCallback(this->_glfwWin, inputs::InputsEngine::_keyCallback);
//     }
// }

// bool inputs::InputsEngine::_hasAction(std::unordered_map<int, common::Action> &listActions, int status)
// {
//     return listActions.contains(status);
// }

// void inputs::InputsEngine::updateActions()
// {
//     for (const auto& [key, status] : actionsTemp) {
//         if (inputs::commands.find(key) != inputs::commands.end()) {
//             if (this->_hasAction(inputs::commands.at(key), status)) {
//                 this->_actions.push(inputs::commands.at(key).at(status));
//             }
//         }
//     }

//     actionsTemp.clear();
// }
