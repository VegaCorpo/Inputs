#include "InputsEngine.hpp"
#include "Commands.hpp"
#include <iostream>
#include <memory>

extern "C++" {
    std::unique_ptr<inputs::InputsEngine> get_inputs_engine()
    {
        std::cout << "Hello from inputs engine" << std::endl;
        return std::make_unique<inputs::InputsEngine>();
    }
}

inputs::InputsEngine::InputsEngine()
{
    this->glfwWin = nullptr;
    this->actions = {};
}

static std::unordered_map<int, int> actionsTemp = {};

void inputs::InputsEngine::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    actionsTemp[key] = action;
}

void inputs::InputsEngine::init()
{
    this->glfwWin = glfwGetCurrentContext();
}

void inputs::InputsEngine::setKeyCallback()
{
    if (this->glfwWin != nullptr) {
        glfwSetKeyCallback(this->glfwWin, inputs::InputsEngine::keyCallback);
    }
}

bool inputs::InputsEngine::hasAction(std::unordered_map<int, common::Action> listActions, int status)
{
    if (listActions.find(status) != listActions.end())
        return true;
    return false;
}

void inputs::InputsEngine::updateActions()
{
    for (const auto& [key, status] : actionsTemp) {
        if (inputs::commands.find(key) != inputs::commands.end()) {
            if (hasAction(inputs::commands.at(key), status)) {
                this->actions.push(inputs::commands.at(key).at(status));
            }
        }
    }

    actionsTemp.clear();
}
