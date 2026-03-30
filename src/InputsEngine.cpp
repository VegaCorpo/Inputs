#include "InputsEngine.hpp"
#include "Commands.hpp"

inputs::InputsEngine::InputsEngine()
{
    this->_glfwWin = nullptr;
    this->_actions = {};
}

static std::unordered_map<int, int> actionsTemp = {};

void inputs::InputsEngine::_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    actionsTemp[key] = action;
}

void inputs::InputsEngine::init()
{
    this->_glfwWin = glfwGetCurrentContext();
}

void inputs::InputsEngine::setKeyCallback()
{
    if (this->_glfwWin != nullptr) {
        glfwSetKeyCallback(this->_glfwWin, inputs::InputsEngine::_keyCallback);
    }
}

bool inputs::InputsEngine::_hasAction(std::unordered_map<int, common::Action> &listActions, int status)
{
    return listActions.contains(status);
}

void inputs::InputsEngine::updateActions()
{
    for (const auto& [key, status] : actionsTemp) {
        if (inputs::commands.find(key) != inputs::commands.end()) {
            if (this->_hasAction(inputs::commands.at(key), status)) {
                this->_actions.push(inputs::commands.at(key).at(status));
            }
        }
    }

    actionsTemp.clear();
}
