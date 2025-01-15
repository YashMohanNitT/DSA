/*
    Farmer John's cows have grown tired of his daily request that they sort themselves before leaving the barn each morning. They have just completed their PhDs in quantum physics, and are ready to speed things up a bit.
This morning, as usual, Farmer John's N
 cows (1≤N≤105
), conveniently numbered 1…N
, are scattered throughout the barn at N
 distinct locations, also numbered 1…N
, such that cow i
 is at location pi
. But this morning there are also M
 wormholes (1≤M≤105
), numbered 1…M
, where wormhole i
 bidirectionally connects location ai
 with location bi
, and has a width wi
 (1≤ai,bi≤N,ai≠bi,1≤wi≤109
).

At any point in time, two cows located at opposite ends of a wormhole may choose to simultaneously swap places through the wormhole. The cows must perform such swaps until cow i
 is at location i
 for 1≤i≤N
.

The cows are not eager to get squished by the wormholes. Help them maximize the width of the least wide wormhole which they must use to sort themselves. It is guaranteed that it is possible for the cows to sort themselves.

SCORING:
Test cases 3-5 satisfy N,M≤1000.
Test cases 6-10 satisfy no additional constraints.
INPUT FORMAT (file wormsort.in):
The first line contains two integers, N
 and M
.
The second line contains the N
 integers p1,p2,…,pN
. It is guaranteed that p
 is a permutation of 1…N.

For each i
 between 1
 and M
, line i+2
 contains the integers ai
, bi
, and wi
.

OUTPUT FORMAT (file wormsort.out):
A single integer: the maximum minimal wormhole width which a cow must squish itself into during the sorting process. If the cows do not need any wormholes to sort themselves, output −1
.
SAMPLE INPUT:
4 4
3 2 1 4
1 2 9
1 3 7
2 3 10
2 4 3
SAMPLE OUTPUT:
9
Here is one possible way to sort the cows using only wormholes of width at least 9:

Cow 1 and cow 2 swap positions using the third wormhole.
Cow 1 and cow 3 swap positions using the first wormhole.
Cow 2 and cow 3 swap positions using the third wormhole.
SAMPLE INPUT:
4 1
1 2 3 4
4 2 13
SAMPLE OUTPUT:
-1
No wormholes are needed to sort the cows.
    
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


void setIO(string name){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

void dfs(int currBarn, int minWidth, int component, vector<bool> &visited, vector<vector<pair<int, int>>> &neighbors, vector<int> &components) {
    visited[currBarn] = true;
    components[currBarn] = component;
    for (auto nextBarn : neighbors[currBarn]) {
        int next = nextBarn.first;
        int width = nextBarn.second;
        if (!visited[next] && width >= minWidth) {
            dfs(next, minWidth, component, visited, neighbors, components);
        }
    }
}

bool valid(int minWidth, vector<int> &cows, vector<vector<pair<int, int>>> &neighbors) {
    int n = neighbors.size();
    vector<bool> visited(n, false);
    int component = 1;
    vector<int> components(n, -1);
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) {
            dfs(i, minWidth, component, visited, neighbors, components);
            component++;
        }
    }
    // EVARS(components, cows);
    for (int i = 0; i < n; ++i) {
        // EVARS(components[i], components[cows[i]])
        if(components[i] != components[cows[i]]) {
            return false;
        }
    }
    return true;
}
void solve() {
    setIO("wormsort");
    int cow_num;
    int wormhole_num;
    cin >> cow_num >> wormhole_num;

    vector<int> cows(cow_num);
    bool sorted = true;
    for (int i = 0; i < cow_num; ++i) {
        cin >> cows[i];
        cows[i]--;
        if (i > 0) {
            sorted = sorted && (cows[i] > cows[i - 1]);
        }
    }
    if (sorted) {
        cout << -1 << endl;
        return;
    }

    int max_width = 0;
    vector<vector<pair<int, int>>> neighbors(cow_num);
    for (int w = 0; w < wormhole_num; w++) {
        int c1, c2, width;
        cin >> c1 >> c2 >> width;
        c1--;
        c2--;
        neighbors[c1].push_back({c2, width});
        neighbors[c2].push_back({c1, width});
        max_width = max(max_width, width);
    }

    int l = 0, r = max_width;
    while(r - l > 1) {
        int m = (l + r)/2;
        if(valid(m, cows, neighbors)) {
            l = m;
        } else {
            r = m;
        }
        // EVARS(l, r, m)
    }
    cout << l << endl;
}
 
int32_t main()
{
    // clock_t begin = clock();
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    yash;
    // w()
    solve();
// #ifndef ONLINE_JUDGE
//     clock_t end = clock();
//     cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
// #endif
    return 0;
}