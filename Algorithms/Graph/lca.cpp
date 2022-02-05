const int LOG=20;
const int MAXN=2e5+5;
ll up[MAXN][LOG];
ll depth[MAXN];

void bin_lift(ll i,ll par)
{
    for(auto it:v[i])
    {
        if(it==par) continue;
        depth[it]=depth[i]+1;
        up[it][0]=i;
        for(ll j=1;j<LOG;j++)
        {
            up[it][j]=up[up[it][j-1]][j-1];
        }
        bin_lift(it,i);
    }

}

ll get_lca(ll a,ll b)
{
    if(depth[a]<depth[b]) swap(a,b);
    ll k=depth[a]-depth[b];
    for(ll i=LOG-1;i>=0;i--)
    {
        if(k&(1<<i)) a=up[a][i];
    }
    if(a==b) return a;
    for(ll i=LOG-1;i>=0;i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

void precomp(ll root)
{
    depth[root]=1;
    for(ll i=0;i<LOG;i++)
    {
        up[root][i]=root;
    }
    bin_lift(root,-1);
}

ll distance(ll a,ll b)
{
    ll o=get_lca(a,b);
    ll ao=depth[a]-depth[o];
    ll bo=depth[b]-depth[o];
    return ao+bo;
}

ll kth_anc(ll a,ll k)
{
    if(depth[a]<=k)
    {
        return -1;
    }
    for(ll i=LOG-1;i>=0;i--)
    {
        if(k&(1<<i)) a=up[a][i];
    }
    return a;
}
