#include "mouse/MouseState.hpp"

inputs::MouseState::MouseState(GLFWwindow* window) : _window(window)
{}

std::optional<common::InputAction> inputs::MouseState::update()
{
    if (!this->_isModifierDown()) {
        if (this->_captured)
            this->_release();
        return std::nullopt;
    }

    if (!this->_captured) {
        // Reference point reset on capture to avoid a camera jump
        this->_capture();
        return std::nullopt;
    }

    double x = 0.0;
    double y = 0.0;
    glfwGetCursorPos(this->_window, &x, &y);

    if (x == this->_lastX && y == this->_lastY)
        return std::nullopt;

    const common::InputAction action = {
        .action = common::Action::ROTATE_CAMERA_MOUSE,
        .x = static_cast<float>(x - this->_lastX),
        .y = static_cast<float>(y - this->_lastY),
    };

    this->_lastX = x;
    this->_lastY = y;
    return action;
}

bool inputs::MouseState::_isModifierDown() const
{
    return glfwGetKey(this->_window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS ||
        glfwGetKey(this->_window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS;
}

void inputs::MouseState::_capture()
{
    glfwSetInputMode(this->_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (glfwRawMouseMotionSupported() == GLFW_TRUE)
        glfwSetInputMode(this->_window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    glfwGetCursorPos(this->_window, &this->_lastX, &this->_lastY);
    this->_captured = true;
}

void inputs::MouseState::_release()
{
    if (glfwRawMouseMotionSupported() == GLFW_TRUE)
        glfwSetInputMode(this->_window, GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
    glfwSetInputMode(this->_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    this->_captured = false;
}
