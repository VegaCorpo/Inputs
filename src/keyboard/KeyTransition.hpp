#pragma once

namespace inputs {
    struct KeyTransition {
            bool wasDown;
            bool isDown;
    };

    [[nodiscard]] constexpr bool onPress(KeyTransition transition)
    {
        return transition.isDown && !transition.wasDown;
    }

    [[nodiscard]] constexpr bool onRelease(KeyTransition transition)
    {
        return transition.wasDown && !transition.isDown;
    }
} // namespace inputs
