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
