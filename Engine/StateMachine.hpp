//
// Created by lucja on 18.06.2024.
//

#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "State.hpp"

#include <memory>
#include <map>

template <typename T>
class FiniteStateMachine
{
protected:
    std::map<T, std::unique_ptr<State<T>>> mStates;
    State<T>* mCurrentState;
public:
    FiniteStateMachine()
            : mCurrentState(nullptr)
    {}

    template <class S>
    State<T>& Add(T id)
    {
        static_assert(not std::is_same<State<T>, S>());
        mStates[id] = std::make_unique<S>(*this);
        return *mStates[id];
    }

    State<T>& GetState(T stateID)
    {
        return *mStates[stateID];
    }

    State<T>& GetCurrentState()
    {
        return *mCurrentState;
    }


    const State<T>& GetCurrentState() const
    {
        return *mCurrentState;
    }


    void SetCurrentState(T stateID)
    {
        State<T>* state = &GetState(stateID);
        SetCurrentState(state);
    }

    void OnUpdate()
    {
        if (mCurrentState != nullptr)
        {
            mCurrentState->OnUpdate();
        }
    }
protected:

    void SetCurrentState(State<T>* state)
    {
        if (mCurrentState == state)
        {
            return;
        }
        if (mCurrentState != nullptr)
        {
            mCurrentState->OnExit();
        }
        mCurrentState = state;
        if (mCurrentState != nullptr)
        {
            mCurrentState->OnEnter();
        }
    }
};

#endif //STATEMACHINE_HPP
