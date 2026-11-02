#pragma once

#include <types/types.hpp>
#include "keyboard/KeyTransition.hpp"

namespace inputs {
    using KeyTrigger = bool (*)(KeyTransition);

    struct KeyBinding {
            int key;
            KeyTrigger trigger;
            common::Action action;
    };
} // namespace inputs
