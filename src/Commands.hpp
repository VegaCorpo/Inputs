#pragma once

#include <unordered_map>
#include "GLFW/glfw3.h"
#include "types/types.hpp"
#include <iostream>
#include <memory>

namespace inputs {
    class ICommand {
        public:
            virtual ~ICommand() {};
            virtual void execute() = 0;
    };

    class ACommand : public ICommand {
        public:
            ACommand(std::string toremove) {
                this->temp = toremove;
            };
            void execute() override {
                std::cout << this->temp << std::endl;
            }
        private:
            std::string temp;
    };
} // namespace inputs
