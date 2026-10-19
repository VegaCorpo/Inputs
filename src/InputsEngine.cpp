#include "InputsEngine.hpp"
#include <iostream>
#include <unordered_map>
// #include "Commands.hpp"

inputs::InputsEngine::InputsEngine()
{
    gainput::DeviceId keyboardId = this->_manager.CreateDevice<gainput::InputDeviceKeyboard>(
        gainput::InputDevice::AutoIndex, gainput::InputDevice::DV_RAW);
    this->_keyboard = this->_manager.GetDevice(keyboardId);
}

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

    for (auto key : this->_keysHandler) {
        if (this->_keyboard->GetBool(key)) {
            std::cout << "click !" << std::endl;
            // Cette partie me cause une erreur je ne comprends pas pourquoi
            auto action = this->_listActions.find(key);
            if (action != this->_listActions.end()) {
                auto command = this->_commands.find(action->second);
                if (command != this->_commands.end()) {
                    std::cout << "test";
                    command->second->execute();
                }
            }
        }
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

const std::unordered_map<common::Action, std::shared_ptr<inputs::ICommand>> inputs::InputsEngine::_commands = {
            {common::Action::MOVE_CAMERA_FORWARD, std::make_shared<inputs::ACommand>("FORWARD")},
            {common::Action::MOVE_CAMERA_LEFT, std::make_shared<inputs::ACommand>("LEFT")},
            {common::Action::MOVE_CAMERA_RIGHT, std::make_shared<inputs::ACommand>("RIGHT")},
            {common::Action::MOVE_CAMERA_BACKWARD, std::make_shared<inputs::ACommand>("BACKWARD")}
};

const std::unordered_map<gainput::Key, common::Action> inputs::InputsEngine::_listActions = {
    {gainput::KeyA, common::Action::MOVE_CAMERA_FORWARD},
    {gainput::KeyQ, common::Action::MOVE_CAMERA_LEFT},
    {gainput::KeyW, common::Action::MOVE_CAMERA_FORWARD},
    {gainput::KeyS, common::Action::MOVE_CAMERA_BACKWARD},
    {gainput::KeyD, common::Action::MOVE_CAMERA_RIGHT}
};
