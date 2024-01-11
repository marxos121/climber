#include "Collider.h"

template<typename T>
inline Collider<T>::Collider(const sf::Transformable& l_parent, const T& l_shape, const sf::Vector2f& l_offset, const std::string& l_id)
	: m_active(true), m_parent(&l_parent), m_id(l_id), m_shape(l_shape), m_offset(l_offset)
{
	m_shape.setPosition({ m_parent.getGlobalBounds().left + m_offset.x, m_parent.getGlobalBounds.top + m_offset.y});
}

template<typename T>
inline std::string Collider<T>::getId() const {
	return m_id;
}

template<typename T>
inline const sf::Transformable& Collider<T>::getParent() const {
	return m_parent;
}

template<typename T>
inline const T& Collider<T>::getShape() const {
	return m_shape;
}

template<typename T>
inline sf::Vector2f Collider<T>::getOffset() const
{
	return m_offset;
}

template<typename T>
inline void Collider<T>::setActive(bool l_active)
{
	m_active = l_active;
}

template<typename T>
inline bool Collider<T>::getActive() const
{
	return m_active;
}