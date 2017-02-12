#ifndef _ENTITY_H
#define _ENTITY_H

#include <memory>
#include <string>
#include <map>

// Forward declare
class Component;

namespace Render {
    class Entity {
    private:
        std::map<std::string, std::shared_ptr<Component>> components;
    public:
        void                       add(std::shared_ptr<Component>& component);
        std::shared_ptr<Component> get(std::string title);
        std::shared_ptr<Component> remove(std::string title);
    };
}

#endif
