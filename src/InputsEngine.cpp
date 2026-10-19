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
    if (!this->_keyboard || !this->_keyboard->IsAvailable())
       std::cerr << "Keyboard gainput unavailable" << std::endl;
}

void inputs::InputsEngine::update()
{
    this->_manager.Update();

    for (auto key : this->_keysHandler) {
        if (this->_keyboard->GetBool(key)) {
            auto action = this->_listActions.find(key);
            if (action != this->_listActions.end()) {
                auto command = this->_commands.find(action->second);
                if (command != this->_commands.end())
                    command->second->execute();
            }
        }
    }
}

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
