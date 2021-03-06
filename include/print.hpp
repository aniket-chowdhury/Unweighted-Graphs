#ifndef PRINT
#define PRINT 1
#include <iostream>
#include <vector>
#include <utility>

template <typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p);
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> vec);

template <typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> vec)
{
    if(vec.size()==0){
        out<<"[]";
        return out;
    }
    out << "[";
    auto it = vec.begin();
    for (it; it < vec.end() - 1; it++)
    {
        out << *it << ", ";
    }
    out << *it << "]";
    return out;
}

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


#endif // PRINT
