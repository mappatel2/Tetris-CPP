#pragma once

namespace Tetris {
    class InputAction {
    public:
        virtual ~InputAction() = default;
        virtual void Update() = 0;
        [[nodiscard]] virtual bool CanExecute() const = 0;
    };
}
