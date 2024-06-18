//
// Created by lucja on 18.06.2024.
//

#ifndef STATE_HPP
#define STATE_HPP

#include <string>

template <typename T>
class FiniteStateMachine;


template <typename T>
class State
{
public:

    inline T getID()
    {
        return mID;
    }

    inline const std::string& GetName() const
    {
        return mName;
    }

    explicit State(FiniteStateMachine<T>& fsm, T id,
                   std::string name = "default")
            : mName(name)
            , mID(id)
            , mFsm(fsm)
    {
    }

    virtual ~State() {}

    virtual void OnEnter()
    {
    }

    virtual void OnExit()
    {
    }

    virtual void OnUpdate()
    {
    }
protected:
    std::string mName;
    T mID;
    FiniteStateMachine<T>& mFsm;
};


#endif //STATE_HPP
