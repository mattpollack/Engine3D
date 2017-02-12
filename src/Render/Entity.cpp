#include "Entity.h"
#include "../Component/Component.h"

#include <stdexcept>

namespace Render {
    void Entity::add(std::shared_ptr<Component>& component) {
        if (this->components.find(component.get()->getName()) == this->components.end() ||
            this->components.find(component.get()->getName())->second == nullptr) {
            this->components[component.get()->getName()] = component;
        }
        else {
            throw std::runtime_error("Attempt to add to existing component");
        }
    }

    std::shared_ptr<Component> Entity::get(std::string title) {
        auto result = this->components.find(title);

        return result == this->components.end() ? nullptr : result->second;
    }

    std::shared_ptr<Component> Entity::remove(std::string title) {
        auto result = this->components.find(title);

        if (result == this->components.end() ||
            result->second == nullptr) {
            return nullptr;
        }
        else {
            this->components[title] = nullptr;
            return result->second;
        }
    }
}
