#pragma once

#include <bitset>
#include <cstddef>
#include <GLFW/glfw3.h>
#include "keyboard/KeyTransition.hpp"

namespace inputs {
    class KeyboardState {
        public:
            explicit KeyboardState(GLFWwindow* window);

            void update();

            [[nodiscard]] KeyTransition transitionOf(int key) const;

        private:
            static constexpr std::size_t KEY_COUNT = GLFW_KEY_LAST + 1;

            GLFWwindow* _window;
            std::bitset<KEY_COUNT> _previouslyDown;
            std::bitset<KEY_COUNT> _currentlyDown;
    };
} // namespace inputs
