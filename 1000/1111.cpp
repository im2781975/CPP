
// determine process a list of integers representing the positions of 
//citizens in Lineland and determine two values for each citizen: minimum & maximum distance to any other citizen.
void LinelandMail(){
    int n; cin >> n;
    int arr[n], maxi[n], mini[n], res[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    /*for(int i = 0; i < n; i++){
        maxi[i] = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
        if(i == 0)
            mini[i] = abs(arr[i] - arr[i + 1]);
        else if(i == n - 1)
            mini[i] = abs(arr[i] - arr[i - 1]);
        else
            mini[i] = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
    }
    for(int i = 0; i < n; i++)
        cin << maxi[i] << " " << mini[i];*/
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            if(arr[i] == arr[j])
                continue;
            if(arr[i] > arr[j])
                res[j] = arr[i] - arr[j];
            else
                res[j] = arr[j] - arr[i];
                
        }
    }
    sort(res, res + n);
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}

// create as many complete teams as possible where each team consists of 
//one student with each of three different types of gifts. Each team should have one student 
//with gift type 1, one student with gift type 2, and one student with gift type 3.
void TeamOlympiad(){
    int n; cin >> n;
    vector <int> count(4, 0);
    vector <vector <int> >student(4, vector <int> (5001));
    for(int i = 1; i <= n; i++){
        //loop runs n times for each student.each iteration, it reads the type of gift from the input.
        int gift; cin >> gift;
        count[gift]++;
        student[gift][count[gift]] = i;
    }
    //teams is calculated as the minimum value among the counts of gift types 1, 2, and 3.
    // it is the maximum number of teams that can be formed, where each team has one student with each type of gift.
    int team = min({count[1], count[2], count[3]});
    for(int i = 1; i <= team; i++){
    //prints the index of a student with gift type 1, gift type 2, and gift type 3.
        cout << student[1][i] << "\n";
        cout << student[2][i] << "\n";
        cout << student[3][i] << "\n";
    }
}
void Presents(){
    int n; cin >> n;
    int arr[n], freq[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] >= 1 && arr[i] <= n)
            freq[arr[i] - 1] = i + 1;
    }
    for(int i = 0; i < n; i++)
        cout << freq[i] << " ";
}
void NewPassword(){
    int TotalLength, CycleLength, i;
    cin >> TotalLength >> CycleLength;
    char alpha[26] = {0};
    for(int i = 0; i <  26; i++){
        alpha[i] = 'a' + i;
    }
    /*for(i = 97; i <= 122; i++)
        alpha[i - 97] = i;
    alpha[i] = '\0';*/
    int CompleteCycle = TotalLength / CycleLength;
    for(int i = 0; i < CompleteCycle; i++){
        for(int j = 0; j < CycleLength; j++) 
            cout << alpha[j] << " ";
    }
    cout << "\n";
    int remainChar = TotalLength % CycleLength;
    for(int i = 0; i < remainChar; i++)
        cout << alpha[i] << " ";
    cout << "\n";
}
using namespace std;0
typedef long long ll;
// Extended Euclidean Algorithm
// This function returns the gcd of a and b, and updates x and y with the coefficients such that: ax + by = gcd(a, b)
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    // if a is 0, then gcd is b, and the coefficients are (0, 1)
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    // To store results of recursive call
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
// Function to find modulo inverse of b under modulo m
// This returns -1 if the inverse doesn't exist (i.e., if gcd(b, m) != 1)
ll modInverse(ll b, ll m) {
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    // Return -1 if b and m are not coprime (gcd != 1)
    if (g != 1)
        return -1;
    // Handle negative x by ensuring result is positive
    return (x % m + m) % m;
}
// compute a / b under modulo m.This function returns (a * b^(-1)) % m if the modular inverse exists; otherwise, -1
ll modDivide(ll a, ll b, ll m) {
    a = a % m;
    ll inv = modInverse(b, m);

    // Check if the modular inverse exists
    if (inv == -1) {
        printf("Division not defined\n");
        return -1;
    }
    else
        return (inv * a) % m;
}
int main() {
    ll a = 10, b = 3, m = 13;
    ll result = modDivide(a, b, m);
    if (result != -1) {
        printf("Result of %lld / %lld under modulo %lld is %lld\n", a, b, m, result);
    }
    return 0;
}
using namespace std;
void check(){
    int n; string str;
    cin >> n >> str;
    if(n == 1){
        if(str == "W")
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
    if(n == 2){
        if(str == "WW" || str == "RB" || str == "BR")
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
    int len = str.size();
    bool flag = true;
    for(int i = 0; i < len;){ 
        //skip white
        while(i < len && str[i] == 'W')
            i++;
        if(i == n)
            break;
        int blue = 0, red = 0;
        while(i < len && str[i]!= 'W'){
            if(str[i] == 'B')
                blue++;
            else if(str[i] == 'R')
                red++;
            i++;
        }
        if(blue == 0 || red == 0){
            flag = false;
            break;
        }
    }
    (flag)? cout << "Yes" : cout << "No";
}
using namespace std;
//determine if a string composed of the characters 'R', 'B', and 'W' satisfies 
// specific adjacency rules for the characters 'R' and 'B'.
void isSatisfied(){
    string str; cin >> str;
    bool valid = true;
    int len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] == 'R' || str[i] == 'B'){
            bool validVicino = false;
            if(i > 0 && (str[i - 1] == 'R' || str[i - 1] == 'B'))
                validVicino = true;
            if(i < len - 1 && (str[i + 1] == 'R' || str[i + 1] == 'B'))
                validVicino = true;
            if(str[i] == 'R'){
                if(i > 0 && str[i - 1] == 'W' && str[i + 1] != 'B')
                    validVicino = false;
                if(i < len - 1 && str[i + 1] == 'W' && str[i - 1]!= 'B')
                    validVicino = false;
            }
           else if(str[i] == 'B'){
                if(i > 0 && str[i - 1] == 'W' && str[i + 1] != 'R')
                    validVicino = false;
                if(i < len - 1 && str[i + 1] == 'W' && str[i - 1]!= 'R')
                    validVicino = false;
            }
            if(!validVicino){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}
using namespace std;
//finds the next palindromic date that is larger than n.
int arr[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int rev(int x){
    int ans = 0;
    while(x){
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}
bool IsLeap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool check(int x, int n){
    if(x <= n)
        return false;
    int day = x % 100;
    x /= 100;
    int month = x % 100;
    int year = x / 100;
    if(month < 1 && month > 12)
        return false;
    if(IsLeap(year) && month == 2)
        return day <= 29;
    return day <= arr[month];
}
int main(){
    int n; cin >> n;
    for (int i = n / 10000; i <= 9999; i++) {
        int x = i * 10000 + rev(i);
        if (check(x, n)) {
            cout << x << endl;
            break;
        }
    }
    for (int i = n / 1000000; i <= 9999; i++) {
        int x = i * 1000000 + i * 10000 + rev(i) * 100 + rev(i);
        if (check(x, n)) {
            cout << x << endl;
            break;
        }
    }
}
using namespace std;
bool UniqueDigit(int year){
    int digits[10] = {0};
    while(year > 0){
        int dig = year % 10;
        if(digits[dig] > 0)
            return false;
        digits[dig]++;
        year /= 10;
    }
    return true;
}
int main(){
    int y; cin >> y;
    int n = y + 1;
    while(true){
        if(UniqueDigit(n)){
            cout << n;
            break;
        }
        n++;
    }
}
using namespace std;
void CountChar(){
    string str; cin >> str;
    int upper = 0, lower = 0, num = 0, special = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            lower++;
        else if(str[i] >= '0' && str[i] <= '9')
            num++;
        else
            special++;
    }
    if(upper > lower)
 	transform(str.begin(), str.end(), str.begin(), ::toupper);
   else if(lower > upper)
 	transform(str.begin(), str.end(), str.begin(), ::tolower);
   else if(upper == lower)
 	transform(str.begin(), str.end(), str.begin(), ::tolower);
   cout << str;
   cout << "\nUpper case letters: " << upper << "\nLower case letters : " << lower  << "\nNumber : " << num << "\nSpecial characters : " << special;
}
using namespace std;
void LuckyDigit(){
    int n, digit, cnt = 0;
    cin >> n;
    while(n){
        digit = n % 10; n /= 10;
        if(digit == 4 || digit == 7)
            cnt++;
    }
    (cnt == 4 || cnt == 7) ? cout << "Yes" : cout << "No";
}
using namespace std;
int main(){
    int n, m, idx; cin >> n >> m;
    int arr[n], tmp[m];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ForwardSteps, ForwardCnt = 0, BackwardCnt = 0;
    for(int i = 0; i < m; i++){
        cin >> tmp[i];
        idx = -1;
        for(int j = 0; j < n; j++){
            if(arr[j] = tmp[i]){
                idx = j;
                break;
            }
        }
        if(idx != -1){
            ForwardSteps = idx + 1;
            ForwardCnt += ForwardSteps;
            ForwardSteps = n - idx;
            BackwardCnt += ForwardSteps;
        }
    }
    cout << ForwardCnt << " " << BackwardCnt;
}
using namespace std;
long BinPow(int a, int b, int m){
    a %= m;
    if(b == 0)
        return 1;
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res = res * a % m;
        a = a * a % m;
        b >> = 1;
    }
    return res;
}
long BinPow(int a, int b){
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res *= a;
        a *= a;
        b >> = 1;
    }
    return res;
}
long long nCr(int n, int p, int r){
    if(n < r)
        return 0;
    if(r == 0)
        return 1;
    int fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % p;
    return (fact[n] * BinPow(fact[r], p - 2, p) % p * BinPow(fact[n - r], p - 2, p) % p) % p;
}
using namespace std;
bool prime[100100];
void isprime(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int p = 2; p * p <= 100100; p++){
        if(prime[p]){
            for(int i = p * p; i <= 100100; i+= p)
                prime[i] = false;
        }
    }
}
using namespace std;
void PrimeFactor(int n, vector <int> &vec){
    while(n % 2 == 0){
        vec.push_back(2);
        n /= 2;
    }
    for(int i = 3; i <= sqrt(n); i+= 2){
        while(n % i == 0){
            vec.push_back(i);
            n /= i;
        }
    }
    if(n > 2)
        vec.push_back(n);
}
using namespace std;
int smallestDiv(int n){
    if(n % 2 == 0)
        return 2;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0)
            return i;
    }
    return n;
}
using namespace std;
vector <pair <int, int> findSubarr(int arr[], int n){
    unordered_map <int, vector <int> > mp;
    vector <pair <int, int> >vec;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0)
            vec.push_back(make_pair(0, i));
        if(mp.find(sum) != mp.end()){
            vector <int> vc = mp[sum];
            for(auto it = vc.begin(); it != vc.end(); ++it)
                vec.push_back(make_pair(*it + 1, i));
        }
        mp[sum].push_back(i);
    }
    return vec;
}
int cntDisjoint(const vector <pair <int, int> > &vec){
    int cnt = 1;
    int prev = -1;
    for(const auto &it : vec){
        if(it.first > prev){
            cnt++;
            prev = it.second;
        }
    }
    return cnt;
}
using namespace std;
int longestSubseq(vector <int> vec){
    vector <int> ans;
    for(int i = 0; i < vec.size(); i++){
        auto it = upper_bound(ans.begin(), ans.end(), vec[i]);
        if(it == ans.end())
            ans.push_back(vec[i]);
        else
            *it = vec[i];
    }
    return ans.size();
}
using namespace std;
int getmid(int l, int r){
    return l + (r - l)/2;
}
int Util(const vector <int> &arr, int s, int e, vector <int> &st, int cur){
    if(s == e){
        st[cur] = arr[s];
        return st[cur];
    }
    int mid = getmid(s, e);
    st[cur] = max(Util(arr, s, mid, st, 2 * cur + 1), Util(arr, mid + 1, e, st, 2 *cur + 2));
    return st[cur];
}
vector <int> constructSt(const vector <int> &arr){
    int n = arr.size();
    int x = (int)(ceil(log2(n)));
    int maxSize = 2 * (int)pow(2, x) - 1;
    vector <int> st(maxSize, INT_MIN);
    Util(arr, 0, n - 1, st, 0);
    return st;
}
int MaxUtil(const vector <int> &st, int s, int e, int l, int r, int node){
    if(l <= s && r >= e)
        return st[node];
    if(s > r || e < l)
        return INT_MIN;
    int mid = getmid(s, e);
    return max(MaxUtil(st, s, mid, l, r, 2 * node + 1), MaxUtil(st, mid + 1, e, l, r, 2 * node + 2 ));
}
int getMax(vector <int> st, int n, int l, int r){
    if(l < 0 || r >= n || l > r){
        return INT_MIN;
    }
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
void update(vector <int> &arr, vector <int> &st, int s, int e, int idx, int val, int node){
    if(idx < s || idx > e)
        return;
    if(s == e){
        arr[idx] = val;
        st[node] = val;
    }
    else{
        int mid = getmid(s, e);
        if(idx <= mid)
            update(arr, st, s, mid, idx, val, 2 * node + 1);
        else
            update(arr, st, mid + 1, e, idx, val, 2 * node + 2);
        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }
}
int main(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    vector <int> st = constructSt(vec);
    while(true){
        int choice; cin >> choice;
        if(choice == 1){
            int l, r; cin >> l >> r;
            cout << "Maximum val between " << l << " & " << r << " is" << getMax(st, n, l, r);
        }
        else if(choice == 2){
            int idx, val; cin >> idx >> val;
            update(vec, st, 0, n - 1, idx, val, 0);
        }
        else if(choice == 3)
            break;
        else
            cerr << "Invalid input";
    }
}
using namespace std;
bool IsKthBit(int n, int k){
    if(n & (1 << k))
        return true;
    return false;
}
//print prime factors and their powers using Sieve Of Eratosthenes
using namespace std;
void sieve(int n, int arr[]){
    vector <bool> prime(n + 1, false);
    for(int i = 2; i <= n; i += 2)
        arr[i] = 2;
    for(int i = 3; i <= n; i+= 2){
        if(!prime[i]){
            arr[i] = i;
            for(int j = i; j * i <= n; j += 2){
                if(!prime[i * j]){
                    prime[i * j] = true;
                    arr[i * j] = i;
                }
            }
        }
    }
}
map <int, int> generatePrime(int n){
    //arr store smallest prime factors & factor store prime factors;
    map <int, int> factor;
    int arr[n + 1] = {0};
    sieve(n, arr);
    int cur = arr[n];
    int power = 1;
    while(n > 1){
        n /= arr[n];
        if(cur == arr[n])
            power++;
        else{
            factor[cur] = power;
            cur = arr[n];
            power = 1;
        }
    }
    return factor;
}
void print(map <int, int> &factor){
    for(const auto & [fact, power] : factor)
        cout << fact << " " << power << "\n";
}
int main(){
    int n = 100;
    map <int, int> factors = generatePrime(n);
    print(factors);
}
using namespace std;
//Returns count of subarrays of arr with XOR
int SubarrXor(int arr[], int n, int m){
    int ans = 0;
    // Map to store frequency of prefix XOR values
    // Create a prefix xor-sum array such that xorArr[i] has value equal to XOR
    // of all elements in arr[] vector<ll>xorArr(n);
    unordered_map <int, int> ump;
    // Initialize cumulative XOR
    int cx = 0;
    for(int i = 0; i < n; i++){
        cx ^= arr[i];
        if(cx == m)
            ans++;
        // Find XOR of current prefix with m
        int tmp = cx ^ m;
        // Add the frequency of the required XOR value
        if(ump.find(tmp)!= ump.end())
        // Increment the count of current XOR in the map
            ump[cx]++;
    }
    return ans;
}
//count all subarrays having XOR of elements as given value m with
// Returns count of subarrays of arr with XOR value equals to m
long long subarrayXor(int arr[], int n, int m)
{
	int ans = 0; 

	// Create a prefix xor-sum array such that xorArr[i] has value equal to XOR of all elements in arr[]
	// vector<ll>xorArr(n);
	// Create map that stores number of prefix array elements corresponding to a XOR value
	unordered_map<int, int> mp;
	// Initialize first element of prefix array [xorArr[0] = arr[0]]
	ll cx = arr[0];
	ll px = cx;
	// Computing the prefix array.
	// for (ll i = 1; i < n; i++)
	// 	xorArr[i] = xorArr[i - 1] ^ arr[i];
	// Calculate the answer
	for (ll i = 0; i < n; i++){
		px = cx;
		if (i != 0)
			cx = px ^ arr[i];
		// Find XOR of current prefix with m.
		// int tmp = m ^ xorArr[i];
		int tmp = m ^ cx;
		// If above XOR exists in map, then there is another previous prefix with same XOR,
		//there is a subarray ending at i with XOR equal to m.
		ans = ans + ((long long)mp[tmp]);
		// If this subarray has XOR equal to m itself.
		if (cx == m)
			ans++;
		// Add the XOR of this subarray to the map
		mp[cx]++;
	}
	// Return total count of subarrays having XOR of elements as given value m
	return ans;
}
using namespace std;
const int MAXN = 1e3;
int Factor[MAXN];
// Calculating SPF (Smallest Prime Factor) for every number till MAXN.
void sieve(){
    Factor[1] = 1;
    for(int i = 2; i < MAXM; i++)
        Factor[i] = i;
    for(int i = 4; i < MAXN; i+= 2)
        Factor[i] = 2;
    for(int i = 3; i * i < MAXN; i++){
        if(Factor[i] == i){
            for(int j = i * i; j < MAXN; j+= i){
                if(Factor[j] == j)
                    Factor[j] = i;
            }
        }
    }
}
vector <int> Factorization(int x){
    vector <int> res;
    while(x != 1){
        res.push_back(Factor[x]);
        x /= Factor[x];
    }
    return res;
}
int main(){
    sieve();
    int num; cin >> num;
    if(num < 1 || num >= MAXN) 
        return 1;
    vector <int> fac = Factorization(num);
    for(int i = 0; i < fac.size(); i++)
        cout << fac[i] << " ";
}
#include<bits/stdc++.h>
using namespace std;
int finish[10],TAT[10],WAT[10],star[10];
struct node{
    int name;
    int arrive;
    int burst;
}arr[10];
bool cmp(node A, node B)
{
    if( A.arrive == B.arrive)
        return A.name < B.name;
    return A.arrive < B.arrive;
}

void FCFS(int N)
{
    for(int i=0;i<N;i++)
    {
        if(i==0)
            star[i]=arr[i].arrive;
        else
            star[i]=finish[i-1];

        WAT[i]=star[i]-arr[i].arrive;
        finish[i]=star[i]+arr[i].burst;
        TAT[i]=finish[i]-arr[i].arrive;
    }

    double sum=0,sum1=0;
    for(int i = 0 ; i < N ; i++){
        sum += (double)WAT[i];
        sum1 += (double)TAT[i];
    }

    printf("Avg TAT : %f\n",sum1/(double)N);
    printf("Avg WAT : %f\n",sum/(double)N);

}
int main()
{
    int N;
    cin>>N;

    for(int i = 0; i < N; i++){
        arr[i].name = i+1;
        cin>>arr[i].arrive >> arr[i].burst;
    }

    sort(arr,arr+N,cmp);
    FCFS(N);
}
using namespace std;
void main(){
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int mn = 1e9;
    for(int i = 0; i <= n - k; i++)
        mn = min(mn, arr[i + k - 1]- arr[i])
    cout << mn;
}
using namespace std;
void main(){
    int n, res = 0; cin >> n;
    for(int i = 0; i <= n; i++){
        int x; cin >> x;
        res += x * pow(2, i);
    }
    int tmp = pow(2, n);
    if(res % tmp != 0)
        cout << -1;
    else
        cout << res / tmp;
}
using namespace std;
void main(){
    int n; cin >> n;
    char x, y;
    int a1 = a2 = b1 = b2 = c1 = c2 = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x = 'G') a1++;
        if(x == 'B') b1++;
        if(x == 'K') c1++;
    }
    for(int i = 0; i < n; i++){
        cin >> y;
        if(y == 'G') a2++;
        if(y == 'B') b2++;
        if(y == 'K') c2++;
    }
    int ans = min(a1, c2) + min(c1, b2) + min(b1, a2);
    cout << ans;
}
using namespace std;
void main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] % n == 0)
            cout << "1";
        else
            cout << "0";
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++)
                sum += arr[k];
            cout << "sum from idx " << i << " to " << j << " is " << sum << "\n";
        }
    }
}
using namespace std;
void main(){
    int n, m; cin >> n >> m;
    vector <int> vec(n + 1);
    for(int i = 1; i <= n; i++)
        vec[i] = i;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        swap(vec[a], vec[b])
    }
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        cout << vec[t] << " ";
    }
}
using namespace std;
// mex tahun baru : troc#18 c -> greedy
void main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << arr[0] << " ";
    
    if(n > 1){
        for(int i = 2; i < n; i++)
            cout << arr[i] << " ";
        cout << arr[1];
    }
}
#include<bits/stdc++.h>
// segitiga tahun baru: troc#18 D -> geometry
using namespace std;
void main(){
    int n; cin >> n;
    if(n == 2 || n == 3 || n == 5)
        cout << "4";
    else
        cout << "3";
}
// Pelajaran pangan : troc#16 B -> greedy
using namespace std;
void main(){
    int n, m; cin >> n >> m;
    int arr[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int res = arr[n] - arr[1];
    for(int i = 1; i < n; i++)
        res = min (res, arr[i] + m - arr[i + 1]);
    cout << res;
}
// Pertahanan wifi : Troc 11 B -> Greedy
using namespace std;
void main(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    for(int i = m - 1; i < n; i++)
        res = min(res, arr[i] - arr[i - m + 1]);
    cout << res;
}


// Membangun menara :  gemastik 2016 -> greedy
using namespace std;
void main(){
    int n; cin >> n;
    int arr[3];
    for(int i = 0; i < 3; i++){
        int q; cin >> q;
        int mx = 0, mn = 0;
        for(int j = 0; j < 3; j++){
            int x, y, z; cin >> x >> y >> z;
            mx += max(x, max(y, z));
            mn += min(x, min(y, z));
        }
        cout << mx << " " << mn;
    }
}
//Membeli mainan : Troc#3
using namespace std;
void main(){
    int x; cin >> x;
    int arr[3];
    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr + 3);
    int tmp = x / (arr[0] + arr[1] + arr[2]);
    int res = 3 * tmp;
    int remain = x - tmp * (arr[0] + arr[1] + arr[2]);
    for(int i = 0; i < 3; i++){
        if(rem >= arr[i]){
            rem -= arr[i];
            res++;
        }
    }
    cout << res;
}
// Menghtiung bola
using namespace std;
void main(){
    int n; cin >> n;
    int tmp = 1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == tmp){
            cout << "Benar" << fflush;
            tmp++;
        }
        else{
            cout << "Salah" << fflush;
            tmp = 1;
        }
    }
}
// Pola III : perulangan lanjut
using namespace std;
void main(){
    int n, x = 0; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << x % 10 << " ";
            x++;
        }
        cout << "\n";
    }
}
// Bilangan pecahan : mikroskil cp 2014
using namespace std;
void Factorization(){
    int a, b; cin >> a >> b;
    if(__gcd(a, b) > 1)
        cout << a / __gcd(a, b) << " " << b / __gcd(a, b);
    else
        cout << "No";
}
using namespace std;
int cntEven(int l, int r){
    int cnt = (r - l) / 2;
    if(l % 2 != 0 || r % 2 != 0)
        cnt++;
    return cnt;
}
int main(){
    int l, r, k; cin >> l >> r >> k;
    if(l == r){
        if(l == 1)
            cout << "No";
        else
            cout << "Yes";
        return 0;
    }
    int res = cntEven(l, r);
    (res > k) ? cout << "No" : cout << "Yes";
}
using namespace std;
void main(){
    int n, k; cin >> n >> k;
    int arr[n], tmp[n];
    vector <pair <int, int> >vec;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> tmp[i];
    for(int i = 0; i < n; i++)
        vec.push_back(make_pair(arr[i], tmp[i]));
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        if(vec[i].first <= k)
            k += vec[i].second;
        else
            break;
    }
    cout << k;
}
using namespace std;
void main(){
    int n, m; cin >> n >> m;
    int arr[n], seq[m], cnt = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < m; i++)
        cin >> seq[i];
    sort(arr, arr + n);
    sort(seq, seq + n);
    for(int i = 0, j = 0; i < n && j < m;){
        if(arr[i] == seq[j]){
            i++; j++; cnt++;
        }
        else if(arr[i] < seq[j])
            i++;
        else
            j++;
    }
    (cnt == n / 2) ? cout << "Yes" : cout << "No";
}
using namespace std;
void main(){
    int n; cin >> n;
    vector <int> vec;
    for(int i = 1; i <= n; i++)
        vec.push_back(i);
    if(n % 2){
        for(int i = 1; i <= n/2; i++)
            cout << i << " ";
        cout << n << " ";
        for(int i = n - 1; i < n / 2; i++)
            cout << i << " ";
        cout << n << " ";
    }
    else if(n != 2){
        cout << n / 2 << " ";
        for(int i = 1; i < n / 2; i++)
            cout << i << " ";
        for(int i = n; i < n / 2; i++){
            if(i != n / 2)
                cout << i << " ";
        }
    }
    else 
        cout << "No";
}
using namespace std;
void main(){
    vector <int> tmp;
    for(int i = 0; i < 17; i++){
        for(int j = i + 1; j < 18; j++){
            for(int k = j + 1; j < 19; j++){
                for(int l = k + 1; l < 20; l++){
                    int val = (1LL << i) + (1LL << j) + (1LL << k) + (1LL << l);
                    tmp.push_back(val);
                    if(tmp.size() == 100)
                        break;
                }
                if(tmp.size() == 100)
                    break;
            }
            if(tmp.size() == 100)
                break;
        }
        if(tmp.size() == 100)
            break;
    }
    for(int i = 0; i < tmp.size(); i++)
        cout << i << " ";
}
using namespace std;
void main(){
    int n; cin >> n;
    if(n == 1)
        cout << "6";
    else{
        int x = 3;
        for(int i = 0; i < n; i++){
            cout << x << " ";
            x += 2;
        }
    }
}
using namespace std;
int numOfArray(vector <int> &vec, int lower, int upper){
    int mini = 0, maxi = 0, sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
        mini = min(mini, sum);
        maxi = max(maxi, sum);
    }
    /*int cnt = 0;
    for(int i = lower; i <= upper; i++){
        if(i + mini < lower || i + maxi > upper)
            continue;
        else
            cnt++;
    }
    return 1LL * cnt;*/
    int startMin = lower - mini;
    int startMax = upper - maxi;
    if(startMax < lower || startMin > upper)
        return 0;
    return (int)(min(upper, startMax) - max(lower, startMin) + 1);
}
int main(){
    vector <int> vec = {1, -3, 4};
    cout << numOfArray(vec, 1, 6);
}
using namespace std;
void minCost(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    int sum = 0;
    sort(vec.rbegin(), vec.rend());
    for(int i = 0; i < vec.size(); i++)
        sum += vec[i];
    for(int i = 2; i < vec.size(); i += 3)
        sum -= vec[i];
    cout << sum
}
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode*> m;
    char c;
    bool isWord;
    TrieNode() : c(0), isWord(false) {}
    TrieNode(char ch) : c(ch), isWord(false) {}
};
class Trie {
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        deleteTrie(root);
    }
    void insert(const string& word) {
        TrieNode* p = root;
        for (char c : word) {
            if (p->m.find(c) == p->m.end()) {
                p->m[c] = new TrieNode(c);
            }
            p = p->m[c];
        }
        p->isWord = true;
    }
    bool search(const string& word) const {
        TrieNode* p = root;
        for (char c : word) {
            if (p->m.find(c) == p->m.end()) return false;
            p = p->m[c];
        }
        return p->isWord;
    }
    bool startsWith(const string& prefix) const {
        TrieNode* p = root;
        for (char c : prefix) {
            if (p->m.find(c) == p->m.end()) return false;
            p = p->m[c];
        }
        return true;
    }
    private:
    void deleteTrie(TrieNode* node) {
        for (auto& pair : node->m)
            deleteTrie(pair.second);
        delete node;
    }
};
using namespace std;
// Function to flip all bits of the number x.
int flip_bits(int x) {
    int flipped = 0, bit_position = 0;
    // Flipping all bits of the number.
    while (x) {
        if (x % 2 == 0) 
            flipped += (1LL << bit_position
        x /= 2;  
        // Shift x to the right to check the next bit.
        bit_position++;
    }
    return flipped;
}
int main() {
    int n; cin >> n;
    int total_sum = 0;
    while (n > 0) {
        int flipped_value = flip_bits(n); 
        int adjusted_value = n;
        if ((adjusted_value & (adjusted_value + 1)) == 0) {
                adjusted_value--;
            }
        int partial_sum = ((adjusted_value * (adjusted_value + 1)) / 2) - ((flipped_value * (flipped_value - 1)) / 2);
        total_sum += (partial_sum * 2);
        n = flipped_value - 1;
    }
    cout << total_sum << "\n";  //
    }
}
using namespace std;
int calculate(int mid, string str){
    int add = 0;
    for(int i = mid; i >= 0; i--){
        int x = (int (str[i])) - int('0') + add) % 10;
        if(x == 0)
            continue;
        add += 10 - x;
    }
    return add;
}
int main(){
    int n, k; cin >> n >> k;
    string str; cin >> str;
    int l = 0, r = n - 1, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(calculate(mid, str) > k)
            r = mid - 1;
        else{
            res++;
            l = mid + 1;
        }
    }
    cout << res;
}
using namespace std;
void main(){
    int n, k; cin >> n >> k;
    if(n > 1 && k == 1)
        cout << -1;
    else if(n == 1 && k == 1)
        cout << 1;
    else{
        for(int i = 1; i < k; i++)
            cout << i << " ";
        for(int i = n; i >= k; i--)
            cout << i << " ";
        cout << "\n";
    }
}
using namespace std;
def sieve(n):
    prime = [True for _ in range(n + 1)]
    p = 2
    while p * p <= n:
        if prime[p]:
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    primes = []
    for p in range(2, n + 1):
        if prime[p]:
            primes.append(p)
    return primes
primes = sieve(10**5)
	a = [1, 2, 3, 4, 5]
using namespace std;
def bl(arr, value):
    try:
        return arr.index(value)
    except ValueError:
        return -1
for _ in range(int(input())):
    n = int(input())
    t = bl(a, n - 1)
    if t >= len(a) or a[t] > n - 1:
        t -= 1

    deg = a[t]

    if n % 2:
        print((deg * (n - 1) + 2) // 2)
    else:
        print((deg * n) // 2)

using namespace std;
void main(){
    int n; cin >> n;
    int res;
    if(n > 3){
        if(n % 2 == 0)
            res = n + n / 2;
        else
            res = n + (n - 1) / 2;
        cout << res;
    }
    else
        cout << "-3";
}
using namespace std;
void main(){
    int n; cin >> n;
    int cur = 2;
    for(int i = 0; i < n; i++){
        cout << cur << " ";
        if(i % 2 == 0)
            cur++;
        else
            cur += 3;
    }
}
using namespace std;
vector <int> LongestNonDecSubseq(vector <int> &vec){
    //store the end elements of NonDecSubseq
    vector <int> tor;
    for(int i = 0; i < vec.size(); i++){
        if(tor.empty() || tor.back() <= vec[i])
            tor.push_back(vec[i]);
        else{
            int ub = upper_bound(tor.begin(), tor.end(), vec[i]) - tor.begin();
            tor[ub] = vec[i];
        }
    }
    return tor.size();
}
using namespace std;
int longestNonDecSubseq(vector <int> &vec){
    multiset <int> mset;
    multiset <int> ::iterator it;
    int n = vec.size();
    for(int i = 0; i < n; i++){
        mset.insert(vec[i]);
        it = mset.upper_bound(vec[i]);
        if(it != mset.end())
            mset.erase(it);
    }
    return mset.size();
}
int main(){
    int n, m; cin >> n >> m;
    vector <int> vec(n), tor(m);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    for(int i = 0; i < m; i++)
        cin >> tor[i];
    cout << longestNonDecSubseq(vec) + longestNonDecSubseq(tor);
}
using namespace std;
void main(){
    int n, cin >> n;
    string str, ing; cin >> str >> ing;
    vector<int> vec(n + 1, 0), tor(n + 1, 0);
    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)
            dp[i][j] = 1e18;
    }
    dp[n][n] = 0;
    for(int i = n - 1; i >= 0; i--){
        vec[i] = vec[i + 1] + (str[i] == '0');
        tor[i] = tor[i + 1] + (ing[i] == '0');
    }
    for(int i = n - 1; i >= 0; i--){
        dp[n][i] = dp[n][i + 1];
        if(ing[i] == '1')
            dp[n][i] += vec[n] + tor[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                if (str[i] == '1')
                    dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + vec[i] + tor[j]);
        }
    }
    cout << dp[0][0];
}
using namespace std;
void main(){
    int n; cin >> n;
    vector <float> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.rbegin(), vec.rend());
    int sum = 0;
    for(int i = 1; i < n; i++)
        sum += vec[i];
    float res = sum / (n - 1);
    res += vec[0];
    cout << res;
/*
	for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())), reverse = True)
    m1 = a[0]
    m2 = (sum(a) - m1) / (n - 1) 
    print(m1 + m2)
    */
}
using namespace std;
void printChar(){
    int n; cin >> n;
    int base = 97;
    for(int i = 0; i < n; i++){
        if(base > 122)
            base = 97;
        cout << char(base) << " ";
        base++;
    }
}
using namespace std;
void computePrefixSuffixGCD(int prefix[], int arr[], int suffix[], int n) {
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = gcd(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = gcd(suffix[i + 1], arr[i]);
    }
}
using namespace std;
void computePrefixGCD(int arr[], int p[], int n) {
    p[0] = arr[0];
    for (int i = 1; i < n; i++)
        p[i] = gcd(p[i - 1], arr[i]);
}
void computeSuffixGCD(int arr[], int s[], int n) {
    s[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        s[i] = gcd(s[i + 1], arr[i]);
}
// Function to calculate the result based on prefix and suffix GCD
int Pratik(int l, int r, int p[], int s[], int n) {
    if (l == 0)
        return s[r + 1];
    if (r == n - 1)
        return p[l - 1];
    return gcd(p[l - 1], s[r + 1]);
}
int main() {
    int n, q; cin >> n >> q;
    int arr[n], p[n], s[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    computePrefixGCD(arr, p, n);
    computeSuffixGCD(arr, s, n);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << "Result: " << Pratik(l, r, p, s, n) << endl;
    }
    return 0;
}
using namespace std;
void frameWork(){
    int row, col; cin >> row >> col;
    int start = 0;
    for(int i = 0, a = col + 1; i < n; i++, a++){
        start = i + 1;
        cout << start << " ";
        for(int j = 1; j < col; j++){
            cout << start + a << " ";
            start += a;
        }
    }
    cout << "\n";
}
void frameWork(){
    int row, col; cin >> row >> col;
    for(int i = 0; i < col; i++)
        cout << i + 1 << " ";
    int face = 2 + n;
    for(int i = 1; i < row; i++){
        int x = face;
        cout << x << " ";
        for(int j = 1; j < col; j++){
            cout << x + i + 1;
            x += i + 1;
        }
    }
    face += row + 1;
    cout << "\n";
}
using namespace std;
int lcm(int a, int b){
    return (a * (b / __gcd(a, b)));
}
bool IsPrime(int n){
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    if(a == b) return a;
    if(a > b) return gcd(a - b, b);
    else return gcd(a, b - a);
}
bool IsPerfect(int x){
    if(x >= 0){
        int n = sqrt(x);
        return (n * n == x);
    }
    return false;
}
using namespace std;
int leftRotate(int arr[], int n){
    int tmp = arr[0];
    for(int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n - 1] = tmp;
}
int main(){
    int n, pos; cin >> n >> pos;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    d %= n;
    for(int i = 0; i < pos; i++)
        leftRotate(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
string intToString(int n){
    char ch[100];
    sprintf(ch, "%lld", ch);
    string str = ch;
    return str;
}
int stringToInt(string str){
    char ch[100];
    int res;
    strcpy(ch, str.c_str());
    sscanf(ch, "%lld", &res);
    return res;
}
string ToBinary(int n){
    int arr[100], i = 0;
    while(n > 0){
        arr[i] = n % 2;
        n /= 2;
        i++;
    }
    string res = " ";
    for(int j = i - 1; j >= 0; j--)
        str += to_string(arr[i]);
    return str;
}
void revstr(string &str){
    int len = str.size();
    for(int i = 0; i < len / 2; i++)
        swap(str[i], str[n - i - 1]);
}
using namespace std;
int dp(int n){
    if(n == 1 || n == 2)
        return 1;
    if(n == 3)
        return 2;
    if(tmp[n] != 0)
        return tmp[n];
    tmp[n] = dp(n - 1) + dp(n - 3);
    return tmp[n];
}
int main(){
    int n; cin >> n;
    cout << dp(n);
}
using namespace std;
int main(){
    int x, a = 0, b = 0;
    char ch;
    for(int i = 0; i < 6; i++){
        cin >> x >> y;
        if(ch == 'A')
            a++;
        else if(ch == 'B')
            b++;
    }
    if(b >= 3)
        cout << 100;
    else if(b == 3)
        cout << 70;
    else
        cout << 40;
}
using namespace std;
void main(){
    string str; cin >> str;
    bool flag = false;
    if(str[0] != str[1]){
        if(str[0] != str[2])
            cout << "1";
        else
            cout << "2";
    }
    for(int i = 2; i < str.length(); i++){
        if(str[i] != str[i - 1] && str[i] != str[i - 2])
            cout << i + 1;
    }
}
using namespace std;
void main(){
    int n, arr[100][100]; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[0][i];
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n; i++)
            tmp[j][i] = tmp[j - 1][i + 1] - tmp[j - 1][i];
    }
    for(int i = 0; i < n; i++){
        if(i < n)
            cout << tmp[i][0] << " ";
    }
}
using namespace std;
int main(){
    int n, m, a; cin >> n >> m >> a;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vec.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    cout << vec[a - 1];
}
using namespace std;
int n, k, val[502], wt[502], dp[502][2001], item[502];
void knapsack(int n, int k){
    for(int cap = 0; cap <= k; cap++)
        dp[0][cap] = 0;
    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap<= k; cap++) {
            if (cap >= wt[i])
                dp[i][cap] = max(dp[i - 1][cap], dp[i - 1][cap- wt[i]] + val[i]);
            else
                dp[i][cap] = dp[i - 1][cap];
        }
    }
}
void findSelectedItems(ll n, ll k){
    int itemIndex = 0; 
    // Index for storing selected items
    int remCap= k;
    while (n > 0 && remCap > 0) {
        // If the current dp value is the same as the one without this item, skip it
        if (dp[n][remCap] == dp[n - 1][remCap])
            n--;
        else{
            items[itemIndex++] = n;
            remCap -= wt[n];
            n--;
        }
    }
    // Sort the selected items in ascending order
    sort(items, items + itemIndex);
    // Output the selected items
    for (int i = 0; i < itemIndex; i++) {
        cout << items[i] << endl;
    }
}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];
    knapsack(n, k);
    findSelectedItems(n, k);
}
using namespace std;
const int MOD = 1e9 + 7;
int addMod(int x, int y) {
    return ((x % MOD) + (y % MOD) + MOD) % MOD;
}
int subMod(int x, int y) {
    return ((x % MOD) - (y % MOD) + MOD) % MOD;
}
int mulMod(int x, int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}
int powerMod(int x, int y) {
    if (y == 0) return 1;
    int half = powerMod(x, y / 2);
    half = mulMod(half, half);
    if (y % 2 == 1) {
        half = mulMod(half, x);
    }
    return half;
}
// Modular division using Fermat's Little Theorem
int divMod(int x, int y) {
    return mulMod(x, powerMod(y, MOD - 2));
}
int main() {
    int n, k; cin >> n >> k;
    // Compute a = n * (n^k - 1)
    int term1 = powerMod(n, k);  
    // n^k
    int term2 = subMod(term1, 1);
    // n^k - 1
    int a = mulMod(n, term2);  
    // n * (n^k - 1)
    // Compute b = n - 1
    int b = subMod(n, 1);
    // Result = a / b (mod MOD)
    cout << divMod(a, b) << endl;
    return 0;
}

using namespace std;
int n, m, a[265000];
// Binary search function to find the minimum time required to satisfy the condition
int binser(int target, int max_time) {
    int l = 0; // Lower bound for time
    int r = max_time; // Upper bound for time
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int total = 0;
        // Calculate the total production or completion for time `mid`
        for (int i = 0; i < n; i++)
            total += mid / arr[i];
        // Adjust search range based on whether total meets the target
        if (total < target)
            l = mid + 1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
int main() {
    // number of machines and the required number of products
    cin >> n >> m;
    // time taken by each machine to produce one unit
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Calculate and print the difference between the two binary search results
    ll max_time = arr[0] * m; 
    // Set an upper bound for search
    cout << binsearch(m + 1, max_time) - binsearch(m, max_time) << endl;
    return 0;
}
using namespace std;
void main(){
    string str; getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if(str[i] - 2 < 65 && str[i] != ' ')
            str[i] += 24;
        else if(str[i] != ' ')
            str[i] -= 2;
        cout << str[i];
    }
}
using namespace std;
void main(){
    int n, mn = 1e4, mx = 0;
    while(cin >> n){
        if(n == 0){
            cout << mn << " " << mx;
            return 0;
        }
        else{
            mx = max(mx, a);
            mn = min(mn, a);
        }
    }
    cout << mx << " " << mx;
}
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int tmp = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(tmp != x){
            while(cnt <= n && arr[cnt] != x)
                cnt++;
            tmp = x;
        }
    }
    (cnt <= n) ? cout << "Yes" : cout << "No";
}
// Mengangkut bebek : OSP 2022 
using namespace std;
void main(){
    int n, k; cin >> n >> k;
    int arr[n];
    pair <int, int> pr;
    for(int i = 0; i < k; i++)
        cin >> pr[i].first;
    for(int i = 0; i < k; i++)
        cin >> pr[i].second;
    sort(pr, pr + k + 1);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater <int> ());
    int j = ans = 0;
    for(int i = 0; i < n; i++){
        ans += pr[j].first * arr[i];
        pr[j].second-;
        if(pr[j].second == 0)
            j++;
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
void main(){
    int n, cin >> n;
    int arr[n]; cin >> arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int res = lower_bound(arr, arr + n, x) - arr;
        cout << res;
    }
}
using namespace std;
void main(){
    int n; cin >> n;
    int arr[n], tmp[n], mx = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i] >> tmp[i];
        mx = max(mx, arr[i] * tmp[i]);
    }
    cout << mx;
}
using namespace std;
void main(){
    int n, m; cin >> n, m;
    if(n == 1)
        cout << m - 1;
    else if(m == 1)
        cout << n - 1;
    else
        cout << n * (m - 1);
}
using namespace std;
void main(){
    int n, a = b = c = 0;
    char ch;
    for(int i = 0; i < n; i++){
        cin >> ch;
        if(ch == '1')
            a += 1;
        if(ch == '2')
            b += a;
        if(ch == '3')
            c += b;
    }
    cout << c;
}
using namespace std;
void main(){
    int n, res = 0; cin >> n;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        res += x;
    }
    cout << res / 2;
}
using namespace std;
void main(){
    string str; cin >> str;
    int n; cin >> n;
    while(n > 0){
        cout << n << " ";
        if(n - 1 != 0)
            cout << "Yes";
        else
            cout << "No";
        n--;
    }
}
using namespace std;
int fact(int x, int y){
    if(y == 0)
        return 1;
    return x * fact(x, y - 1);
}
int main(){
    int x, y; cin >> x >> y;
    cout << fact(x, y);
}
