
bool vis[N]; 
stack<ll> st;
vector<ll> order;
ll pos[N];

void toposort(ll i,ll par)
{
    vis[i]=true;
    for(auto it:v[i])
    {
        if(!vis[it]) toposort(it,i);
    }
    st.push(i);
}

ll check_cycle()
{
    memf(vis);
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i]) toposort(i,i);
    }
    ll cnt=0;
    while(!st.empty())
    {
        pos[st.top()]=cnt++;
        order.pb(st.top());
        st.pop();
    }
    ll ret=0;
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i]) continue;
        for(auto it:v[i])
        {
            if(pos[i]>pos[it]) ret++; // cycle exists
        }
    }
    return ret;

}
