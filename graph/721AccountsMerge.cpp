#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		vector<int> parent;
		vector<int> rank;
		
		int find(int x){
			if(parent[x] != x){
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		void unionSet(int x, int y){
			int rootX = find(x);
			int rootY = find(y);
			if(rootX != rootY){
				if(rank[rootX] > rank[rootY]){
					parent[rootY] = rootX;
				}else if (rank[rootX] < rank[rootY]){
					parent[rootX] = rootY;
				}else {
					parent[rootY] = rootX;
					rank[rootX]++;
				}
			}
		}
		vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
			unordered_map<string, int> emailToID;
			int emailCount = 0;
			for(int i = 0; i < 10001; i++){
				parent.push_back(i);
				rank.push_back(0);
			}
			for(int i = 0; i < accounts.size(); i++){
				for(int j = 1; j < accounts[i].size(); j++){
					string email = accounts[i][j];
					if(emailToID.find(email) == emailToID.end()){
						emailToID[email] = emailCount++;
					}
					unionSet(emailToID[accounts[i][1]], emailToID[email]);
				}
			}
			unordered_map<int, vector<string>> groups;
			for(auto& [email, id] : emailToID){
				int root = find(id);
				groups[root].push_back(email);
			}
			vector<vector<string>> mergedAccounts;
			for(auto& [root, emails] : groups){
				sort(emails.begin(), emails.end());
				string name = "";
				for(auto& account: accounts){
					if(emailToID[account[1]] == root){
						name = account[0];
						break;
					}
				}
				emails.insert(emails.begin(), name);
				mergedAccounts.push_back(emails);
			}
			return mergedAccounts;
		}
};
int main(){
    Solution obj;
	vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
	vector<vector<string>> result = obj.accountsMerge(accounts);
	for (const auto& account : result) {
		for (const auto& email : account) {
			cout << email << " ";
		}
		cout << endl;
	}
	return 0;
}