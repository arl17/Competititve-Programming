ll d[N];
ll p[N];

void dijkstra(ll root)
{
    set<pii> q;
    for(ll i=1;i<=n;i++) 
    {
        d[i]=INF;
        p[i]=-1;
    }
    d[root]=0;
    for(ll i=1;i<=n;i++)
    {
        q.insert({d[i],i});
    }
    while(!q.empty())
    {
        ll i=q.begin()->ss;
        q.erase(q.begin());
        for(auto it:v[i])
        {
            ll j=it.ff;
            ll wt=it.ss;
            if(d[i]+wt<d[j])
            {
                q.erase({d[j],j});
                d[j]=d[i]+wt;
                p[j]=i;
                q.insert({d[j],j});
            }
        }
    }
}

vector<ll> restore_path(ll x,ll root)
{
    vector<ll> path;
    for(ll i=x;i!=root;i=p[i])
    {
        if(i==-1) break;
        path.pb(i);
    }
    path.pb(root);
    reverse(path.begin(),path.end());
    return path;
}