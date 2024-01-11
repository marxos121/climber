#include "ResourceUser.h"

#include "ResourceManager.h"

template<typename Resource>
inline ResourceUser<Resource>::ResourceUser(ResourceManager<Resource>* mgr)
	: m_mgr(mgr)
{
}

template<typename Resource>
inline std::string ResourceUser<Resource>::getResourceName() const
{
	return m_resourceName;
}

template<typename Resource>
inline void ResourceUser<Resource>::notifyRelease()
{
	m_mgr->release(m_resourceName);
}

template<typename Resource>
inline void ResourceUser<Resource>::changeResource(const std::string& newRes) {
	m_resourceName = newRes;
}