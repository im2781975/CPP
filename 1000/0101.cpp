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
