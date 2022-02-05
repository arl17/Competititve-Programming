
//number of elements in a range [l,r] in a sorted vector 

ll left=lb(all(a),l)-a.begin();
ll right=ub(all(a),r)-a.begin();
right--;
ll x=right-left+1;

// x is the number of elements in a range [l,r] in a sorted vector