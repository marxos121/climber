#pragma once
enum class StateType
{
	Intro, MainMenu, Play, Pause, GameOver, Credits
};

class BaseState
{
public:
	BaseState(StateType type, bool transparent = false, bool transcendent = false)
		: m_type(type), m_isTranscendent(transcendent), m_isTransparent(transparent), m_isActive(true) { }
	virtual ~BaseState() = default;

	virtual void update(float delta = 0.f) = 0;
	virtual void render() = 0;
	virtual void activate() { m_isActive = true; }
	virtual void deactivate() { m_isActive = false; }
	virtual void onResize() {}

private:
	StateType m_type;
	bool m_isTranscendent;
	bool m_isTransparent;
	bool m_isActive;

public:
	//Setters and getters
	StateType getType() const { return m_type; }

	bool setTranscendent(bool transcendent) { m_isTranscendent = transcendent; }
	bool getTranscendent() const { return m_isTranscendent; }
	bool setTransparent(bool transparent) { m_isTranscendent = transparent; }
	bool getTransparent() const { return m_isTransparent; }

	bool isActive() const { return m_isActive; }
};