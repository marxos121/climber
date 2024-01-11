#ifndef RESOURCE_USER_H
#define RESOURCE_USER_H

#include <string>

template <typename T>
class ResourceManager;

template <typename Resource>
class ResourceUser {
protected:
	ResourceManager<Resource>* m_mgr;
	std::string m_resourceName = "";
public:
	ResourceUser() = delete;
	ResourceUser(ResourceManager<Resource>* mgr);
	~ResourceUser() = default;

	std::string getResourceName() const;

protected:
	void notifyRelease();
	void changeResource(const std::string& newRes);
};

#include "ResourceUser.inl"

#endif