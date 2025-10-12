#include <iostream>
#include <algorithm>
#define max 100
int graph[max][max];
bool visted[max];
int dfs(int node,int n)
{
    visted[node] = true;
    std::cout << node;
    for(int i=0;i<n;i++)
    {
        if(graph[node][i]==1&&!visted[i]) 
        {
            dfs(i,n);
        }
    }
}
int main()
{
    int n = 4;
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][3] = graph[3][2] = 1;

    std::cout << "DFS traversal starting from node 0: ";
    dfs(0,n);
    std::cout << std::endl;
}