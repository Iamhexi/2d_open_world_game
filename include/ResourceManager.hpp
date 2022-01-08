#include <SFML/Graphics.hpp>
#include <map>

template<class T>
class ResourceManager
{
private:
    std::map<std::string, T> container;
public:
    T& get(std::string name);
    void set(std::string name, T resource);
};
