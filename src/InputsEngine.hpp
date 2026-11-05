#pragma once

#include <interfaces/IInputsEngine.hpp>
#include <optional>
#include <queue>
#include <span>
#include "bindings/KeyBinding.hpp"
#include "keyboard/KeyboardState.hpp"
#include "mouse/MouseState.hpp"

namespace inputs {
    class InputsEngine : public common::IInputsEngine {
        public:
            explicit InputsEngine(std::span<const KeyBinding> bindings);

            [[nodiscard]] bool init(void* windowHandle) override;
            [[nodiscard]] std::queue<common::InputAction> poll() override;

        private:
            [[nodiscard]] bool _isTriggered(const KeyBinding& binding) const;

            std::span<const KeyBinding> _bindings;
            std::optional<KeyboardState> _keyboard;
            std::optional<MouseState> _mouse;
    };
} // namespace inputs
