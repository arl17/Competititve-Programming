#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;


/*ordered_set<ll> s;
s.insert(x);
s.order_of_key(x); to get the number of elements strictly smaller than x
*/
//https://codeforces.com/blog/entry/11080
// https://codeforces.com/contest/1579/problem/E2
