#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int l;
    int ans = 0;
    bool check(string& s){
        if(s.size() >= 4){
            if(s[0] == s[s.size() - 1]){
                return true;        
            }
        }
        return false;
    }
    void solve(int start, string& word){
        if(start >= l){
            return;
        }
        for(int i = start; i < l; i++){
            for(int j = start; j < l; j++){
                string s = word.substr(i, (j - i) + 1);
                if(check(s)){
                    ans++;
                    solve(j + 1, word);
                    return;
                }
            }            
        }
    }
    int maxSubstrings(string word) {
        l = word.size();
        solve(0, word);
        return ans;
    }
};
int main(){
    Solution sol;
    sol.maxSubstrings("abcdeafdef");
}