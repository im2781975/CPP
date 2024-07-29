
const int MAX_SIZE = 100;
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int counter = 0, groupSize = 0, column = 0;
    for (int i = size - 1; i >= 0; i--, counter = 0, column++)
    {
        while (counter < pow(3, size))
        {
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 1;
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 2;
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 3;
        }
    }
}

main()
{
    int x, y;
    cin >> x >> y;

    int matrix[MAX_SIZE][MAX_SIZE];
    fillMatrix(matrix, y);

    int n = 0;
    while (cin >> n)
    {
        int dimension = pow(3, n);
        int **dynamicMatrix = new int *[dimension];
        for (int row = 0; row < dimension; ++row)
        {
            dynamicMatrix[row] = new int[n];
            fillMatrix(dynamicMatrix, n);
            for (int r = 0; r < pow(3, n); r++)
            {
                for (int c = 0; c < n; c++)
                    cout << dynamicMatrix[r][c];
                cout << "\n";
            }
        }
        for (int q = 0; q < dimension; ++q)
            delete[] dynamicMatrix[q];
        delete[] dynamicMatrix;
        cout << endl;
    }
    return 0;
}

//calculates the sum of the integers a for which the corresponding string r starts with the character ch and prints this sum.
struct X{
    char r[100], int a;
}
main(){
    int n; cin >> n;
    struct X arr[100];
    //reads a character & integer from the array
    for(int i = 0; i < n; i++)
        cin >> arr[i].r >> arr[i].a;
    char ch; cin >> ch;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].r[0] == ch)
            cnt += arr[i].a;
    }
    cout << cnt;
}

#include<iostream>
using namespace std;
//manipulate the values of x and y through a series of recursive calls.
int cnt = 0, odd = 0;
int request(int x, int y){
    if(y == 1)
        return x;
    if(x + y + 1 == y)
        return (pow(2, cnt - 1) + odd);
    if(x + odd == y)
        return pow(2, cnt);
    if(x == y)
        return pow(pow(2, cnt) + odd);
    if(x <= y && odd > y)
         return (pow(2, cnt) + odd / y + (odd % y));
    if(x <= y && odd > y)
        return (pow(2, cnt) + 1);
    if(x % 2 == 0){
        x /= 2;
        cnt++;
    }
    else {
        x = (x + 1)/2;
        cnt++; odd++;
    }
    return request(x, y);
}
main(){
    int x, y;
    cin >> x >> y;
    cout << request(x, y);
}

//checks if a given number is prime using a probabilistic method similar to the Fermat primality test.
bool powermod(int a, int b, int n){
    if(b == 0)
        return 1;
    int k = powermod(a, b/2, n);
    k = (k * k)% n;
    if(b & 1)
        k = (k * a) % n;
    return k;
}
bool IsPrime(int n, int iter = 5){
    if(n < 4)
        return n == 3 || n == 2;
    if(n % 3 == 0 || n % 2 == 0)
        return false;
    srand(time(nullptr));
    for(int i = 0; i < iter; i++){
        int a = 2 + rand() % (n - 2);
        if(powermod(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
main(){
    int num; cin >> num;
    (IsPrime(num))?cout << num << " Is prime":cout << "Not prime";
}

//Count hididng places & positions in a grid which is represent by '#'
void CountHiding(){
    int row; cin >> row;
    int cnt = 0;
    if(row <= 0){
        cout << "Invalid Input";
        return 0;
    }
    vector <string> grid(row);
    //row wise it will take take string not char
    for(int i = 0; i < row; i++){
        cin >> grid[i];
        if(grid[i].length() !=row){
            cout << "Row didn't match";
            return 0;
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            if(grid[i][j] == '#'){
                cout << i + 1 << " " << j + 1 << "\n";
                cnt++;
            }
        }
    }
    (cnt == 0)?cout << "No Hiding places":cout << "Hiding places are: " << cnt;
}

//Print elements in vector
void Print(){
    const int MAX = 1001;
    int n, x, cnt = 0;
    cin >> n;
    vector <int> vec(MAX, -1);
    for(int i = 0; i < n; i++){
        cin >> x;
        vec[x] = x;
    }
    for(int i = 0; i < MAX; i++){
        if(vec[i] != -1)
            cnt++;
    }
    cout << "\n";
    bool first = true;
    for(int i = 0; i < MAX; i++){
        if(vec[i] != -1){
            if(first){
                cout << vec[i] << " ";
                first = false;
            }
            else
                cout << vec[i] << " ";
        }
    }
    cout << "\n";
}

// check if there is any row or column in n*n grid that is completely filled with the character '*'.
void CheckCondition(){
    char arr[10][10];
    int rowCnt[10] = {0};
    int colCnt[10] = {0};
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(arr[i][j] == '*'){
                rowCnt[i]++;
                colCnt[j]++;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        if(rowCnt[i] == 10 || colCnt[i] == 10){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}

// perform a series of arithmetic operations on a sequence of numbers 
//based on given operators, and then output the final result of these operations.
void Operation(){
    int n; cin >> n;
    char *arr = new char[n];
    double *dbl = new double[n + 1];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i <= n; i++)
        cin >> dbl[i];
    for(int i = 0; i < n; ++i){
        switch(arr[i]){
            case '+': dbl[i + 1] = dbl[i] + dbl[i + 1]; break;
            case '-': dbl[i + 1] = dbl[i] - dbl[i + 1]; break;
            case '*': dbl[i + 1] = dbl[i] * dbl[i + 1]; break;
            case '/': 
                if(dbl[i + 1] !=0)
                    dbl[i + 1] = dbl[i] / dbl[i + 1];
                else {
                    cout << "Division By Zero";
                    delete []arr;
                    delete []dbl;
                    return 1;
                }
                break;
            default:
                cout << "Invalid Operator";
                delete []arr;
                delete []dbl;
                return 1;
        }
    }
    cout << dbl[n];
    delete []arr;
    delete []dbl;
    return 0;
}

// counts the occurrences of b among these a integers and records the position of the
//first occurrence. Finally, it outputs the count and the position of the 
//first occurrence of b if found, otherwise, it outputs −1
void CountPos(){
    int a, b, x, cnt = 0, PosCnt = 0, pos;
    while(cin >> a >> b && a > 0 && b > 0){
        for(int i = 0; i < a; i++){
            cin >> x;
            if(x == b) {
                if(cnt == 0)
                    pos = PosCnt;
                cnt++;
            }
            PosCnt++;
        }
    }
    (cnt == 0)?cout << "-1":cout << cnt << " " << pos;
}

//determine whether the parity (even or odd nature) of the input numbers 
//matches the parity of their positions (index) in the sequence
void checkParity(){
    int num, cur, idx = 1 ,cnt = 0; 
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> cur;
        if((cur % 2 == 0 && idx % 2 == 0) || (cur % 2!= 0 && idx % 2 != 0))
            cnt++;
        idx++;
    }
    (cnt == idx)? cout << "Yes":cout << "No";
}

//Find Kth element which is not divisible by n
void kThElement(){
    int n, k;
    cin >> n >> k;
    cout << k + ((k - 1)/(n - 1));
}

//Find Maximum Element
int FindMax(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
//Is the vector is sorted
bool IsSorted(vector <int> vec){
    for(int i = 1; i < vec.size(); i++){
        if(vec[i - 1] > vec[i])
            return false;
    }
    return true;
}
//determines whether a vector of integers has any local maximum
//A local maximum is an element that is greater than its immediate neighbors
bool LocalMax(vector <int> vec){
    for(int i = 1; i < vec.size(); i++){
        if(i !=vec.size() -1){
            if(vec[i] > vec[i - 1] && vec[i] < vec[i + 1])
                return true;
        }
        return false;
    }
}
//Is the string contain NonZero
bool Check(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '0')
            return true;
    }
    return false;
}

//count the number of consecutive integers that are divisors of n
//Find the max length of such consecutive divisors and prints this max length.
void CountLength(){
    int n; cin >> n;
    int cnt = 0, maxSize = 0;
    int sqrt_n = sqrt(n);
    for(int i = 1; i <= sqrt_n; i++){
        if(n % i == 0)
            cnt++;
        else {
            maxSize = max(maxSize, cnt);
            cnt = 0;
        }
    }
    maxSize = max(maxSize, cnt);
    cout << maxSize;
}

//count how many times a sequence of input integers is greater than
//or less than the previous integer in the sequence.
void CountGreater(){
    int n, cur, prv;
    int high = 0, low = 0;
    cin >> n;
    if(n <= 1){
        cout << high << " " << low;
        return 0;
    }
    cin >> prv;
    for(int i = 0; i < n; i++){
        cin >> cur;
        if(cur > prv)
            high++;
        else if(cur < prv)
            low++;
        prv = cur;
    }
    cout << high << " " << low;
}

//BubbleSort with count swaps
void BubbleSort(){
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int Ind = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < arr[i + 1])
            continue;
        else
            Ind = -1;
    }
    if(Ind == 0){
        cout << "Ordered";
        return 0;
    }
    else{
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1 - i; j++){
                if(arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
                    ++Ind;
            }
        }
    }
    cout << Ind << "\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    delete []arr;
}

//computes the binomial coefficient C(n,r) using a recursive approach
int factorial(int n, int r, vector <vector<int> >dp){
    if(r > n)
        return 0;
    if(r == 0 || r == 1)
        return 1;
    if(dp[n][r] != -1)
        return dp[n][r];
    // Use the recursive relation: nCr = (n-1)Cr + (n-1)C(r-1)
    dp[n][r] = factorial(n - 1, r, dp) + factorial(n -1, r - 1, dp);
    return dp[n][r];
}
main(){
    int n, r;
    cin >> n >> r;
    vector <vector <int> >dp(n + 1, vector <int> (r + 1, -1));
    int res = factorial(n, r, dp);
    cout << res;
}

//compute the result of raising a base a to an exponent b under a modulus c
int powermod(int a, int b, int c){
    if(b == 0)
        return 1;
    int k = powermod(a, b / 2, c);
    k *= k;
    k %= c;
    if(b & 1)
        k = (k * a) % c;
    return k;
}
main(){
    int a, b, c;
    //a present base, b present exponential, c present modulo
    cin >> a >> b >> c;
    cout << powermod(a, b, c);
}

void Sqrt(){
    int x; cin >> x;
    int ans = 0;
    //i start with 2^30.
    for(long long i = 1 << 30; i!= 0; i/=2){
        if((ans + i)*(ans + i) <= x)
            ans += i;
    }
    cout << ans;
}

//partition an number into two nearly equal parts.
void MakePartition(){
    int n; cin >> n;
    //In Bitwise And operation if n becomes odd looo returns true(0011 & 0001 = 0001)
    if(n & 1)
        cout << n/2 << " " << n/2 + 1 << "\n";
    else
        cout << n /2 << "\n";
}

void PrimeFactor(){
    int n; cin >> n;
    int cnt = 0;
    while (n % 2 == 0){
        cnt++;
        n /= 2;
    }
    for(int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            cnt++;
            n /= i;
        }
    }
    if(n > 2)
        cnt++;
    cout << cnt;
}

//implementation of Kadane's Algorithm, which is used to 
//find the maximum sum of a contiguous subarray in an array
int maxSubArraySum(int arr[], int n){
    int maxi = INT_MIN; curSum = 0;
    //CurSum will accumulate the sum of the cur subarray being evaluated.
    for(int i = 0; i < n; i++){
        curSum = curSum + arr[i];
        if(curSum > maxi)
            maxi = curSum;
        if(curSum < 0)
            curSum = 0;
    }
    return maxi;
}

//find GCD
void gcd(int a, int b){
    if(b > a)
        return gcd(b, a);
    if(b == 0)
        return a;
    return (b, a % b);
}

//determine the minimum number of boxes required to store a certain number of balls of 
//three different colors: blue, green, and red. Each type of ball has a specific quantity 
//requirement based on a given integer n, and the boxes have a capacity of k balls.
void CntBox(){
//n represents a base quantity used to calculate the number of balls of each color.
//k represents the capacity of each box (i.e., how many balls a single box can hold).
    int n, k;
    cin >> n >> k;
    int blue, green, red;
   /* blue = (8 * n + k -1)/k;
    green = (5 * n + k - 1)/k;
    red = (2 * n + k -1)/k;
    cout << blue + green + red; */
    blue = (8 * n)/k;
    green = (5 * n)/k;
    red = (2 * n)/k;
    if(8 * n % k != 0)
        blue += 1;
    if(5 * n % k != 0)
        green += 1;
    if(2 * n % k != 0)
        red += 1;
    cout << blue + green+ red;
}

//determine how many of these scores fall into specific ranges
//and then calculate and display the percentages of scores
void CalculatePercentage(){
    int n; cin >> n;
    int Top = 0, Avg = 0;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > 85){
            Top++; 
            Avg++;
        }
        else if(x >= 60 && x < 85)
            Avg++;
    }
    double b = (Top /(n * 1.0))*100;
    double c = (Avg /(n * 1.0))*100;
    //((b - int(b)) >= 0.5) ? Top = int(b) + 1 : Top = int(b);
    //((c - int(c)) >= 0.5) ? Avg = int(c) + 1 : Avg = int(c);
    Top = round(b);
    Avg = round(c);
    cout << Top << '%' << "\n";
    cout << Avg << '%' << "\n";
}
