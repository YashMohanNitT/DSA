/*
Farmer John's N
 cows (1≤N≤1000
) want to organize an emergency "moo-cast" system for broadcasting important messages among themselves.
Instead of mooing at each-other over long distances, the cows decide to equip themselves with walkie-talkies, one for each cow. These walkie-talkies each have a limited transmission radius, but cows can relay messages to one-another along a path consisting of several hops, so it is not necessary for every cow to be able to transmit directly to every other cow.

The cows need to decide how much money to spend on their walkie-talkies. If they spend $X, they will each get a walkie-talkie capable of transmitting up to a distance of X−−√
. That is, the squared distance between two cows must be at most X
 for them to be able to communicate.

Please help the cows determine the minimum integer value of X
 such that a broadcast from any cow will ultimately be able to reach every other cow.

INPUT FORMAT (file moocast.in):
The first line of input contains N
.
The next N
 lines each contain the x
 and y
 coordinates of a single cow. These are both integers in the range 0…25,000
.

OUTPUT FORMAT (file moocast.out):
Write a single line of output containing the integer X
 giving the minimum amount the cows must spend on walkie-talkies.
SAMPLE INPUT:
4
1 3
5 4
7 2
6 1
SAMPLE OUTPUT:
17
    
*/


#include <bits/stdc++.h>
 
#define endl            "\n"
#define all(x)           x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()             int t; cin>>t; while(t--)
#define rep(i,a,b)      for(int i=a;i<b;++i)
#define vpii            vector<pair<int, int>>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define read(v,n)       rep(i,0,n) cin>>v[i];
#define int             long long
#define ull             unsigned long long
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;
#define pq              priority_queue
#define mod             1000000007
 
using namespace std;
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}
template<typename t>
void evars(vector<vector<t>> a){
    for(auto i:a){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
#define EVARS(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}
 
inline void __evars_begin(int line) { cout << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cout << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cout << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cout << val; }
inline void __evars(vector<string>::iterator it) { cout << endl; }
 
template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cout << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cout << "; ";
    __evars(++it, args...);
}


void setIO(string name, bool useLocal){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!useLocal) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    } else {
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
    }
}

void dfs(int currCow, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[currCow] = true;
    for (auto nextCow : adj[currCow]) {
        if (!visited[nextCow]) {
            dfs(nextCow, visited, adj);
        }
    }
}

bool valid(int maxCost, vector<pair<int,int>> &cowCoords) {
    vector<vector<int>> adj(cowCoords.size());
    vector<bool> visited(cowCoords.size(), false);

    for(int i = 0; i < cowCoords.size(); ++i) {
        int x1 = cowCoords[i].first, y1 = cowCoords[i].second;
        for (int j = i + 1; j < cowCoords.size(); ++j) {
            int x2 = cowCoords[j].first, y2 = cowCoords[j].second;
            if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= maxCost) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    dfs(0, visited, adj);

    for (int i = 0; i < cowCoords.size(); ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

void solve() {
    setIO("moocast", false);
    int n;
    cin >> n;
    int x, y;
    vector<pair<int,int>> cowCoords;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        cowCoords.push_back({x, y});
    }
    int l = -1, r = 1250000010LL;
    while(r - l > 1) {
        int m = (l + r)/2;
        if(valid(m, cowCoords)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}
 
int32_t main()
{
    solve();
    return 0;
}