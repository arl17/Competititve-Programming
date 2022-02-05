const int MAXN=1e7+5;
ll spf[MAXN];


void sieve() 
{ 
    spf[1]=1; 
    for (ll i=2;i<MAXN;i++)
    {  
        spf[i]=i; 
    }
    for (ll i=4;i<MAXN;i+=2)
    { 
        spf[i]=2; 
    }
    for (ll i=3;i*i<MAXN;i++) 
    {  
        if (spf[i]==i) 
        {  
            for (int j=i*i;j<MAXN;j+=i) 
            {
                if (spf[j]==j)
                { 
                    spf[j]=i;
                }
            }         
        } 
    } 
} 
  
 
vector<ll> get_factors(ll x) 
{ 
    vector<ll> ret;
    while (x!=1) 
    {  
        ret.push_back(spf[x]); 
        x=x/spf[x]; 
    } 
    return ret;
} 
