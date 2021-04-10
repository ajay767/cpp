#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lli                                 long long int
#define ll                                  long long
#define FOR(i,a,b)                          for(int i=a;i<b;i++)
#define pi                                  pair<int,int>
#define vi                                  vector<int>
#define vii                                 vector<pi>
#define all(a)                              a.begin(),a.end()
#define sz(a)                               (int)a.size()
#define pb                                  push_back
#define ppb                                 pop_back
#define pf                                  push_front
#define fr                                  first
#define sc                                  second
#define uniq(v)                             (v).erase(unique(all(v)),(v).end())
using namespace std;

void _print(int x) {cerr << x;}void __print(long x) {cerr << x;}void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");}template<typename T, typename V>void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}void _print() {cerr << "]\n";}template <typename T, typename... V>void _print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// __builtin_popcountll(x);
// __builtin_clz(x) // Count Leading zeros
// __builtin_ctz(x) // Trailing zeros
const int MM = 998244353;
const int mod = 1e9 + 7;
const int INF = 1e9 + 5;
const int N = 5e6 + 4;
// vector<int>pref(N,0);
// vector<int>suff(N,0);


void solve()
{
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    if(a % 2 != 0 && b % 2 != 0) {
        cout << "-1\n";
        return;
    }
    int n = s.size();
    FOR(i,0,n/2) {
        char c1 = s[i];
        char c2 = s[n-i-1];
        if(c1 != c2 && c1 != '?' && c2 != '?') {
            cout << -1 << "\n";
            return;
        }
        if(c1 == c2 && c1 == '?') continue;
        if(c1 == c2) continue; // 0 == 0 or 1 == 1;
        if(c1 != c2 && c1 == '?') {
            c1 = c2;
        }
        if(c1 != c2 && c2 == '?') {
            c2 = c1;
        }
        s[i] = c1;
        s[n-i-1] = c2;
    }
    int cnt[2] = {0,0};
    for(char ch : s) {
        cnt[ch-'0']++;
    }
    if(cnt[0] > a) {
        cout << "-1\n";
        return;
    }
    if(cnt[1] > b) {
        cout << "-1\n";
        return;
    }
    // cerr << cnt[0] << " " << cnt[1] << '\n';
    char even;
    int fill;
    if(a % 2 == 0) {
        even = '0';
        fill = a - cnt[0];
    }
    else {
        even = '1';
        fill = b - cnt[1];
    }
    // debug(even,fill);
    for(int i=0;i<n/2 && fill != 0;i++) {
        if(s[i] == '?') {
            fill -= 2;
            s[i] = even;
            s[n-i-1] = even;
        }
    }
    if(even == '1') {
        even = '0';
    }
    else {
        even = '1';
    }
    for(char &ch : s) {
        if(ch == '?') {
            ch = even;
        }
    }
    cnt[0] = 0;
    cnt[1] = 0;
    for(char ch : s) {
        cnt[ch-'0']++;
    }
    if(cnt[0] != a) {
        cout << "-1\n";
        return;
    }
    cout << s << '\n';
}

signed main()
{
    ios;
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
/* stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?)
  * remember out of bounds case mainly in if else
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
*/