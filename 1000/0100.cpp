//find the minimum integer x such that the sum of the series 
//x+ x/k + x/k^2 + x/k^3..... +… is at least n
bool check(int x, int n, int k){
    int a = k;
    int sum = x;
    while(x / a > 0){
        sum += x / a;
        a *= k;
    }
    if(sum >= n)
        return true;
    return false;
}
int FindMin(){
    int low = 1, high = INT_MAX, mid;
    while(low < high){
        mid = low + (high - low)/2;
        if(check(mid, n, k))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
main(){
    int n, k; cin >> n >> k;
    //x + x/(1)^i……… will be infinie loop
    if(k == 1){
        cout << "The minimum x such that the sum of the series is at least " << n << " is: " << n << "\n";
        return 0;
    }
    int res = FindMin(n, k);
    cout <<…"The minimum x such that the sum of the series is at least " << n << " is: " << result << "\n";
}

//calculating the binomial coefficient 
#define ll long long
#define MOD 998244353
ll fact(ll n){
    int res = 1;
    while(n !=0){
        res = (res * n) % MOD;
        n--;
    }
    return res;
}
ll modExp(ll a, ll b){
    int res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll Inverse(ll a){
    return modExp(a, MOD - 2);
}
 main(){
    int n, r; cin >> n >> r;
    if(r < 0 || r > n)
        return 0;
    ll nume = fact(n);
    ll denom = (fact(n - r) * fact(r)) % MOD;
    ll res = (nume * Inverse(denom)) % MOD;
    cout << res;
}
//compute the modular inverse of a number num modulo mod using the Extended Euclidean Algorithm. 
int ExtendedGcd(int num, int mod, int x, int y){
    //num * x + mod * y = gcd(num, mod)
    if(num == 0){
        x = 1; y = 0;
        return num;
    }
    int a, b;
   // mod * a + (num % mod) * b = gcd(num, num % mod)
    int gcd = ExtendedGcd(mod, num % mod, a, b);
    x = b;
    y = a - b *(num/mod);
    return gcd;
}
int modInverse(int num, int mod){
    int x, y;
    int gcd = ExtendedGcd(num, mod, x, y);
    if(gcd != 1)
        return -1;
    else {
        x = (x % mod + mod) % mod;
        return x;
    }
}
main(){
    int num, mod; cin >> num >> mod;
    int Inverse = modInverse(num, mod);
    if(Inverse == -1)
        cout << "Doesn't Exits";
    else 
        cout << "Modular Inverse of " << num << " mod " << mod << " is " << Inverse;
}

// Count production Time
void CountTime(){
    int n = 10000, UMP = 600 / 60;
    //n->Initial Quantity, UMP->units per min
    int TotalTime = 0;
    while(n){
        if(n - 600 < 0){
            TotalTime += n / UMP;
            break;
        }
        else {
            n -= 300;
            TotalTime += 30;
        }
    }
    cout << TotalTime;
}

void CntMin(){
    int cnt = 0;
    for(int i = 1922; i <= 2020; i++){
        if((i % 4 == 0 && i % 100 !=0) || (i % 400 == 0))
            cnt += 366;
        else
            cnt += 365;
    }
    cout << cnt * 24 * 60;
}

//EuclidGCD
int EuclidGCD(int a, int b){
    if(b == 0)
        return a;
    int rem = a % b;
    return EuclidGCD(b, rem);
}
main(){
    int a, b;
    cin >> a >> b;
    cout << EuclidGCD(a, b);
    
}

void BinaryConv(){
    int num; cin >> num;
    for(int i = 31; i >= 0; i--){
        if(num & (1 << i))
            cout << "1";
        else 
            cout << "0";
    }
}

//define is a number prime or not.if prime it will be Intelligeng.else stupid
int check(int num){
    if(num <= 1)
        return 0;
    for(int i = 2; i * i <= num; ++i){
        if(num % i == 0)
            return 0;
    }
    return 1;
}
main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(check(x)){
            (i == x)? cout << "Intelligent":cout << "Intelligent";
        }
        else {
            (i == x)? cout << "Stupid" :cout << "Stupid";
        }
    }
}

//divide an integer n into part parts, each of which should not exceed limit. 
void DivideIntoPart(){
    int n, part, limit;
    cin >> n >> part >> limit;
    for(int i = 0; i < part; i++){
        if(n >= limit){
            n -= limit;
            cout << limit;
        }
        else{
            cout << n;
            n = 0;
        }
        if(i < part -1)
            cout << " ";
    }
}

void AddVal(){
    int ans = 0;
    for(int i = 0; i < 2; i++){
        ans += 4;
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 6; k++)
                ans += 5;
            ans += 7;
        }
        ans += 8;
    }
    ans += 9;
    cout << ans;
}

void compareSQRT(){
    int x, y;
    cin >> x >> y;
    (sqrt(x * x + y * y) == int(sqrt(x * x + y * y)))? cout << "Same" : cout << "Not same";
}
void IsDivisible(){
    int x, y; cin >> x >> y;
    int Ind = x % y;
    (Ind == 0)?cout << "Yes":cout << "No";
}

//find the divisor of 100 that minimizes the expression 
//involving the quotient and the divisor itself. 
void FindDivisor(){
    int ans = 0, sum = INT_MAX;
    for(int i = 1; i <= 100; i++){
        if(100 % i == 0){
            int tmp = 100/i + i;
            if(tmp < sum){
                sum = tmp;
                ans = i;
            }
        }
    }
    cout << ans;
}

void CntRunAvg(){
    int n; cin >> n;
    int score[n + 10], sum = 0;
    int maxi = INT_MIN, mini = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> score[i];
        maxi = max(score[i], maxi);
        mini = min(score[i], mini);
        sum += score[i];
    }
    double avg = double(sum)/double(n);
    cout << "Average is: " << avg << "\nMaximum is: " << maxi << "\nMinimum is: " << mini;
}

//process a list of arithmetic operations and output their 
//results in a simplified fraction format. 
void process(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        char ch;
        cin >> x >> y >> ch;
        if(x % y == 0)
            cout << x / y;
        else{
            if(y == 1)
                cout << x;
            else{
                int divisor =__gcd(x, y);
                cout << x / divisor << " " << ch << " " << y / divisor;
            }
        }
        if(i < n -1)
            cout << "\n";
    }
}

void BitManipulation(){
    int x = -2147483647;
    long z = 4294967296U;
    ui y = static_cast <ui>(x);
    cout << "x: " << x << "\nY: " << y;
    cout << "\nz: " << z << "\nz - (-x): " << z - (-x) << "\n";
    cin >> x;
    for(int i = 31; i >= 0; i--){
        if(x & (1 << i))
            cout << "1";
        else 
            cout << "0";
    }
    cout << "\n";
    int a = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int b = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    int c = a | b;
    for(int i = 0; i < 32; i++){
        if(c & (1 << i))
            cout << i << " ";
    }
    cout << "\n";
}
void Perform(){
    int a, b; cin >> a >> b;
    a = a % 100;
    b = b % 100;
    a += b;
    cout << a % 100;
}
// Fibonacci count
void Fibonacci(){
    int n; cin >> n;
    int a = 0, b = 1, c;
    for(int i = 0; i < n; i++){
        c = a + b;
        a = b; b = c;
    }
    cout << c;
}
//Perform time Addition
void TimeAdd(){
    int Hrs, Min, Sec;
    int AddHrs, AddMin, AddSec;
    cin >> Hrs >> Min >> Sec >> AddHrs >> AddMin >> AddSec;
    Sec += AddSec;
    if(Sec >= 60){
        Min += Sec/60;
        Sec = Sec % 60;
    }
    Min += AddMin;
    if(Min >= 60){
        Hrs += Min/60;
        Min = Min % 60;
    }
    Hrs += AddHrs;
    cout << "\nHours: " << Hrs << "\nMinutes: " << Min << "\nSecond: " << Sec;
}
//determine if two numbers a & b form an amicable pair. Amicable numbers are 
//two different numbers so related that the sum of the proper divisors 
//(excluding the number itself) of each is equal to the other number.
int IsAmicable(int x){
    int ans = 1;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            ans += i ;
            if(i !=x /i)
                ans += x/i;
        }
    }
    return ans;
}
int main(){
    int a, b;
    cin >> a >> b;
    (IsAmicable(a) == b && IsAmicable(b) == a)?cout << "Yes": cout << "No";
}
//wether sum of the three num less than two
void Smaller(){
    int ans = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        if(a + b + c <= 2)
            ans++;
    }
    cout >> ans;
}
//implementation of the modular exponentiation algorithm, which efficiently computes (a^b) % c
void Exponentiation(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1;
    a = a % c;
    while(b){
        if(b & 1)
            ans =(ans * b) % c;
        a = (a * a) % c;
        b >> 1;
    }
    cout << ans;
}
//calculates the area of the smallest square that can completely cover two given rectangles on a 2D plane. 
void SmallestSquare(){
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    cin >> x1 >> x2 >> x3 >> x4;
    cin >> y1 >> y2 >> y3 >> y4;
    int a = max(x2, x4) - min(x1, x3);
    int b = max(y2, y4) - min(y1, y3);
    int c = max(a, b);
    cout << c * c;
}
#include<bits/stdc++.h>
using namespace std;
//determine whether there exists an integer i [0, 65] such that the expression (n * i + 18) % 65 == 0
void verify(){
    int n; cin >> n;
    bool flag = true;
    for(int i = 0; i < 66; i++){
        if((n * i + 18) % 65 == 0){
            cout << i << " ";
            flag = false;
            break;
        }
    }
    (flag == true) ?cout << "Yes": cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
void BubbleSort(){
    int n; cin >> n;
    int arr[n + 3];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(abs(arr[i]) > abs(arr[j]))
                swap(arr[i], arr[j]);
        }
    }
    for(int i = 0; i < n - 1; i++)
        cout << arr[i] << " ";
    cout << arr[n - 1];
}
//Divide n in even pair
void DivideEven(){
    int n; cin >> n;
    for(int i = 2; i < n; i+=2){
        if((n - i) % 2 == 0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
//check if all numbers in the range [x,y], when transformed by the function f(i)=i^2 + i + 41 
//result in prime numbers. If all such numbers are prime, it outputs "ok"; else  "Break out".
bool IsPrime(int x){
    if(x <= 1)
        return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0)
            return false;
    return true;
}
main(){
    int x, y;
    while(cin >> x >> y && x !=0 && y !=0){
        bool flag = true;
        for(int i = x; i <= y; i++){
            if(!IsPrime(i * i + i + 41)){
                cout << "Break out";
                flag = false;
                break;
            }
        }
        if(flag == true)
            cout << "ok";
    }
}
//counts the number of pairs of integers within the range [1, 2020] 
//that are coprime (they share no common divisors other than 1).
int gcd(int a, int b){
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}
main(){
    int cnt = 0;
    for(int i = 1; i <= 2020; i++){
        for(int j = 1; j <= 2020; j++){
            if(gcd(i, j) == 1)
                cnt++;
        }
    }
    cout << cnt;
}
//Count the number of times the digit '2' appears in the integers from 1 to 2020.
void count(){
    int ans = 0;
    for(int i = 1; i <= 2020; i++){
        int tmp = i;
        while(tmp){
            cout << tmp << " ";
            if(tmp % 10 == 2)
                ans++;
            tmp /= 10;
        }
    }
    cout << ans;
}
void CountCeil(){
    int a, b; cin >> a >> b;
    (a % b == 0) ? cout << a /b: cout << a/b + 1;
}
void FindSqrt(){
    int n; cin >> n;
    int l = 1, r = n;
    while(r > l){
        r = l + (r - l)/2;
        l = n / r;
    }
    cout << r;
}
void Exponential(){
    int a, b, res = 1;
    cin >> a >> b;
    while(b){
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    cout << res;
}
