ll tin[N],tout[N];
ll a[2*N];
ll ao[N]; //values of each node
ll timer=0;
ll t[8*N];
ll mx[8*N];

//build(1,0,n-1)--> for building,root node=1
void build(ll i,ll tl,ll tr)
{
    if(tl==tr)
    {
        t[i]=a[tl];
        mx[i]=a[tl];
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*i,tl,tm);
        build(2*i+1,tm+1,tr);
        t[i]=t[2*i]+t[2*i+1];
        mx[i]=max(mx[2*i],mx[2*i+1]);
    }

    
}


//sum(1,0,n-1,l,r)-->to get sum from l to r,l & r should be zero indexed
ll sum(ll i,ll tl,ll tr,ll l,ll r)
{
    if(tr<l || tl>r) return 0;
    if(tl>=l && tr<=r) return t[i];
    else
    {
        ll tm=(tl+tr)/2;
        return (sum(2*i,tl,tm,l,r)+sum(2*i+1,tm+1,tr,l,r));
    }
    
}

//max_el(1,0,n-1,l,r)--> to get max from l to r 
ll max_el(ll i,ll tl,ll tr,ll l,ll r)
{
    if(tr<l || tl>r) return 0;
    if(tl>=l && tr<=r) return mx[i];
    else
    {
        ll tm=(tl+tr)/2;
        return max(max_el(2*i,tl,tm,l,r),max_el(2*i+1,tm+1,tr,l,r));
    }
    
}

//update(1,0,n-1,pos,new_val)
void update(ll i,ll tl,ll tr,ll pos,ll new_val)
{
    if(tl==tr)
    {
        t[i]=new_val;
        mx[i]=new_val;
    }
    else
    {
        ll tm=(tl+tr)/2;
        if(pos<=tm) update(2*i,tl,tm,pos,new_val);
        else update(2*i+1,tm+1,tr,pos,new_val);
        t[i]=t[2*i]+t[2*i+1];
        mx[i]=max(mx[2*i],mx[2*i+1]);
    }

}


void dfs(ll i,ll par)
{
    tin[i]=timer++;
    a[tin[i]]=ao[i];
    for(auto it:v[i])
    {
        if(it!=par) dfs(it,i); 
    }
    tout[i]=timer++;
    a[tout[i]]=ao[i];
}

// update the value of a node
void q1()
{
    ll s,x;
    cin>>s>>x;
    update(1,0,timer,tin[s],x);
    update(1,0,timer,tout[s],x);
}


// print the sum of subtree of a node
void q2()
{
    ll s;
    cin>>s;
    cout<<sum(1,0,timer,tin[s],tout[s])/2<<endl;
}