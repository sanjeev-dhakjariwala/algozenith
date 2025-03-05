#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool countChar(string s){
            int n = s.length();
            int c = 0;
            map<char, int> mp;
            for(auto c: s){
                mp[c]++;
            }
            return mp.size() == 1;
        }
        bool hasSpecialSubstring(string s, int k) {
            int n = s.size();
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    if(j - i + 1 == k){
                        string sub = s.substr(i, j - i + 1);
                        bool single = countChar(sub);
                        cout << "single" << single << "\n";
                        int prev = i - 1;
                        bool isPrevUni = true;
                        int next = j + 1;
                        bool isNextUni = true;
                        if(prev > -1){
                            if(s[prev] == s[j]){
                                isPrevUni = false;
                            }
                        }
                        if(next < s.size()){
                            if(s[next] == s[j]){
                                isNextUni = false;
                            }
                        }
                        if(single && isPrevUni && isNextUni){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    };
    int main(){
        Solution s;
        cout << s.hasSpecialSubstring("aaabaaa", 3) << "\n";
        return 0;
    }