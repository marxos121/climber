#include "StateManager.h"

StateManager::~StateManager()
{
	for (auto state : m_states)
	{
		delete state;
	}
}

void StateManager::addState(StateType state)
{
	if (hasState(state)) {
		return;
	}

	m_states.push_back(m_stateFactory[state]());
}

void StateManager::swapState(StateType newState)
{
	auto it = std::find_if(m_states.begin(), m_states.end(),
		[newState](BaseState* st) { return st->getType() == newState; });


	BaseState* temp = nullptr;
	if (it == m_states.end())
	{
		temp = m_stateFactory[newState]();
	}
	else
	{
		temp = *it;
		m_states.erase(it);
	}

	if (!m_states.empty() && !temp->getTranscendent()) {	//will hold recursively for all previous states
		m_states.back()->deactivate();
	}

	m_states.emplace_back(temp);
	m_states.back()->activate();
}

void StateManager::update(float delta)
{
	if (m_states.empty()) {
		return;
	}

	auto it = m_states.rbegin();
	while (it != m_states.rend()) {
		if ((*it)->isActive()) {
			(*it)->update(delta);
		}
		if (!(*it)->getTranscendent()) {
			return;
		}
		it++;
	}
}

void StateManager::render()
{
	if (m_states.empty())
	{
		return;
	}

	auto it = m_states.end() - 1;
	
	while (it >= m_states.begin())
	{
		if (!(*it)->getTransparent())
		{
			break;
		}
		--it;
	}

	while (it != m_states.end())
	{
		(*it)->render();
		++it;
	}
}

void StateManager::onResize()
{
	for (auto state : m_states)
	{
		state->onResize();
	}
}

inline void StateManager::togglePause()
{
	if (m_states.back()->getType() == StateType::Pause)
	{
		swapState(StateType::Play);
	}
	else if (m_states.back()->getType() == StateType::Play)
	{
		swapState(StateType::Pause);
	}
}

inline bool StateManager::hasState(StateType type) const
{
	for (const auto& state : m_states) {
		if (state->getType() == type) {
			return true;
		}
	}

	return false;
}

inline StateType StateManager::getCurrentState() const
{ 
	return m_states.empty() ? StateType(-1) : m_states.back()->getType(); 
}
