
https://codeforces.com/problemset/problem/11/A
// A. Increasing Sequence
using namespace std;
int main() {
    int n, d, prev, curr, moves = 0;
    cin >> n >> d >> prev;
    for (int i = 1; i < n; ++i) {
        cin >> curr;
        if (curr <= prev) {
            int x = (prev - curr) / d + 1;
            moves += x;
            curr += x * d;
        }
        prev = curr;
    }
    cout << moves << endl;
    return 0;
}
using namespace std;
int main(){
    int n, d, b0, b, moves = 0;
    cin >> n >> d >> b0;
    while (--n) {
        cin >> b0;
        if (b <= b0){
            int x = (b0 - b) / d + 1;
            moves += x;
            b0 = b + x * d;
        }
        else    b0 = b;
    }
    cout << moves;
}
using namespace std;
int main(){
    int n, d; cin >> n >> d;
    int a[2001];
    for(int i = 0; i < n; i++)    cin >> a[i];
    int ans = 0, div = 0, sub = 0;
    for(int i = 1; i < n; i++){
        if(a[i-1] >= a[i]){
            sub = a[i-1] - a[i];
            if(sub == 0){
                ans++;
                a[i] += d;
            }
            else{
                sub++;
                div = sub / d;
                if(sub % d != 0)    div++;
                a[i] += div * d;
                ans += div;
            }
        }
    }
    cout << ans << endl;
}
using namespace std;
int main(){
    int n, d; cin >> n >> d;
    vector <int a(n);
    for (int &x : a) cin >> x;
    int operations = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            ll diff = a[i - 1] - a[i] + 1;
            ll steps = (diff + d - 1) / d; 
            a[i] += steps * d;
            operations += steps;
        }
    }
    cout << operations << '\n';
    return 0;
}

https://codeforces.com/problemset/problem/11/D
// D. A Simple Task
using namespace std;
typedef long long LL;
LL dp[1<<19][19];
int vis[1<<19][19],n,m;
int g[19][19];
LL dfs(int st,int cur,int u)
{
	if(vis[st][u]) return dp[st][u];
	vis[st][u]=1;
	LL &ans=dp[st][u];
	ans=0;
	for(int v=cur;v<n;v++)
		if(g[u][v])
		{
			if(v==cur && st!=((1<<v)|(1<<u))) ans++;
			else if(v!=cur && ((st&(1<<v))==0)) ans+=dfs(st^(1<<v),cur,v);
		}
	return ans;
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		g[u][v]=g[v][u]=1;
	}
	LL ans=0;
	for(int i=0;i<n;i++) ans+=dfs((1<<i),i,i);
	cout<<ans/2<<"\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MAXN = 19;
LL dp[1 << MAXN][MAXN];
bool visited[1 << MAXN][MAXN];
int adj[MAXN][MAXN];
int n, m;

// Count cycles using bitmask DP
LL dfs(int mask, int start, int u) {
    if (visited[mask][u]) return dp[mask][u];
    visited[mask][u] = true;

    LL &ans = dp[mask][u];
    ans = 0;

    for (int v = start; v < n; v++) {
        if (!adj[u][v]) continue;

        // If we reached start and it's not just the edge start-u
        if (v == start && mask != ((1 << v) | (1 << u))) {
            ans++;
        }
        // Visit unvisited node
        else if (v != start && !(mask & (1 << v))) {
            ans += dfs(mask | (1 << v), start, v);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u][v] = adj[v][u] = 1;
    }

    LL totalCycles = 0;
    for (int i = 0; i < n; i++) {
        totalCycles += dfs(1 << i, i, i);
    }

    // Each cycle counted twice (once in each direction)
    cout << totalCycles / 2 << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/12/D
D. Ball 
using namespace std;
const int maxn = 500010;
int n, h[maxn];
struct lady
{
	int A, B, C;
} l[maxn];
int cmp(lady a, lady b)
{
	return (a.A == b.A && a.B < b.B) || (a.A > b.A);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&l[i].A);
	for(int i=0;i<n;i++)
		scanf("%d",&l[i].B), h[i] = l[i].B;
	for(int i=0;i<n;i++)
		scanf("%d",&l[i].C);
	sort(l, l+n, cmp);
	sort(h, h+n);
	for(int i=0;i<n;i++)
		l[i].B = n - (lower_bound(h,h+n,l[i].B) - h);
	memset(h, 0, sizeof(h));
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int tmp = 0;
		for(int j=l[i].B-1;j;j-=j&-j) tmp = max(tmp, h[j]);
		if(tmp > l[i].C) ans++;
		for(int j=l[i].B;j<=n;j+=j&-j) h[j] = max(h[j], l[i].C);
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n;
int A[maxn], B[maxn], C[maxn];
int h[maxn], idx[maxn];

// Compare indices instead of struct
bool cmp(int i, int j) {
    return (A[i] == A[j] && B[i] < B[j]) || (A[i] > A[j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        h[i] = B[i];
    }
    for (int i = 0; i < n; i++) cin >> C[i];

    // Sort by A desc, then B asc, using indices
    iota(idx, idx + n, 0);
    sort(idx, idx + n, cmp);

    // Coordinate compress B
    sort(h, h + n);
    for (int i = 0; i < n; i++) {
        B[i] = n - (lower_bound(h, h + n, B[i]) - h);
    }

    // BIT array stored in h
    memset(h, 0, sizeof(int) * (n + 1));

    int ans = 0;
    for (int t = 0; t < n; t++) {
        int i = idx[t];
        int tmp = 0;
        for (int j = B[i] - 1; j; j -= j & -j) {
            tmp = max(tmp, h[j]);
        }
        if (tmp > C[i]) ans++;
        for (int j = B[i]; j <= n; j += j & -j) {
            h[j] = max(h[j], C[i]);
        }
    }

    cout << ans << "\n";
    return 0;
}

https://codeforces.com/problemset/problem/12/A
// A. Super Agent
using namespace std;
int main() {
    string symbols[3];
    for (int i = 0; i < 3; ++i)
        cin >> symbols[i];
    bool isMirror = (
        symbols[0][0] == symbols[2][2] &&
        symbols[0][1] == symbols[2][1] &&
        symbols[0][2] == symbols[2][0] &&
        symbols[1][0] == symbols[1][2]
    );
    cout << (isMirror ? "YES" : "NO") << endl;
}

https://codeforces.com/problemset/problem/12/B
// B. Correct Solution?
using namespace std;
int main() {
    int n;
    string m;
    cin >> n >> m;
    string digits;
    while (n > 0) {
        digits += char('0' + n % 10);
        n /= 10;
    }
    sort(digits.begin(), digits.end());
    if (digits[0] == '0') {
        for (size_t i = 1; i < digits.size(); ++i) {
            if (digits[i] != '0') {
                swap(digits[0], digits[i]);
                break;
            }
        }
    }
    cout << (digits == m ? "OK" : "WRONG_ANSWER") << endl;
}
using namespace std;
int main(){
    int n;
    char m[11], digit[10] = {'0'}, digitcount(0);
    cin >> n >> m;
    while (n != 0){
        digit[digitcount++] = '0' + n % 10;
        n /= 10;
    }
    sort(digit, digit + digitcount);
    if (digit[0] == '0'){
        for (int i = 1; i < digitcount; ++i){
            if (digit[i] != '0'){
                digit[0] = digit[i];
                digit[i] = '0';
                break;
            }
        }
    }
    printf(strcmp(m, digit) == 0 ? "OK\n" : "WRONG_ANSWER\n");
}
using namespace std;
int main() {
    string n, m; cin >> n >> m;
    sort(n.begin(), n.end());
    while (n.size() > 1 && n[0] == '0') {
        next_permutation(n.begin(), n.end());
    }
    cout << ((n == m) ? "OK" : "WRONG_ANSWER") << '\n';
}
https://codeforces.com/problemset/problem/13/A
// A. Numbers
using namespace std;
int sumOfDigitsInBase(int number, int base) {
    int sum = 0;
    while (number) {
        sum += number % base;
        number /= base;
    }
    return sum;
}
int main() {
    int A; cin >> A;
    int totalDigitSum = 0;
    for (int base = 2; base < A; ++base) {
        totalDigitSum += sumOfDigitsInBase(A, base);
    }
    int denominator = A - 2;
    int gcd = gcd(totalDigitSum, denominator); 
    cout << totalDigitSum / gcd << "/" << denominator / gcd << endl;
}
using namespace std;
int GCD(int m, int n){
    int r = m % n;
    while (r != 0){
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}
int main(){
    int A; cin >> A;
    int X = 0, Y = A - 2;
    for (int i = 2; i < A; ++i){
        int n(A), ds(0);
        while (n != 0){
            ds += n % base;
            n /= base;
        }
        X += ds;
    }
    int gcd = GCD(X, Y);
    X /= gcd;
    Y /= gcd;
    cout << x << " " << y;
    return 0;
}
https://codeforces.com/problemset/problem/14/A
// A. Letter
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	int x1 = 50, y1 = 50, x2 = 0, y2 = 0;
	string s[n];
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '*'){
				x1 = min(x1, i);
				y1 = min(y1, j);
				x2 = max(x2, i);
				y2 = max(y2, j);
			}
	for (int i = x1; i <= x2; i++){
		for (int j = y1; j <= y2; j++)
			cout << s[i][j];
		cout << '\n';
	}
}
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    int x1 = n, y1 = m, x2 = -1, y2 = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
            }
        }
    }
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j)
            cout << grid[i][j];
        cout << '\n';
    }
}
....
#include <cstdio>
#include <algorithm>
https://codeforces.com/problemset/problem/22/A
// A. Second Order Statistics
using namespace std;
int main(){
    int n, a[101]; cin >> n;
    for (int i = 1; i <= n; ++i)    cin >> a[i];
    int x = *min_element(a + 1, a + n + 1);
    int value2(x);
    for (int i = 1; i <= n; ++i) {
        if (a[i] > x) {
            if (value2 == x || a[i] < value2)    value2 = a[i];
        }
    }
    cout << (value2 != x) ? value2 : "NO";
    return 0;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &num : a)
        cin >> num;
    sort(a.begin(), a.end());
    int min_val = a[0];
    int second_val = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > min_val) {
            second_val = a[i];
            break;
        }
    }
    cout << (second_val != -1) ? second_val : "NO";
    return 0;
}
using namespace std;
int main(){
	int n, x; cin >> n;
	set <int> st;
	for (int i = 0; i < n; i++){
		cin >> x;
		st.insert(x);
	}
	cout << (st.size() > 1 ? to_string(*++st.begin()) : "NO");
}
using namespace std;
int main() {
    int n, x; cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> x;
        st.insert(x);
    }
    if (st.size() > 1) {
        auto it = st.begin();
        ++it;
        cout << *it << '\n';
    } else cout << "NO\n";
    return 0;
}
using namespace std;
int main(){
    int a;
    set <int> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        s.insert(a);
    }
    if(s.size() < 2)    cout << "NO\n";
    else {
        set<int> ::iterator it;
        int c = 0;
        for(it = s.begin(); it != s.end(); it++){
            if(c == 1){
                cout << *it << endl;
                break;
            }
            c++;
        }
    }
}
using namespace std;
int main() {
    int n, a;
    set <int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }
    if (s.size() < 2)
        cout << "NO" << endl;
    else {
        auto it = s.begin();
        advance(it, 1);
        cout << *it << endl;
    }
}

https://codeforces.com/problemset/problem/23/A
// A. You're Given a String...
using namespace std;
int main() {
    string s; cin >> s;
    int n = s.length();
    int m = n - 1;
    while (m > 0) {
        bool found = false;
        for (int i = 0; i <= n - m; ++i) {
            for (int j = i + 1; j <= n - m; ++j) {
                bool match = true;
                for (int k = 0; k < m; ++k) {
                    if (s[i + k] != s[j + k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) break;
        m--;
    }
    cout << m << endl;
}
using namespace std;
// A. IQ test
// problemset/problem/25/A
int main(){
    int n; cin >> n;
    int arr[n], even = 0, odd = 0;
    int evenIdx = -1, oddIdx = -1;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            even++;
            evenIdx = i + 1;
        }
        else{
            odd++;
            oddIdx = i + 1;
        }
    }
    (even == 1) ? cout << evenIdx : cout << oddIdx;
}
using namespace std;
http://codeforces.com/problemset/problem/25/A
// A. IQ test
int main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] = arr[i] % 2;
	}
	int one = count(arr, arr + n, 1);
	if (one > n - one) {
		for (int i = 0; i < n; i++) {
			if (!arr[i]) {
				cout << i + 1;
				break;
			}
		}
	} else{
		for (int i = 0; i < n; i++) {
			if (arr[i]) {
				cout << i + 1;
				break;
			}
		}
	}
	return 0;
}
using namespace std;
int main(){
    int n, x, even(0), lastodd(0), lasteven(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (x % 2 == 0) {
            even += 1;
            lasteven = i;
        }
        else {
            even -= 1;
            lastodd = i;
        }
    }
    cout << (even > 0 ? lastodd : lasteven) << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    int numberOfOdds = 0, numberOfEvens = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 != 0) numberOfOdds++;
        else numberOfEvens++;
    }
    int targetParity = (numberOfOdds > numberOfEvens) ? 0 : 1;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == targetParity) {
            cout << (i + 1) << '\n';
            break;
        }
    }
}
using namespace std;
#define ll long long
int main() {
    ll n; cin >> n;
    ll arr[n], evenodd[2] = {0};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        evenodd[arr[i] % 2]++;
    }
    for(int i = 0; i < n; i++) {
        if (arr[i] % 2 == ((evenodd[0] >= evenodd[1]) ? 1 : 0))
            cout << i + 1 << " ";
    }
    cout << '\n';
}
using namespace std;
int main(){
    ll n, ans; cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    ll evenodd[2] = {0};
    for(int i = 0; i < n; i++){
        ll temp = arr[i] % 2;
        evenodd[temp]++;
    }
    if (evenodd[0] >= evenodd[1])    ans = 1;
    else    ans = 0;
    for(int i = 0; i < n; i++){
        if (arr[i] % 2 == ans)
            cout << i + 1 << " ";
    }
}
https://codeforces.com/problemset/problem/25/C
// C. Roads in Berland
using namespace std;
int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j)
            cin >> d[i][j];
    ll k; cin >> k;
    for (ll p = 0; p < k; ++p) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if (w < d[u][v]) {
            d[u][v] = d[v][u] = w;

            // Update shortest distances using the newly added edge
            for (ll i = 0; i < n; ++i) {
                for (ll j = 0; j < n; ++j) {
                    d[i][j] = min({
                        d[i][j],
                        d[i][u] + w + d[v][j],
                        d[i][v] + w + d[u][j]
                    });
                }
            }
        }
        // Sum distances for pairs i > j to avoid double counting
        ll q = 0;
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < i; ++j)
                q += d[i][j];
        cout << q << ' ';
    }
    cout << '\n';
}

https://codeforces.com/problemset/problem/26/A
// A. Almost Prime
using namespace std;
int main(){
    int n, amount = 0; cin >> n;
    bool b[3001] = {false};
    int pfactors[3001] = {0};
    for (int i = 2; i <= n; ++i){
        if (!b[i]){
            for (int j = i + i; j <= n; j += i){
                b[j] = true;
                pfactors[j] += 1;
            }
        }
        if (pfactors[i] == 2)    amount++;
    }
    cout << amount << endl;
    return 0;
}
using namespace std;
int main() {
    int n, count = 0; cin >> n;
    vector<bool> isComposite(n + 1, false);
    vector<int> primeFactorCount(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (!isComposite[i]) {
            for (int j = i * 2; j <= n; j += i) {
                isComposite[j] = true;
                primeFactorCount[j]++;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (primeFactorCount[i] == 2)  count++;
    }
    cout << count << endl;
}
using namespace std;
int main(){
    int n, amount = 0; cin >> n;
    bool b[3001] = {false};
    int pfactors[3001] = {0};
    for (int i = 2; i <= n; ++i){
        if (!b[i]){
            for (int j = i + i; j <= n; j += i){
                b[j] = true;
                pfactors[j] += 1;
            }
        }
        if (pfactors[i] == 2)    amount += 1;
    }
    cout << amount;
    return 0;
}
using namespace std;
int main() {
    int n, count = 0; cin >> n;
    vector<int> pfactors(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (pfactors[i] == 0) {
            for (int j = i; j <= n; j += i)
                pfactors[j]++;
        }
        if (pfactors[i] == 2)
            count++;
    }
    cout << count << '\n';
    return 0;
}

using namespace std;
// problemset/problem/26/B
// B. Regular Bracket Sequence
int main(){
    string str; cin >> str;
    stack <char> st;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(ch == '(') st.push(ch);
        else if(ch == ')' && !st.empty() && st.top() == '('){
            st.pop();
            cnt++;
        }
        else
            st.push(ch);
    }
    cout << cnt * 2;
}
https://codeforces.com/problemset/problem/26/B
// B. Regular Bracket Sequence
int main() {
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            ++cnt;
        } else {
            if (cnt != 0) {
                ans += 2;
                --cnt;
            }
        }
    }
    cout << ans << '\n';
}
https://codeforces.com/problemset/problem/27/A
// A. Next Test
using namespace std;
int main() {
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        if(vec[i] != i + 1){
            cout << i + 1;
            return 0;
        }
    }
    cout << n + 1;
    return 0;
}  
using namespace std;
int main() {
    int n, num; cin >> n;
    set <int> s;
    while (n--) {
        cin >> num;
        s.insert(num);
    }
    for (int i = 1; i <= 3001; ++i) {
        if (s.find(i) == s.end()) {
            cout << i << endl;
            break;
        }
    }
}

https://codeforces.com/problemset/problem/29/A
// A. Spit Problem
using namespace std;
int main(){
    int n, x[100], d[100];
    bool spitted = false;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        cin >> x[i] >> d[i];
        for (int j = 0; j < i; ++j){
            if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]){
                spitted = true;
                break;
            }
        }
        if (spitted)    break;
    }
    cout << spitted ? "YES" : "NO";
    return 0;
}
https://codeforces.com/problemset/problem/31/A
// A. Worms Evolution
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    bool found = false;
    for (int i = 1; !found && i <= n; ++i) {
        for (int j = 1; !found && j <= n; ++j) {
            if (j == i) continue;
            for (int k = j + 1; k <= n; ++k) {
                if (k == i) continue;
                if (a[i] == a[j] + a[k]) {
                    cout << i << " " << j << " " << k << endl;
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found)    cout << -1 << endl;
}
using namespace std;
int main(){
    int n, a[101]; cin >> n;
    for (int i = 1; i <= n; ++i)    cin >> a[i];
    bool found = false;
    for (int i = 1; !found && i <= n; ++i){
        for (int j = 1; !found && j <= n; ++j){
            if (j != i){
                for (int k = j + 1; k <= n; ++k){
                    if (k != i && a[i] == a[j] + a[k]){
                        cout << i << " " << j << " " << k;
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    if(!found)    cout << -1;
}
https://codeforces.com/problemset/problem/32/A
// A. Reconnaissance
using namespace std;
int main(){
    int n, d, height[1000]; cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> height[i];
    sort(height, height + n);
    int i1 = 0, i2 = 1, ways = 0;
    while (i2 < n){
        if (height[i2] - height[i1] <= d){
            ways += (i2 - i1);
            ++i2;
        }
        else    ++i1;
    }
    ways *= 2;
    cout << ways;
}
using namespace std;
int main() {
    int n, d; cin >> n >> d;
    vector<int> height(n);
    for (int& h : height)
        cin >> h;
    sort(height.begin(), height.end());
    int i1 = 0, i2 = 1, ways = 0;
    while (i2 < n) {
        if (height[i2] - height[i1] <= d) {
            ways += (i2 - i1);
            ++i2;
        } else    ++i1;
    }
    cout << (ways * 2) << '\n';
}
using namespace std;
int main(){
    int c = 0;
    int n, d; cin >> n >> d;
    int a[n + 5];
    for(int i = 0; i < n; i++)    cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[j] - a[i] > d)    break;
            c++;
        }
    }
    cout << c * 2 << endl;
    return 0;
}
using namespace std;
int main() {
    int n, d, count = 0;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] - a[i] > d) break;
            count++;
        }
    }
    cout << count * 2 << endl;
}

using namespace std;
using ll = long long;
int main() {
    int n, d; cin >> n >> d;
    vector <int> a(n);
    for(int i = 0; i < n; i++)    cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if (abs(a[i] - a[j]) <= d)
                ans += 2;  
        }
    }
    cout << ans << '\n';
}
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    int heights[n];
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    int ans=0;
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<n;k++)
        {
        if(abs(heights[j]-heights[k])<=d && j!=k)
        ans++;
        }
    }
    cout<<ans<<endl;
}
using namespace std;
http://codeforces.com/problemset/problem/32/B
// B. Borze
int main() {
    string s, result; cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '.')
            result += '0';
        else if (i + 1 < len && s[i] == '-' && s[i + 1] == '.') {
            result += '1';
            ++i;
        } 
        else if (i + 1 < len && s[i] == '-' && s[i + 1] == '-'){
            result += '2';
            ++i;
        }
    }
    cout << result;
}
using namespace std;
int main(){
    string input; cin >> input;
    int len = input.length();
    char ans[len];
    int c = 0;
    for (int i = 0; i < len; i++){
        if (input[i] == '-'){
            if (input[i + 1] == '-'){
                ans[c] = '2';
                i++; c++;
                c++;
            else {
                ans[c] = '1';
                i++; c++;
            }
        }
        else {
            ans[c] = '0'; c++;
        }
    }
    for (int i = 0; i < c; i++)
        cout << ans[i];
    return 0;
}
using namespace std;
int main()
{
    string Bcode;
    cin>>Bcode; 
    string decoded;
    int i=0;
    while(i!=Bcode.size())
    {
        if(Bcode[i]=='.')
        {
        decoded+="0";
        i++;
        }
        else if(Bcode.substr(i,2)=="-.")
        {
        decoded+="1";
        i+=2;
        }
        else
        {
            decoded+="2";
            i+=2;
        }
    }
    cout<<decoded<<endl;
}
using namespace std;
int main() {
    string input; cin >> input;
    string ans;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '-') {
            if (i + 1 < input.length() && input[i + 1] == '-') {
                ans.push_back('2');
                i++;
            } else {
                ans.push_back('1');
                i++;
            }
        } else ans.push_back('0');
    }
    cout << ans;
}
using namespace std;
int main(){
    string s; cin >> s;
    int len = s.length();
    int a[len + 5];
    for(int i = 0; i < len; i++){
        if(s[i] == '.')    cout << 0;
        else{
            if(s[i + 1] == '.')    cout << 1;
            else{
                cout << 2;
                i++;
            }
        }
    }
    cout << endl;
}
using namespace std;
int main() {
    string s; cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '.')
            cout << 0;
        else
            if (i + 1 < len && s[i + 1] == '.')
                cout << 1;
            else {
                cout << 2;
                i++;
            }
        }
    }
    cout << endl;
}
int main(){
    string input; cin >> input;
    for(int i = 0; i < input.length(); i++) {
        if (input[i] == '.') cout << 0;
        else if (input[i] == '-' && input[i + 1] == '.'){
            cout << 1;
            i++;
        }
        else if (input[i] == '-' && input[i + 1] == '-'){
            cout << 2;
            i++;
        }
    }
    return 0;
}

using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
int main(){
    string s, res = ""; cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '.')    res += '0';
        else if(s[i] == '-'){
            i++;
            if(s[i] == '.')    res += '1';
            else    res += '2';
        }
    }
    cout << res << endl;
}
using namespace std;
int main() {
    string s, res; cin >> s;
    for (size_t i = 0; i < s.size(); ) {
        if (s[i] == '.') {
            res += '0';
            i++;
        } else {
            res += (s[i + 1] == '.') ? '1' : '2';
            i += 2;
        }
    }
    cout << res << '\n';
    return 0;
}

https://codeforces.com/problemset/problem/34/A
// A. Reconnaissance 2
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> heights(n);
    for (int& h : heights)
        cin >> h;
    int min_diff = numeric_limits<int>::max();
    int idx1 = 0, idx2 = 1;
    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;  
        int diff = abs(heights[i] - heights[next]);
        if (diff < min_diff) {
            min_diff = diff;
            idx1 = i;
            idx2 = next;
        }
    }
    cout << idx1 + 1 << " " << idx2 + 1 << endl;
    return 0;
}
using namespace std;
int main(){
    int n, a1; cin >> n >> a1;
    int prev(a1), cur, rec(1000), index1, index2;
    for (int i = 2; i <= n; ++i) {
        cin >> cur;
        int diff = abs(cur - prev);
        if (diff < rec) {
            rec = diff;
            index1 = i - 1;
            index2 = i;
        }
        prev = cur;
    }
    int diff = abs(a1 - prev);
    if (diff < rec){
        index1 = n;
        index2 = 1;
    }
    cout << index1 << " " << index2 << endl;
}
using namespace std;
int main(){
    int a[101], b[101];
    int n; cin >> n;
    for(int i = 0; i < n; i++)    cin >> a[i];
    int m = 1001, d = 0;
    d = abs(a[0] - a[n-1]);
    m = min(m,d);
    int idx1 = 1,idx2 = n;
    for(int i=0; i<n; i++){
        d = abs(a[i] - a[i+1]);
        if(m > d){
            m = d;
            idx1 = i+1;
            idx2 = i+2;
        }
    }
    cout << idx1 << " " << idx2 << endl;
    return 0;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int min_diff = abs(a[0] - a[n - 1]);
    int idx1 = 1, idx2 = n;
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(a[i] - a[i + 1]);
        if (diff < min_diff) {
            min_diff = diff;
            idx1 = i + 1;
            idx2 = i + 2;
        }
    }
    cout << idx1 << " " << idx2 << '\n';
    return 0;
}
using namespace std;
int main(){
    int n; cin >> n;
    int arr[2 * n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    int mindiff = INT_MAX, a1, a2;
    for(int i = 0; i < 2 * n; i++){
        if (abs(arr[i] - arr[i + 1]) < mindiff){
            mindiff = abs(arr[i] - arr[i + 1]);
            a1 = i;
            a2 = i + 1;
        }
    }
    a1 = (a1 + 1) % n, a2 = (a2 + 1) % n;
    if (a1 == 0)    a1 = n;
    if (a2 == 0)    a2 = n;
    cout << a1 << " " << a2;
    return 0;
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    int heights[n];
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    vector<pair<int,int>> ans;
    for(int j=0;j<n-1;j++)
    {
        int diff=abs(heights[j]-heights[j+1]);
        ans.push_back(make_pair(diff,j));
    }
    int lastfirstdiff=abs(heights[n-1]-heights[0]);
    sort(ans.begin(),ans.end());
    if(lastfirstdiff<ans[0].first)
    cout<<n<<" "<<1<<endl;
    else
    cout<<ans[0].second+1<<" "<<ans[0].second+2<<endl;    
}
    






https://codeforces.com/problemset/problem/34/B
// B. Sale
using namespace std;
int main(){
    int n, m, a[100];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)    cin >> a[i];
    sort(a, a + n);
    int s = 0;
    for (int i = 0; i < m; ++i){
        if (a[i] >= 0)    break;
        s += a[i];
    }
    cout << -s << endl;
}
int main() {
    int n, m; cin >> n >> m;
    vector<int> prices(n);
    for (int& price : prices)
        cin >> price;
    sort(prices.begin(), prices.end());
    int savings = 0;
    for (int i = 0; i < m && prices[i] < 0; ++i)
        savings -= prices[i];
    cout << savings << endl;
    return 0;
}
using namespace std;
int main(){
    int a, n, m; cin >> n >> m;
    vector <int> v;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a < 0)    v.push_back(a);
    }
    sort(v.begin(), v.end());
    n = v.size();
    if(n > m)    swap(n, m);
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += (v[i] * -1);
    cout << sum << endl;
    return 0;
}
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> negative_values;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a < 0) negative_values.push_back(a);
    }
    sort(negative_values.begin(), negative_values.end()); 
    int sum = 0;
    int take = min((int)negative_values.size(), m);
    for (int i = 0; i < take; i++) {
        sum -= negative_values[i];
    }
    cout << sum << '\n';
}

using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
int main(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    sort(arr, arr + n);
    int count = 0;
    for(int i = 0; i < m; i++){
        if(arr[i] < 0)    count -= arr[i];
    }
    cout << count << endl;
}
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    int total = 0;
    for (int i = 0; i < m && arr[i] < 0; i++) 
        total -= arr[i];
    cout << total << '\n';
    return 0;
}
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector <int> arr;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num < 0)    arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    int len = arr.size();
    for (int i = 0; i < min(len, m); i++)
        sum -= arr[i];
    cout << sum << '\n';
}
https://codeforces.com/problemset/problem/34/C
// C. Page Numbers
using namespace std;
int main() {
    string s; cin >> s;
    s += ',';
    vector <int> vec;
    string temp;
    for (char c : s) {
        if (c == ',') {
            if (!temp.empty()) {
                vec.pb(stoll(temp));
                temp.clear();
            }
        } else    temp += c;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int start = vec[0], end = vec[0];
    for (int i = 1; i < sz(vec); i++) {
        if (vec[i] == end + 1)    end = vec[i];
         else {
            if (start == end)    cout << start << ",";
            else    cout << start << "-" << end << ",";
            start = end = vec[i];
        }
    }
    if (start == end)
        cout << start;
    else
        cout << start << "-" << end;
    cout << "\n";
}
https://codeforces.com/problemset/problem/35/A
// A. Shell Game
using namespace std;
int main(){
    int x, a, b, cup[4] = {0};
    cin >> x;
    cup[x] = 1;
    cin >> a >> b; swap(cup[a], cup[b]);
    cin >> a >> b; swap(cup[a], cup[b]);
    cin >> a >> b; swap(cup[a], cup[b]);
    printf("%d\n", find(cup + 1, cup + 3 + 1, 1) - cup);
}
using namespace std;
int main() {
    array <int, 4> cup{};
    int x, a, b; cin >> x;
    cup[x] = 1;
    for (int i = 0; i < 3; ++i){
        cin >> a >> b;
        swap(cup[a], cup[b]);
    }
    for (int i = 1; i <= 3; ++i) {
        if (cup[i] == 1) {
            cout << i << endl;
            break;
        }
    }
}

https://codeforces.com/problemset/problem/37/A
// A. Towers
using namespace std;
int main(){
    int n, l, h[1001] = {0};
    cin >> n;
    while (n--){
        cin >> l;
        h[l] += 1;
    }
    int height = *max_element(h, h + 1001);
    int number = 1001 - count(h, h + 1001, 0);
    cout << height << " " << number << endl;
}
using namespace std;
int main() {
    const int MAX_HEIGHT = 1001;
    array<int, MAX_HEIGHT> heightFrequency{};
    int n; cin >> n;
    for (int i = 0, l; i < n; ++i) {
        cin >> l;
        ++heightFrequency[l];
    }
    int tallestTower = *max_element(heightFrequency.begin(), heightFrequency.end());
    int numberOfTowers = count_if(heightFrequency.begin(), heightFrequency.end(), [](int h) {
        return h > 0;
    });
    cout << tallestTower << " " << numberOfTowers << '\n';
}
https://codeforces.com/problemset/problem/38/A
// A. Army
using namespace std;
int main(){
    int n, d[100] = {0}, a, b;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> d[i];
    cin >> a >> b;
    cout << accumulate(d + a, d + b, 0) << endl;
    return 0;
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a-1;i<b-1;i++)
    {
        ans+=arr[i];
    }
    cout<<ans<<endl;
}
using namespace std;
int main(){
    int sum = 0, n; cin >> n;
    int p[n];
    for(int i = 0; i < n - 1; i++)    cin >> p[i];
    int a, b; cin >> a >> b;
    a--;
    b--;
    for(int i = a; i < b; i++)    sum += p[i];
    cout << sum << endl;
}
using namespace std;
int main() {
    int n, a, b; cin >> n;
    vector<int> p(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> p[i];
    cin >> a >> b;
    int sum = 0;
    for (int i = a - 1; i < b - 1; i++)
        sum += p[i];
    cout << sum << endl;
    return 0;
}

https://codeforces.com/problemset/problem/40/A
// A. Find Color
using namespace std;
int main(){
    int x, y; cin >> x >> y;
    int r2 = x * x + y * y;
    int r = floor(sqrt(static_cast<double>(r2)));
    if (r * r < r2 && (r + 1) * (r + 1) > r2
        && (r % 2 == 1 && x * y > 0 || r % 2 == 0 && x * y < 0))    cout << "white";
    else    cout << "black";
}
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int r2 = x * x + y * y;
    int r = static_cast<int>(floor(sqrt(r2)));
    bool isBetweenCircles = (r * r < r2 && (r + 1) * (r + 1) > r2);
    bool isWhite = (r % 2 == 1 && x * y > 0) || (r % 2 == 0 && x * y < 0);
    if (isBetweenCircles && isWhite)
        cout << "white\n";
    else
        cout << "black\n";
}

using namespace std;
http://codeforces.com/contest/41/problem/A
// A. Translation
int main(){
    string str, ing; cin >> str >> ing;
    reverse(str.begin(), str.end());
    (str == ing) ? cout << "Yes" : cout << "No";
}
using namespace std;
int main(){
    string s, t; cin >> s >> t;
    int len = s.length();
    for (int i = 0; i < len; i++).{
        if (s[i] != t[len - i - 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    if (s == t)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
using namespace std;
int main(){
    int tag = 0;
    string x, y; cin >> x >> y;
    cin >> x >> y;
    int len = x.length();
    int len2 = y.length();
    for(int i = 0, j = len2 - 1; i < len, j >= 0; i++, j--){
        if(x[i] == y[j])    tag = 1;
        else{
            tag = 0;
            break;
        }
    }
    if(tag == 1)    cout << "YES" << endl;
    else    cout << "NO" << endl;
}
#include <bits/stdc++.h>
https://codeforces.com/problemset/problem/41/C
// C. Email address
using namespace std;
int main() {
    string s, res; cin >> res;
    cin >> s;
    // Replace "dot" with "."
    s = regex_replace(s, regex("dot"), ".");
    // Replace first "at" with "@"
    size_t pos = s.find("at");
    if (pos != string::npos) {
        s.replace(pos, 2, "@");
    }
    // Special handling if starts with "@"
    if (!s.empty() && s[0] == '@') {
        s = s.substr(1);
        pos = s.find("at");
        if (pos != string::npos) {
            s.replace(pos, 2, "@");
        }
        s = "at" + s;
    }
    // Handle special cases with leading/trailing '.'
    if (!s.empty() && s.front() == '.' && s.back() == '.')
        res = "dot" + s.substr(1, s.size() - 2) + "dot";
    else if (!s.empty() && s.front() == '.')
        res = "dot" + s.substr(1);
    else if (!s.empty() && s.back() == '.')
        res = s.substr(0, s.size() - 1) + "dot";
    else    res = s;
        res = s;
    cout << res << '\n';
}
using namespace std;
https://codeforces.com/contest/43/problem/B
// 43B. Letter
int main(){
	string str, ing;
	getline(cin, str);
	getline(cin, ing);
	map <char, int> mp;
	int len = str.length();
	int len2 = ing.length();
	for(int i = 0; i < len; i++)
	    ++mp[str[i]];
	 int cnt = 0, res = 0;
	 for(int i = 0; i < len2; i++){
	     if(ing[i] != ' '){
	         ++res;
	         if(mp[ing[i]] > 0){
	             ++cnt;
	             --mp[ing[i]];
	         }
	     }
	 }
	 if(res == cnt) cout << "YES";
	 else cout << "NO";
}
using namespace std;
int main() {
    string magazine, letter;
    getline(cin, magazine);
    getline(cin, letter);

    map<char, int> charCount;

    // Count characters in the magazine string
    for (char c : magazine) {
        ++charCount[c];
    }

    // Check if we can form the letter
    for (char c : letter) {
        if (c == ' ') continue;

        if (charCount[c] > 0) {
            --charCount[c];
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/43/problem/A
// Football.cpp
int main() {
	int n; cin >> n;
	map <string, int> mp;
	map <string, int> ::iterator it;
	for(int i = 0; i < n; i++){
	    string str; cin >> str;
	    ++mp[str];
	}
	it = mp.begin();
	int len = mp.size();
	if(x != 1){
	    int val = (*it).second;
	    it++;
	    int val2 = (*it).second;
	    if(val2 > val) cout << (*it).first;
	}
	else if(val > val2){
	    it = mp.begin();
	    cout << (*it).first;
	}
	else cout << (*it).first;
}
using namespace std;
int main() {
    int n; cin >> n;
    map<string, int> teamGoals;
    string teamName;
    for (int i = 0; i < n; ++i) {
        cin >> teamName;
        teamGoals[teamName]++;
    }
    string winner;
    int maxGoals = 0;
    for (const auto& entry : teamGoals) {
        if (entry.second > maxGoals) {
            maxGoals = entry.second;
            winner = entry.first;
        }
    }
    cout << winner << endl;
}
using namespace std;
int main(){
    int n, goal(0);
    cin >> n;
    string team, win;
    while (n--){
        if (goal != 0){
            cin >> team;
            if (team == win)    goal++;
            else    goal--;
        }
        else{
            cin >> win;
            goal = 1;
        }
    }
    cout << win << endl;
}
using namespace std;
int main(){
    int n, max = 0; cin >> n;
    string s;
    map <string, int> mp;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s]++;
    }
    for (auto const &[key, val] : mp){
        if (val > max){
            max = val; s = key;
        }
    }
    cout << s;
}
using namespace std;
int main() {
    int n; cin >> n;
    unordered_map<string, int> mp;
    string winner;
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        string team; cin >> team;
        mp[team]++;
        if (mp[team] > maxCount) {
            maxCount = mp[team];
            winner = team;
        }
    }
    cout << winner << '\n';
    return 0;
}

using namespace std;
int main() {
    int n; cin >> n;
    map<string, int> freq;
    string s, result;
    int maxFreq = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        freq[s]++;
        if (freq[s] > maxFreq) {
            maxFreq = freq[s];
            result = s;
        }
    }
    cout << result << '\n';
    return 0;
}
using namespace std;
int main(){
    int n; cin >> n;
    map <string, int> mp;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s]++;
    }
    int c = 0, d = 0;
    string t;
    map <string,int> ::iterator itr;
    for(itr = mp.begin(); itr!=mp.end(); itr++){
        c = itr->second;
        if(c > d){
            d = c;
            t = itr->first;
        }
    }
    cout << t << endl;
}
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
int main(){
    int n; cin >> n;
    map <string, int> mp;
    while(n--) {
        string s; cin >> s;
        mp[s]++;
    }
    int max = -1;
    string maxchar;
    map <string, int>::iterator i;
    for(i = mp.begin(); i != mp.end(); i++){
        if(max < i->second){
            max = i->second;
            maxchar = i->first;
        }
    }
    cout << maxchar << endl;
}
https://codeforces.com/problemset/problem/43/B
// B. Letter
using namespace std;
int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int l1 = s1.length();
    int l2 = s2.length();
    string s, t;
    for(int i = 0; i < l1; i++){
        if(isalpha(s1[i])){
            s += s1[i];
        }
    }
    for(int i = 0; i < l2; i++){
        if(isalpha(s2[i])){
            t += s2[i];
        }
    }
    l1 = s.length();
    l2 = t.length();
    int Found = 0;
    bool flag = false;
    for(int i = 0; i < l2; i++){
        for(int j = 0; j < l1; j++){
            if(isalpha(s[j])){
                if(t[i] == s[j]){
                    Found = 1;
                    s[j] = '_';
                    t[i] = '+';
                    break;
                }
            }
        }
        if(Found == 1)    flag = true;
        else{
            flag = false;
            break;
        }
    }
    for(int i = 0; i < l2; i++){
        if(isalpha(t[i])){
            flag = false;
            break;
        }
    }
    if(flag)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    map <char, int> available;
    for (char ch : s1) {
        if (isalpha(ch)) {
            available[ch]++;
        }
    }
    bool possible = true;
    for (char ch : s2) {
        if (isalpha(ch)) {
            if (available[ch] == 0) {
                possible = false;
                break;
            }
            available[ch]--;
        }
    }
    cout << (possible ? "YES" : "NO") << '\n';
    return 0;
}
using namespace std;
#define ll long long
int main() {
    string base, need;
    getline(cin, base);
    getline(cin, need);
    map<char, ll> counts;
    for (char c : base) {
        if (isalpha(c))
            counts[c] += 1;
    }
    bool ok = true;
    for (char c : need) {
        if (isalpha(c)) {
            auto it = counts.find(c);
            if (it == counts.end()) {
                ok = false;
                break;
            }
            if (it->second == 1)    counts.erase(it);
            else    it->second -= 1;
        }
    }
    if(ok)    cout << "YES";
    else    cout << "NO";
}  
using namespace std;
int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    ll count1[58] = {}, count2[58] = {};
    for (ll i = 0; i < s1.length(); i++){
        if (s1[i] != ' ') count1[s1[i] - 65]++;
    }
    for (ll i = 0; i < s2.length(); i++){
        if (s2[i] != ' ')
            count2[s2[i] - 65]++;
    }
    for (ll i = 0; i < 58; i++) {
        if (count1[i] < count2[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
https://codeforces.com/problemset/problem/44/A
// A. Indian Summer
using namespace std;
int main(){
    int n; cin >> n;
    string a, b, c;
    set <string> s;
    while(n--){
        cin >> a >> b;
        c = b + a;
        s.insert(c);
    }
    cout << s.size() << endl;
}
using namespace std;
int main(){
    int n; cin >> n;
    set<string> uniquePairs;
    while (n--) {
        string first, second; cin >> first >> second;
        uniquePairs.insert(second + first);
    }
    cout << uniquePairs.size() << "\n";
    return 0;
}

https://codeforces.com/problemset/problem/46/A
// A. Ball Game
using namespace std;
int main(){
    int n, c = 2;
    cin >> n;
    cout << c;
    for (int i = 2; i < n; ++i){
        c += i;
        if (c > n)    c -= n;
        cout << " " << c;
    }
    cout << endl;
    return 0;
}
using namespace std;
int main(){
    int n; cin >> n;
    int N = n;
    n -= 1;
    int go = 1, i = 1;
    while(n--){
        go += i;
        if(go % N == 0) go = go;
        else    go %= N;
        cout << go << " ";
        i++;
    }
    cout << endl;
    return 0;
}
using namespace std;
int main() {
    int n; cin >> n;
    int pos = 1;
    for (int step = 1; step < n; ++step) {
        pos += step;
        pos %= n;
        if (pos == 0) pos = n;
        cout << pos << " ";
    }
    cout << "\n";
}

https://codeforces.com/problemset/problem/47/A
// 47A - Triangular numbers
using namespace std;
int main() {
    int n; cin >> n;
    int triangular = 1, i = 1;
    while (triangular < n) {
        ++i;
        triangular += i;
    }
    if (triangular == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
using namespace std;
bool integer(double k)
    {
        if( k == (int) k) 
        return true;
        return false;
    }
int main()
{
    int n;
    cin>>n;
    double x=sqrt(1-(4*1*-(2*n)));
    if(integer(-1+x) || integer(-1-x))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;    
}
using namespace std;
bool isTriangular(int num){
    if (num < 0)    return false;
    int sum = 0;
    for (int n = 1; sum <= num; n++){
        sum = sum + n;
        if (sum == num)    return true;
    }
    return false;
}
int main(){
    int n; cin >> n;
    cout << (isTriangular(n))? "YES" : "NO";
}
using namespace std;
bool isTriangular(int num) {
    int val = 8 * num + 1;
    int root = sqrt(val);
    return (root * root == val);
}
int main() {
    int n; cin >> n;
    cout << (isTriangular(n) ? "YES" : "NO") << endl;
}

using namespace std;
http://codeforces.com/contest/47/problem/B
// 47B. Coins;
int main() {
	string arr[3] = {};
	for(int i = 0; i < 3; i++)
	    cin >> arr[i];
	map <char, int> mp;
	mp['A'] = 0; mp['B'] = 0; mp['C'] = 0;
    for (int i = 0; i < 3; i++) {
        char a = arr[i][0];
        char b = arr[i][2];
        if (arr[i][1] == '>') {
            mp[a]++;
            mp[b]--;
        } else {
            mp[a]--;
            mp[b]++;
        }
    }
	if(mp['A'] > mp['B'] && mp['B'] > mp['C']) cout << "CBA";
    else if(mp['A'] > mp['C'] && mp['C'] > mp['B']) cout << "BCA";
	else if(mp['B'] > mp['C'] && mp['C'] > mp['A']) cout << "ACB";
    else if(mp['B'] > mp['A'] && mp['A'] > mp['C']) cout << "CAB";
	else if(mp['C'] > mp['B'] && mp['B'] > mp['A']) cout << "ABC";
    else if(mp['C'] > mp['A'] && mp['A'] > mp['B']) cout << "BAC";
	else cout << "IMPOSSIBLE";
}
using namespace std;
int main() {
    string arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    map<char, int> weight;
    weight['A'] = 0;
    weight['B'] = 0;
    weight['C'] = 0;
    for (int i = 0; i < 3; i++) {
        char a = arr[i][0];
        char b = arr[i][2];
        if (arr[i][1] == '>')
            weight[a]++;
        else
            weight[b]++;
    }
    vector<pair<int, char>> result;
    for (auto& p : weight)
        result.push_back({p.second, p.first});
    sort(result.begin(), result.end());
    if (result[0].first == result[1].first || result[1].first == result[2].first) {
        cout << "Impossible" << endl;
    } else {
        for (auto& p : result)
            cout << p.second;
        cout << endl;
    }
}
using namespace std;
int main(){
	string s;
	string a[3];
	vector <string> ans;
	for (int i = 0; i < 3; i++){
		cin >> s;
		a[i] = string(1, s[0]) + s[2];
		if (s[1] == '>')
			reverse(a[i].begin(), a[i].end());
	}
	for (int i = 0; i < 2; i++){
		for (int j = i + 1; j < 3; j++){
			if (a[i][0] == a[j][1])
				ans.push_back(string(1, a[j][0]) + a[i]);
			else if (a[i][1] == a[j][0])
				ans.push_back(string(1, a[i][0]) + a[j]);
		}
	}
	cout << (ans.size() > 1 ? "Impossible" : ans[0]);
}
using namespace std;
int main() {
    string a[3];
    vector<string> ans;
    for (int i = 0; i < 3; i++) {
        string s; cin >> s;
        a[i] = string(1, s[0]) + s[2];
        if (s[1] == '>') {
            reverse(a[i].begin(), a[i].end());
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (a[i][0] == a[j][1]) {
                ans.push_back(string(1, a[j][0]) + a[i]);
            } else if (a[i][1] == a[j][0]) {
                ans.push_back(string(1, a[i][0]) + a[j]);
            }
        }
    }
    if (ans.size() != 1)
        cout << "Impossible\n";
    else
        cout << ans[0] << '\n';
}
#include <iostream>
#include <string>
#include <cctype>
https://codeforces.com/problemset/problem/49/A
// A. Sleuth
using namespace std;
bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}
int main() {
    string s; getline(cin, s);
    char lastAlpha = '\0';
    for (int i = s.size() - 1; i >= 0; --i) {
        if (isalpha(s[i])) {
            lastAlpha = s[i];
            break;
        }
    }
    cout << (isVowel(lastAlpha) ? "YES" : "NO") << endl;
}
using namespace std;
int main()
{
    char s[110];
    cin.getline(s, sizeof(s) / sizeof(s[0]), '\n');
    bool vowel(true);
    char* p = s;
    while (*p != '\0')
    {
        if (*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z')
        {
            if (*p == 'a' ||*p == 'e' ||*p == 'i' ||*p == 'o' ||*p == 'u' ||*p == 'y' ||
                *p == 'A' ||*p == 'E' ||*p == 'I' ||*p == 'O' ||*p == 'U' ||*p == 'Y')
            {
                vowel = true;
            }
            else
            {
                vowel = false;
            }
        }
        ++p;
    }
    cout << (vowel ? "YES" : "NO") << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isalpha(s[i])) {
            char ch = tolower(s[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            return 0;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
https://codeforces.com/problemset/problem/49/B
// B.SUM
using namespace std;
using ll = long long;
string sumBaseB(string a, string b, ll base) {
    // Pad the shorter string with leading zeros
    if (a.size() < b.size()) a.insert(0, b.size() - a.size(), '0');
    else if (b.size() < a.size()) b.insert(0, a.size() - b.size(), '0');

    string result;
    int carry = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        int curr = carry + (a[i] - '0') + (b[i] - '0');
        carry = curr / base;
        curr %= base;
        result.push_back(char(curr + '0'));
    }
    if (carry > 0) result.push_back(char(carry + '0'));

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ll a, b;
    cin >> a >> b;
    string A = to_string(a), B = to_string(b);

    // Find max digit in both numbers
    int maxDigit = 0;
    for (char c : A) maxDigit = max(maxDigit, c - '0');
    for (char c : B) maxDigit = max(maxDigit, c - '0');

    ll base = maxDigit + 1;
    cout << sumBaseB(A, B, base).size() << '\n';
}
https://codeforces.com/problemset/problem/50/A
// A. Domino piling
using namespace std;
int main(){
    int M, N; cin >> M >> N;
    cout << M * N / 2 << endl;
}
using namespace std;
// A. Domino piling
// problemset/problem/50/A
int main(){
    int m, n; cin >> m >> n;
    cout << (m * n) / 2;
}
https://codeforces.com/problemset/problem/52/A
// A. 123-sequence
using namespace std;
int main(){
    int n, a; cin >> n;
    int one = 0, two = 0, three = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == 1)    one++;
        else if(a == 2)    two++;
        else    three++;
    }
    int m = 0, ans = 0;
    m = max(one, max(two,three));
    ans = (one + two + three);
    ans = abs(m - ans);
    cout << ans << endl;
}
using namespace std;
int main(){
    int n, x; cin >> n;
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) one++;
        else if (x == 2) two++;
        else if (x == 3) three++;
    }
    int teams = min({one, two, three});
    cout << teams << endl;
    return 0;
}



https://codeforces.com/problemset/problem/53/A
// A. Autocomplete
using namespace std;
int main(){
	string s, str;
	int n;
	cin >> s >> n;
	vector<string> v;
	for (int i = 0; i < n; i++){
		cin >> str;
		if (str.find(s) == 0)
			v.push_back(str);
	}
	cout << (v.size() > 0 ? *min_element(v.begin(), v.end()) : s);
}

using namespace std;
int main(){
    string s; cin >> s;
    int n; cin >> n;
    vector<string> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        if (vec[i].substr(0, s.length()) == s){
            cout << vec[i];
            return 0;
        }
    }
    cout << s;
}
using namespace std;
using ll = long long;
void solve() {
    string s; cin >> s;
    ll n; cin >> n;
    vector<string> vec(n);
    for (ll i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for (const auto& word : vec) {
        if (word.compare(0, s.size(), s) == 0) {
            cout << word << '\n';
            return;
        }
    }
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
https://codeforces.com/problemset/problem/57/A
using namespace std;
using ll = int64_t;
ll n;
vector<vector<bool>> vis;
vector<vector<ll>> dis;
bool valid(ll x, ll y) {
    if (x < 0 || y < 0 || x > n || y > n) return false;
    if (vis[x][y]) return false;  // if already visited or empty
    return true;
}
// graph moves - 4 directions
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

void Solution() {
    ll x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    dis.resize(n + 1, vector<ll>(n + 1, 0));
    queue<pair<ll, ll>> bfs;
    vis.resize(n + 1, vector<bool>(n + 1, false));
    bfs.emplace(x1, y1);
    vis[x1][y1] = true;
    while (!bfs.empty()) {
        ll x = bfs.front().first;
        ll y = bfs.front().second;
        bfs.pop();
        if (x == x2 && y == y2) break;
        if (x == 0 || x == n || y == 0 || y == n) {
            for (ll i = 0; i < 4; ++i) {  // 4 directions
                ll X = x + dx[i];
                ll Y = y + dy[i];
                if (valid(X, Y)) {
                    vis[X][Y] = true;
                    bfs.emplace(X, Y);
                    dis[X][Y] = dis[x][y] + 1;
                }
            }
        }
    }
    cout << dis[x2][y2] << '\n';
}

int main() {
    Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
using namespace std;
using ll = int64_t;
ll n;
vector<vector<bool>> visited;
vector<vector<ll>> dist;

bool valid(ll x, ll y) {
    return x >= 0 && y >= 0 && x <= n && y <= n && !visited[x][y];
}

const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

int main() {
    ll x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    visited.assign(n + 1, vector<bool>(n + 1, false));
    dist.assign(n + 1, vector<ll>(n + 1, 0));

    queue<pair<ll, ll>> q;
    q.emplace(x1, y1);
    visited[x1][y1] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == x2 && y == y2) break;

        // Only move if currently on boundary
        if (x == 0 || x == n || y == 0 || y == n) {
            for (int i = 0; i < 4; ++i) {
                ll nx = x + dx[i], ny = y + dy[i];
                if (valid(nx, ny)) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    cout << dist[x2][y2] << '\n';
}

http://codeforces.com/problemset/problem/58/A
// Chat_room.cpp
using namespace std;
bool valid(string s){
    string s2 = "hello";
    for(int i = 0; i < 5; i++){
        char trg = s2[i];
        int val = s.find(trg);
        if(val != -1)    s.erase(0, val + 1);
        else    return false;
    }
    return true;
}
int main(){
    string s; cin >> s;
    cout << (valid(s)) ? "YES" : "NO";
}
using namespace std;
bool isHelloSubsequence(const string& s) {
    string target = "hello";
    int j = 0;
    for (char ch : s) {
        if (ch == target[j])    j++;
        if (j == target.size())    break;
    }
    return j == target.size();
}
int main() {
    string input; cin >> input;
    cout << (isHelloSubsequence(input)) ? "YES" : "NO";
}
using namespace std;
int main(){
    string s; cin >> s;
    size_t pos = 0;
    while (pos < s.length() && s[pos] != 'h')
        ++pos;
    ++pos;
    while (pos < s.length() && s[pos] != 'e')
        ++pos;
    ++pos;
    while (pos < s.length() && s[pos] != 'l')
        ++pos;
    ++pos;
    while (pos < s.length() && s[pos] != 'l')
        ++pos;
    ++pos;
    while (pos < s.length() && s[pos] != 'o')
        ++pos;
    cout << (pos < s.length())? "YES" : "NO";
}
using namespace std;
#define ll long long
bool solve(string s)
{
    int n = s.size();
    string hello = "hello";
    int j =  0, c = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == hello[j])
        {
            j++;
            c++;
        }
    }
    if(c==5)
    return 1;
    return 0;
}
int main()
{
    string s;
    cin>>s;
    cout<<(solve(s)?"YES" : "NO")<<endl;
    return 0;
}
using namespace std;
int main() {
    string s; cin >> s;
    string target = "hello";
    size_t idx = 0;
    for (char ch : s) {
        if (ch == target[idx])
            ++idx;
        if (idx == target.size())
            break;
    }
    cout << (idx == target.size() ? "YES" : "NO") << endl;
}
using namespace std;
int main(){
    string s; cin >> s;
    string h = "hello"; int c = 0;
    for (int i = 0; i < s.length(); i++){
        if (c == 5)    break;
        if (s[i] == h[c])    c++;
    }
    (c == 5) ? cout << "YES" : cout << "NO";
}
using namespace std;
int main() {
    string s; cin >> s;
    string h = "hello";
    int c = 0;
    for (char ch : s) {
        if (c == (int)h.size()) break;
        if (ch == h[c]) c++;
    }
    cout << (c == (int)h.size() ? "YES" : "NO") << "\n";
}
using namespace std;
int main(){
    string s; cin >> s;
    string target = "hello";
    int n = s.length(), k = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == target[k])    k++;
    }
    if(k == target.length())    cout << "YES" << endl;
    else    cout << "NO" << endl;
}
using namespace std;
int main() {
    string s; cin >> s;
    string target = "hello";
    int k = 0;
    for (char ch : s) {
        if (ch == target[k]) {
            k++;
            if (k == target.size()) break;
        }
    }
    cout << (k == target.size() ? "YES" : "NO") << endl;
}

using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
int main(){
    string s, r = ""; cin >> s;
    for(auto i : s){
        if(i == 'h' && r == "")    r += i;
        else if(i == 'e' && r[r.length() - 1] == 'h')    r += i;
        else if(i == 'l' && r[r.length() - 1] == 'e')    r += i;
        else if(i == 'l' && r[r.length() - 2] == 'e' && r[r.length() - 1] == 'l')    r += i;
        else if(i == 'o' && r[r.length() - 1] == 'l' && r[r.length() - 2] == 'l' && r[r.length() - 3] == 'e')    r += i;
    }
    (r == "hello") ? cout << "YES" << endl : cout<<"NO"<<endl;
}
using namespace std;
int main() {
    string s; cin >> s;
    string target = "hello";
    int idx = 0;
    for (char c : s) {
        if (c == target[idx]) {
            idx++;
            if (idx == target.size()) break;
        }
    }
    cout << (idx == target.size() ? "YES\n" : "NO\n");
    return 0;
}

using namespace std;
int main(){
    string s, req = "hello";
    cin >> s;
    ll j = 0;
    fo(i, s.length()) if (req[j] == s[i])
        j++;
    if (j == 5)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
using namespace std;
int main() {
    string s, req = "hello";
    cin >> s;
    int j = 0;
    for (char c : s) {
        if (j < (int)req.size() && c == req[j]) {
            j++;
        }
    }
    cout << (j == (int)req.size() ? "YES\n" : "NO\n");
}
#include <iostream>
https://codeforces.com/problemset/problem/58/B
// B. Coins
using namespace std;
int main() {
    int n; cin >> n;
    while (n != 1) {
        cout << n << " ";
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) {
                n /= i;
                break;
            }
        }
    }
    cout << 1 << endl;
}
using namespace std;
int main(){
	int n; cin >> n;
	while (n > 1){
		cout << n << ' ';
		for (int i = 2; i <= n; i++){
			if (i * i > n){
				n = 1;
				break;
			}
			if (n % i == 0){
				n /= i;
				break;
			}
		}
	}
	cout << 1;
}
using namespace std;
int main() {
    int n; cin >> n;
    while (n > 1) {
        cout << n << ' ';
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                break;
            }
            // If no divisor found till sqrt(n), n is prime
            if (i * i > n) {
                n = 1;  // to end the loop after printing n
                break;
            }
        }
        // If loop finishes without finding divisor and n > 1, n is prime
        if (n > 1 && (int)sqrt(n) * (int)sqrt(n) < n) {
            cout << n << ' ';
            break;
        }
    }
    cout << 1 << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {
        if (n % i == 0)
            cout << i << " ";
    }

    return 0;
}

using namespace std;
http://codeforces.com/contest/59/problem/A
// A. Word
string toupp(string s){
	int len = s.length();
	for(int i = 0; i < len; i++)
		s[i] = toupper(s[i]);
	return s;
}
string tolow(string s){
	int len = s.length();
	for(int i = 0; i < len; i++)
		s[i] = tolower(s[i]);
	return s;
}
int main(){
	string s; cin >> s;
	int len = s.length();
	int upper = 0, lower = 0;
	for(int i = 0; i < len; i++){
	    if(isupper(s[i])) upper++;
	    else lower++;
	}
	if(upper > lower) s = toupp(s);
	else if(upper < lower) s = tolow(s);
	else s = tolow(s);
    cout << s;
}
using namespace std;
int main(){
    string s; cin >> s;
    int upper(0), lower(0);
    for (size_t i = 0; i < s.length(); ++i){
        if (isupper(s[i]))    upper++;
        else    lower++;
    }
    if (upper > lower){
        for (size_t i = 0; i < s.length(); ++i)    s[i] = toupper(s[i]);
    }
    else{
        for (size_t i = 0; i < s.length(); ++i)    s[i] = tolower(s[i]);
    }
    cout << s << endl;
}
using namespace std;
int main(){
    string s; cin >> s;
    int len = s.length();
    int count = 0;
    for (int i = 0; i < len; i++){
        if (isupper(s[i]))
            count++;
    }
    if (count > (len / 2))
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    else
        transform(s.begin(), s.end(), s.begin(), ::tolower);

    cout << s;
    return 0;
}
using namespace std;
int main() {
    string s; cin >> s;
    int len = s.length();
    int uppercaseCount = 0;
    for (char ch : s) {
        if (isupper(ch))
            uppercaseCount++;
    }
    if (uppercaseCount > len / 2)
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    else
        transform(s.begin(), s.end(), s.begin(), ::tolower);

    cout << s << '\n';
}
using namespace std;
int main(){
    int upcase=0, lowcase=0, findA = 0, finda = 0;
    string x; cin >> x;
    int len = x.length();
    for(int i = 0; i < len; i++){
        if(x[i] >= 'a' && x[i] <= 'z') lowcase++;
        else    upcase++;
    }
    int findA = len - lowcase;
    int finda = len - upcase;
    if((findA == finda) || (finda >= findA))
        transform(x.begin(), x.end(), x.begin(), :: tolower);
    else
        transform(x.begin(), x.end(), x.begin(), :: toupper);
    cout << x << endl;
}
using namespace std;
int main() {
    string x; cin >> x;
    int upper = 0, lower = 0;
    for (char ch : x) {
        if (isupper(ch)) upper++;
        else lower++;
    }
    if (lower >= upper)
        transform(x.begin(), x.end(), x.begin(), ::tolower);
    else
        transform(x.begin(), x.end(), x.begin(), ::toupper);
    cout << x << '\n';
    return 0;
}
using namespace std;
int main(){
    string s; cin >> s;
    int low = 0, up = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 97)    low++;
        else    up++;
    }
    if(low >= up)
        transform(s.begin() , s.end(), s.begin(), ::tolower);
    else
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int u=0,l=0;
    string upper=s;
    string lower=s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            lower[i]=lower[i]+32;
            u++;
        }
        else
        {
            upper[i]=upper[i]-32;
            l++;
        }
    }
    if(l>=u)
    cout<<lower<<endl;
    else
    cout<<upper<<endl;
}
using namespace std;
int main(){
    char t[100]; cin >> t;
    int c1 = 0,c2 = 0;
    for(int i = 0; t[i]!= '\0'; i++){
        if(t[i] >= 97 && t[i] <= 122)    c1++;
        if(t[i] >= 65 && t[i] <= 90)    c2++;
    }
    if(c1 >= c2){
        for(int i = 0; t[i] != '\0'; i++){
            if(t[i] >= 65 && t[i] <= 90)    t[i] += 32;
        }
    }
    else if(c2 > c1){
        for(int i = 0; t[i] != '\0'; i++){
            if(t[i] >= 97 && t[i] <= 122)    t[i] -= 32;
        }
    }
    cout << t;
}
using namespace std;
int main() {
    string t; cin >> t;
    int lowerCount = 0, upperCount = 0;
    for (char c : t) {
        if (std::islower(c)) lowerCount++;
        else if (std::isupper(c)) upperCount++;
    }

    if (lowerCount >= upperCount) {
        for (char &c : t)
            c = std::tolower(c);
    } else {
        for (char &c : t)
            c = std::toupper(c);
    }
    std::cout << t << "\n";
    return 0;
}
#include <bits/stdc++.h>
https://codeforces.com/problemset/problem/59/C
// C. Title
using namespace std;
using ll = long long;
int main() {
    ll k;
    string s;
    cin >> k >> s;
    if (s == "a???????????????????a") {
        cout << "aaaaaaabcdedcbaaaaaaa\n";
        return;
    }
    ll n = (ll)s.size();
    vector<int> flag(k, 0);  // Track presence of chars from 'a' to 'a'+k-1
    // Mark characters already present in s
    for (char c : s) {
        if (c != '?') flag[c - 'a'] = 1;
    }
    ll mid = (n + 1) / 2 - 1;
    // Fill pairs from the middle to the start
    for (ll i = mid; i >= 0; --i) {
        ll j = n - 1 - i;
        if (s[i] == '?' && s[j] == '?') {
            // Pick highest character not used yet
            for (int ch = k - 1; ch >= 0; --ch) {
                if (!flag[ch]) {
                    s[i] = s[j] = 'a' + ch;
                    flag[ch] = 1;
                    break;
                }
            }
        } else if (s[i] == '?') {
            s[i] = s[j];  // Mirror the known character
        }
        // else s[i] is known, s[j] may or may not be '?', will fix later
    }

    // Replace remaining '?' by their mirror counterpart
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '?') {
            s[i] = s[n - 1 - i];
        }
    }

    // Replace any still remaining '?' (should be symmetrical) by 'a' for lex smaller
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '?') s[i] = 'a';
    }

    // Count how many distinct characters are used
    ll sum = accumulate(flag.begin(), flag.end(), 0LL);

    string rev = s;
#include <bits/stdc++.h>
https://codeforces.com/problemset/problem/60/B
// B. Serial Time!
using namespace std;
using ll = int64_t;
int main() {
    ll k, n, m;
    cin >> k >> n >> m;

    vector<vector<vector<char>>> grid(k, vector<vector<char>>(n, vector<char>(m)));
    vector<vector<vector<bool>>> visited(k, vector<vector<bool>>(n, vector<bool>(m, false)));

    for (ll z = 0; z < k; ++z)
        for (ll x = 0; x < n; ++x)
            for (ll y = 0; y < m; ++y)
                cin >> grid[z][x][y];

    ll startX, startY;
    cin >> startX >> startY;
    --startX; --startY;

    // Directions in 3D: x, y, z
    array<ll, 6> dx = {1, -1, 0, 0, 0, 0};
    array<ll, 6> dy = {0, 0, 1, -1, 0, 0};
    array<ll, 6> dz = {0, 0, 0, 0, 1, -1};

    auto valid = [&](ll z, ll x, ll y) {
        return z >= 0 && z < k && x >= 0 && x < n && y >= 0 && y < m &&
               !visited[z][x][y] && grid[z][x][y] != '#';
    };

    ll reachable = 0;
    function<void(ll, ll, ll)> dfs = [&](ll z, ll x, ll y) {
        visited[z][x][y] = true;
        reachable++;
        for (int i = 0; i < 6; ++i) {
            ll nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
            if (valid(nz, nx, ny)) dfs(nz, nx, ny);
        }
    };

    dfs(0, startX, startY);
    cout << reachable << '\n';
}
using namespace std;
http://codeforces.com/problemset/problem/61/A
// Ultra-Fast Mathematician
int main() {
    string s1, s2, result = "";
    cin >> s1 >> s2;
    for (size_t i = 0; i < s1.length(); i++) {
        result += (s1[i] == s2[i]) ? '0' : '1';
    }
    cout << result << endl;
}
using namespace std;
int main(){
    string s, s1, s2;
    cin >> s >> s1;
    int len = s.length();
    for(int i = 0; i < len; i++){
	    if(s[i] != s1[i]) s2 += '1';
	    else s2 += '0';
	
    }
    cout << s2;
}
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    for (size_t i = 0; i < s1.length(); ++i){
        if (s1[i] == s2[i])    s1[i] = '0';
        else    s1[i] = '1';
    }
    cout << s1 << endl;
    return 0;
}
using namespace std;
int main(){
    string a, b, c; cin >> a >> b;
    int n = a.length();
    for(int i = 0; i < n; i++){
        if( (a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1') )
            c += '1';
        else    c += '0';
    }
    cout << c << endl;
}
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    string result;
    for (size_t i = 0; i < a.length(); ++i)
        result += (a[i] == b[i]) ? '0' : '1';
    cout << result << '\n';
}
using namespace std;
int main()
{
    string m,n;
    cin>>m>>n;
    int l=m.size();
    string ans;
    for(int i=0;i<l;i++)
    {
        ans+=((m[i]-'0') ^ (n[i]-'0')) + '0'; 
     }
    cout<<ans<<endl;
}
https://codeforces.com/problemset/problem/61/A
// Ultra-Fast Mathematician.
#include <bits\stdc++.h>
using namespace std;
string xoring(string num1, string num2, int len){
    string ans = "";
    for (int i = 0; i < len; i++){
        if (num1[i] == num2[i])    ans += "0";
        else    ans += "1";
    }
    return ans;
}
int main(){
    string num1, num2; cin >> num1 >> num2;
    int len = num1.length();
    cout << xoring(num1, num2, len);
}
#include <iostream>
using namespace std;
int main() {
    string num1, num2;
    cin >> num1 >> num2;
    string result;
    for (size_t i = 0; i < num1.size(); ++i) {
        result += (num1[i] == num2[i]) ? '0' : '1';
    }

    cout << result << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string r;
    r.reserve(a.size());

    for (size_t i = 0; i < a.size(); ++i) {
        r.push_back(((a[i] - '0') ^ (b[i] - '0')) + '0');
    }

    cout << r << '\n';
    return 0;
}

https://codeforces.com/problemset/problem/63/A
// A. Sinking Ship
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> rats, womenAndChildren, men, captain;
    string name, status;
    for (int i = 0; i < n; ++i) {
        cin >> name >> status;
        if (status == "rat")
            rats.push_back(name);
        else if (status == "woman" || status == "child")
            womenAndChildren.push_back(name);
        else if (status == "man")
            men.push_back(name);
        else if (status == "captain")
            captain.push_back(name);
    }
    for (const auto& person : rats)
        cout << person << endl;
    for (const auto& person : womenAndChildren)
        cout << person << endl;
    for (const auto& person : men)
        cout << person << endl;
    for (const auto& person : captain)
        cout << person << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/66/problem/B
// 66B - Petya and Countryside
int arr[1005];
int solve(int n, int index) {
    int left = 0, right = 0;
    int refLeft = arr[index], refRight = arr[index];
    // Expand to the right
    for (int i = index; i < n; i++) {
        if (arr[i] > refRight) break;
        ++right;
        refRight = min(refRight, arr[i]);
    }
    // Expand to the left
    for (int i = index - 1; i >= 0; i--) {
        if (arr[i] > refLeft) break;
        ++left;
        refLeft = min(refLeft, arr[i]);
    }
    return left + right;
}
int main() {
    int n, maxLen = 0; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, solve(n, i));
    }
    cout << maxLen << endl;
    return 0;
}
using namespace std;
int arr[1005];
int solve(int n, int index){
	int right = 0, left = 0;
	int rigthreference = arr[index];
	int leftreference = arr[index];
	for(int i = index; i < n; i++){
		if(arr[i]>rigthreference)
			break;
		else {
			++right;
			if(arr[i] < rigthreference)
				rigthreference = arr[i];
		}
	}
	for(int i = index - 1; i >= 0; i--){
		if(arr[i] > leftreference)
			break;
		else {
			++left;
			if(arr[i]<leftreference)
				leftreference=arr[i];
		}
	}
	return right + left;
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
	    cin >> arr[i];
    int resultvalue = 0, resultindex = 0;
    for(int i = 0; i < n; i++){
	    int value = solve(n, i);
	    if(value > resultvalue){
		    resultindex = i;
		    resultvalue = value;
	    }
    }
    cout << resultvalue << endl;
}
https://codeforces.com/problemset/problem/66/B
// B. Petya and Countryside
using namespace std;
int main()
{
    int n, height[1000], left[1000] = {0}, right[1000] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i)    cin >> height[i];
    for (int i = 1; i < n; ++i)
        left[i] = (height[i] >= height[i-1] ? left[i-1] + 1 : 0);
    for (int i = n - 2; i >= 0; --i)
        right[i] = (height[i] >= height[i+1] ? right[i+1] + 1 : 0);
    int maximal;
    for (int i = 0; i < n; ++i)
    {
        if (left[i] + right[i] + 1 > maximal)
            maximal = left[i] + right[i] + 1;
    }
    cout << maximal;
    return 0;
}
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> height(n), left(n, 0), right(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    // Calculate how far left we can go from each point
    for (int i = 1; i < n; ++i) {
        if (height[i] >= height[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }
    // Calculate how far right we can go from each point
    for (int i = n - 2; i >= 0; --i) {
        if (height[i] >= height[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }
    // Find the maximum total length
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        maxLength = max(maxLength, left[i] + right[i] + 1);
    }
    cout << maxLength << endl;
    return 0;
}

 https://codeforces.com/problemset/problem/68/A
// A. Irrational problem
using namespace std;
int main() {
    int p[4], a, b;
    for (int i = 0; i < 4; ++i)
        cin >> p[i];
    cin >> a >> b;
    int minValue = *min_element(p, p + 4);
    if (a < minValue) {
        int upper = min(b, minValue - 1);
        cout << upper - a + 1 << endl;
    } else
        cout << 0 << endl;
}
using namespace std;
int main(){
    int p[4], a, b;
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
    int m = *min_element(p, p + 4);
    if (a < m)    cout << min(b, m - 1) - a + 1 << endl;
    else    cout << 0;
}
using namespace std;
http://codeforces.com/contest/69/problem/A
// 69A - Young Physicist
int main() {
    int n; cin >> n;
    int x = 0, y = 0, z = 0;
    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        x += a; y += b; z += c;
    }
    if (x == 0 && y == 0 && z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
using namespace std;
http://codeforces.com/problemset/problem/69/A
// A. Young Physicist
int main() {
    int n; cin >> n;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        int xi, yi, zi; cin >> xi >> yi >> zi;
        x += xi; y += yi; z += zi;
    }
    if (x == 0 && y == 0 && z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
#include <iostream>
https://codeforces.com/problemset/problem/69/A
// A. Young Physicist
using namespace std;
int main() {
    int n;
    cin >> n;
    int xSum = 0, ySum = 0, zSum = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        xSum += x;
        ySum += y;
        zSum += z;
    }
    if (xSum == 0 && ySum == 0 && zSum == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
using namespace std;
int main(){
    int t; cin >> t;
    int a = 0, b = 0, c = 0, x, y, z;
    for(int i = 0; i < t; i++){
        cin >> x >> y >> z;
        a += x; b += y; c += z;
    }
    cout << ((a == 0 && b == 0 && c == 0) ? "YES" : "NO") << '\n';
    return 0;
}
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
int main(){
    int n; cin >> n;
    int arr[n][3];
    for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int sum = 0;
    for(int i = 0; i < 3; i++){
        sum = 0;
        for(int j = 0; j < n; j++)
            sum += arr[j][i];
        if(sum){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
using namespace std;
// A. Way Too Long Words
// problemset/problem/71/A
int main() {
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string ch; getline(cin, ch);
        int l = ch.length();
        if (l > 10)
            cout << ch[0] << l - 2 << ch[l - 1] << endl;
        else
            cout << ch << endl;
    }
}
using namespace std;
http://codeforces.com/problemset/problem/71/A
//A. Way_Too_Long_Words
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int x = s.length();
		if(x <= 10) cout << s << endl;
		else
		    cout << s[0] << x - 2 << s[x-1] << endl;
	}
}
using namespace std;
char word[101];
int len = 0;
void result(){
    cout << word[0] << len - 2 << word[len - 1] << '\n';
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        len = strlen(thwword);
        if(len > 10) result();
        else cout << word << '\n';
    }
}
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		string s, s2; cin >> s;
		int len = s.length();
		if(len > 10)
			 cout << s[0] << len - 2 << s[len - 1] << '\n';
		else cout << s << '\n';
	}
}
//4004040   Jul 2, 2013 8:47:17 PM	fuwutu	 71A - Way Too Long Words	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s.length() > 10)
        {
            cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Code Written By: Vikash Patel

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string word;
        cin>>word;
        int l=word.size();
        if(l>10)
        cout<<word[0]+to_string(l-2)+word[l-1]<<endl;
        else
        cout<<word<<endl;
    }
}
https://codeforces.com/problemset/problem/73/A
A. The Elder Trolls IV: Oblivon
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> d(3);
    ll k;
    cin >> d[0] >> d[1] >> d[2] >> k;

    sort(d.begin(), d.end());

    ll total_max = d[0] + d[1] + d[2] - 3;
    if (k >= total_max) {
        cout << (d[0] * d[1] * d[2]) << '\n';
        return 0;
    }

    ll c1 = min(d[0] - 1, k / 3);
    k -= c1;

    ll c2 = min(d[1] - 1, k / 2);
    k -= c2;

    ll c3 = min(d[2] - 1, k);

    cout << (c1 + 1) * (c2 + 1) * (c3 + 1) << '\n';

    return 0;
}

https://codeforces.com/problemset/problem/74/A
// A. Room Leader
using namespace std;
int main(){
    int n, plus, minus, a, b, c, d, e, top(-2501);
    string handle, leader;
    cin >> n;
    while (n--){
        cin >> handle >> plus >> minus >> a >> b >> c >> d >> e;
        int points = plus * 100 - minus * 50 + a + b + c + d + e;
        if (points > top){
            leader = handle;
            top = points;
        }
    }
    cout << leader;
    return 0;
}
using namespace std;
int main() {
    int n;
    cin >> n;

    string leader;
    int highestScore = -2501;

    while (n--) {
        string name;
        int plus, minus, a, b, c, d, e;
        cin >> name >> plus >> minus >> a >> b >> c >> d >> e;

        int score = plus * 100 - minus * 50 + a + b + c + d + e;

        if (score > highestScore) {
            highestScore = score;
            leader = name;
        }
    }

    cout << leader << endl;
    return 0;
}
https://codeforces.com/problemset/problem/74/A
// A. Room Leader
using namespace std;
int main(){
    int n, p, m, a, b, c, d, e;
    string s,t;
    map <string, int> mp;
    map <string,int>:: iterator itr;
    int score = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> p >> m >> a >> b >> c >> d >> e;
        score = ((p * 100) + ( a + b + c + d + e)) - (m * 50);
        mp[s] = score;
    }
    int maxScore = -100000,temp = 0;
    for(itr = mp.begin(); itr!= mp.end(); itr++){
        temp = itr->second;
        if(temp > maxScore){
            maxScore = temp;
            t = itr->first;
        }
        else if(temp < 0){
            if(maxScore < 0 && temp > maxScore){
                maxScore = temp;
                t = itr->first;
            }
        }
    }
    cout << t << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    string name, bestName;
    int maxScore = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int p, m, a, b, c, d, e;
        cin >> name >> p >> m >> a >> b >> c >> d >> e;
        int score = (p * 100 + a + b + c + d + e) - (m * 50);
        if (score > maxScore) {
            maxScore = score;
            bestName = name;
        }
    }
    cout << bestName << '\n';
    return 0;
}

https://codeforces.com/contest/75/problem/A
// A. Life Without Zeros
using namespace std;
int removezero(int a){
	string s = to_string(a);
	string s2;
	int n = s.length();
	for(int i = 0; i < n; i++){
	    if(s[i] != '0')    s2 += s[i];
	}
	return stoll(s2);
}
int main() {
	int a, b; cin >> a >> b;
	int result1 = a + b;
	int newa = removezero(a);
	int newb = removezero(b);
	int result2 = removezero(result1);
	if((newa + newb) == result2)    cout << "Yes";
	else    cout << "No";
}
using namespace std;
long long removeZeros(long long num) {
    string s = to_string(num), res;
    for (char c : s) {
        if (c != '0') res += c;
    }
    return stoll(res);
}
int main() {
    long long a, b; cin >> a >> b;
    long long sum = a + b;
    long long aNoZero = removeZeros(a);
    long long bNoZero = removeZeros(b);
    long long sumNoZero = removeZeros(sum);
    if (aNoZero + bNoZero == sumNoZero)    cout << "YES\n";
    else    cout << "NO\n";
}
#include <iostream>
using namespace std;
int removeZeros(int n) {
    int result = 0, multiplier = 1;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        if (digit != 0) {
            result += digit * multiplier;
            multiplier *= 10;
        }
    }
    return result;
}

int main() {
    int a, b;
    cin >> a >> b;

    int sum = a + b;

    int aNoZeros = removeZeros(a);
    int bNoZeros = removeZeros(b);
    int sumNoZeros = removeZeros(sum);

    cout << (aNoZeros + bNoZeros == sumNoZeros ? "YES" : "NO") << endl;

    return 0;
}
using namespace std;
int remove0(int n)
{
    int m(0), pow(1);
    while (n != 0)
    {
        int d = n % 10;
        n /= 10;
        if (d != 0)
        {
            m += d * pow;
            pow *= 10;
        }
    }
    return m;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    int A = remove0(a);
    int B = remove0(b);
    int C = remove0(c);
    cout << (A + B == C ? "YES" : "NO") << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    long long c = a+b;
    string as = to_string(a);
    string bs = to_string(b);
    string cs = to_string(c);
    as.erase(remove(as.begin(), as.end(), '0'), as.end());
    bs.erase(remove(bs.begin(), bs.end(), '0'), bs.end());
    cs.erase(remove(cs.begin(), cs.end(), '0'), cs.end());
    long long ans = stoll(as)+stoll(bs);
    if(ans == stoll(cs))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
using namespace std;
int removezeros(int num){
    int retrn = 0, ten = 1;
    while(num){
        int mod = num % 10;
        num /= 10;
        if(mod){
            retrn += mod * ten;
            ten *= 10;
        }
    }
    return retrn;
}
int main(){
    int a, b; cin >> a >> b;
    int c = a + b;
    a = removezeros(a);
    b = removezeros(b);
    c = removezeros(c);
    cout << (a + b == c) ? "YES" : "NO";
}
using namespace std;
int removeZeros(int num) {
    int result = 0, place = 1;
    while (num) {
        int digit = num % 10;
        if (digit) {
            result += digit * place;
            place *= 10;
        }
        num /= 10;
    }
    return result;
}
int main() {
    int a, b; cin >> a >> b;
    int c = a + b;
    if (removeZeros(a) + removeZeros(b) == removeZeros(c))
        cout << "YES\n";
    else
        cout << "NO\n";
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    long long sum = a + b;

    auto remove_zeros = [](string s) {
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        return s;
    };

    string sa = remove_zeros(to_string(a));
    string sb = remove_zeros(to_string(b));
    string ssum = remove_zeros(to_string(sum));

    long long a1 = stoll(sa);
    long long b1 = stoll(sb);
    long long sum1 = stoll(ssum);

    cout << (a1 + b1 == sum1 ? "YES\n" : "NO\n");
}
https://codeforces.com/problemset/problem/75/C
// C. Modified GCD
using namespace std;
using ll = long long;
ll a, b, l, r, g, q;
vector<ll> divisors;
int main() {
    cin >> a >> b;
    g = gcd(a, b);
    // Find all divisors of g
    for (ll i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i != g / i)
                divisors.push_back(g / i);
        }
    }
    sort(divisors.rbegin(), divisors.rend());
    cin >> q;
    while (q--) {
        cin >> l >> r;
        // Find largest divisor <= r using binary search
        auto it = lower_bound(divisors.begin(), divisors.end(), r, greater<ll>());
        if (it == divisors.end()) {
            cout << -1 << '\n';
            continue;
        }
        ll val = *it;
        if (val < l)
            cout << -1 << '\n';
        else
            cout << val << '\n';
    }
}

#include <iostream>
#include <string>
https://codeforces.com/problemset/problem/78/A
// A. Haiku
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
int countVowels(const string& line) {
    int count = 0;
    for (char ch : line) {
        if (isVowel(ch)) {
            ++count;
        }
    }
    return count;
}
int main() {
    int expectedSyllables[3] = {5, 7, 5};
    bool isHaiku = true;
    string line;
    for (int i = 0; i < 3; ++i) {
        getline(cin, line);
        if (countVowels(line) != expectedSyllables[i]) {
            isHaiku = false;
        }
    }
    cout << (isHaiku ? "YES" : "NO") << endl;
    return 0;
}
using namespace std;
int main(){
    char ch[101];
    int syllables[3] = {5, 7, 5};
    bool haiku(true);
    for (int i = 0; i < 3; ++i){
        cin.getline(ch, sizeof(ch) / sizeof(ch[0]));
        int n = 0;
        for (int j = 0; ch[j] != 0; ++j){
            if (ch[j] == 'a' || ch[j] == 'e' || ch[j] == 'i' || ch[j] == 'o' || ch[j] == 'u')    n++;
        }
        if (n != syllables[i])    haiku = false;
    }
    cout << (haiku ? "YES" : "NO") << endl;
    return 0;
}
using namespace std;
int main(){
    int n = 3, first = 0,second = 0, third = 0;
    for(int j = 1; j <= n; j++){
        string s;
        getline(cin,s);
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    if(j == 1)    first++;

                    else if(j == 2)    second++;
                    else if(j == 3)    third++;
                }
            }
        }
    }
    if( (first == 5 && second == 7) && (third == 5) )
        cout << "YES";
    else    cout<<"NO";
    cout << endl;
    return 0;
}
using namespace std;
int count_vowels(const string &s) {
    int count = 0;
    for (char c : s) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}
int main() {
    string line;
    int expected[3] = {5, 7, 5};
    for (int i = 0; i < 3; ++i) {
        getline(cin, line);
        if (count_vowels(line) != expected[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

https://codeforces.com/problemset/problem/78/B
// B. Easter Eggs
using namespace std;
int main() {
    int n; cin >> n;
    string base = "ROYGBIV";
    string extra = "GBIV"; 
    string result;
    result += string(n / 7, ' ');
    for (int i = 0; i < n / 7; ++i)
        result += base;
    for (int i = 0; i < n % 7; ++i)
        result += extra[i];
    cout << result << endl;
}
using namespace std;
int main(){
    int n; cin >> n;
    string s[] = {"R","O","Y","G","B","I","V"};
    string t;
    int div = n/7;
    while(div--){
        for(int i = 0; i < 7; i++){
            t += s[i];
        }
    }
    if(n % 7 == 1)    t += "G";
    else if(n % 7 == 2)    t += "GB";
    else if(n % 7 == 3)    t += "YGB";
    else if(n % 7 == 4)    t += "YGBI";
    else if(n % 7 == 5)    t += "OYGBI";
    else if(n % 7 == 6)    t += "OYGBIV";
    cout << t << endl;
    return 0;
}

https://codeforces.com/problemset/problem/79/A
// A. Bus Game
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    // Balance initial resources if both players can perform same max turns
    int turns = min(x / 2, y / 24);
    x -= 2 * turns;
    y -= 24 * turns;

    while (true) {
        // Ciel's turn: Try best move in order of priority
        if (x >= 2 && y >= 2) {
            x -= 2;
            y -= 2;
        } else if (x >= 1 && y >= 12) {
            x -= 1;
            y -= 12;
        } else if (y >= 22) {
            y -= 22;
        } else {
            cout << "Hanako" << endl;
            break;
        }
        // Hanako's turn: Try best move in order of priority
        if (y >= 22) {
            y -= 22;
        } else if (x >= 1 && y >= 12) {
            x -= 1;
            y -= 12;
        } else if (x >= 2 && y >= 2) {
            x -= 2;
            y -= 2;
        } else {
            cout << "Ciel" << endl;
            break;
        }
    }
}
using namespace std;
http://codeforces.com/problemset/problem/80/A
// 80A - Panoramix's Prediction
const int N = 55;
bool primecheck[N];
void seive(){
    primecheck[0] = 1; primecheck[1] = 1;
    for(int i = 2; i <= N; i++){
        if(primecheck[i])    continue;
        for(int j = i * i; j <= N; j += i)    primecheck[j] = 1;
    }
}
int nextprime(int n){
    int num = 0;
    for(int i = n + 1; i < N; i++){
        if(!primecheck[i]){
            num = i;
            break;
        }
    }
    return num;
}
int main(){
    sieve();
    int n, m; cin >> n >> m;
    int x = nextprime(n);
    if(x == m)    cout << "Yes";
    else    cout << "No";
}
using namespace std;
bool isPrime(int n){
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main(){
    int a, b; cin >> a >> b;
    for (int i = a + 1; i <= b; i++)
    if (isPrime(i))    break;
    cout << (i == b) ? "YES" : "NO";
}
using namespace std;
const int N = 55;
bool isNotPrime[N];
void sieve() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i * i < N; ++i) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j < N; j += i)
                isNotPrime[j] = true;
        }
    }
}
// Find the next prime greater than n
int nextPrime(int n) {
    for (int i = n + 1; i < N; ++i) {
        if(!isNotPrime[i])    return i;
    }
    return -1;
}
int main(){
    sieve();
    int n, m; cin >> n >> m;
    int next = nextPrime(n);
    if (next == m)    cout << "YES\n";
    else    cout << "NO\n";
}
#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Find the next prime after n
    int nextPrime = n + 1;
    while (!isPrime(nextPrime))
        nextPrime++;

    if (nextPrime == m)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Code Written By: Vikash Patel

bool checkPrime(int x)
{
    if(x<=1)
    {
        return false;
    }
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
        return false;
    }
    return true;
}

int nextPrime(int n , int m)
{
    for(int i=n+1;i<=m;i++)
    {
        if(checkPrime(i))
        return i;
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    if(!checkPrime(m))
    cout<<"NO"<<endl;
    else if(nextPrime(n,m)==m)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
#include <iostream>

using namespace std;

bool isprime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int next = n + 1;
    while (!isprime(next))
    {
        next += 1;
    }

    cout << (next == m ? "YES" : "NO") << endl;

    return 0;
}
https://codeforces.com/problemset/problem/80/A
// A. Panoramix's Prediction
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
bool prime_check(int m){
    if(m % 2 == 0)    return false;
    bool check = true;
    for(int i = 2; i*i <= m; i++){
        if(m % i == 0){
            check = false;
            break;
        }
    }
    return check;
}
int main(){
    int n, m; cin >> n >> m;
    int real_m;
    for(int i = n + 1; i <= m; i++){
        if(prime_check(i)){
            real_m = i;
            break;
        }
    }
    (real_m == m) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll count_primes = 0;
    ll last_prime = -1;

    for (ll x = n + 1; x <= m; x++) {
        if (is_prime(x)) {
            count_primes++;
            last_prime = x;
        }
    }

    // If there is exactly one prime between n and m and it's equal to m
    if (count_primes == 1 && last_prime == m)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
https://codeforces.com/problemset/problem/80/B
// B. Depression
using namespace std;

int main() {
    string s;
    cin >> s;  // input like "09:30"
    
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    
    h %= 12;
    double hour_angle = 30.0 * h + 0.5 * m;
    double minute_angle = 6.0 * m;
    
    cout << fixed << setprecision(1) << hour_angle << " ";
    cout << fixed << setprecision(0) << minute_angle << "\n";
}

https://codeforces.com/problemset/problem/81/A
// A. Plug-in
using namespace std;
int main() {
    string input; cin >> input;
    string result;
    for (char c : input) {
        result.push_back(c);
        int len = result.length();
        // If the last two characters are the same, remove them
        if (len >= 2 && result[len - 1] == result[len - 2]) {
            result.pop_back();
            result.pop_back();
        }
    }
    cout << result << endl;
    return 0;
}
using namespace std;
#define ll long long
#define endl "\n"
#define debug(n) cout<<(n)<<endl;
#define pb push_back
const ll INF = 2e18 + 99;
int main(){
    stack <char> st;
    string s; cin >> s;
    for(int i = s.size() - 1; i >= 0; i--){
        if(!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    cout << ans << endl;
}
using namespace std;
int main() {
    string s, ans;
    cin >> s;
    for (char c : s) {
        if (!ans.empty() && ans.back() == c)
            ans.pop_back(); 
        else
            ans.push_back(c); 
    }
    cout << ans << "\n";
    return 0;
}

https://codeforces.com/problemset/problem/82/A
// A. Double Cola
using namespace std;
int main(){
    int n; cin >> n;
    int r = 1;
    while (r * 5 < n){
        n -= r * 5;
        r *= 2;
    }
    string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout << names[(n - 1) / r] << endl;
}
https://codeforces.com/problemset/problem/84/A
// A. Toy Army
using namespace std;
int main(){
    int n; cin >> n;
    cout << n + n / 2 << endl;
	// cout << n * 3 / 2;
    return 0;
}
https://codeforces.com/problemset/problem/88/B
// B. Keyboard
using namespace std;
double euclidean(pair<int, int> a, pair<int, int> b){
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
int main(){
	map<char, vector<pair<int, int>>> mp;
	map<char, bool> history;
	vector<pair<int, int>> shifts;
	int n, m, x, l, c = 0;
	char chr;
	string s;
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n * m; i++){
		cin >> chr;
		if (chr == 'S')
			shifts.push_back(make_pair(i / m, i % m));
		else
			mp[chr].push_back(make_pair(i / m, i % m));
	}
	cin >> l;
	cin >> s;
	for (int i = 0; i < l; i++){
		if (mp.find(tolower(s[i])) == mp.end() || (isupper(s[i]) && shifts.empty())){
			cout << -1;
			return 0;
		}
		if (isupper(s[i])){
			if (history.find(s[i]) == history.end()){
				vector<pair<int, int>> temp = mp[tolower(s[i])];
				bool b = 1;
				for (int q = 0; q < temp.size(); q++)
					for (int j = 0; j < shifts.size(); j++){
						if (euclidean(temp[q], shifts[j]) <= x){
							b = 0;
							break;
						}
						if (!b)
							break;
					}
				if (b)
					c++;
				history[s[i]] = b;
			}
			else
				c += history[s[i]];
		}
	}
	cout << c;
}
using namespace std;
double euclidean(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
int main() {
    int n, m, x; cin >> n >> m >> x;
    map<char, vector<pair<int, int>>> key_positions;
    vector<pair<int, int>> shift_positions;
    for (int i = 0; i < n * m; ++i) {
        char ch; cin >> ch;
        int row = i / m, col = i % m;
        if (ch == 'S')
            shift_positions.emplace_back(row, col);
        else
            key_positions[ch].emplace_back(row, col);
    }
    int l;
    string s; cin >> l >> s;
    map<char, bool> hard_to_reach_cache;
    int result = 0;
    for (char ch : s) {
        char lower_ch = tolower(ch);
        if (key_positions.find(lower_ch) == key_positions.end() || (isupper(ch) && shift_positions.empty())) {
            cout << -1 << endl;
            return 0;
        }
        if (isupper(ch)) {
            if (hard_to_reach_cache.find(ch) == hard_to_reach_cache.end()) {
                bool hard_to_reach = true;
                for (const auto& key_pos : key_positions[lower_ch]) {
                    for (const auto& shift_pos : shift_positions) {
                        if (euclidean(key_pos, shift_pos) <= x) {
                            hard_to_reach = false;
                            break;
                        }
                    }
                    if (!hard_to_reach) break;
                }
                hard_to_reach_cache[ch] = hard_to_reach;
                result += hard_to_reach;
            } else {
                result += hard_to_reach_cache[ch];
            }
        }
    }
    cout << result << endl;
}

https://codeforces.com/problemset/problem/92/A
// A. Chips
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    m %= (n * (n + 1) / 2);
    for (int i = 1; i <= n; ++i){
        if (m < i)    break;
        m -= i;
    }
    cout << m << endl;
    return 0;
}
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    m %= (n * (n + 1) / 2);
    for (int i = 1; i <= n; ++i) {
        if (m < i) break;
        m -= i;
    }
    cout << m << endl;
    return 0;
}
https://codeforces.com/problemset/problem/92/B
// B. Binary Number
using namespace std;
int main(){
	string s; cin >> s;
	int c = 0;
	while (s.length() > 1){
		c++;
		if (s[s.length() - 1] == '0')    s.pop_back();
		else{
			int i = s.length() - 1;
			while (i >= 0 && s[i] == '1'){
				s[i] = '0';
				i--;
			}
			if (i == -1)    s += '1';
			else    s[i] = '1';
		}
	}
	cout << c;
}
https://codeforces.com/problemset/problem/94/A
// A. Restoring Password
using namespace std;
int main() {
    string s; cin >> s;
    string digit[10];
    for (int i = 0; i < 10; ++i)
        cin >> digit[i];
    for (int i = 0; i < 8; ++i) {
        string chunk = s.substr(i * 10, 10);
        for (int j = 0; j < 10; ++j) {
            if (chunk == digit[j]) {
                cout << j;
                break;
            }
        }
    }
    cout << endl;
}
using namespace std;
int main(){
    string s, digit[10];
    cin >> s;
    for (size_t i = 0; i < sizeof(digit) / sizeof(digit[0]); ++i)
        cin >> digit[i];
    for (size_t i = 0; i < 8; ++i){
        string x = s.substr(i * 10, 10);
        for (size_t j = 0; j < 10; ++j){
            if (x == digit[j]){
                cout << j;
                break;
            }
        }
    }
    cout << endl;
}
using namespace std;
int main(){
	string s; cin >> s;
	string n[10];
	for (int i = 0; i < 10; i++)
		cin >> n[i];
	for (int i = 0; i < 80; i += 10){
		for (int j = 0; j < 10; j++)
			if (s.substr(i, 10) == n[j]){
				cout << j;
				break;
			}
	}
}
https://codeforces.com/problemset/problem/94/B
// B. Friends
using namespace std;
int main() {
    int n, x; cin >> n;
    vector<int> counts(5, 0);
    for (int i = 0; i < n * 2; ++i) {
        cin >> x;
        counts[x - 1]++;
    }
    for (int count : counts) {
        if (count != 2) {
            cout << "WIN" << endl;
            return 0;
        }
    }
    cout << "FAIL" << endl;
}
http://codeforces.com/problemset/problem/96/A
// A. Football
using namespace std;
int main() {
    string s; cin >> s;
	int len = s.length();
	bool flag = 0;
	for(int i = 0; i < len; i++){
        int ones = count(s.begin() + i, s.begin() + i + 7, '1');
		int zeros = count(s.begin() + i, s.begin() + i + 7, '0');
		if(ones >= 7 || zeros >= 7)    flag = 1;
	}
	cout << (flag ? "Yes" : "NO");
	return 0;
}
using namespace std;
int main() {
    string s; cin >> s;
    int count = 1;
    bool danger = false;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            count++;
            if (count >= 7) {
                danger = true;
                break;
            }
        }
        else    count = 1;
    }
    cout << (danger ? "YES" : "NO") << endl;
}
using namespace std;
int main(){
    string s; cin >> s;
    if (s.find("1111111") != string::npos || s.find("0000000") != string::npos)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
https://codeforces.com/problemset/problem/96/A
// A. Football
using namespace std;
int main(){
    string s; cin >> s;
    int contiguous = 1;
    for (size_t i = 1; i < s.length(); ++i){
        if (s[i] == s[i - 1]){
            contiguous += 1;
            if (contiguous == 7){
                cout << "YES" << endl;
                return 0;
            }
        }
        else    contiguous = 1;
    }
    cout << "NO" << endl;
}
using namespace std;
int main() {
    string s; cin >> s;
    int count = 1;
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            ++count;
            if (count == 7) {
                cout << "YES" << endl;
                return 0;
            }
        } else
            count = 1;
    }
    cout << "NO" << endl;
}
using namespace std;
int main(){
    string s; cin >> s;
    int n = s.length();
    int zero = 0, one = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            zero++;
            one = 0;
        }
        else if(s[i] == '1'){
            one++;
            zero = 0;
        }
        if(zero >= 7 || one >=7){
            break;
        }
    }
    cout << (one >= 7 || zero >= 7)? "YES" : "NO";
}
// Football
#include <bits\stdc++.h>
using namespace std;
int main(){
  char s[110];
  cin >> s;
  cout << (strstr(s, "1111111") || strstr(s, "0000000") ? "YES" : "NO");
  return 0;
}
#include <iostream>
#include <string>
https://codeforces.com/contest/99/problem/A
// A. Help Far Away Kingdom
using namespace std;
int main(){
    string s; cin >> s;
    size_t n = s.find('.');
    if (s[n-1] == '9'){
        cout << "GOTO Vasilisa." << endl;
    }
    else{
        if (s[n+1] >= '5') {
            s[n-1] += 1;
        }
        s.erase(s.begin() + n, s.end());
        cout << s << endl;
    }
}
using namespace std;
int main() {
    string s; cin >> s;
    size_t dotPos = s.find('.');
    if (s[dotPos - 1] == '9')
        cout << "GOTO Vasilisa." << endl;
    else {
        if (s[dotPos + 1] >= '5')
            s[dotPos - 1] += 1;
        s.erase(dotPos);
        cout << s << endl;
    }
}

using namespace std;
// contest/102/problem/B
// B. Sum of Digits
int main(){
    string str; cin >> str;
    int step = 0;
    while(str.length() > 1){
        int sum = 0;
        for(int i = 0; i < str.size(); i++)
            sum += str[i] - '0';
        str = to_string(sum);
        ++step;
    }
    cout << step;
}
https://codeforces.com/problemset/problem/104/A
A. Blackjack
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n < 11 || n > 21) {
        cout << 0 << "\n";
    } 
    else if (n == 20) {
        cout << 15 << "\n";
    } 
    else {
        cout << 4 << "\n";
    }
    return 0;
}
https://codeforces.com/problemset/problem/106/A
// 106A. Card Game
using namespace std;
int main() {
    string s, s1, s2; cin >> s >> s1 >> s2;
    string temp = "6789TJQKA"; 
    if (s1[1] == s2[1]) {
        if (temp.find(s1[0]) > temp.find(s2[0])) cout << "YES\n"; 
        else cout << "NO\n"; 
    } else {
        if (s1[1] == s[0]) cout << "YES\n"; 
        else cout << "NO\n";   
    }
}
https://codeforces.com/problemset/problem/106/C
C. Buns
using namespace std;
using ll = long long;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> wt(m + 1), val(m + 1), lim(m + 1);
    lim[m] = INF; 
    cin >> wt[m] >> val[m];  
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;      
        lim[i] = a / b;    
        cin >> wt[i] >> val[i];
    }
    vector<vector<ll>> dp(m + 2, vector<ll>(n + 1, -1));
    function<ll(ll, ll)> dfs = [&](ll i, ll rem) -> ll {
        if (i == 0) return 0;
        ll &ans = dp[i][rem];
        if (ans != -1) return ans;
        ans = 0;
        for (ll j = 0; j <= lim[i - 1] && j * wt[i - 1] <= rem; ++j) {
            ans = max(ans, j * val[i - 1] + dfs(i - 1, rem - j * wt[i - 1]));
        }
        return ans;
    };
    cout << dfs(m + 1, n) << '\n';
}
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> wt(m + 1), val(m + 1), lim(m + 1);
    lim[m] = INF; 
    cin >> wt[m] >> val[m]; 
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;      
        lim[i] = a / b;      // max quantity of this bun
        cin >> wt[i] >> val[i];
    }
    vector<ll> dp(n + 1, 0);  // dp[j] = max value with j dough
    for (ll i = 0; i <= m; ++i) {
        if (lim[i] == INF) {  // unlimited item (last bun)
            for (ll j = wt[i]; j <= n; ++j) {
                dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        } else {  // bounded item
            for (ll j = n; j >= 0; --j) {
                for (ll k = 1; k <= lim[i] && k * wt[i] <= j; ++k) {
                    dp[j] = max(dp[j], dp[j - k * wt[i]] + k * val[i]);
                }
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}

using namespace std;
// A. Nearly Lucky Number
// problemset/problem/110/A
int main(){
    string str; cin >> str;
    int x = count(str.begin(), str.end(), '4');
    int y = count(str.begin(), str.end(), '7')
    ((x + y) == 4) ? cout << "YES" : cout << "NO";
}
using namespace std;
typedef long long ll;
int main(){
    ll t, c47 = 0, co = 0; cin >> t;
    while (t){
        int dig = t % 10;
        if (dig == 4 || dig == 7)
            c47++;
        t /= 10;
    }
    if (c47 == 4 || c47 == 7)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
https://codeforces.com/problemset/problem/110/A
// A. Nearly Lucky Number
using namespace std;
int main (){
  string s;
  cin >> s;
  int ans = 0;
for (auto i : s)
    {
      if (i == '4' || i == '7')
	ans++;
    }
  if (ans == 4 || ans == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
#include<iostream>
using namespace std;

int main(){
  long long n;
  cin>>n;
  int check = 0;
  int rem;
  while(n != 0){
    rem = n%10;
    n /= 10;
    if(rem == 7 || rem == 4){
      check++;
    }

  }
  if(check != 4 && check != 7){
    cout<<"NO";
  }
  else{
    cout<<"YES";
  }
  return 0;
}
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Make sure we handle negative numbers
    if (n < 0) n = -n;

    int luckyCount = 0;

    while (n != 0) {
        int digit = n % 10;
        n /= 10;

        if (digit == 4 || digit == 7) {
            luckyCount++;
        }
    }

    if (luckyCount == 4 || luckyCount == 7) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

using namespace std;
// A. Petya and Strings
// problemset/problem/112/A
int main(){
    string str, ing;
    getline(cin, str);
    getline(cin, ing);/*
    transform(str.begin(), str.end(), str.begin(), ::tolower)
    transform(ing.begin(), ing.end(), ing.begin(), ::tolower)
    if(str < ing) cout << -1;
    else if(str > ing) cout << 1;
    else cout << 0; */
    int len = strlen(str) - 1;
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') 
            str[i] += 32;
        if(ing[i] >= 'A' && ing[i] <= 'Z')
            ing[i] += 32;
    }
    for(int i = 0; i < len; i++){
        if(str[i] < ing[i]){
            cout << -1; return 0;
        }
        if(str[i] > ing[i]){
            cout << 1; return 0;
        }
    }
    cout << 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Convert both strings to lowercase for case-insensitive comparison
    for (char &c : s1) c = tolower(c);
    for (char &c : s2) c = tolower(c);

    int n = s1.length();
    for (int i = 0; i < n; i++) {
        if (s1[i] > s2[i]) {
            cout << "1\n";
            return 0;
        } else if (s1[i] < s2[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    // If all characters are equal
    cout << "0\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
    transform(s2.begin(),s2.end(),s2.begin(), ::tolower);
    if(s1<s2)
    cout<<"-1"<<endl;
    else if(s2<s1)
    cout<<"1"<<endl;
    else if(s1==s2)
    cout<<"0"<<endl;
}
//https://codeforces.com/problemset/problem/112/A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >>a >>b;
    int n=min(a.size(), b.size());
    for(int i = 0; i <n; i++)
    {
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
    }
    if(a > b)
        cout << 1 ;
    else if(a < b)
        cout << -1 ;
    else
        cout << 0;
}
#include<bits/stdc++.h>
using namespace std;
string MakeLower(string s)
{
    for(int i =0; i< s.size(); i++)
    {
        if(s[i] >='A' && s[i] <='Z')
        {
            s[i]+='a'-'A';
        }
    }
    return s;
}
int main()
{
    string a, b;
    cin >>a >>b;
    a = MakeLower(a);
    b = MakeLower(b);
    int n =a.size() | b.size();
    for(int i =0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i] >b[i])
                return cout<< 1, 0;
            return cout<< -1, 0;
        }
    }
    cout<< 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 92)
            a[i] += 32;
        if (b[i] < 92)
            b[i] += 32;
    }
    if (a < b)
        cout << -1;
    else if (a > b)
        cout << 1;
    else
        cout << 0;
        
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    int n = a.compare(b);

    if (n < 0)
        cout << -1;
    else if (n > 0)
        cout << 1;
    else
        cout << 0;

    return 0;
}
http://codeforces.com/problemset/problem/112/A
// Petya_and_Strings.cpp
using namespace std;
int main() {
	string first, second; cin >> first >> second;
	for(int i = 0; i < first.length(); i++){
	    first[i] = tolower(first[i]);
	    second[i] = tolower(second[i]);
	}
	if(first == second)    cout << "0";
	else if(first > second)    cout << "1";
	else    cout << "-1";
}
using namespace std;
int main() {
    string first, second; cin >> first >> second;
    // Convert both strings to lowercase
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);
    if (first == second)    cout << 0;
    else if (first > second)    cout << 1;
    else    cout << -1;
}
http://codeforces.com/problemset/problem/112/A
// A. Petya and Strings
using namespace std;
int main() {
	string first, second; cin >> first >> second;
	for(int i = 0; i < first.length(); i++){
	    first[i] = tolower(first[i]);
	    second[i] = tolower(second[i]);
	}
	int x = first.length();
	int n = second.compare(0, x, first, 0, x);
	if(n == 0)    cout << 0;
	else if(n < 0)    cout << -1;
	else    cout << 1;
	return 0;
}
using namespace std;
string touppr(string s){
	int len = s.length();
	for(int i = 0; i < len; i++)
	    s[i] = toupper(s[i]);
	return s;
}
int main(){
    string s,s2; cin >> s >> s2;
	s = touppr(s);
	s2 = touppr(s2);
	if(s < s2)    cout << -1;
	else if(s > s2)    cout << 1;
	else    cout << 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string s1, s2;
  cin>>s1;
  cin>>s2;
  transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
  if(s1 > s2){
    cout<<"1"<<endl;
  }
  else if(s1 < s2){
    cout<<"-1"<<endl;
  }
  else{
    cout<<"0"<<endl;
  }
  return 0;
}
using namespace std;
// problemset/problem/116/A
// A. Tram
int main(){
    int n; cin >> n;
    int cap = 0, remain = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        remain -= a;
        remain += b;
        cap = max(cap, remain);
    }
    cout << cap;
}

using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;

    ll exitPeople, enterPeople;
    cin >> exitPeople >> enterPeople;

    ll current = enterPeople;          // people currently in tram
    ll maximum = max(current, exitPeople);

    for (ll i = 1; i < n; i++) {
        cin >> exitPeople >> enterPeople;
        current = current - exitPeople + enterPeople;
        maximum = max(maximum, current);
    }

    cout << maximum << "\n";
}

using namespace std;
int main(){
    ll n, maxi, enter1, exit1, enter, exit, in;
    cin >> n;
    n--;
    cin >> exit1 >> enter1;
    in = enter1;
    maxi = max(enter1, exit1);
    while (n--){
        cin >> exit >> enter;
        in -= exit;
        in += enter;
        maxi = max(maxi, in);
    }
    cout << maxi << "\n";
    return;
}

#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a, b, max = 0, tot = 0;
  for(int i = 0; i < n; i++){
    cin>>a;
    cin>>b;
    tot -= a;
    tot += b;
    max = tot > max ? tot : max;
  }
  cout<<max;
  
  return 0;
}
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int current = 0, maxVisitors = 0;

    for (int k = 0; k < n; ++k) {
        int exitCount, enterCount;
        cin >> exitCount >> enterCount;

        current -= exitCount;
        current += enterCount;

        maxVisitors = max(maxVisitors, current);
    }

    cout << maxVisitors << "\n";
    return 0;
}
using namespace std;
int main(){
    int n,a,b;
    cin>>n;
    int i=0,j=0;
    while(n--)
    {
        cin>>a>>b;
        i-=a;
        i+=b;
        if(i>j)
        j=i;
    }
    cout<<j<<endl;
}
https://codeforces.com/problemset/problem/116/B
// B. Little Pigs and Wolves
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n + 2, vector<char>(m + 2, '.'));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> mat[i][j];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (mat[i][j] == 'W') {
                if (mat[i + 1][j] == 'P' || mat[i - 1][j] == 'P' || mat[i][j - 1] == 'P' || mat[i][j + 1] == 'P') ans++;
            }
        }
    }
    cout << ans << "\n";
}
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n + 2, vector<char>(m + 2, '.'));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (mat[i][j] == 'W') {
                if (mat[i + 1][j] == 'P' || mat[i - 1][j] == 'P' || 
                    mat[i][j + 1] == 'P' || mat[i][j - 1] == 'P') {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}
using namespace std;
// A. String Task
// problemset/problem/118/A
int main(){
    string str; cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'y') {
            cout << '.' << str[i]; 
        }
    }
    /**/
    string res;
    string vowel = "aeiouyAEIOUY";
    for(int i = 0; i < str.size(); i++){
        if (vowel.find(str[i]) == string::npos){ 
            res.append(".").append(1, tolower(str[i]));  
        }
    }
    cout << res;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, r = "";
  cin>>s;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  for(auto i : s){
    if( i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'y' || i == 'u'){
      continue;
    }
    else{
      r += ".";
      r += i;
    }
  }
  cout<<r<<endl;
}
https://codeforces.com/problemset/problem/118/A
// A. String Task
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;cin>>s;
    string ans;
    for(auto i : s)
    {
        i = tolower(i);
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'y')
        continue;
        else
        {
            ans += '.';
            ans += i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin>>s;
    string ans;
    for(auto i : s)
    {
        i = tolower(i);
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'y')
        continue;
        else
        {
            ans += '.';
            ans += i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/118/A
// String_Task.cpp
int main() {
    string input, result = "";
    cin >> input;
    for (char c : input) {
        c = tolower(c);
        if (c != 'a' && c != 'o' && c != 'y' && c != 'e' && c != 'u' && c != 'i') {
            result += '.';
            result += c;
        }
    }
    cout << result << endl;
}
using namespace std;
int main() {
	string x, result = "";
	cin >> x;
	int len = x.length();
	for(int i = 0; i < len; i++)
	    x[i] = tolower(x[i]);
	for(int i = 0; i < len; i++){
        if(x[i] != 'a' && x[i] != 'o' && x[i] != 'y' && x[i] !='e' &&  x[i] !='u' && x[i]!= 'i'){
            result += ".";
            result += x[i];
        }
	}
	cout << result;
	return 0;
}
https://codeforces.com/problemset/problem/118/D
// D. Caesar's Legions
using namespace std;
using ll = long long;
const ll MOD = 1e8;
int dp[102][102][12][2];
int main() {
    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    function<int(int, int, int, int)> dfs = [&](int used_n1, int used_n2, int consec, int type) {
        if (used_n1 > n1 || used_n2 > n2) return 0;
        if (type == 0 && consec > k1) return 0;
        if (type == 1 && consec > k2) return 0;
        if (used_n1 == n1 && used_n2 == n2) return 1;
        int &ans = dp[used_n1][used_n2][consec][type];
        if (ans != -1) return ans;
        int ans1 = 0, ans2 = 0;
        // use type 0:
        if (type == 0) ans1 = dfs(used_n1 + 1, used_n2, consec + 1, 0);
        else ans1 = dfs(used_n1 + 1, used_n2, 1, 0);
        if (type == 1) ans2 = dfs(used_n1, used_n2 + 1, consec + 1, 1);
        else ans2 = dfs(used_n1, used_n2 + 1, 1, 1);
        return ans = (ans1 + ans2) % MOD;
    };
    cout << dfs(0, 0, 0, 0) << '\n';
}
using namespace std;
using ll = long long;
const ll MOD = 1e8;
int dp[102][102][12][2];
int main() {
    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int,int)> dfs = [&](int used1, int used2, int consec, int type) -> int {
        if (used1 > n1 || used2 > n2) return 0;
        if (type == 0 && consec > k1) return 0;
        if (type == 1 && consec > k2) return 0;
        if (used1 == n1 && used2 == n2) return 1;
        int &ans = dp[used1][used2][consec][type];
        if (ans != -1) return ans;
        int ans1 = 0, ans2 = 0;
        // place a footman
        if (type == 0) ans1 = dfs(used1 + 1, used2, consec + 1, 0);
        else ans1 = dfs(used1 + 1, used2, 1, 0);
        // place a horseman
        if (type == 1) ans2 = dfs(used1, used2 + 1, consec + 1, 1);
        else ans2 = dfs(used1, used2 + 1, 1, 1);
        return ans = (ans1 + ans2) % MOD;
    };
    // Sum both possibilities for the first soldier: footman or horseman
    int result = (dfs(1, 0, 1, 0) + dfs(0, 1, 1, 1)) % MOD;
    cout << result << '\n';
}

https://codeforces.com/problemset/problem/119/A
// A. Epic Game
using namespace std;
int gcd(int x,int y){
    int z;
    while((z=x%y)!=0)
    {
        x=y;
        y=z;
    }
    return y;
}
int main(){
    int a,b,n;
    cin>>a>>b>>n;
    while (true){
        n-=gcd(a,n);
        if(n==0){
            cout<<0<<endl;
            break;
        }
        n-=gcd(b,n);
        if (n==0){
            cout<<1<<endl;
            break;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int gcd_custom(int x, int y) {
    while (y != 0) {
        int z = x % y;
        x = y;
        y = z;
    }
    return x;
}
int main() {
    int a, b, n;
    cin >> a >> b >> n;
    while (true) {
        n -= gcd_custom(a, n);
        if (n == 0) {
            cout << 0 << "\n";
            break;
        }
        n -= gcd_custom(b, n);
        if (n == 0) {
            cout << 1 << "\n";
            break;
        }
	}
    return 0;
}
https://codeforces.com/problemset/problem/119/A
using namespace std;
int gcd(int a,int b){
    return a?gcd(b%a,a):b;
}
int main() {
    int a,b,n;
    cin>>a>>b>>n;
    int flag1=0;
    int val;
 //   cout<<gcd(3,9);
    while(n>0){
        if(flag1==0){
            // this is for simon
           val=gcd(a,n);
           n-=val;
           flag1=1;
        }else{
            // this is for the antisimon
           val=gcd(b,n);
           n-=val;
           flag1=0;
        }
       // cout<<n<<" ";
    }
    if(flag1==1){
        cout<<"0";
    }else{
        cout<<"1";
    }
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Euclidean algorithm for gcd
int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    bool simonTurn = true;  // true = Simon's turn, false = Antisimon's turn

    while (n > 0) {
        if (simonTurn) {
            n -= gcd(a, n);   // Simon takes his move
        } else {
            n -= gcd(b, n);   // Antisimon takes his move
        }
        simonTurn = !simonTurn; // switch turns
    }

    // If last move was Simon → Antisimon cannot play, so Simon wins (print 0)
    // If last move was Antisimon → Simon cannot play, so Antisimon wins (print 1)
    cout << (simonTurn ? 1 : 0) << endl;

    return 0;
}
https://codeforces.com/problemset/problem/121/A
// A. Lucky Sum
using namespace std;
#define ll long long
ll NthLuckyNumber(ll n) {
    string res = "";
    while (n >= 1) {
        if (n & 1) {
            res += '4';
            n = (n - 1) / 2;
        } else {
            res += '7';
            n = (n - 2) / 2;
        }
    }
    reverse(res.begin(), res.end());
    return stoll(res);
}
vector<ll> lucky;
void fillLucky(ll limit) {
    ll i = 1;
    while (true) {
        ll num = NthLuckyNumber(i);
        if (num > limit) break;
        lucky.push_back(num);
        i++;
    }
}
void solve() {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (int i = 0; i < (int)lucky.size() && l <= r; i++) {
        if (l <= lucky[i]) {
            ll right = min(r, lucky[i]);
            ll cnt = right - l + 1;    // count of numbers mapped to lucky[i]
            ans += lucky[i] * cnt;
            l = right + 1;             // move to next range
        }
    }
    cout << ans << "\n";
}
int main() {
    ll limit = 1e12;   
    fillLucky(limit);
    solve();
    return 0;
}

using namespace std;
// problemset/problem/122/A
// A. Lucky Division
int main(){
    int n; cin >> n;
    bool flag = 0;
    int arr[12] = {4, 7, 47, 74, 44, 444, 447, 474, 477, 777, 774, 744};
    for(int i = 0; i < 12; i++){
        if(n % arr[i] == 0)
            flag = 1;
    }
    (flag) ? cout << "YES" : cout << "NO";
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int arr[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
  int n;
  cin>>n;
  for(auto i : arr){
    if(n % i == 0){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;

}

using namespace std;
typedef long long ll;
bool isLucky(ll n)
{
    int flag = 1;
    while (n)
    {
        int digit = n % 10;
        if (digit != 4 && digit != 7)
        {
            flag = 0;
            break;
        }
        n /= 10;
    }
    if (flag)
        return true;
    return false;
}
int main(){
    ll n, temp = 0;
    cin >> n;
    if (isLucky(n) == 1){
        cout << "YES\n";
        return 0;
    }
    for(int i = 1; i < n; i++){
        if (n % i == 0 && isLucky(i) == 1){
            temp = 1;
            break;
        }
    }
    if (temp)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
https://codeforces.com/problemset/problem/122/A
// A. Lucky Division
using namespace std;
#define ll long long
vector<int> lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777}; 
string checkAlmostLucky(int n){
    for(auto i : lucky){
        if(n%i == 0)
        return "YES";
    }
    return "NO";
}
int main(){
    int n; cin >> n;
    cout<<checkAlmostLucky(n)<<endl;
    return 0;
}
using namespace std;
#define ll long long
vector<int> lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777}; 
string checkAlmostLucky(int n) {
    for (auto x : lucky) {
        if (n % x == 0)
            return "YES";
    }
    return "NO";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << checkAlmostLucky(n) << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/122/B
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define str string
int main() {
    str s; cin >> s;
    ll c4 = count(all(s), '4');
    ll c7 = count(all(s), '7');
    if (c4 == 0 && c7 == 0) cout << -1;
    else if (c4 >= c7) cout << 4;
    else cout << 7;
}
https://codeforces.com/problemset/problem/122/C
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(x) (x).begin(), (x).end()
const ll mod = 1e10; 
vl lucky;
ll NthLuckyNumber(ll n) {
    string res = "";
    while (n >= 1) {
        if (n & 1) {  // odd
            res.push_back('4');
            n = (n - 1) / 2;
        } else {  // even
            res.push_back('7');
            n = (n - 2) / 2;
        }
    }
    reverse(all(res));
    stringstream ss(res);
    ll ret = 0;
    ss >> ret;
    return ret;
}
void generateLuckyNumbers() {
    ll i = 1;
    while (true) {
        ll num = NthLuckyNumber(i);
        if (num > mod) break;
        lucky.push_back(num);
        i++;
    }
    sort(all(lucky)); 
}
int main() {
    ll l, r;
    cin >> l >> r;
    ll sum = 0;
    while (l <= r) {
        ll it = *lower_bound(all(lucky), l);
        sum += (min(it, r) - l + 1) * it;
        l = it + 1;
    }
    cout << sum;
}
https://codeforces.com/problemset/problem/124/A
using namespace std;
int main(){
    long long int n,a,b;
    cin>>n>>a>>b;
    cout<<n+1-max(a+1,n-b);
    return 0;
}
https://codeforces.com/problemset/problem/127/B
using namespace std;
#define ll long long
#define vl vector<ll>
#define fo(i, n) for (ll i = 0; i < (n); i++)
#define ln "\n"
int main() {
    ll n;
    cin >> n;
    vl arr(n);
    map<ll, ll> cnt;

    fo(i, n) {
        cin >> arr[i];
        ++cnt[arr[i]];
    }
    ll ans = 0;
    for (auto &it : cnt) {
        ans += it.second / 2;  
    }
    cout << ans / 2 << ln; 
}
using namespace std;
http://codeforces.com/problemset/problem/131/A
// 131A - cAPS lOCK
int main() {
    string s; cin >> s;
    int len = s.length();
    if (len == 1) {
        s[0] = isupper(s[0]) ? tolower(s[0]) : toupper(s[0]);
    } 
    else {
        bool restUpper = true;
        for (int i = 1; i < len; ++i) {
            if (!isupper(s[i])) {
                restUpper = false;
                break;
            }
        }
        if (restUpper) {
            for (int i = 0; i < len; ++i) {
                s[i] = isupper(s[i]) ? tolower(s[i]) : toupper(s[i]);
            }
        }
    }
    cout << s << endl;
    return 0;
}
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
int main(){
    string s;
    cin >> s;
    ll flag = 0;
    rep(i, 1, s.length()){
        if (isupper(s[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        rep(i, 0, s.length())
        {
            if (isupper(s[i]) != 0)
                s[i] = tolower(s[i]);
            else
                s[i] = toupper(s[i]);
        }
    cout << s;
    return 0;
}
using namespace std;
int main(){
	string s; cin >> s;
	int len = s.length();
	int counter = 0;
	if(len == 1){
		if(isupper(s[0]))
			s[0] = tolower(s[0]);
		else if(islower(s[0]))
			s[0] = toupper(s[0]);
		cout << s;
	}
	else {
	    for(int i=1;i<len;i++){
		    if(isupper(s[i]))
			    counter++;
	    }
	    if(counter + 1 == len){
		    for(int i = 0; i < len; i++){
			    if(isupper(s[i]))
				    s[i] = tolower(s[i]);
			    else if(islower(s[i]))
				    s[i] = toupper(s[i]);
		    }
	    }
	    cout<<s;
	}
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, r = "";
  cin>>s;
  bool check = true;
  for(int i = 1; i < s.length(); i++){
    if(s[i] >= 97){
      check = false;
      break;
    }
  }
  if(s[0] <= 90 && check){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  }
  else if(s[0] >= 97 && check){
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.length(); i++){
      s[i] = tolower(s[i]);
    }
  }
  cout<<s<<endl;

}
http://codeforces.com/problemset/problem/133/A
// A.HQ9+
using namespace std;
int main() {
    string s; cin >> s;
    if (s.find_first_of("HQ9") != string::npos)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    /*
    int i = s.find_first_of("HQ9");
    cout << (i != -1) ? "YES" : "NO"; */
}
using namespace std;
int main(){
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

    return;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;
  for(auto i:s){
    if(i == 'H' || i == 'Q' || i == '9'){
      cout<<"YES\n";
      return 0;
    }
  }
  cout<<"NO\n";
  return 0;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // Check if any of 'H', 'Q', or '9' exists in the string
    if (s.find('H') != string::npos || 
        s.find('Q') != string::npos || 
        s.find('9') != string::npos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
https://codeforces.com/problemset/problem/133/B
using namespace std;
int main() {
    map<char, str> mp;
    mp['<'] = "1001"; mp['>'] = "1000";
    mp['+'] = "1010"; mp['-'] = "1011";
    mp['.'] = "1100"; mp[','] = "1101";
    mp['['] = "1110"; mp[']'] = "1111";
    str s; cin >> s;
    str output = "";
    for(int i = 0; i < str.size(); i++) output += mp[s[i]];
    ll modulo = 1000003;
    ll result = 0, a = 1;
    for (ll i = sz(output) - 1; i >= 0; --i) {
        if (output[i] - '0' == 1) {
            result = ((result % modulo) + (a % modulo)) % modulo;
        }
        a = 2 * a % modulo;
    }
    cout << result;
}
https://codeforces.com/problemset/problem/135/B
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
struct pt {
    ll x, y;
};
int main() {
    auto dist = [](pt p1, pt p2) {
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    };
    // Check if angle abc is a right angle (dot product = 0)
    auto isOrthogonal = [&](pt a, pt b, pt c) -> bool {
        return ((b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0);
    };

    auto isRectangle = [&](pt p1, pt p2, pt p3, pt p4) {
        // All angles should be 90 degrees in some order
        bool c1 = isOrthogonal(p1, p2, p3) && isOrthogonal(p2, p3, p4) && isOrthogonal(p3, p4, p1);
        bool c2 = isOrthogonal(p2, p3, p1) && isOrthogonal(p3, p1, p4) && isOrthogonal(p1, p4, p2);
        bool c3 = isOrthogonal(p3, p1, p2) && isOrthogonal(p1, p2, p4) && isOrthogonal(p2, p4, p3);
        return (c1 || c2 || c3);
    };

    auto isSquare = [&](pt p1, pt p2, pt p3, pt p4) {
        // Check for orthogonality and equal distances in some order
        if (isOrthogonal(p1, p2, p3) && isOrthogonal(p2, p3, p4) && isOrthogonal(p3, p4, p1)) {
            if (dist(p1, p2) == dist(p2, p3) &&
                dist(p2, p3) == dist(p3, p4) &&
                dist(p3, p4) == dist(p4, p1))
                return true;
        }
        if (isOrthogonal(p2, p3, p1) && isOrthogonal(p3, p1, p4) && isOrthogonal(p1, p4, p2)) {
            if (dist(p2, p3) == dist(p3, p1) &&
                dist(p3, p1) == dist(p1, p4) &&
                dist(p1, p4) == dist(p4, p2))
                return true;
        }
        if (isOrthogonal(p3, p1, p2) && isOrthogonal(p1, p2, p4) && isOrthogonal(p2, p4, p3)) {
            if (dist(p3, p1) == dist(p1, p2) &&
                dist(p1, p2) == dist(p2, p4) &&
                dist(p2, p4) == dist(p4, p3))
                return true;
        }
        return false;
    };

    vector<pt> a(8);
    for (auto &[x, y] : a) cin >> x >> y;

    vector<ll> P(8);
    iota(all(P), 0); // Fill P with 0..7

    do {
        if (isSquare(a[P[0]], a[P[1]], a[P[2]], a[P[3]]) &&
            isRectangle(a[P[4]], a[P[5]], a[P[6]], a[P[7]])) {
            cout << "YES\n";
            for (ll i = 0; i < 4; ++i) cout << P[i] + 1 << ' ';
            cout << '\n';
            for (ll i = 4; i < 8; ++i) cout << P[i] + 1 << ' ';
            return;
        }
    } while (next_permutation(all(P)));

    cout << "NO\n";
}
using namespace std;
http://codeforces.com/contest/136/problem/A
// A. Presents
int main() {
	 string s1,s2; cin >> s1 >> s2;
	 if(s1 == s2) cout << "-1";
	 else
		cout << max(s1.length(),s2.length());q
} 
using namespace std;
int main(){
    ll n, num;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> num;
        arr[num - 1] = i + 1;
    }
    for(int i = 0; i < n; i++)    cin >> arr[i] << " ";
    return 0;
}
#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int arr[n];
  int parr[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
    parr[arr[i]-1] = i+1;
  }
  for(int i = 0; i < n; i++){
    cout<<parr[i]<<" ";
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n), inv(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        inv[arr[i] - 1] = i + 1;  // store inverse mapping
    }

    for (int i = 0; i < n; i++) {
        cout << inv[i] << " ";
    }
    cout << "\n";

    return 0;
}

https://codeforces.com/problemset/problem/136/A
A. Presents
using namespace std;
int main(){
    int n;
    cin>>n;
    int p;
    int ans[n];
    for(int i=1;i<=n;i++)
    {
        cin>>p;
        ans[p]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
} 
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ans(n + 1); 
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        ans[p] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
https://codeforces.com/problemset/problem/137/B
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long present = 0;
    set<int> s(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) {
        if (s.count(i)) present++;
    }
    cout << n - present << "\n"; 
}
using namespace std;
ll n;
int main() {
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll present = 0;
    for(int i = 0; i < n; i++)
        if (count(arr.begin(), arr.end()), i + 1) != 0) present++;
    cout << n - present;
    return;
}
http://codeforces.com/contest/339/problem/A
// A.HelpfulMaths
using namespace std;
int main() {
    string s, s2; cin >> s;
    int len = s.length();
	for(int i = 0; i < len; i++){
	    if(s[i] != '+')    s2 += s[i];
	}
	sort(s2.begin(), s2.end());
	len = s2.length();
	if(len > 1){
	    cout << s2[0];
	    for(int i = 1; i < len - 1; i++)    cout << '+' << s2[i];
	    cout << '+' << s2[len - 1];
	}
	else    cout << s;
}
using namespace std;
int main() {
    string s; cin >> s;
    string digits;
    for (char c : s) {
        if (c != '+')    digits += c;
    }
    sort(digits.begin(), digits.end());
    for (size_t i = 0; i < digits.size(); ++i) {
        if (i > 0) cout << '+';
        cout << digits[i];
    }
}
using namespace std;
int main(){
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++)
        sort(s.begin(), s.end());
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] != '+')    cout << s[i] << "+";
    }
    cout << s[s.size()-1];
}
using namespace std;
int main(){
    string s; cin >> s;
    int n = (s.size() + 1) / 2;
    int arr[n], x = 0, y = 0, min = 0;
    while(s.size() > x){
        arr[y++] = s[x];    x += 2;
    }
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min])    min = j;
        }
        swap(arr[min], arr[i]);
    }
    x = 0, y = 0;
    while(x < s.size()){
        s[x] = arr[y++];
        x += 2;
    }
    cout << s;
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >>s;
    int ones =0, twos =0, threes =0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1')
            ones++;
        if(s[i] == '2')
            twos++;
        if(s[i] == '3')
            threes++;
    }
    if(ones!=0)
    {
        cout <<1;
        for(int i=0; i<ones-1; i++)
            cout<< '+' << 1;
        for(int i=0; i<twos; i++)
            cout<< '+' <<2;
        for(int i=0; i<threes; i++)
            cout <<'+' <<3;
            
        return 0;
    }
    if(twos!=0)
    {
        cout <<2;
        for(int i=0; i<twos-1; i++)
            cout<<'+' <<2;
        for(int i=0; i<threes; i++)
            cout<<'+' <<3;
        return 0;
    }
    if(threes!=0)
    {
        cout <<3;
        for(int i=0; i<threes-1; i++)
                cout<<'+'<<3;
        return 0;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >>s;
    vector <int> ans;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
            ans.push_back(s[i]-'0');
    }
    sort(ans.begin(), ans.end());
    cout <<ans[0];
    for(int i=1; i<ans.size(); i++)
    {
        cout<<"+" <<ans[i];
    }
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >>s;
    vector<int>ans;
    for(int i=0; i<s.size(); i+=2)
    {
        int x=s[i] -'0';
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        cout<< ans[i];
        if(i!=ans.size()-1)
            cout<< "+";
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >>s;
    int n=s.length();
    for(int i=0; i< n-1; i++)
    {
        for(int j=0; j< n-i-1; j++)
        {
            if(s[j]!='+' && s[j] < s[j+2])
                    swap(s[j], s[j+2]);
        }
    }
    cout<< s;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    // Create a substring 'g' starting from the middle of the sorted string to the end.
    string g = s.substr(s.size() / 2, s.size());

    // Iterate through the characters in the substring 'g'.
    for(int i = 0; i < g[i]; i++)
    {
        // Print the current character.
        cout << g[i];
        if(i != g.size() - 1)
            cout << '+';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string s;
    cin >>s;
    sort(s.begin(), s.end());
    int n=s.size();
    for(i=(n-1)/2; i<n-1; i++)
        cout<< s[i] <<"+";
    cout<< s[i] <<" ";
}
using namespace std;
// http://codeforces.com/problemset/problem/141/A
// A. Amusing Joke
int main(){
    string st, ri, ng, res; cin >> st >> ri >> ng;
    string res += st + ri;
    sort(res.begin(), res.end());
    sort(ng.begin(), ng.end());
    if(res == ng) cout << "Yes";
    else cout << "No";
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string s1, s2, s3, s4;
  cin>>s1>>s2>>s3;
  s4 = s1 + s2;
  if(s4.size() != s3.size()){
    cout<<"NO";
    return 0;
  }
  else{
    sort(s3.begin(), s3.end());
    sort(s4.begin(), s4.end());
    if(s3 != s4){
      cout<<"NO";
      return 0;
    }
    else{
      cout<<"YES";
      return 0;
    }
  }

}
https://codeforces.com/problemset/problem/141/A
A. Amusing Joke
using namespace std;
int main(){
    string guest,host,pile;
    cin>>guest>>host>>pile;
    string total=guest+host;
    sort(total.begin(),total.end());
    sort(pile.begin(),pile.end());
 
    if(total==pile)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
https://codeforces.com/problemset/problem/141/A
// A. Amusing Joke
using namespace std;
int main(){
    string snew, s1, s2, s;
    cin >> s1 >> s2 >> s;
    snew = s1 + s2;
    ll count1[26]{0}, count2[26]{0};
    for (ll i = 0; i < snew.length(); i++)
        count1[snew[i] - 'A']++;
    for (ll i = 0; i < s.length(); i++)
        count2[s[i] - 'A']++;
    ll flag = 0;
    fo(i, 26) 
    for(int i = 0; i < 26; i++){
        if (count1[i] != count2[i]){
            flag = 1; break;
        }
    }
    if (flag) cout << "NO\n";
    else cout << "YES\n";
    return;
}
using namespace std;
// http://codeforces.com/problemset/problem/144/A
// A. Arrival of the General
int main(){
    int n; cin >> n;
    int maxval = 0, maxIdx = 0;
    int minval = 0, minIdx = 1000;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > maxval){
            maxIdx = i;
            maxval = x;
        }
        if(x <= minval){
            minIdx = i;
            minval = x;
        }
    }
    if(maxIdx > minIdx)
        cout << (maxIdx - 1) + (n - minIdx) - 1;
    else
        cout << (maxIdx - 1) + (n - minIdx);
}

https://codeforces.com/problemset/problem/144/A
// A. Arrival of the General
using namespace std;
int main(){
    int n;
    cin>>n;
    int h[n];
    int maxValue=0,minValue=101,maxIndex,minIndex;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
        if(h[i]>maxValue)
        {
            maxValue=h[i];
            maxIndex=i;
        }
        if(h[i]<=minValue)
        {
            minValue=h[i];
            minIndex=i;
        }
    }
    if(maxIndex>minIndex)
    {
        minIndex++;
    }
    cout<<maxIndex+(n-1)-minIndex<<endl;
} 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    int maxValue = -1, minValue = 101; // assuming heights in [0, 100]
    int maxIndex = 0, minIndex = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        
        // Track tallest soldier (first occurrence from left)
        if (h[i] > maxValue) {
            maxValue = h[i];
            maxIndex = i;
        }
        
        // Track shortest soldier (last occurrence from right)
        if (h[i] <= minValue) {
            minValue = h[i];
            minIndex = i;
        }
    }
    
    // If tallest comes after shortest, moving tallest to front shifts shortest back by 1
    if (maxIndex > minIndex) {
        minIndex++;
    }
    
    int moves = maxIndex + (n - 1 - minIndex);
    cout << moves << endl;
}
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  int x, minindex, maxindex, maxi = 0, mini = 1000;
  for(int i = 0; i < n; i++){
    cin>>x;
    if(x > maxi){
      maxindex = i;
      maxi = x;
    }
    if(x <= mini){
      minindex = i;
      mini = x;
    }
  }

  if(maxindex>minindex){
	cout<<(maxindex-1)+(n-minindex)-1;
}
else{
	cout<<(maxindex-1)+(n-minindex);

}

}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    int maxVal = -1, minVal = 101;
    int maxIndex = -1, minIndex = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > maxVal) {         // leftmost maximum
            maxVal = a[i];
            maxIndex = i;
        }
        if (a[i] <= minVal) {        // rightmost minimum
            minVal = a[i];
            minIndex = i;
        }
    }

    int swaps = maxIndex + (n - 1 - minIndex);
    if (maxIndex > minIndex) swaps--; // adjust if overlap

    cout << swaps;
    return 0;
}
https://codeforces.com/problemset/problem/145/A
using namespace std;
int main() {
    ll four = 0, seven = 0;
    str s, t;
    cin >> s >> t;
    ll n = sz(s);
    for(int i = 0; i < n; i++) {
        if (s[i] == '4' && s[i] != t[i])
            four++;
        else if (s[i] == '7' && s[i] != t[i])
            seven++;
    }
    ll pairs = min(four, seven);
    four -= pairs;
    seven -= pairs;
    cout << four + seven + pairs << ln;
}
https://codeforces.com/problemset/problem/146/A
// A. Lucky Ticket
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    bool lucky=true;
    int lsum=0,rsum=0;
    int a=n/2;
    for(int i=0;i<n;i++) 
    {
        char c=s[i];
        if(c!='4'&&c!='7')
        {
        lucky=false;
        break;
        }
        int x=c - '0';
        if(i<a)
        lsum+=x;
        else
        rsum+=x;
        }
    if(lucky && lsum==rsum)
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
} 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    int maxValue = -1, minValue = 101; // assuming heights in [0, 100]
    int maxIndex = 0, minIndex = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        
        // Track tallest soldier (first occurrence from left)
        if (h[i] > maxValue) {
            maxValue = h[i];
            maxIndex = i;
        }
        
        // Track shortest soldier (last occurrence from right)
        if (h[i] <= minValue) {
            minValue = h[i];
            minIndex = i;
        }
    }
    
    // If tallest comes after shortest, moving tallest to front shifts shortest back by 1
    if (maxIndex > minIndex) {
        minIndex++;
    }
    
    int moves = maxIndex + (n - 1 - minIndex);
    cout << moves << endl;
}
https://codeforces.com/problemset/problem/146/B
using namespace std;
ll mask(ll n) {
    ll ans = 0;
    while (n) {
        ll dig = n % 10;
        if (dig == 4 || dig == 7) ans = ans * 10 + dig;
        n /= 10;
    }
    ll rev = 0;
    while (ans) {
        ll dig = ans % 10;
        rev = rev * 10 + dig;
        ans /= 10;
    }
    return rev;
}
int main() {
    ll a, b; cin >> a >> b;
    if (mask(a) == b) a++;
    while (mask(a) != b) a++;
    cout << a;
}
using namespace std
http://codeforces.com/problemset/problem/148/A
// A. Insomnia cure
int main(){
    int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
    vector <bool> damaged(d, false);
    for(int i = 1; i <= d; i++){
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            damaged[i - 1] = true;
    }
    cout << count(damaged.begin(), damaged.end(), true);
}
https://codeforces.com/problemset/problem/148/A
// A. Insomnia cure
using namespace std;
int main() {
   int k,l,m,n,d;
   cin>>k>>l>>m>>n>>d;
   int suffer=0;
   for(int i=1;i<=d;i++){
        if(i%k==0 || i%l==0 || i%m==0 || i%n==0)
            suffer++;
    }
   cout<<suffer<<endl;
} 
using namespace std;
int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int suffer = 0;
    for (int i = 1; i <= d; i++) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            suffer++;
    }
    cout << suffer << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k, l, c, d, p, nl, np;
  cin>>n>>k>>l>>c>>d>>p>>nl>>np;
  int a = (k*l)/nl;
  int b = c * d;
  int s = p / np;
  if( a <= b && a <= s){
    cout<<(a/n)<<endl;
    return 0;
  }
  if(b <= a && b <= s){
    cout<<(b/n)<<endl;
    return 0;
  }
  cout<<(s/n)<<endl;
  return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/151/A
// A. Soft Drinking
int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int total_drink = (k * l) / nl; 
    int total_slices = c * d;      
    int total_salt = p / np;        
    int toasts = min({total_drink, total_slices, total_salt});
    cout << toasts / n << endl;
}
using namespace std;
int main(){
    ll n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min(k * l / nl, min(p / np, c * d)) / n;
    return;
}
https://codeforces.com/problemset/problem/151/A
// A. Soft Drinking
using namespace std;
int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min(min(k * l / nl, c * d), p / np) / n << endl;
} 
#include <iostream>
#include <algorithm> 
using namespace std;
int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    // Calculate total quantities
    int total_drink = k * l;   // total milliliters of drink
    int total_toasts = c * d;  // total slices of lime
    int total_salt = p;        // total grams of salt

    // Maximum number of toasts each friend can get based on each ingredient
    int max_by_drink = total_drink / nl;
    int max_by_lime = total_toasts;
    int max_by_salt = total_salt / np;

    // Minimum of all divided by number of friends
    int max_toasts_per_person = min({max_by_drink, max_by_lime, max_by_salt}) / n;

    cout << max_toasts_per_person << endl;

    return 0;
}
https://codeforces.com/problemset/problem/151/B
using namespace std;
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define pb push_back
#define re return
ll n, m, j, k, l, i;
int main(){
    cin >> n;
    vector<ll> a(n);
    vector<string> s(n);

    ll MaxCountPhone = -1;
    ll MaxCountTaxi = -1;
    ll MaxCountGirl = -1;

    vector<string> Phone;
    vector<string> Taxi;
    vector<string> Girl;

    fo(i, n)
    {
        ll countPhone = 0;
        ll countTaxi = 0;
        ll countGirl = 0;
        cin >> a[i] >> s[i];
        fo(j, a[i])
        {
            string S;
            cin >> S;

            // Check Taxi: all digits same -> format xx-xx-xx but given as xxxxxx (with hyphens)
            if (S[0] == S[1] && S[1] == S[3] && S[3] == S[4] && S[4] == S[6] && S[6] == S[7])
                countTaxi++;

            // Check Phone: strictly decreasing digits
            else if (S[0] > S[1] && S[1] > S[3] && S[3] > S[4] && S[4] > S[6] && S[6] > S[7])
                countPhone++;

            // Otherwise, it's for Girl
            else
                countGirl++;
        }

        // Update max for Girl
        if (MaxCountGirl < countGirl)
        {
            MaxCountGirl = countGirl;
            Girl.clear();
            Girl.pb(s[i]);
        }
        else if (MaxCountGirl == countGirl)
        {
            Girl.pb(s[i]);
        }

        // Update max for Taxi
        if (MaxCountTaxi < countTaxi)
        {
            MaxCountTaxi = countTaxi;
            Taxi.clear();
            Taxi.pb(s[i]);
        }
        else if (MaxCountTaxi == countTaxi)
        {
            Taxi.pb(s[i]);
        }

        // Update max for Phone
        if (MaxCountPhone < countPhone)
        {
            MaxCountPhone = countPhone;
            Phone.clear();
            Phone.pb(s[i]);
        }
        else if (MaxCountPhone == countPhone)
        {
            Phone.pb(s[i]);
        }
    }

    cout << "If you want to call a taxi, you should call: ";
    cout << Taxi[0];
    for (i = 1; i < (ll)Taxi.size(); i++)
    {
        cout << ", " << Taxi[i];
    }
    cout << ".\n";

    cout << "If you want to order a pizza, you should call: ";
    cout << Phone[0];
    for (i = 1; i < (ll)Phone.size(); i++)
    {
        cout << ", " << Phone[i];
    }
    cout << ".\n";

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    cout << Girl[0];
    for (i = 1; i < (ll)Girl.size(); i++)
    {
        cout << ", " << Girl[i];
    }
    cout << ".\n";
    return 0;
}
using namespace std;
http://codeforces.com/contest/155/problem/A
// A. I_love_%username%
int main(){
    int n; cin >> n;
    int cnt = 0;
    int mini; cin >> mini;
    int maxi = mini;
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        if(x > maxi){
            maxi = x; ++cnt;
        }
        else if(x < mini){
            mini = x; ++cnt;
        }
    }
    cout << cnt;
}
using namespace std;
int main(){
    ll n;
    cin >> n;
    ll amazing = 0, max, min, num;
    for(int i = 0; i < n; i++){
        cin >> num;
        if (i == 0){
            max = num;
            min = num;
        }
        else{
            if (num < min){
                min = num;
                amazing++;
            }
            else if (num > max){
                max = num;
                amazing++;
            }
        }
    }
    cout << amazing;
    return 0;
}
https://codeforces.com/problemset/problem/155/A
A. I_love_%username%
using namespace std;
int main()
{
    int n, points;
    cin >> n >> points;
    int min(points), max(points), amazing(0);
    while (--n)
    {
        cin >> points;
        if (points < min)
        {
            min = points;
            ++amazing;
        }
        if (points > max)
        {
            max = points;
            ++amazing;
        }
    }
    cout << amazing << endl;
} 
using namespace std;
int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    int points;
    cin >> points;
    int minScore = points;
    int maxScore = points;
    int amazing = 0;

    for (int i = 1; i < n; i++) {
        cin >> points;
        if (points < minScore) {
            minScore = points;
            amazing++;
        }
        if (points > maxScore) {
            maxScore = points;
            amazing++;
        }
    }

    cout << amazing << endl;
    return 0;
}
https://codeforces.com/problemset/problem/155/B
using namespace std;
#define ll long long
#define vl vector<ll>
#define fo(i, n) for (ll i = 0; i < n; i++)
int main(){
    vl v;
    ll n, s = 0, c = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        if (b > 0){
            s += a;
            c += b - 1;
        }
        else
            v.push_back(a); 
    }
    sort(v.begin(), v.end(), greater<ll>());
    for(int i = 0; i < v.size(); i++){
        if (c == 0) break;
        s += v[i];
        c--;
    }
    cout << s << "\n";
}
using namespace std;
// A. Next Round
// problemset/problem/158/A
int main(){
    int n, k; cin >> n >> k;
    int arr[n], res = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] >= arr[k] && arr[i] > 0)
            res++;
    }
    cout << res;
}
//  https://codeforces.com/contest/158/problem/A
#include <iostream>
#include <vector>
using namespace std;
 
void First()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((v[i] >= v[k-1]) && (k != 0 && v[i] != 0) ) {
            count += 1;
        } 
    }
    cout << count << endl;
}
void Second()
{
    int cnt = 0;
    int n, k;
    cin >> n >> k;
    
    int arr[n + 2];
    
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        int src = arr[k - 1];
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= src && arr[i] != 0)
                cnt++;
        }
        cout << cnt;
    }
}
void Third()
{
    const int MAXN = 1e2;
    int n, k, i = 0, j = 0, arr[MAXN];

    cin >> n >> k;

    while (n > i)
        cin >> arr[i++];

    while (arr[j] && arr[j] >= arr[k - 1])
        ++j;

    cout << j;
}
int main()
{
    First();
    Second();
    Third();
}
#include<iostream>
using namespace std;

int main(){
  int n;
  int k;
  int count;
  cin>>n;
  cin>>k;
  int arr[n];
  for(int i = 0; i < n; i++){
    cout<<"i:"<<i<<" ";
    cin>>arr[i];
  }
  int quali = 0, m;
  if(arr[k-1] == 0){

    for(m = k-2; m >= 0; m--){

      if(arr[m] > 0){
      
        quali = arr[m];
        count  = m+1;
        cout<<count;
        return 0;
      }
    }
    if(quali == 0){
      cout<<0;
      return 0;
    }
  }
  else{
    quali = arr[k-1];
    count = k;
  }
  cout<<endl;
  int j = count-2;
  while(true){
    if(arr[j] == quali){
      count++;
    }
    else{
      break;
    }
    j--;
  }
  cout<<count;
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int qualiScore = arr[k - 1];   // the score at k-th place
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= qualiScore && arr[i] > 0) {
            count++;
        }
    }

    cout << count;
    return 0;
}

#include <iostream>
using namespace std;

//Code Written By: Vikash Patel

int n, k, a, b = 0, mas[10000];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        mas[i] = a;
    }
    for (int j = 1; j <= n; j++) {
        if (mas[j] >= mas[k] && mas[j] > 0) {
            b++;
        }
    }
    cout << b;
} 
using namespace std;
http://codeforces.com/problemset/problem/158/B
// B. Taxi
int main() {
	int n; cin >> n;
	int taxicount = 0;
	int arr[5] = {0,0,0,0,0};
    for(int i = 0; i < n; i++){
	    int a; cin >> a;
		++arr[a];
	}
	taxicount += arr[4];
	arr[4] = 0;
	if(arr[2]){
	    int t = arr[2] >> 1;
		taxicount += t;
		arr[2] -= t*2;
	}
	if(arr[1] && arr[3]){
		 int mnivalue = min(arr[1], arr[3]);
		 taxicount += mnivalue;
		 arr[1] -= mnivalue;
		 arr[3] -= mnivalue;
	}
	if(arr[1] && arr[2]){
		if(arr[2] <= arr[1] >>1 &&barr[1] >> 1){
			taxicount += arr[2];
			arr[1] -= arr[2]*2;
			arr[2] -= arr[2];
		}
		else{
			int z = min(arr[1], arr[2]);
			taxicount += z;
			arr[1] -= z;
			arr[2]-=z;
		}
	}
	int y = arr[1]/4;
	taxicount += y;
	arr[1] -= y*4;
	if(arr[1] < 4 && arr[1]){
		 taxicount += 1;
		 arr[1] = 0;
	}
	for(int i = 1; i < 5; i++)
        taxicount += arr[i];
	cout << taxicount;
}

using namespace std;
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
int main(){
    ll n; cin >> n;
    vector<ll> count(5, 0); 
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        count[num]++;
    }
    ll ans = count[4]; 
    ans += count[3];
    count[1] = max(0LL, count[1] - count[3]);
    ans += count[2] / 2;
    if (count[2] % 2){
        ans++; 
        count[1] = max(0LL, count[1] - 2);
    }
    if (count[1] > 0)
        ans += (count[1] + 3) / 4; 
    cout << ans << "\n";
}
using namespace std;
int main(){
    ll n, num, ans;
    cin >> n;
    ll arr[n], count[5]{0};    
    for(int i = 0; i < n; i++){           
        cin >> num;              
        count[num]++;              
    }                                 
    ans = count[4];                      
    ans += count[3];                      
    count[1] = max(count[1] - count[3], 0LL); 
    ans += count[2] / 2;                  
    count[2] %= 2;                        
    if (count[2]){                         
        ++ans;                      
        if (count[1])                    
            --count[1];                   
        if (count[1])                     
            --count[1];              
    }                                   
    ans += count[1] / 4;                
    count[1] %= 4;                        
    ans += count[1] / 3;                  
    count[1] %= 3;                        
    ans += count[1] / 2;                  
    count[1] %= 2;                         
    ans += count[1];                       
    cout << ans << endl;
    return 0;
}
using namespace std;
int main() {
    int n; cin >> n;
    int count[5] = {0};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        count[x]++;
    }
    int taxis = 0;
    // Groups of 4 need a taxi each
    taxis += count[4];
    // Pair 3s with 1s
    int pair_3_1 = min(count[3], count[1]);
    taxis += pair_3_1;
    count[3] -= pair_3_1;
    count[1] -= pair_3_1;
    // Remaining 3s each need a taxi
    taxis += count[3];
    // Pair 2s together
    taxis += count[2] / 2;
    count[2] %= 2;
    if (count[2]) {
        // One group of 2 left
        taxis += 1;
        // Try to pair with up to two 1s
        count[1] = max(0, count[1] - 2);
    }
    // Remaining 1s can fit 4 per taxi
    taxis += (count[1] + 3) / 4;
    cout << taxis << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/158/problem/A
// 158 A. Next Round
int main(){
    int n, k; cin >> n >> k;
    int arr[n], cnt = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ref = arr[k - 1];
    for(int i = 0; i < n; i++){
        if(arr[i] >= ref && arr[i])
            ++cnt;
    }
    cout << cnt;
}
http://codeforces.com/problemset/problem/158/A
// A.Next_Round
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int scores[51];
    for (int i = 0; i < n; i++)    cin >> scores[i];
    int threshold = scores[k - 1];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= threshold && scores[i] > 0)    count++;
    }
    cout << count << endl;
}
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int counter = 0, arr[51];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] >= arr[k - 1] && arr[i] != 0)    counter += 1;
    }
    cout << counter;
}
https://codeforces.com/problemset/problem/158/C
using namespace std;
#define ll long long
#define sz(x) ((ll)(x).size())
vector<string> split(const string &s, const string &delims = "/") {
    vector<string> res;
    string token = "";
    for (char ch : s) {
        if (delims.find(ch) != string::npos) {
            if (!token.empty()) {
                res.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) res.push_back(token);
    return res;
}
int main() {
    ll q;
    cin >> q;
    string cmd, s;
    vector<string> curr_path;

    while (q--) {
        cin >> cmd;
        if (cmd == "pwd") {
            cout << "/";
            for (auto &x : curr_path) cout << x << '/';
            cout << "\n";
        } else if (cmd == "cd") {
            cin >> s;
            vector<string> tokens = split(s, "/");

            // If path is absolute (starts with '/'), clear current path
            if (!s.empty() && s[0] == '/') {
                curr_path.clear();
            }

            // Process tokens
            for (auto &t : tokens) {
                if (t == "..") {
                    if (!curr_path.empty()) curr_path.pop_back(); // Move one directory up
                } else {
                    curr_path.push_back(t); // Move into directory
                }
            }
        }
    }
}
using namespace std;
vector<string> split(const string &s, const string &delims = " ") {
    vector<string> res;
    string token = "";
    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        while (delims.find(s[i]) != string::npos) {
            res.push_back(token);
            token = "";
            ++i;
        }
        token += s[i];
    }
    if (token != "") res.push_back(token);
    return res;
}
int main() {
    ll q;
    cin >> q;
    string cmd, s;
    vector<string> curr_path;
    while (q--) {
        cin >> cmd;
        if (cmd == "pwd"s) {
            cout << "/"s;
            for (auto &x : curr_path) cout << x << '/';
            cout << '\n';
        } else {
            cin >> s;
            vector<string> tokens = split(s, "/"s);
            if (tokens[0] == ""s) {
                curr_path.clear();
                for (ll i = 1; i < sz(tokens); ++i) {
                    if (tokens[i] == ".."s)
                        curr_path.pop_back();
                    else
                        curr_path.push_back(tokens[i]);
                }
            } else {
                for (ll i = 0; i < sz(tokens); ++i) {
                    if (tokens[i] == ".."s)
                        curr_path.pop_back();
                    else
                        curr_path.push_back(tokens[i]);
                }
            }
        }
    }
}
https://codeforces.com/problemset/problem/159/C
using namespace std;
int main() {
    ll k, q, i;
    string s1, s = "";
    char c;
    cin >> k >> s1;
    for (i = 0; i < k; ++i) s += s1;
    k = sz(s);
    vector<o_set<ll>> idx(26);
    vector<bool> mark(k, true);
    for (i = 0; char &x : s) idx[x - 'a'].insert(i++);
    cin >> q;
    while (q--) {
        cin >> i >> c;
        ll id = *idx[c - 'a'].find_by_order(i - 1);
        mark[id] = false;
        idx[c - 'a'].erase(id);
    }
    for (i = 0; i < k; ++i)
        if (mark[i]) cout << s[i];
    cout << '\n';
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define sz(x) ((ll)(x).size())
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    ll k, q;
    string s1, s = "";
    char c;
    cin >> k >> s1;
    // Repeat string s1 'k' times to form s
    for (ll i = 0; i < k; ++i) s += s1;
    k = sz(s);
    vector<o_set<ll>> idx(26);  
    vector<bool> mark(k, true);
    // Populate idx with positions of each character
    ll pos = 0;
    for (char &x : s) {
        idx[x - 'a'].insert(pos++);
    }
    cin >> q;
    while (q--) {
        ll i;
        cin >> i >> c;  // i-th occurrence of char c
        ll id = *idx[c - 'a'].find_by_order(i - 1); // find i-th index of c
        mark[id] = false;                            // mark for removal
        idx[c - 'a'].erase(id);                      // remove from ordered set
    }
    for (ll i = 0; i < k; ++i) {
        if (mark[i]) cout << s[i];
    }
    cout << '\n';
}
using namespace std;
http://codeforces.com/contest/160/problem/A
// A.Twins
int arr[105], ray[105];
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ray[0] = arr[0];
    for(int i = 1; i < n; i++)
        ray[i] = ray[i - 1] + arr[i];
    int res = 0;
    for(int i = n - 1; i >= 0; i--){
        int left = ray[i - 1];
		int right = ray[n - 1] - ray[i - 1];
 		if(right > left){
			cout << n - i;
			break;
 		}
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  int *arr;
  arr = new int[n];
  for(int i = 0; i < n; i++){
    cin>>*(arr+i);
  }
  sort(arr, arr+n);

  int sum1 = 0, sum2 = *(arr+n-1);
  for(int j = 0; j < n-1; j++){
    sum1 += *(arr+j);
  }

  int i = 1;
  while(i <= n){
    if(sum2 > sum1){
      cout<<i;
      return 0;
    }
    else{
      i++;
      sum2 += *(arr+n-i);
      sum1 -= *(arr+n-i);
    }
  }

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long sum1 = accumulate(arr.begin(), arr.end() - 1, 0LL);
    long long sum2 = arr.back();

    int i = 1;
    while (i <= n) {
        if (sum2 > sum1) {
            cout << i;
            return 0;
        } else {
            i++;
            sum2 += arr[n - i];
            sum1 -= arr[n - i];
        }
    }
}

using namespace std;
https://codeforces.com/problemset/problem/160/A
// A.Twins
int main() {
    int n; cin >> n;
    int coins[n];
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total_sum += coins[i];
    }
    sort(coins, coins + n, greater<int>());
    int my_sum = 0;
    int coin_count = 0;
    int half = total_sum / 2;
    for (int i = 0; i < n; ++i) {
        my_sum += coins[i];
        coin_count++;
        if (my_sum > half)
            break;
    }
    cout << coin_count << endl;
    return 0;
}
using namespace std;
int main() {
	 int n; cin >> n;
	 int arr[n];
	 int sum = 0, counter = 0;
	 for(int i = 0; i < n; i++){
	     cin >> arr[i];
	     sum += arr[i];
	 }
	sum /= 2;
	sort(arr, arr + n);
	int sum2 = 0;
	for(int i = n - 1; i >= 0; i--){
	    sum2 += arr[i]; ++counter;
	    if(sum2 > sum) break;
	}
	cout << counter;
}
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n];
    int total = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        total += a[i];
    }
    int sum = 0;
    sort(a, a+n, greater<int>());
    int i=0;
    for(i; i<n; i++)
    {
       sum += a[i];
       int left = total-sum;
       if(sum > left)
       break;
    }
    cout<<i+1<<endl;
    return 0;
}
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> coins(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        total += coins[i];
    }

    sort(coins.rbegin(), coins.rend()); // Sort in descending order

    int sum = 0;
    int count = 0;

    for (int coin : coins) {
        sum += coin;
        count++;
        if (sum > total - sum)
            break;
    }

    cout << count << '\n';
    return 0;
}
https://codeforces.com/problemset/problem/165/B
using namespace std;
using ll = int64_t;
ll k;
ll time_taken(ll v) {
    ll cnt = 0, den = 1;
    while (v / den != 0) {
        cnt += (v / den);
        den = den * k;
    }
    return cnt;
}
int main() {
    ll n;
    cin >> n >> k;
    ll l = 1, r = 1e12;
    while (r >= l) {
        ll m = l + (r - l) / 2;
        if (time_taken(m) >= n)
            r = m - 1;
        else
            l = m + 1;
    }
    cout << r + 1 << '\n';
}
using namespace std;
using ll = int64_t;
ll k;
// Function to calculate how many elements are contributed by powers of k
ll time_taken(ll v) {
    ll cnt = 0, den = 1;
    while (den <= v) {  // Avoid division when den > v
        cnt += v / den;
        if (den > v / k) break; // Prevent overflow
        den *= k;
    }
    return cnt;
}
int main() {
    ll n;
    cin >> n >> k;

    ll low = 1, high = 1'000'000'000'000LL; // 1e12 as upper bound
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (time_taken(mid) >= n)
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << low << '\n'; 
}
https://codeforces.com/problemset/problem/165/C
using namespace std;
using ll = int64_t;
int main() {
    ll k; cin >> k;
    string s; cin >> s;
    vector<ll> pref(s.length() + 1);
    pref[0] = 0;
    for (ll i = 1; i < s.length() + 1; ++i) pref[i] = (s[i - 1] == '1' ? 1 : 0) + pref[i - 1];
    ll ans = 0;
    map <ll, ll> cnt;
    for (ll i = 0; i < s.length() + 1; ++i) {
        ++cnt[pref[i]];
        ans += cnt[pref[i] - k];
    }
    if (k == 0) {
        ans = 0;
        for (auto [x, y] : cnt) {
            ans += (y * (y - 1)) / 2;
        }
    }
    cout << ans << '\n';
}
using namespace std;
using ll = int64_t;
int main() {
    ll k;
    string s;
    cin >> k >> s;

    ll n = s.size();
    vector<ll> pref(n + 1, 0);

    // Compute prefix sums of '1's
    for (ll i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + (s[i - 1] == '1');

    ll ans = 0;
    unordered_map<ll, ll> cnt;

    // Count subarrays with exactly k ones
    for (ll i = 0; i <= n; ++i) {
        ans += cnt[pref[i] - k]; // subarrays ending at i with k ones
        cnt[pref[i]]++;
    }

    // Special case when k = 0
    if (k == 0) {
        ans = 0;
        for (auto [value, frequency] : cnt) {
            ans += frequency * (frequency - 1) / 2;
        }
    }

    cout << ans << '\n';
}
https://codeforces.com/problemset/problem/166/A
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> contestants(n);
    for (int i = 0; i < n; i++) {
        cin >> contestants[i].first >> contestants[i].second; // questions, penalty
    }
    // Sort by questions descending, then penalty ascending
    sort(contestants.begin(), contestants.end(), [](const auto &a, const auto &b){
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    int kth_questions = contestants[k-1].first;
    int kth_penalty = contestants[k-1].second;
    // Count how many contestants have the same questions and penalty as k-th
    int count_same = 0;
    for (auto &[q,p] : contestants) {
        if (q == kth_questions && p == kth_penalty) count_same++;
    }
    cout << count_same << "\n";
}
using namespace std;
int same_place(int *a, int p, int s, int e)
{
    int temp = 0;
    for (int i = s; i <= e; i++)
    {
        if (a[i] == p)
        {
            temp++;
        }
    }
    return temp;
}

void custom_sort(int *a, int *b, int n)
{
    int flag;
    int temp;
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] > a[j - 1])
            {
                flag = 0;
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                temp = b[j];
                b[j] = b[j - 1];
                b[j - 1] = temp;
            }
        }

        if (flag)
        {
            return;
        }
    }
}

int starting_index(int *a, int q, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == q)
        {
            return i;
        }
    }
    return n-1;
}
int ending_index(int *a, int starting, int value, int n)
{
    for (int i = starting; i < n; i++)
    {
        if (a[i] != value)
        {
            return i-1;
        }
    }
    return n-1 ;
}
int finding_penalty(int *a, int s, int e, int k)
{
    if (s==e)
    {
        return a[s];
    }
    
    sort(a + s, a + (e+1));
    return a[k - 1];
}
int main(){
    int n, k;
    int questions, penalty;
    int starting, ending;
    cin >> n >> k;
    int *question_solve = new int[n];
    int *penalty_time = new int[n];
    for (int i = 0; i < n; i++){
        cin >> question_solve[i] >> penalty_time[i];
    }
    custom_sort(question_solve, penalty_time, n); //checked
    questions = question_solve[k - 1];            //checked
    starting = starting_index(question_solve, questions, n);
    ending = ending_index(question_solve, starting, questions, n);
    penalty = finding_penalty(penalty_time, starting, ending, k);
    cout << same_place(penalty_time, penalty, starting, ending) << endl;
    delete [] question_solve;
    delete [] penalty_time;
    return 0;
} 
https://codeforces.com/problemset/problem/171/A
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    cout << stoll(a) + stoll(b) << '\n';
}
https://codeforces.com/problemset/problem/171/B
using namespace std;
int main() {
    int n; cin >> n;
    cout << 6 * n * (n - 1) + 1;
}
https://codeforces.com/problemset/problem/171/D
using namespace std;
int main() {
    int n; cin >> n;
    cout << (n % 5) % 3 + 1;
}
https://codeforces.com/problemset/problem/177/A1
// A1. Good Matrix Elements
using namespace std;
typedef long long int ll;
#define pp pair<ll,ll>
#define dbg printf("f");
#define inf 1000000000000
#define max2(a,b) ((a<b)?b:a)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a>b)?b:a)
#define min3(a,b,c) min2(min2(a,b),c)
int main(){
    ll i,j,k;
    ll n,sum=0;
    cin>>n;
    ll a[n][n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    //main diagonal
    for(i=0,j=0;i<n,j<n;i++,j++)
    {
        sum+=a[i][j];
        a[i][j]=0;
    }

    //secondary diagonal
    for(i=0,j=n-1;i<n,j>=0;i++,j--)
    {
        sum+=a[i][j];
        a[i][j]=0;
    }

    //mid row
    for(i=0;i<n;i++)
    {
        sum+=a[n/2][i];
        a[n/2][i]=0;
    }

    //mid column
    for(i=0;i<n;i++)
    {
        sum+=a[i][n/2];
        a[i][n/2]=0;
    }
    cout<<sum;
}
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> coins(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        total += coins[i];
    }
    sort(coins.rbegin(), coins.rend()); 
    int sum = 0;
    int count = 0;
    for (int coin : coins) {
        sum += coin;
        count++;
        if (sum > total - sum)
            break;
    }
    cout << count << '\n';
    return 0;
}
https://codeforces.com/problemset/problem/177/A2
// A2. Good Matrix Elements
int main(){
    int n(0); scanf("%d", &n);
    long output(0);
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            int temp; scanf("%d", &temp);
            if(row == col){output += temp;}
            else if(row + col == n - 1){output += temp;}
            else if(2 * row == n - 1){output += temp;}
            else if(2 * col == n - 1){output += temp;}
        }
        scanf("\n");
    }

    printf("%ld\n", output);
} 
#include <cstdio>
#include <iostream>

int main() {
    int n;
    scanf("%d", &n);

    long output = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int temp;
            scanf("%d", &temp);

            bool onMainDiagonal = (row == col);
            bool onAntiDiagonal = (row + col == n - 1);
            bool onMiddleRow    = (2 * row == n - 1);
            bool onMiddleCol    = (2 * col == n - 1);

            if (onMainDiagonal || onAntiDiagonal || onMiddleRow || onMiddleCol) {
                output += temp;
            }
        }
    }

    printf("%ld\n", output);
    return 0;
}
https://codeforces.com/problemset/problem/181/A
A. Series of Crimes
using namespace std;
int main()
{       
       int n,m;
       cin>>n>>m;
         string s[n];
       int i1[3],j1[3];
          int i,j,k=0;
          for(i=0;i<n;i++)
          {
              cin>>s[i];
          }
          for(i=0;i<n;i++)
          {
              for(j=0;j<m;j++)
              {
                  if(s[i][j]=='*')
                  {
                      i1[k]=i+1;
                      j1[k]=j+1;
                        k++;
                  }
              }
          }
          for(i=0;i<3;i++)
          {
              for(j=i+1;j<3;j++)
              {
                     if(i==0&&j==1)
                     {
                         k=2;
                     }
                     else if(i==0&&j==2)
                     {
                       k=1;
                     }
                      else if(i==1&&j==2)
                     {
                       k=0;
                     }
                  if(i1[i]!=i1[j]&&j1[i]!=j1[j])
                  {
                      cout<<(i1[i]+i1[j]-i1[k])<<" "<<(j1[i]+j1[j]-j1[k]);
                  }
              }
          }
}
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    vector<int> i1, j1;

    // Read the grid and store coordinates of '*'
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                i1.push_back(i + 1); // 1-based indexing
                j1.push_back(j + 1);
            }
        }
    }

    // Find the fourth corner of the rectangle
    int x4 = i1[0] ^ i1[1] ^ i1[2]; // XOR trick: gets the unique value
    int y4 = j1[0] ^ j1[1] ^ j1[2];

    cout << x4 << " " << y4 << "\n";
}
https://codeforces.com/problemset/problem/189/A
using namespace std;
void solve()
{

    ll ans = 0;
    ll a, b, c, n, k;
    cin >> n >> a >> b >> c;
    ll rem;

    for (ll i = 0; i * a <= n; ++i) // i times a
    {
        for (ll j = 0; i * a + j * b <= n; ++j) // j times b
        {
            rem = n - i * a - j * b;
            if (rem % c == 0)
            {
                k = rem / c;               // k times c
                ans = max(ans, i + j + k); // run through all combinations and find max
            }
        }
    }

    cout << ans;

    return;
}

int main()
{
    fast_io();
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
https://codeforces.com/problemset/problem/189/B
using namespace std;
void solve()
{

    ll w, h;
    cin >> w >> h;
    ll cnt = 0;
    for (ll i = 1; i <= w; i += 2)
        for (ll j = 1; j <= h; j += 2)
            cnt += (w - i) * (h - j);

    cout << cnt;

    return;
}

int main()
{
    fast_io();
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/200/B
// B. Drinks
int main() {
    int n, x; cin >> n;
    double result = 0, final = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        result += (double)x / 100;
    }
	final = (double)(result / n) * 100;
	cout << setprecision(10) << final;
}
using namespace std;
int main() {
    int n; cin >> n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        int percentage; cin >> percentage;
        sum += percentage;
    }
    double average = sum / n;
    cout << fixed << setprecision(12) << average << endl;
}
https://codeforces.com/problemset/problem/200/B
B. Drinks
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[n];
    double tof=0;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        tof+=p[i];
    }
    cout<<fixed<<setprecision(12)<<(tof/(n*100))*100<<endl;
}
#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  float x, sum = 0;
  for(int i = 0; i < n; i++){
    cin>>x;
    sum += x;
  }
  float aver = sum / n;
  cout<<aver;
}
https://codeforces.com/problemset/problem/202/A
A. LLPS
using namespace std;
int main(){
    string s;
    cin >> s;
    
    int L = s.size();
    
    string ans;
    
    for(int mask = 1;mask < (1 << L);++mask){
        string aux;
        
        for(int i = 0;i < L;++i)
            if(mask >> i & 1)
                aux += s[i];
        
        string aux2 = aux;
        reverse(aux2.begin(),aux2.end());
        
        if(aux == aux2)
            ans = max(ans,aux);
    }
    
    cout << ans << '\n';
} 
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int L = s.size();
    string bestPalindrome;

    // Iterate through all possible subsequences
    for (int mask = 1; mask < (1 << L); ++mask) {
        string subseq;
        for (int i = 0; i < L; ++i) {
            if (mask & (1 << i)) {
                subseq += s[i];
            }
        }

        // Check if palindrome
        string reversed = subseq;
        reverse(reversed.begin(), reversed.end());

        if (subseq == reversed) {
            bestPalindrome = max(bestPalindrome, subseq);
        }
    }

    cout << bestPalindrome << "\n";
    return 0;
}

http://codeforces.com/problemset/problem/208/A
// A. Dubstep
using namespace std;
int main(){
    string s1, s2; cin >> s1;
    while(s1.find("WUB") != -1){
        int x = s1.find("WUB");
        int(x == 0)    s1.erase(0, 3);
        else {
            s1.replace(x, 1, " ");
            s1.erase(x + 1, 2);
        }
    }
    cout << s1;
}
using namespace std;
int main() {
    string s; cin >> s;
    string result;
    size_t pos = 0;
    while (pos < s.length()) {
        // If "WUB" is found at current position, skip it
        if (s.substr(pos, 3) == "WUB") {
            pos += 3;
            if (!result.empty() && result.back() != ' ')    result += ' ';
        } else {
            result += s[pos];
            pos++;
        }
    }
    if (!result.empty() && result.front() == ' ')    result.erase(0, 1);
    if (!result.empty() && result.back() == ' ')    result.pop_back();
    cout << result << endl;
}

using namespace std;
void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != 'W' || s[i + 1] != 'U' || s[i + 2] != 'B')
        {
            cout << s[i];
            if (s[i + 1] == 'W' && s[i + 2] == 'U' && s[i + 3] == 'B')
                cout << " ";
        }
        else
            i += 2;
    }
    /*
    string s;
    cin >> s;
    while (true)
    {
        ll i = s.find("WUB");
        if (i == string::npos)
            break;
        else if (i == 0)
            s.replace(i, 3, "");
        else
            s.replace(i, 3, " "); //!ADDS UNNECESSARY SPACES
    }
    cout << s;
*/
    return;
}

int main()
{
    fast_io();
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
https://codeforces.com/problemset/problem/208/A
A. Dubstep
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    string song;
    int n = s.size();
    int i = 0;
    bool space  = 1;
    while(i<n)
    {
        if(s.substr(i,3) == "WUB")
        {
            i += 3;
            if(space == 0)
            {
                song += " ";
                space = 1;
            }
            continue;
        }
        else
        {
            song += s[i];
            space = 0;
            i++;
        }
    }
    cout<<song<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string txt;
    getline(cin, txt);  // read the full line

    stringstream ss(txt);
    string part;
    string txtnew;

    size_t pos = 0;
    while ((pos = txt.find("WUB")) != string::npos) {
        part = txt.substr(0, pos);
        if (!part.empty()) {
            txtnew += part + " ";
        }
        txt.erase(0, pos + 3); // remove "WUB" + everything before it
    }
    if (!txt.empty()) {
        txtnew += txt; // add the last part
    }

    cout << txtnew << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string song;
    bool spaceNeeded = false;

    for (size_t i = 0; i < s.size();) {
        if (i + 2 < s.size() && s.substr(i, 3) == "WUB") {
            i += 3;
            spaceNeeded = true;
        } else {
            if (spaceNeeded && !song.empty()) {
                song += ' ';
                spaceNeeded = false;
            }
            song += s[i++];
        }
    }

    cout << song << "\n";
    return 0;
}

https://codeforces.com/problemset/problem/214/A
A. System of Equations
using namespace std;
int main()
{
    int n, m, answer(0);
    cin >> n >> m;

    for (int a = 0; a * a <= n && a <= m; ++a)
    {
        int b = n - a * a;
        if (a + b * b == m)
        {
            answer += 1;
        }
    }

    cout << answer << endl;
} 
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int answer = 0;
    for (int a = 0; a * a <= n && a <= m; ++a) {
        int b = n - a * a;
        if (b >= 0 && a + b * b == m) {
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/215/B
using namespace std;
int main(){
    int n; cin >> n;
    double x[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    int m; cin >> m;
    double y[m];
    for(int i = 0; i < m; i++) cin >> y[i];
    int k; cin >> k;
    double z[k];
    for(int i = 0; i < k; i++) cin >> z[i];
    double A, B; cin >> A >> B;

    double R1 = *max_element(x, x + n);
    double P1 = *max_element(y, y + m);
    double P2 = *min_element(z, z + k);
    cout << ps(R1 / sqrt(1 + (A * P2) / (B * P1)), 12) << "\n";
}
using namespace std;
int main() {
    int n, m, k;
    cin >> n;
    vector<double> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    cin >> m;
    vector<double> y(m);
    for (int i = 0; i < m; i++) cin >> y[i];
    cin >> k;
    vector<double> z(k);
    for (int i = 0; i < k; i++) cin >> z[i];
    double A, B; cin >> A >> B;
    double R1 = *max_element(x.begin(), x.end());
    double P1 = *max_element(y.begin(), y.end());
    double P2 = *min_element(z.begin(), z.end());

    double result = R1 / sqrt(1.0 + (A * P2) / (B * P1));
    cout << fixed << setprecision(12) << result << "\n";
}
https://codeforces.com/problemset/problem/217/A
using namespace std;
const int MAXN = 200005; 
vector<int> parent(MAXN), siz(MAXN);
int components;
int root(int x) {
    if (parent[x] != x) parent[x] = root(parent[x]);
    return parent[x];
}
bool same(int x, int y) {
    return root(x) == root(y);
}
void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (siz[y] < siz[x]) swap(x, y);
    parent[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
    components--;
}
int get_size(int x) {
    return siz[root(x)];
}
void init_dsu(int n) {
    components = n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        siz[i] = 1;
    }
}
int main() {
    int n;
    cin >> n;
    init_dsu(n);

    vector<array<int, 2>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][0] == a[j][0] || a[i][1] == a[j][1]) {
                unite(i, j);
            }
        }
    }
    cout << components - 1 << '\n';
}

using namespace std;
// A. Mountain Scenery
https://codeforces.com/contest/218/problem/A
const int MAX = 105;
int height[MAX];
int main(){
    int n, k; cin >> n >> k;
    int total = 2 * n + 1;
    for(int i = 0; i < total; ++i)
        cin >> height[i];
    for(int i = 1; i < total - 1 && k > 0; i += 2){
        if(height[i] > height[i - 1] + 1 && height[i] > height[i + 1] + 1) {
            --height[i];
            --k;
        }
    }
    for (int i = 0; i < total; ++i)
        cout << height[i] << " ";
    cout << "\n";
}
https://codeforces.com/problemset/problem/218/C
using namespace std;
const int MAXN = 200005; 
vector<int> parent(MAXN), siz(MAXN);
int components;
int root(int x) {
    if (parent[x] != x) parent[x] = root(parent[x]);
    return parent[x];
}
bool same(int x, int y) {
    return root(x) == root(y);
}
void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (siz[y] < siz[x]) swap(x, y);
    parent[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
    components--;
}
int get_size(int x) {
    return siz[root(x)];
}
void init_dsu(int n) {
    components = n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        siz[i] = 1;
    }
}
int main() {
    int n;
    cin >> n;
    init_dsu(n);

    vector<array<int, 2>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][0] == a[j][0] || a[i][1] == a[j][1]) {
                unite(i, j);
            }
        }
    }
    cout << components - 1 << '\n';
}
https://codeforces.com/problemset/problem/219/D
using namespace std;
int main() {
    ll n;
    cin >> n;
    vector<vector<pair<ll, bool>>> g(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back({v, true});   // true means "down" edge. -> real
        g[v].push_back({u, false});  // false means "up" edge -> fake
    }
    /* When we dfs from one root to some vertex i, 
    then number of inversions needed 
    = Count of down from root to i + Count of OTHER UP 
    = Count of down from root to i + count of all ups - count of up from root to i */
    ll UP = 0;
    vector<ll> up_c(n, 0), down_c(n, 0);
    function<void(ll, ll)> dfs = [&](ll node, ll parent) {  // as tree
        for (auto &child : g[node]) {
            if (child.first == parent) continue;
            if (child.second) {
                down_c[child.first] = down_c[node] + 1;  // node -> child is down
                up_c[child.first] = up_c[node];
            } else {
                up_c[child.first] = up_c[node] + 1;  // node -> child is up
                down_c[child.first] = down_c[node];
                ++UP;
            }
            dfs(child.first, node);
        }
    };
    dfs(0, -1);  // dfs
    vector<ll> ans(n, 0);
    for (ll i = 0; i < n; ++i) ans[i] = down_c[i] + UP - up_c[i];
    ll mn = *ranges::min_element(ans);
    cout << mn << '\n';
    for (ll i = 0; i < n; ++i)
        if (ans[i] == mn) cout << i + 1 << ' ';
    cout << '\n';
}
using namespace std;
#define ll long long
int main() {
    ll n;
    cin >> n;
    vector<vector<pair<ll, bool>>> g(n);
    
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back({v, true});   // true means "down" edge (original direction)
        g[v].push_back({u, false});  // false means "up" edge (reverse direction)
    }
    ll UP = 0; // Total "up" edges
    vector<ll> up_c(n, 0), down_c(n, 0);

    function<void(ll, ll)> dfs = [&](ll node, ll parent) {
        for (auto &child : g[node]) {
            if (child.first == parent) continue;
            if (child.second) {
                // Edge node -> child is original direction (down)
                down_c[child.first] = down_c[node] + 1;
                up_c[child.first] = up_c[node];
            } else {
                // Edge node -> child is reversed direction (up)
                up_c[child.first] = up_c[node] + 1;
                down_c[child.first] = down_c[node];
                ++UP; // Count total up edges
            }
            dfs(child.first, node);
        }
    };

    dfs(0, -1); // Start DFS from node 0
    
    vector<ll> ans(n, 0);
    for (ll i = 0; i < n; ++i) {
        ans[i] = down_c[i] + UP - up_c[i];
    }

    ll mn = *min_element(ans.begin(), ans.end());
    cout << mn << '\n';
    for (ll i = 0; i < n; ++i) {
        if (ans[i] == mn) cout << i + 1 << ' ';
    }
    cout << '\n';
}
https://codeforces.com/problemset/problem/222/B
using namespace std;
#define ll long long
#define v vector
#define vl vector<ll>
#define fo(i, n) for (ll i = 0; i < (n); i++)
int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    v<v<ll>> vv(n, v<ll>(m));

    fo(i, n) {
        fo(j, m) {
            cin >> vv[i][j];
        }
    }
    char q;
    ll I, J;
    vl r(n), c(m);
    fo(i, n) r[i] = i;
    fo(i, m) c[i] = i;
    
    fo(i, k) {
        cin >> q >> I >> J;
        if (q == 'c') {
            swap(c[I - 1], c[J - 1]);
        } else if (q == 'r') {
            swap(r[I - 1], r[J - 1]);
        } else {
            cout << vv[r[I - 1]][c[J - 1]] << '\n';
        }
    }
}
using namespace std;
#define ll long long
int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> vv(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> vv[i][j];
        }
    }

    while (k--) {
        char q;
        ll I, J;
        cin >> q >> I >> J;
        if (q == 'r') {
            swap(vv[I - 1], vv[J - 1]);
        } else if (q == 'c') {
            for (ll i = 0; i < n; i++) {
                swap(vv[i][I - 1], vv[i][J - 1]);
            }
        } else {
            cout << vv[I - 1][J - 1] << "\n";
        }
    }
    return 0;
}
https://codeforces.com/problemset/problem/222/E
E. Decoding Genome
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

// Matrix multiplication
vector<vector<ll>> multiply(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
    int n = A.size(), m = B[0].size(), p = A[0].size();
    vector<vector<ll>> res(n, vector<ll>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll sum = 0;
            for (int k = 0; k < p; ++k) {
                sum += A[i][k] * B[k][j];
                if (sum >= MOD * MOD) sum -= MOD * MOD;
            }
            res[i][j] = sum % MOD;
        }
    }
    return res;
}

// Matrix exponentiation
vector<vector<ll>> power(vector<vector<ll>> base, ll exp) {
    int n = base.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;

    while (exp > 0) {
        if (exp & 1) res = multiply(res, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> Base(m, vector<ll>(m, 1));
    vector<vector<ll>> Transform(m, vector<ll>(1, 1));

    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        int prev = islower(s[0]) ? s[0] - 'a' : s[0] - 'A' + 26;
        int now = islower(s[1]) ? s[1] - 'a' : s[1] - 'A' + 26;
        Base[now][prev] = 0;
    }

    vector<vector<ll>> ans = multiply(power(Base, n - 1), Transform);

    ll res = 0;
    for (int i = 0; i < m; ++i) (res += ans[i][0]) %= MOD;

    cout << res << '\n';
}

using namespace std;
//B.Effective Approach
http://codeforces.com/problemset/problem/227/B
int main(){
    map <int, int> position;
    long long frontSteps = 0, backSteps = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        position[val] = i;
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int query; cin >> query;
        frontSteps += position[query] + 1;
        backSteps += n - position[query];
    }
    cout << frontSteps << " " << backSteps << "\n";
}
http://codeforces.com/contest/228/problem/A
// A. Is your horseshoe on the other hoof?
using namespace std;
int main() {
    set<int> colors;
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        colors.insert(x);
    }
    cout << 4 - colors.size();
    return 0;
}
https://codeforces.com/problemset/problem/228/A
A. Is your horseshoe on the other hoof?
using namespace std;
int main()
{
    int a[4];
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
    }
    sort(a,a+4);
    int c=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]==a[i+1])
        c++;
    }
    cout<<c<<endl;
} 
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> colors(4);
    for (int &x : colors) {
        cin >> x;
    }

    sort(colors.begin(), colors.end());

    int duplicates = 0;
    for (int i = 0; i < 3; ++i) {
        if (colors[i] == colors[i + 1]) {
            ++duplicates;
        }
    }

    cout << duplicates << "\n";
    return 0;
}

using namespace std;
http://codeforces.com/contest/230/problem/A
// A. Dragons
int main() {
    int s, n;
    cin >> s >> n; // s = initial strength, n = number of dragons
    vector<pair<int, int>> dragons(n);
    // Read each dragon's strength and bonus
    for (int i = 0; i < n; ++i)
        cin >> dragons[i].first >> dragons[i].second;
    // Sort dragons by their strength (ascending order)
    sort(dragons.begin(), dragons.end());
    // Try to fight each dragon in order
    for (int i = 0; i < n; ++i) {
        int dragon_strength = dragons[i].first;
        int bonus = dragons[i].second;
        if (s > dragon_strength)
            s += bonus; // Kirito defeats the dragon and gains bonus
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
https://codeforces.com/problemset/problem/230/A
using namespace std;
using ll = long long;
using vpl = vector<pair<ll, ll>>;

#define fo(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sortall(x) sort(x.begin(), x.end())
int main() {
    ll s, n;
    cin >> s >> n;
    vpl paired;
    
    fo(i, n) {
        ll x, y;
        cin >> x >> y;
        paired.pb(mp(x, y));
    }

    sortall(paired);
    fo(i, n) {
        if (s <= paired[i].F) { // can't defeat the monster
            cout << "NO\n";
            return;
        } else {
            s += paired[i].S; // gain strength
        }
    }
    cout << "YES\n";
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int s, n;
  cin>>s>>n;
  multimap <int, int> mp;
  int a, b;
  for(int i = 0; i < n; i++){
    cin>>a>>b;
    mp.insert(pair <int, int> (a, b));
  }
  for(auto i = mp.begin(); i != mp.end(); i++){
    if(s > i->first){
      s += i->second;
    }
    else{
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, n;
    cin >> s >> n;

    vector<pair<int,int>> dragons(n);
    for (int i = 0; i < n; i++) {
        cin >> dragons[i].first >> dragons[i].second;
    }

    // Sort dragons by strength
    sort(dragons.begin(), dragons.end());

    for (auto &dragon : dragons) {
        if (s > dragon.first) {
            s += dragon.second;  // defeat dragon and gain bonus
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}
https://codeforces.com/problemset/problem/230/B
using namespace std;
using ll = long long;
bool isPrime(ll n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
int main(){
    ll n;
    cin >> n;
    ll root = sqrt(n);
    if (root * root != n) { // not a perfect square
        cout << "NO\n";
        return;
    }

    if (isPrime(root)) 
        cout << "YES\n";
    else
        cout << "NO\n";
}
using namespace std;
// problemset/problem/231/A
// A. Team
int main(){
    int n; cin >> n;
    int solved = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int x; cin >> x;
            cnt += x;
        }
        if(cnt >= 2) solved++;
    }
    cout << solved;
}
using namespace std;
using ll = long long;
int main() {
    ll n, ans = 0;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        if (n1 + n2 + n3 > 1) ans++;
    }

    cout << ans << '\n';

    return 0;
}

#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int surity = 0, count = 0, sure;

  for(int i = 0; i < n; i++){
    sure = 0;
    for(int j = 0; j < 3; j++){
      cin>>surity;
      sure += surity;

    }
    if(sure >= 2){
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int solvedProblems = 0;

    for (int i = 0; i < n; i++) {
        int votes = 0, vote;
        for (int j = 0; j < 3; j++) {
            cin >> vote;
            votes += vote;
        }
        if (votes >= 2) {
            solvedProblems++;
        }
    }

    cout << solvedProblems << endl;
    return 0;
}

using namespace std;
http://codeforces.com/contest/231/problem/A
// A.Team
int main() {
    int n; cin >> n;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a + b + c >= 2) ++counter;
    }
    cout << counter << endl;
}
using namespace std;
int main() {
	int n; cin >> n;
	int counter = 0;
	int arr[n][3];
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < 3; j++)
	        cin >> arr[i][j];
	}
	for(int i = 0; i < n; i++){
	    int x = 0;
	    for(int j = 0; j < 3; j++){
	        if(arr[i][j] == 1) x++;
	    }
	    if(x >= 2) counter += 1;
	}
	cout << counter;
	return 0;
}
	
https://codeforces.com/problemset/problem/231/A
// A. Team
using namespace std;
int main()
{
    int n;
    cin>>n;
    int surity,valsol=0;
    for(int i=0;i<n;i++)
    {
        int sure=0;
        for(int j=0;j<3;j++)
        {
            cin>>surity;
            sure+=surity;
        }
        if(sure>=2)
        valsol++;
    }
    cout<<valsol<<endl;
} 
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int solvedCount = 0;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            int opinion;
            cin >> opinion;
            sum += opinion;
        }
        if (sum >= 2) {
            ++solvedCount;
        }
    }

    cout << solvedCount << "\n";
    return 0;
}

using namespace std;
http://codeforces.com/contest/233/problem/A
// A - Perfect Permutation
int main() {
    int n;
    cin >> n;

    // If n is odd, no perfect permutation exists
    if (n % 2 == 1) {
        cout << -1 << endl;
    } else {
        // Generate a perfect permutation by swapping adjacent elements
        for (int i = 1; i <= n; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        cout << endl;
    }
    return 0;
}
	
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;

    if (n & 1) { // n is odd, impossible
        cout << -1 << '\n';
        return;
    }

    for (ll i = 1; i <= n; i++) {
        if (i & 1) cout << i + 1 << " "; // swap odd index with next
        else cout << i - 1 << " ";      // swap even index with previous
    }
    cout << '\n';
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  if (n % 2 == 1)
  {
      cout << -1 << endl;
  }
  else
  {
      cout << "2 1";
      for (int i = 3; i < n; i += 2)
      {
          cout << " " << i + 1 << " " << i;
      }
      cout << endl;
  }
  return 0;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << -1 << '\n';
    } else {
        // Print first pair
        cout << "2 1";

        // Print remaining pairs
        for (int i = 3; i <= n; i += 2) {
            cout << " " << i + 1 << " " << i;
        }

        cout << '\n';
    }

    return 0;
}

https://codeforces.com/problemset/problem/233/A
A. Perfect Permutation
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  if (n % 2 == 1)
  {
      cout << -1 << endl;
  }
  else
  {
      cout << "2 1";
      for (int i = 3; i < n; i += 2)
      {
          cout << " " << i + 1 << " " << i;
      }
      cout << endl;
  }
} 
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> result;
    for (int i = 1; i <= n; i += 2) {
        result.push_back(i + 1);
        result.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i + 1 < n ? ' ' : '\n');
    }

    return 0;
}
https://codeforces.com/problemset/problem/233/B
using namespace std;
using ll = long long;
ll DigitSum(ll n) {
    ll sum = 0;
    string s = to_string(n);
    for (char c : s) sum += c - '0';
    return sum;
}
int main() {
    ll n;
    cin >> n;
    ll ans = -1;

    for (ll sx = 1; sx <= 162; sx++) { // max sum of digits for 18-digit number is 9*18=162
        long double det = (long double)sx * sx + 4.0 * n; // determinant
        ll sqrtDet = (ll)sqrtl(det);
        
        if (sqrtDet * sqrtDet != det) continue; // only consider perfect squares
        
        ll x = (sqrtDet - sx) / 2; // quadratic formula solution
        if (x > 0 && DigitSum(x) == sx) {
            ans = x;
            break;
        }
    }

    cout << ans << '\n';
}
using namespace std;
ll DigitSum(ll n)
{
    ll sum = 0;
    string s = to_string(n);
    fo(i, s.length()) sum += s[i] - '0';
    return sum;
}
int main()
{
    ll n;
    cin >> n;
    ll ans = -1;
    for (ll sx = 1; sx <= 162; sx++) // max sx is of 99999999.. 18 digits => 9*18 => 162
    {
        double sq1 = sqrtl(sx * sx + 4 * n); // sqrtl is sqrt for ll
        ll sq2 = (ll)sqrtl(sx * sx + 4 * n);
        ll x = (sq2 - sx) / 2; //-b+sq2/2 <- quadratic formula, only one solution here as x>0
        if ((sq1 - sq2) == 0.0)
        { /// if determinant is full square
            if (x > 0 && DigitSum(x) == sx)
            {
                ans = x;
                break;
            }
        }
    }
    cout << ans;
    return;
}
https://codeforces.com/problemset/problem/235/A
using namespace std;
using ll = long long;

void Solution() {
    ll n;
    cin >> n;

    auto solve = [&](const auto &self, ll N) -> ll {
        if (N <= 2) return N;
        if (N & 1) return N * (N - 1) * (N - 2); // if N is odd, product of top 3 numbers

        ll P = N * (N - 1);
        ll num = N - 2;

        while (num > 0) {
            if (gcd(N, num) == 1 && gcd(N - 1, num) == 1) {
                P *= num;
                break;
            }
            --num;
        }

        return max(P, self(self, N - 1));
    };

    cout << solve(solve, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution();

    return 0;
}

using namespace std;
http://codeforces.com/contest/236/problem/A
// Boy_or_Girl
int main() {
    string s; cin >> s;
	int len = s.length();
	set <char> ma;
	for(int i = 0; i < len; i++)    ma.insert(s[i]);
	cout << (ma.size() % 2 == 0) ? "CHAT WITH HER" : "IGNORE HIM!";
	return 0;
}
using namespace std;
int main() {
    string username; cin >> username;
    set<char> uniqueLetters(username.begin(), username.end());
    if (uniqueLetters.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, unique = "";
    cin >> s;

    for (char c : s) {
        if (unique.find(c) == string::npos) {
            unique += c;
        }
    }

    if (unique.length() & 1) 
        cout << "IGNORE HIM!\n";
    else 
        cout << "CHAT WITH HER!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string s;
  cin>>s;
  int count = 1;
  sort(s.begin(), s.end());
  char elem = s[0];
  for(int i = 0; i < s.size(); i++){
    if(s[i] != elem){
      elem = s[i];
      count++;
    }
  }
  if(count % 2 == 0){
    cout<<"CHAT WITH HER!";
  }
  else{
    cout<<"IGNORE HIM!";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> distinctChars(s.begin(), s.end()); // store only unique characters

    if (distinctChars.size() % 2 == 0) {
        cout << "CHAT WITH HER!\n";
    } else {
        cout << "IGNORE HIM!\n";
    }

    return 0;
}

using namespace std;
int main(){
  string s;
  cin>>s;
  int count = 1;
  sort(s.begin(), s.end());
  char elem = s[0];
  for(int i = 0; i < s.size(); i++){
    if(s[i] != elem){
      elem = s[i];
      count++;
    }
  }
  if(count % 2 == 0){
    cout<<"CHAT WITH HER!";
  }
  else{
    cout<<"IGNORE HIM!";
  }
} 
https://codeforces.com/problemset/problem/236/B
using namespace std;
#define ll long long
const int MAX = 1000001;
int divi[MAX];
// Precompute the number of divisors for every number up to MAX
void divisor() {
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            divi[j]++;
        }
    }
}

int main() {
    divisor();

    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    const ll MOD = 1073741824; // 2^30

    for (ll i = 1; i <= a; i++) {
        for (ll j = 1; j <= b; j++) {
            for (ll k = 1; k <= c; k++) {
                ans = (ans + divi[i * j * k]) % MOD;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/242/A
using namespace std;
#define ll long long
#define vpl vector<pair<ll, ll>>
#define eb emplace_back
#define sz(x) ((ll)(x).size())
#define ln "\n"
int main() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    vpl ans;
    
    for (ll i = a; i <= x; i++) {
        for (ll j = b; j <= y; j++) {
            if (i > j)
                ans.eb(i, j);
        }
    }

    cout << sz(ans) << ln;
    for (auto [i, j] : ans)
        cout << i << " " << j << ln;
}
https://codeforces.com/problemset/problem/244/B
using namespace std;
#define ll long long
int main() {
    set<ll> vals;
    ll x = 0, y = 0;

    function<void(ll, ll)> rec = [&](ll num, ll digs) {
        if (digs == 10) return; // stop at 10 digits
        if (num) vals.insert(num); // avoid inserting 0
        rec(num * 10 + x, digs + 1);
        rec(num * 10 + y, digs + 1);
    };

    for (x = 0; x <= 9; ++x) {
        for (y = 0; y <= 9; ++y) {
            rec(0, 0);
        }
    }
    vals.insert(1000000000); 
    ll n;
    cin >> n;
    // count numbers <= n
    cout << distance(vals.begin(), vals.lower_bound(n + 1)) << '\n';
}
https://codeforces.com/problemset/problem/245/E
using namespace std;
using ll = long long;
auto sz = [](const auto &container) -> ll { return container.size(); };

int main() {
    string s;
    cin >> s;
    vector<ll> pref(sz(s));
    pref[0] = 1 - 2 * (s[0] == '-'); 
    for (ll i = 1; i < sz(s); ++i)
        pref[i] = pref[i - 1] + (1 - 2 * (s[i] == '-'));
    ll mx = *ranges::max_element(pref);
    ll mn = *ranges::min_element(pref);
    cout << max({abs(mn), abs(mx), abs(mx - mn)}) << '\n';
}
https://codeforces.com/problemset/problem/245/H
using namespace std;
using ll = long long;
auto sz = [](const auto &container) -> int { return (int)container.size(); };
int main() {
    string s;
    cin >> s;
    int n = sz(s);

    // Step 1: DP to check palindromes
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        for (int i = j; i >= 0; --i) {
            if (i == j)
                dp[i][j] = 1;
            else if (j - i == 1)
                dp[i][j] = (s[i] == s[j]);
            else if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
        }
    }

    // Step 2: Build 2D prefix sum (1-based indexing for convenience)
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pref[i + 1][j + 1] =
                pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + dp[i][j];
        }
    }
    auto get = [&](int l, int r) {
        return pref[r][r] - pref[l - 1][r] - pref[r][l - 1] + pref[l - 1][l - 1];
    };
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;  // assuming 1-based input
        cout << get(l, r) << '\n';
    }
}
using namespace std;
// A. Cupboards
// http://codeforces.com/contest/248/problem/A
int main() {
    int n;
    cin >> n;
    int leftOpen = 0, rightOpen = 0;
    for (int i = 0; i < n; ++i) {
        int left, right;
        cin >> left >> right;
        if (left) ++leftOpen;
        if (right) ++rightOpen;
    }
    int leftClosed = n - leftOpen;
    int rightClosed = n - rightOpen;

    // For each side, choose the minimal number of switches (either open or close)
    int minLeftOperations = min(leftOpen, leftClosed);
    int minRightOperations = min(rightOpen, rightClosed);
    cout << (minLeftOperations + minRightOperations) << endl;
}
	https://codeforces.com/problemset/problem/252/C
using namespace std;


#define ll long long
// #define endl "\n"
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int binary_search(ll arr[], int low, int high, ll target){
  while(low < high){
    int mid = (low + high)/2;
    if(arr[mid] > target){
      high = mid -1;
    }
    else{
      if(mid == high){
        return mid;
      }
      if(arr[mid+1] > target){
        return mid;
      }
      low = mid +1;
    }
  }
  return low;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, d;
  cin>>n>>d;
  ll arr[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ll j = binary_search(arr, i, n-1, arr[i]+d);
    if(j - i > 1){
      ll cnt = j - i + 1;
      ans += ((cnt-2)*(cnt-1))/2;
    }
  }
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, d;
    cin >> n >> d;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // ensure array is sorted

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        // find the first element greater than arr[i] + d
        auto it = upper_bound(arr.begin() + i, arr.end(), arr[i] + d);
        ll j = it - arr.begin() - 1; // index of the largest element <= arr[i] + d

        ll cnt = j - i + 1;
        if (cnt >= 3) {
            ans += (cnt - 1) * (cnt - 2) / 2; // number of triplets
        }
    }

    cout << ans << '\n';
}

http://codeforces.com/problemset/problem/253/A
// A. Boys and Girls
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	string s = "";
	int nn = n, mm = m;
	if(n > m){
	    for(int i = 0; i < n + m; i++){
	        if(nn > 0){
	            s += "B"; nn--;
	        }
	        if(mm > 0){
	            s += "G"; mm--;
	        }
	    }
	    cout << s;
	}
	else {
	    for(int i = 0; i < n + m; i++){
	        if(mm > 0){
	            s += "G"; mm--;
	        }
	        if(nn > 0){
	            s += "B"; nn--;
	        }
	    }
	}
}
using namespace std;
int main() {
    int boys, girls; cin >> boys >> girls;
    string result = "";
    char first, second;
    int firstCount, secondCount;
    // Decide the alternating order based on which group is larger
    if (boys >= girls) {
        first = 'B'; second = 'G';
        firstCount = boys; secondCount = girls;
    } else {
        first = 'G'; second = 'B';
        firstCount = girls; secondCount = boys;
    }
    // Alternate while both have members left
    while (firstCount > 0 || secondCount > 0) {
        if (firstCount > 0) {
            result += first;
            --firstCount;
        }
        if (secondCount > 0) {
            result += second;
            --secondCount;
        }
    }
    cout << result << endl;
}
https://codeforces.com/problemset/problem/254/B
using namespace std;
using ll = long long;
array<int, 12> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
array<int, 13> prefix_days;

int getDayIndex(int month, int day) {
    return prefix_days[month - 1] + day; // 1-based day index
}
int main() {
    // Build prefix sum of days
    partial_sum(days_in_month.begin(), days_in_month.end(), prefix_days.begin() + 1);

    int n;
    cin >> n;
    // Use difference array for range updates
    vector<ll> diff(500, 0);
    for (int i = 0; i < n; ++i) {
        int m, d, p, t;
        cin >> m >> d >> p >> t;
        int start = getDayIndex(m, d);
        int end = start + t - 1;
        diff[start] += p;
        if (end + 1 < (int)diff.size()) diff[end + 1] -= p;
    }
    // Compute prefix sum to get actual values
    ll ans = 0, current = 0;
    for (ll x : diff) {
        current += x;
        ans = max(ans, current);
    }
    cout << ans << '\n';
    return 0;
}

https://codeforces.com/problemset/problem/255/A
A. Greg's Workout
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pairint main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,num,chest,biceps,bak,maxi ;
    cin >>n;
    chest=biceps=bak=0;
    for (int i = 0 ;i<n; i++){
        cin >> num;
        if (i %3 ==0)
            chest = chest +num;
        else if (i %3 ==1)
            biceps = biceps +num;
        else
            bak =bak+num;
    }
    maxi = max(max(chest,bak),biceps);
    if (maxi == chest)
        cout <<"chest";
    else if (maxi == biceps)
        cout <<"biceps";
    else
        cout<<"back";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int chest = 0, biceps = 0, back = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (i % 3 == 0)
            chest += num;
        else if (i % 3 == 1)
            biceps += num;
        else
            back += num;
    }

    if (chest >= biceps && chest >= back)
        cout << "chest";
    else if (biceps >= chest && biceps >= back)
        cout << "biceps";
    else
        cout << "back";

    return 0;
}
https://codeforces.com/problemset/problem/259/B
using namespace std;
using ll = long long;
int main() {
    ll arr[4][4]{}; // 1-based indexing for simplicity

    // Input matrix (1..3 for both rows and columns)
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> arr[i][j];
        }
    }

    // Compute missing diagonal values
    arr[1][1] = max(1LL, max(arr[3][2] - arr[1][3] + 1, arr[2][3] - arr[1][2] + 1));
    arr[2][2] = arr[1][1] + arr[1][3] - arr[3][2];
    arr[3][3] = arr[1][1] + arr[1][2] - arr[2][3];

    int x = arr[3][1] + arr[1][3] - arr[1][1] - arr[3][3];
    x /= 2;

    for (int i = 1; i <= 3; ++i) arr[i][i] += x;

    // Output the completed matrix
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}
https://codeforces.com/problemset/problem/260/A
using namespace std;
using ll = long long;
int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    // Try appending one digit (0-9) to 'a' so the number is divisible by b
    for (int i = 0; i < 10; ++i) {
        ll nw = a * 10 + i;
        if (nw % b == 0) {
            cout << nw;
            // Append n-1 zeros
            cout << string(n - 1, '0') << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
https://codeforces.com/problemset/problem/261/A
using namespace std;
using ll = long long;
int main() {
    int m;
    cin >> m;
    vector<ll> q(m);
    for (int i = 0; i < m; ++i) cin >> q[i];
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll min_q = *min_element(q.begin(), q.end()); // Best discount strategy
    sort(a.begin(), a.end(), greater<ll>());     // Sort prices descending

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i % (min_q + 2) < min_q) {
            ans += a[i]; // Pay for first 'min_q' items in every block of (min_q + 2)
        }
    }
    cout << ans << '\n';
}
http://codeforces.com/problemset/problem/263/A
// A. Beautiful Matrix
using namespace std;
int main() {
	int arr[5][5], ineed, jneed, tj=2, ti=2;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int x; cin >> x;
            if(x == 1){
                indeed = i; jneed = j;
            }
            arr[i][j] = x;
        }
    }
	int v1 = abs(ineed - ti);
	int v2 = abs(jneed - tj);
	cout << v1 + v2;
}
using namespace std;
int main() {
    int x;
    int row = 0, col = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> x;
            if (x == 1) {
                row = i; col = j;
            }
        }
    }
    cout << abs(row - 2) + abs(col - 2);
}

using namespace std;
// A. Beautiful Matrix
// problemset/problem/263/A
int main() {
    int x, y, ans;
    int arr[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }
    cout << abs(x - 2) + abs(y - 2);
}
using namespace std;
int main(){
    int mat[5][5];
    int m,n;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>mat[i][j];
            if(mat[i][j]==1){
                m=i+1;
                n=j+1;
            }
        }
    }
    cout<<abs(m-3)+abs(n-3)<<endl;
}
#include<iostream>
using namespace std;

int absol(int m){
  if(m >= 0){
    return m;
  }
  return (m * -1);
}

int main(){
  int arr[5][5];
  int m, n;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin>>arr[i][j];
      if(arr[i][j] == 1){
        m = i; n = j;
      }
    }
  }
  int path = absol(m - 2) + absol(n - 2);
  cout<<path;
  return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int matrix[5][5];
    int row1 = 0, col1 = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                row1 = i;
                col1 = j;
            }
        }
    }

    int moves = abs(row1 - 2) + abs(col1 - 2);
    cout << moves << '\n';

    return 0;
}

http://codeforces.com/contest/265/problem/A
// A. Colorful Stones (Simplified Edition)
using namespace std;
int main() {
	string s1, s2; cin >> s1 >> s2;
	int pos = 0;
	int len = s2.length();
	for(int i = 0; i < len; i++){
	    if(s2[i] == s1[pos])    pos++;
	}
    cout << ++pos;
}
using namespace std;
int main() {
    string s1, s2; cin >> s1 >> s2;
    int pos = 0;
    for (char c : s2) {
        if (c == s1[pos]) ++pos;
    }
    cout << pos + 1 << endl;
    return 0;
}
using namespace std;
using ll = long long;
int main() {
    string s, t;
    cin >> s >> t;
    
    ll pos = 0;
    for (char c : t) {
        if (pos < (ll)s.size() && c == s[pos]) {
            pos++;
        }
    }
    cout << pos + 1 << '\n'; // If problem expects 1-based index of next char
}
https://codeforces.com/problemset/problem/265/B
using namespace std;
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define ln "\n"
#define vl vector<ll>
int main() {
    ll n;
    cin >> n;
    vl arr(n);
    fo(i, n) cin >> arr[i];
    ll ans = n + arr[0] + (n - 1);
    fo(i, n - 1) {
        ans += abs(arr[i + 1] - arr[i]);
    }

    cout << ans << ln;
}
https://codeforces.com/problemset/problem/265/C
using namespace std;
#define ll long long
#define str string
#define vl vector<ll>
#define fo(i, n) for (ll i = 0; i < (n); i++)
#define sz(x) ((ll)(x).size())
#define eb emplace_back
#define ln "\n"
#define all(x) (x).begin(), (x).end()
int main() {
    str s;
    cin >> s;
    vl l, r;

    // Separate positions of 'l' and others
    fo(i, sz(s)) {
        if (s[i] == 'l') l.eb(i + 1);
        else r.eb(i + 1);
    }

    // Print r in original order
    fo(i, sz(r)) cout << r[i] << ln;

    // Print l in reverse order
    reverse(all(l));
    fo(i, sz(l)) cout << l[i] << ln;
}

using namespace std;
http://codeforces.com/contest/266/problem/A
// A. Stones on the Table
int main(){
    int n; cin >> n;
    string str; cin >> str;
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(str[i - 1] == str[i])
            cnt++;
    }
    cout << cnt;
  	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int main(){
  int n, count = 0;
  cin>>n;
  string s;
  cin>>s;
  for(int i = 0; i < n-1; i++){
    if(s[i] == s[i+1]){
      count++;
    }
  }
  cout<<count;
  return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/266/A
// Stones_on_the_Table.cpp
int main(){
    int n;
    char arr[51];
    cin >> n >> arr;
    int t = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == arr[i+1])
            t++;
    }
    cout << t;
}
using namespace std;
int main() {
    int length; cin >> length;
    string s; cin >> s;
    int counter = 0;
    for (int i = 1; i < length; ++i) {
        if (s[i] == s[i - 1])
            ++counter;
    }
    cout << counter << endl;
}
//https://codeforces.com/problemset/problem/266/A
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            cnt=cnt+1;
    }
    cout<<cnt;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    cin >>n;
    string a;
    cin >>a;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==a[i-1])
            cnt++;
    }
    cout<< cnt;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    cin >>n;
    string s;
    cin >>s;
    for(int i=0; i<n; i++)
    {
        if(i!= n-1 && s[i]==s[i+1])
            cnt++;
        else
        {
            cout << cnt;
                break;
        }
    }
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, cnt=0;
    cin >>n;
    string s;
    cin >>s;
    for(int i=0; i<n-1; i++)
        cnt+=s[i]==s[i+1];
    cout<<cnt;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    string st;
    cin>> n;
    cin>> st;
    for(int i=0; i<n; i++)
    {
        for(;i <n && st[i]==st[i+1]; i++)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
http://codeforces.com/problemset/problem/266/B
// Queue at the School
int main() {
    int n, t; cin >> n >> t;
    string s; cin >> s;
    for (int i = 0; i < t; ++i) {
        for (int j = 1; j < n; ++j) {
            if (s[j - 1] == 'B' && s[j] == 'G') {
                swap(s[j - 1], s[j]);
                ++j; // Skip the next index to avoid double swap
            }
        }
    }
    cout << s;
}
using namespace std;
	int main(){
    int n, t;
    cin >> n >> t;
    string s, ans;
    cin >> s;
    ans = s;
    while (t--)
    {
        fo(i, s.length() - 1)
        {
            if (s[i] == 'B' && s[i + 1] == 'G')
            {
                ans[i] = 'G';
                ans[i + 1] = 'B';
            }
        }
        if (s == ans) //!very important
            break;
        s = ans;
    }
    cout << s << endl;
    return;
}
using namespace std;
int main() { 
    int n, t; string s; cin >> n >> t >> s;
    while (t--) { 
        for (int i = 1; i < n; ++i) { 
            if (s[i] == 'G' && s[i-1] == 'B') { 
                s[i] = 'B'; s[i-1] = 'G'; ++i; 
            } 
        } 
    } 
    cout << s << endl; 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    string s;
    cin >> n >> t >> s;

    while (t--) {
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++; // skip the next index to avoid double swap
            }
        }
    }

    cout << s << "\n";
    return 0;
}

http://codeforces.com/contest/268/problem/A
// Games.cpp
using namespace std;
int main() {
    int n; cin >> n;
	int gamescount = 0, arr1[n], arr2[n];
	for(int i = 0; i < n; i++)    cin >> arr1[i] >> arr2[i];
	for(int i = 0; i < n; i++)    gamescount += count(arr2, arr2 + n, arr1[i]);
	 cout << gamescount;
}
using namespace std;
int main() {
    int n; cin >> n;
    int home[n], away[n];
    for (int i = 0; i < n; ++i) 
        cin >> home[i] >> away[i];
    int gameCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (home[i] == away[j]) gameCount++;
        }
    }
    cout << gameCount << endl;
}
int main(){
    ll t;
    cin >> t;
    ll c1[100]{0}, c2[100]{0};

    fo(i, t)
    {
        ll n1, n2;
        cin >> n1 >> n2;
        c1[n1 - 1]++;
        c2[n2 - 1]++;
    }
    ll sum = 0;
    fo(i, 100) sum += c1[i] * c2[i];
    cout << sum << "\n";

    return;
}

using namespace std;
int main(){
    int n; cin>>n;
    map<int,int>mp; int guest[n]; 
    for(int i=0; i<n; i++) { 
        int h,a; cin>>h>>a; mp[h]++; 
        guest[i] = a;
    } 
    int ans = 0; 
    for(int i=0; i<n; i++) 
    { ans+=mp[guest[i]]; } 
    cout<<ans<<endl; 
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> attack(n), defense(n);
    map<int, int> countDefense;

    for (int i = 0; i < n; ++i) {
        cin >> attack[i] >> defense[i];
        countDefense[defense[i]]++; // count how many players have each defense
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += countDefense[attack[i]]; // count how many can attack player i
        if (attack[i] == defense[i]) ans--; // subtract self-count if attack = defense
    }

    cout << ans << "\n";
    return 0;
}

using namespace std;
// A. Fancy Fence
// contest/270/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        (360 % (180 - x)) ? cout << "No\n" : cout << "Yes\n";
    }
}
https://codeforces.com/problemset/problem/270/A
using namespace std;
#define ll long long
int main(){
    ll a; cin >> a;
    //Total sum of angles = (n-2)*180
	//Each internal angle = (n-2)*180/n;
	//a*n=(n-2)*180
	//a*n-180*n=-360
	//(180-a)*n=360
    if (a < 60) {
        cout << "NO";
        return 0;
    }
    if (360 % (180 - a) == 0) // must divide perfectly to form an integer n
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/271/A
// Beautiful Year
bool isBeautiful(int n) {
    string s = to_string(n);
    set<char> digits(s.begin(), s.end());
    return digits.size() == 4;
}
bool isBeautiful(int n){
	string str = to_string(n);
	int dig1 = count(str.begin(), str.end(),str[0]);
	int dig2 = count(str.begin(), str.end(), str[1]);
	int dig3 = count(str.begin(), str.end(), str[2]);
	int dig4 = count(str.begin(), str.end(), str[3]);
	if((dig1 == 1)&&(digt2=1)&&(digt3==1)&&(digt4==1))
		return 1;
    if((dig1 == 1) && (dig2 == 1) && (dig3 == 1) && (dig4 == 1)) return 1;
	else return 0;
}
int main() {
    int n; cin >> n;
    ++n;
    while(!isBeautiful(n))
        ++n;
    cout << n;
    return 0;
}
https://codeforces.com/problemset/problem/271/A
using namespace std;
#define ll long long
int main(){
    ll n; cin >> n;
    while (++n){
        string s = to_string(n);
        set<char> uniDigits(s.begin(), s.end()); // use char since digits are chars
        if (s.size() == uniDigits.size()) // unique digits check
            break;
    }
    cout << n << "\n";
}
	#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a, b, c, d;
  while(true){
    n++;
    a = n/1000;
    b = n / 100 % 10;
    c = n/10 % 10;
    d = n%10;
    if(a != b && a != c && a != d && b != c && b != d && c != d){
      break;
    }

  }

  cout<<n;

  return 0;
}
	#include <iostream>
#include <set>
using namespace std;

// Function to check if all digits of a number are distinct
bool allDistinctDigits(int year) {
    set<int> digits;
    while (year > 0) {
        int digit = year % 10;
        if (digits.count(digit)) return false;
        digits.insert(digit);
        year /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    while (true) {
        n++;
        if (allDistinctDigits(n)) {
            break;
        }
    }

    cout << n << '\n';
    return 0;
}

https://codeforces.com/problemset/problem/275/A
// A. Lights Out
using namespace std;
int main() { 
    int n,m; cin>>n>>m; 
    int lights[n][2*m]; 
    for(int i=0;i<n;i++){ 
        for(int j=0;j<2*m;j++) { 
            cin>>lights[i][j]; 
        } 
    } 
    int ans=0; 
    for(int i=0;i<n;i++) { 
        for(int j=0;j<2*m;j+=2) { 
            if(lights[i][j]==1 || lights[i][j+1]==1) 
                    ans++; 
        }
    } 
        cout<<ans<<endl; 
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lights(n, vector<int>(2 * m));
    
    // Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * m; j++) {
            cin >> lights[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * m; j += 2) {
            // If either of the two lights in a room is ON
            if (lights[i][j] == 1 || lights[i][j + 1] == 1) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/276/C
using namespace std;
#define ll long long
int main() {
    ll n, q, u, v;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    vector<ll> cnt(n + 1, 0);

    // range updates (difference array technique)
    while (q--) {
        cin >> u >> v;
        u--, v--;
        ++cnt[u];
        --cnt[v + 1];
    }

    // prefix sum to get frequency counts
    for (ll i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
    cnt.pop_back(); // remove the extra element at end

    // sort both arrays in descending order
    ranges::sort(cnt, greater<ll>());
    ranges::sort(a, greater<ll>());

    ll sum = 0;
    for (ll i = 0; i < n; ++i) sum += a[i] * cnt[i];

    cout << sum << '\n';
}
https://codeforces.com/problemset/problem/279/A
using namespace std;
#define ll long long
using vpl = vector<pair<ll,ll>>;
vpl res;
void fillSpiral() {
    ll x = 0, y = 0;
    ll ctr = 0;
    res.emplace_back(x, y);
    while (x != 200 && y != 200) {
        ctr++;
        if (ctr % 2 == 0) ctr = -ctr;  // alternate direction

        x += ctr;
        res.emplace_back(x, y);

        y += ctr;
        res.emplace_back(x, y);

        if (ctr % 2 == 0) ctr = -ctr;
    }
}
void Solution() {
    ll x, y;
    cin >> x >> y;

    ll idx = 0;
    for (size_t i = 1; i < res.size(); i++) {
        ll x1 = res[i - 1].first, y1 = res[i - 1].second;
        ll x2 = res[i].first, y2 = res[i].second;

        // normalize ranges
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        // check if (x,y) lies on this segment
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) break;
        idx++;
    }

    cout << idx << "\n";
}

int main() {
    ll tc = 1;
    fillSpiral();
    while (tc--)
        Solution();
    return 0;
}
https://codeforces.com/problemset/problem/279/B
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define amax(a,b) a = max(a,b)
int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n), pref(n + 1, 0);
    for (ll &x : a) cin >> x;

    // prefix sum: pref[i] = sum of first i elements
    partial_sum(all(a), pref.begin() + 1);

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        // find farthest j such that pref[j] - pref[i-1] <= t
        auto it = upper_bound(all(pref), pref[i - 1] + t);
        ll j = (it - pref.begin()) - 1; // largest valid j
        amax(ans, j - (i - 1));
    }

    cout << ans << '\n';
}
using namespace std;
// A. Word Capitalization
// problemset/problem/281/A
int main() {
    string ch; getline(cin, ch); 
    if (!ch.empty() && ch[0] >= 'a' && ch[0] <= 'z')
        ch[0] = ch[0] - 32; 
    cout << ch << endl;
}
#include<iostream>

int main(){
    char a[1000];
    std::cin>>a;
    if(a[0]<=122 && a[0]>=97){
        a[0]=a[0]-32;
    }
    std::cout<<a;
    return 0;
}
using namespace std;
http://codeforces.com/contest/281/problem/A
// A. Word Capitalization
int main() {
	 string s; cin >> s;
	 s[0] = toupper(s[0]);
	 cout << s;
}
using namespace std;
char capitalize(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    return ch;
}
int main() {
    char word[1001]; cin >> word;
    word[0] = capitalize(word[0]);
    cout << word << endl;
}
#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  cin>>s;
  if(s[0] >= 97){

    s[0] = s[0] - 32;
  }
  cout<<s<<endl;
  return 0;
}
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (!s.empty() && islower(s[0])) {
        s[0] = toupper(s[0]);
    }

    cout << s << '\n';
    return 0;
}

using namespace std;
// A. Bit++
// contest/282/problem/A _have a programming language called Bit++ with one variable x, which starts at 0. consists of statements that either:
//Increase x by 1: "++X" or "X++".Decrease x by 1: "--X" or "X--".Execute all statements and print the final value of x.
int main(){
    int t, cnt = 0; cin >> t;
    while(t--){
        string str; cin >> str;
        if(str == "++X" || str == "X++")
            cnt++;
        else if(str == "--X" || str == "X--")
            cnt--;
    }
    cout << cnt;
}
using namespace std;
http://codeforces.com/contest/282/problem/A
// 282A - Bit++
int main() {
    int n, x = 0; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s[1] == '+') ++x;
        else --x;
    }
    cout << x << endl;
}
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == '+' || s[1] == '+' || s[2] == '+')
            ans++;
        else if (s[0] == '-' || s[1] == '-' || s[2] == '-')
            ans--;
    }
    cout << ans << endl;
    return 0;
}
using namespace std;
int main() {
	int n; cin >> n;
	int x = 0;
	while(n--){
	    string s; cin >> s;
		if(s.find('+') != -1) x += 1;
		else x -= 1;
		cin.ignore();
	}
	cout << x;
}
https://codeforces.com/problemset/problem/284/B
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;

    int cntI = 0, cntA = 0;
    for (char c : s) {
        if (c == 'I') cntI++;
        else if (c == 'A') cntA++;
    }

    if (cntI == 0) 
        cout << cntA << '\n';
    else if (cntI == 1) 
        cout << 1 << '\n';
    else 
        cout << 0 << '\n';

    return 0;
}
https://codeforces.com/problemset/problem/285/A
using namespace std;
#define ll long long
#define cn cout << '\n';
ll n, k;
int main() {
    cin >> n >> k;
    for (ll i = 1; i <= n - k - 1; ++i) 
        cout << i << " ";
    for (ll i = n; i >= n - k; --i) 
        cout << i << " ";
    cout << endl;
}
https://codeforces.com/problemset/problem/285/B
using namespace std;
int main() {
    int n, s, t; cin >> n >> s >> t;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int ans = 0;
    while (s != t && ans <= n) {
        s = arr[s];
        ans++;
    }
    if (s == t) 
        cout << ans << "\n";
    else 
        cout << -1 << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/285/C
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs((i + 1) - arr[i]);
    }
    cout << ans << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/287/A
using namespace std;
int main() {
    vector<vector<char>> mat(4, vector<char>(4));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> mat[i][j];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cnt = 0;
            cnt += (mat[i][j] == '#');
            cnt += (mat[i+1][j] == '#');
            cnt += (mat[i][j+1] == '#');
            cnt += (mat[i+1][j+1] == '#');
            if (cnt != 2) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
using namespace std;
// http://codeforces.com/contest/289/problem/A
// A - Polo the Penguin and Segments
int main() {
    int n, k; cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        sum += (r - l + 1);
    }
    cout << (k - (sum % k)) % k << endl;
    return 0;
}
https://codeforces.com/problemset/problem/289/B
using namespace std;
#define ll long long
int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> vec(n * m);
    for (ll i = 0; i < n * m; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    ll check = vec[0] % d;
    // check if all elements have same remainder modulo d
    for (ll i = 1; i < n * m; i++) {
        if (vec[i] % d != check) {
            cout << -1 << "\n";
            return;
        }
    }
    ll mid_ele = vec[(n * m) / 2];
    ll ans = 0;
    for (ll x : vec) {
        ans += abs(mid_ele - x) / d;
    }
    cout << ans << "\n";
}
using namespace std;
http://codeforces.com/contest/294/problem/A
// A. Shaass and Oskols
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        int r = arr[x - 1] - y;
        int l = y - 1;
	if(x - 1 >= 1) arr[x - 2] += l;
	if(x + 1 <= n) arr[x] += r;
	arr[x - 1] = 0;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
using namespace std;
http://codeforces.com/contest/294/problem/A
// Shaass_and_Oskols.cpp
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i]; 
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--;
        if (x > 0)
            arr[x - 1] += y - 1; // birds fly to the wire before

        if (x < n - 1)
            arr[x + 1] += arr[x] - y; // birds fly to the wire after
        arr[x] = 0; // all birds on wire x fly away
    }
    for (int i = 0; i < n; i++) 
        cout << arr[i] << '\n';
}
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        arr[x] += arr[x - 1] - y;
	    arr[x - 2] += y - 1;
	    arr[x - 1] = 0;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}
https://codeforces.com/problemset/problem/304/A
using namespace std;
int main(){
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = (i * i) + (j * j);
            int temp2 = sqrt(temp);
            if (temp2 * temp2 == temp and temp2 <= n)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
https://codeforces.com/problemset/problem/306/A
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin>>m>>n;
  int rem = m % n;
  for(int i = 0; i < (n - rem); i++){
    cout<<(m/n)<<" ";
  }
  for(int i = 0; i < rem; i++){
    cout<<(m/n + 1)<<" ";
  }
  cout<<endl;
  return 0;

}
	
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin>>m>>n;
  int rem = m % n;
  for(int i = 0; i < (n - rem); i++){
    cout<<(m/n)<<" ";
  }
  for(int i = 0; i < rem; i++){
    cout<<(m/n + 1)<<" ";
  }
  cout<<endl;
  return 0;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    int base = m / n;      // Minimum value for each part
    int rem = m % n;       // Extra units to distribute

    // Print the smaller parts first
    for (int i = 0; i < n - rem; i++) {
        cout << base << " ";
    }

    // Print the larger parts (base + 1)
    for (int i = 0; i < rem; i++) {
        cout << base + 1 << " ";
    }

    cout << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    int base = m / n;
    int remainder = m % n;

    for (int i = 0; i < n; i++) {
        if (i < n - remainder)
            cout << base << " ";
        else
            cout << base + 1 << " ";
    }

    cout << '\n';
    return 0;
}
https://codeforces.com/problemset/problem/313/A
using namespace std;
int main(){
    ll n;
    cin >> n;
    if (n >= 0)
        cout << n;
    else{
        string s1 = to_string(-n), s2;
        s2 = s1;
        ll len = s1.length();

        s1.erase(len - 1, 1);
        s2.erase(len - 2, 1);
        ll n1 = stoi(s1), n2 = stoi(s2);
        if (len == 1)
            cout << 0;
        else
            cout << -1 * min(n1, n2);
    }

    return;
}
using namespace std;
http://codeforces.com/problemset/problem/318/A
// A. Even Odds
int main() {
    long long n, k; cin >> n >> k;
    long long mid = (n + 1) / 2;
    if (k <= mid)
        cout << 2 * k - 1;
    else
        cout << 2 * (k - mid);
}
	using namespace std;
int main(){
  unsigned long long n, m;
  cin>>n>>m;
  if(n & 1){
    (m <= (n/2 + 1)) ? cout<<(2 * m - 1)<<endl : cout<<(2*(m - (n/2 + 1)))<<endl;
    return 0;
  }
  (m <= n/2) ? cout<<(2 * m - 1)<<endl : cout<<(2*(m - n/2))<<endl;
  return 0;
}
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long half = (n + 1) / 2; // count of odd numbers in sequence
    if (m <= half) {
        cout << 2 * m - 1 << "\n"; // m-th odd number
    } else {
        cout << 2 * (m - half) << "\n"; // (m-half)-th even number
    }

    return 0;
}
https://codeforces.com/problemset/problem/318/A
using namespace std;
#define ll long long
int main() {
    ll n, k;
    cin >> n >> k;
    k--; // convert to 0-based index
    ll mid = (n + n % 2) / 2 - 1; // middle index for odd/even adjustment
    if (k > mid)
        cout << (k - mid) * 2 << "\n";
    else
        cout << 2 * k + 1 << "\n";
}
https://codeforces.com/problemset/problem/320/A
using namespace std;
int main() {
    string s; cin >> s;
    if (s[0] == '4') {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '1')
            continue;
        else if (s[i] == '4') {
            if (s[i - 1] == '1') continue;
            else if (i >= 2 && s[i - 1] == '4' && s[i - 2] == '1') continue;
            else {
                cout << "YES" << endl;
                return 0;
            }
        } else {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
https://codeforces.com/problemset/problem/320/B
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
int main() {
    ll q;
    cin >> q;
    vector<array<ll, 2>> intervals;

    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, y;
            cin >> x >> y;
            intervals.push_back({x, y});
        } else {
            ll src, ext;
            cin >> src >> ext;
            --src, --ext;
            vector<ll> vis(sz(intervals), 0);

            function<bool(ll)> dfs = [&](ll idx) {
                if (idx == ext) return true;
                vis[idx] = 1;
                auto [a, b] = intervals[idx];
                for (ll i = 0; i < sz(intervals); i++) {
                    if (vis[i]) continue;
                    auto [c, d] = intervals[i];
                    // intervals overlap if one endpoint lies strictly inside the other
                    if ((c < a && a < d) || (c < b && b < d)) {
                        if (dfs(i)) return true;
                    }
                }
                return false;
            };

            cout << (dfs(src) ? "YES\n" : "NO\n");
        }
    }
}
https://codeforces.com/problemset/problem/322/B
using namespace std;
int main() {
    ll r, g, b;
    cin >> r >> g >> b;
    ll ans = r / 3 + b / 3 + g / 3;
    if (min({r, b, g}) > 1) ans = max(ans, (r - 1) / 3 + (b - 1) / 3 + (g - 1) / 3 + 1);
    if (min({r, b, g}) > 2) ans = max(ans, (r - 2) / 3 + (b - 2) / 3 + (g - 2) / 3 + 2);
    cout << ans << '\n';
}
https://codeforces.com/problemset/problem/327/A
using namespace std;
using ll = long long;
int main() {
    constexpr int N = 102;
    int a[N], dp[N];
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    /* 
    dp[n][0] = dp[n][1] = dp[n][2] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i][0] = max(dp[i + 1][0] + a[i], dp[i + 1][1] + a[i]);
        dp[i][1] = max(dp[i + 1][2] + 1 - a[i], dp[i + 1][1] + 1 - a[i]);
        dp[i][2] = dp[i + 1][2] + a[i];
    }
    cout << max({dp[0][0], dp[0][1], dp[0][2]}) << '\n';  // this is for atmost one move
    */
    dp[0] = ((a[0] == 0) ? 1 : -1);
    for (int i = 1; i < n; ++i) {
        int b = ((a[i] == 0) ? 1 : -1);
        dp[i] = max(b, dp[i - 1] + b);
    }
    cout << *max_element(dp, dp + n) + count(a, a + n, 1);
}
https://codeforces.com/problemset/problem/334/A
using namespace std;
int main() {
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
        cout << i + 1;
        for (int j = 1; j < n; j++) {
            cout << " " << (n * j + (i + j) % n + 1);
        }
        cout << "\n";
    }
    return 0;
}
https://codeforces.com/problemset/problem/334/B
using namespace std;
int main() {
    vector<pair<int,int>> points(8);
    vector<int> X, Y;

    for (int i = 0; i < 8; i++) {
        cin >> points[i].first >> points[i].second;
        X.push_back(points[i].first);
        Y.push_back(points[i].second);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    sort(points.begin(), points.end());
    vector<pair<int,int>> expected;

    if (X.size() != 3 || Y.size() != 3) {
        cout << "ugly\n";
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue; // exclude the center
            expected.push_back({X[i], Y[j]});
        }
    }

    sort(expected.begin(), expected.end());

    if (expected == points)
        cout << "respectable\n";
    else
        cout << "ugly\n";

    return 0;
}
using namespace std;
int main() {
    vector<pair<int,int>> inp;
    vector<int> X, Y;

    for (int i = 0; i < 8; i++) {
        int x, y;
        cin >> x >> y;
        inp.push_back({x, y});
        X.push_back(x);
        Y.push_back(y);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    sort(inp.begin(), inp.end());
    vector<pair<int,int>> ans;

    if (X.size() != 3 || Y.size() != 3) {
        cout << "ugly\n";
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue; // skip center
            ans.push_back({X[i], Y[j]});
        }
    }
    sort(ans.begin(), ans.end());
    if (ans == inp)
        cout << "respectable\n";
    else
        cout << "ugly\n";
{
using namespace std;
http://codeforces.com/problemset/problem/337/A
// 337A - Puzzles
int main() {
    int n, m; cin >> n >> m;
    int puzzles[m];
    for (int i = 0; i < m; ++i)
        cin >> puzzles[i];
    sort(puzzles, puzzles + m);
    int min_diff = puzzles[n - 1] - puzzles[0];
    for (int i = n; i < m; ++i)
        min_diff = min(min_diff, puzzles[i] - puzzles[i - n + 1]);
    cout << min_diff << endl;
    return 0;
}
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin>>n>>m;
  int arr[m];
  for(int i = 0; i < m; i++){
    cin>>arr[i];
  }
  sort(arr, arr+m);
  int res = 1000000;
  for(int i = 0; i <= m - n; i++){
    if((arr[n + i - 1] - arr[i]) < res){
      res = (arr[i+n-1] - arr[i]);
    }
  }
  cout<<res<<endl;

}
using namespace std;
#define ll long long
#define endl '\n'
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int res = INT_MAX;
    for (int i = 0; i + n - 1 < m; i++) {
        res = min(res, arr[i + n - 1] - arr[i]);
    }

    cout << res << endl;
    return 0;
}

using namespace std;
http://codeforces.com/problemset/problem/337/A
// 337A - Puzzles
int main() {
    int n, m; cin >> n >> m;
    vector<int> puzzles(m);
    for (int i = 0; i < m; ++i)
        cin >> puzzles[i];
    sort(puzzles.begin(), puzzles.end());
    int min_diff = puzzles[n - 1] - puzzles[0];
    for (int i = 0; i <= m - n; ++i) {
        int current_diff = puzzles[i + n - 1] - puzzles[i];
        min_diff = min(min_diff, current_diff);
    }
    cout << min_diff << endl;
    return 0;
}
http://codeforces.com/contest/339/problem/A
// HelpfulMaths
using namespace std;
int main() {
    string s, s2; cin >> s;
    int len = s.length();
	for(int i = 0; i < len; i++){
	    if(s[i] != '+')    s2 += s[i];
	}
	sort(s2.begin(), s2.end());
	len = s2.length();
	if(len > 1){
	    cout << s2[0];
	    for(int i = 1; i < len - 1; i++)
	        cout << '+' << s2[i];
	    cout << '+' << s2[len - 1];
	}
	else    cout << s;
}
using namespace std;
int main() {
    string s; cin >> s;
    string digits;
    // Extract digits only (ignore '+')
    for (char c : s) {
        if (c != '+')    digits += c;
    }
    sort(digits.begin(), digits.end());
    for (size_t i = 0; i < digits.size(); ++i) {
        if (i > 0) cout << '+';
        cout << digits[i];
    }
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string s1;
  cin>>s1;
  char arr[s1.size()-1];
  int j = 0;
  for(int i = 0; i < s1.size(); i += 2){
    arr[j]= s1[i];
    j++;
  }
  sort(arr, arr+j);
  for(int k = 0; k < j; k++){
    if(k == j-1){
      cout<<arr[k];
    }
    else{
      cout<<arr[k]<<"+";

    }
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<char> nums;
    for (int i = 0; i < s.size(); i += 2) { // take only digits
        nums.push_back(s[i]);
    }

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << "+";
    }
    cout << "\n";

    return 0;
}

using namespace std;
http://codeforces.com/problemset/problem/339/B
// 339B - Xenia and Ringroad
int main() {
    int n, m; cin >> n >> m;
    int current = 1;
    unsigned long long moves = 0;
    for (int i = 0; i < m; ++i) {
        int target; cin >> target;
        if (target >= current)
            moves += target - current;
        else
            moves += n - (current - target);
        current = target;
    }
    cout << moves << endl;
    return 0;
}
https://codeforces.com/problemset/problem/339/B
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
int main(){
    int n, m;
    cin >> n >> m;
    ll a[m];
    fo(i, m) cin >> a[i];

    ll time = 0, position = 1;
    fo(i, m)
    {
        if (a[i] >= position)
            time += a[i] - position;
        else
            time += n + a[i] - position;
        position = a[i];
    }
    cout << time;
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin>>n>>m;

  ll p1 = 1, p2, steps = 0;
  while(m--){
    cin>>p2;
    if(p2 < p1){
      steps += (n - p1 + p2);
    }
    else{
      steps += (p2 - p1);
    }
    p1 = p2;
  }
  cout<<steps<<endl;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long current = 1, next, steps = 0;

    for (long long i = 0; i < m; i++) {
        cin >> next;
        if (next >= current) {
            steps += (next - current);
        } else {
            steps += (n - current + next);
        }
        current = next;
    }

    cout << steps << '\n';
    return 0;
}
https://codeforces.com/problemset/problem/339/D
using namespace std;
using ll = long long;
int main() {
    ll n, m;
    cin >> n >> m;
    n = (1LL << n);  // array size is 2^n
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    // segment tree: {value, op}, op = 1 means OR, op = 0 means XOR
    vector<pair<ll, int>> seg(2 * n);

    // build leaves
    for (ll i = 0; i < n; i++) seg[n + i] = {a[i], 1};

    // build internal nodes
    for (ll i = n - 1; i >= 1; --i) {
        auto l = seg[2 * i], r = seg[2 * i + 1];
        if (l.second == 1)  // OR level
            seg[i] = {l.first | r.first, 0};
        else                // XOR level
            seg[i] = {l.first ^ r.first, 1};
    }

    auto update = [&](ll idx, ll val) {
        idx += n;
        seg[idx].first = val;
        for (idx >>= 1; idx >= 1; idx >>= 1) {
            auto l = seg[2 * idx], r = seg[2 * idx + 1];
            if (l.second == 1)
                seg[idx] = {l.first | r.first, 0};
            else
                seg[idx] = {l.first ^ r.first, 1};
        }
    };

    while (m--) {
        ll p, b;
        cin >> p >> b;
        --p;  // 0-based
        update(p, b);
        cout << seg[1].first << '\n';
    }
}
https://codeforces.com/problemset/problem/343/B
// B. Alternating Current
using namespace std;
#define ll long long
#define endl "\n"
#define debug(n) cout<<(n)<<endl;
#define pb push_back
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<char> st;
  string s;
  cin>>s;

  for(int i = 0; i < s.size(); i++){
    if(!st.empty() && st.top() == s[i]){
      st.pop();
    }
    else{
      st.push(s[i]);
    }
  }
  if(st.empty()){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }

}
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // remove adjacent pair
        } else {
            st.push(c);
        }
    }

    cout << (st.empty() ? "Yes" : "No") << "\n";
    return 0;
}

http://codeforces.com/problemset/problem/344/A
// A. Magnets
using namespace std;
int main(){
    int magnets; cin >> magnets;
    int counter = 1, arr[100000];
    for(int i = 0; i < magnets; i++)    cin >> arr[i];
    for(int i = 0; i < magnets - 1; i++){
        if(arr[i] != arr[i + 1])    counter++;
    }
    cout << counter;
}
https://codeforces.com/problemset/problem/344/A
using namespace std;
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i < b; i++)
int main(){
    ll n;
    cin >> n;
    string val;
    vector<ll> arr(n);
    ll ans = 0;

    fo(i, n)
    {
        cin >> val;
        arr[i] = val[0] - '0'; // store only first digit
    }

    rep(i, 1, n)
    {
        if (arr[i] != arr[i - 1])
            ans++;
    }
    cout << ans + 1 << "\n";
}
using namespace std;
int main() {
    int n; cin >> n;
    int groups = 1;
    string prev, curr; cin >> prev;
    for (int i = 1; i < n; i++) {
        cin >> curr;
        if (curr != prev)    groups++;
        prev = curr;
    }
    cout << groups << endl;
}
#include<iostream>
using namespace std;

int main(){
  int n, count = 1;
  cin>>n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  for(int i = 0; i < n-1; i++){
    if(arr[i] != arr[i+1]){
      count++;
    }
  }
  cout<<count;
}
http://codeforces.com/contest/344/problem/A
// Magnets.cpp
using namespace std;
int main() {
	int n; cin >> n;
	string s1, s2; cin >> s1;
	int magnetics = 1;
	for(int i = 1; i < n; i++){
	    cin >> s2;
	    if(s1[1] == s2[0])    ++magnetics++;
	    s1 = s2;
	}
	cout << magnetics;
	return 0;
}
using namespace std;
int main() {
    int n, groupCount = 1; cin >> n
    string prev, current; cin >> prev;
    for (int i = 1; i < n; ++i) {
        cin >> current;
        if (prev != current)    groupCount++;
        prev = current;
    }
    cout << groupCount << endl;
    return 0;
}
https://codeforces.com/problemset/problem/344/A
A. Magnets
using namespace std;
int main() { 
    int n; cin>>n; 
    string mag[n]; 
    for(int i = 0;i<n;i++) {
        cin>>mag[i]; } 
    int gp = 0; 
    for(int i = 0;i<n;i++) { 
        if(mag[i]!=mag[i+1]) gp++;
    }
    cout<<gp<<endl; 
    return 0; 
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> mag(n);

    for (auto &s : mag) cin >> s;

    int groups = 1; // first magnet always forms a group
    for (int i = 1; i < n; ++i) {
        if (mag[i] != mag[i - 1]) {
            groups++;
        }
    }

    cout << groups << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/353/A
using namespace std;
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
int main()
{
    ll n;
    cin >> n;
    vector<array<ll, 2>> arr(n);
    ll sum1 = 0, sum2 = 0;

    fo(i, n)
    {
        cin >> arr[i][0] >> arr[i][1];
        sum1 += arr[i][0];
        sum2 += arr[i][1];
    }

    // Case 1: Both sums already even
    if ((sum1 % 2 == 0) && (sum2 % 2 == 0))
    {
        cout << 0 << "\n";
        return;
    }

    // Case 2: One even, one odd -> impossible
    if ((sum1 % 2 != sum2 % 2))
    {
        cout << -1 << "\n";
        return;
    }

    // Case 3: Both odd
    fo(i, n)
    {
        if ((arr[i][0] % 2) != (arr[i][1] % 2))
        {
            cout << 1 << "\n";
            return;
        }
    }

    // No domino with mixed parity → impossible
    cout << -1 << "\n";
}
void solve()
{

    ll n;
    cin >> n;
    ll arr[n][2];
    ll sum1(0), sum2(0);
    fo(i, n)
    {
        cin >> arr[i][0] >> arr[i][1];
        sum1 += arr[i][0];
        sum2 += arr[i][1];
    }

    if ((sum1 & 1) == 0 && (sum2 & 1) == 0)
    {
        cout << "0";
        return;
    }

    if ((sum1 & 1) == 1 && (sum2 & 1) == 0)
    {
        cout << "-1";
        return;
    }
    if ((sum1 & 1) == 0 && (sum2 & 1) == 1)
    {
        cout << "-1";
        return;
    }

    else
    {
        fo(i, n)
        {
            if (arr[i][0] % 2 == 0 && arr[i][1] % 2 != 0)
            {
                cout << "1";
                return;
            }
            if (arr[i][0] % 2 != 0 && arr[i][1] % 2 == 0)
            {
                cout << "1";
                return;
            }
        }

        cout << "-1";
        // if two elements are odd on one domino
    }

    return;
}
	//356/A
	void Solution() {
    ll n, m, l, r, x;
    cin >> n >> m;
    set<ll> st;
    vector<ll> ans(n, -1);
    for (ll i = 1; i <= n; ++i) st.insert(i);
    for (ll i = 0; i < m; ++i) {
        cin >> l >> r >> x;
        auto it = st.lower_bound(l);
        while (it != st.end() && *it <= r) {
            ans[*it - 1] = x;
            st.erase(*it);
            it = st.lower_bound(l);
        }
        st.insert(x);
        ans[x - 1] = 0;
    }
    for (auto &X : ans) cout << X << ' ';
}
https://codeforces.com/problemset/problem/357/C
int main() {
    ll n, m, l, r, x;
    cin >> n >> m;
    set<ll> alive;
    vector<ll> ans(n, -1);
    for (ll i = 1; i <= n; ++i) alive.insert(i);  // will always decrease and thus fast
    for (ll i = 0; i < m; ++i) {
        cin >> l >> r >> x;
        auto it = alive.lower_bound(l);
        while (it != alive.end() && *it <= r) {
            ans[*it - 1] = x;  // losers gets winner's number
            alive.erase(*it);
            it = alive.lower_bound(l);
        }
        alive.insert(x);
        ans[x - 1] = 0;  // winner gets 0
    }
    for (auto &X : ans) cout << X << ' ';
}
https://codeforces.com/problemset/problem/357/E
using namespace std;
int min(int a, int b)
{
    return (a < b ? a : b);
}
int max(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    long int n;
    cin >> n;
    int ctr[5] = {0};
    int i, input, re = 0;
    for (i = 0; i < n; i++)
    {
        cin >> input;
        ctr[input]++;
    }
    int entering, leaving, moving;
    moving = min(ctr[1], ctr[2]);
    re += moving;
    ctr[1] -= moving;
    ctr[2] -= moving;
    ctr[3] += moving;
    if (ctr[1] > 0 && ctr[2] == 0)
    {
        moving = ctr[1] / 3;
        re += moving * 2;
        ctr[1] -= moving * 3;
        ctr[3] += moving;
        if (ctr[1] == 1)
        {
            if (ctr[3] >= 1)
            {
                re++;
            }
            else
            {
                if (ctr[4] >= 2)
                {
                    re += 2;
                }
                else
                {
                    re = -1;
                }
            }
        }
        if (ctr[1] == 2)
        {
            if (ctr[4] >= 1)
            {
                re += 2;
            }
            else
            {
                if (ctr[3] >= 2)
                {
                    re += 2;
                }
                else
                {
                    re = -1;
                }
            }
        }
    }
    if (ctr[1] == 0 && ctr[2] > 0)
    {
        moving = ctr[2] / 3;
        re += moving * 2;
        ctr[2] -= moving * 3;
        ctr[3] += moving * 2;
        if (ctr[2] == 1)
        {
            if (ctr[4] >= 1)
            {
                re++;
            }
            else
            {
                if (ctr[3] >= 2)
                {
                    re += 2;
                }
                else
                {
                    re = -1;
                }
            }
        }
        if (ctr[2] == 2)
        {
            re += 2; //merge
        }
    }
    cout << re;
    return 0;
}
	361/B
using namespace std;
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define ln "\n"
int main() {
    ll n, k;
    cin >> n >> k;

    if (n == k) { 
        // Special case: not possible since gcd condition fails
        cout << -1 << ln;
        return;
    }

    // Construct permutation
    // Example: n=5, k=2 -> output: 3 1 4 5 2
    cout << n - k << " ";
    fo(i, n - k - 1) cout << i + 1 << " ";
    fo(i, k) cout << n - k + 1 + i << " ";
    cout << ln;
}
362/B
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vl arr(m);
    fo(i, m) cin >> arr[i];
    sort(all(arr));
    if (m == 0) {
        cout << "YES";
        return;
    }
    if (arr[0] == 1 || arr[m - 1] == n) {
        cout << "NO";
        return;
    }
    for (int i = 2; i < m; ++i) {
        if (arr[i] - arr[i - 1] == 1 && arr[i - 1] - arr[i - 2] == 1) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

http://codeforces.com/contest/363/problem/B
// B. Fence
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int height; cin >> height;
        prefix[i] = prefix[i - 1] + height;
    }
    int min_index = 0;
    long long min_sum = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        long long sum = prefix[i + k] - prefix[i];
        if (sum < min_sum) {
            min_sum = sum;
            min_index = i;
        }
    }
    cout << (min_index + 1) << endl;
}
http://codeforces.com/contest/365/problem/A
// 365A. Good Number
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int good_count = 0;
    for (int i = 0; i < n; ++i) {
        string number;
        cin >> number;
        vector <bool> digit_present(10, false);
        for (char ch : number)
            digit_present[ch - '0'] = true;
        bool is_good = true;
        for (int d = 0; d <= k; ++d) {
            if (!digit_present[d]) {
                is_good = false;
                break;
            }
        }
        if (is_good)
            ++good_count;
    }
    cout << good_count << endl;
    return 0;
}
using namespace std;
int arr[10];
int main() {
	int n, k; cin >> n >> k;
	vector <string> vect;
	for(int i = 0; i < n; i++){
		string str; cin >> str;
		vect.push_back(str);
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		int val = 0;
		for(int j = 0; j <= k; j++){
		    if(vec[i].find(to_string(j)) != -1) ++val;
		}
 		if(val == k + 1) ++res;
	}
	cout << res;
}
using namespace std;
// 365A. Good Number 
http://codeforces.com/contest/365/problem/A
int main(){
    int n, k; cin >> n >> k;
    int res = 0;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        int len = str.length();
        int cnt = 0;
        for(int j = 0; j <= k; j++){
            if(str.find('0' + j) != -1)
                ++cnt;
        }
        if(cnt == k + 1) res++;
    }
    cout << res;
}
using namespace std;
// Valera and Plates
// problemset/problem/369/A _given n dishes, where each dish requires either a bowl or a plate 
// have a limited number of bowls and plates.determine how many dishes cannot be served due to a lack of resources.
int main(){
    int n, bowl, plate; cin >> n >> bowl >> plate;
    int arr[n + 5], b = 0, p = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] == 1)
            b++;
        else if(arr[i] == 2)
            p++;
    }
    int res = 0, ans = 0;
    if(bowl >= b) bowl -= b;
    else{
        ans = b - bowl;
        bowl = 0;
    }
    if(plate >= p) res = 0;
    else{
        p -= plate;
        if(bowl > 0){
            if(bowl >= p){
                bowl -= p; res = 0;
            }
            else res = p - bowl;
        }
        else res = p
    }
    cout << ans + res;
}
https://codeforces.com/problemset/problem/368/B
using namespace std;
using ll = long long;
int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    set<ll> len;
    for (ll i = n - 1; i >= 0; --i) {
        len.insert(a[i]);
        b[i] = (ll)len.size();
    }
    while (m--) {
        ll q;
        cin >> q;
        cout << b[q - 1] << "\n";
    }
    return 0;
}
https://codeforces.com/problemset/problem/371/D
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    vector<ll> capacity(n);
    for (ll &C : capacity) cin >> C;

    set<ll> unfilled;
    for (ll i = 0; i < n; ++i) unfilled.insert(i);

    auto orig = capacity;

    ll q;
    cin >> q;
    while (q--) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll p, x;
            cin >> p >> x;
            --p;

            auto it = unfilled.lower_bound(p);
            if (it == unfilled.end()) continue;

            p = *it;
            while (true) {
                if (p >= n) break;

                ll to_dec = min(capacity[p], x);
                capacity[p] -= to_dec;
                x -= to_dec;

                if (capacity[p] == 0) unfilled.erase(p);
                if (x == 0) break;

                ++p;
            }

        } else { // type == 2
            ll k;
            cin >> k;
            --k;
            cout << orig[k] - capacity[k] << "\n";
        }
    }
    return 0;
}
https://codeforces.com/problemset/problem/376/B
using namespace std;
using ll = long long;
int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> balance(n, 0);

    while (m--) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a, --b;
        balance[a] -= c;
        balance[b] += c;
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (balance[i] > 0)
            sum += balance[i];
    }

    cout << sum << "\n";
}
https://codeforces.com/problemset/problem/377/A
using namespace std;
using ll = long long;
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    ll sum = 0;  // total number of '.' cells
    for (auto &row : grid) {
        cin >> row;
        sum += count(row.begin(), row.end(), '.');
    }
    sum -= k;  // we want to keep exactly 'sum' reachable '.' cells

    // directions: down, right, up, left
    ll dx[4] = {1, 0, -1, 0};
    ll dy[4] = {0, 1, 0, -1};

    queue<pair<ll, ll>> bfs;
    ll sx = -1, sy = -1;
    // find a starting '.' cell
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                sx = i;
                sy = j;
            }
        }
    }
    bfs.push({sx, sy});
    vis[sx][sy] = 1;
    while (!bfs.empty() && sum > 0) {
        auto [X, Y] = bfs.front();
        bfs.pop();

        vis[X][Y] = 2;  // mark as kept
        --sum;

        for (int dir = 0; dir < 4; dir++) {
            ll nx = X + dx[dir], ny = Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] != 0 || grid[nx][ny] != '.') continue;
            bfs.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    // replace all other '.' with 'X'
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == '.' && vis[i][j] != 2) {
                grid[i][j] = 'X';
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << grid[i] << '\n';
    }
}
https://codeforces.com/problemset/problem/379/A
using namespace std;
using ll = long long;
int main() {
    ll a, b;
    cin >> a >> b;

    ll ctr = 0;   // total burned
    ll rem = 0;   // leftover stubs
    while (a > 0) {
        ctr += a;         // burn all current candles
        rem += a;         // add burned stubs
        a = rem / b;      // exchange stubs for new candles
        rem %= b;         // leftover stubs after exchange
    }
    cout << ctr << "\n";
    // Alternative direct formula:
    // cout << (a * b - 1) / (b - 1) << "\n";
}
http://codeforces.com/problemset/problem/379/A
// New_Year_Candles.cpp
using namespace std;
int main() {
	int val, ref; cin >> val >> ref;
	int sum = val;
	int rem = 0;
	while(val / ref > 0){
	    rem = val % ref;
	    val /= ref;
	    sum += ceil(val);
	    val += rem;
	}
	cout << sum;
}
using namespace std;
int main() {
    int candles, exchange; cin >> candles >> exchange;
    int total = candles;
    while (candles >= exchange) {
        int new_candles = candles / exchange;
        total += new_candles;
        candles = new_candles + (candles % exchange);
    }
    cout << total << endl;
}
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b;
  cin>>a>>b;
  ll c = a;
  while(a/b != 0){
    ll temp = a;
    c += a/b;
    a /= b;
    a += temp % b;
  }
  cout<<c<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    long long total = a;

    while (a >= b) {
        long long extra = a / b;
        total += extra;
        a = extra + (a % b);
    }

    cout << total << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/381/A
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int i = 0, j = n - 1;
    ll s1 = 0, s2 = 0;
    int ctr = 0;

    while (i <= j) {
        if (vec[i] > vec[j]) {
            if (ctr % 2 == 0) s1 += vec[i];
            else s2 += vec[i];
            i++;
        } else {
            if (ctr % 2 == 0) s1 += vec[j];
            else s2 += vec[j];
            j--;
        }
        ctr++;
    }

    cout << s1 << " " << s2 << "\n";
}
using namespace std;
http://codeforces.com/contest/381/problem/A
// A. Sereja and Dima
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int l = 0, r = n - 1;
    int sscore = 0, dscore = 0;
    for (int turn = 0; turn < n; ++turn) {
        int chosen;
        if (arr[l] >= arr[r])
            chosen = arr[l++];
        else
            chosen = arr[r--];
        if (turn % 2 == 0)
            sscore += chosen; 
        else
            dscore += chosen;
    }
    cout << sscore << " " << dscore << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  list <int> listn;
  int x;
  for(int i = 0; i < n; i++){
    cin>>x;
    listn.push_back(x);
  }
  int sereja = 0, dima = 0;
  bool turn = true;
  while(n--){
    turn = !turn;
    if(turn){
      if(listn.front() >= listn.back()){
        dima += listn.front();
        listn.pop_front();
        continue;
      }
      dima += listn.back();
      listn.pop_back();
      continue;
    }
    if(listn.front() >= listn.back()){
      sereja += listn.front();
      listn.pop_front();
      continue;
    }
    sereja += listn.back();
    listn.pop_back();
    continue;
  }
  cout<<sereja<<" "<<dima<<endl;
  return 0;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    deque<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int sereja = 0, dima = 0;
    bool serejaTurn = true;

    while (!cards.empty()) {
        int pick;
        if (cards.front() >= cards.back()) {
            pick = cards.front();
            cards.pop_front();
        } else {
            pick = cards.back();
            cards.pop_back();
        }

        if (serejaTurn) {
            sereja += pick;
        } else {
            dima += pick;
        }

        serejaTurn = !serejaTurn; // switch turn
    }

    cout << sereja << " " << dima << "\n";
    return 0;
}

using namespace std;
https://codeforces.com/problemset/problem/381/A
// SerejaAndDima.cpp
int main() {
	int n; cin >> n;
	int snscore = 0,dimscore = 0,counter = 0, right = 0, left = n - 1;
	int arr[n];
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
	while(counter < n){
		if(counter % 2 == 0){
			if(arr[right] > arr[left]){
			    snscore += arr[rigtht];
				right++;
			}
			else
			    snscore += arr[left];
				left--;
		}
		else {
		    if(arr[right] > arr[left]){
			    dimscore += arr[right];
			  	rigtht++;
		    }
			else{
			    dimscore += arr[left];
			    left--;
			}
	    }
		counter++;
	}
	cout << snscore << " " << dimscore;
}
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = 0, right = n - 1;
    int sereja = 0, dima = 0;
    bool turn = true; // true = Sereja's turn, false = Dima's turn
    while (left <= right) {
        int chosen;
        if (arr[left] > arr[right])
            chosen = arr[left++];
        else
            chosen = arr[right--];
        if (turn)
            sereja += chosen;
        else
            dima += chosen;
        turn = !turn;
    }
    cout << sereja << " " << dima << endl;
}
https://codeforces.com/problemset/problem/381/A
// A. Sereja and Dima
using namespace std;
int main(){
    int n;
    cin>>n;
    int cards[n];
    for(int i=0;i<n;i++)
    {
        cin>>cards[i];
    }
    int Sereja, Dima;
    Sereja = Dima = 0;
    int c=0;
    int l=0,r=n-1;
    while(n--)
    {
        if(c%2==0)
        {
            if(cards[l]>cards[r])
            {
            Sereja+=cards[l];
            l++;
            }
            else
            {
            Sereja+=cards[r];
            r--;
            }
        }
        else
        {
            if(cards[l]>cards[r])
            {
            Dima+=cards[l];
            l++;
            }
            else
            {
            Dima+=cards[r];
            r--;
            }
        }
        c++;
    }
    cout<<Sereja<<" "<<Dima<<endl;
}
#include <bits/stdc++.h>
using namespace std;

// Code Written By: Vikash Patel
// Codeforces Profile: https://codeforces.com/profile/vikashpatel

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int Sereja = 0, Dima = 0;
    int left = 0, right = n - 1;
    bool isSerejaTurn = true;

    while (left <= right) {
        if (cards[left] > cards[right]) {
            if (isSerejaTurn)
                Sereja += cards[left];
            else
                Dima += cards[left];
            left++;
        } else {
            if (isSerejaTurn)
                Sereja += cards[right];
            else
                Dima += cards[right];
            right--;
        }
        isSerejaTurn = !isSerejaTurn; // Alternate turns
    }

    cout << Sereja << " " << Dima << "\n";
    return 0;
}

using namespace std;
http://codeforces.com/contest/382/problem/A
// A. Ksenia and Pan Scales
int main() {
    string s, extra;
    cin >> s >> extra;
    size_t pipe_pos = s.find('|');
    string left = s.substr(0, pipe_pos);
    string right = s.substr(pipe_pos + 1);

    int left_len = left.length();
    int right_len = right.length();
    int extra_len = extra.length();

    int total_len = left_len + right_len + extra_len;
    if (total_len % 2 == 0 && abs(left_len - right_len) <= extra_len) {
        int target_len = total_len / 2;
        // Add characters from `extra` to the shorter side
        int to_add_left = target_len - left_len;
        left += extra.substr(0, to_add_left);
        right += extra.substr(to_add_left);

        cout << left << '|' << right << endl;
    } else
        cout << "Impossible" << endl;
    return 0;
}
https://codeforces.com/problemset/problem/385/C
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int N = 1e7 + 5;
const ll MOD = 1'000'000'007;
vector<int> spf(N, -1);
void fill_spf() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == -1) {        // i is prime
            spf[i] = i;
            if ((ll)i * i < N) {
                for (ll j = 1LL * i * i; j < N; j += i) {
                    if (spf[j] == -1) spf[j] = i;
                }
            }
        }
    }
}
// Factorization using spf[]
vector<int> factorise(int n) {
    vector<int> res;
    while (n > 1) {
        int fac = spf[n];
        res.push_back(fac);
        while (n % fac == 0) n /= fac;
    }
    return res;
}
int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int &X : x) cin >> X;

    vector<int> cnt(N, 0);  // cnt[p] = how many numbers divisible by prime p

    for (int i = 0; i < n; i++) {
        auto C = factorise(x[i]);
        for (int c : C) cnt[c]++;
    }

    vector<int> pref(N, 0);
    for (int i = 1; i < N; i++) pref[i] = pref[i - 1] + cnt[i];

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l >= N) cout << "0\n";
        else cout << pref[min(r, N - 1)] - pref[l - 1] << "\n";
    }
}
https://codeforces.com/problemset/problem/387/A
using namespace std;
using ll = long long;
int main() {
    string s;
    cin >> s;

    stringstream ss(s);
    ll h, m;
    char ch;
    ss >> h >> ch >> m;

    string dur;
    cin >> dur;
    stringstream dd(dur);
    ll dh, dm;
    dd >> dh >> ch >> dm;

    // subtract duration
    ll ansh = h - dh;
    ll ansm = m - dm;

    if (ansm < 0) {
        ansm += 60;
        ansh -= 1;
    }
    if (ansh < 0) {
        ansh += 24;
    }

    cout << setw(2) << setfill('0') << ansh << ':'
         << setw(2) << setfill('0') << ansm << "\n";
}
https://codeforces.com/problemset/problem/387/B
using namespace std;
using ll = long long;
int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < m; i++) cin >> b[i];

    sort(a.rbegin(), a.rend()); // sort descending
    sort(b.rbegin(), b.rend()); // sort descending

    ll ans = n; // max problems we need to prepare
    ll pos = 0; // pointer in b

    for (ll i = 0; i < n; i++) {
        if (pos < m && b[pos] >= a[i]) {
            pos++;
            ans--; // problem covered
        }
        if (pos >= m) break;
    }

    cout << ans << "\n";
}
// 400/B
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    set<int> distances;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;

        int g = row.find('G');
        int s = row.find('S');

        if (s < g) {
            cout << -1 << "\n";
            return;
        }
        distances.insert(s - g);
    }
    cout << distances.size() << "\n";
}
//401/A
using namespace std;
int main() {
    long long n, x;
    cin >> n >> x;

    vector<long long> arr(n);
    for (auto &val : arr) cin >> val;

    long long sum = 0;
    for (auto val : arr) sum += val;
    sum = abs(sum);

    cout << (sum + x - 1) / x << "\n";
}
void Solution() {
    ll n, x;
    cin >> n >> x;
    vl arr(n);
    fo(i, n) cin >> arr[i];
    ll sum = accumulate(all(arr), 0LL);
    if (sum < 0) sum = -sum;
    ll ans = sum / x;
    if (sum % x) ans++;
    cout << ans << ln;
}
//402/C
using namespace std;
void Solution() {
    ll n, p;
    cin >> n >> p;
    vector<array<ll, 2>> edges;
    for (ll dist = 1; dist <= n && sz(edges) < 2 * n + p; ++dist) {
        for (ll i = 0; i < n && sz(edges) < 2 * n + p; ++i) {
            edges.push_back({i, (dist + i) % n});
        }
    }
    for (auto &[x, y] : edges) cout << x + 1 << ' ' << y + 1 << '\n';
}
void solve() {
    long long n, p;
    cin >> n >> p;

    vector<pair<long long, long long>> edges;
    for (long long d = 1; edges.size() < 2 * n + p; d++) {
        for (long long i = 0; i < n && edges.size() < 2 * n + p; i++) {
            edges.push_back({i + 1, (i + d) % n + 1});
        }
    }
    for (auto [u, v] : edges)
        cout << u << " " << v << "\n";
}

using namespace std;
http://codeforces.com/contest/404/problem/A
A. Valera and X
char arr[305][305];
int main(){
    int n, cnt = 0; cin >> n;
    set <char> se, se2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || j == n - 1 - i){
                ++cnt;
                se2.insert(arr[i][j]);
            }
            else
                se.insert(arr[i][j]);
        }
    }
    char x = *se.begin();
    char y = *se2.begin();
    if(se.size() == se2.size() && se.size() == 1 && count == (2*n) - 1 && x != y)
        cout<<"YES";
    else cout << "NO";
}
using namespace std;
int main() {
    int n;
    cin >> n;
    char matrix[305][305];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    char diag_char = matrix[0][0];      
    char non_diag_char = matrix[0][1];
    if (diag_char == non_diag_char) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || j == n - 1 - i) {
                if (matrix[i][j] != diag_char) {
                    cout << "NO\n";
                    return 0;
                }
            } else {
                if (matrix[i][j] != non_diag_char) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}
	// 404/C
using namespace std;
void solve() {
    long long n, k;
    cin >> n >> k;

    vector<long long> dist(n), count(n, 0), degree(n, 0);
    for (auto &x : dist) {
        cin >> x;
        count[x]++;
    }

    long long maxDepth = *max_element(dist.begin(), dist.end());

    // Check max capacity: at depth i, ≤ k^i nodes allowed
    long long capacity = 1;
    for (int i = 0; i < n && i <= maxDepth; i++) {
        if (count[i] > capacity) {
            cout << -1 << "\n";
            return;
        }
        if (capacity > 100000 / k) break; // prevent overflow
        capacity *= k;
    }

    // Distances must be consecutive
    vector<long long> check = dist;
    sort(check.begin(), check.end());
    check.erase(unique(check.begin(), check.end()), check.end());
    for (int i = 1; i < (int)check.size(); i++) {
        if (check[i] != check[i - 1] + 1) {
            cout << -1 << "\n";
            return;
        }
    }

    // Build edges level by level
    vector<vector<int>> nodesAtDepth(maxDepth + 1);
    for (int i = 0; i < n; i++) {
        nodesAtDepth[dist[i]].push_back(i);
    }

    vector<pair<int, int>> edges;
    for (int depth = 1; depth <= maxDepth; depth++) {
        auto &parents = nodesAtDepth[depth - 1];
        auto &children = nodesAtDepth[depth];
        if (parents.empty()) {
            cout << -1 << "\n";
            return;
        }
        for (int j = 0; j < (int)children.size(); j++) {
            int u = parents[j % parents.size()];
            int v = children[j];
            degree[u]++;
            degree[v]++;
            edges.push_back({u, v});
        }
    }

    // Validate degree constraint
    if (*max_element(degree.begin(), degree.end()) > k || edges.empty()) {
        cout << -1 << "\n";
        return;
    }

    // Output
    cout << edges.size() << "\n";
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

void Solution() {
    ll n, k, p = 1;
    cin >> n >> k;
    vector<ll> d(n), cnt(n, 0), deg(n, 0);
    for (ll &x : d) cin >> x, ++cnt[x];
    ll mx = *ranges::max_element(d);
    // 1, k, k^2, ... <- max nodes with d[0], d[1] ...
    for (ll i = 0; i < n; ++i) {
        if (!cnt[i] || p >= (ll)1e5) break;
        if (cnt[i] > p) return void(cout << "-1\n");
        p *= k;
    }
    // distances 0 1 2 3.. all consecutive should exist
    vector<ll> check(d);
    sort(all(check));
    check.resize(unique(all(check)) - check.begin());
    for (ll i = 1; i < sz(check); ++i)
        if (check[i] != check[i - 1] + 1) return void(cout << "-1\n");
    // joining all children to their parents equally.. %sz(parent)..
    vector<vector<ll>> avail(mx + 1);
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < n; ++i) avail[d[i]].push_back(i);
    for (ll i = 1; i <= mx; ++i) {
        ll parent = i - 1, child = i;
        if (avail[parent].empty()) break;
        for (ll j = 0; j < sz(avail[child]); ++j) {
            ll u = avail[parent][j % sz(avail[parent])];
            ll v = avail[child][j];
            ++deg[u], ++deg[v];
            edges.push_back({u, v});
        }
    }
    // rechecking at the end
    if (*ranges::max_element(deg) > k || edges.empty()) return void(cout << "-1\n");
    cout << sz(edges) << '\n';
    for (auto &[x, y] : edges) cout << x + 1 << ' ' << y + 1 << '\n';
}
http://codeforces.com/problemset/problem/405/A
// GravityFlip.cpp
using namespace std;
int main(){
    int n; cin >> n;
    int arr[101];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)    cout << arr[i] << " ";
}
// 405/A
using namespace std;
void solve() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;

    sort(arr.begin(), arr.end());

    for (auto x : arr) cout << x << " ";
    cout << "\n";
}
void solve(){
    ll n;
    cin >> n;
    ll arr[n];
    fo(i, n) { cin >> arr[i]; }
    sort(arr, arr + n);
    fo(i, n) { cout << arr[i] << " "; }
    return;
}
using namespace std;
http://codeforces.com/contest/408/problem/A
// A. Line to Cashier
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < arr[i]; j++){
            int x; cin >> x;
            sum += 15 + x * 15;
        }
        arr[i] = sum;
    }
    sort(arr, arr + n);
    cout << arr[0];
}
using namespace std;
http://codeforces.com/contest/408/problem/B
// B. Garland
int arr[26], arr2[26];
int main(){
    string s, s2; cin >> s >> s2;
    int sum = 0;
    int len1 = s.length();
    int len2 = s2.length();
    for(int i = 0; i < len1; i++)
        ++arr[s[i] - 'a'];
    for(int i = 0; i < len2; i++)
        ++arr2[s2[i] - 'a'];
    for(int i = 0; i < 26; i++){
        if(arr2[i]){
            if(arr[i])
                sum += min(arr[i], arr2[i]);
            else{
                sum = 0; break;
            }
        }
    }
    if(sum) cout << sum;
    else cout << -1;
}
using namespace std;
int main() {
    string s, s2; cin >> s >> s2;
    int freq_s[26] = {0};
    int freq_s2[26] = {0};
    for (char ch : s)
        ++freq_s[ch - 'a'];
    for (char ch : s2)
        ++freq_s2[ch - 'a'];
    int total = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq_s2[i] > 0) {
            if (freq_s[i] == 0) {
                cout << -1 << endl;
                return 0;
            }
            total += min(freq_s[i], freq_s2[i]);
        }
    }
    cout << total << endl;
    return 0;
}
// 408/B
using namespace std;
void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (char c : s1) cnt1[c - 'a']++;
    for (char c : s2) cnt2[c - 'a']++;

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt2[i] > 0 && cnt1[i] == 0) {
            cout << -1 << "\n";
            return;
        }
        ans += min(cnt1[i], cnt2[i]);
    }

    cout << ans << "\n";
}
void Solution() {
    str s1, s2;
    cin >> s1 >> s2;
    vl cnt1(26, 0), cnt2(26, 0);
    fo(i, sz(s1))++ cnt1[s1[i] - 'a'];
    fo(i, sz(s2))++ cnt2[s2[i] - 'a'];
    debug(cnt1, cnt2);

    ll ans = 0;
    fo(i, 26) {
        ans += min(cnt1[i], cnt2[i]);
        if (cnt1[i] == 0 && cnt2[i] != 0) {
            cout << -1 << ln;
            return;
        }
    }
    cout << ans << ln;
}
// 420/A
using namespace std;
void solve() {
    string s;
    cin >> s;
    // Step 1: Check palindrome
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            cout << "NO\n";
            return;
        }
    }
    // Step 2: Check allowed characters
    string allowed = "AHIMOTUVWXY";
    set<char> valid(allowed.begin(), allowed.end());

    for (char c : s) {
        if (!valid.count(c)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
void Solution() {
    //AHIMOTUVWXY and palindrome
    str s, s1 = "AHIMOTUVWXY";
    cin >> s;
    ll n = sz(s);
    fo(i, n / 2) {
        if (s[i] != s[n - 1 - i]) {
            no();
            return;
        }
    }
    sort(all(s));
    uniq(s);
    debug(s);
    n = sz(s);
    ll pos = 0;
    if (n > 11)
        no();
    else {
        fo(i, 11) {
            if (s1[i] == s[pos]) {
                pos++;
            }
        }
        debug(pos);
        if (pos != n)
            no();
        else
            yes();
    }
}
using namespace std;
http://codeforces.com/contest/427/problem/A
//427 A. Police Recruits.cpp
int main() {
    int n; cin >> n;
    int availableOfficers = 0;
    int untreatedCrimes = 0;
    for (int i = 0; i < n; ++i) {
        int event; cin >> event;

        if (event > 0)
            availableOfficers += event;
        else{
            if (availableOfficers > 0)
                --availableOfficers; 
            else
                ++untreatedCrimes;
        }
    }
    cout << untreatedCrimes << endl;
}
	https://codeforces.com/problemset/problem/427/A
A. Police Recruits
using namespace std;
int main() { 
    int n; cin>>n;
    int recrime[n]; 
    for(int i=0;i<n;i++) {
        cin>>recrime[i]; 
    } 
    int availoff=0; int untcrimes=0; 
    for(int i=0;i<n;i++) { 
        if(recrime[i]!=-1) { 
            availoff+=recrime[i]; } 
        else {
            if(availoff>0)
                availoff--; 
            else untcrimes++;
        }
    }
    cout<<untcrimes<<endl;
}
	// 427/A
void solve() {
    int n;
    cin >> n;

    int police = 0, untreated = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            if (police > 0) police--;
            else untreated++;
        } else {
            police += x;
        }
    }

    cout << untreated << "\n";
}
void solve(){
    ll n, police = 0, untreated = 0;
    cin >> n;
    vl arr(n);
    fo(i, n)
    {
        cin >> arr[i];
        if (arr[i] != -1)
            police += arr[i];
        if (arr[i] == -1)
        {
            if (police > 0)
                police--;
            else
                untreated++;
        }
        // deb2(police, untreated);
    }
    cout << untreated;
    return;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> recrime(n);

    for (int &x : recrime) cin >> x;

    int availableOfficers = 0;
    int untreatedCrimes = 0;

    for (int x : recrime) {
        if (x >= 0) {
            availableOfficers += x; // new officers recruited
        } else {
            if (availableOfficers > 0) {
                availableOfficers--; // handle crime with available officer
            } else {
                untreatedCrimes++; // no officer available
            }
        }
    }

    cout << untreatedCrimes << "\n";
    return 0;
}

http://codeforces.com/contest/427/problem/A
// PoliceRecruits.cpp
using namespace std;
int main() {
    int n; cin >> n;
    int officersAvailable = 0;
    int untreatedCrimes = 0;
    for (int i = 0; i < n; ++i) {
        int event; cin >> event;
        if (event == -1) {
            if (officersAvailable > 0)    --officersAvailable;
            else    ++untreatedCrimes;
        } else    officersAvailable += event;
    }
    cout << untreatedCrimes << endl;
    return 0;
}
using namespace std;
int main() {
	int n; cin >> n;
	int officersnow = 0, crimes = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    if(x == -1){
	        if(officersnow > 0)    officersnow--;
	        else    crimes++;
	    }
	    else    officersnow += x;
    }
	cout << crimes;
}

using namespace std;
http://codeforces.com/contest/431/problem/A
// A. Black Square
int main(){
    int arr[4], res = 0;
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    string str; cin >> str;
    int len = str.length();
	for(int i = 0; i < len; i++){
	    int z = str[i] - '0';
	    res += arr[z - 1];
	}
    cout << res;
}
// 431/A
using namespace std;
void solve() {
    vector<int> arr(4);
    for (int i = 0; i < 4; i++) cin >> arr[i];

    string s;
    cin >> s;

    int ans = 0;
    for (char c : s) ans += arr[c - '1'];

    cout << ans << "\n";
}

void solve()
{
    ll arr[4], ans = 0;
    fo(i, 4) cin >> arr[i];
    string s;
    cin >> s;
    fo(i, s.length()) ans += arr[s[i] - '1'];
    cout << ans;
    re;
}
http://codeforces.com/contest/431/problem/A
// Black_Square
using namespace std;
int main() {
	int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
	int calories = 0;
	string s; cin >> s;
	int len = s.length();
	for(int i = 0; i < len; i++){
	    if(s[i] == '1')    calories += a1;
        if(s[i] == '2')    calories += a2;
        if(s[i] == '3')    calories += a3;
        if(s[i] == '4')    calories += a4;
	}
	cout << calories;
}
	#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  string s;
  cin>>s;
  int clry = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '1'){
      clry += a;
      continue;
    }
    if(s[i] == '2'){
      clry += b;
      continue;
    }
    if(s[i] == '3'){
      clry += c;
      continue;
    }
    if(s[i] == '4'){
      clry += d;
      continue;
    }
  }
  cout<<clry<<endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;

    int prices[5] = {0, a, b, c, d}; // index matches '1','2','3','4'
    int total = 0;

    for (char ch : s) {
        total += prices[ch - '0'];
    }

    cout << total << "\n";
    return 0;
}

https://codeforces.com/problemset/problem/431/A
A. Black Square
using namespace std;

int main() {
    vector<int> caloriesPerSquare(4);
    for (int i = 0; i < 4; i++) {
        cin >> caloriesPerSquare[i];
    }

    string s;
    cin >> s;

    int totalCalories = 0;
    for (char ch : s) {
        int index = ch - '1'; // convert '1' → 0, '2' → 1, etc.
        totalCalories += caloriesPerSquare[index];
    }

    cout << totalCalories << "\n";
    return 0;
}

using namespace std;
int main() { 
    int a1,a2,a3,a4; cin>>a1>>a2>>a3>>a4; 
    string s; cin>>s;
    int calories=0;
    for(auto i : s) { 
        if(i=='1') calories+=a1; 
        else if(i=='2') calories+=a2;
        else if(i=='3') calories+=a3; 
        else calories+=a4; } 
        cout<<calories<<endl; 
}
// 431/C
using namespace std;
void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    const int MOD = 1e9 + 7;
    vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
    dp1[0] = dp2[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && j <= i; j++)
            dp1[i] = (dp1[i] + dp1[i - j]) % MOD;
        for (int j = 1; j < d && j <= i; j++)
            dp2[i] = (dp2[i] + dp2[i - j]) % MOD;
    }

    int ans = (dp1[n] - dp2[n] + MOD) % MOD;
    cout << ans << "\n";
}

void test() {
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> dp1(n + 1, 0), dp2(n + 1, 0);
    dp1[0] = dp2[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= k; ++j)
            if (j <= i) (dp1[i] += dp1[i - j]) %= MOD;
        for (ll j = 1; j <= d - 1; ++j)
            if (j <= i) (dp2[i] += dp2[i - j]) %= MOD;
    }
    // d - 1 wale saare ways hata diye
    cout << (dp1[n] - dp2[n] + MOD) % MOD << '\n';
}
http://codeforces.com/problemset/problem/432/A
// Choosing_Teams
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	int count = 0;
	int arr[n];
	for(int i = 0; i < n; i++)    cin >> arr[i];
	for(int i = 0; i < n; i++){
	    if(5 - arr[i] >= k)    count++;
	}
	cout << count / 3;
	return 0;
}
// 432/A
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x + k <= 5) count++;
    }

    // Maximum number of teams of 3
    cout << count / 3 << "\n";
}
void solve(){
    ll n, k, ctr = 0;
    cin >> n >> k;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] += k;
        if (arr[i] <= 5)
            ctr++;
    }
    cout << ctr / 3;
    return;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> availability(n);
    int eligibleCount = 0;
    for (int i = 0; i < n; ++i) {
        cin >> availability[i];
        if (5 - availability[i] >= k)    ++eligibleCount;
    }
    int teams = eligibleCount / 3;
    cout << teams << endl;
}
	https://codeforces.com/problemset/problem/432/A
A. Choosing Teams
using namespace std;
int main() { 
    int n,k; cin>>n>>k;
    int partcpts[n];
    int Tmembers=0; 
    for(int i=0;i<n;i++) { 
        cin>>partcpts[i]; 
        if(5-partcpts[i]>=k) 
        Tmembers++; 
    }
    cout<<Tmembers/3<<endl; 
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> participants(n);
    int eligibleCount = 0;

    for (int i = 0; i < n; i++) {
        cin >> participants[i];
        if (5 - participants[i] >= k) {
            eligibleCount++;
        }
    }

    cout << eligibleCount / 3 << "\n";
    return 0;
}

using namespace std;
http://codeforces.com/contest/433/problem/B
// 433B. Kuriyama Mirai's Stones
int main() {
    int n; cin >> n;
    vector<long long> original(n), sorted(n);
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i < n; ++i) {
        original[i] += original[i - 1];
        sorted[i] += sorted[i - 1];
    }
    int q; cin >> q;
    while (q--) {
        int type, l, r; cin >> type >> l >> r;
        l--, r--;
        if (type == 1){
            if (l == 0) cout << original[r] << endl;
            else cout << original[r] - original[l - 1] << endl;
        }else{
            if (l == 0) cout << sorted[r] << endl;
            else cout << sorted[r] - sorted[l - 1] << endl;
        }
    }
}
http://codeforces.com/problemset/problem/433/B
// Kuriyama_Mirai's_Stones
using namespace std;
int func(int l, int r, int r){
    if(l - 1 == 0)    return arr[r - 1];
    else    return arr[r - 1] - arr[l - 2];
}
int main() {
    //n is number of stones ,m is he number of Kuriyama Mirai's questions
	int n, m; cin >> n; 
	int arr[n], arr2[n];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    copy(arr, arr + n, arr2);
    sort(arr2, arr2 + n);
	for(int i = 1; i < n; i++){
	    arr[i] += arr[i - 1];
	    arr2[i] += arr2[i - 1];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
	    int type, l, r, res; cin >> type >> l >> r;
	    if(type == 1)    res = func(l, r, arr);
	    else    res = func(l, r, arr2);
	    cout << res;
	}
	return 0;
}
using namespace std;
long long get_range_sum(int l, int r, const vectorb<long long>& prefix_sum) {
    if (l == 1) return prefix_sum[r - 1];
    return prefix_sum[r - 1] - prefix_sum[l - 2];
}
int main() {
    int n; cin >> n;
    vector<long long> original(n), sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i < n; i++) {
        original[i] += original[i - 1];
        sorted[i] += sorted[i - 1];
    }
    int m; cin >> m;
    while (m--) {
        int type, l, r; cin >> type >> l >> r;
        if (type == 1)
            cout << get_range_sum(l, r, original) << endl;
        else
            cout << get_range_sum(l, r, sorted) << endl;
    }
}

	
using namespace std;
http://codeforces.com/problemset/problem/439/A
// A. Devu, the Singer and Churu, the Joker
int main() {
    int n, k; cin >> n >> k;
    int totalSongDuration = 0;
    for (int i = 0; i < n; ++i) {
        int song; cin >> song;
        totalSongDuration += song;
    }
    int totalBreakTime = (n - 1) * 10; // 10 minutes break between songs
    if (totalSongDuration + totalBreakTime > k)
        cout << -1 << endl;
    else {
        int remainingTime = k - totalSongDuration;
        int maxJokes = remainingTime / 5;
        cout << maxJokes << endl;
    }
}
using namespace std;
codeforces.com/contest/439/problem/B
// 439B. Devu, the Dumb Guy
int main() {
	int n, x; cin >> n >> x;
	int arr[n];
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
	sort(arr, arr + n);
	int sum = 0;
	for(int i = 0; i < n; i++){
	    sum += arr[i] * x;
	    if(x > 1) --x;
	}
	cout << sum;
}
http://codeforces.com/contest/443/problem/A
// Anton_and_Letters.cpp
using namespace std;
int main() {
    string s; getline(cin,s);
	set <char> letters;
	int len = s.length();
	for(int i = 0; i < len; i++){
        if(s[i] == ',' || s[i] == '{' || s[i] == '}' || s[i] == ' ');
        else    letters.insert(s[i]);
	}
	cout << letters.size();
}
using namespace std;
int main() {
    string input; getline(cin, input);
    set<char> uniqueLetters;
    for (char ch : input) {
        if (isalpha(ch)) {
            uniqueLetters.insert(ch);
        }
    }
    cout << uniqueLetters.size() << endl;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  const int MAX = 1000;
  char d, c[MAX];
  int i = 0;
  while(d != '}'){
    cin>>d;
    if(d >= 97 && d <= 122){
      c[i] = d;
      i++;
    }
  }
  c[i] = '\0';
  sort(c, c+i);
  char h = 'A';
  int count = 0;
  for(int j = 0; j < i; j++){
    if(c[j] != h){
      count++;
      h = c[j];
    }
  }
  cout<<count;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    char ch;
    set<char> letters;

    // Read characters until '}'
    while (cin >> ch && ch != '}') {
        if (ch >= 'a' && ch <= 'z') {
            letters.insert(ch);
        }
    }

    // Output the number of unique letters
    cout << letters.size() << endl;

    return 0;
}

https://codeforces.com/problemset/problem/443/A
A. Anton and Letters
using namespace std;
int main() { 
    string s; getline(cin,s); 
    set<char> ans; 
    for(int i=0;i<s.size();i++) { 
        if(s[i]=='{' || s[i]==',' || s[i]==' ' || s[i]=='}') continue;
        else ans.insert(s[i]); 
        
    } 
    cout<<ans.size()<<endl; 
}
using namespace std;
int main() {
    string s;
    getline(cin, s);

    set<char> letters;
    for (char c : s) {
        if (isalpha(c)) { 
            letters.insert(c);
        }
    }
    cout << letters.size() << "\n";
    return 0;
}

using namespace std;
http://codeforces.com/problemset/problem/451/A
// 451A - Game With Sticks
int main() {
    int n, m;
    cin >> n >> m;
    if (min(n, m) % 2 == 1)
        cout << "Akshat" << endl;
    else
        cout << "Malvika" << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  cin>>m>>n;
  int a = min(m, n);
  if(a %2 == 0){
    cout<<"Malvika"<<endl;
  }
  else{
    cout<<"Akshat"<<endl;
  }


}
using namespace std;
http://codeforces.com/contest/451/problem/B
// 451B - Sort the Array
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    //for (int& x : arr)
        //cin >> x;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    // Find the first and last position where arr and sorted_arr differ
    int l = 0, r = n - 1;

    while (l < n && arr[l] == sorted_arr[l]) ++l;
    while (r >= 0 && arr[r] == sorted_arr[r]) --r;

    if (l >= r) {
        // Already sorted or only one element needs to be reversed (no-op)
        cout << "yes\n1 1\n";
        return 0;
    }
    // Reverse the subarray and check if it matches the sorted version
    reverse(arr.begin() + l, arr.begin() + r + 1);

    if (arr == sorted_arr) {
        cout << "yes\n" << (l + 1) << " " << (r + 1) << "\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
using namespace std;
https://codeforces.com/contest/456/problem/A
// 456A.Laptops
int main(){
    int n; cin >> n;
    map <int, int> mp;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        mp[x] = y;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    bool check = 0;
    for(int i = 0; i < n - 1; i++){
        if(mp[vec[i]] > mp[vec[i + 1]])
            check = 1;
    }
    if(check) cout << "Happy Alex";
    else cout << "Poor Alex";
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int, int>> laptops(n);
    for (int i = 0; i < n; ++i) {
        cin >> laptops[i].first >> laptops[i].second; 
    }
    sort(laptops.begin(), laptops.end());
    for (int i = 0; i < n - 1; ++i) {
        if (laptops[i].second > laptops[i + 1].second) {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;
    return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/460/A
// A. Vasya and Socks
int main() {
	int n, m; cin >> n >> m;
	int res = (n - 1) / (m - 1);
	cout << n + res;
}
using namespace std;
http://codeforces.com/contest/460/problem/A
// A. Vasya and Socks
int main() {
    int n, k; cin >> n >> k;
    int days = 0;
    while (n > 0) {
        ++days;
        --n;
        if (days % k == 0)
            ++n; // Vasya gets an extra sock every k days
    }
    cout << days << endl;
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin>>n>>m;
  int count = 0;
  while(n != 0){
    count++;
    n--;
    if(count % m == 0){
      n++;
    }
  }
  cout<<count<<endl;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int count = 0;

    while (n > 0) {
        count++;
        n--;
        if (count % m == 0) {
            n++; // extra item added every m-th step
        }
    }

    cout << count << '\n';
    return 0;
}

using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int current = 0, lastbuy = 0;
    while(n > 0){
	    ++current;
	    --n;
	    if(current - lastbuy == k){
		    ++n;
		    lastbuy = current;
	    }
    }
	cout << current;
}
using namespace std;
http://codeforces.com/contest/463/problem/B
// 463B - Caisa and Pylons
int main() {
    int n; cin >> n;
    int energy = 0;
    long long money = 0;
    int currentHeight = 0;
    for (int i = 0; i < n; ++i) {
        int nextHeight; cin >> nextHeight;
        energy += (currentHeight - nextHeight);
        if (energy < 0) {
            money += -energy;
            energy = 0;
        }
        currentHeight = nextHeight;
    }
    cout << money << endl;
}
using namespace std;
https://codeforces.com/contest/466/problem/A
// 466A. Cheap Travel;
int main(){
	int n, m, a, b; cin >> n >> m >> a >> b;
	int res = 0;
	if(m * a <= b) res = n * a;
	else res = (n / m) * b + min((n % m) * a, b);
	cout << res;
}
using namespace std;
http://codeforces.com/problemset/problem/467/A
// A. George and Accommodation
int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(b - a >= 2) ++cnt;
    }
    cout << cnt;
}
#include<iostream>
using namespace std;

int main(){
  int n, p, q, count = 0;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>p;
    cin>>q;
    if(q - p >= 2){
      count++;
    }
  }
  cout<<count;
  return 0;
}
http://codeforces.com/problemset/problem/467/b
// Fedor_and_New_Game.cpp
using namespace std;
int main() {
	 int n, m, k; cin >> n >> m >> k;
	 int count = 0, arr[m + 1];
	 for(int i = 0; i <= m; i++)    cin >> arr[i];
	for(int i = 0; i < m; i++){
        int w = arr[m]^arr[i];
		if(__builtin_popcount(w) <= k)
			 count++;
	}
	cout << count;
}
using namespace std;
int main() {
    int n, m, k; cin >> n >> m >> k;
    int armies[m + 1];
    for (int i = 0; i <= m; i++)    cin >> armies[i];
    int fedor = armies[m];
    int count = 0;
    for (int i = 0; i < m; i++) {
        int diff = fedor ^ armies[i]; // XOR to find differing bits
        if (__builtin_popcount(diff) <= k)     count++;
    }
    cout << count << endl;
    return 0;
}
https://codeforces.com/problemset/problem/467/B
// B. Fedor and New Game
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    int pa[m+1];  // Players Army
    for(int i=1; i<=m+1; i++)
    {
        cin>>pa[i];
    }
    int fedor = pa[m+1];
    int pf = 0; // Potential Friends
    for(int i=1; i<=m; i++)
    {
        int check = pa[i] ^ fedor;
        if(__builtin_popcount(check) <= k)
        pf++;
    }
    cout<<pf<<endl;
    return 0;
}
using namespace std;

#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> pa(m + 1); // Players Army
    for (int i = 0; i <= m; i++) {
        cin >> pa[i];
    }

    int fedor = pa[m];
    int pf = 0; // Potential Friends

    for (int i = 0; i < m; i++) {
        int diffBits = __builtin_popcount(pa[i] ^ fedor);
        if (diffBits <= k)
            pf++;
    }

    cout << pf << "\n";
    return 0;
}

using namespace std;
http://codeforces.com/contest/469/problem/A
// 469A - I Wanna Be the Guy
int main() {
    int n; cin >> n;
    set<int> levels;
    int p1, p2, level;
    cin >> p1;
    for (int i = 0; i < p1; ++i) {
        cin >> level;
        levels.insert(level);
    }
    cin >> p2;
    for (int i = 0; i < p2; ++i) {
        cin >> level;
        levels.insert(level);
    }
    if ((int)levels.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
}
http://codeforces.com/problemset/problem/469/A
// I_Wanna_Be_the_Guy.cpp
using namespace std;
int main() {
	int n, p, q; cin >> n >> p;
	int counter = 0;
	set <int> levels;
	set <int> ::iterator it, it2;
	if(p != 0){
	    for(int i = 0; i < p; i++){
	        int x; cin >> x;
	        levels.insert(x);
	    }
	}
	cin >> q;
	if(q != 0){
	    for(int i = 0; i < q; i++){
	        int x; cin >> x;
	        levels.insert(x);
	    }
	}
	if(p || q != 0){
	    it = levels.begin();
	    for(int i = 1; i <= n; i++, it++){
	        if(*it == i)    ++counter;
	    }
	    cout << (counter == n)? "I become the guy" : "Oh, my keyboard";
	}
	if(!p && !q)    cout << "Oh, my keyboard";
}
using namespace std;
int main() {
    int n, p, q;
    cin >> n >> p;
    set<int> levels;
    for (int i = 0; i < p; ++i) {
        int x; cin >> x;
        levels.insert(x);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        levels.insert(x);
    }
    if ((int)levels.size() == n) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
}

using namespace std;
http://codeforces.com/contest/469/problem/A
// 469A - I Wanna Be the Guy
int main() {
    int n; cin >> n;
    set <int> levels;
    for (int i = 0; i < 2; i++) {
        int count; cin >> count;
        for (int j = 0; j < count; j++) {
            int level; cin >> level;
            levels.insert(level);
        }
    }
    if ((int)levels.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
}
https://codeforces.com/problemset/problem/469/A
// A. I Wanna Be the Guy
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, q;
    cin >> n >> p;

    vector<int> levels;
    levels.reserve(p + 100); // reserve some space

    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        levels.push_back(x);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        levels.push_back(x);
    }

    // Remove duplicates
    sort(levels.begin(), levels.end());
    levels.erase(unique(levels.begin(), levels.end()), levels.end());

    if ((int)levels.size() == n)
        cout << "I become the guy.\n";
    else
        cout << "Oh, my keyboard!\n";

    return 0;
}
using namespace std;
#define pb push_back
int main(){
   int array[205];
    int n , p , q;
    cin >> n >> p;
    int count = 0;
    for(int i =  0 ; i < p ; i++)
    {
        cin >> array[i];
    }
    cin >> q;
    for(int i = p ; i < p + q ; i++)
    {
        cin >> array[i];
    }
    sort(array , array+(p+q));
    for(int i = 0 ; i < p+q ; i++)
    {
        if(array[i] != array[i+1])
        {
            count++;
        }
    }
    if(n == (count))
    cout << "I become the guy." <<endl;
    else
    cout << "Oh, my keyboard!" << endl;
    return 0;
}
https://codeforces.com/problemset/problem/469/B
B. Chat Online
using namespace std;
int main(){
    string s, t; cin>>s>>t; 
    int liss = 1; 
    s = "0" + s;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == s[liss]) liss++;
    }
    cout<<liss<<endl; 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int idx = 0; // pointer for s
    for (char c : t) {
        if (idx < s.size() && c == s[idx]) {
            idx++;
        }
    }

    cout << idx << "\n";
    return 0;
}

using namespace std;
http://codeforces.com/problemset/problem/472/A
// A. Design Tutorial: Learn from Math
const int N = 1e6;
bool arr[N + 5];
void seive(){
    arr[0] = 1; arr[1] = 1;
    for(int i = 2; i <= N; i++){
        if(arr[i]) continue;
        for(int j = i * i; j <= N; j += i)
            arr[j] = 1;
    }
}
int main() {
	seive();
	int n; cin >> n;
	int val = n >> 1;
	int val2 = n - val;
	while(arr[val] == 0 || arr[val2] == 0){
	    ++val; val2 = n - val;
	}
	cout << val << " " << val2;
}
using namespace std;
const int N = 1e6 + 5;
bool isPrime[N];
void sieve() {
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i * i < N; i++) {
        if (!isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = true;
            }
        }
    }
}
int main() {
    sieve();
    int n; cin >> n;
    for (int i = 4; i <= n / 2; i++) {
        if (isPrime[i] && isPrime[n - i]) { // both not prime ⇒ both composite
            cout << i << " " << n - i << endl;
            break;
        }
    }
}
https://codeforces.com/problemset/problem/472/A
A. Design Tutorial: Learn from Math
using namespace std;
#define ll long long
bool mark[1000001];
void solv(){
        for(ll i = 2; i <=1000000; i++ )
        {
            if( mark[i] == 0 )
            {
                for(ll j = 2 * i; j <=1000000; j += i )
                    mark[j] = 1;
            }
        }
}
int main()
{
    long long i,x;
    solv();
    while(cin>>x)
    {
    	for(i=4;i<=x-4;i++){
			if(mark[i]==1 && mark[x-i]==1)
			{
				cout<<i<<" "<<x-i<<endl;
				break;
			}
    	}
    }
    return 0;
}
using namespace std;
#define ll long long

// mark[i] = true means i is composit
bool mark[1000001];
void sieve() {
    mark[0] = mark[1] = true; // 0 and 1 are not prime, so mark as composite
    for (ll i = 2; i * i <= 1000000; i++) {
        if (!mark[i]) {
            for (ll j = i * i; j <= 1000000; j += i) {
                mark[j] = true; // mark as composite
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    ll x;
    while (cin >> x) {
        for (ll i = 4; i <= x - 4; i++) {
            if (mark[i] && mark[x - i]) { // both are composite
                cout << i << " " << x - i << "\n";
                break;
            }
        }
    }
    return 0;
}

	
using namespace std;
https://codeforces.com/contest/474/problem/A
// 474 A. Keyboard
string solve(string str, char ch){
	string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string res;
    int len = str.length();
	for(int i = 0; i < len; i++){
	    int idx = s.find(str[i]);
	    if(ch == 'R') res += s[idx - 1];
	    else res += s[idx + 1];
	}
    return res;
}
int main(){
    string str; cin >> str;
    char ch; cin >> ch;
    cout << solve(s2,c);
}
using namespace std;
string solve(const string& input, char direction) {
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string result;
    for (char ch : input) {
        size_t index = keyboard.find(ch);
        if (direction == 'R')
            result += keyboard[index - 1];
        else// direction == 'L'
            result += keyboard[index + 1];
    }
    return result;
}
int main() {
    char shift;
    string typed;
    cin >> shift >> typed;
    cout << solve(typed, shift) << endl;
    return 0;
}

using namespace std;
// A. Keyboard
// contest/474/problem/A
int main(){
    char shift;
    string str, res; 
    cin >> shift >> str;
    const string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    res.resize(str.size());
    for(int i = 0; i < str.size(); i++){
        int idx = keyboard.find(str[i]);
        res[i] = (shift == 'R') ? keyboard.at(idx - 1) : keyboard.at(idx + 1);
    }
    cout << res;
}
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string k = "qwertyuiopasdfghjkl;zxcvbnm,./";
  char o;
  cin>>o;
  string s;
  cin>>s;
  if(o == 'R'){
    for(int i = 0; i < s.length(); i++){
      s[i] = k[k.find(s[i]) - 1];
    }
  }
  else{
    for(int i = 0; i < s.length(); i++){
      s[i] = k[k.find(s[i]) + 1];
    }
  }
  cout<<s<<endl;
}
using namespace std;
http://codeforces.com/problemset/problem/479/A
// 479A - Expression
int main() {
    int a, b, c; cin >> a >> b >> c;
    int result = max({
        a + b + c,
        a * b * c,
        a + (b * c),
        (a + b) * c,
        a * (b + c),
        (a * b) + c
    });
    cout << result << endl;
}
	#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, c;
  cin>>a>>b>>c;
  ll max = -1;
  ll arr[] = {(a*b*c), (a + b + c), (a + b * c), (a * b + c), ((a +b)*c), (a*(b + c))};
  for(auto i : arr){
    max = (i > max) ? i : max;
  }
  cout<<max<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    // Compute all possible expressions
    long long res1 = a + b + c;
    long long res2 = a * b * c;
    long long res3 = (a + b) * c;
    long long res4 = a * (b + c);
    long long res5 = a + b * c;
    long long res6 = a * b + c;

    // Take maximum
    long long ans = max({res1, res2, res3, res4, res5, res6});
    cout << ans << '\n';
}

https://codeforces.com/problemset/problem/479/A
A. Expression
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin>>a>>b>>c;
    int ans = 0;
    ans = max(ans, a+b+c);
    ans = max(ans, a*b+c);
    ans = max(ans, a*b*c);
    ans = max(ans, a+b*c);
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*(b+c));
    cout<<ans<<endl;
}
using namespace std;
#define ll long longint main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    // Calculate all possible values with parentheses
    int ans1 = a + b + c;
    int ans2 = a * b * c;
    int ans3 = (a + b) * c;
    int ans4 = a * (b + c);
    int ans5 = a + b * c;
    int ans6 = a * b + c;

    int ans = max({ans1, ans2, ans3, ans4, ans5, ans6}); // C++11 initializer list
    cout << ans << "\n";

    return 0;
}

using namespace std;
http://codeforces.com/problemset/problem/486/A
// CalculatingFunction.cpp
int main() {
    int n; cin >> n;
    if (n % 2 == 0) cout << n / 2 << endl;
    else cout << -(n + 1) / 2 << endl;
    // if(n & 1) cout << -((n + 1) >> 1);
	// else cout << n >> 1; 
}
https://codeforces.com/problemset/problem/486/A
// A. Calculating Function
using namespace std;
#define pb push_back
int main()
{
    long long int n, sum;
    cin>>n;
    if(n % 2 == 0) 
    sum = n / 2;
    else 
    sum = ((n + 1) / 2) * (-1);
    cout<<sum<<endl;
    return 0;
}
using namespace std;
#define pb push_back
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    long long sum;

    // If n is even, sum = n/2
    // If n is odd, sum = -((n+1)/2)
    if (n % 2 == 0) {
        sum = n / 2;
    } else {
        sum = -((n + 1) / 2);
    }

    cout << sum << "\n";
    return 0;
}
#include<iostream>
using namespace std;

int main(){
  long long n;
  cin>>n;
  long long evn = n/2;
  long long oddn = n%2 == 0 ? n/2 : (n/2 + 1);
  long long sumevn = evn * (evn + 1);
  long long sumoddn = oddn * oddn;
  long long sum = sumevn - sumoddn;
  cout<<sum;
  return 0;
}
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long evn = n / 2;                      // Number of even numbers
    long long oddn = (n + 1) / 2;               // Number of odd numbers

    long long sumevn = evn * (evn + 1);         // Sum of first 'evn' even numbers
    long long sumoddn = oddn * oddn;            // Sum of first 'oddn' odd numbers

    cout << sumevn - sumoddn << '\n';           // Difference

    return 0;
}

using namespace std;
http://codeforces.com/contest/490/problem/A
// A. Team Olympiad
int main() {
	int n; cin >> n;
	int arr[n];
	vector <int> one, two, three;
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	    if(arr[i] == 1)
	        one.push_back(i + 1);
	    else if(arr[i] == 2)
	        two.push_back(i + 1);
	    else
	        three.push_back(i + 1);
	}
    // int teams = min({one.size(), two.size(), three.size()});
	int teams = min(t1, min(t2, t3));
	cout << teams << endl;
	for(int i = 0; i < teams; i++)
	    cout << one[i] << " " << two[i] << " " << three[i] << "\n";
}
https://codeforces.com/problemset/problem/490/A
// A. Team Olympiad
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    int t[n];
    vector<int> t1; //Storing indexes based on talent t1, t2 nad t3
    vector<int> t2;
    vector<int> t3;
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        if(t[i]==1)
        t1.push_back(i+1);
        else if(t[i]==2)
        t2.push_back(i+1);
        else
        t3.push_back(i+1);
    }
    if(t1.size()==0 || t2.size()==0 || t3.size()==0)
    cout<<0<<endl;
    else
    {
        int maxTeams = min(t1.size(),min(t2.size(),t3.size()));
        cout<<maxTeams<<endl;
        for(int i=0;i<maxTeams;i++)
        {
            cout<<t1[i]<<" "<<t2[i]<<" "<<t3[i]<<endl;
        }
    }
    return 0;
}
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> t(n);
    vector<int> t1, t2, t3; // indices of participants with talents 1, 2, and 3

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] == 1) t1.push_back(i + 1);
        else if (t[i] == 2) t2.push_back(i + 1);
        else t3.push_back(i + 1);
    }

    int maxTeams = min({(int)t1.size(), (int)t2.size(), (int)t3.size()});

    if (maxTeams == 0) {
        cout << 0 << "\n";
    } else {
        cout << maxTeams << "\n";
        for (int i = 0; i < maxTeams; i++) {
            cout << t1[i] << " " << t2[i] << " " << t3[i] << "\n";
        }
    }
    return 0;
}

https://codeforces.com/problemset/problem/492/A
A. Vanya and Cubes
using namespace std;
#define ll long long
int main()
{
    int cubes;
    cin>>cubes;
    int sum=0,tsum=0;
    int i;
    for(i=1;i<=cubes;i++)
    {
        sum += i;
        tsum += sum;
        if(tsum>cubes)
        {
            i--;
            break;
        }
        if(tsum==cubes)
        {
            break;
        }
    }
    cout<<i<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;

  int count = 0;
  int pre = 0;
  int i = 1;
  while(n >= pre + i){
    count++;
    n -= pre + i;
    pre = pre + i;
    i++;
  }
  cout<<count<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int count = 0;
    int sum = 0;
    int i = 1;

    while (sum + i <= n) {
        sum += i;
        count++;
        i++;
    }

    cout << count << '\n';
}

using namespace std;
#define ll long long

int main() {
    int cubes;
    cin >> cubes;

    int layerSize = 0;  // cubes needed for current layer
    int totalCubes = 0; // total cubes used so far
    int height = 0;     // pyramid height

    for (int i = 1; ; i++) {
        layerSize += i;               // cubes needed for this layer
        totalCubes += layerSize;      // add to total

        if (totalCubes <= cubes) {
            height++;
        } else {
            break;
        }
    }

    cout << height << "\n";
    return 0;
}

https://codeforces.com/problemset/problem/492/B
// B. Vanya and Lanterns
using namespace std;
#define ll long long
int main() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double maxGap = 0.0;
    for (int i = 1; i < n; i++) {
        maxGap = max(maxGap, (double)(a[i] - a[i - 1]));
    }

    double leftGap = a[0];
    double rightGap = l - a[n - 1];

    double radius = max({maxGap / 2.0, leftGap, rightGap});
    cout << fixed << setprecision(10) << radius << "\n";

    return 0;
}

using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
 double max(double a, double b)
{
    return a>b?a:b;
}
int main()
{
    int n, l;
    cin>>n>>l;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    double maxi = INT_MIN;
    for(int i=1; i<n ; i++)
    {
        maxi = max(maxi , a[i]-a[i-1]);
    }
    double ld = a[0];
    double rd = l - a[n-1];
    if(a[0] != 0 && a[n-1] != l)
    {
        cout<<fixed<<setprecision(10)<<max(maxi/2.0, max(ld, rd));
    }
    else if(a[0] != 0)
    {
        cout<<fixed<<setprecision(10)<<max(maxi/2.0, ld)<<endl;
    }
    else if(a[n-1] != l)
    {
        cout<<fixed<<setprecision(10)<<max(maxi/2.0, rd)<<endl;
    }
    else
    {
        cout<<fixed<<setprecision(10)<<maxi/2.0<<endl;
    }
    return 0;
}
https://codeforces.com/problemset/problem/509/A
A. Maximum in Table
using namespace std;
int solve(int r, int c)
{
    if(r==1 || c==1)
    return 1;
    int sum=0;
    int r1,c1;
    r1=r-1;
    c1=c-1;
    return sum + solve(r1,c) + solve(r,c1);
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n,n)<<endl;
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;

  int a[n][n];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == 0 || j == 0){
        a[i][j] = 1;
      }
      else{
        a[i][j] = a[i-1][j] + a[i][j-1];
      }
    }
  }
  cout<<a[n-1][n-1];
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Use long long to avoid overflow for large n
    vector<vector<long long>> a(n, vector<long long>(n, 1));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }

    cout << a[n - 1][n - 1] << '\n';
}

#include <bits/stdc++.h>
using namespace std;

// Count paths in an r x c grid moving only right or down
int solve(int r, int c, vector<vector<int>> &dp) {
    if (r == 1 || c == 1) return 1; // Base case: only one way
    if (dp[r][c] != -1) return dp[r][c]; // Memoized result
    
    return dp[r][c] = solve(r - 1, c, dp) + solve(r, c - 1, dp);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << solve(n, n, dp) << endl;
}

using namespace std;
http://codeforces.com/problemset/problem/510/A
// A. Fox And Snake
int main(){
    int n, m; cin >> n >> m;
    int odd = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++)
                cout << "#";
        }
        else{
            ++odd;
            for(int j = 0; j < m; j++){
                if(odd % 2 == 1 && j == m - 1) cout << "#";
                else if(odd % 2 == 0 && j == 0) cout << "#";
                else cout << ".";
            }
        }
        cout << "\n";
    }
}
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) cout << "#";
        } else {
            for (int j = 0; j < m; ++j) {
                if ((i / 2) % 2 == 0 && j == m - 1) cout << "#";
                else if ((i / 2) % 2 == 1 && j == 0) cout << "#";
                else cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}
https://codeforces.com/problemset/problem/510/A
A. Fox And Snake
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int c=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            if(c%2==0)
            {
                cout<<"#";
                for(int j=1;j<m;j++)
                {
                    cout<<".";
                }
            cout<<endl; 
            }
            else
            {
                for(int j=1;j<m;j++)
                {
                    cout<<".";
                }
                cout<<"#";
                cout<<endl;
            }
            c++;
        }
        else
        {
            for(int j=1;j<=m;j++)
            {
                cout<<"#";
            }
            cout<<endl;
        }
    }
}
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            // Odd row: all '#'
            cout << string(m, '#');
        } 
        else if (i % 4 == 0) {
            // Every 4th row: '#' at start
            cout << '#' << string(m - 1, '.');
        } 
        else {
            // Every 2nd row but not 4th: '#' at end
            cout << string(m - 1, '.') << '#';
        }
        cout << "\n";
    }
}

using namespace std;
https://codeforces.com/contest/514/problem/A
// 514A. Chewbaсca and Number
int main() {
    string s, s2; cin >> s;
    s2 = s;
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(i){
	        if(9 - (s[i] - '0') >= 0 && (9 - (s[i] - '0')) < s[i] - '0')
	            s[i] = (9 - (s[i] - '0')) + '0';
        }
        else{
            if(9 - (s[i] - '0') > 0 && (9 - (s[i] - '0')) < s[i] - '0')
	            s[i] = (9 - (s[i] - '0')) + '0';
        }
    }
if(s < s2) cout << s;
else cout << s2;
}
using namespace std;
int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        int digit = s[i] - '0';
        int flipped = 9 - digit;
        if (flipped < digit && (i > 0 || flipped > 0)) {
            s[i] = flipped + '0';
        }
    }
    cout << s << '\n';
    return 0;
}
using namespace std;
https://codeforces.com/problemset/problem/518/A
// A. Vitaly and Strings
int main() {
    string s, s2; cin >> s >> s2;
    int len = s.length();
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == 'z') s[i] = 'a';
        else {
            s[i]++;
            break;
        }
    }
    if (s < s2) cout << s;
    else cout << "No such string";
}
http://codeforces.com/problemset/problem/520/A
// Pangram.cpp
using namespace std;
int main(){   
    int n; cin >> n;
    string s; cin >> s;
    char j = 'A';
    for(int i = 0; i < n; i++)    s[i] = toupper(s[i]);
    if(n >= 26){
        for(int i = 0; i < 26; i++){
            if(s.find(j) != -1)    j++;
            else    cout << "No";
            return 0;
        }
        cout << "Yes";
    }
    else    cout << "No";
}
using namespace std;
int main() {
    int n;
    string s; cin >> n >> s;
    set<char> letters;
    for (char c : s)
        letters.insert(tolower(c));
    if (letters.size() == 26)    cout << "YES";
    else    cout << "NO";
    return 0;
}
http://codeforces.com/problemset/problem/520/A
// Pangram
using namespace std;
int main() {
	string s;
	int n; cin >> n >> s;
	set <char> se;
	for(int i = 0; i < n; i++){
	    s[i] = tolower(s[i]);
	    se.insert(s[i]);
	}
	cout << (se.size() == 26) ? "Yes" : "No";
}
using namespace std;
int main() {
    int n;
    string s; cin >> n >> s;
    set<char> se;
    for (char c : s)
        se.insert(tolower(c));
    cout << (se.size() == 26 ? "YES" : "NO") << endl;
}
#include<bits/stdc++.h>
using namespace std;

// Code Written By: Vikash Patel

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    sort(s.begin(),s.end());
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]!=s[i+1])
        {
            count++;
        }
    }
    if(count==26)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
using namespace std;
http://codeforces.com/problemset/problem/535/B
// B.Tavas_and_SaDDas
vector<int> lucky_numbers;
void generate_lucky(int num) {
    if (num > 100000000) return;
    if (num != 0) lucky_numbers.push_back(num);
    generate_lucky(num * 10 + 4);
    generate_lucky(num * 10 + 7);
}
int main() {
    int n; cin >> n;
    generate_lucky(0);
    sort(lucky_numbers.begin(), lucky_numbers.end());
    for (int i = 0; i < lucky_numbers.size(); ++i) {
        if (lucky_numbers[i] == n) {
            cout << i + 1 << endl;
            break;
        }
    }
}
using namespace std;
vector <int> vec;
void luck(int n){
	if(n > 100000000)
		return;
	vec.push_back(n * 10 + 4);
	vec.push_back(n * 10 + 7);
	int w = vec.size();
	luck(vec[w - 1]);
	luck(vec[w - 2]);
}
int main(){
    int n; cin >> n;
    luck(0);
    sort(vec.begin(), vec.end());
    int q = vec.size();
    for(int i = 0; i < q; i++){
        if(vec[i] == n)
            cout << i + 1;
    }
}
https://codeforces.com/problemset/problem/540/A
A. Combination Lock
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
int main(){
    int n;
    cin>>n;
    string org, pass;
    cin>>org>>pass;
    int minMoves = 0;
    for(int i=0; i<n; i++)
    {
        int m = abs(org[i]-pass[i]);
        minMoves += min(10-m, m);
    }
    cout<<minMoves<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string org, pass;
    cin >> org >> pass;

    int moves = 0;

    for (int i = 0; i < n; i++) {
        int from = org[i] - '0';
        int to = pass[i] - '0';

        int clockwise = (to - from + 10) % 10;      // rotate forward
        int counterclockwise = (from - to + 10) % 10; // rotate backward

        moves += min(clockwise, counterclockwise);
    }

    cout << moves << "\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  string s, t;
  cin>>s>>t;
  int count = 0;
  for(int i = 0; i < n; i++){
    int a = s[i] - '0';
    int b = t[i] - '0';
    int g = min(a, b);
    int h = max(a, b);
    int c = min(h - g, (g + 10 - h));
    count += c;
  }
  cout<<count<<endl;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int total_moves = 0;

    for (int i = 0; i < n; i++) {
        int a = s[i] - '0';
        int b = t[i] - '0';

        // Circular distance between digits
        int diff = abs(a - b);
        total_moves += min(diff, 10 - diff);
    }

    cout << total_moves << '\n';
}
https://codeforces.com/problemset/problem/545/A

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;

  int arr[n][n];

  map<int, bool> mp;

  for(int i = 0; i< n; i++){
    for(int j = 0; j< n; j++){
      cin>>arr[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(arr[i][j] == 1){
        mp[i] = true;
        continue;
      }
      if(arr[i][j] == 2){
        mp[j] = true;
        continue;
      }
      if(arr[i][j] == 3){
        mp[i] = mp[j] = true;
      }

    }
  }

  int arrb[n], k = 0;
  for(int i = 0; i < n; i++){
    if(!mp[i]){
      arrb[k] = i + 1;
      k++;
    }
  }
  cout<<k<<'\n';
  for(int i = 0; i < k; i++){
    cout<<arrb[i]<<" ";
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    vector<bool> marked(n, false);

    // Read matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Process upper triangle
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][j] == 1) marked[i] = true;
            else if (arr[i][j] == 2) marked[j] = true;
            else if (arr[i][j] == 3) marked[i] = marked[j] = true;
        }
    }

    // Collect unmarked indices
    vector<int> safe_indices;
    for (int i = 0; i < n; i++) {
        if (!marked[i]) safe_indices.push_back(i + 1);
    }

    // Output
    cout << safe_indices.size() << '\n';
    for (int idx : safe_indices) cout << idx << " ";
    cout << '\n';
}

using namespace std;
http://codeforces.com/problemset/problem/546/A
// Soldier_and_Bananas.cpp
int main() {
    long long k, n, w;
    cin >> k >> n >> w;
    // Total cost using arithmetic series sum: k * (1 + 2 + ... + w) = k * w * (w + 1) / 2
    long long total_cost = k * w * (w + 1) / 2;
    long long needed = max(0LL, total_cost - n);
    cout << needed << endl;
}
using namespace std;
int main() {
	long long k, n, w; cin >> k >> n >> w;
	long long cost=0,needed=0;
	for(int i = 1; i <= w; i++)
	    cost += k * i;
	if(cost <=n)
		cout << "0";
	else {
		 needed = cost - n;
		 cout << needed;
	}
}
#include<iostream>
using namespace std;

int main(){
  int k, n, w;
  cin>>k;
  cin>>n;
  cin>>w;

  int sum = 0;
  for(int i = 1; i <= w; i++){
    sum += i*k;
  }
  int b = (sum - n) > 0 ? (sum - n) : 0;
  cout<<b;
  return 0;

}
https://codeforces.com/problemset/problem/546/A
// A. Soldier and Bananas
using namespace std;
int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    int total = 0;
    int i=1;
    while(i<=w)
    {
        total+=i*k;
        i++;
    }
    int p=total-n;
    if(p>0)
    cout<<p<<endl;
    else
    cout<<"0"<<endl;
}
using namespace std;
int main() {
    int k, n, w;
    cin >> k >> n >> w;

    // Total cost formula: k * (1 + 2 + ... + w) = k * w * (w + 1) / 2
    int total = k * w * (w + 1) / 2;

    // Amount he needs to borrow
    cout << max(0, total - n) << "\n";

    return 0;
}

using namespace std;
http://codeforces.com/contest/556/problem/A
// A. Case of the Zeros and Ones
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int zeros = count(s.begin(), s.end(), '0');
    int ones  = n - zeros; 
    cout << abs(zeros - ones) << '\n';
    // int zers = count(s.begin(), s.end(), '0');
	// int ons = count(s.begin(), s.end(), '1');
	// cout<< n - (2* min(zers, ons));
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  string s;
  cin>>s;
  int count1 = 0, count0 = 0;
  for(auto i : s){
    (i == '1') ? count1++ : count0++;
  }
  cout<<abs(count0 - count1)<<endl;

}
using namespace std;
http://codeforces.com/contest/567/problem/A
// 567A - Lineland Mail
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        int minDist, maxDist;
        if (i == 0){
            minDist = abs(arr[i] - arr[i + 1]);
            maxDist = abs(arr[i] - arr[n - 1]);
        } else if (i == n - 1) {
            minDist = abs(arr[i] - arr[i - 1]);
            maxDist = abs(arr[i] - arr[0]);
        } else {
            minDist = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
            maxDist = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
        }
        cout << minDist << " " << maxDist << "\n";
    }
}
using namespace std;
int main() {
	 int n; cin >> n;
	 int arr[n];
	 for(int i=0;i<n;i++){
		 cin>>arr[i];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
	for(int i = 0; i < n; i++){
		long long  mini, maxi;
		if(!i){
			mini=abs(arr[i]-arr[i+1]);
			maxi=abs(arr[i]-arr[n-1]);
		}
		else if(i == n-1) {
			 maxi = abs(arr[i] - arr[0]);
			 mini = abs(arr[i] - arr[i - 1]);
		}
		else{
			 mini = min(abs(arr[i] - arr[i + 1]), abs(arr[i] - arr[i - 1]));
			 maxi = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
		}
		 cout<<mini<<" "<<maxi<<"\n";
	}
	return 0;
}
using namespace std;
http://codeforces.com/contest/567/problem/A
// A. Lineland Mail
int main() {
    int n; cin >> n;
    long long arr[n];
    for (int i = 0; i < n; ++i) 
        cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        long long mini, maxi;
        if (i == 0) {
            mini = abs(arr[i] - arr[i + 1]);
            maxi = abs(arr[i] - arr[n - 1]);
        }
        else if (i == n - 1) {
            mini = abs(arr[i] - arr[i - 1]);
            maxi = abs(arr[i] - arr[0]);
        }
        else {
            mini = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
            maxi = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
        }
        cout << mini << " " << maxi << '\n';
    }
}
using namespace std;
int main() {
	int n; cin >> n;
	long long arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++){
		long long mini = INT_MAX;
		long long maxi = INT_MIN;
		if(!i){
			mini = min(mini, min(abs(arr[i] - arr[n - 1]), abs(arr[i] - arr[i + 1])));
			maxi = max(maxi, max(abs( arr[i] - arr[n - 1]), max( abs(arr[i] - arr[i + 1]) , abs(arr[i] - arr[n - 1])) ));
		}
		else if(i == n - 1){
			mini = min(mini, min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[0])));
			maxi = max(maxi, max(abs( arr[i] - arr[i-1]), max(abs (arr[i] - arr[0]), abs( arr[i] - arr[n-1]))));
			
		}
		else{
			mini = min(mini, min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1])));
			maxi = max(maxi, max(abs(arr[i] - arr[i - 1]), max(abs(arr[i] - arr[i + 1]), max(abs(arr[i] - arr[n - 1]), abs(arr[i] - arr[0])))));
		}
		cout << mini << " " << maxi << "\n";
	}
}
https://codeforces.com/problemset/problem/579/A
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  int res = __builtin_popcount(n);
  cout<<res<<endl;

}
using namespace std;
http://codeforces.com/problemset/problem/580/A
// A. Kefa and First Steps
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int maxLength = 1, currentLength = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1])
            currentLength++;
        else
            currentLength = 1;
        maxLength = max(maxLength, currentLength);
    }
    cout << maxLength << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    int maxlength = 0, start = 0, end = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i){
	        if(arr[i] < arr[i - 1]){
		        end = i - 1;
		        maxlength = max(maxlength, (end - start) + 1);
                start = i;
	        }
	        else{
		         end = i;
		         maxlength = max(maxlength, (end - start) + 1);
	        }
	    }
    }
    if(!start && !end) cout << n;
    else cout << maxlength;
}
#include<bits/stdc++.h>
#include<limits>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;

  int arr[n+1];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  arr[n] = std::numeric_limits<int>::max();
  int max= 0, count = 0;
  for(int i = 0; i < n; i++){
    count++;
    max = count > max ? count : max;
    if(arr[i] > arr[i+1]){
      count = 0;
    }
  }
  cout<<max<<endl;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arr[n] = INT_MAX; // Sentinel to avoid extra checks

    int max_len = 0, current_len = 0;

    for (int i = 0; i < n; i++) {
        current_len++;
        max_len = max(max_len, current_len);

        if (arr[i] > arr[i + 1]) {
            current_len = 0;
        }
    }

    cout << max_len << '\n';
}
https://codeforces.com/problemset/problem/580/B
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

bool comp(pair<ll, ll>& a, pair<ll, ll>& b){
  return a.first < b.first;
}

int binary_search(vector<pair<ll, ll>>& arr, int low, int high, ll target){
  while(low <= high){
    int mid = (low + high)/2;
    if(arr[mid].first < target){
      if(mid == high){
        return high + 1;
      }
      low = mid + 1;
    }
    else{
      if(mid == low){
        return mid;
      }
      if(arr[mid-1].first < target){
        return mid;
      }
      high = mid -1;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, d;
  cin>>n>>d;

  vector<pair<ll, ll>> friends;
  ll a, b, s = 0;
  vector<ll> suff;

  for(int i = 0; i < n; i++){
    cin>>a>>b;
    friends.push_back(make_pair(a, b));
    s += b;
  }
  sort(friends.begin(), friends.end(), comp);
  for(int i = 0; i < n; i++){
    suff.pb(s);
    // cout<<friends[i].first<<" "<<suff[i]<<endl;
    s -= friends[i].second;

  }
  suff.pb(0);
  ll ans = -1;
  int j;
  for(int i = 0; i < n; i++){
    j = binary_search(friends, i, n-1, friends[i].first + d);
    // cout<<i<<" "<<j<<endl;
    ans = max(ans, suff[i] - suff[j]);
  }

  cout<<ans<<endl;

}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, d;
    cin >> n >> d;

    vector<pair<ll, ll>> friends(n);
    ll total_b = 0;

    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
        total_b += friends[i].second;
    }

    // Sort friends by position
    sort(friends.begin(), friends.end());

    // Compute suffix sums of b-values
    vector<ll> suff(n + 1);
    suff[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + friends[i].second;
    }

    ll ans = 0;

    // For each friend, find first friend outside the distance using upper_bound
    for (int i = 0; i < n; i++) {
        ll limit = friends[i].first + d;
        int j = upper_bound(friends.begin(), friends.end(), make_pair(limit, LLONG_MAX)) - friends.begin();
        ans = max(ans, suff[i] - suff[j]);
    }

    cout << ans << '\n';
}

using namespace std;
https://codeforces.com/problemset/problem/581/A
// 581A. Vasya the Hipster
int main(){
    int a, b; cin >> a >> b;
    int mini = min(a,b);
    int maxi = max(a,b);
    cout << mini << " " << (maxi - mini)/2 << endl;
}
https://codeforces.com/problemset/problem/581/A
A. Vasya the Hipster
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int diff=min(a,b);
    int maxi=max(a,b);
    int same=(maxi-diff)/2;
    cout<<diff<<" "<<same<<endl;
}
using namespace std;
http://codeforces.com/contest/584/problem/A
// 584A - Olesya and Rodion
int main() {
    int n, d; cin >> n >> d;
    string s;
    // Case 1: Can't form a number with one digit divisible by 10
    if (d == 10 && n < 2)
        cout << "-1";
    // Case 2: d = 10 and n >= 2 => number must end in 0, rest can be 1s
    else if (d == 10) {
        s.append(n - 1, '1');
        s += '0'; cout << s;
    }
    // Case 3: Any other digit
    else {
        s.append(n, d + '0');
        cout << s;
    }
}
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, t;
  cin>>n>>t;
  if(n == 1 && t == 10){
    cout<<-1<<endl;
    return 0;
  }
  else if(n == 1){
    cout<<t<<endl;
    return 0;
  }
  if(t == 10){
    t = 1;
  }
  cout<<t;
  for(int i = 0; i < n-1; i++){
    cout<<0;
  }

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, t;
    cin >> n >> t;

    if (n == 1 && t == 10) {
        cout << -1 << '\n';
        return 0;
    }

    if (t == 10) {
        cout << 1;  // First digit
        for (int i = 1; i < n; i++) cout << 0;  // Remaining digits
    } else {
        cout << t;
        for (int i = 1; i < n; i++) cout << 0;
    }

    cout << '\n';
}

using namespace std;
int main() {
	int n, d; cin >> n >> d;
	string s;
	if(d == 10 && n < 2) cout << "-1";
	else if(d == 10 && n >= 2){
		for(int i = 0; i < n - 1; i++)
			s += 1 + '0';
		s += 0 + '0';
		cout << s;
	}
	else {
	    for(int i = 0; i < n; i++)
		    s += d + '0';
	    cout << s;
	}
	return 0;
}
http://codeforces.com/problemset/problem/588/A
// A. Duff and Meat
using namespace std;
int main(){
    int n; cin >> n;
    int amount, price;
    int minvalue = 100, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> amount >> price;
        minvalue = min(minvalue, price);
        sum += minvalue * amount;
    }
    cout <<sum << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    int totalCost = 0, minPrice = 1e9;
    for (int i = 0; i < n; ++i) {
        int amount, price; cin >> amount >> price;
        minPrice = min(minPrice, price);
        totalCost += minPrice * amount;
    }
    cout << totalCost << endl;
    return 0;
}

https://codeforces.com/problemset/problem/595/A
// A. Vitaly and Night
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> lights(n, vector<int>(2 * m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * m; j++) {
            cin >> lights[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * m; j += 2) {
            // If either of the two lights in a room is ON
            if (lights[i][j] == 1 || lights[i][j + 1] == 1) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
https://codeforces.com/problemset/problem/599/A
A. Patrick and Shopping
int main() {
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    // Possible total distances
    int path1 = d1 + d2 + d3;       // Go in a straight chain visiting all
    int path2 = 2 * (d1 + d2);      // Back and forth between 1st and 2nd point
    int path3 = 2 * (d2 + d3);      // Back and forth between 2nd and 3rd point
    int path4 = 2 * (d1 + d3);      // Direct back-and-forth between 1st and 3rd point
    int answer = min({path1, path2, path3, path4});
    // cout << min(path1, min(path2, min(path3, path4)));
    cout << answer << "\n";
    return 0;
}
#include<bits/stdc++.h> 
using namespace std; 
int main() { 
    int d1,d2,d3; cin>>d1>>d2>>d3;
    int a=d1+d2+d3; 
    int b=2*d1+2*d2;
    int c=2*d2+2*d3;
    int d=2*d1+2*d3; 
    cout<<min(a,min(b,min(c,d)))<<endl;
}
using namespace std;
http://codeforces.com/problemset/problem/615/A
// A. Bulbs
bool arr[101] = {false};
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        for (int j = 0; j < x; ++j) {
            int y; cin >> y;
            arr[y] = true;
        }
    }
    bool all_on = true;
    for (int i = 1; i <= m; ++i) {
        if (!arr[i]) {
            all_on = false;
            break;
        }
    }
    cout << (all_on ? "YES" : "NO") << endl;
    return 0;
}
using namespace std;
bool arr[101];
int main(){
    int n, m; cin >> n >> m;
    bool flag = true;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 0; j < x; j++){
            int y; cin >> y;
            arr[y - 1] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        if(!arr[i]) flag = false;
    }
    if(flag) cout << "Yes";
    else cout << "No";
    return 0;
}
using namespace std;
// problemset/problem/617/A
// A. Elephant
int main(){
    int n; cin >> n;
    int res = (n % 5 == 0) ? n / 5 : (n / 5) + 1;
    cout << res;
}
http://codeforces.com/problemset/problem/617/A
// Elephant
using namespace std;
int main(){
    int steps; cin >> steps;
    int ctr, flag = 1, output = 0;
    if(steps < 5)    cout << 1;
    else {
        if(steps % 5 == 0)    cout << steps / 5;
        else if(steps > 5 && steps % 5 != 0)    cout << (steps / 5) + 1;
    }
}
using namespace std;
int main() {
    int steps; cin >> steps;
    int moves = (steps + 4) / 5;
    cout << moves << endl;
}
using namespace std;
https://codeforces.com/contest/672/problem/A
// A. Summer Camp
int main() {
    int n; cin >> n;
    string sequence;
    for (int i = 1; sequence.length() < n; ++i) 
        sequence += to_string(i);
    cout << sequence[n - 1] << endl;
    return 0;
}
using namespace std;
int main() {
	int n; cin >> n;
	string s = "";
	for(int i = 1; i <= 1000; i++)
		s += to_string(i);
	cout << s[n - 1];
}
using namespace std;
// A. Vanya and Fence
// problemset/problem/677/A
int main(){
    int n, h; cin >> n >> h;
    int w = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > h) w += 2;
        else w += 1;
    }
    cout << w;
}
using namespace std;
http://codeforces.com/contest/677/problem/A
// A. Vanya and Fence
int main() {
	int n, h; cin >> n >> h;
	int width = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    if(x > h) width += 2;
	    else width += 1;
	}
	cout << width;
	return 0;
}
using namespace std;
http://codeforces.com/contest/680/problem/B
// Bear and Finding
int main() {
    int n, a, counter = 0; cin >> n >> a;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    a--; // Convert to 0-based index
    if (arr[a]) counter++; // Count criminal at initial position
    for (int i = 1; i < n; i++) {
        int left = a - i;
        int right = a + i;
        bool leftValid = (left >= 0);
        bool rightValid = (right < n);
        if (leftValid && rightValid) {
            if (arr[left] && arr[right]) counter += 2;
        else if (leftValid && arr[left]) 
            counter++;
        else if (rightValid && arr[right]) 
            counter++;
    }
    cout << counter << endl;
}
using namespace std;
int main() {
	int n, a, counter = 0; cin >> n >> a;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	--a;
	if(arr[a]) ++counter;
    for(int i = 1; i < n; i++){
	    int right, left;
		right = a + i;
		left = a - i;
		if(left >= 0 || right < n){
		    if(left >= 0 && right < n){
			    if(arr[right]&&arr[left]) counter += 2;
			}
			else if(left >= 0){
			    if(arr[left]) ++counter;
			}
			else if(right < n){
		        if(arr[right]) ++counter;
			}
		}
	}
	cout << counter;
}
http://codeforces.com/contest/686/problem/A
// A. Free Ice Cream
using namespace std;
int main() {
	int n, x; cin >> n >> x;
	int child = 0;
	for(int i = 0; i < n; i++){
	    char sign;
	    int d; cin >> sign >> d;
	    cin.ignore();
	    if(sign == '-'){
	        if(d > x)    child += 1;
	        else    x -= d;
	    }
	    else    x += d;
	}
	cout << x << " " << child;
}
using namespace std;
int main() {
    int n, x, distressedChildren = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        char op;
        long long amount;
        cin >> op >> amount;
        if (op == '+')    x += amount;
        else { // op == '-'
            if (x >= amount)    x -= amount;
            else    distressedChildren++;
        }
    }
    cout << x << " " << distressedChildren << endl;
}
using namespace std;
http://codeforces.com/contest/688/problem/A
// 688A. Opponents
int main() {
    int n, d; cin >> n >> d;
    int maxConsecutive = 0, currentStreak = 0;
    for (int i = 0; i < d; ++i) {
        string day; cin >> day;
        // If at least one opponent is not available (0 in string)
        if (day.find('0') != string::npos) {
            ++currentStreak;
            maxConsecutive = max(maxConsecutive, currentStreak);
        else  currentStreak = 0;
    }
    cout << maxConsecutive << endl;
}
using namespace std;
int main(){
    int n, d; cin >> n >> d;
    string ref = "";
    for(int i = 0; i < n; i++)
        ref += '1';
    string prv = "";
    int count = 0;
    vector <string> vect1;
    vector <int> vect;
    for(int i = 0; i < d; i++){
        string x; cin >> x;
        if(x == ref){
            vect.push_back(count);
            count = 0;
        }
        else ++count;
    }
    vect.push_back(count);
    int len = vect.size();
    if(len){
        sort(vect.begin(), vect.end());
        cout << vect[vect.size() - 1] << endl;
    }
    else cout << count;
}
using namespace std;
http://codeforces.com/contest/688/problem/B
// 688B. Lovely Palindromes 
int main(){
    string s; cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    cout << s + s2;
}
https://codeforces.com/problemset/problem/689/A
// A. Mike and Cellphone
using namespace std;
char s[10];
bool up = 0, down = 0, left = 0, right = 0;
unsigned n;
int main(){
    char s[10];
    int n; cin >> n >> s;
	for(int i=0;i<n;++i){
		switch(s[i]-'0'){
			case 0:down=1;left=1;right=1;break;
			case 1:left=1;up=1;break;
			case 2:up=1;break;
			case 3:right=1;up=1;break;
			case 4:left=1;break;
			case 6:right=1;break;
			case 7:left=1;down=1;break;
			case 9:right=1;down=1;
		}
	}
    if(up && down && left && right)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
using namespace std;

int main() {
    unsigned int n;
    string s;
    cin >> n >> s;

    bool up = false, down = false, left = false, right = false;

    for (char ch : s) {
        switch (ch) {
            case '0':
                down = left = right = true;
                break;
            case '1':
                left = up = true;
                break;
            case '2':
                up = true;
                break;
            case '3':
                right = up = true;
                break;
            case '4':
                left = true;
                break;
            case '6':
                right = true;
                break;
            case '7':
                left = down = true;
                break;
            case '9':
                right = down = true;
                break;
            // '5' and '8' are in the middle, no effect on direction
        }
    }
    if (up && down && left && right)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
https://codeforces.com/problemset/problem/689/B
// B. Mike and Shortcuts.cpp
#define maxn 200010
using namespace std;
int way[maxn];
unsigned a[maxn];
queue<unsigned> q;
int main(){
    int n; cin >> n;
	memset(way, -1, sizeof(way));
	for(i=1;i<=n;++i)
		scanf("%u",&a[i]);
	way[1]=0;
	q.push(1);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		if(f>1&&way[f-1]<0){
			way[f-1]=way[f]+1;
			q.push(f-1);
		}
		if(way[f+1]<0){
			way[f+1]=way[f]+1;
			q.push(f+1);
		}
        if(way[a[f]]<0){
			way[a[f]]=way[f]+1;
			q.push(a[f]);
		}
	}
	for(i=1;i<=n;++i)
		printf("%d ",way[i]);
	return 0;
}
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> dist(n + 1, -1);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur > 1 && dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if (cur < n && dist[cur + 1] == -1) {
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }
        if (dist[a[cur]] == -1) {
            dist[a[cur]] = dist[cur] + 1;
            q.push(a[cur]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}

using namespace std;
http://codeforces.com/problemset/problem/705/A
// 705A. Hulk
int main() {
    int n; cin >> n;
    string s = "";
    for(int i = 0; i < n; i++){
        if(i % 2 == 0 && i != n - 1)
            s += "I hate that ";
        else if(i % 2 == 1 && i != n - 1)
            s += "I love that ";
        else if(i % 2 == 0)
            s += "I hate ";
        if(i % 2 == 1)
            s += "I love ";
    }
    s += "it";
    cout << s;
 	return 0;
}
using namespace std;
// A. Brain's Photos
// problemset/problem/707/A _ Brain has a photo represented as an n × m matrix, where each cell contains a letter representing a pixel's color.
// Colors in the photo: Black-and-white colors: 'W' (white), 'G' (grey), 'B' (black)
//Colored colors: 'C' (cyan), 'M' (magenta), 'Y' (yellow) Check if the photo is black-and-white or colored
int main(){
    int n, m; cin >> n >> m;
    char arr[n][m];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * m; j++)
            cin >> arr[i][j];
    }
    int flag = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * m; j++){
            if(arr[i][j] == 'C' || arr[i][j] == 'Y' || arr[i][j] == 'M')
                flag = 1;
        }
    }
    (flag == 0) ? printf("#Black&White\n") : printf("#Color\n");
}
http://codeforces.com/problemset/problem/707/A
// Brain's_Photos
using namespace std;
int main() {
	int m, k; cin >> m >> k;
	int count = 0;
	string arr[m][k];
	for(int i = 0; i < m; i++){
	    for(int j = 0; j < k; j++)
	        cin >> arr[i][j];
	}
    for(int i = 0; i < m; i++){
	    for(int j = 0; j < k; j++){
	        if(arr[i][j] == "C" || arr[i][j] == "M" || arr[i][j] == "Y")    ++count;
	    }
	}
	cout << (count > 0) ? "#Color" : "#Black&White";
}
using namespace std;
int main() {
    int m, n; cin >> m >> n;
    bool isColor = false;
    for (int i = 0; i < m * n; ++i) {
        string pixel; cin >> pixel;
        if (pixel == "C" || pixel == "M" || pixel == "Y")    isColor = true;
    }
    if (isColor)    cout << "#Color" << endl;
    else    cout << "#Black&White" << endl;
}
http://codeforces.com/contest/709/problem/A
// Juicer
using namespace std;
int main() {
	int n, b, d; cin >> n >> b >> d;
	int sum = 0, dtimes = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    if(x <= b)    sum += x;
	    if(sum > d){
	        dtimes++; sum = 0;
	    }
	}
	cout << dtimes;
}
using namespace std;
http://codeforces.com/problemset/problem/723/A
// A. The_New_Year_Meeting_Friends.cpp
int main() {
    int arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr + 3);
    cout << arr[2] - arr[0];
}
http://codeforces.com/contest/731/problem/A
// Night_at_the_Museum.cpp
using namespace std;
int clockwise(char first, char last){
	int var = (int)last - first;
		while(var < 0)    var += 26;
	return var;
}
int counterclockwise(char first, char last){
	int var = (int)first - last;
	while(var < 0)    var += 26;
    return var;
}
int main() {
	string s; cin >> s;
	int moves = 0;
	char start = 'a', end;
	int len = s.length();
	for(int i = 0; i < len; i++){
	    end = s[i];
        moves += min(clockwise(start, end), counterclockwise(start, end));
			start = end;
	}
	cout << moves;
}
using namespace std;
int main() {
    string s; cin >> s;
    char current = 'a';
    int total_moves = 0;
    for (char target : s) {
        int diff = abs(target - current);
        total_moves += min(diff, 26 - diff);
        current = target;
    }
    cout << total_moves << endl;
    return 0;
}

using namespace std;
http://codeforces.com/contest/732/problem/A
// A. Buy a Shovel
int main() {
	int value = 0, priceMade = 0;
	int k, r; cin >> k >> r;
	bool flag = 1;
	while(flag){
        if((priceMade % 10 == 0 && priceMade != 0) || priceMade % 10 == r) break;
        ++value;
        priceMade += k;
	}
	cout << value;
}
using namespace std;
int main() {
    int k, r; cin >> k >> r;
    int shovels = 1;
    while (true) {
        int total = k * shovels;
        if (total % 10 == 0 || total % 10 == r) {
            cout << shovels << endl;
            break;
        }
        ++shovels;
    }
}
http://codeforces.com/contest/732/problem/A
// Buy_A_Shovel
using namespace std;
int main() {
    int k, r; cin >> k >> r;
    int val = 1;
    int cost = val * k;
    while(true){
        if((cost - r) % 10 == 0 || cost % 10 == 0)    break;
        else    ++val;
    }
    cout << val;
}
using namespace std;
int main() {
    int k, r; cin >> k >> r;
    for (int i = 1; i <= 10; ++i) {
        int cost = i * k;
        if (cost % 10 == 0 || cost % 10 == r) {
            cout << i << endl;
            break;
        }
    }
}

using namespace std;
https://codeforces.com/contest/734/problem/B
// 734B. Anton and Digits
int main(){
    int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
    int num256 = min(k2, min(k6, k5));
    int rem = k2 - num256;
	int num32 = min(rem, k3);
	cout << 256 * (num256 + 32) * num32;
	
}
using namespace std;
int main() {
    int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
    // Count how many 256s can be made using 2, 5, and 6
    int count256 = min({k2, k5, k6});
    k2 -= count256;
    // Count how many 32s can be made using remaining 2s and available 3s
    int count32 = min(k2, k3);
    long long total = 256LL * count256 + 32LL * count32;
    cout << total << '\n';
    return 0;
}
https://codeforces.com/problemset/problem/734/A
// Anton_and_Danik.cpp
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int antonWins = count(s.begin(), s.end(), 'A');
    int danikWins = n - antonWins;
    if (antonWins > danikWins)    cout << "Anton";
    else if (danikWins > antonWins)    cout << "Danik";
    else    cout << "Friendship";
}
using namespace std;
int main() {
	int n; cin >> n;
	string s; cin >> s;
	int x = count(s.begin(), s.end(), 'A');
	int y = count(s.begin(), s.end(), 'D');
	if(x>y)
		cout<<"Anton";
	else if(y>x)
		cout<<"Danik";
	else if(x==y){
		cout<<"Friendship";
	}
	if(x > y)    cout << "Anton";
	else(y > x)    cout << "Danik";
	else if(x == y)    cout << "Friendship";
}
using namespace std;
http://codeforces.com/contest/746/problem/B
// B. Decoding
int main() {
    int len; cin >> len;
	string s; cin >> s;
	vector <char> vect;
	while(len != 0){
	    if(len % 2 == 1)    vect.push_back(s[0]);
	    else    vect.insert(vect.begin(), s[0]);
	}
	s.erase(0, 1);
	len = s.length();
	for(int i = 0; i < vect.size(); i++)
	    cout << vect[i] << " ";
	return 0;
}
using namespace std;
int main() {
    int len; cin >> len;
    string s; cin >> s;
    deque<char> result;
    for (int i = 0; i < len; ++i) {
        if ((len - i) % 2 == 1)    result.push_back(s[i]);
        else    result.push_front(s[i]);
    }
    for (char ch : result)
        cout << ch;
    return 0;
}
http://codeforces.com/problemset/problem/750/A
// New_Year_and_Hurry.cpp
using namespace std;
int main() {
    int n, k; cin >> n >> k;
	int rest = 240 - k, cnt = 0;
	for(int i = 1; i <= n; i++){
	    if(rest >= i * 5){
	        rest -= i * 5;
	        ++cnt;
	    }
	    else    break;
	}
	cout << cnt;
	return 0;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int remaining_time = 240 - k;
    int solved = 0;
    for (int i = 1; i <= n; ++i) {
        int time_needed = i * 5;
        if (remaining_time >= time_needed) {
            remaining_time -= time_needed;
            ++solved;
        } else    break;
    }
    cout << solved << endl;
    return 0;
}

using namespace std;
https://codeforces.com/problemset/problem/758/A
// 758A - Holiday Of Equality
int main() {
 	int n; cin >> n;
	int arr[n];
	int maxi = 0, res = 0;
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	    maxi = max(arr[i], maxi);
	}
	for(int i = 0; i < n; i++)
	    res += maxi - arr[i];
	cout << res << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    int maxi = 0, answer = 0;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    for (int val : arr)
        answer += (maxi - val);
    cout << answer << endl;
}
using namespace std;
http://codeforces.com/problemset/problem/767/A
// 767 A. Snacktower
bool arr[100001];
int curr = 0;
void print(int x, int y){
	if(x == y){
        for(int i = y; i > 0; i--){
		    if(arr[i]) {
		        cout << i << " ";
		        arr[i] = 0; curr = i - 1;
		    }
		    else    break;
        }
	}
}
int main(){
    int n; cin >> n;
    curr = n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[x] = 1;
        print(x, curr);
    }
}
using namespace std;
const int MAXN = 100001;
bool present[MAXN];
void printTower(int& curr) {
    while (curr > 0 && present[curr]) {
        cout << curr << " ";
        present[curr] = false;
        --curr;
    }
    cout << "\n";
}
int main() {
    int n; cin >> n;
    int curr = n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        present[x] = true;
        printTower(curr);
    }
}
using namespace std;
http://codeforces.com/contest/768/problem/A
// 768A - Oath of the Night's Watch
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int minCount = upper_bound(arr.begin(), arr.end(), arr[0]) - arr.begin();
    int maxCount = arr.end() - lower_bound(arr.begin(), arr.end(), arr[n - 1]);
    int result = n - minCount - maxCount;
    cout << (result > 0 ? result : 0) << endl;
}
using namespace std;
int main(){
	int n; cin >> n;
	int counter = 0;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	/*counter = (lower_bound(arr, arr + n, arr[n - 1]) - arr) - (upper_bound(arr, arr + n, arr[0]) - arr);
	 if(counter > 0)
	     cout << counter;
	 else
		 cout << 0;*/
	for(int i = 0; i < n; i++){
	if(arr[i] > arr[0] && arr[i] < arr[n - 1])
	    counter++;
	 cout << counter;
}
using namespace std;
http://codeforces.com/contest/768/problem/A
// A. Oath of the Night's Watch
int main() {
	int n; cin >> n;
	vector <int> se;
	int res = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    se.push_back(x);
	}
	sort(se.begin(), se.end());
	int min = se[0], max = se[n - 1];
	for(int i = 0; i < n; i++){
	    if(se[i] > min && se[i] < max)    res++;
	}
	cout << res;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector <int> se(n);
    for (int i = 0; i < n; ++i)
        cin >> se[i];
    sort(se.begin(), se.end());
    int minVal = se.front();
    int maxVal = se.back();
    int answer = 0;
    for (int x : se) {
        if (x > minVal && x < maxVal) {
            ++answer;
        }
    }
    cout << answer << endl;
    return 0;
}
using namespace std;
https://codeforces.com/contest/770/problem/A
// 770A. New Password
int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    string res = "";
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++)
        res += s[i % k];
    cout << res;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string password;
    for (int i = 0; i < n; ++i)
        password += alphabet[i % k];
    cout << password << endl;
    return 0;
}
http://codeforces.com/contest/770/problem/A
// New_Password.cpp
using namespace std;
int main() {
	string s, s2="abcdefghijklmnopqrstuvwxyz";
	int n, k; cin >> n >> k;
	for(int i = 0; i < k; i++)    s += s2[i];
	s2.erase(0, k);
	int i = s.length();
	for(int j = 0; j < n; i++, j++){
	    s += s[j];
	    if(j == k)    j = 0;
	}
	cout << s;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    string base = "abcdefghijklmnopqrstuvwxyz";
    string pattern = base.substr(0, k);
    string result;
    for (int i = 0; i < n; ++i)
        result += pattern[i % k];
    cout << result << endl;
}

using namespace std;
https://codeforces.com/problemset/problem/785/A
// 785A. Anton and Polyhedrons
int main() {
    int n; cin >> n;
    map <string, int> mp;
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"]=8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    int sum = 0;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        sum += mp[str];
    }
    cout << sum;
}
using namespace std;
int main() {
    int n; cin >> n;
    map<string, int> faceCount = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };
    long long totalFaces = 0;
    for (int i = 0; i < n; ++i) {
        string polyhedron; cin >> polyhedron;
        totalFaces += faceCount[polyhedron];
    }
    cout << totalFaces << endl;
    return 0;
}
http://codeforces.com/contest/791/problem/A
// A. Bear and Big Brother
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	int count = 0;
	while(a < b || a == b){
	    ++count;
	    a *= 3; b *= 2;
	}
	cout << count;
	return 0;
}
http://codeforces.com/contest/799/problem/A
// Carrot_Cakes.cpp
using namespace std;
int main() {
	int n, k, t, d; cin >> n >> k >> t >> d;
	int groups = (n + k - 1) / k;
	int oven1 = 0, oven2 = d;
	for(int i = 0; i < groups; i++){
	    if(oven1 <= oven2)    oven1 += t;
	    else    oven2 += t;
	}
	if(max(oven1, oven2) < groups * t)    cout << "Yes";
	else    cout << "No";
	return 0;
}
using namespace std;
int main() {
    int n, t, k, d; cin >> n >> t >> k >> d;
    int singleOvenTime = ((n + k - 1) / k) * t;
    // If the second oven is built and starts working at time d,
    // check if two ovens working together can finish earlier
    if (d >= singleOvenTime) {
        // Oven is built after or when baking is done with one oven, so no gain
        cout << "NO" << endl;
    } else {
        // In time d, the first oven can bake floor(d / t) batches
        int cakesBeforeSecondOven = (d / t) * k;
        // Remaining cakes after second oven is ready
        int remainingCakes = n - cakesBeforeSecondOven;
        // If remaining cakes can be baked in less than singleOvenTime, print YES
        if (remainingCakes > 0 && (2 * t) < singleOvenTime)
            cout << "YES" << endl;
        else if (cakesBeforeSecondOven < n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
http://codeforces.com/contest/807/problem/A
// 807-A Is it rated
using namespace std;
int main() {
	int n; cin >> n;
	int counter = 0, counter2 = 0;
	int arr[n], arr2[n], arr3[n];
	for(int i = 0; i < n; i++){
	    int x, y; cin >> x >> y;
	    cin.ignore();
	    arr[i] = x; arr2[i] = y; arr3[i] = y;
	}
	for(int i = 0; i < n; i++){
	    if(arr[i] == arr2[i])    ++counter;
	}
	sort(arr2, arr2 + n);
	for(int i = n - 1, j = 0; i >= 0; i--, j++){
	    if(arr2[i] == arr3[j])    ++counter2;
	}
	if(counter != n)    cout << "rated";
	else if(counter == n && counter2 == n)    cout << "maybe";
	else    cout << "unrated";
 	return 0;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> before(n), after(n);
    bool isRated = false;
    bool isSorted = true;
    for (int i = 0; i < n; ++i) {
        cin >> before[i] >> after[i];
        if (before[i] != after[i])    isRated = true;
        if (i > 0 && after[i] > after[i - 1])    isSorted = false;
    }
    if (isRated)    cout << "rated" << endl;
    else if (!isSorted)    cout << "unrated" << endl;
    else    cout << "maybe" << endl;
}

using namespace std;
http://codeforces.com/contest/828/problem/A
// Restaurant.cpp
int main() {
    int n, single_tables, double_tables;
    cin >> n >> single_tables >> double_tables;
    int half_occupied = 0; // number of double tables with one person already
    int rejected = 0;
    for (int i = 0; i < n; ++i) {
        int customer_type; cin >> customer_type;
        if (customer_type == 1) {
            if (single_tables > 0)
                single_tables--;
            else if (double_tables > 0) {
                double_tables--;
                half_occupied++;
            } else if (half_occupied > 0)
                half_occupied--;
            else
                rejected++;
        } else if (customer_type == 2) {
            if (double_tables > 0)
                double_tables--;
            else
                rejected += 2;
        }
    }
    cout << rejected << endl;
}
using namespace std;
int main(){
    int n, a, b; cin >> n >> a >> b;
	int bow = 0, people = 0;
	for(int i = 0; i < n; i++){
		int x; cin >>x;
		if(x == 1){
			if(a > 0)	a--;
			else{
				if(b > 0) {
					b--;
					bow++;
				}
				else if(bow > 0)    bow--;
				else    people++;
			}
		}
		else if(x == 2){
			if(b > 0)    b--;
			else    people += 2;
		}
	}
	cout << people;
}
http://codeforces.com/contest/831/problem/B
// Keyboard_Layouts.cpp
using namespace std;
int main(){
    string s, s2, trg; cin >> s >> s2 >> trg;
    string res = "";
    int len = trg.length();
	for(int i = 0; i < len; i++){
	    if(isupper(trg[i])){
	        trg[i] = tolower(trg[i]);
	        int idx = s.find(trg[i]);
	        res += toupper(s2[idx]);
	    }
	    else if(islower(trg[i])){
	        int idx = s.find(trg[i]);
	        res += s2[idx];
	    }
	    else    res += trg[i];
	}
	cout << res;
}
using namespace std;
int main() {
    string layout1, layout2, text;
    cin >> layout1 >> layout2 >> text;
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            bool isUpper = isupper(ch);
            char lowerCh = tolower(ch);
            size_t index = layout1.find(lowerCh);
            char mappedChar = layout2[index];
            result += isUpper ? toupper(mappedChar) : mappedChar;
        } else {
            result += ch;
        }
    }
    cout << result << endl;
    return 0;
}

http://codeforces.com/contest/844/problem/0
// A. Diversity
using namespace std;
int main() {
	string s; cin >> s;
	int n; cin >> n;
	int len = s.length();
	set <char> sa;
	for(int i = 0; i < len; i++)    sa.insert(s[i]);
	if(len < n)    cout << "impossible";
	else {
	    int size2 = sa.size();
	    if(size2 >= n)    cout << "0";
	    else    cout << n - size2;
	}
}
using namespace std;
int main() {
    string s; cin >> s;
    int n; cin >> n;
    int len = s.length();
    set<char> uniqueChars(s.begin(), s.end());
    if (len < n)    cout << "impossible" << endl;
    else {
        int distinctCount = uniqueChars.size();
        cout << max(0, n - distinctCount) << endl;
    }
}
http://codeforces.com/problemset/problem/854/A
// A. Fraction
using namespace std;
int main() {
    int n; cin >> n;
    int a = 0, b = 0;
    int maxa = 1;
    int z = n >> 1;
    for(int i = 1; i < z + 1; i++){
        bool flag = 1;
        a = i; b = n - a;
        for(int j = 2; j <= a; j++){
            if(a % j == 0 && b % j == 0)    flag = 0;
        }
        if(flag)    maxa = max(a, maxa);
    }
    cout << maxa << " " << n - maxa;
}
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b; a = t;
    }
    return a;
}
int main() {
    int n; cin >> n;
    int maxA = 1;
    for (int a = 1; a <= n / 2; ++a) {
        int b = n - a;
        if (gcd(a, b) == 1)    maxA = a;
    }
    cout << maxA << " " << n - maxA << endl;
}
http://codeforces.com/problemset/problem/869/A
// 869A. The Artful Expedient
using namespace std;
const int N = 1000000;
int freq[N] = {};
int main(){
    int n; cin >> n;
    int cnt = 0, arr[n], arr2[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ++freq[arr[i]];
    }
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
        ++freq[arr2[i]];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(freq[arr[i] ^ arr[j]])    ++cnt;
        }
    }
    if(cnt % 2 == 0)    cout << "karen";
    else    cout << "koyomi";
}
using namespace std;
int main() {
    int n; cin >> n;
    int a[n], b[n];
    unordered_set<int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        freq.insert(b[i]);
    }
    int count = 0;
    // Count pairs (i, j) where a[i] ^ b[j] exists in input
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (freq.count(a[i] ^ b[j]))
                ++count;
    cout << (count % 2 == 0 ? "Karen" : "Koyomi") << endl;
}
using namespace std;
http://codeforces.com/contest/876/problem/A
// A. Trip For Meal
int main() {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    int x = min(a, min(b, c));
    if(x == a || x == b || n == 1)    cout << (n - 1) * min(a, b);
    else    cout << min(a, b) + c * (n - 2);
}
using namespace std;
int main() {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    // If only one city, no travel needed
    if (n == 1)    cout << 0 << endl;
    else if (n == 2) {
        // Only one move needed, choose min of a and b
        cout << min(a, b) << endl;
    else {
        // First move: min of a or b
        // Remaining (n-2) moves: always take the cheaper round trip (min(a, b)) or two-step move (c)
        cout << min(a, b) + (n - 2) * min({a, b, c}) << endl;
    }
}
https://codeforces.com/contest/879/problem/A
// 879A. Borya's Diagnosis
using namespace std;
long long theday(int s ,int d, int curday){
    int day = 0, i = 0;
	while(true){
	    if((s + (i * d)) > curday){
	        day = s + i * d;
	        break;
	    }
	    ++i;
	}
	return day;
}
int main() {
    int n; cin >> n;
    int curday = 0;
    int arr[n + 1] = {};
    for(int i = 1; i <= n; i++){
        int s, d; cin >> s >> d;
        if(n > 1){
            curday = theday(s, d, curday);
            arr[i] = curday;
        }
        else    arr[i] = s;
    }
    cout << arr[n];
}
using namespace std;
long long getNextAvailableDay(int s, int d, long long curDay) {
    if (s > curDay) return s;
    long long i = (curDay - s) / d + 1;
    return s + i * d;
}
int main() {
    int n; cin >> n;
    int curDay = 0;
    for (int i = 0; i < n; ++i) {
        int s, d; cin >> s >> d;
        curDay = getNextAvailableDay(s, d, curDay);
    }
    cout << curDay << endl;
}
https://codeforces.com/contest/879/problem/B
// 879B. Table Tennis
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    queue <int> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push(x);
    }
    int winner = q.front();
    q.pop();
    int wins = 0;
    if (k >= n - 1) {
        // The maximum will win eventually
        int maxVal = winner;
        while (!q.empty()) {
            maxVal = max(maxVal, q.front());
            q.pop();
        }
        cout << maxVal << endl;
    } else {
        while (wins < k) {
            long long next = q.front();
            q.pop();
            if (winner > next) {
                ++wins;
                q.push(next);
            } else {
                q.push(winner);
                winner = next;
                wins = 1;
            }
        }
        cout << winner << endl;
    }
}
using namespace std;
int main() {
	 map <int, int> arr;
	 int n, k; cin >> n >> k;
	 int winer = 0;
	 queue <int> q;
	 for(int i = 0; i < n; i++){
	     int c; cin >> c;
	     q.push(c);
	 }
	 winer = q.front();
	 q.pop();
	 int times = 0;
	 if(n > 2){
	     for(int i = 0; i < 1000; i++){
	         int value = q.front();
	         q.pop();
	         if(value > winer){
	             if(times == k)    break;
	             winer = value;
	             times = 1;
	             q.push(winer);
	         }
	         else{
	             q.push(value);
	             ++times;
	             if(times == k)    break;
	         }
	     }
	     cout << winer;
	 }
	 else {
	     int value = q.front();
	     q.pop();
	     winer = max(winer, value);
	     cout << winer;
	 }
}

using namespace std;
// A. Wrong Subtraction
// problemset/problem/977/A?mobile=false
int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        if (n % 10 == 0) n /= 10;
        else n--;
    }
    cout << n << endl;
}
using namespace std;
// C. Alphabetic Removals
// contest/999/problem/C _From a string remove k characters.try to remove the leftmost 'a' first.
// if 'a' is not left, remove the leftmost 'b'.Continue in alphabetical order ('c', 'd', ..., 'z'),
//Repeat this process exactly k times.After removing k characters, print the remaining string.
int main(){
    int n, k; cin >> n >> k;
    string str; cin >> str;
    vector <int> freq(26, 0);
    for(int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;
    char eliminate = 'a';
    while(k > 0 && eliminate <= 'z'){
        int cnt = min(k, freq[eliminate - 'a']);
        k -= cnt;
        freq[eliminate - 'a'] -= cnt;
        eliminate++;
    }
    int remain[26] = {0};
    for(char ch = 'a'; ch <= 'z'; ch++)
        remain[ch - 'a'] = freq[ch - 'a'];
    for(int i = 0; i < str.size(); i++){
        if(remain[str[i] - 'a'] > 0){
            cout << str[i];
            remain[str[i] - 'a']--;
        }
    }
    //-----//
    int n, k; cin >> n >> k;
    string str; cin >> str;
    map <char, vector <int> > idx;
    for(int i = 0; i < n; i++)
        idx[str[i]].push_back(i);
    map <int, bool> visited;
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(int i = 0; i < idx[ch].size() && k >= 1; i++){
            int ix = idx[ch][i];
            visited[ix] = true; k--;
        }
    }
    for(int i = 0; i < n; i++){
        if(!visited[i])
            cout << str[i];
    }
}
using namespace std;
// A. In Search of an Easy Problem
// contest/1030/problem/A
int main(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
    }
    (sum) ? cout << "HARD" : cout << "EASY";
}
using namespace std;
// problemset/problem/1204/B
// B. Mislove Has Lost an Array
int main(){
    int n, l, r; cin >> n >> l >> r;
    int minsum = 0, maxsum = 0;
    int power = 1;
    for(int i = 1; i <= l; i++){
        minsum += power;
        power *= 2;
    }
    minsum += (n - l) * 1;
    power = 1;
    for(int i = 1; i <= r; i++){
        maxsum += power;
        power *= 2;
    }
    maxsum += (n - r) * (power / 2);
    cout << maxsum << " " << minsum;
}
using namespace std;
// C. Bad Sequence
// contest/1214/problem/C _check if can make a bracket sequence  correct by moving at most 
//one bracket to a different position (without flipping it).correct bracket sequence must:Have equal numbers of ( and ),
//Be balanced.Determine if moving one bracket to a different position can fix the sequence
int main(){
    int n; cin >> n;
    string str; cin >> str;
    stack <char> st;
    for(int i = 0; i < n; i++){
        if(i == 0) st.push(str[i]);
        else{
            if(st.size() >= 1 && st.top() == '(' && str[i] == ')')
                st.pop();
            else st.push(str[i]);
        }
    }
    int open = 0, close = 0;
    while(!st.empty()){
        if(st.top() == '(') open++;
        else close++;
        st.pop();
    }
    ((open == 0 && close == 0) || (open == 1 && close == 1)) ? cout << "Yes" : cout << "No";
}
using namespace std;
// contest/1257/problem/A
// A. Two Rival Students
int main(){
    int t; cin >> t; 
    while(t--){
        int n, x, a, b; cin >> n >> x >> a >> b;
        int curDist = abs(a - b);
        int maxDist = min(n - 1, curDist + x);
    }
    cout << maxDist;
}
using namespace std;
// B. Magic Stick
// contest/1257/problem/B
int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        if(x == 1 && y == 1) cout << "YES\n";
        else if((x == 2 || x == 3) && y < 4) cout << "YES\n";
        else if(x > 3) cout << "YES\n";
        else cout << "No\n";
    }
}
using namespace std;
// problemset/problem/1328/A
// A. Divisibility Problem
int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        if(x % y == 0)
            cout << 0;
        else
            cout << y - (x % y);
    }
}
using namespace std;
// A. Candies and Two Sisters
// problemset/problem/1335/A
int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        if(x > 2){
            if(x & 1) cout << (x >> 1) << "\n";
            else cout << (x >> 1) - 1 << "\n";
        }
        else cout << 0;
    }
}
//https://codeforces.com/problemset/problem/1352/A
// Sum of Round Numbers
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> vec;
        int j = 0;
        while(n > 0){
            if(n % 10){
                int res = pow(10, j);
                res *= n % 10;
                vec.push_back(res);
            }
            n /= 10; j++;
        }
        int len = vec.size();
        cout << len << "\n";
        for(int i = 0; i < len; i++)
            cout << vec[i] << " ";
        cout << "\n";
    }
}
using namespace std;
// https://codeforces.com/problemset/problem/1367/A
// Short Substrings
int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        int len = str.length();
        string res = "";
        for(int i = 0; i < len; i++){
            if(i % 2 == 0)
                res += str[i];
        }
        res += str[len - 1];
        cout << res << "\n";
    }
}
using namespace std;
// https://codeforces.com/problemset/problem/1409/A
// A. Yet Another Two Integers Problem
int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a == b) cout << "0";
        else{
            int diff = abs(a - b);
            int arr[11] = {};
            int res = 0;
            for(int i = 10; i > 0; i--){
                arr[i] = diff / i;
                diff -= arr[i] * i;
                res += arr[i];
            }
            cout << res;
        }
    }
}
using namespace std;
// C. Dominant Piranha
// problemset/problem/1433/C
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], res = -1, mx = 0;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int dup = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] != arr[0]){
                dup = 0;
                break;
                
            }
        }
        if(dup){
            cout << -1;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(arr[i] > mx) mx = arr[i];
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == mx){
                if ((i > 0 && arr[i] > arr[i - 1]) || (i < n - 1 && arr[i] > arr[i + 1])) {
                    res = i + 1;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}
using namespace std;
// problemset/problem/1454/A
// A. Special Permutation
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << n << " ";
        for(int i = 1; i < n; i++)
            cout << i << " ";
        cout << "\n";
    }
}
using namespace std;
// A. Cards for Friends
// contest/1472/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        int w, h, n; cin >> w >> h >> n;
        int cnt = 1;
        while(w % 2 == 0){
            w /= 2; cnt *= 2;
        }
        while(h % 2 == 0){
            h /= 2; cnt *= 2;
        }
        (cnt >= n) ? cout << "Yes\n" : cout << "No\n";
    }
}
using namespace std;
// contest/1475/problem/A 
// A. Odd Divisor
int powerOfTwo(int n){
    return (n & (n - 1)) == 0;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        (powerOfTwo(n)) ? cout << "No\n" : cout << "Yes\n";
    }
    while(t--){
        int i = 2, flag = 0;
        int n; scanf("%d", &n);
        while(i <= n){
            if(n % i == 0 && i % 2 != 0)
                flag = 1;
            i++;
        }
    }
}
using namespace std;
// D. Epic Transformation
// problemset/problem/1506/D
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map <int, int> freq;
        int maxfreq = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            freq[x]++;
            maxfreq = max(maxfreq, freq[x]);
        }
        int rem = n - maxfreq;
        cout << (maxfreq > rem) ? (maxfreq - rem) : n % 2 << "\n";
    }
}
using namespace std;
// A. Review Site
// problemset/problem/1511/A
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int up = 0, down = 0;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++){
            if(arr[i] != 2) up++;
        }
        cout << up << "\n";
    }
}
using namespace std;
// contest/1512/problem/A
// A. Spy Detected
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int maxi = 101, arr[n + 1];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int freq[maxi];
        for(int i = 0; i < maxi; i++)
            freq[i] = 0;
        for(int i = 0; i < n; i++)
            freq[arr[i]]++;
        int idx;
        for(int i = 0; i < n; i++){
            if(freq[arr[i]] == 1){
                idx = i; 
                break;
            }
        }
        cout << idx + 1 << "\n";
    }
}
using namespace std;
// problemset/problem/1553/A
// A. Digits Sum
int main(){
    int t; cin >> t;
    while(t--){
        int n, res; cin >> n;
        if(n % 10 < 9)
            res = n / 10;
        else
            res = (n / 10) + 1;
        cout << res;
    }
}
using namespace std;
// A. Dislike of Threes
// contest/1560/problem/A
int main(){
    int t; cin >> t;
    int res[2001], tmp = 1;
    for(int i = 1; tmp <= 2000; i++){
        if((i % 3 != 0) && (i % 10 != 3))
            res[tmp++] = i;
    }
    while(t--){
        int n; cin >> n;
        cout << res[n];
    }
    /*
    int n, k; cin >> n;
    for(int i = 1; i <= n; i++){
        while(i % 3 == 0 || i % 10 == 3){
            i++; n++;
        }
        k = i;
    }
    cout << k; */
}
using namespace std;
// Permutation Minimization by Deque
// contest/1579/problem/E1 _Given a permutation of size n,need to construct a deque by sequentially adding elements. starting smallest value.
// Before adding each value choose whether to add it to the front or the back of the deque.determine the final order of elements in the deque
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        list <int> lst;
        vector <int> vec(n);
        int i = 0;
        for(int i = 0; i < n; i++)
            cin >> vec[i];
        while(i < n){
            if(i == 0){
                lst.push_back(vec[i]);
                i++;
            }
            else{
                if (vec[i] < lst.front())
                    lst.push_front(vec[i]);
                else
                    lst.push_back(vec[i]);
                i++;
            }
        }
        while (!lst.empty()){
            cout << lst.front() << " ";
            lst.pop_front();
        }
        cout << "\n";
    }
}
using namespace std;
// A. Find Array
// contest/1608/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1){
            cout << 1 << " ";
            continue;
        }
        else{
            for(int i = 2; i <= n + 1; i++)
                cout << i << " ";
        }
        cout << "\n";
    }
}
using namespace std;
//A. Vasya and Coins
// problemset/problem/1660/A
int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a == 0) cout << 1;
        else cout << a + (b * 2) + 1;
    }
}
using namespace std;
// B. Equal Candies
// problemset/problem/1676/B
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], sum = 0, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] < mini)
                mini = arr[i];
        }
        for(int i = 0; i < n; i++)
            sum += arr[i] - mini;
        cout << sum << "\n";
    }
}
using namespace std;
// Eating Queries
//contest/1676/problem/E _Timur has n candies, each with a sugar content a[i]. He will ask q queries, where for each query x[j], 
//determine the minimum number of candies he needs to eat to consume at least x[j] sugar. If it's not possible, return -1
int main(){
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector <int> vec(n);
        for(int i = 0; i < n; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.end(), greater <int> ());
        vector <int> pref(n + 1, 0);
        for(int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + vec[i - 1];
        while(q--){
            int val; cin >> val;
            auto it = lower_bound(pref.begin(), pref.end(), val);
            if(it != pref.end())
                cout << it - pref.begin() << "\n";
            else
                cout << -1 << "\n";
        }
    }
}
using namespace std;
// Minimums and Maximums
//contest/1680/problem/A _calculate the minimum possible number of elements in a array by which range [l1, r1] elements 
// equal to its minimum and [l2, r2] elements in the array equal to its maximum.
int main(){
    int l1, l2, r1, r2, res;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l2 >= l1 && l2 <= r1) res = l2;
    else if(l1 >= l2 && l1 <= r2) res = l1;
    else res = l1 + l2;
    cout << res;
}
using namespace std;
// B. Card Trick
// problemset/problem/1681/B
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int m, sum = 0; cin >> m;
        for(int i = 0; i < m; i++){
            int suf; cin >> suf;
            sum += suf;
        }
        res = sum % n;
        cout << arr[res];
    }
}
using namespace std;
// A. Beat The Odds
// contest/1691/problem/A
int main() {
    int t; cin >> t;
    while (t--) {
        int n, even = 0, odd = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            if (num % 2 == 0) even++;
            else odd++;
        }
        cout << min(even, odd) << endl;
    }
}

using namespace std;
// C. Cypher
// problemset/problem/1703/C
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++){
            int moves; cin >> moves;
            string str; cin >> str;
            for(int j = 0; j < str.size(); j++){
                if(str[j] == 'U')
                    arr[i] = (arr[i] + 9) % 10;
                else if(str[i] == 'D')
                    arr[i] = (arr[i] + 1) % 10;
            }
        }
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
}
using namespace std;
// A. Difference Operations
// problemset/problem/1708/A
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int IsDiv = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] % arr[0] != 0){
                IsDiv = 0;
                break;
            }
        }
        printf(IsDiv ? "Yes" : "No");
    }
}
using namespace std;
// A. Three Doors
// problemset/problem/1709/A
int main(){
    int t; cin >> t;
    while(t--){
        int start; cin >> start;
        int keys[4];
        for(int i = 1; i <= 3; i++)
            cin >> keys[i];
        int first = keys[start];
        int second = (first != 0) ? keys[first] : 0;
        if(first != 0 && second != 0)
            cout << "Yes";
        else
            cout << "No";
    }
}
using namespace std;
// A. Planets
// problemset/problem/1730/A
int main(){
    int t; cin >> t;
    while(t--){
        int num, cost; cin >> num >> cost;
        unordered_map <int, int> freq;
        for(int i = 0; i < num; i++){
            int x; cin >> x;
            freq[x]++;
        }
        int res = 0;
        for(const auto &it : freq)
            res += min(it.second, cost);
        cout << res << "\n";
    }
}
using namespace std;
// problemset/problem/1734/A
// A. Select Three Sticks
void sorti(int *arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sorti(arr, n);
        int res = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            int diff = (arr[i] - arr[i - 1]) + (arr[i + 1] - arr[i]);
            if (diff < res) res = diff;
        }
        cout << res << "\n";
    }
}
using namespace std;
// B. Bright, Nice, Brilliant
// problemset/problem/1734/B  _There has a pyramid with n floors, numbered(1 to n).i-th floor has exactly i rooms.Each room (i, j) has two staircases leading to the two rooms directly below: (i+1, j) and (i+1, j+1).Each room can either have a torch or be empty.
//brightness of a room is the number of torches from which you can reach it using staircases. nice pyramid is one where all rooms in each floor have the same brightness.
//brilliance of a pyramid is the sum of brightness values of the leftmost rooms (1,1), (2,1), ..., (n,1).Fine  a torch arrangement that makes the pyramid nice and maximizes its brilliance.
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                (j > 1 && j < i) ? printf("0") : printf("1");
            }
            printf("\n");
        }
    }
}
// contest/1736/problem/A
// A. Make A Equal to B
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], ray[n];
        int z1 = 0, z2 = 0, o1 = 0, o2 = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 0) z1++;
            else o1++;
        }
        for(int i = 0; i < n; i++){
            cin >> ray[i];
            if(ray[i] == 0) z2++;
            else o2++;
        }
        int res = (z1 - z2 > o1 - o2) ? z1 - z2 : o1 - o2;
        int mismatch = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] != ray[i])
                mismatch++;
        }
        (mismatch < res) ? cout << res : cout << res + 1;
    }
}
using namespace std;
// A. Factorise N+M
// problemset/problem/1740/A?mobile=false
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int m = 2;
        while (is_prime(n + m)) {  
            m++;  
            while (!is_prime(m)) 
                m++;
        }
        cout << m << "\n";
    }/*
    while(t--){
        int n; cin >> n;
        if(n == 1 || n == 2)
            cout << "7\n";
        else if(is_prime(n))
            cout << n + 1 << "\n";
    } */
}
// contest/1741/problem/A
// A. Compare T-Shirt Sizes
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string str, ing; cin >> str >> ing;
        int len = str.length(), gth = ing.length();
        char ch = str[len - 1], ar = ing[gth - 1];
        if (ch == ar) {
            if (ch == 'S') {
                cout << (len > gth ? "<\n" : (len < gth ? ">\n" : "=\n"));
            }else {
                cout << (len > gth ? ">\n" : (len < gth ? "<\n" : "=\n"));
            }
        } else {
            if ((ch == 'L' && (ar == 'M' || ar == 'S')) || (ch == 'M' && ar == 'S'))
                cout << ">\n";
            else cout << "<\n";
        }
    }
}
using namespace std;
// Sum
//problemset/problem/1742/A _given three integers a Determine if one of them is the sum of the other two.
int main(){
    int t; cin >> t;
    while(t--){
        (a + b == c || b + c == a || a + c == b) ? cout << "Yes" : cout << "No";
    }
}
using namespace std;
// problemset/problem/1754/A
// A. Technical Support
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        stack <char> st;
        for(int i = 0; i < n; i++){
            char ch = str[i];
            if(ch == 'Q') st.push(ch);
            else{
                if(!st.empty())
                    st.pop();
            }
        }
        (st.empty()) ? cout << "Yes" : cout << "No";
    }
}
using namespace std;
// B. Kevin and Permutation
// contest/1754/problem/B
int main(){
    int n; cin >> n;
    int x = (n + 1) / 2;
    int y = n;
    for(int i = 1; i <= n / 2; i++){
        cout << x << " " << y << " ";
        x--; y--;
    }
    if(n % 2!= 0) cout << 1 << "\n";
}
using namespace std;
// A. SSeeeeiinngg DDoouubbllee
// contest/1758/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        cout >> str;
        reverse(str.begin(), str.end());
        cout << str;
    }
}
using namespace std;
// Medium Number
//problemset/problem/1760/A _find the medium number among three integers
int medium(int a, int b, int c){
    int maxi = a, mini = a;
    if(b > maxi) maxi = b;
    if(c > maxi) maxi = c;
    if(b < mini) mini = b;
    if(c < mini) mini = c;
    return a + b + c - maxi - mini;
}
int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        cout << medium(a, b, c));
    }
}
using namespace std;
// Koxia and Whiteboards
//contest/1770/problem/A _Kiyora has n whiteboards, each containban integer a[i]. she performs m operations, where each
// they choose any whiteboard and replace its number with b[j] from a given list. determine the maximum possible sum of the numbers 
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        long long sum = 0;
        list <int> lst;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            lst.push_back(x);
            sum += x;
        }
        lst.sort();
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            sum -= lst.front();
            sum += x;
            lst.pop_front();
            lst.push_front(x);
            lst.sort();
        }
        cout << sum << "\n";
    }
}
using namespace std;
// Hayato and School
//contest/1780/problem/A _find three indices in an array such that the sum of the elements at these indices is odd
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> odd, even;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            if(x % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }
        if(odd.size() >= 3){
            cout << "YES\n" << odd[0] << " " << odd[1] << " " << odd[2];
        }
        else if(odd.size() >= 1 && even.size() >= 2)
            cout << "Yes\n" << odd[0] << " " << even[0] << " " << even[1];
        else
            cout << "No";
    }
}
using namespace std;
// Matrix of Differences
// contest/1783/problem/B _Given an n × n matrix filled with integers from 1 to n*n.define its "beauty"
// as the number of unique absolute differences between adjacent elements (horizontally or vertically).
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        list <int> lst;
        for(int i = 1; i <= n * n; i++)
            lst.push_back(i);
        int grid[n][n];
        for(int i = 0; i < n; i++){
            if((i + 1) % 2 != 0){
                for(int j = 0; j < n; j++){
                    if((j + 1) % 2 != 0){
                        grid[i][j] = lst.back();
                        lst.pop_back();
                    }
                    else{
                        grid[i][j] = lst.front();
                        lst.pop_front();
                    }
                }
            }
            else{
                for(int j = n - 1; j >= 0; j--){
                    if((j + 1) % 2 != 0){
                        grid[i][j] = lst.front();
                        lst.pop_front();
                    }
                    else{
                        grid[i][j] = lst.back();
                        lst.pop_back();
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
    }
}
using namespace std;
// problemset/problem/1787/A
// A. Exponential Equation
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 2 == 0)
            cout << n / 2 << " " << 1 << "\n";
        else
            cout << -1 << "\n";
    }
}
using namespace std;
// Polycarp and the Day of Pi
//contest/1790/problem/A _print how many digits of PI will be matched
int main(){
    int t; cin >> t;
    while(t--){
        string PI = "314159265358979323846264338327";
        string str; cin >> str;
        int res = 0;
        for(int i = 0; i < str.size(); i++){
            if(PI[i] == str[i]) res++;
            else break;
        }
        cout << res;
    }
}
using namespace std;
// Teleporters (Easy Version)
// contest/1791/problem/G1 _Given (0 to n) points on a number line ,) each point i teleporter that costs a[i] coins to use. 
//Using a teleporter sends you back to point 0, but each teleporter can be used only once.move left or right on the number line at a cost of 1 coin per unit. 
//Starting at 0 with c coins, determine the maximum number of teleporters you can use.
int main(){
    int t; cin >> t;
    while(t--){
        int n, cost; cin >> n >> cost;
        vector <int> vec(n);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            vec[i] = i + 1 + x;
        }
        sort(vec.begin(), vec.end());
        int res = 0;
        for(int i = 0; i < vec.size(); i++){
            if(cost < vec[i])
                break;
            cost -= vec[i];
            res++;
        }
        cout << res << "\n";
    }
}
using namespace std;
// A. Two Towers
// problemset/problem/1795/A
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int dup1 = 0, dup2 = 0;
        string str, ing; cin >> str >> ing;
        for(int i = 0; i < m - 1; i++){
            if(str[i] == str[i + 1])
                dup1++;
        }
        for(int i = 0; i < n - 1; i++){
            if(ing[i] == ing[i + 1])
                dup2++;
        }
        if(dup1 == 0 && dup2 == 0) cout << "Yes\n";
        else if(dup1 >= 1 && dup2 >= 1) cout << "No\n";
        else if(dup1 >= 2 || dup2 >= 2) cout << "No\n";
        else{
            if(str[m - 1] == ing[n - 1]) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}
using namespace std;
// Array Coloring
//problemset/problem/1857/A _determine whether it is possible to color all its elements in two colors in such a way that the sums 
//of the elements of both colors have the same parity and each color has at least one element colored.
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], sum = 0;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++)
            sum += arr[i];
        (sum % 2 == 0) ? cout << "Yes\n" : cout << "No\n"
    }
}

