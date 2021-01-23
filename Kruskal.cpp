//https://www.hackerrank.com/challenges/kruskalmstrsub/problem?isFullScreen=true
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void makeSet(int v, vi &rank, vi &parent);
int Find(int v, vi &rank, vi &parent);
void Union(int a, int b, vi &rank, vi &parent);
void Union(int a, int b, vi &rank, vi &parent)
{
    int a_id=Find(a, rank, parent);
    int b_id=Find(b, rank, parent);
    if(a_id!=b_id)
    {
        if(rank[a_id]>rank[b_id])
            parent[b_id]=a_id;
        else
        {
            parent[a_id]=b_id;
            if(rank[a_id]==rank[b_id])
                rank[b_id]++;
        }
    }
}
int Find(int v,vi &rank, vi &parent)
{
    if(v!=parent[v])
        parent[v]=Find(parent[v], rank, parent);
    return(parent[v]);
}
void makeSet(int v, vi &rank, vi &parent)
{
    parent[v]=v;
    rank[v]=0;
}
int kruskals(int g_nodes, vi &g_from, vi &g_to, vi &g_weight) {
    vvi A, edges(g_from.size());//A represents the spanning tree, edges represent the edges of the graph
    int i;
    for(i=0;i<g_from.size();i++)
    {
        vi edge{g_from[i],g_to[i],g_weight[i]};//0th index=from vertex, 1st index=to vertex, 2nd index=weight
        edges[i]=edge;
    }
    /*for(i=0;i<g_from.size();i++)//testing whether the assignment of edges has occured correctly
        cout<<"i="<<i<<" from="<<edges[i][0]<<" to="<<edges[i][1]<<" weight="<<edges[i][2]<<"\n";*/
    //using disjoint set data structure
    vi rank(g_nodes),parent(g_nodes);
    for(i=0;i<g_nodes;i++)
        makeSet(i,rank,parent);
    sort(edges.begin(),edges.end(), [](const vi &e1, const vi &e2)->bool {
        return(e1[2]<e2[2] || (e1[2]==e2[2] && e1[0]<=e2[0]));
        });
    for(i=0;i<edges.size();i++)
    {
        if(Find(edges[i][0]-1,rank,parent) != Find(edges[i][1]-1,rank,parent))//doing -1 because in the input the vertices start from 1
        {
            A.push_back(edges[i]);
            Union(edges[i][0]-1,edges[i][1]-1, rank, parent);
        }
    }
    int s=0;
    for(i=0;i<A.size();i++)
        s+=A[i][2];
    //cout<<s<<"\n";
    return(s);
}
int main()
{
    int g_nodes,g_edges,i;
    cin>>g_nodes>>g_edges;
    vi g_from(g_edges),g_to(g_edges),g_weights(g_edges);
    for(i=0;i<g_edges;i++)
        cin>>g_from[i]>>g_to[i]>>g_weights[i];
    cout<<kruskals(g_nodes,g_from,g_to,g_weights);
}
