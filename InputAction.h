#pragma once;

namespace Tetris {
    class InputAction {
    public:
        virtual ~InputAction() = default;
        virtual void Update() = 0;
        virtual bool CanExecute() const = 0;
    };
}
