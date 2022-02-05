//updating the array in O(1)
 
vector<ll> initialize_diff_array(vector<ll>& a)
{
    ll n=a.size();
    vector<ll> d(n+1);

    d[0]=a[0];
    d[n]=0;
    for(i=1;i<n;i++)
    {
        d[i]=a[i]-a[i-1];
    }
    return d;
}


// adding x to a in the range [l,r]
void update(vector<ll>& d,l,r,x)
{
    d[l]+=x;
    d[r+1]-=x;
}

//prints the updated version of a
void print(vector<ll>& d,vector<ll>& a)
{
    for(i=0;i<n;i++)
    {
        if(i==0) a[i]=d[i];
        else a[i]=d[i]+a[i-1];
        cout<<a[i]<<" ";
    }cout<<endl;
}