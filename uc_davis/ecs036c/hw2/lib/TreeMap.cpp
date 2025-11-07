#ifndef TREE_MAP_CPP
#define TREE_MAP_CPP

#include "TreeMap.hpp"
#include "TreeSet.cpp"

// TODO: Implement all methods defined in TreeMap.hpp here

template <typename TKey, typename TValue>
TreeMap<TKey, TValue>::TreeMap() {
    // _tree = TreeSet<std::pair <Key, TValue>>(_comparator);
}

template <typename TKey, typename TValue>
TreeMap<TKey, TValue>::TreeMap(const std::vector<std::pair<TKey, TValue>> &items)
{
    for (int i = 0; i < items.size(); i++)
    {
        _tree.add(items[i]);
    }
}

template <typename TKey, typename TValue>
size_t TreeMap<TKey, TValue>::size() const
{
    return _tree.size();
}

template <typename TKey, typename TValue>
void TreeMap<TKey, TValue>::insert(TKey key, TValue value)
{
    std::pair<TKey, TValue> pair = {key, value};
    _tree.add(pair);
}

template <typename TKey, typename TValue>
std::optional<TValue> TreeMap<TKey, TValue>::get(TKey key) const
{
    std::vector<std::pair<TKey, TValue>> treeMap = _tree.to_vector();
    for (int i = 0; i < treeMap.size(); i++)
    {
        if (treeMap[i].first == key)
        {
            return treeMap[i].second;
        }
    }
    return std::nullopt;
}

template <typename TKey, typename TValue>
bool TreeMap<TKey, TValue>::contains(TKey key) const
{
    return (get(key) != std::nullopt);
}

template <typename TKey, typename TValue>
std::vector<std::pair<TKey, TValue>> TreeMap<TKey, TValue>::to_vector() const
{
    return _tree.to_vector();
}

template <typename TKey, typename TValue>
bool TreeMap<TKey, TValue>::is_empty() const
{
    return _tree.is_empty();
}

template <typename TKey, typename TValue>
void TreeMap<TKey, TValue>::clear()
{
    _tree.clear();
}

template <typename TKey, typename TValue>
TreeMap<TKey, TValue>::~TreeMap() {}

#endif
