#pragma once

#include <iostream>
#include "Resource.hpp"

class ResourceManager {
    private:
    std::shared_ptr<Resource> resource; 

    public:
        ResourceManager() : resource(std::make_shared<Resource>()) {}
          double get() {
        if (resource) {
            return resource->get(); 
        } else {
            std::cerr << "Brak inicjalizacji.";
        }
    }

    ResourceManager(const ResourceManager& other) : resource(other.resource) {}
    
    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}
    
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    ~ResourceManager() {}
};
