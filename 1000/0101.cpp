//computes and prints the number of ways to place two knights on an i x i chessboard 
//such that they do not attack each other.A knight can attack total 8 position in L shape.
//(i - 1) or (i - 2). (i−1)×(i−2) horizontally & (i - 2)*(i - 1) vertically.total ways 4*(i - 1)*(i - 2)
void knightAttack(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        //knight move
        int k = i * i;
        //knight can attach
        int a = k *(k - 1)/2;
        if(k > 2)
            a = a - 4*(i - 1)(i - 2);
        cout << a << " ";
    }
}

void ExtendGCD(int a, int b, vector<int> vec){
    if(b == 0){
        vec[0] = 1;
        vec[1] = 0;
        vec[2] = a; //gcd;
        return;
    }
    ExtendGCD(b, a % b, vec);
    int tmp = vec[1];
    vec[1] = vec[0] - vec[1] *(a / b);
    vec[0] = tmp;
}
main(){
    int a, b; cin >> a >> b;
    vector <int> vec(3);
    ExtendGCD(a, b, vec);
    cout << "Coefficients x and y such that ax + by = gcd(a, b):" << "\n";
    cout << "x: " << v[0] << ", y: " << v[1] << "\n";
    cout << "gcd(a, b): " << v[2] << "\n";
}
int mini(int a, int b, int c){
    int minimum= a < c ? a < b ? a : c : b < c ? b : c;
    return minimum;
}
int GCD(int a, int b){
    while(a > 0 && b > 0){
        if(a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}
int Fact(int n){
    if(n == 0 || n == 1)
        return 1;
    return n * Fact(n - 1);
}
//Is last number even or odd
bool LastNum(int n){
    while(n > 0){
        if(n % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}
//checks whether all the digits of a given integer are odd. 
bool OddDigit(int n){
    while(n > 0){
        if((n % 10) % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}
int Fib(int n){
    if(n == 1 || n == 2)
        return 1;
    return Fib(n - 1) + Fib(n - 2);
}
void Rec(int a, int b){
    if(a <= b){
        cout << a << " ";
        if(a < b){
            cout << " ";
            Rec(a + 1, b);
        }
    }
}
void Palindrome(int n){
    int rev = 0;
    int tmp = n;
    while(n > 0){
        rev += rev * 10 + n % 10;
        n /= 10;
    }
    (tmp == rev) ? cout << "Palindrome" : cout << "Not Palindrome";
}
void IsPrime(int n){
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}


//compute GeoSeries
int ModPow(int a, int b, int mod){
    if(b == 0)
        return 1;
    int tmp = ModPow(a, b/2, mod) % mod;
    tmp = (tmp * tmp) % mod;
    if(b % 2 == 0)
        return tmp;
    else
        return (tmp * a) % mod;
}
int Divisors(int n){
    int cnt = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            cnt++;
    }
    return cnt;
}
int GeoSeries(int a, int b, int mod){
    if(b == 1)
        return 1;
    if(b == 2)
        return (1 + a) % mod;
    int tmp = GeoSeries(a, b/2, mod) % mod;
    int x = ModPow(a, b/2, mod) % mod;
    int y = ModPow(a, b - 1, mod) % mod;
    if(b % 2 == 0)
        return (tmp *(1 + x)) % mod;
    else
        return ((tmp *(1 + x)) % mod + y % mod) % mod;
}
main(){
    int a, b, mod;
    cin >> a >> b >> mod;
    //Modular Exponent
    cout << "ModPower is: " << ModPow(a, b, mod);
    int n; cin >> n;
    //Divisor
    cout << "\nNumber of divisors: " << Divisors(n);
    //geometric series
    cout << "\nGeometric series is: " << GeoSeries(a, b, mod);
}

//Count Letter
int LetterCount(int n){
    if(n < 0 || n > 999)
        return 0;
    string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hundred = "hundred";
    int cnt = 0;
    if(n >= 100){
        cnt += units[n / 100].length() + hundred.length();
        if(n % 100 !=0)
            cnt += 3;
        n %= 100;
    }
    if(n >= 20){
        cnt += tens[n / 10].length();
        n %= 10;
    }
    if(n >= 10)
        cnt += teens[n - 10].length();
    else
        cnt += units[n].length();
    return cnt;
}
main(){
    int d = 11;
    cout << "Letter count is: " << LetterCount(911) << "\n";
    for(int i = 1; i <= 999; i++){
        d += LetterCount(i);
    }
    cout << "Total Letter: " << d;
}

//construct a binary tree from user input
vector<int>vec(100, 0);
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
    if(i >= vec.size() || vec[i] == 0 )
        return;
    func(i * 2);
    cout << vec[i] << " ";
    func(i * 2 + 1);
}
main(){
    create(1);
    func(1);
    string str(1, char(127));
    cout << str;
}
int power(int nume, int denom, int mod){
    nume = nume % mod;
    if(denom == 0)
        return 1;
    if(denom % 2 == 0){
        int half = power(nume, denom / 2, mod);
        return (half * half) % mod;
    }
    else
        return (nume * power(nume, denom - 1, mod)) % mod;
}
void CalculateBitwise(){
    const int M = 1e9;
    int n; cin >> n;
    if(n < 31)
        cout << (1 << n) % M << "\n";
    else
        cout << "value to large";
    int x = 1;
    for(int i = 0; i < n; i++)
        x = 2 * x % M;
    cout << x;
}
//Access elements from spiral
void Spiral(){
    int row, col, ans;
    cin >> row >> col;
    if(row > col){
        if(row % 2 == 0)
            ans = (row * row) - col +1;
        else 
            ans = (row - 1)*(row - 1) + col;
    }
    else {
        if(col % 2 == 0)
            ans = (col - 1)*(col - 1) + row;
        else
            ans = (col * col) - row + 1;
    }
    cout << ans;
}
void checkPalindrome(){
    int n; cin >> n;
    if(n < 0)
        return 0;
    if(n == 0 || n == 1){
        cout << "palindrome";
        return 0;
    }
    int arr[n];
    int cnt = 0;
    while(n != 0){
        arr[cnt] = n % 10;
        cnt++;
        n /= 10;
    }
    int i = 0, j = cnt -1;
    while(i < j){
        if(arr[i] !=arr[j]){
            cout << "Not Plaindrome";
            return 0;
        }
        i++; j--;
    }
    cout << "palindrome";
    return 0;
}

//check is number contain all unique int
void IsUnique(){
    int n; cin >> n;
    if(n < 1000 && n > 9999){
        cout << "Invalid";
        return 0;
    }
    int digit[4];
    for(int i = 0; i < 4; i++)
        digit[i] = (n/static_cast<int>(pow(10, i))) % 10;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(digit[i] == digit[j])
                cout << "Not unique";
        }
    }
    cout << "Unique";
}

//Identify if a number power of 2 or not
void IsPowered(){
    int n; cin >> n;
    /*for(int i = 0; i <= n; i++){
        if (pow(2, i) == n){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";*/
    if(n > 0 && (n & (n - 1)) == 0)
        cout << "Yes";
    else
        cout << "No";
}
void verify(){
    int n, x; cin >> n;
    (n == 2)? x = 2: x = 2*n - 4;
    cout << x;
}

//determine if the count of 'lucky' digits (4 and 7) in a given number n is exactly 4 or exactly 7. 
void Lucky(){
    int n; cin >> n;
    int cnt = 0;
    while(n !=0){
        int r = n % 10;
        n /= 10;
        if(r == 4 || r == 7)
            cnt++;
    }
    (cnt == 4 || cnt == 7)?cout << "Yes":cout << "No";
}

void WrongSubtraction(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++){
        if(n % 10 == 0)
            n /= 10;
        else if(n % 10 !=0)
            n--;
    }
    cout << n;
}
//Find Minimum & diffrence between sum of these number & twice of minimum
void FindDiff(){
    int a, b, c;
    cin >> a >> b;
    if(a <= b)
        c = a;
    else
        c = b;
    cout << "Minimun is: " << c << "\nexpression is: " << (a + b - 2 * c);
}
//determine how many iterations it will take for the value of a to become greater than or
//equal to the value of b when a is tripled and b is doubled in each iteration.
void CountIteration(){
    int a, b, cnt = 0;
    cin >> a >> b;
    while(a < b){
        a *= 3;
        b *= 2;
        cnt++;
    }
    cout << cnt;
}
void verifyCond(){
    int x, y;
    cin >> x >> y;
    if((2 *x - y) >= 0 && (2 *x - y) % 3 == 0 && (2 *y - x) >= 0 && (2 *y - x) % 3 == 0 )
        cout << "Yes";
    else
        cout << "No";
}

//determines if it is possible to reduce both a and b to zero by repeatedly performing 
//one of two operations: reducing a by 2 & b by 1, or reducing a by 1 & b by 2. 
// key observation here is that the sum of a & b must be divisible by 3, and
//neither a nor b can exceed twice the value of the other at any point.
void PairSame(){
    /*int a, b; cin >> a >> b;
    if((a + b) % 3 != 0){
        cout << "No";
        continue;
    }
    if(a > 2*b || b > 2*a){
        cout << "No";
        continue;
    }
    cout << "Yes";*/
    int a, b; cin >> a >> b;
    while(true){
        if(a == 0 || b == 0)
             break;
        else if((a + b) % 3 !=0)
            break;
        if((a % 3 == 0) && (b % 3 == 0)){
            a = 0; b = 0;
            break;
        }
        else {
            if(a > b){
                a -= 2; b -= 1;
            }
            else {
                a -= 1; b -= 2;
            }
        }
    }
    (a == 0 && b == 0)?cout << "Yes":cout << "NO";
}

bool IsPalindrome(int idx, int *arr, int n){
    if(idx >= n/2)
        return true;
    return (arr[idx] == arr[n - idx - 1]) && IsPalindrome(idx + 1, arr, n);
}
void Seive(){
    const int Maxn = 1e7;
    bool IsPrime
    for(int i = 2; i <= Maxn; i++)
        IsPrime[i] = true;
    for(int i < 2; i <= Maxn; i++){
        if(IsPrime[i]){
            for(int j = i*i; j < maxn; j+=i)
                IsPrime[j] = false;
        }
    }
    IsPrime[0] = IsPrime[1] = false;
}
main(){
    int arr[]{1, 2, 3, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    (IsPalindrome(0, arr, n)) ? cout << "Yes":cout << "No";
}

void SumOf(){
    int a, b, ans = 0;
    char ch; cin >> ch;
    while(cin >> a >> b && ch !='e')
        ans += a + b;
    cout << ans;
}

//read pairs of hexadecimal integers from the standard input, 
//sum them, and then output the result in uppercase hexadecimal format. 
void ConvertHex(){
    int a, b;
    while(cin >> hex >> a >> b){
        int sum = a + b;
        if(sum < 0)
            cout << hex << uppercase << "-" << -sum;
        else
            cout << hex << uppercase << sum;
        /*if(a + b < 0)
			cout << setiosflags(uppercase) << hex << "-" << -(a + b) << endl;
		else 
            cout << setiosflags(uppercase) << (a + b) << endl; */
    }
}
//read pairs of integers n and m. compute the average of every m consecutive numbers in the 
//sequence of the first n even numbers, and print these averages.
void countGroupAvg(){
    int n, m;
    vector <int> res;
    while(cin >> n >> m){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i * 2;
            if(i % m == 0){
                res.push_back(sum/m);
                sum = 0;
            }
        }
        if(n % m !=0)
            res.push_back(sum /(n % m));
        if(!res.empty()){
            cout << res[0];
            for(int i = 1; i < res.size(); i++)
                cout << " " << res[i];
        }
    }
}
//checks if an input integer n can be decomposed into a sum of two even integers.
//If n is even and greater than 2, it prints "YES"; otherwise, it prints "NO".
void DivideEven(){
    int n; cin >> n;
    if(n % 2 == 0 && n != 2)
        cout << "Yes";
    if(n % 2 == 1 || n == 2)
        cout << "No";
}

//calculate and print the minimum number of square tiles of size a x a needed to cover a rectangular area of size x * y
void MinTile(){
    int x, y, a;
    cin >> x >> y >> a;
    int r1 = x / a;
    int r2 = y / a;
    if(x % a !=0)
        r1++;
    if(y % a !=0)
        r2++;
    cout << r1 * r2;
}
void Condition() {
    int n;
    while (cin >> n) {
        int x = n;
        if (n == 1) {
            cout << 1 << endl;
        } else if (n == 2) {
            cout << 4 << endl;
        } else {
            while (n--) {
                if (n == 2) {
                    x *= 2;
                    break;
                } else
                    x = (x + 1) * 2 + 1;
            }
            cout << x << endl;
        }
    }
}

void Operation(){
    int n; cin >> n;
    int tmp = n;
    int mult = 1, sum = 0, cnt = 0;
    while(tmp > 0){
        cnt++;
        mult *= tmp % 10;
        sum += tmp % 10;
        tmp /= 10;
    }
    cout << "Multipication is: " << mult << "\nSum is: " << sum << "\nAmount Of Number is: " << cnt;
    //Count Zero
    tmp = n; cnt = 0;
    while(tmp > 0){
        if(tmp % 10 == 0)
             cnt++;
        tmp/= 10;
    }
    cout << "\nCount of Zero is: " << cnt;
    
    //Reverse
    tmp = n;
    int rev = 0;
    while(tmp > 0){
        rev += tmp % 10;
        rev *= 10;
        tmp /= 10;
    }
    rev /= 10;
    cout << "\nReverse is: " << rev;
}
