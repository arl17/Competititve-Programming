ll col[N],p[N];
vector<ll> cyc[N];
ll cyc_cnt;


void dfs(ll i,ll par)
{
    if(col[i]==2) return ;
    if(col[i]==1)
    {
        cyc_cnt++;
        cyc[cyc_cnt].pb(i);
        ll cur=par;
        while(cur!=i)
        {
            cyc[cyc_cnt].pb(cur);
            cur=p[cur];
        }
        return ;
    }
    p[i]=par;
    col[i]=1;
    for(auto it:v[i])
    {
        dfs(it,i);
    }
    col[i]=2;
}
