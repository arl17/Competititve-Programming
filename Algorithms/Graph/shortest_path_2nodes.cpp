ll dist[N];
bool vis[N];

void bfs(ll x,ll y)
{
    ll mn=INF;
    queue<ll> q;
    q.push(x);
    dist[x]=0;
    vis[x]=true;
    while(!q.empty())
    {
        ll i=q.front();
        q.pop();
        for(auto it:v[i])
        {
            if(vis[it]) continue;
            q.push(it);
            dist[it]=dist[i]+1;
            vis[it]=true;
            if(it==y) return;
        }
    }
}


ll shortest_dist(ll x,ll y)
{
    for(ll i=1;i<=n;i++) dist[i]=INF,vis[i]=false;
    bfs(x,y);
    return dist[y];
}