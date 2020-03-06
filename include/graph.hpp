#include "nodes.hpp"
#include <utility>
#include <vector>
#include <initializer_list>
#include <iostream>
#include <algorithm>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::initializer_list<T> l)
{
    for (auto it = l.begin(); it < l.end(); it++)
    {
        out << *it;
    }
    out << "\n";
    return out;
}

namespace lib
{
template <typename T>
class graph
{
public:
    std::vector<std::pair<T, GraphNode<T>>> v;
    graph(std::initializer_list<std::initializer_list<T>> l)
    {
        for (auto inner_list = l.begin(); inner_list < l.end(); inner_list++)
        {
            T first = *(inner_list->begin());
            std::vector<T> second(inner_list->begin() + 1, inner_list->end());
            v.push_back(std::make_pair(first, GraphNode<T>(second)));
        }
    };

    friend std::ostream &operator<<(std::ostream &out, const graph g)
    {
        for (auto const &p : g.v)
        {
            out << p.first;
            for (auto const i : p.second.list)
            {
                out << "->" << i;
            }
            out << "\n";
        }
        return out;
    }

    std::vector<T>& operator [](T i){
        auto isThis=[i](std::pair<T, GraphNode<T>> p){
            return p.first==i;
        };
        auto it = std::find_if(v.begin(),v.end(),isThis);
        return it->second.list;
        // return std::vector<T> v(10);
    }
};

} // namespace lib