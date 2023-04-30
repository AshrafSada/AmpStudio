#pragma once
#include <functional>
#include <memory>
#include <unordered_map>
#include <any>
#include <typeindex>


class Container
{
public:
    template<class T>
    using Generator = std::function<std::shared_ptr<T>>;

    template<class T>
    void RegisterDependencyFactory(Generator<T> generator)
    {
        factoryMap[typeid(T)] = generator;
    }
    
    template<class T>
    std::shared_ptr<T> Resolve()
    {

    }
private:
    std::unordered_map<std::type_index, std::any> factoryMap;
};