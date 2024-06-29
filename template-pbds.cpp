#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


/*
Functions:
1. order_of_key(x) -> index k, where element at k is strictly lesser than x
2. find_by_order(x) -> pointer to the element at index x (use * to get the element)
    Eg: 
    os<int> s;
    *(s.find_by_order(1));
*/