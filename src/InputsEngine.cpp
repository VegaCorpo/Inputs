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
    if (!this->_keyboard || !this->_keyboard->IsAvailable())
       std::cerr << "Keyboard gainput unavailable" << std::endl;
}

void inputs::InputsEngine::update()
{
    this->_manager.Update();

    for (auto key : this->_keysHandler) {
        if (this->_keyboard->GetBool(key)) {
            auto action = this->_listActions.find(key);
            if (action != this->_listActions.end())
                this->_actions.push(action->second);
        }
    }
}

std::queue<common::Action> inputs::InputsEngine::getActions() {
    return std::exchange(this->_actions, std::queue<common::Action>{});
}

const std::unordered_map<gainput::Key, common::Action> inputs::InputsEngine::_listActions = {
    {gainput::KeyA, common::Action::MOVE_CAMERA_FORWARD},
    {gainput::KeyQ, common::Action::MOVE_CAMERA_LEFT},
    {gainput::KeyW, common::Action::MOVE_CAMERA_FORWARD},
    {gainput::KeyS, common::Action::MOVE_CAMERA_BACKWARD},
    {gainput::KeyD, common::Action::MOVE_CAMERA_RIGHT}
};
