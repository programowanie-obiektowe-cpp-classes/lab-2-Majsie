#pragma once

#include "Resource.hpp"

class ResourceManager {
private:
    Resource resource;

public:
    ResourceManager() : resource() {}

    double get() {
        return resource.get();
    }

    ~ResourceManager() = default;

    ResourceManager(const ResourceManager& other) : resource(other.resource) {}

    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }
};
