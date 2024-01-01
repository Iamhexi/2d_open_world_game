#include "../../include/components/Inventory.hpp"

std::shared_ptr<NotExistingItem> InventoryComponent::notExistingItem = nullptr;

InventoryComponent::InventoryComponent(sf::RenderWindow& window, sf::Texture& notExistingItemTexture)
    : window(window)
{
   
}

bool InventoryComponent::intersects(ComponentPtr other) const {
    
}

void InventoryComponent::move(const sf::Vector2f& movement) {
    
}
