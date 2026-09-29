#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[4271];
int _rank[4271];

struct Edge
{
    int u,v,cost;
};

void initialize(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        _rank[i]=0;
    }
}

int _find(int a)
{
    if(parent[a]!=a)
        return _find(parent[a]);
    else
        return a;
}

void _union(int a, int b)
{
    int roota=_find(a);
    int rootb=_find(b);

    if(roota!=rootb)
    {
        if(_rank[roota]==_rank[rootb])
        {
            parent[rootb]=roota;
            _rank[roota]++;
        }
        else
        {
            if(_rank[roota]>_rank[rootb])
                parent[rootb]=roota;
            else
                parent[roota]=rootb;
        }
    }
}

bool custom_sort(Edge a,Edge b)
{
    return a.cost<b.cost;
}

int main()
{
    int N,M,A;
    cin>>N>>M>>A;

    initialize(N);

    for(int i=1;i<=A;i++)
    {
        int u,v;
        cin>>u>>v;

        _union(u,v);
    }

    int X,Y,C;
    cin>>X>>Y>>C;

    int total_cost=C;

    _union(X,Y);

    vector<Edge> edges;

    for(int i=1;i<=M;i++)
    {
        Edge e;

        cin>>e.u>>e.v>>e.cost;

        edges.push_back(e);
    }

    sort(edges.begin(),edges.end(),custom_sort);

    for(auto e:edges)
    {
        if(_find(e.u)!=_find(e.v))
        {
            _union(e.u,e.v);

            total_cost=total_cost+e.cost;
        }
    }

    cout<<total_cost<<endl;
}
