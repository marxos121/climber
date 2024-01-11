#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <unordered_map>
#include <string>

template <typename T>
    class ResourceManager {
        struct ResourceData {
            std::string path;
            T* file;
            int users;
        };
private:
    std::unordered_map<std::string, ResourceData>  m_resources;
    void remove(std::unordered_map<std::string, ResourceData>::iterator element);

public:
    ResourceManager() = default;
    ~ResourceManager();

    T* get(const std::string& filename);

    virtual bool loadFile(const std::string& name);
    void loadPaths(const std::string& pathfile);
    bool addPath(const std::string& name, const std::string& filepath);

    void release(const std::string& filename);
    void remove(const std::string& filename);
    void removeAll();

    bool hasResource(const std::string& filename) const;
};

#include "ResourceManager.inl"

//using FontManager = ResourceManager<sf::Font>;
//using TextureManager = ResourceManager<sf::Texture>;
//using AudioManager = ResourceManager<sf::SoundBuffer>;

#endif