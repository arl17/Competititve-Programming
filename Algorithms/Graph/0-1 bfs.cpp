vector<pii> v[N];
ll dp[N];
bool vis[N];

void bfs01(ll root)
{
    for(ll i=1;i<=n;i++) dp[i]=INF;
    dp[root]=0;
    deque<ll> q;
    q.push_front(root);
    while(!q.empty())
    {
        ll x=q.front();
        q.pop_front();
        vis[x]=true;
        for(auto it:v[x])
        {
            if(dp[x]+it.ss<dp[it.ff])
            {
                dp[it.ff]=dp[x]+it.ss;
                if(it.ss==1) q.push_back(it.ff);
                else q.push_front(it.ff);
            }
        }
    }
}
