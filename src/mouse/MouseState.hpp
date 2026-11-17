#pragma once

#include <GLFW/glfw3.h>
#include <optional>
#include <types/types.hpp>

namespace inputs {
    /**
     * @brief Tracks mouse movement for camera rotation.
     *
     * Mouse rotation is only active while Alt is held: the cursor is then captured and its movement reported.
     * Otherwise the cursor is free and nothing is reported.
     */
    class MouseState {
        public:
            explicit MouseState(GLFWwindow* window);

            [[nodiscard]] std::optional<common::InputAction> update();

        private:
            [[nodiscard]] bool _isModifierDown() const;
            void _capture();
            void _release();

            GLFWwindow* _window;
            bool _captured = false;
            double _lastX = 0.0;
            double _lastY = 0.0;
    };
} // namespace inputs
