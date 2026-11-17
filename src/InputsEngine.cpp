#include "InputsEngine.hpp"
#include <ranges>

inputs::InputsEngine::InputsEngine(std::span<const KeyBinding> bindings) : _bindings(bindings)
{}

bool inputs::InputsEngine::init(void* windowHandle)
{
    if (windowHandle == nullptr)
        return false;

    auto* window = static_cast<GLFWwindow*>(windowHandle);

    this->_keyboard.emplace(window);
    this->_mouse.emplace(window);
    return true;
}

std::queue<common::InputAction> inputs::InputsEngine::poll()
{
    std::queue<common::InputAction> actions;

    if (!this->_keyboard || !this->_mouse)
        return actions;

    this->_keyboard->update();

    const auto isTriggered = [this](const KeyBinding& binding) { return this->_isTriggered(binding); };

    for (const KeyBinding& binding : this->_bindings | std::views::filter(isTriggered))
        actions.push({.action = binding.action});

    if (const auto mouseAction = this->_mouse->update())
        actions.push(*mouseAction);
    return actions;
}

bool inputs::InputsEngine::_isTriggered(const KeyBinding& binding) const
{
    return binding.trigger(this->_keyboard->transitionOf(binding.key));
}
