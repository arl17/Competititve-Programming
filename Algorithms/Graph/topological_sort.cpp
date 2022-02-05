bool vis[N];
stack<ll> st;


void toposort(ll i)
{
    vis[i]=true;
    for(auto it:v[i])
    {
        if(!vis[it]) toposort(it);
    }
    st.push(i);
}
