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
