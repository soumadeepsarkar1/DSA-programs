#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void DFS(vvi &adj, int n, list<int> &topo);
void DFS_visit(vvi &adj,int n, int v, vi &visited, list<int> &topo);
int main()
{
    int n,m;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>m;
    vvi edges(m,vi (2));
    cout<<"Enter the edges: \n";
    for(auto &i:edges)
        cin>>i[0]>>i[1];
    //creating adjacency list
    vvi adj(n);
    for(auto i:edges)
        adj[i[0]-1].push_back(i[1]-1);
    /*for(auto i: edges)
        cout<<i[0]<<" "<<i[1]<<"\n";*/
    list<int> topo;
    DFS(adj,n,topo);
    for(auto i:topo)
        cout<<i<<" ";
}
void DFS(vvi &adj,int n,list<int> &topo)
{
    vi visited(n,0);
    int i;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            DFS_visit(adj,n,i,visited,topo);
        }
    }
}
void DFS_visit(vvi &adj, int n, int v, vi &visited,list<int> &topo)//here v starts from 0
{
    for(auto i:adj[v])
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            DFS_visit(adj,n,i,visited,topo);
        }
    }
    topo.push_front(v+1);
}