#ifndef TETRIS_SUBJECT_H
#define TETRIS_SUBJECT_H

#include <algorithm>
#include "Observer.h"
#include "GameEvents.h"
#include <vector>

namespace Tetris {
    class Subject {

    private:
        std::vector<Observer*> m_Observers;

    public:
        void AddObserver(Observer* observer) {
            m_Observers.push_back(observer);
        }

        void RemoveObserver(const Observer* observer) {
            auto it = std::find(m_Observers.begin(), m_Observers.end(), observer);
            if (it != m_Observers.end()) {
                m_Observers.erase(it);
            }
        }

    protected:
        void Notify(GameEvent event) const {
            for (auto observer : m_Observers) {
                observer->OnNotify(event);
            }
        }
    };
}

#endif //TETRIS_SUBJECT_H
