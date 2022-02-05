ll d[105][105]; 

void Floyd_Warshall()
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(graph[i][j]==1) d[i][j]=1;
            else d[i][j]=INF;
        }
        d[i][i]=0;
    }
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
