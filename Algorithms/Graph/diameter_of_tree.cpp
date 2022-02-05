ll x; // will give a node having maximum distance
ll max_dist;

void dfs(ll i,ll par,ll dist2)
{
    if(dist2>=max_dist) 
    {
        max_dist=dist2;
        x=i;
    }
    for(auto it:v[i])
    {
        if(it!=par) dfs(it,i,dist2+1);
    }
}

ll diameter()
{
    x=0;
    max_dist=0;
    // starting from a random node
    dfs(1,1,0); 
    max_dist=0;
    // starting from a node having max_dist from node 1
    dfs(x,x,0);
    ll d=max_dist;
    return d;

}
