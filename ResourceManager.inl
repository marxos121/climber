#include "ResourceManager.h"

#include <fstream>
#include <sstream>

template <typename T>
inline ResourceManager<T>::~ResourceManager() {
    removeAll();
}

template <typename T>
inline void ResourceManager<T>::release(const std::string& filename) {
    auto it = m_resources.find(filename);
    if(it == m_resources.end()) {
        return;
    }
    (it->second.users)--;

    if((it->second.users) <= 0) {
        remove(it);
    }
}

template <typename T>
inline void ResourceManager<T>::remove(std::unordered_map<std::string, ResourceData>::iterator element) {
    if(element == m_resources.end()) {
        return;
    }

    delete element->second.file;
    element->second.file = nullptr;
    //m_resources.erase(element);
}


template <typename T>
inline void ResourceManager<T>::remove(const std::string& filename) {
    auto it = m_resources.find(filename);
    if(it == m_resources.end()) {
        return;
    }
    delete it->second.file;
    m_resources.erase(it);
}

template <typename T>
inline void ResourceManager<T>::removeAll() {
    for(auto& res : m_resources) {
        delete res.second.file;
    }

    m_resources.clear();
}

template <typename T>
inline bool ResourceManager<T>::hasResource(const std::string& name) const {
    return m_resources.find(name) == m_resources.end() ? false : true;
}

template <typename T>
inline T* ResourceManager<T>::get(const std::string& filename) {
    auto it = m_resources.find(filename);

    if(it == m_resources.end()) {
        return nullptr;
    }

    if(it->second.file == nullptr) {
        if(it->second.path != "") {
            bool res = loadFile(filename);
            if(!res) {
                return nullptr;
            }
        }
        else {
            return nullptr;
        }
    }

    (it->second.users)++;
    return it->second.file;
}

template <typename T>
inline bool ResourceManager<T>::addPath(const std::string& name, const std::string& filepath) {
    if(hasResource(name)) {
        return false;
    }

    auto res = m_resources.emplace(name, ResourceData());
    
    if(!res.second) {
        return false;
    }

    res.first->second.path = filepath;
    return true;
}

template <typename T>
inline bool ResourceManager<T>::loadFile(const std::string& name) {
    T* temp = new T();

    auto it = m_resources.find(name);
    if(it == m_resources.end() || !temp->loadFromFile(it->second.path)) {
        delete temp;
        return false;
    }

    it->second.file = temp;
    return  true;
}

template <typename T>
inline void ResourceManager<T>::loadPaths(const std::string& pathfile) {
    std::ifstream is;
    if(!is.open(pathfile)) {
        return;
    }

    std::string line;
    while(std::getline(is, line)) {
        std::string name;
        std::string path;

        std::stringstream ss;
        ss >> name >> path;

        addPath(name, path);
    }

    is.close();
}