#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n; // node
int m; //edge
bool visited[1000];
vector<pair<int,int>>adj[1000];
int prims(int start){

 priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    int cost=0;
while(!pq.empty()){
     pair<int,int>p=pq.top(); /// extract
        pq.pop();
          int weight=p.first;
        int node=p.second;
        if(visited[node]==false)
        {
            visited[node]=true;
            cost+=weight;
        }
        for(auto it: adj[node]) /// visit the adjacency/neighbor list of that node
        {
            // "it" is a pair in the adjacency list of node. one by one, visit every pair using loop
            int weight=it.first;
            int neighbor=it.second;
            if(visited[neighbor]==false){
                pq.push({weight,neighbor});
            }
}


}
return cost;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int start, end, weight;
        cin>>start>>end>>weight;

        adj[start].push_back({weight,end});
        adj[end].push_back({weight,start});

    }

    cout<<prims(1)<<endl;

}
