#include<bits/stdc++.h>
#include<cmath>
#include<string>
#include <cctype>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n], tmp[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j)
                sum += arr[j];
        }
        tmp[i] = sum;
        sum = 0;
    }
    for(int i = 0; i < n; i++)
        cout << tmp[i] << " ";
}
using namespace std;
bool sortbysec(const pair <string, int> &a, const pair <string, int> &b){
    if(a.second!= b.second)
        return a.second > b.second;
    if (a.first.find(b.first) == 0 || b.first.find(a.first) == 0)
        return a.first.size() > b.first.size();
    return a.first < b.first;
}
int main(){
    int n; cin >> n;
    vector <string> name;
    vector <int> mark;
    vector <pair <string, int> > vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end(), sortbysec);
    for(int i = 0; i < n; i++)
        cout << vec[i].first << " " << vec[i].second;
}
using namespace std;
string ReducedStr(string &str){
    string res;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(!res.empty() && res.back() == ch)
            res.pop_back();
        else
            res.push_back(ch);
    }
    return (res.empty() ? "Empty" : res);
}
int main(){
    string str; cin >> str;
    cout << ReducedStr(str);
}
using namespace std;
void FindConsecutive(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(n < 3){
        cout << -1;
        continue;
    }
    sort(arr, arr + n);
    bool found = false;
    for(int i = 0; i < n - 2; i++){
        if(arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]){
            cout << arr[i];
            found = true;
            break;
        }
    }
    if(!found)
        cout << -1;
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
void Consecutive(){
    string str; cin >> str;
    int len = str.size();
    if(len == 1){
        cout << "No";
        return 0;
    }
    bool valid = true;
    for(int i = 0; i < len; i++){
        if(i == 0){
            if(str[i]!= str[i + 1]){
                valid = false;
                break;
            }
        }
        else if(i == len - 1){
            if(str[i] != str[i - 1]){
                valid = false;
                break;
            }
        }
        else{
            if(str[i] != str[i + 1] && str[i] != str[i - 1]){
                valid = false;
                break;
            }
        }
    }
    cout << (valid ? "Yes" : "No");
}
using namespace std;
void check(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    bool valid = true;
    int evenIdx = arr[0] % 2;
    for(int i = 0; i < n; i += 2){
        if(arr[i] % 2 != evenIdx){
            valid = false;
            break;
        }
    }
    if(valid){
        int oddIdx = (n > 1) ?  arr[1] % 2 : evenIdx;
        for(int i = 1; i < n; i += 2){
            if(arr[i] % 2 != oddIdx){
                valid = false;
                break;
            }
        }
    }
    cout << (valid ? cout << "Yes" : cout << "No");
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
void Satisfied(){ 
    int cnt = 0;
    int n; cin >> n;
    string str[n];
    for(int i = 0; i < n; i++)
        cin >> str[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((str[i][0] == str[j][0] && str[i][1] != str[j][1]) || (str[i][0] != str[j][0] && str[i][1] == str[j][1]))
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
//swap occurrences of "BG" to "GB" in a string repeatedly until no more "BG" pairs can be found and swapped
void swap(){
    int n; string str;
    cin >> n >> str;
    size_t found = 0;
    while(found < str.size()){
        found = str.find("BG", found);
        if(found != string::npos){
            str[found] = 'G';
            str[found + 1] = 'B';
            found += 2;
        }
        else
            break;
    }
    cout << str;
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
void printChar(){
    string str; cin >> str;
    for(int i = 0; i < str.size(); i++){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            if(i + 1 < str.size() && isdigit(str[i + 1])){
                int n = str[i + 1] - '0';
                for(int j = 0; j < n; j++)
                    cout << str[i] << " ";
                i++;
            }
            else
                cout << str[i] << " ";
        }
        
    }
}
using namespace std;
//find the divisor of 100 that minimizes the value of the expression 100 / i + i.
void FindDiv(){
    int ans = 0, sum = INT_MAX;
    for(int i = 1; i <= 100; i++){
        if(100 % i == 0){
            int cur = 100/i + i;
            if(cur < sum){
                sum = cur;
                ans = i;
            }
        }
    }
    cout << ans;
}
using namespace std;
int func(int n){
    int cnt = 0;
    while(n){
        if(n % 10 == 2)
            cnt++;
        n /= 10;
    }
    return cnt;
}
int main(){
    int ans = 0;
    for(int i = 1; i <= 2020; i++)
        ans += func(i);
    cout << ans;
}
using namespace std;
int GCD(int a, int b){
    if(a % b == 0)
        return b;
    return GCD(b, a % b);
}
int main(){
    int ans = 0;
    for(int i = 1; i <= 2020; i++){
        for(int j = 1; j <= 2020; j++){
            if(GCD(i, j) == 1)
                ans++;
        }
    }
    cout << ans;
}
using namespace std;
void MaxMin(){
    int n; cin >> n;
    int score[100001], mx = 0, mn = INT_MAX, total;
    for(int i = 0; i < n; i++){
        cin >> score[i];
        mx = max(mx, score[i]);
        mn = min(mn, score[i]);
        total += score[i];
    }
    double avg = static_cast<double>(total)/n;
    cout << mx << " " << mn << " " << avg;
}
using namespace std;
void Morse(){
    string str, vec;
    cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] == '.')
            vec.push_back('0');
        else if(str[i] == '-'){
            if(i + 1 < len && str[i + 1] == '.'){
                vec.push_back('1');
                i++;
            }
            else if(i + 1 < len && str[i + 1] == '-'){
                vec.push_back('2');
                i++;
            }
        }
    }
    cout << vec;
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
using namespace std;
int SumOfDigit(int num){
    return num == 0 ? 0 : num % 10 + SumOfDigit(num / 10);
}
int sumI(int num){
    int sum = 0;
    for(int i = 4; i < num; i+= 3){
        sum += ++i;
        if(i < num)
            sum += i;
    }
    return sum;
}
int sumO(int num){
    int sum = 0;
    for(int i = 2; i < num; i += 2){
        sum += ++i;
        if(i < num)
            sum += i;
    }
    return sum;
}
int cntDiv(int n){
    int cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(n / i == i)
                cnt++;
            else
                cnt += 2;
        }
    }
    return cnt;
}
vector <int> CountFreq(string str, string txt){
    int m = str.size(), n = txt.size();
    int res = 0;
    vector <int> vec;
    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(txt[i + j] != str[j])
                break;
        }
        if(j == m)
            vec.push_back(i);
    }
    return vec;
}
int main(){
    string txt = "ABABDABACDABABCABAB";
    string str = "ABABCABAB";
    vector <int> res = CountFreq(str, txt);
    for(auto idx : res)
        cout << idx << " ";
    cout << "\n";
}
