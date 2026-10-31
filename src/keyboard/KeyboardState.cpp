#include "keyboard/KeyboardState.hpp"
#include <ranges>

inputs::KeyboardState::KeyboardState(GLFWwindow* window) : _window(window)
{}

void inputs::KeyboardState::update()
{
    this->_previouslyDown = this->_currentlyDown;

    for (const int key : std::views::iota(GLFW_KEY_SPACE, GLFW_KEY_LAST + 1))
        this->_currentlyDown[static_cast<std::size_t>(key)] = glfwGetKey(this->_window, key) == GLFW_PRESS;
}

inputs::KeyTransition inputs::KeyboardState::transitionOf(int key) const
{
    const auto index = static_cast<std::size_t>(key);

    return {.wasDown = this->_previouslyDown[index], .isDown = this->_currentlyDown[index]};
}
