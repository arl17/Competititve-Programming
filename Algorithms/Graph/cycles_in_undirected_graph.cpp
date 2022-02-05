 
vector<ll> cyc[N];
ll col[N];
ll par[N];
ll cnt;
bool done;
 
 
void dfs(ll i)
{
    col[i]=1;
    for(auto it:v[i])
    {
        if(col[it]==0) par[it]=i,dfs(it);
        else if(col[it]==1)
        {
            ll cur=i;
            while(cur!=it)
            {
                cyc[cnt].pb(cur);
                cur=par[cur];
            }
            cyc[cnt].pb(it);
            cnt++;
        }
    }
    col[i]=2;
}
 
void get_cycles()
{
    cnt=0;
    memset(col,0,sizeof col);
    for(ll i=1;i<=n;i++)
    {
        if(!col[i])
        {
            dfs(i);
        }    
    }
}