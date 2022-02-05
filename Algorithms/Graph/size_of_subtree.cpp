

void dfs(ll i,ll par)
{
    sz[i]=1;
    for(auto it:v[i])
    {
        if(it==par) continue;
        dfs(it,i);
        sz[i]+=sz[it];
    }
    return sz[it];

}
