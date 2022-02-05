bool prime[N+1];
vector<ll> p;

void sieve() 
{
    for(ll i=1;i<=N;i++) prime[i]=true; 
  
    for (int i=2; i*i<=N; i++) 
    { 
         
        if (prime[i] == true) 
        {  
            for (int j=i*i;j<=N;j+=i) 
                prime[j] = false; 
        } 
    } 
    for(ll i=1;i<=N;i++)
    {
        if(prime[i]==true) p.pb(i);
    }
  
} 

