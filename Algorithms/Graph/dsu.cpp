ll par[N];
ll sz[N];

ll find_parent(ll i)
{
    if(par[par[i]]!=par[i])
    {
        par[i]=find_parent(par[i]);
    }
    return par[i];
}

void union_nodes(ll a,ll b)
{
    ll parent_a=find_parent(a);
    ll parent_b=find_parent(b);

    if(parent_a==parent_b) return ;
    if(sz[parent_a]>=sz[parent_b]) swap(parent_a,parent_b);

    sz[parent_b]+=sz[parent_a];
    par[parent_a]=parent_b;

}

void init_dsu(ll n)   // initialise dsu
{
    for(ll i=0;i<=n;i++)
    {
        par[i]=i;
        sz[i]=1;
    }
}

