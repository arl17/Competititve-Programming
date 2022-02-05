ll max_subarray()
{
    ll cur_mx=a[0];
    ll mx_so_far=a[0];
    for(ll i=1;i<n;i++)
    {
        cur_mx=max(a[i],cur_mx+a[i]);
        if(cur_mx>mx_so_far)
        {
            mx_so_far=cur_mx;
        }
    }
    return mx_so_far;
}