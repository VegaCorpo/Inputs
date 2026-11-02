#include "InputsEngine.hpp"
#include <ranges>

inputs::InputsEngine::InputsEngine(std::span<const KeyBinding> bindings) : _bindings(bindings)
{}

bool inputs::InputsEngine::init(void* windowHandle)
{
    if (windowHandle == nullptr)
        return false;

    this->_keyboard.emplace(static_cast<GLFWwindow*>(windowHandle));
    return true;
}

std::queue<common::Action> inputs::InputsEngine::poll()
{
    std::queue<common::Action> actions;

    if (!this->_keyboard)
        return actions;

    this->_keyboard->update();

    const auto isTriggered = [this](const KeyBinding& binding) { return this->_isTriggered(binding); };

    for (const KeyBinding& binding : this->_bindings | std::views::filter(isTriggered))
        actions.push(binding.action);
    return actions;
}

bool inputs::InputsEngine::_isTriggered(const KeyBinding& binding) const
{
    return binding.trigger(this->_keyboard->transitionOf(binding.key));
}
