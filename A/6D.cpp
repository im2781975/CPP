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
using namespace std;
void recursive(int a, int b){
    if(a <= b){
        cout << a << " ";
        if(a < b){
            cout << " ";
            recursive(a + 1, b);
        }
    }
}
using namespace std;
int GCD(int a, int b){
    while(a > 0 && b > 0){
        if(a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}
using namespace std;
void ExtendGCD(int a, int b, vector<int> vec){
    if(b == 0){
        vec[0] = 1; //x
        vec[1] = 0; //y
        vec[2] = a; //gcd(a, b)
        return;
    }
    ExtendGCD(b, a % b, vec);
    int tmp = vec[1];
    vec[1] = vec[0] - vec[1] *(a / b);
    vec[0] = tmp;
}
int main(){
    int a, b; cin >> a >> b;
    vector <int> vec(3);
    ExtendGCD(a, b, vec);
    cout << "Coefficients x and y such that ax + by = gcd(a, b):" << "\n";
    cout << "x: " << vec[0] << ", y: " << vec[1] << "\n";
    cout << "gcd(a, b): " << vec[2] << "\n";
}
using namespace std;
//prints the number of ways to place two knights on i x i chessboard such that they do not attack each other.
//A knight can attack total 8 position in L shape.(i - 1) or (i - 2).(x + 2, y + 1), (x + 2, y - 1), (x - 2, y + 1), (x - 2, y - 1)
//(i−1)×(i−2) horizontally & (i - 2)*(i - 1) vertically.total ways 4*(i - 1)*(i - 2)
void knightAttack(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int sqr = i * i;
        int totalway = sqr * (sqr - 1) / 2;
        int invalidWay = 0;
        if(i > 2)
            invalidway = 4 * (i - 1) * (i - 2);
        int validway = totalway - invalidway;
        cout << validway << " ";
    }
}
using namespace std;
// define four conditions define specific regions in a 2D coordinate plane
//a ->upper ragion / b->left ragion
//c->lower ragion / d -> right ragion
void statement(){
    int x, y; cin >> x >> y;
    int res = 0;
    if(x < y && x >= -y){
        res += -2 *y + 4;
        cout << "a";
    }
    else if(x > y && x <= -y + 1){
        cout << "b";
        res += -y * 4;
    }
    else if(x >= y && x > -y + 1){
        cout << "c";
        res += -3 + x*4;
    }
    else if(x <= y && x > -y){
        cout << "d";
        res += -1 - 4*x;
    }
    cout << res;
}
using namespace std;
//count how many elements in a given list are greater than or equal to a specific threshold value.
int cntGreater(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end(), greater <int> ());
    int hold = max(1, vec[n - 1]);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] >= hold)
            cnt++;
    }
    cout << cnt;

using namespace std;
vector <bool> DetectPrime(int n){
    vector <bool> num(n, true);
    num[0] = num[1] = false;
    for(int i = 2; i < n; i++){
        if(num[i]){
            for(int j = i * i; j <= n; j += i)
                num[j] = false;
        }
    }
    return num;
}
vector <int> getDigit(int n){
    vector <int> Digits;
    while(n > 0){
        Digits.push_back(n % 10);
        n /= 10;
    }
    return Digits;
}
int main(){
    int n; cin >> n;
    vector <bool> prime = DetectPrime(n);
    vector <int> get = getDigit(n);
    for(int i = 2; i <= n; i++){
        if(prime[i])
            cout << i << " ";
    }
    for(int i = 0; i < get.size(); i++)
        cout << get[i] << " ";
}
using namespace std;
// determine whether a given target number n can be reached starting from 1
bool canReached(int cur, int trg){
    if(cur == trg) return true;
    if(cur > trg) return false;
    return canReached(cur *10, trg) || canReached(cur * 20, trg);
}
int main(){
    int n; cin >> n;
    (canReached(1, n)? cout << "Yes" : cout << "No");
}
using namespace std;
// check whether a given integer num will eventually converge to 1 when repeatedly replaced by 
//the sum of the squares of its digits. If not, it checks if the sequence enters a cycle
int squaresum(int num){
    int sum = 0;
    while(num > 0){
        int dig = num % 10;
        sum += dig * dig;
        num /= 10;
    }
    return sum;
}
void convergence(int num, int maxiter){
    int cur = num, org = num, iter = 0;
    do{
        cur = squaresum(num);
        if(cur == 1) return 1;
        if(cur == org) return 0;
        iter++;
    }while(iter < maxiter);
    return 0;
}
int main(){
    int num; cin >> num;
    res = convergence(num, 100);
    (res == 1)? cout << num << "Covergence to 1" : cout << "Not convergence or entered into cycle";
}
using namespace std;
void statement(){
    int a, b, res; cin >> a >> b;
    (a == 0) ? res = 1 : res = a + 2 * b + 1;
    cout << res;
}
using namespace std;
void statement(){
    int n; cin >> n;
    int x = n % 10 - 1;
    int res += 10 * x;
    int k = n % 10;
    int cnt = 0, ptr = 1;
    while(cnt <= n){
        cnt = cnt % 10 + k;
        res += ptr;
        ptr++;
    }
    cout << res;
}
using namespace std;
void statement(){
    int x, y; cin >> x >> y;
    if(x == 1 && y == 1)
        cout << 0;
    else if((x == 1 && y == 2) || (x == 2 && y == 1))
        cout << 1;
    else if(x == 1 || y == 1)
        cout << 2;
    else{
        int maxi = max(x, y);
        if((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
            cout << (maxi - 1) * 2;
        else 
            cout << (maxi - 1) * 2 -1;
    }
}
using namespace std;
void Hanoi(int n, char a, char b, char c){
    if(n > 0){
        Hanoi(n - 1, a, c, b);
        cout << "Move from " << a << " to " << b << " use " << c << "\n";
        Hanoi(n - 1, c, b, a)
    }
}
int main(){
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    Hanoi(n, a, b, c);
}
using namespace std;
void calAvg(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        sum += arr[i];
    cout << sum / n;
}
using namespace std;
//determine whether an array of integers contains any 1s. If it does, output "Hard"; otherwise, "Easy".
void hardEasy(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] == 1) cnt++;
    }
    (cnt == 0)? cout << "Easy" : cout << "Hard";
}
using namespace std;
// count how many times the cumulative sum of the array elements becomes negative.
//while also keeping the cumulative sum within the range of -1 to 1 during the process.
void cntNegSum(){
    int n; cin >> n;
    int arr[n], cnt = sum = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            cnt++; 
            sum = 0;
        }
        /*if(sum < -1)
            sum = -1;
        else if(sum > 1)
            sum = 1;*/
    }
    cout << cnt;
}
using namespace std;
//Find the mid between n & m
void FindMid(){
    int n, m; cin >> n >> m;
    int cnt = (n + 1) / 2;
    int res = ((cnt + m - 1) / m) * m;
    (res > n)? cout << -1 : cout << res;
}
using namespace std;
// maximize the value of a number when it is negative by simulating the removal of one digit
void maximize(){
    int n; cin >> n;
    if(n >= 0)
        cout << n;
    else{
        int a = -n /10 %10;
        int b = n % 10;
        cout << (a > b) ? n /10 - b : n / 10;
    }
}
using namespace std;
// outputs the coordinates of the other two points required to complete a square. 
void CompleteSquare(){
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    if(abs(x1 - x2) == abs(y1 - y2))
        cout << x1 << " " << x2 << " " << y1 << " " << y2;
    //if these points are horizontal
    else if(x1 == x2){
        int length = abs(y2 - y1);
        cout << x1 + length << " " << y1 << " " << x2 + length << " " << y2;
    }
    //if these points are vertically
    else if(y1 == y2){
        int length = abs(x2 - x1);
        cout << x1 << " " << y1 + length << " " << x2 << " " << y2 + length;
    }
    else 
        cout << -1;
}
using namespace std;
//count How Much 5 will be exits
void cntFive(){
    int n; cin >> n;
    int cnt = 0, tmp = 0;
    while(n--){
        int x; cin >> x;
        (x == 5) ? cnt++ : tmp++;
    }
    if(tmp == 0){
        cout << -1; return;
    }
    if(cnt < 9){
        cout << 0; return;
    }
    int five = (cnt / 9) * 9;
    for(int i = 0; i < five; i++)
        cout << 5 << " ";
    for(int i = 0; i < tmp; i++)
        cout << 0 << " ";
}
using namespace std;
//calculate the sum of 5 integers , and determine if the sum can be evenly divided by 5
void DivisibleFive(){
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    a += b + c + d + e;
    (a % 5 == 0 && a / 5 != 0) ? cout << "Yes" : cout << "No";
}
//count how many of the n integers are greater than the threshold value 
using namespace std;
void cntGreater(){
    int n, trg; cin >> n >> trg;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        if(num > trg) cnt++;
    }
    cout << cnt + n;
}
using namespace std;
// divide a resource c into chunks of size equal to the LCM of two other quantities a & b
void divide(){
    int a, b, c; cin >> a >> b >> c;
    int x = (a * b) / __gcd(a, b);
    cout << c / x;
}
using namespace std;
//calculate the minimum number of steps required to adjust a given range defined by start and end to a target range
void calculateStep(){
    int l, r, start, end; cin >> l >> r >> start >> end;
    int cnt = 0;
    if(start != l)cnt++;
    if(end != r) cnt++;
    if(start != l && end != r){
        cnt += abs(start - end);
        cnt += min(abs(l - start), abs(r - end));
    }
    else if(start == l && end != r)
        cnt += abs(end - r);
    else if(start != l && end == r)
        cnt += abs(start - l);
    cout << cnt;
}
using namespace std;
//find the highest possible value of maxi
void statement(){
    int a, b, maxi = -1;
    int n, trg; cin >> n >> trg;
    while(n--){
        cin >> a >> b;
        if(a < trg){
            if(b != 0)
                maxi = max(maxi, 100 - b);
            else
                maxi = max(maxi, 0);
        }
        else if(a == trg){
            if(b == 0)
                maxi = max(maxi, 0);
        }
    }
    cout << maxi;
}
using namespace std;
// compare two numbers and output which one is larger, 
void compBetween(){
    int a, b; cin >> a >> b;
    if(a > b) cout << "A";
    else if cout << "B";
    else cout << "Equal";
}
using namespace std;
// determine whether it is possible to perform a series of jumps between two integers
//a and b, using a fixed step size c, such that the total number of jumps is even.
void cntJump(){
    int start, end, step; cin >> start >> end >> step;
    int dist = abs(start - end);
    if(dist % step != 0){
        cout << "No";
        return 0;
    }
    dist /= step;
    (dist % 2 == 0) ? cout << "Yes" : cout << "No";
}
using namespace std;
//determines the final position in a circular range after performing a given number of adjustments. 
void circularRange(){
    int maxi, adjust, cur; cin >> maxi >> adjust >> cur;
    cur = (cur + adjust) % maxi;
    if(cur <= 0)
        cur += maxi;
    cout << cur;
}
using namespace std;
//How much steps we need for being two variable same
void cntOperation(){
    int x, y; cin >> x >> y;
    if(x == y)
        cout << 0;
    else if(x > y)
        cout << x - y;
    else{
        int operation = 0;
        while(y > x){
            (y % 2 == 0) ? y /= 2 : y++; 
            operation++;
        }
        operation += x - y;
        cout << operation;
    }
}
using namespace std;
// divide an integer into the smallest possible number of parts, where each part is either 2 or 3
void divideInto(){
    int n; cin >> n;
    if(n % 2 == 0){
        cout << n / 2 << "\n";
        for(int i = 0; i < n / 2; i++)
            cout << 2 << " ";
    }
    else{
        cout << (n - 3) / 2 + 1 << "\n";
        cout << 3 << " ";
        for(int i = 0; i < (n - 3) / 2 ; i++)
            cout << 2 << " ";
    }
}
using namespace std;
// determines whether a given number of units can be distributed evenly across a specified number of groups
void EvenDistribute(){
    int x, y; cin >> x >> y;
    if(y == 1){
        cout << (x == 0 ? cout << "Yes" : cout << "No");
        return;
    }
    y -= 1;
    x -= y;
    (x >= 0 && y >= 0 && x % 2 == 0) ? cout << "Even" : cout << "Odd";
}
using namespace std;
// Calculate total values for two participants & determine which one is win
void compare(){
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    int first = b * a + 2 *d;
    int sec = c * a + 2 * e;
    if(first > sec) cout << "first";
    else if(sec > first) cout << "Second";
    else cout << "Friendship"
}
using namespace std;
//compute and print the minimum value from a set of given expressions 
void findMin(){
    int a, b, c; cin >> a >> b >> c;
    cout << min({a + b + c, 2 *(a + b), 2 * (b + c), 2 *(c + a)});
}
using namespace std;
vector <int> suffixSum(vector <int> &vec){
    vector <int> suffix(vec.size());
    suffix[vec.size() - 1] = vec[vec.size() - 1];
    for(int i = vec.size() - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + vec[i];
    return suffix;
}
vector <int> prefixSum(vector <int> &vec){
    vector <int> prefix;
    prefix[0] = vec[0];
    for(int i = 1; i < vec.size(); i++)
        prefix[i] = prefix[i - 1] + vec[i];
    return prefix;
}
vector <int> minPos(vector <int> &vec){
    int maxi= 0, mini = 0;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] > vec[maxi])
            maxi = i;
    }
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] < vec[mini])
            mini = i;
    }
    return maxi, mini;
}
int main(){
    vector <int> vec{2, 3, 1, 5, 4};
    vector <int> suffix = suffixSum(vec);
    vector <int> prefix = prefixSum(vec);
    for(int i = 0; i < suffix.size(); i++)
        cout << suffix[i] << " "; 
}

using namespace std;
int GCD(int a, int b){
    if(b > a) swap(b, a);
    if(a == b) return a;
    for(int i = b; i > 0; i--){
        if(a % i == 0 && b % i == 0)
            return i;
    }
}
int GCD(int a, int b){
    if(a == 0 || b == 0) return a + b;
    if(a > b) return GCD(a % b, b);
    else
        return GCD(a, b % a);
}
int LCM(int a, int b){
    for(int i = max(a, b); i <= a * b; i++){
        if(i % a == 0 && i % b == 0)
            return i;
    }
    return -1;
}
int main(){
    int n, x; cin >> n >> x;
    cout << GCD(n, x);
}
using namespace std;
// Print three consecutive even numbers starting from l. if they fit within the range [l, r].
void printBetween(){
    int l, r; cin >> l >> r;
    if(l % 2 != 0) l += 1;
    if(r - l >= 4)
        cout << l << " " << l + 2 << " " << l + 4;
    else
        cout << -1;
}
using namespace std;
//calculate the maximum number of drinks (servings) that can be made for a group of friends based on the availability of ingredients:
void partyArrange(){
    int amico, bottle, mlBottle, lime, sliceLime, salt, mlServing, saltServing;
    cin >> amico >> bottle >> mlBottle >> lime >> sliceLime >> salt >> mlServing >> saltServing;
   int totalMl = (bottle * mlBottle) / mlServing / amico;
    int totalLime = (lime * sliceLime) / amico;
    int totalsalt = salt / saltServing / amico;
    res = min({totalMl, totalLime, totalsalt});
    cout << res;
}
using namespace std;
//check if there is at least one item where the price does not match the quality.
void checkQuality(){
    int n; cin >> n; 
    for(int i = 0; i < n; i++){
        int price, quality; cin >> price >> quality;
        if(price != quality)
            cout << "Happy";
            return 0;
    }
    cout << "Poor";
}
using namespace std;
//calculates the maximum "happiness" value achievable from a list of items, 
//considering a penalty for exceeding a given time limit.
void cntmaxHappiness(){
    int n, k; cin >> n >> k;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        int curr;
        if(y <= k)
            curr = x;
        else
            curr = x - (y - k);
        maxi = max(maxi, curr);
    }
}
using namespace std;
//determine how many times each die wins, and how many times there is a draw, 
// when compared to a series of possible dice outcomes (from 1 to 6).
void compDice(){
    int dice1, dice2; cin >> dice1 >> dice2;
    int win1, win2, draw = 0;
    for(int i = 1; i <= 6; i++){
        if(abs(dice1 - i) > abs(dice2 - i))
            win1++;
        else if(abs(dic1 - i) < abs(dice2 - i))
            win2++;
        else
            draw++;
    }
}
using namespace std;
void snakePattern(){
    int row, col; cin >> row >> col;
    for(int i = 0; i < row; i++){
        if(i % 2 == 0){
            for(int j = 0; j < col; j++)
                cout << "#";
        }
        else{
            if((i / 2) % 2 == 0){
                for(int j = 0; j < col - 1; j++)
                    cout << ".";
                cout << "#";
            }
            else{
                cout << "#";
                for(int j = 1; j < col; j++)
                    cout << ".";
            }
        }
        cout << "\n";
    }
}
using namespace std;
//find first even or odd unique element
void findUnique(){
    int n; cin >> n;
    int pos1 = -1 pos2 = -1, even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 2 == 0){
            even++;
            pos1 = i + 1;
        }
        else{
            odd++;
            pos2 = i + 1;
        }
    }
    (odd == 1) ? cout << pos2 : cout << pos1;
}
#include<bits/stdc++.h>
using namespace std;
void transform(){
    int n; cin >> n;
    int res[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int mid = (x + 1) / 2;
        res[i] = mid - 1;
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
using namespace std;
//counting how many times an element in the guest array matches an element in the host array
void cntMatch(){
    int n; cin >> n;
    int host[n], guest[n];
    for(int i = 0; i < n; i++)
        cin >> host[i];
    for(int i = 0; i < n; i++)
        cin >> guest[i];
    for(int i = 0; i < n; i++){
        int tmp = guest[i];
        for(int j = 0; j < n; j++)
            if(host[i] == tmp)
                cnt++;
    }
    cout << cnt;
}
using namespace std;
bool isSorted(int *arr, int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
bool contain0(int *arr, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == 0)
            return true;
    }
    return false;
}
bool containDup(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j])
                return true;
        }
    }
    return false;
}
#include<bits/stdc++.h>
using namespace std;
void MinIdx(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int idx = 0, mini = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < mini){
            mini = arr[i];
            idx = i;
        }
    }
    if(idx != 0)
        swap(arr[0], arr[idx]);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
using namespace std;
//Find the largest abs value 1-th based idx
void findLargest(){
    int row, col; cin >> row >> col;
    int arr[row][col], x, y;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
    int res = arr[0][0];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(abs(arr[i][j]) > abs(res)){
                res = arr[i][j];
                x = i + 1; y = j + 1;
            }
        }
    }
    cout << x << " " << y;
}
using namespace std;
void appendVal(){
    int n, x; cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = x;
    sort(arr, arr + n + 1);
    for(int i = 0; i <= n; i++)
        cout << arr[i] << " ";
}
using namespace std;
// determine how many participants in a competition will advance to the next round based on their scores.
void nextRound(){
    int n, k; cin >> n >> k;
    int arr[n], cnt = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int tmp = arr[k - 1];
    for(int i = 0; i < n; i++){
        if(arr[i] >= tmp && arr[i] > 0)
            cnt++;
    }
    cout << cnt;
}
#include<bits/stdc++.h>
using namespace std;
//prrint integers that are div by 10 & cnt digits from int that arn't divisible by 10
void divisibleByTen(){
    int n; cin >> n;
    vector <int> vec(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 10 == 0)
            vec.push_back(x);
        else{
            int tmp = x;
            while(tmp != 0){
                r++;
                tmp /= 10;
            }
        }
    }
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "digits that aren't divisible by 10: " << r;
}
using namespace std
//calculates the minimum cost of traveling a given number of units, 
//given the cost of single tickets and special tickets. The special tickets cover 
//multiple units at a potentially reduced cost
//dist(total distance), Gdist(special ticket can covered dist), Ticprice(normal ticket price), (GTicketPrice)
void TravellingCost(){
    int dist, Gdist, Ticprice, GTicprice;
    cin >> dist >> Gdist >> Ticprice >> GTicprice;
    int price = 0;
    if(TicPrice * Gdist <= GTicprice){
        price += dist * Ticprice;
        return 0;
    }
    int needGTic = dist / Gdist;
    int remainDist = dist % Gdist;
    int x = (needGTic + 1) * GTicprice;
    int y = needTic * GTicprice + remainDist * Ticprice;
    price = min(x, y);
    cout << price;
}
#include<bits/stdc++.h>
using namespace std;
//compute specific values related to the movement or relationship between two points on a 2D grid
void GridMove(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int IsDiffrent = (a != c && b != d) ? 2 : 1;
    int SameParity = ((a + b) % 2 == (c + d) % 2) ? 1 : 0;
    int DiffrentDirection = (a - b == c - d || a + b == c + d) ? 1 : 0;
    int res = IsDiffrent * (2 - DiffrentDirection);
    int maxDist = max(abs(c - a), abs(d - b));
    cout << res << " " << SameParity * res << " " << maxDist ;
}
using namespace std;
// print sum between range
int sumRange(int l, int r){
    if(r < l) 
        return 0;
    if(l > 1)
        return sumRange(1, r) - sumRange(1, l - 1);
    if(r % 2 == 1)
        return sumRange(1, r - 1) + r;
    else
       return r * (r + 1) / 2;
}
