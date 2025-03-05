#include <bits/stdc++.h>
using namespace std;
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
#define F first
#define S second
class Solution {
public:
    vector<vector<ii>> graph;
    vector<vector<int>> dis;
    vector<vector<int>> vis;
    void dijkstra(int node, vector<vector<ii>>& graph, int k){
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        pq.push({0, {node, 0}});
        dis[node][0] = 0;
        while(!pq.empty()){
            int w = pq.top().F;
            int parent_node = pq.top().S.F;
            int stop = pq.top().S.S;
            pq.pop();
            // if(vis[parent_node][stop]){
            //     continue;
            // }
            // vis[parent_node][stop] = 1;
           
            for(auto neigh: graph[parent_node]){
                int neigh_node = neigh.F;
                int weight = neigh.S;
                // if(!vis[neigh_node][stop]){
                //     if(dis[neigh_node][stop + 1] > dis[parent_node][stop] + weight){
                //         dis[neigh_node][stop + 1] = dis[parent_node][stop] + weight;
                //         pq.push({weight, neigh_node, stop + 1});
                //     }
                // }
                if(dis[neigh_node][stop + 1] > dis[parent_node][stop] + weight){
                    dis[neigh_node][stop + 1] = dis[parent_node][stop] + weight;
                    pq.push({weight, {neigh_node, stop + 1}});
                }
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        graph.resize(n);
        int m = flights.size();
        dis.resize(n, vector<int>(m, 1e9));
        vis.resize(n, vector<int>(m, 0));
        for(auto flight: flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            graph[u].push_back({v, w});
        }
        dijkstra(src, graph, k);
        for(int i = 0; i < m; i++){
            cout << dis[dst][i] << "\t";
        }
        cout << "\n";
        return dis[dst][k + 1] != 1e9 ? dis[dst][k + 1] : -1;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, k = 1;
    Solution s;
    cout << s.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}