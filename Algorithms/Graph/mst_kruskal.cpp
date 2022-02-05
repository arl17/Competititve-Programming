vector<pair<ll,pii>> edge;// edge.first=wt of edge
ll par[N];
vector<ll> v[N]; //minimum spanning tree
map<pii,ll> mp;
ll sz[N];

ll root(ll x)
{
    while(par[x]!=x)
    {
        x=par[x];
    }
    return x;
}

void union1(ll x,ll y,ll w)
{
    ll a=x;
    ll b=y;

    ll parent_a=root(a);
    ll parent_b=root(b);

    if(parent_a==parent_b) return ;
    if(sz[parent_a]>=sz[parent_b]) swap(parent_a,parent_b);

    sz[parent_b]+=sz[parent_a];
    par[parent_a]=parent_b;

    v[x].pb(y);
    v[y].pb(x);
    mp[{x,y}]=w;
    mp[{y,x}]=w;
}


ll kruskal() // returns the min weight
{
    ll min_cost=0;
    for(auto it:edge)
    {
        ll x=it.second.first;
        ll y=it.second.second;
        ll cost=it.first;
        if(root(x)!=root(y))
        {
            min_cost+=cost;
            union1(x,y,cost);
        }
    }
    return min_cost;
}

void mst()
{
    sort(edge.begin(),edge.end()); // sort wrt the weight

    for(ll i=1;i<=n;i++) //initialising root to itself
    {
        par[i]=i;
        sz[i]=1;
    }
    kruskal();
}