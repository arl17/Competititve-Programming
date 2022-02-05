
ll phi(ll x)
{
    ll res=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            while(x%i==0)
            {
                x=x/i;
            }
            res-=res/i;
        }
    }
    if(x>1) 
    {
        res-=res/x;
    }
    return res;
}
