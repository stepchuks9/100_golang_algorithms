#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <iterator>

#define BidirectionalIterator typename
#define InputIterator typename

template<InputIterator I>
using ValueType = typename std::iterator_traits<I>::value_type;


/*
template <BidirectionalIterator I>
inline
I reverse_find(I f, I l, const decltype(*I())& val) {
    if (f != l) while(f != --l && *l != val);
    return l;
}
*/


/*
template <BidirectionalIterator I>
inline 
I reverse_find_unguarded(I f, I l, const decltype(*I())& val) {
    while (f != --l && *l != val); 
    return l;
}

template <BidirectionalIterator I>
inline 
I reverse_find(I f, I l, const decltype(*I())& val) {
    return f != l ? reverse_find_unguarded(f,l,val) 
            : l;
}
*/

template <BidirectionalIterator I>
inline 
I reverse_find_unguarded(I f, I l, const ValueType<I>& val) {
    while (f != --l && *l != val); 
    return l;
}

template <BidirectionalIterator I>
inline 
I reverse_find(I f, I l, const ValueType<I>& val) {
    return f != l ? reverse_find_unguarded(f,l,val) 
            : l;
}


/*
inline 
std::pair<std::string, std::string>
Split(const std::string& s) {
    auto i = reverse_find(s.begin(), s.end(), '/');
    return {std::string(s.begin(), i+1),
                std::string(i+1, s.end())};
}
*/

/*
inline 
std::pair<std::string, std::string>
Split(const std::string& s) {
    auto i = s.begin() != s.end() ?
        reverse_find_unguarded(s.begin(), s.end(), '/')+1
            : s.end();
    return {std::string(s.begin(), i),
                std::string(i, s.end())};
}
*/


inline 
std::pair<std::string, std::string>
Split(const std::string& s) {
    auto i = s.begin() == s.end() ? s.end() 
        : reverse_find_unguarded(s.begin(), s.end(), '/');
    i =  s.begin() == i ? i : i+1;        
    return {std::string(s.begin(), i),
                std::string(i, s.end())};
}




int main() {
    std::vector<std::string> vec {
        "static/myfile.css",
        "myfile.css",
        ""};

    for(auto s : vec) {
        auto [x, y] = Split(s);
        std::cout << "dir: " << x << ", " << "file: " << y << '\n';
    }
    
}
