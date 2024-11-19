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
 
#include <iostream>#include <iostream>
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
