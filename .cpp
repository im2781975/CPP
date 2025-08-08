template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #VA_ARGS << "):", dbg_out(VA_ARGS)
#else
#define dbg(...)
#endif
#define ar array
#define ll…
#define all(cont) cont.begin(), cont.end()
#define ll long long
using namespace std;
#define xx long long
#define foi(xxxxx) for(xx yyyyy=0;yyyyy<xxxxx;yyyyy++)
typedef vector<xx>          vll;
#include<string>
#include <sstream>
#include<bitset>
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define br printf("\n")
#define fo(i, n) for(i=0;i<n;i++)
#define fox(i, a,b) for(i=a;i<=b;i++)
#define reps(i, a,b) for(int i=a;i<=b;i++)
#define repe(i, a,b) for(int i=a;i>=b;i--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n…
[10:29 pm, 23/01/2022] Pratik Suryawanshi: #include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")
#define gc getchar_unlocked
#define ll long long int
#define br printf("\n")
#define fo(i, n) for(i=0;i<n;i++)
#define fox(i, a,b) for(i=a;i<=b;i++)
#define reps(i, a,b) for(int i=a;i<=b;i++)
#define repe(i, a,b) for(int i=a;i>=b;i--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y;
#include<bits/stdc++.h>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define google(tc) cout<<"Case #"<<tc++<<": ";
#define FILE freopen("input.txt","r",stdin); freopen("output.txt","w", stdout);
#define GetSetBolt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define ll long long int  
#define LD long double
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#endif
#define max3(a,b,c) max(a,max(b,c)) 
#define min3(a,b,c) min(a,min(b,c)) 
#define FF first 
#define SS second 
#define PB push_back 
#define PF push_front 
#define PPB pop_back  
#define PPF pop_front  
#define Endl endl
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define in2(arr,n,m) for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cin>>arr[i][j];}
#define dis(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
#define dis2(arr,n,m) for(int ii=0;ii<n;ii++){for(int j=0;j<m;j++)cout<<arr[ii][j]<<" ";cout<<endl;} 
#define tc int t=0;cin>>t; while(t--) 

#define For(n) for(ll i=0;i<n;i++)
#define For0(x,z) for(ll x=0;x<z;x++)
#define Forx(x,z) for(x;x<z;x++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

#define toLower(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define toUpperr(s) transform(s.begin(),s.end(),s.begin(),::toupper)

#define sortAD(arr,n) sort(arr,arr+n, greater<int>());
#define sortVD(v) sort(v.begin(), v.end(), greater<int>());
#define sortA(arr) sort(arr,arr+n);
#define sortV(v) sort(v.begin(),v.end());

#define mem0(X) memset((X), 0, sizeof((X)))
#define memx(X,x)  memset((X), x, sizeof((X)))
#define setbits(X)  __builtin_popcountll(X)
#define precise(X)  cout<<fixed << setprecision(X);
#define valid(x,y,row,col) (((x) >= 0 and (x) < row) and ((y) >= 0 and (y) < col))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define timer(d) for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))
#define rsz resize
#define bk back()
#define ld long double
typedef pair<int, int> PII; 
typedef pair<ll, ll> PLL;
typedef pair<double,double> PDD;
typedef pair<string, string> PSS; 
typedef pair<string, ll> PSL; 
typedef long double lld;

typedef vector<int> VI;  
typedef vector<ll> VL;  
typedef vector<double> VD;
typedef vector<string> VS; 
typedef vector<VI> VVI;  
typedef vector<VL> VVL; 
typedef vector<VS> VVS; 
typedef vector<PII> VPII; 
typedef vector<PLL> VPLL; 
typedef vector<PSS> VPSS; 
typedef vector<PSL> VPSL; 

typedef map<int,int> MII; 
typedef map<ll,ll> MLL;   
typedef map<char,ll> MCL;  
typedef map<char,int> MCI; 
typedef map<char,ll> MCL;   
typedef map<string,string> MSS;  
typedef map<string,int> MSI;  
typedef map<string,ll> MSL; 

typedef unordered_map<int,int> UMII; 
typedef unordered_map<ll,ll> UMLL;   
typedef unordered_map<char,ll> UMCL;  
typedef unordered_map<char,int> UMCI; 
typedef unordered_map<char,ll> UMCL;   
typedef unordered_map<string,string> UMSS;  
typedef unordered_map<string,int> UMSI;  
typedef unordered_map<string,ll> UMSL; 
typedef unsigned long long ull;

const int inf = (int)1e9 + 5;
const ll infl = (ll)1e18 + 5;
const ld PI = acos((ld)-1);
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};   // for every grid problem


//--------------------------------- Trace Functions --------------------------------------

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void fastio() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define int ll
#define endl "\n"
#define ll          long long
#define vi          vector<int>
#define vll         vector<ll>
#define pll         pair<ll, ll>
#define pb          push_back
#define endl        '\n'
#define ll          long long
#define pb          push_back
#define endl        '\n'
: #pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 1001001001
typedef unsigned int ui;
typedef unsigned long long int ul;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 1001001001
typedef unsigned int ui;
typedef unsigned long long int ul;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 1001001001
typedef unsigned int ui;
typedef unsigned long long int ul;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,char>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 1001001001
typedef unsigned int ui;
typedef unsigned long long int ul;
#define all(c) c.begin(),c.end()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(__gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout(x) freopen(x, "w", stdout)
#define filein(x) freopen(x, "r",stdin)
#define error(x) freopen(x,"w",stderr)
#define sqr(x) ((x)*(x))
#define cube(x) ((x)(x)(x))
#define inf 1<<30
#defin#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 1001001001
const long double pi = 3.141592653;
typedef unsigned int ui;
typedef unsigned long long int ul;
#define all(c) c.begin(),c.end()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(__gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout(x) freopen(x, "w", stdout)
#define filein(x) freopen(x, "r",stdin)
#define error(x) freopen(x,"w",stderr)
#define sqr(x) ((x)*(x))
#…
[8:18 pm, 21/01/2022] Pratik Suryawanshi: #pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 1001001001
const long double pi = 3.141592653;
typedef unsigned int ui;
typedef unsigned long long int ul;
#define all(c) c.begin(),c.end()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(__gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout(x) freopen(x, "w", stdout)
#define filein(x) freopen(x, "r",stdin)
#define error(x) freopen(x,"w",stderr)
#define sqr(x) ((x)*(x))
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 1001001001
typedef unsigned int ui;
typedef unsigned long long int ul;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1e9+7
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define INF 100100100
#define all(c) c.begin(),c.end()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(__gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout(x) freopen(x, "w", stdout)
#define filein(x) freopen(x, "r",stdin)
#define error(x) freopen(x,"w",stderr)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(),c.end()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(__gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout(x) freopen(x, "w", stdout)
#define filein(x) freopen(x, "r",stdin)
#define error(x) freopen(x,"w",stderr)
#define sqr(x) ((x)*(x))
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long
#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

void fileIO(void) {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif


#ifdef ONLINE_JUDGE
    //freopen("", "r", stdin);
#endif

}

void fastIO(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

typedef pair<ll, ld> pld;
typedef pair<double, pii> pdii;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

typedef vector<ll> vl;
typedef vector<pll> vll;
typedef vector<plll> vlll;

typedef vector<string> vs;
typedef vector<bool> vb;

typedef vector<vl> vvl;

typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int>> pqr;

#define loop(n)          for(int i = 0; i < (n); i++)
#define lop(n)           for(int j=0;j<(n);j++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define loop_r(n)          for(ll i = (n) - 1; i >= 0; i--)
#define lp_r(x, s, e)      for(ll x = (e) - 1; x >= (s); x--)
#define lpe_r(x, s, e)     for(ll x = (e); x >= (s); x--)

#define MP make_pair
#define PB push_back
#define EmB emplace_back
#define Em emplace
#define len(s)   (ll)s.length()
#define sz(v)    (ll)v.size()
#define all(a)   a.begin(),a.end()
#define all_r(a)   a.rbegin(),a.rend()
#define clr(x, val)    memset((x), (val), sizeof(x))
#define maxEle *max_element
#define minEle *min_element
#define MP make_pair
#define PB push_back
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define all_r(a)   a.rbegin(),a.rend()
#define clr(x, val)    memset((x), (val), sizeof(x))

#define tests int t; cin >> t; int i = 0; while(i++ < t)
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <iomanip>

using namespace std;

typedef long long ll;

#define P pair
typedef P<int, int> Pii;
typedef P<ll, ll> Pll;
#define mp make_pair
#define fi first
#define se second

#define V vector
typedef V<int> Vi;
typedef V<Pii> VPii;
typedef V<ll> Vll;
typedef V<Pll> VPll;

#define pb push_back
#define all(v) (v).begin(), (v).end()
#define forn(i, n, l) for (int i = l; i < n; i++)

typedef set<int> si;
typedef multiset<int> mi;
typedef map<int, int> mii;

#define endl '\n'
#define escanor return 0
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define pf push_front
#define start ios_base::sync_with_stdio(0)
#define fi first
#define se second
include <iostream>
#include <set>
 #define pr pair<long long, long long>
#define fr first
#define sc second
#define ll long long int
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repf(i, a, b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
#define int long long
#define pb push_back
#define s second
#define f first
#define pii pair<int,int>
 #define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <vector>
#include <utility>
#include <iomanip>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <queue>
#define MAXN 100005
#define ZERO 0
#define ONE 1
#define TWO 2
#include <unordered_set>
#include <deque>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef pair<ll, ld> pld;
typedef pair<double, pii> pdii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef vector<plll> vlll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vl> vvl;
#define loop(n)          for(int i = 0; i < (n); i++)
#define loop2(n)          for(int j = 0; j < (n); j++)
#define loop1(n)          for(int i = 1; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define for_each(n)     for(auto &it : n)
#define SZ(v) ((int)((v).size()))
#define MP make_pair
#define PB push_back
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define all_r(a)   a.rbegin(),a.rend()
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <vector>
#include <utility>
#include <iomanip>
#include <cstring>
#include <string>
#include <set>
#include <deque>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

typedef pair<ll, ld> pld;
typedef pair<double, pii> pdii;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;

typedef vector<ll> vl;
typedef vector<pll> vll;
typedef vector<plll> vlll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;

typedef vector<vl> vvl;
#define loop(n)          for(int i = 0; i < (n); i++)
#define loop2(n)          for(int j = 0; j < (n); j++)
#define loop1(n)          for(int i = 1; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define for_each(n)     for(auto &it : n)
#define SZ(v) ((int)((v).size()))
#define MP make_pair
#define PB push_back
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define sc second
#define fi first

#define all_r(a)   a.rbegin(),a.rend()
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cfloat>
#include <sstream>
#include <unordered_set>
#include <queue>
#include <deque>
#include <iomanip>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cctype>
#include <chrono>
#include <random>
#include <iostream>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <valarray>
#include <cmath>
#include <numeric>
#include <iostream>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
 #include <iostream>
 #include<set>
 #include<map>
 #include<stack>
 #include<queue>
 #include<vector>
 #include<cstdio>
 #include<string>
 #include<cstring>
 #include<cstdlib>
 #include<iostream>
 #include<algorithm>
 #include<cmath>
#define forI(n) for(ll i = 0; i < n; ++i)
#define forJ(n) for(ll j = 0; j < n; ++j)
#define forR(n) for(ll i = n - 1; i >= 0; --i)
#define forRangeI(l, r) for(ll i = l; i <= r; ++i)
#define forRRangeI(l, r) for(ll i = r; i >= l; --i)
#define forRangeJ(l, r) for(ll j = l; i <= r; ++i)
#define forRRangeJ(l, r) for(ll j = r; i >= l; --i)
#define forEach(array) for(auto &item : array)
#define forEach1(array) for(auto &item1 : array)
#define printSpace(a) cout << a << " "
#define printSpace2(a, b) cout << a << " " << b << " "
#define printSpace3(a, b, c) cout << a << " " << b << " " << c << " "
#define printSpace4(a, b, c, d) cout << a << " " << b << " " << c << " " << d <<" "
#define printSpace5(a, b, c, d, e) cout << a << " "<< b << " " << c << " " << d <<" " << e << " "
#define printSpace6(a, b, c, d, e, f) cout << a << " "<< b << " " << c << " " << d <<" "<< e << " " << f << " "
#define printLn(n) cout << n << '\n'
#define printNL() cout <<'\n'
#define print(n) cout << n
typedef long long ll;
typedef unsigned long long ull;
#include <bits/stdc++.h>
#define ceill(n,m) (n / m + (n%m != 0))
#define ll	 long long
using namespace std;
const int siz = 100000;
typedef int Back;
typedef long l;
typedef float f;
typedef double d;
typedef long double ld;
typedef double d;
#define nooo cout << "NO\n";
#define yeee cout << "YES\n";
#define fine cout <<"OK\n";
#define c(x)  cout <<x
#define container(x) vector<int> container(x)
#define pqmx priority_queue
#define pqmni priority_queue <int, vector<int>, greater<int> >
#define pqmnll priority_queue <ll, vector<ll>, greater<ll> > 
#define pb push_back
#define mp make_pair
#define V2Di(c,r) vector<vector <int>> VECT(c,vector<int>(r));
#define KHOD_HAT(FILE,FILE2) freopen(FILE,"r",stdin); freopen(FILE2,"w",stdout); auto start = high_daysolution_clock::now();
#define KHOD(FILE) freopen(FILE,"r",stdin);
#define untie ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mem(x,n) memset(x,n,sizeof x);
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define read(x) for (auto &it:(x))cin >> it;
#define print(x) for (auto &it:(x))cout << it << " ";
#define print2D(x) for (vector<int> vect1D : x) {for (auto &it:vect1D)cout << it << " "; cout << endl;}
#define f0(n) for (int i = 0; i < n; i++)
#define f1(n) for (int i = 1; i <= n; i++)
#define isVOWEL(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define setP(n) cout << fixed<<setprecision(n);
#define en endl
#define all(a) (a).begin(),(a).end()
#define fr(n) for(int i=0;i<n;i++)
#define countTime auto stop = high_daysolution_clock::now(); auto duration = duration_cast<milliseconds>(stop - start); cout << "\n$time in ms: "<<duration.count();
const double pi = 3.14159265359; //atan(1)*4 as precision(13)
const double e = 2.71828182846;
const int mod = 1e9 + 7;
/ For printing
#define p0(a) cout << a << " "
#define p1(a) cout << a << "\n"
#define p2(a, b) cout << a << " " << b << "\n"
#define p3(a, b, c) cout << a << " " << b << " " << c << "\n"
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << "\n"
#define p5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << "\n"

#define fsp(n) fixed << setprecision(n)

#define pfi(x) printf("%d\n", x);
#define pfi2(x, y) printf("%d %d\n", x, y);
#define pfi3(x, y, z) printf("%d %d %d\n", x, y, z);

#define pfl(x) printf("%lld\n", x);
#define pfl2(x, y) printf("%lld %lld\n", x, y);
#define pfl3(x, y, z) printf("%lld %lld %lld\n", x, y, z);

#define pfs(x) printf("%s\n", x);
#define pfs2(x, y) printf("%s %s\n", x, y);
#define pfs3(x, y, z) printf("%s %s %s\n", x, y, z);

#define ia(arr, n) \
    f0(i, n) { cin >> arr[i]; }
#define pa(arr, n)                      \
    f0(i, n) { cout << arr[i] << " "; } \
    cout << "\n";

//Scanf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define sf5(a, b, c, d, e) scanf("%d %d %d %d %d", &a, &b, &c, &d, &e)
#define sf1l(a) scanf("%I64d", &a)
#define sf2l(a, b) scanf("%I64d %I64d", &a, &b)
#define sf3l(a, b, c) scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sf4l(a, b, c, d) scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)
#define sf5l(a, b, c, d, e) scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &d, &e)

// Short Forms
#define ld long double
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define al(x, n) (x), (x) + n
#define mp make_pair
#define sz size()
#define clr clear()
#define len length()

// Constant
#define Mod 1000000007
#define Mod2 998244353
#define INF 2147483647
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};

// Self Defined
#define gcd __gcd
#define lcm(a, b) (a * b) / gcd(a, b)
#define rsort(r) sort(r, greater<ll>())
#define ABS(r) ((r) < 0 ? -(r) : (r))
#define deb(x) cout << ">> " << #x << " : " << x << endl;

// Max - Min
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
#define max5(a, b, c, d, e) max(max4(a, b, c, d), e)
#define min5(a, b, c, d, e) min(min4(a, b, c, d), e)
#define maxa(v) *max_element(v, v + v.size())
#define mina(v) *min_element(v, v + v.size())

//remain
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define f3(i, n) for (ll i = n - 1; i >= 0; i--)
#define f4(i, n) for (ll i = n; i > 0; i--)

// Type Def Start
typedef long long int ll;
// typedef int64_t ll;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<int, string> mis;

typedef unordered_map<string, int> usi;
typedef unordered_map<int, int> uii;
typedef unordered_map<ll, ll> ull;
typedef unordered_map<char, int> uci;
typedef unordered_map<int, string> uis;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef pair<int, pii> tri;
typedef pair<double, double> pd;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<pii> vpi;

typedef priority_queue<int, vector<int>, greater<int>> rpq;
typedef priority_queue<int> pq;

typedef set<int> si;
typedef set<ll> sl
#include <algorithm> 
#include <array>
#include <bitset>
#include <unordered_map>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
#include <immintrin.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>
// typedef vector<int> VI;// Standard template library (STL)
#define all(v) ((v).begin()),((v).end()); // Standard template library(STL)
#define sz(v)  ((int)((v).size())); // Standard template library (STL)
// two functions for vector : front {V.front()}   back {V.back()}  
// For swaping the first and the last element => swap(V.front() , V.end())
//=========================================================================//
//vector from vector
//v3(v1.begin() , v1.end())
// RESIZE => resize(15) from 10 for example to 15
// Unique => v.resize(unique (all(v)) - v.begin())
// Set intersection    => set_intersection(all(v1) , all(v2) , back_intersecter(v)) [find the intersection between them]
// Set difference      => set_difference  (all(v1) , all(v2) , back_intersecter(v)) [find what is in v1 not in v2]
// FOR decreasing sort => sort(v.begin() , v.end() , greater<int>) || sort(v.rbegin() , v.rend());
// Set union           => set_union(all(v1) , all(v2) , back_intersecter(v))) 
 
/*
MAX_ELEMENT => maxx = *max_element(v.begin() , v.end()); 
MIN_ELEMENT => minn = *min_element(v.begin() , v.end()); 
 
int vecSum = accumulate(all(v) , 0) => SUMMTION
int vecMulti = accumulate(all(v) , 1 , multiplies<int> ()) => multiplie all elements
 
INNER PRODUCT => 
int sumproduct1 = inner_product(A.begin(), A.end(), A.begin(), 0); // every element multiples by itself and sum with the next
*/
//============================ Queue =======================//
// queue<int> q;
// q.push(10); 
// q.push(20); 
// q.push(30);
 
// while(!q.empty()){
//     cout << q.front() << endl;
//     q.pop();
// }
//=========================== deQue =====================//
// deque <int> dq;
// dq.push_back(30);
// dq.push_front(10);
//=========================== Stack (LIFO)===============//
//LAST IN FIRST OUT
// stack<int> st;
// st.push(10);
// st.push(20);
// st.push(30);
// cout << "Element of stack : ";
// while(!st.empty()){
//     cout << st.top() << " ";
//     st.pop();
// }
//========================== PAIR =======================//
// pair<int , char> p1 = make_pair(20,'a')
// pair<string , pair<int  , char>   p2 =  make_pair("mostafa" , p1)
// cout << p2 . first << "\n";
// cout << p2 . second . first << "\n";
// cout << p2 . second . second << "\n";
// vector<pair<int,int> vp;
// vp . push_back(make_pair(1 , 2))
// vp . push_back(make_pair(2 , 2))
// vp . push_back(make_pair(3 , 3))
// sort(all(vp) , sortpairscmp);
//========================== MAP =======================//
 
// map<string , int> mp ;
// mp["muhamed"] = 10 ;
// mp["hamed"] = 20 ;
//convert map to vector
// vector<pair<string,int> > mptov(all(mp));
// for(int i = 0 ; i < (int)(mptov.size()) ; ++i){
//     cout << mptov[i].first << " " << mptov[i].second<<"\n"; 
// }
typedef long long ll;
typedef long double ld;
#include<bits/stdc++.h>
#include<sstream>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<iterator>
#include<iostream>
#include<cmath>

#define lli long long int
#define ld long double
#define llu long unsigned int
#define mod ((lli)(1e9+7))
#define ilpf(a,b) for(lli i=a;i<=b;i++)
#define jlpf(a,b) for(lli j=a;j<=b;j++)
#define klpf(a,b) for(lli k=a;k<=b;k++) 
#define ilpb(a,b) for(lli i=a;i>=b;i--)
#define jlpb(a,b) for(lli j=a;j>=b;j--)
#define klpb(a,b) for(lli k=b;k>=a;k--)
#define vlli vector<lli>
#define vld vector<ld>
#define vb vector<bool>
#define vch vector<char>
#define vstr vector<string>
#define vpllilli vector<pair<lli,lli>>
#define vpllild vector<pair<lli,ld>>
#define vpldlli vector<pair<ld,lli>>
#define vpllib vector<pair<lli,bool>>
#define vpldld vector<pair<ld,ld>>
#define vpldb vector<pair<ld,bool>>
#define vpstrlli vector<pair<string,lli>>
#define vpllistr vector<pair<lli,string>>
#define vpstrld vector<pair<string,ld>>
#define vpldstr vector<pair<ld,string>>
using namespace std;
lli llin(){lli x;scanf("%lld",&x);return x;}
ld ldin(){ld x;scanf("%Lf",&x);return x;}
char chin(){char ch;cin>>ch;return ch;}
string strin(){string str;cin>>str;return str;}
void No(){ cout<<"No"<<endl;}
void NO(){ cout<<"NO"<<endl;}
void Yes(){ cout<<"Yes"<<endl;}
void YES(){ cout<<"YES"<<endl;}
lli fmin_i(vlli v){lli n=v.size(),mn_i=0,mn_e=v[0];ilpf(0,n-1){lli MIN=min(mn_e,v[i]);if(MIN!=mn_e){mn_e=MIN;mn_i=i;}}return mn_i;}
lli fmax_i(vlli v){lli n=v.size(),mx_i=0,mx_e=v[0];ilpf(0,n-1){lli MAX=max(mx_e,v[i]);if(MAX!=mx_e){mx_e=MAX;mx_i=i;}}return mx_i;}
lli lmin_i(vlli v){lli n=v.size(),mn_i=0,mn_e=v[0];ilpf(0,n-1){if(v[i]<=mn_e){mn_e=v[i];mn_i=i;}}return mn_i;}
lli lmax_i(vlli v){lli n=v.size(),mx_i=0,mx_e=v[0];ilpf(0,n-1){if(v[i]>=mx_e){mx_e=v[i];mx_i=i;}}return mx_i;}
lli min_e(vlli v){lli mn_e=v[0],n=v.size();ilpf(0,n-1)mn_e=min(mn_e,v[i]);return mn_e;}
lli max_e(vlli v){lli mx_e=v[0],n=v.size();ilpf(0,n-1)mx_e=max(mx_e,v[i]);return mx_e;}
void make_prime(vb&v){lli I=2,n=(lli)v.size()-1;ilpf(0,n)v[i]=true;v[0]=false;v[1]=false;while(I<=n){while(I<=n&&!v[I])I++;if(I>n)break;lli i=2;while(i*I<=n){v[i*I]=false;i++;}I++;}}

/*---------------------------------------------------Vector STL/Function----------------------------------------------------------
 * vlli v2(v.begin(),v.begin()+size);
 * vlli v2(v)
 * sort(v.begin().v.end())
 * reverse(v.begin(),v.end())
 * (bool) binary_search(v.begin(),v.end(),key)
 * (iterator) lower_bound(v.begin(),v.end(),key);
 * (iterator) upper_bound(v.bein(),v.end(),key);
 * (iterator) v.lower_bound(key);
 * (iterator) v.upper_bound(key);
 * v.erase(v.begin()+i)
 * v.erase(unique(v.begin(),v.end()),v.end())
 * v.erase(v.begin()+i,v.end()-j)  ||    v.erase(v.begin(),v.begin()+j)
 * v.erase(remove(v.begin(),v.end(),data),v.end())  //erase  all the 'data' from the vector
 * (bool)next_premutation(v.begin(),v.end())
 * (bool)prev_premutation(v.begin(),v.end())
 * v.insert(it,data) || v.insert(i,data)  
 * v.insert(it,no_of_times,data) || v.insert(i,no_of_times,data)
 * 
 * v.push_back(data),v.pop_back(data),(data) v.front() ,(data) v.back() ,(data) v[index] ,(iterator) v.begin() ,(iterator) v.end()
 * (lli) max_e(v) ,(lli)min_e(v) ,lli fmax_i(v) ,lli lmax_i(v) ,lli fmin_i(v) ,lli lmin_i(v)
 * vector<vector<int>>v(r,vector<int>(c));
 */ 
 
 /*--------------------------------------------------Vector of pairs----------------------------------------------------------------
  * vector<pair<key_type,data type>> vp
  * vp.push_back(make_pair(key,data))
  * 
  * sort by key/first element (then data/second)
  * sort(vp.begin(),vp.end()) 
  * 
  * sort by sec element(only by sec)
  * bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
  * { 
  *       return (a.second < b.second); 
  * }
  * sort(vp.begin(),vp.end(),sortbysec) 
  * 
  * (data) vp[i].first ,(data) vp[i].second ,
  */
  
  /*----------------------------------------------String Manupulation -------------------------------------------------------------
   * string str2(str1)
   * string str2(str1.begin(),str1.begin()+length)
   * string s=str.substr(starting_index,length) 
   * s.erase(s.begin()+index)
   * s.erase(s.begin()+index,s.end()-index)  ||  s.erase(s.begin()+index(),s.begin()+index)
   * s.erase(unique(s.begin(),s.end()),s.end())  ::adjecent will not be same
   * sort(s.begin(),s.end());
   * reverse(s.begin(),s.end())
   * str.erase(remove(str.begin(),str.end(),'ch'),str.end()); //erase all the 'ch' from string
   * str.insert(it,'ch')  ||  str.insert(i,'ch')
   * str.insert(it,no_of_times,'ch') ||  str.insert(i,no_of_times,'ch')
   * 
   * getline(cin,string_name)
   * stringstream(string_name)>>type1_>>type2_>>type3_.........>>typeN_;
   * stringstream STREAM_name(string_name)
   * STREAM_name>>type1_>>type2_>>type3>>type4_>>type5_;
   * s=to_string(2018)
   */
   
 /* -------------------------------------------------STACK------------------------------------------ 
  * stack<data_type>s
  * push()              :s.push(data)           :O(1)
  * pop()               :s.pop()                :O(1)
  * top()               :s.top()                :O(1)
  * empty()             :s.empty()              :O(1)
  * size()              :s.size()               :O(1)
  */
  
 /* -------------------------------------------------QUEUE------------------------------------------          
  * queue<data_type>q    
  * push()               :q.push(data)          :O(1)
  * pop()                :q.pop()               :O(1)
  * front()              :q.front()             :O(1)
  * back()               :q.back()              :O(1)
  * empty()              :q.empty()             :O(1)
  * size()               :q.size()              :O(1)
  */
  
 /*------------------------------------------ priority_queue(default MAX HEAP)-------------------------------
  * priority_queue(data_type>pq
  * push()               :pq.push(data)         :O(log(n))
  * pop()                :pq.pop()              :O(long(n))
  * top()                :pq.top()              :O(1)
  * size()               :pq.size()             :O(1)
  * empty()              :pq.empty()            :O(1)
  */

 /*-------------------------------SET:Element in sorted order(increasing) and UNIQUE*****----------------------
 * declaration     :set<lli>s
 * insertion       :s.insert(data)  //insert if it is not present     :O(log(n))             
 * size            :s.size()                                          :O(1) 
 * find            :auto it=s.find(data) //if it!=s.end -> data found :O(log(n))
 * s.lower_bound() :it=s.lower_bound(data)
 * s.upper_bound() :it=s.upper_bound(data)
 * lower_bound()   :it=lower_bound(s.begin(),s.end(),data)
 * upper_bound()   :it=upper_bound(s.begin(),s.end(),data)
 * erase()         :erase(it)
 * erase()         :s.erase(it1,it2)
 * s.erase()       :s.erase(data)
 * loop            :for(auto it=s.begin();it!=s.end();it++)
 */
 
 /*------------------------------------------MAP:Elemnet r SORTED,unlike set we insert (key and data)--------------------------
 * declaration   :map<key_type,data_type>m
 * insert        :m.insert(make_pair(key,data));                     :O(log(n))
 *               :m.insert(pair<type,type>(key,data))
 * find          :auto it=m.find(key) //if(it!=m.end)it->first=key   :O(log(n))
 * []            :m[key]++      //data=data+1 ,at that key           :O(log(n))
 * size          :m.size()                                           :O(1)
 * m.lower_bound :it=m.lower_bound(key)
 * m.upper_bound :it=m.lower_bound(key)
 * lower_bound   :it=lower_bound(m.begin(),m.end(),key)
 * upper_bound   :it=upper_bound(m.begin(),m.end(),key)
 * erase()       :s.erase(it)
 *               :s.erase(it1,it2)
 *               :s.erase(key)
 * loop          :for(auto it=m.begin();it!=s.end();it++)
 * 
 * it->first ,it->second ,
 */
 
 
 /*------------------------------------------Unorderd SET  :Elements in unsorted order(used hasing to store data)------------------------------------
 * declaration   :unordered_set<lli>s
 * insertion     :s.insert(data)                                     :O(1)
 * size          :s.size()                                           :O(1)
 * find          :auto it=s.find(data)//if it!=s.end ->data found    :O(1)     ||  worst case O(n)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 */

 /*Unordered MAP :Element r UNSORTED,unlike unordered set we insert (key and data)|| 
 * declaration   :unorderd_map<key_type,data_type> m
 * insert        :insert(make_pair(key,data))                        :O(1) 
 * find          :auto it=m.find(key) //if (it!=m.end)it->first=key  :O(1)
 * []            :m[key]++      //data=data+1 ,at that key           :O(1)
 * size          :m.size()                                           :O(1)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 */
 
 /* muti_set             :similar to set but have duplicate element
  * multi_set<data_type>ms
  * insert()               :ms.insert(data)         :O(log(n))
  * find()                 :auto it=ms.find(data)   :O(long(n))
  * size()                 :ms.size()               :O(1)
  */
  
  /* multimap              :similar to MAP but can have duplicate keys  :search O(logn):insert O(logn):delete O(logn)  
   * mulimap<key_type,data_type>mm
   * mm.insert(pair<key_type,data_type>(key,data))        :O(long(n))
   * multimap<key_type,data_type> mm2(mm.begin(),mm.end())  
   * find()                :it=mm.find(key)  //first it   :O(long(n))
   * mm.lower_bound(key)->second //data      mm.lower_bound(key)=it  1st elemet having the key  or mm.end()
   * mm.upper_bound(key)->second //data      mm.upper_bound(key)=it  1st element just after the key or mm.end()
   * mm.erase(key)         :erase all element of the key value
   * mm.erase(mm.begin(),mm.find(key))    :remove all having(key) less than the given key
   * mm.size()                                             :O(1)
   * for(auto it=mm.begin();it!=mm.end;it++)     :traversal
   */
