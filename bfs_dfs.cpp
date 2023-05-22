#include<iostream>
#include<omp.h>
#include<queue>
#include<vector>
using namespace std;

void dfs(int node, vector<int>* graph, bool* visited){
    visited[node] = true;
    cout<<node<<" ";

    #pragma omp parallel for
    for(int i=0; i < graph[node].size(); i++){
        int neighbor = graph[node][i];
        if(!visited[neighbor]){
            dfs(neighbor, graph, visited);
        }
    }
}

void bfs(int start, vector<int>* graph){
    queue<int> q;
    bool visited[graph->size()] = { false };

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        #pragma omp parallel for
        for(int i = 0; i < graph[node].size(); i++){
            int neighbor = graph[node][i];
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
}
}

int main() {
    int n = 8;
    vector<int>* graph = new vector<int>[n];

    //Graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[3].push_back(6);
    graph[4].push_back(7);
    graph[4].push_back(5);
    graph[6].push_back(7);

    bool visited[n] = { false };
    cout<<"DFS traversal: ";
    dfs(0, graph, visited);
    cout<<endl<<endl;

    cout<<"BFS traversal: ";
    bfs(0, graph);
    cout<<endl;

    return 0;
}
