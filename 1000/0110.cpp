//calculates the minimum cost of traveling a given number of units, 
//given the cost of single tickets and special tickets. The special tickets cover 
//multiple units at a potentially reduced cost
void CountTravelCost(){
//n ->Total units of travel required. m -> Number of units covered by the special ticket.
//a is the Cost of a single ticket. and b is the Cost of the special ticket.
    int n, m, a, b;
    cout << n << m << a << b;
    int price = 0;
    // Cost of 'm' single tickets
    int CostSingleTicket = a * m;
    if(CostSingleTicket <= b)
        price = a * n;
    else {
        int SpecialTickets = n/m
        int RemainingUnit = n % m;

        int x = (SpecialTickets + 1) * b;
        int y = SpecialTickets * b + RemainingUnit * a;
        price = min(x, y);
    }
    cout << price;
}
//check if there is at least one item where the price does not match the quality. 
void checkQuality(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int price, quality;
        cin >> price >> quality;
        if(price != quality)
            cout << "Happy";
        return 0;
    }
    cout << "Poor";
    return 0;
}
//Compressed Letter
struct CompressedLetter{
    int num;
    char letter;
};
vector <CompressedLetter> Process(const string &str){
    vector <CompressedLetter> res;
    int pos = 0;
    while(pos < str.length()){
        int len = 0;
        while(str[pos]>= '0' && str[pos] <= '9'){
            len = len * 10 + (str[pos] - '0');
            pos++;
        }
        if(len == 0)
            len = 1;
        if(pos < str.length()){
            res.push_back({len, str[pos]});
            pos++;
        }
    return res;
}
//Sum Between Ranges
int SumRanges(int l, int r){
    if(r < l)
        return 0;
    if(l > 1)
        return SumRanges(1, r) - SumRanges(1, l - 1);
    if(r % 2 == 1)
        return SumRanges(1, r - 1) + r;
    else
        return r * (r + 1)/2;
}

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
//determine how many times each die wins, and how many times there is a draw, 
// when compared to a series of possible dice outcomes (from 1 to 6).
void CompareDice(){
    int dice1, dice2; cin >> dice1 >> dice2;
    int dice1Win = 0, dice2Win = 0, draw = 0;
    for(int i = 1; i <= 6; i++){
        if(abs(dice1 - i) > abs(dice2 - i))
            dice2Win++;
        else if(abs(dice1 - i) < abs(dice2 - i))
            dice1Win++;
        else
            draw++;
    }
    cout << dice1Win << " " << draw << " " << dice2Win;
}
void verify(){
    int n, k; cin >> n >> k;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if(k >= y){
            if(x > maxi)
                maxi = x;
        }
        else {
            if((x - (y - k)) > maxi)
                maxi = x - (y - k);
        }
    }
    cout << maxi;
}
//output the position of the unique number (either odd or even) in a sequence of integers. 
void FindUnique(){
    int n, x;
    cin >> n;
    int even = 0, odd = 0, pos1 = -1, pos2 = -1;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x % 2 == 0){
            even++; pos1 = i + 1;
        }
        else {
            odd++; pos2 = i + 2;
        }
    }
    (odd == 1) ? cout << pos2 :cout << cout << pos1;
}
void SnakePattern(){
    int row, col; cin >> row >> col;
    for(int i = 0; i < row; i++){
        if(i % 2 == 0){
            for(int j = 0; j < col; j++)
                cout << "#";
        }
        else {
            if((i / 2) % 2 == 0){
                for(int j = 0; j < col - 1; j++)
                    cout << ".";
                cout << "#";
            }
            else {
                cout << "#";
                for(int j = 1; j < col; j++)
                    cout << ".";
            }
        }
        cout << "\n";
    }
}
//Count How much Five will be exits
void CountFive(){
    int n, x = 0, y = 0, a;
    cin >> n;
    while(n--){
        cin >> a;
        (a == 5) ? x++ : y++;
    }
    if( y == 0)
        cout << -1 << "\n";
    else{
        if(x < 9)
            cout << 0 << "\n";
        else{
            int Five = (x / 9) *9;
            for(int i = 0; i < Five; i++)
                cout << 5 << " ";
            for(int i = 0; i < y; i++)
                cout << 0 << " ";
            cout << "\n";
        }
    }
}
//Find Integer between range
void FindInteger(){
    int n, m; cin >> n >> m;
    int cnt = (n + 1) / 2;
    int ans = ((cnt + m - 1) / m)*m;
    if(ans > n)
        cout << - 1;
    cout << ans;
}
//determines and outputs the coordinates of the other two points required to complete a square. 
void CompleteSquare(){
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    if(abs(x1 - x2) == abs(y1 - y2))
        cout << x1 << " " << x2 << " " << y1 << " " << y2;
    //if these points are horizontal
    else if(x1 == x2){
        int length = abs(y2 - y1);
        cout << x1 + length << " " << y1 << " " << x1 + length << " " << y2;
    }
    else if(y1 == y2){
        int length = abs(x2 - x1);
        cout << x1 << " " << y1 + length << " " << x2 << " " << y2 + length;
    }
    else 
        cout << -1;
}
void Calculate(){
    int sum; cin >> sum;
    if(sum >= 0)
        cout << sum;
    else {
        int a = -sum / 10 % 10;
        int b = sum % 10;
        cout << (a > b? sum/100 * 10 - b: sum / 10);
    }
}
//determine the maximum value based on certain conditions applied to a list of pairs of integers
void FindMax(){
    int a, b, maxi = -1;
    int n, x; cin >> n >> x;
    while(n--){
        cin >> a >> b;
        if(a < x){
            if(b !=0)
                maxi = max(maxi, 100 - b);
            else
                maxi = max(maxi, 0);
        }
        else if(a == x){
            if(b == 0)
                maxi = max(maxi, 0);
        }
    }
    cout << maxi;
}
void verify(){
    int a, b, maxi = -1;
    int n, x; cin >> n >> x;
    while(n--){
        cin >> a >> b;
        if(a < x){
            if(b !=0)
                maxi = max(maxi, 100 - b);
            else
                maxi = max(maxi, 0);
        }
        else if(a == x){
            if(b == 0)
                maxi = max(maxi, 0);
        }
    }
    cout << maxi;
}
void Verify(){
    int a,  b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    b *= c; b /= g;
    d *= e; f /= h;
    cout << min({b, f, d})/ a;
}
//you need to divide a resource c into chunks of size equal to the LCM of two other quantities a & b
void Verify(){
    int a, b, c;
    cin >> a >> b >> c;
    b = (a * b)/__gcd(a, b);//LCM
    cout << c/b
}
//purpose of the program is to count how many of the n integers are greater than the threshold value j. 
void Greater(){
    int n, j; cin >> n >> j;
    int x = n;
    while(n--){
        int i; cin >> i;
        if(i > j)
            x++;
    }
    cout << x;
}

//calculate the sum of 5 integers , and determine if the sum can be evenly divided by 5
void DivisibleFive(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    a += b + c + d + e;
    (a % 5 == 0 && a / 5 != 0) ?cout << a / 5:cout << -1;
}
void VerifyCond(){
    int l, r, maxi, initial;
    int cnt = 0;
    cin >> maxi >> initial >> l >> r;
    if(l != 1)
        cnt++;
    if(r != maxi)
        cnt++;
    if(l != 1 && r != maxi)
        cnt += abs(l - r);
    if(l == 1 && r != maxi)
        cnt += abs(r - initial);
    else if(l != 1 && r == maxi)
        cnt += abs(l - initial);
    else if(l != 1 && r!= maxi)
        cnt += min(abs(initial - l), abs(initial - r));
    cout << cnt;
}
void Condition(){
    int maxi, adjust, curr;
    cin >> maxi >> adjust >> curr;
    while(adjust != 0){
        if(adjust < 0){
            adjust += 1;
            curr -= 1;
            if(curr == 0)
                curr = maxi;
        }
        else {
            adjust -= 1;
            curr += 1;
            if(curr > maxi)
                curr = 1;
        }
    }
    cout << curr << "\n";
}
//determine whether it is possible to perform a series of jumps between two integers
//a and b, using a fixed step size c, such that the total number of jumps is even.
void CountJump(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int j = abs(a - b);
    if(j % c != 0){
        cout << "No";
        continue;
    }
    j /= c;
    if(j % 2 == 0)
        cout << "Yes";
    else
        cout << "No";
}
//purpose of this program is to simply compare two numbers and output which one is larger, 
void CompareBetween(){
    int x = 0, y = 0;
    int a, b; cin >> a >> b;
    (a > b) ? x++: y++;
    if(x > y) cout << "A";
    else if(y > x) cout << "B";
    else
        cout << "Equal";
}
//decompose a given integer a into the smallest number of parts such that each part 
//is either the integer 2 or 3. It then prints the number of parts followed by the actual parts themselves
void divideIntoParts(){
    int n, j; 
    cin >> n;
    if(n % 2 == 0){
        cout << n / 2;
        j = n / 2;
        while(j--){
            cout << 2 << " ";
        }
    }
    else {
        cout << (a - 3)/2 + 1;
        j = (a - 3)/2;
        cout << 3 ;
        while(j--){
            cout << 2 << " ";
        }
    }
}
//How much steps we need for being two variable same
void Same(){
    int x, y;
    cin >> x >> y;
    if(x == y)
        cout << 0;
    else if(x > y)
        cout << x - y;
    else {
        int Operation = 0;
        while(y > x){
            if(y % 2 == 0)
                y /= 2;
            else
                y++;
            Operation++;
        }
        Operation += x - y;
        cout << Operation;
    }
}
void Compare(){
    int x, y;
    cin >> x >> y;
    if(y == 1){
        if(x == 0)
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
    y -= 1;
    x -= y;
    (x >= 0 && y >= 0 && x % 2 == 0) ? cout << "Yes": cout << "No";
}
//compute and print the minimum value from a set of given expressions 
void Calculate(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << min({a + b + c, 2 *(a + b), 2 * (b + c), 2 * (c + a)});
}
//compare two calculated values to determine which of two options is better, or if they are equivalent. 
void Compare(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    b *= a; b += 2 * d;
    c *= a; c += 2 * e;
    if(b > c)
        cout << "second";
    else if(c > b)
        cout << "First";
    else
        cout << "Friendship";
}

int MinPos(vector <int> &vec){
    int pos = 0;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] < vec[pos])
            pos = i;
    }
    return pos;
}
int MaxPos(vector <int> &vec){
    int pos = 0; 
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] > vec[pos])
             pos = i;
    }
    return i;
}
vector <int> PrefixSum(vector <int> &vec){
    vector <int> prefix(vec.size());
    prefix[0] = vec[0];
    for(int i = 1; i < vec.size(); i++){
        prefix[i] = prefix[i - 1] + vec[i];
    }
    return prefix;
}
vector <int> SuffixSum(vector <int> &vec){
    vector <int> suffix(vec.size());
    suffix[vec.size() - 1] = vec[vec.size() - 1];
    for(int i = vec.size() - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + vec[i];
    return suffix;
}
//DetectPrime
vector <bool> DetectPrime(int n){
    vector <bool> num( n + 1, true);
    num[0] = false; num[1] = false;
    for(int i = 2; i <= n; i++){
        if(num[i]){
            for(int j = i*i; j <= n; j+= i){
                num[j] = false;
            }
        }
    }
    return num;
}
vector <int> GetDigit(int n){
    vector <int> Digits;
    while(n > 0){
        Digits.push_back(n % 10);
        n /= 10;
    }
    return Digits;
}
__main(){
    int n; cin >> n;
    vector <bool> prime = DetectPrime(n);
    vector <int> Get = GetDigit(n);
    
    for(int i = 2; i <= n; i++){
        if(prime[i])
            cout << i << " ";
    }
    cout << "\n";
    for(int i = 0; i < Get.size(); i++)
        cout << Get[i] << " ";
}
// count and output the number of elements in the vector that are greater than or
//equal to the maxi value between 1 and the smallest element in the sorted vector.
void Count(){
    int n; cin >> n;
    int k = n - 1;
    vector <int>vec(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vec[i] = x;
    }
    sort(vec.begin(), vec.end(), greater <int>());
    int min = max(1, vec[k]);
    int res = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] >= mini)
            res++;
    }
    cout << res;
}

//determine if a given integer will eventually converge to 1 when repeatedly replaced by the sum of the squares of its digits. 
int SquareSum(int num){
    int sum = 0;
    while(num > 0){
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}
int convergence(int num, int maxiit){
    int cur = num, original = num, iteration = 0;
    do {
        cur = SquareSum(cur);
        if(cur == 1)
            return 1;
        if(cur == original)
            return 0;
        iteration++;
    }while(iteration < maxiit);
    return 0;
}
main(){
    int num; cin >> num;
    int res = convergence(num, 100);
    (res == 1)?cout << num << " covergence to 1":cout << num << " Enters into a cycle or not convergence";
}

//Given Value n with number 1.can multiply either 10 or 20 with n.check is it can reach the output value
bool ReachValue(int cur, int trg){
    if(cur == trg)
        return true;
    if(cur > trg)
        return false;
    return ReachValue(cur *10, trg) || ReachValue(cur *20, trg);
}
main(){
    int n; cin >> n;
    (ReachValue(1, n))? cout << "Yes":cout << "No";
}

void verify(){
    int x, y; cin >> x >> y;
    if(x == 1 && y == 1)
        cout << 0;
    else if(x == 1 && y == 2 || x == 2 && y == 1)
        cout << 1;
    else if(x == 1 && y > 2 || x > 2 && y == 1)
        cout << 2;
    else {
        if((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
            cout << (max(x, y) - 1)*2;
        else 
            cout << (max(x, y) - 1)*2 - 1;
    }
}
void verify(){
    int n; cin >> n;
    int ans = 0;
    int x = n % 10 - 1;
    ans += 10 * x;
    int k = n % 10;
    int cnt = 0, ptr = 1;
    while(cnt <= n){
        cnt = cnt % 10 + k;
        ans += ptr; ptr++;
    }
    cout << ans;
}
void BasedCondition(){
    int a, b, ans;
    cin >> a >> b;
    (a == 0) ? ans = 1 : ans = a + 2 * b + 1;
    cout << ans;
}
//GCD, LCM
int GCD(int a, int b){
    if(a == 0 || b == 0)
        return a + b;
    if(a > b)
        return (a % b, b);
    return (a, b % a);
}
int GCD(int a, int b){
    if(b > a)
        swap(b, a);
    if(a == b)
        return a;
    for(int i = b; i > 0; i--){
        if(b % i == 0 && a % i == 0)
            return i;
    }
}
int LCM(int a, int b){
    for(int i = max(a, b); i <= a*b; i++){
        if(i % a == 0 && i % b == 0)
            return i;
    }
    return -1;
}
__main(){
    int n, x; cin >> n >> x;
    cout << GCD(n, x);
}
//Hanoi
void Hanoi(int n, char a, char b, char c){
    if(n > 0){
        Hanoi(n - 1 , a, c, b);
        cout << "Move From " << a << " To " << b << " Use " << c << "\n";
        Hanoi(n - 1, c, b, a);
    }
}
__main(){
    int n; cin >> n;
    char a, b, c; cin >> a >> b >> c;
    Hanoi(n, a, b, c);
}
//Party Arrange
void PartyArrange(){
    int Friends, Bottles, mlPerBottle, Lime, SlicePerLime, SaltAmount, mlPerServing, SaltPerServing;
    cin >> Friends >> Bottles >> mlPerBottle >> Lime >> SlicePerLime >> SaltAmount >> mlPerServing >> SaltPerServing;
    int TotalML = (Bottle * mlPerBottle)/mlPerServing / Friends;
    int TotalSalt = SaltAmount / SaltPerServing / Friends;
    int TotalLime = (Lime * SlicePerLime) / Friends;
    int minServing = min({TotalML, TotalSalt, TotalLime});
    cout << minServing;
}

void verifyCond(){
    int x, y; cin >> x >> y;
    int res = 0;
    if(y > x && x >= -y){
        cout << "a";
        res = -2 + y * 4;
    }
    else if(x > y && x <= -y + 1){
        cout << "b";
        res = -y * 4;
    }
    else if(y <= x && x > -y + 1){
        cout << "c";
        res = -3 + x * 4;
    }
    else if(y >= x && x < -y){
        cout << "d";
        res = -1 - 4 * x;
    }
    cout << res;
}

//Print Even Between range
void PrintBetween(){
    int l, r; cin >> l >> r;
    if(l % 2 != 0)
        l += 1;
    if(r - l >= 4)
        cout << l << " " << l + 2 << " " << l + 4;
    else
        cout << -1;
}
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
