// if we are given a list of masks and we are asked to mark all of their subsets
const int MAX=(1<<20)+1;
ll have[MAX];   // have[i]==1--> if mask is there in the list else its 0

    for(ll i=MAX;i>=1;i--)
    {
        if(!have[mask]) continue;
        ll mask=i;
        for(ll i=0;i<20;i++)
        {
            if(mask&(1<<i)) have[mask^(1<<i)]=have[mask];
        }
    }
    
