/* #include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += "#";
        }

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            int mirror = 2 * center - i;
            if (i < right)
                p[i] = min(right - i, p[mirror]);

            int a = i + p[i] + 1;
            int b = i - p[i] - 1;
            while (a < n && b >= 0 && t[a] == t[b])
            {
                p[i]++;
                a++;
                b--;
            }

            if (i + p[i] > right)
            {
                center = i;
                right = i + p[i];
            }

            count += (p[i] + 1) / 2; // each center contributes this many palindromes
        }

        return count;
    }
};
int main(){
    Solution solution;
    string s = "abc";
    cout << solution.countSubstrings(s) << "\n";
} */

#include<bits/stdc++.h>
using namespace std;
// #define int long long
struct manacher{
    vector<int> p;
    void run_manacher(string s){
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for(int i = 1; i < n; i++){
            p[i] = max(0, min(r - i, p[l + r - i]));
            while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]){
                p[i]++;
            }
            if(i + p[i] > r){
                l = i - p[i];
                r = i + p[i];
            }
        }
        for(auto v: p){
            cout << v << " ";
        }
        cout << "\n";
    }
    void build(string s){
        cout << s << "\n";
        string t = "#";
        for(auto it: s){
            t += it;
            t += "#";
        }
        cout << t << "\n";
        run_manacher(t);
    }
}m;
void solve(){
    string s = "bab";
    m.build(s);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
	t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
