
ll getsqrt(ll x)
{
    ll l=sqrt(x);
    for(ll i=-2;i<=2;i++)
    {
        if(l+i>=0 && (l+i)*(l+i)==x)
        {
            return l;
        }
    }
    return -1;
}
