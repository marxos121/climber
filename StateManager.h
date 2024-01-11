#pragma once
#include "BaseState.h"
#include <vector>
#include <functional>

class StateManager
{
public:
	StateManager() = default;
	~StateManager();

	void addState(StateType state);

	template <typename T>
	void registerState(StateType type, bool transparent = false, bool transcendent = false) {
		m_stateFactory.emplace(type, [&transcendent, &transparent]() {
			return new T(/*transcendent, transparent*/);
			});
	}

	void swapState(StateType newState);

	void update(float delta);
	void render();

	void onResize();
	
	bool hasState(StateType) const;
	StateType getCurrentState() const;
	void togglePause();


private:
	std::vector<BaseState*> m_states;

	std::unordered_map<StateType, std::function<BaseState*()>> m_stateFactory;
};

