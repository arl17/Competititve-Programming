vector<ll> t[4*N];

//build(1,0,n-1)--> for building,root node=1
void build(ll i,ll tl,ll tr)
{
    if(tl==tr)
    {
        t[i].pb(a[tl]);
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*i,tl,tm);
        build(2*i+1,tm+1,tr);
        merge(t[2*i].begin(),t[2*i].end(),t[2*i+1].begin(),t[2*i+1].end(),back_inserter(t[i]));
    }

    
}

// returns the number of elements >=k in the range [l,r]

ll query(ll i,ll tl,ll tr,ll l,ll r,ll k)
{
    if(tl>r || tr<l) return 0;
    if(tl>=l && tr<=r) 
    {
        return t[i].end()-lb(t[i].begin(),t[i].end(),k);
    }
    ll tm=(tl+tr)/2;
    return query(2*i,tl,tm,l,r,k)+query(2*i+1,tm+1,tr,l,r,k);
}
