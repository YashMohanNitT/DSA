/*
    Problem link/desc
*/
#include <bits/stdc++.h>
using namespace std;

#define endl       "\n"
#define all(x)     (x).begin(), (x).end()
#define yash       ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()        int t; cin >> t; while (t--)
#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define vpii       vector<pair<int,int>>
#define vi         vector<int>
#define vvi        vector<vector<int>>
#define read(v,n)  rep(i,0,n) cin >> v[i];
#define int        long long
#define out(v,n)   rep(i,0,n) {cout << v[i] << " ";}cout << endl;

void setIO(const string &fileName, bool useLocal) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    if (!useLocal) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    } else {
#ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
    }
}

int32_t main(){
    // setIO("", true);
    w() {
        int n, k; cin >> n >> k;
        map<int,int> freq;
        rep(i,0,n){
            int a; cin >> a;
            freq[a]++;
        }
        // debug(freq);
        vector< pair<int,int> > freqPair;
        for (auto &[k, v] : freq){
            // push_back({ frequency, value })
            freqPair.push_back(make_pair(v, k));
        }
        sort(all(freqPair));
        // debug(freqPair);
        int idx = 0, ans = freqPair.size();
        while (k > 0 && idx < (int)freqPair.size() - 1) {
            int cost = freqPair[idx].first;
            if (cost <= k) {
                k -= cost;
                ans--;
                idx++;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
