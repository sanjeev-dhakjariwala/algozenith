#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()){
			return 0;
		}
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>> indegree(rows, vector<int>(cols, 0));
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};
		
		// Step 1: Compute Indegree
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				for(int k = 0; k < 4; k++){
					int x = i + dx[k];
					int y = j + dy[k];
					if(x >= 0 && x < rows && y >= 0 && y < cols &&
						matrix[x][y] > matrix[i][j]){
						indegree[x][y]++;
					}
				}
			}
		}
		queue<ii> q;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(indegree[i][j] == 0){
					q.push({i, j});
				}
			}
		}
		int longestPath = 0;
		while(!q.empty()){
			int size = q.size();
			longestPath++;
			for(int i = 0; i < size; i++){
				auto [r, c] = q.front();
				q.pop();
				for(int k = 0; k < 4; k++){
					int x = r + dx[k];
					int y = c + dy[k];
					if(x >= 0 && x < rows && y >= 0 && y < cols &&
						matrix[x][y] > matrix[r][c]){
						indegree[x][y]--;
						if(indegree[x][y] == 0){
							q.push({x, y});
						}
					}
				}
			}
		}
		return longestPath;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << s.longestIncreasingPath(matrix) << endl;
    return 0;
}