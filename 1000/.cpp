using namespace std;
void euclidGCD(int a, int b){
    if(b == 0)
        return a;
    int rem = a % b;
    return euclidGCD(b, rem);
}
int main(){
    int a, b; cin >> a >> b;
    cout << euclidGCD(a, b);
}
using namespace std;
void cntMinute(){
    int res = 0;
    for(int i = 1922; i <= 2020; i++){
        if((i % 4 == 0 && i % 4 != 0) || (i % 400 == 0))
            res += 366;
        else
            res += 365;
    }
    cout << res * 24 * 60;
}
using namespace std;
void productionTime(){
    int Quantity = 10000, Ump = 10;
    int totalTime = 0;
    while(Quantity){
        if(Quantity < 300){
            totalTime += n / 10;
            break;
        }
        else{
            n -= 300;
            totalTime += 30;
        }
    }
    cout << totalTime;
}
using namespace std;
//define is a number prime or not.if prime will be Intelligeng else stupid
bool Isprime(int x){
    if(x <= 1)
        return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        (Isprime(x)) ? cout << "Intelligent" : cout << "stupid";
    }
}
using namespace std;
// divide n into a specified number of parts, ensuring that no part exceeds a given limit. 
void Dividelimit(){
    int n, limit, part; cin >> n >> limit >> part;
    for(int i = 0; i < part; i++){
        if(n >= limit){
            n -= limit;
            cout << limit << " ";
        }
        else{
            cout << n << " ";
            n = 0;
        }
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
using namespace std;
void CompDivisible(){
    int x, y; cin >> x >> y;
    (x % y == 0) ? cout << "Yes" : cout << "No";
    (sqrt(x * x + y * y) == int(sqrt(x * x + y * y))? cout << "Same" : cout << "Not Same");
}
using namespace std;
//find the divisor of 100 that minimizes the expression involving the quotient and the divisor itself. 
void satisfyCond(){
    int idx = 0, sum = INT_MAX;
    for(int i = 1; i <= 100; i++){
        if(100 % i == 0){
            int tmp = 100 / i + i;
            if(tmp < sum)
                sum = tmp;
                idx = i;
        }
    }
    cout << idx;
}
using namespace std;
void countAvg(){
    int n; cin >> n;
    int score[n], sum = 0;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> score[i];
        mini = min(mini, score[i]);
        maxi = max(maxi, score[i]);
        sum += score[i];
    }
    double avg = double(sum) / double(n);
    cout << "Maxi: " << maxi << "\nMini: " << mini << "\nAvg: " << avg;
}
using namespace std;
//compute the modular inverse of a number num modulo mod using the Extended Euclidean Algorithm. 
int Extend(int num, int mod, int x, int y){
    //num * x + mod * y = gcd(num, mod)
    if(num == 0){
        x = 0; y = 1;
        return mod;
    }
    int a, b;
    // mod * a + (num % mod) * b = gcd(num, num % mod)
    int gcd = Extend(mod % num, num, a, b);
    x = b - (mod / num) * a;
    y = a;
    return gcd;
}
int modInv(int num, int mod){
    if x, y;
    int gcd = Extend(int num, int mod, int x, int y);
    if(gcd != 1)
        return -1;
    else{
        x = (x % mod + mod) % mod;
        return x;
    }
}
int main(){
    int num, mod; cin >> num >> mod;
    int inverse = modInv(num, mod);
    if (inverse == -1)
        cout << "Modular Inverse doesn't exist" << endl;
    else
        cout << "Modular Inverse of " << num << " mod " << mod << " is " << inverse << endl;

}
using namespace std;
//Calculate Binomial Coefficient(ncr)
#define mod 998244353
int Exp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int Inverse(int n){
    return Exp(n, mod - 2);
}
int fact(int n){
    int res = 1;
    while(n){
        res = (res * n) % mod;
        n--;
    }
    return res;
}
int main(){
    int n, r; cin >> n >> r;
    int numer = fact(n);
    int denom = (fact(r) * fact(n - r)) % mod;
    int res = (numer * Inverse(denom)) % mod;
    cout << res;
}
using namespace std;
//finds the minimum integer x such that the sum of the following series is at least a given target sum = x+ x/k + x/k^2 + x/k^3..... 
bool check(int x, int trg, int k){
    int a = k;
    int sum = x;
    while(x / a > 0){
        sum += x / a;
        a *= k;
    }
    if(sum >= trg)
        return true;
    return false;
}
int FindMin(int trg, int k){
    int low = 1, high = trg;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(check(mid, trg, k))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main(){
    int trg, k; cin >> trg >> k;
    if(k == 1){
        cout << "The minimum x such that the sum of the series is at least " << trg << " is: " << trg << "\n";
        return 0;
    }
    int res = FindMin(trg, k);
    cout << "The minimum x such that the sum of the series is at least " << trg << " is: " << res << "\n";
}
using namespace std;
void lastDig(){
    int n; cin >> n;
    int tmp = n, mult = 1, sum = 0;
    while(tmp > 0){
        mult *= tmp % 10;
        sum += tmp % 10;
        tmp /= 10;
    }
    cout << "Multiplication of Digits is: " << mult;
    int cnt = 0; tmp = n;
    while(tmp > 0){
        if(tmp % 10 == 0)
            cnt++;
        tmp /= 10;
    }
    cout << "\nCount of Zero is: " << cnt;
    int rev = 0; tmp = n;
    while(tmp > 0){
        rev += tmp % 10;
        rev *= 10;
        tmp /= 10;
    }
    rev /= 10;
    cout << "\nAfter Reverse the seq is: " << rev;
}
using namespace std;
void statement(){
    int n;
    while(cin >> n){
        int res = n;
        if(n == 1) cout << 1;
        else if(n == 2) cout << 4;
        else{
            int tmp = n;
            while(tmp > 0){
                if(tmp == 2){
                    res *= 2; break;
                }
                else
                    res = (res + 1) * 2 + 1;
                tmp--;
            }
        }
        cout << res;
    }
}
//read integers n and m. compute the average of every m consecutive numbers in the sequence of the first n even numbers, and print these averages.
using namespace std;
void cntGrpAvg(){
    int n, m;
    vector <int> res;
    while(cin >> n >> m){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i * 2;
            if(i % m == 0){
                res.push_back(sum / m);
                sum = 0;
            }
        }
        if(n % m != 0)
            res.push_back(sum / (n % m));
        if(!res.empty()){
            cout << res[0] << " ";
            for(int i = 0; i < res.size(); i++)
                cout << res[i] << " ";
        }
    }
}
using namespace std;
//construct a binary tree from user input
vector <int> vec(100, 0);
int create(int i){
    int x; cin >> x;
    if(x == 0)
        return 0;
    vec[i] = x;
    create(2 * i);
    create(2 * i + 1);
    return x;
}
void func(int i){
    if(i >= vec.size() || vec[i] == 0)
        return;
    func(i * 2);
    cout << vec[i] << " ";
    func(i * 2 + 1);
}
int main(){
    create(1); func(1);
    string str(1, char(127));
    cout << str;
}
using namespace std;
int letterCnt(int n){
    string unit[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hundred = "hundred";
    int cnt = 0;
    if(n >= 100){
        cnt += unit[n / 100].length() + hundred.length();
        if(n % 100 != 0)
            cnt += 3; //for 'and'
        n %= 100;
    }
    if(n >= 20){
        cnt += tens[n / 10].length();
        n %= 10;
    }
    if(n >= 10)
        cnt += teens[n - 10].length();
    else
        cnt += unit[n].length();
    return cnt;
}
int main(){
    int digit = 11; //one thousand;
    for(int i = 1; i <= 999; i++)
        digit += letterCnt(i);
    cout << "Total letter: " << digit;
    cout << letterCnt(911);
}
using namespace std;
int power(int numer, int denom, int mod){
    if(denom == 0)
        return 1;
    if(denom % 2 == 0){
        int half = power(numer, denom / 2, mod);
        return (half * half) % mod;
    }
    else
        return (numer * power(numer, denom - 1, mod)) % mod;
}
int main(){
    int numer, denom, mod; cin >> numer >> denom >> mod;
    cout << power(numer, denom, mod);
}
using namespace std;
//Access elements from spiral
void spiral(){
    int row, col, res; cin >> row >> col;
    if(row > col){
        if(row % 2 == 0)
            res = (row * row) - col + 1;
        else
            res = (row - 1) * (row - 1) + col;
    }
    else{
        if(col % 2 == 0)
            res = (col - 1) * (col - 1) + row;
        else
            res = (col * col) - row + 1;
    }
    cout << res;
}
using namespace std;
//identify if a number power of two or not
void poweredOfTwo(){
    int n; cin >> n;
    // [n & (n - 1)] rep binary bitset.a power of 2 rep only one bitset.(100 & 011 = 000)
    //(n > 0 && (n & (n - 1)) == 0)? cout << "Yes" : cout << "No";
    for(int i = 0; i <= n; i++){
        if(pow(2, i) == n){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
//check is number contain all unique int
using namespace std;
void IsUnique(){
    int n; cin >> n;
    int digit[4];
    if(n < 1000 && n > 9999){
        cout << "Invalid";
        return 0;
    }
    //(1234 / 10^i) % 10 return the last digits.
    for(int i = 0; i < 4; i++)
        digit[i] = (n / static_cast < int >(pow(10, i))) % 10;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(digit[i] == digit[j]){
                cout << "Not Unique";
                return 0;
            }
        }
    }
    cout << "unique";
}
using namespace std;
void makePalindrome(){
    int len; cin >> len;
    char arr[len + 1];
    int l = 0, r = len - 1, cnt = 0;
    while(l < r){
        if(arr[l] !=  arr[r]){
            cnt++;
            if(arr[l] < arr[r])
                arr[r] = arr[l];
            else
                arr[l] = arr[r];
        }
        l++; r--;
    }
    cout << change;
}
using namespace std;
void IsPalindrome(){
    int n; cin >> n;
    if(n < 0)
        return 0;
    if(n == 0 || n == 1){
        cout << "palindrome";
        return 0;
    }
    int arr[n], cnt = 0;
    while(n != 0){
        arr[cnt++] = n % 10;
        n /= 10;
    }
    int i = 0, j = cnt - 1;
    while(i < j){
        if(arr[i] != arr[j]){
            cout << "Not palindrome";
            return 0;
        }
        i++; j--;
    }
    cout << "palindrome;"
}
using namespace std;
bool Ispalindrome(int *arr, int idx, int n){
    if(idx >= n / 2)
        return true;
    return (arr[idx] == arr[n - 1 - idx]) && Ispalindrome(arr, idx + 1, n);
}
int main(){
    int arr[] = {1, 2, 3, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    (Ispalindrome(arr, 0, n) ? cout << "Yes" : cout << "No");
}
using namespace std;
//checks if n can be decomposed into a sum of two even integers.If n is even and greater than 2,  prints "YES", else prints "NO".
void DivideEven(){
    int n; cin >> n;
    if(n % 2 == 0 && n != 2)
        cout << "Yes";
    if(n % 2 == 1 || n == 2)
        cout << "No";
}
using namespace std;
// reads pairs of hex numbers, computes their sum, and outputs the result in uppercase hex format
void convertToHex(){
    int a, b;
    // hex manipulator tells to interpret input values as hexadecimal numbers.
    while(cin >> hex >> a >> b){
        int sum = a + b;
        cout << hex << uppercase;
        if(sum < 0)
            cout << "-" << -sum;
        else
            cout << sum;
        //setiosflags(uppercase): Ensures that hexadecimal letters (A–F) are displayed in uppercase.
        /*if(a + b < 0)
            cout << setiosflags(uppercase) << hex << "-" << -(a + b);
        else
            cout << setiosflags(uppercase) << a + b;
        cout << "\n";*/
    }
}
using namespace std;
void pairSum(){
    int a, b; cin >> a >> b;
    //((a + b) % 3 == 0 || a <= 2 * b || b <= 2 * a)? cout << "Yes" : cout << "No";
    while(true){
        if(a == 0 && b == 0)
            break;
        else if((a + b) % 3 != 0)
            break;
        if((a % 3 == 0) && (b % 3 == 0)){
            a = 0; b = 0;
            break;
        }
        else{
            if(a > b)
                a -= 2; b -= 1;
            else
                a -= 1; b -= 2;
        }
    }
    (a == 0 && b == 0)? cout << "Yes" : cout << "No";
}
using namespace std;
void statement(){
    int n; cin >> n;
    (n == 2)? cout << 2 : cout << 2 * n - 4;
}
using namespace std;
void statement(){
    int x, y; cin >> x >> y;
    if((2 * x - y) >= 0 && (2 * x - y) % 3 == 0 && (2 * y - x) >= 0 && (2 * y - x) % 3 == 0)
        cout << "Yes";
    else
        cout << "No";
}

using namespace std;
//determine how many iterations will take for the value of 'a' to become greater than or
//equal to the value of 'b' when a is tripled and b is doubled in each iteration.
void countIteration(){
    int a, b; cin >> a >> b;
    int cnt = 0;
    while(a < b){
        a *= 3; b *= 2;
        cnt++;
    }
    cout << cnt;
}
using namespace std;
//Find Minimum & diffrence between sum of these number & twice of minimum
void MinDiff(){
    int a, b, c; cin >> a >> b;
    if(a <= b) c = a;
    else c = b;
    cout << "Min val is: " << c << " Expression is: " << (a + b - 2 * c);
}
using namespace std;
//After some specific operation in k times whats the value of n 
void wrongSubtract(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++){
        if(n % 10 == 0)
            n /= 10;
        if(n % 10 != 0)
            n--;
    }
    cout << n;
}
using namespace std;
void sumInt(){
    int a, b, res = 0; char ch;
    while(cin >> ch && ch != 'e'){
        cin >> a >> b;
        res += a + b;
    }
    cout << res;
}
using namespace std;
void seive(){
    const int maxi = 1e7;
    bool prime[maxi];
    prime[0] = prime[1] = false;
    for(int i = 2; i <= maxn; i++)
        prime[i] = true;
    for(int i = 2; i <= maxn; i++){
        if(prime[i]){
            for(int j = i * i; j <= maxn; j += i)
                prime[j] = false;
        }
    }
    for(int i = 2; i <= maxn; i++){
        if(prime[i]){
            cout << i << " ";
        }
    }
}
using namespace std;
//determine if the count of 'lucky' digits (4 and 7) in a given number n is exactly 4 or exactly 7. 
void Lucky(){
    int n, cnt = 0; cin >> n;
    while(n != 0){
        int dig = n % 10;
        n /= 10;
        if(dig == 4 || dig == 7)
            cnt++;
    }
    (cnt == 4 || cnt == 7) ? cout << "Yes" : cout << "No";
}
using namespace std;
//Geo series
int modPower(int a, int b, int mod){
    if(b == 0)
        return 1;
    int tmp = modPower(a, b / 2, mod);
    tmp = (tmp * tmp) % mod;
    if(b % 2 == 0)
        return tmp;
    else
        return (tmp * a) % mod;
}
int Geoseries(int a, int b, int mod){
    //a^0 + a^1 + a^2 + a^3+.... 
    if(b == 1) return 1;
    if(b == 2) return (1 + a) % mod;
    //calculate geo of the first half
    int tmp = Geoseries(a, b / 2, mod) % mod;
    int x = modPower(a, b/2, mod) % mod;
    int y = modPower(a, b - 1, mod) % mod;
    if(b % 2 == 0)
        return (tmp *(1 + x)) % mod;
    else
        return ((tmp *(1 + x)) % mod + y % mod) % mod;
}
int main(){
    int a, b, mod; cin >> a >> b >> mod;
    cout << "\nMod power is: " << modPower(a, b, mod);
    cout << "\nGeometricSeries are: " << Geoseries(a, b, mod);
}
using namespace std;
void Bitwise(){
    const int mod = 1e9;
    int n; cin >> n;
    if(n < 31)
        cout << (1 << n) % mod << " ";
    else
        cout << "OutOf Bound";
    int x = 1;
    for(int i = 0; i < n; i++)
        x = 2 * x % mod;
    cout << x << " ";
}
using namespace std;
bool Isprime(int n){
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
using namespace std;
void Ispalindrome(int n){
    int rev = 0, tmp = n;
    while(n > 0){
        rev += rev * 10 + n % 10;
        n /= 10;
    }
    (tmp == rev) ? cout << "palindrome" : cout << "Not palindrome";
}
using namespace std;
int fib(int n){
    if(n == 1 || n == 2)
        return 1
    return fib(n - 1) + fib(n - 2);
}
using namespace std;
//check of all digits of giver integer odd
bool oddDigit(int n){
    while(n > 0){
        if((n % 10) % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}
using namespace std;
//Is Last number even or odd
bool lastDigit(int n){
    while(n > 0){
        if(n % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}
using namespace std;
int fact(int n){
    if(n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}
