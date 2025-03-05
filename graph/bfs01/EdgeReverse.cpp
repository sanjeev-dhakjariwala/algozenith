#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
int n, m;
vector<vector<ii>> graph;
vector<bool> vis;
vector<int> dis;

void bfs01(){
	deque<int> dq;
	dq.push_front(1);
	dis[1] = 0;
	while(!dq.empty()){
		auto parent = dq.front();
		dq.pop_front();
		for(auto neigh: graph[parent]){
			int node = neigh.first;
			int weight = neigh.second;
			if(dis[node] > weight + dis[parent]){
				dis[node] = weight + dis[parent];
				if(weight){
					dq.push_back(node);
				}else{
					dq.push_front(node);
				}
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	graph.resize(n + 1);
	vis.resize(n + 1, false);
	dis.resize(n + 1, 1e18);
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back({v , 0});
		graph[v].push_back({u, 1});
	}
	bfs01();
	if(dis[n] == 1e18){
		cout << -1 << "\n";
	}else{
		cout << dis[n] << "\n";
	}
	graph.clear();
	dis.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}