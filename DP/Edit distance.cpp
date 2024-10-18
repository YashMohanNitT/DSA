/*
    The edit distance between two strings is the minimum number of operations required to transform one string into the other.
    The allowed operations are:

    Add one character to the string.
    Remove one character from the string.
    Replace one character in the string.

    For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
    Your task is to calculate the edit distance between two strings.
    
    Input
        The first input line has a string that contains n characters between A–Z.
        The second input line has a string that contains m characters between A–Z.
    Output
        Print one integer: the edit distance between the strings.
   
    Constraints

        1 <= n,m <= 5000

    Example
        Input:
            LOVE
            MOVIE

        Output:
            2
*/

#include <bits/stdc++.h>
 
#define endl            "\n"
#define all(x)            x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()             int t; cin>>t; while(t--)
#define rep(i,a,b)      for(int i=a;i<b;++i)
#define vi                 vector<int>
#define vvi                 vector<vector<int>>
#define read(v,n)        rep(i,0,n) cin>>v[i];
#define int               long long
#define ull               unsigned long long
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;
#define pq                priority_queue
#define mod               1000000007
 
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

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
 
string n,m;
int mem[5010][5010];
int dp(int i, int j) {
    if(i == n.size() && j == m.size()) {
        return 0;
    }
    if (i == n.size()) {
        return m.size() - j; // take a look at this
    }
    if (j == m.size()) {
        return n.size() - i; // take a look at this
    }
    if (mem[i][j] != -1) {
        return mem[i][j];
    }
    if (n[i] == m[j]) {
        return mem[i][j] = dp(i + 1, j + 1);
    }
    int ans = INT_MAX;
    ans = min(ans, dp(i, j + 1)); // insert a new character
    ans = min(ans, dp(i + 1, j + 1));// replace the character 
    ans = min(ans, dp(i + 1, j));// delete the character
    return mem[i][j] = ans + 1;
}


void solve() {
    cin >> n >> m;
    memset(mem, -1, sizeof(mem));
    cout << dp(0, 0);
}
 
int32_t main()
{
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    yash;
    // w()
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}