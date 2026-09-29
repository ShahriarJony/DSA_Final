#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dist[4271];
int proc_delay[4271];

struct Edge
{
    int v;
    int w;
};

void pc_Relay(int n, vector<Edge> graph[])
{
    for(int i=1;i<=n;i++)
        dist[i]=1000000000;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[1]=0;

    pq.push({0,1});

    while(!pq.empty())
    {
        int current_dist=pq.top().first;
        int u=pq.top().second;

        pq.pop();

        if(current_dist!=dist[u])
            continue;

        for(auto e:graph[u])
        {
            int v=e.v;
            int w=e.w;

            int new_dist=dist[u]+w+proc_delay[v];

            if(new_dist<dist[v])
            {
                dist[v]=new_dist;

                pq.push({dist[v],v});
            }
        }
    }

    cout<<dist[n]<<endl;
}

int main()
{
    int N,M;

    cin>>N>>M;

    vector<Edge> graph[4271];

    for(int i=1;i<=M;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    for(int i=1;i<=N;i++)
        cin>>proc_delay[i];

    pc_Relay(N,graph);

    return 0;
}
