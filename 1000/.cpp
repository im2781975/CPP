#include<bits/stdc++.h>
using namespace std;
void Isunique(){
    string str, ing; cin >> str >> ing;
    bool flag = true;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 97) str[i] -= 32;
        if(ing[i] >= 97) ing[i] -= 32;
        if(str[i] != ing[i]){
            flag = false;
            break;
        }
    }
    (flag) ? cout << "20 / 20" << "No";
}
using namespace std;
void findMin(){
    string str; cin >> str;
    int b = o = n = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'o') o++;
        else if(str[i] == 'n') n++;
        else if(str[i] == 'b') b++;
    }
    if(b < 2 || o < 2 || n < 2)
        cout << 0;
    else
        cout << min(b, min(o, n)) - 1;
}
#include<bits/stdc++.h>
using namespace std;
void Bubble(int **arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j][0] > arr[j + 1][0]){
                swap(arr[j][0], arr[j + 1][0]);
                swap(arr[j][1], arr[j + 1][1]);
            }
        }
    }
}
int main(){
    int data[4][2]{{3, 2}, {1, 4}, {4, 1}, {2, 3}};
    int *ptr[4];
    for(int i = 0; i < 4; i++)
        ptr[i] = data[i];
    Bubble(ptr, 4);
    for(int i = 0; i < 4; i++)
        cout << ptr[i][0] << " " << ptr[i][1] << "\n";
}
#include<bits/stdc++.h>
using namespace std;
void QuickSort(int *arr, int left, int right){
    int l = left, r = right;
    int mid = arr[l + (r - l) / 2];
    do{
        while(mid > arr[l])
            l++;
        while(mid < arr[r])
            r--;
        if(l <= r){
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++; r--;
        }
    }while(l <= r);
    if(left < r)
        QuickSort(arr, left, r);
    if(l < right)
        QuickSort(arr, l, right);
}
int main(){
    int arr[]{2, 3, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
#include<bits/stdc++.h>
using namespace std;
//How much we can divide a rod into a equal part.
void cntPart(){
    int n, res; cin >> n;
    if(n == 1) res = 0;
    else if(n % 2 == 0) res = n / 2;
    else if(n % 3 == 0) res = n / 3;
    else if(n % 5 == 0) res = n / 5;
    else if(n % 7 == 0) res = n / 7;
    else
        res = 1;
    cout << res << " " << n - res;
}
using namespace std;
void statement(){
    int arr[3]; cin >> arr[0] >> arr[1] >> arr[2];
    (arr[0] == arr[2] - 1 && arr[1] == arr[2] - 1 && arr[0] + arr[1] > arr[2]) ? cout << "Yes" : cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
//determine if sumOf the pair is even.
void pairSum(){
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    bool x = (a + d) % 2;
    bool y = (b + e) % 2;
    bool z = (c + f) % 2;
    (x && y && z) ? cout << 1 : cout << p;
}
using namespace std;
void statement(){
    int x; cin >> x;
    cout >> (x * x) * (x * x + 1)/2;
}
//find the maximum sum of a specific sequence from a 2D array
const int N = 5;
void FindSum(){
    int arr[N][N], maxi = INT_MIN, cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            arr[i][j] = i + j;
    }
    for(int i = 0; i <= 1; i++){
        for(int j = i; j <= 2; j++){
            if(j > i + 1)
                j = 3;
            for(int k = j; k <= 3; k++){
                if(k > j + 1)
                    k = 4;
                for(int l = k; l <= 4; l++){
                    if(l > k + 1)
                        l = 5;
                    int sum = arr[0][0] + arr[1][i] + arr[2][j] + arr[3][k] + arr[4][l] ;
                    if(sum > maxi)
                        maxi = sum;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << " " << maxi << "\n";
}
#include<bits/stdc++.h>
using namespace std;
// count how many numbers within range [a,b] (inclusive) do not contain the digit '4' & '26'.
const int maxi = 1e5;
void cntRange(){
    int arr[maxi];
    arr[0] = 1;
    for(int i = 1; i <= maxi; i++){
        int tmp = i;
        bool forbidden = false;
        while(tmp){
            if(tmp % 10 == 4){
                forbidden = true;
                break;
            }
            if(tmp % 10 == 2 && (tmp / 10) % 10 == 6){
                forbidden = true;
                break;
            }
            tmp /= 10;
        }
        if(forbidden)
            arr[i] = arr[i - 1];
        else
            arr[i] = arr[i - 1] + 1;
    }
    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0)
            break;
        if(a > b)
            swap(a, b);
        cout << arr[b] - arr[a - 1];
    }
}
using namespace std;
//convert the string in (int, char) pair
vector <pair <int, char > >process(const string &str){
    vector <pair <int, char > > res;
    int pos = 0;
    while(pos < str.length()){
        int len = 0;
        while(pos < str.length() && str[pos] >= '0' && str[pos] <= '9'){
            len = len * 10 + (str[pos] - '0');
            pos++;
        }
        if(len == 0)
            len = 1;
        if(pos < str.length()){
            res.push_back({len, str[pos]});
            pos++;
        }
    }
    return res;
}
using namespace std;
// find the minimal unused capacity of a knapsack of size cap given n items of various sizes. 
const int N = 200100;
int main(){
    int cap, n; cin >> cap >> n;
    //cap - knapsack capacity n - number of items
    int arr[N] = {0};
    for(int i = 1; i <= n; i++){
        int sz; cin >> sz;
        for(int j = cap; j >= sz; j--)
            arr[j] = max(arr[j - sz] + sz, arr[j]);
    }
    cout << cap - arr[cap];
}
#include<bits/stdc++.h>
using namespace std;
void pascalTriangle(){
    int n; cin >> n;
    int arr[33][33];
    arr[1][1] = 1;
    for(int i = 2; i <= n; i++){
        arr[i][1] = 1;
        arr[i][i] = 1;
        for(int j = 2; j < i; j++)
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}
//counts how many times the subsequent elements are greater than or equal to the current element, 
// adjusts the count based on certain conditions, and then prints n - cnt for each outer loop iteration.
void SubSequent(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] >= arr[i]){
                cnt++;
                if(j == n - 1)
                    cnt--;
            }
            else{
                i = j - 1;
                //start the outer loop where it is broken.
                if(cnt > 0)
                    cnt--;
                break;
            }
        }
    }
    cout << n - cnt;
}
#include<bits/stdc++.h>
using namespace std;
void subarrSum(){
    int n; cin >> n;
    int arr[n], sum = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int i = 1, j = n -1, k = 5;
    while(k > 0 && i < n - 1 && j >= 0){
        if(arr[i] + arr[i - 1] < arr[j]){
            i += 2;
            k--;
        }
        else if(arr[i] + arr[i - 1] > arr[j]){
            j--; k--;
        }
        else if(arr[i] + arr[i - 1] == arr[j] && k >= 2){
            i += 2, j--; k-= 2;
        }
        else{
            j--; k--;
        }
    }
    i = max(1, i - 1);
    for(int idx = i; idx <= j; idx++)
        sum += arr[idx];
    cout << sum;
}
using namespace std;
//implements a sieve algorithm to generate prime numbers and 
// calculate the Euler's Totient function (φ) for each number up to N
const int N = 1e5;
bool Isprime[N];
int prime[N / 10], cnt = 0, phi[N], arr[N];
void eularTotient(){
    fill(Isprime, Isprime + N, true);
    Isprime[0] = Isprime[1] = false;
    for(int i = 0; i < N; i++)
        phi[i] = i;
    for(int i = 2; i < N; i++){
        if(Isprime[i]){
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < cnt && prime[j] * i < N; j++){
            int composite = i * prime[j];
            arr[composite] = prime[j];
            Isprime[composite] = false;
            if(i % prime[j] == 0){
                phi[composite] = phi[i] * prime[j];
                break;
            }
            else
                phi[composite] = phi[i] * (prime[j] - 1);
        }
    }
    for(int i = 0; i < 20; i++)
        cout << phi[i] << " ";
}
using namespace std;
//determine how dynamic the array is in terms of new highs and lows as you traverse it 
//from start to end. By counting the number of times the max and min values change,
void cntMaxMin(){
    int n; cin >> n;
    int arr[n], cntMin = 0, cntMax = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int mini = arr[0], maxi = arr[0];
    for(int i = 1; i < n; i++){
        if(mini > arr[i]){
            mini = arr[i];
            cntMin++;
        }
        if(maxi < arr[i]){
            maxi = arr[i];
            cntMax++;
        }
    }
    cout << cntMax + cntMin;
}
using namespace std;
//find the length of the longest contiguous subarray in an array of integers where the absolute difference between consecutive elements remains consistent.
void subarrLen(){
    int n; cin >> n;
    int arr[n], cnt = 1, maxlen = 1;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int diff = abs(arr[1] - arr[0]);
    for(int i = 1; i < n; i++){
        int tmp = abs(arr[i + 1] - arr[i]);
        if(diff == tmp){
            cnt++;
            if(cnt > maxlen)
                maxlen = cnt;
        }
        else{
            diff = tmp;
            cnt = 1;
        }
    }
    cout << "maximum length is: " << maxlen;
}
//count the number of times the x value from one input pair matches the
//y value from another input pair, excluding when they are at the same index. 
using namespace std;
void matchPair(){
    int n; cin >> n;
    int arr[n], tmp[n], cnt = 0;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr[i] = x; tmp[i] = y;
    }
    for(int i = 0, j = 0; i < n, j < n; i++, j++){
        if(arr[i] == tmp[j] && i != j) cnt++;
    }
    cout << "Matched pair is: " << cnt;
}
using namespace std;
//Count Consecutive Duplicate & count the number of distinct contiguous segments in an array of integers
void cntUnqDup(){
    int n; cin >> n;
    int arr[n], unq = 0, dup = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1])
            unq++;
        if(arr[i] != arr[i + 1])
            dup++;
    }
    cout << "Consecutive Duplicate: " << dup << "\nUnique element is: " << unq + 1;
}
using namespace std;
//find the maximum gap between adjacent elements in an array after removing
//one element in a way that minimizes the maximum gap between the remaining adjacent elements. 
void maximumGap(){
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int mini = INT_MAX, pos = -1;
    for(int i = 2; i < n; i++){
        if(arr[i] - arr[i - 2] < mini){
            mini = arr[i] - arr[i - 2];
            pos = i - 1;
        }
    }
    int maxi = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        if(i + 1 == pos && i + 2 < n){
            maxi = max(maxi, arr[i + 2] - arr[i]);
            i++;
        }
        else
            maxi = max(maxi, arr[i + 1] - arr[i]);
    }
}
using namespace std;
// calculate the total exercise done for each muscle group over the n days 
//and determine which muscle group has the maximum exercise.
void Exercise(){
    int n; cin >> n;
    int *exercise = new int[n];
    for(int i = 0; i < n; i++)
        cin >> exercise[i];
    int chest = biceps = back = 0;
    switch(i % 3){
        case 0: 
            chest += exercise[i]; break;
        case 1:
            biceps += exercise[i]; break;
        case 2: 
            back += exercise[i]; break;
    }
    if(chest > biceps && chest > back)
        cout << "chest: " << chest;
    else if(biceps > chest && biceps > back)
        cout << "biceps: " << biceps;
    else
        cout <<"Back: " << back;
}
using namespace std;
// calculate sum of the first two integers in each triplet, 
//store these in an array, and then find and print the largest sum decreased by 1.
void maxSum(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b;
        c = a + b;
        arr[i] = c;
    }
    int maxi = arr[0];
    for(int i = 1; i < n; i++){
        if(maxi < arr[i])
            maxi = arr[i];
    }
    cout << maxi - 1;
}
void maxSum(){
    int n; cin >> n;
    int a[n], b[n], c[n], sum = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++){
        sum -= (a[i] + b[i]);
        c[i] = sum;
    }
    int maxi = c[0];
    for(int i = 1; i < n; i++){
        if(maxi < c[i])
            maxi = c[i];
    }
    cout << maxi;
}
#include<bits/stdc++.h>
using namespace std;
void executeIng(){
    int n; cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str.size() > 10 )
            cout << str[0] << " " << str.size() - 2 << " " << str[str.size() - 1];
        else
            cout << str;
    }
}
using namespace std;
const int N = 1e7;
bool mark[N];
int prime[N / 10], cnt = 0;
void printPrime(){
    mark[0] = mark[1] = false;
    for(int i = 2; i < N; i++)
        mark[i] = true;
    for(int i = 2; i < N; i++){
        if(mark[i]){
            prime[++cnt] = i;
            for(int j = i * 2; j < N; j += i)
                mark[j] = false;
        }
    }
    int sum = 0;
    for(int i = 0; i < 25; i++){
        cout << prime[i] << " ";
        sum += prime[i];
    }
    cout << "sum of the prime is: " << sum;
}
using namespace std;
// find and print the 1-based index of the unique element in
void findUnqIdx(){
    int t; cin >> t;
    int res[t];
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int unqIdx = -1;
        if(arr[0] != arr[1]){
            unqIdx = (arr[1] == arr[2]) ? 0 : 1;
        }
        else{
            for(int i = 2; i < n; i++){
                if(arr[0] != arr[i]){
                    unqIdx = i;
                    break;
                }
            }
        }
        res[t] = unqIdx + 1;
    }
    for(int i = 0; i < t; i++)
        cout << res[i] << " ";
}
using namespace std;
//Sum consecutive integer Diffrence
void sumDiff(){
    int arr[3];
    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr + 3);
    for(int i = 0; i < n; i++)
        arr[i] = abs(arr[i]);
    
    int x = abs(arr[1] - arr[0]);
    int y = abs(arr[2] - arr[1]);
    cout << x + y;
}
// determine the minimum number of steps required to make two integers equal. 
using namespace std;
void countStep(){
    int n; cin >> n;
    vector <int> res(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        int step = 0;
        if(a > b){
            int diff = a - b;
            if(diff % 2 == 0) ? step = 1 : step = 2;
        }
        else if(a < b){
            int diff = b - a;
            if(diff % 2 == 0) ? step = 2 : step = 1;
        }
        else
            step = 0;
        res[i] = step;
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
//find the first occurrence where adjacent elements are different
using namespace std;
void spyDetect(){
    int t; cin >> t;
    vector <int> res(t);
    for(int k = 0; k < t; k++){
        int n; cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int cnt = -1;
        if(arr[0] != arr[1]){
            cnt = (arr[0] != arr[2]) ? 1 : 2;
        }
        else{
            for(int i = 2; i < n; i++){
                if(arr[i] != arr[0]){
                    cnt = i + 1;
                    break;
                }
            }
        }
        res[t] = cnt;
    }
    for(int i = 0; i < t; i++)
        cout << res[i] << " ";
}
using namespace std;
//Find the nxt number which contain unique digits
bool IsDistinct(int num){
    set <int> digits;
    while(num > 0){
        int dig = num % 10;
        //if already exits dig
        if(digits.count(dig))
            return false;
        digits.insert(dig);
        num /= 10;
    }
    return true;
}
int main(){
    int n; cin >> n;
    for(int i = n + 1; ; i++){
        //print the nxt distinct
        if(IsDistinct(i)){
            cout << i ;
            break;
        }
    }
}
using namespace std;
// determine if all the levels from 1 to n are covered by the unique elements present in two given arrays. 
int RemoveDup(int *arr, int n){
    if(n == 0 || n == 1)
        return n;
    int tmp[n], j = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] != arr[i + 1])
            tmp[j++] = arr[i];
    }
    tmp[j++] = arr[n - 1];
    for(int i = 0; i < n; i++)
        arr[i] = tmp[i];
    return j;
}
int main(){
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int arr[a], tmp[b];
    for(int i = 0; i < a; i++)
        cin >> arr[i];
    a = RemoveDup(arr, n);
    for(int i = 0; i < b; i++)
        cin >> tmp[i];
    b = RemoveDup(tmp, n);
    int cnt = n;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] == j)
                cnt--;
        }
    }
    for(int i = 0; i < b; i++){
        // Iterate over all levels Player B can complete
        for(int j = 0; j < n; j++){
        // Compare each level Player B can complete to all levels from 0 to n-1
            if(tmp[i] == j)
                cnt--;
        }
    }
    (cnt == 0)? cout << "Become the Guy" : cout << "No ome";
}
using namespace std;
void IsDistinct(){
    int totalLevel; cin >> totalLevel;
    //Number of Levels that a can complete
    int a; cin >> a;
    set <int> Levels;
    for(int i = 0; i < a; i++){
        int lev; cin >> lev;
        Levels.insert(lev);
    }
    int b; cin >> b;
    for(int i = 0; i < b; i++){
        int lev; cin >> lev;
        Levels.insert(lev);
    }
    if((int)Levels.size() == n) ? cout << "Become the Guy" : cout << "No one";
    
    /*bool Levels[totalLevel + 1];
    for(int i = 0; i < a; i++)
        Levels[i] = true;
    for(int i = 0; i < b; i++)
        Levels[i] = true;
    for(int i = 1; i <= n; i++){
        if(!Levels[i])
            return 0;
    }
    cout << "Become the Guy";*/
}
using namespace std;
//calculate and display 2^num to find the sum of the digits of the resulting number. 
int powerTwo(int digits[], int cntDig){
    int tmp = 0;
    for(int i = 0; i < cntDig; i++){
        //double the digit arr elements
        int product = digits[i] * 2 + tmp;
        digits[i] = product % 10;
        tmp = product / 10;
    }
    while(tmp){
        digits[cntDig] = tmp % 10;
        tmp /= 10;
        cntDig++;
    }
    return cntDig;
}
void powerBase(int num){
    int digits[500], cntDig = 1, sumDig = 0;
    
    digits[0] = 1;  //2^0 = 1
    for(int i = 1; i <= num; i++)
        cntDig = powerTwo(digits, cntDig);
    for(int i = cntDig - 1; i >= 0; i--){
        cout << digits[i];
        sumDig += digits[i];
    }
    cout << "\n" << sumDig << "\n";
}
int main(){
    int num; cin >> num;
    powerBase(num);
}
using namespace std;
void checkDiag(){
    int n; cin >> n;
    vector <vector <char> >matrix(n, vector <char> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    char Diag = matrix[0][0];
    for(int i = 0; i < n; i++){
        if(matrix[i][i] != Diag || matrix[i][n - i - 1] != Diag){
            cout << "No";
            return 0;
        }
    }
    char notDiag = matrix[0][1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && i + j != n - 1){
                if(matrix[i][j] != notDiag){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}
using namespace std;
// fill a matrix with alternating 'B' and 'W' characters, starting from the given positions marked with a dot ('.'). 
void fillChar(){
    int row, col; cin >> row >> col;
    cin.ignore();
    vector <string> matrix(row);
    for(int i = 0; i < row; i++){
        getline(cin, matrix[i]);
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == '.'){
                matrix[i][j] = ((i + j) % 2 == 0) ? 'B' : 'W';
            }
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
using namespace std;
const int N = 1010;
int w, n, dp[N][N], wt[N], item[N];
void KnapSack(){
    cin >> w >> n;
    for(int i = 1; i <= n; i++)
        cin >> wt[i] >> item[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < w; j++){
            //If the curr item isn't included, the value remains the same as when considering only the first (i - 1)items.
            dp[i][j] = dp[i - 1][j];
            if(j >= wt[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i]] + item[i]);
        }
    }
    cout << dp[n][w];
}
using namespace std;
//an array representing the number of additional sockets available from various devices. 
//Each device can contribute a certain number of additional sockets.
//determine how many of these devices you need to use to ensure that you have enough sockets to accommodate a given number of devices.
void mergesort(int *arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = left[i];
        k++; i++;
    }
    while(j < n2){
        arr[k] = right[j];
        k++; j++;
    }
}
void merge(int *arr, int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        merge(arr, l, mid);
        merge(arr, mid + 1, r);
        mergesort(arr, l, mid, r);
    }
}
int main(){
    //supply :The number of devices have to (or array elements)add.each supply device contibute some socket which is stored in arr
    //devices:(total number of devices) sockets: initial number of available sockets
    int supply, socket, device; cin >> supply >> socket >> device;
    int arr[supply];
    for(int i = 0; i < supply; i++)
        cin >> arr[i];
    merge(arr, 0, supply - 1);
    if(socket >= device)
        cout << 0;
    else{
        int i = 0;
        while(i < supply && device > socket){
            //atleast 1 socket connect with supply device.
            socket += arr[i] - 1;
            i++;
        }
        if(i != supply)
            cout << i;
        else if(socket >= device)
            cout << i;
        else
            cout << -1;
    }
}
using namespace std;
void Collatz Conjecture(){
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++){
        (x % 2 == 0) ? x /= 2 : x = 3 * x + 1;
        cout << x << " ";
    }
}
using namespace std;
//if the charge is less than 60% will take 1 minute to charge for every 1%. If the charge is less than 80%  will take 2 minute 
// And finally from 80% it will take 3 minutes .if the current charge is X% then how many minutes it will take to charge completely.
void cntMinute(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int minute[n];
    if(arr[i] >= 0 && arr[i] < 60)
        minute[i] = (60 - arr[i]) * 1;
    else if(arr[i] >= 60 && arr[i] < 80)
        minute[i] = (80 - arr[i]) * 2 + 40;
    else if(arr[i] >= 80 && arr[i] <= 100)
        minute[i] = (100 - arr[i]) * 3 + 140;
    for(int i = 0; i < n; i++)
        cout << minute[i] << " ";
}
using namespace std;
// determine how many 01 and 10 pair exist in the a string.
void pairMatch(){
    int n; cin >> n;
    string str; cin >> str;
    int cnt = 0;
    for(int i = 0, j = 1; str[j]; i++, j++){
        if((str[i] == '1' && str[j] == '0') || (str[i] == '0' && str[j] == '1')
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void binarySearch(){
    vector <int> vec {2, 6, 8, 10, 12, 14, 15, 18, 19, 28, 30};
    int low = 0, high = vec.size() - 1;
    int trg = 15, res = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == trg){
            res = mid;
            break;
        }
        else if(arr[mid] > trg)
             high = mid - 1;
        else
            low = mid + 1;
    }
    cout << res;
}
using namespace std;
void Diffrence(){
    int a, b; cin >> a >> b;
    if(a >= 0 && b >= 0 && a <= 100 && b <= 100){
        int dist = abs(a - b)
        cout << dist;
    }
}
using namespace std;
void pattern(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--)
            cout << j << " ";
        cout << "\n";
    }
}
// divide N among 3 people such that every person get the same amount. If possible give same amount to 3 people, print -1 otherwise print the amount.
void divideAgain(){
    int x; cin >> x;
    (x % 3 == 0)? cout << x / 3 ; cout << -1;
}
using namespace std;
//captain put the notebooks of girls first, and then the boys. captain should keep the boy's notebooks to the left side and then the girl's notebooks. 
//If the last index of a girl's notebook is K then can you print them in the right order? Note: If K is 0, that means there is no girl's notebook.
void divideThem(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int m; cin >> m;
    //girls notebook
    for(int i = m; i <= n; i++)
        cout << arr[i] << " ";
    //boys botebook
    for(int i = 0; i < m; i++)
        cout << arr[i] << " ";
}
using namespace std;
void fifaYear(){
    int year; cin >> year;
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        cout << "Yes";
    else
        cout << "No";
}
using namespace std;
void FirstLastIdx(){
    vector <int> arr{1, 2, 3, 3, 3, 4, 5, 6};
    int low = 0, high = arr.size() - 1;
    int trg = 3, firstIdx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == trg){
            firstIdx = mid;
            high = mid - 1;
        }
        else if(arr[mid] > trg)
            high = mid - 1;
        else
            low = mid + 1;
    }
    low = 0, high = arr.size() - 1;
    int lastIdx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == trg){
            lastIdx = mid;
            low = mid + 1;
        }
        else if(arr[mid] > trg)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << firstIdx << " " << lastIdx;
}
using namespace std;
// given an array of N positive integers. Find the maximum even value from the array. For finding, can perform only one of the following operations-
//Choose any even value from the array.
// Choose any two(must be different) values from the array and perform summation on those two values. If it will even you can pick those two values.
void pickValue(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    int res = ans = 0;
    int evenCnt = oddCnt = 2;
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] % 2 == 0 && evenCnt > 0){
            evenCnt--;
            res += arr[i];
        }
        else if(arr[i] % 2 == 1 && oddCnt > 0){
            oddCnt--;
            ans += arr[i];
        }
    }
    if(oddCnt > 0)
        cout << res;
    else
        cout << max(res, ans);
}
using namespace std;
//Count the total unique characters from the string
void cntUnique(){
    int arr[26] = {0}, cnt = 0;
    string str; cin >> str;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z')
            arr[str[i] - 'a']++;
        i++;
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] > 0)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
//count the total unique hand shakes
void cntHandShakes(){
    int n; cin >> n;
    int res = (n * (n - 1)) / 2;
    cout << res;
}
using namespace std;
//reorder a string letters in such a way that it becomes a palindrome
void createPalindrome(){
    string str;
    cin >> str;
    int n = str.length();
    vector<int> freq(27, 0);
    for (char ch : str){
        freq[ch - 'A' + 1]++;

    int oddValue = -1, totalCharCount = 0, odd = 0;
    char oddChar;

    for (int i = 1; i <= 26; ++i){
        if (freq[i] >= 1)
            totalCharCount++;
        if (freq[i] % 2 != 0){
            oddValue = freq[i];
            oddChar = i + 64;
            freq[i] = 0;
            odd++;
        }
    }
    // If more than one odd frequency, no solution
    if (odd > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int remainingChar = n;
    if (oddValue != -1){
        totalCharCount -= 1;
        remainingChar -= oddValue;
    }
    string firstHalf, secondHalf;
    // Create the palindrome halves
    for (int i = 1; i <= 26; ++i){
        if (freq[i] > 1){
            char evenChar = i + 64;
            int halfCount = freq[i] / 2;
            firstHalf.append(halfCount, evenChar);
            secondHalf.append(halfCount, evenChar);
        }
    }
    // Reverse the second half
    reverse(secondHalf.begin(), secondHalf.end());
    // Print the result
    cout << firstHalf;
    if (oddValue != -1){
        cout << string(oddValue, oddChar);
    }
    cout << secondHalf;
    return 0;
}
using namespace std;
void xossPatern(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << i;
        for(int j = 2; j <= n; j++){
            if(i == 1)
                cout << j;
            else if(i < n){
                if(j == n)
                    cout << n;
                else
                    cout << " ";
            }
            else
                cout << n;
        }
        cout << "\n";
    }
}
using namespace std;
bool Isvalid(){
    string str; cin >> str;
    stack <char> st;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else if(ch == ')' && !st.empty() && st.top() == '(')
            st.pop();
        else if(ch == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else if(ch == ']' && !st.empty() && st.top() == '[')
            st.pop();
        else
            st.push(ch);
    }
    (st.empty())? cout << "valid" : cout << "Invalid";
}
using namespace std;
bool Isvalid(string str){
    int n = str.size();
    bool found = true;
    vector <int> vec();
    for(int i = 0; i < n; i++){
        if((int)vec.size() == 0)
            vec.push_back(str[i]);
        else{
            char ch = vec.back();
            if(ch == '{' && str[i] == '}')
                vec.pop_back();
            else if(ch == '[' && str[i] == ']')
                vec.pop_back();
            else if(ch == '(' && str[i] == ')')
                vec.pop_back();
            else
                vec.push_back(str[i]);
        }
    }
    found = (vec.size() == 0) ? true : false;
    return found;
}
#include<bits/stdc++.h>
using namespace std;
// If b is added to twice a number, the sum will be sum. What is the number
void TwinNumber(){
    int sum, a, b; cin >> sum >> a;
    b = sum - a;
    cout << b / 2;
}
using namespace std;
//If a value of a matrix matches with the current row and column  add 3.
//If matches only the current row then add 2, If matches only the current column number then add 1 with the value.
void 2DOperation(){
    int row, col; cin >> row >> col;
    int arr[101][101];
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++)
            cin >> arr[i][j];
    }
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            if(i == arr[i][j] && j == arr[i][j])
                arr[i][j] += 3;
            else if(i == arr[i][j])
                arr[i][j] += 2;
            else if(j == arr[i][j])
                arr[i][j] += 1;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
using namespace std;
//return the square root of n rounded down the nearest integers
void sqrot(){
    int n; cin >> n;
    int low = 0, high = n - 1, res;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid * mid <= n){
            res = mid;
            low = mid + 1;
        }
        if(mid * mid > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << res;
}
using namespace std;
void searchVal(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int trg; cin >> trg;
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == trg){
            idx = i;
            break;
        }
    }
    (idx!= -1) ? cout << idx + 1 : cout << "Not Found";
}
using namespace std;
// a number would be a good secret code if no other number except 1 and N can divide that number. find out that number
void secretCode(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        int cnt = 0;
        if(arr[i] == 0 || arr[i] == 1)
            cnt++;
        for(int j = 2; j <= (arr[i] / 2); j++){
            if(arr[i] % j == 0){
                cnt++;
                break;
            }
        }
        (cnt == 0) ? cout << "Yes" : cout << "No";
    }
}
using namespace std;
void ReversePrint(){
    int n; cin >> n;
    stack <int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.push(x);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
using namespace std;
//each number [1 – 9] represent [A – I].But if the number is more than one digit it reverse itself.
void RevCode(){
    int n; cin >> n;
    while(n > 0){
        cout << char(64 + n % 10);
        n /= 10;
    }
}
using namespace std;
//given signs(plus or minus) consecutively. not one by one.count maximum of all signs which give sequentially
void plusMinus(){
    int n; cin >> n;
    string str; cin >> str;
    int cnt = 1, maxi = 1;
    for(int i = 1; i < n; i++){
        if(str[i] == str[i - 1])
            cnt++;
        else
            cnt = 1;
        if(maxi <= cnt)
            maxi = cnt;
    }
    cout << maxi;
}
using namespace std;
int peakIdx(vector <int> &vec){
    int res;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > vec[i - 1] && vec[i] > vec[i + 1]){
            res = i;
            break;
        }
    }
    cout << res;
}
using namespace std;
//If any player isn't able to make at least K runs he will be out of the team. Count number of players that will be out of the team
void outOfTeam(){
    int player, run; cin >> player >> run;
    int arr[player], cnt = 0;
    for(int i = 0; i < player; i++)
        cin >> arr[i];
    for(int i = 0; i < player; i++){
        if(arr[i] < run)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
// given a string consisting Add, Mult. next line will contain two positive values. Calculate the sum of every operations. 
void Operation(){
    string str; cin >> str;
    int a, b; cin >> a >> b;
    int res = 0;
    for(int i = 0; str[i]; i++){
        if(str[i] == '+')
            res = a + b;
        else if(str[i] == '*')
            res = a * b;
    }
    cout << res;
}
using namespace std;
const int N = 300;
void MissingSeqNum(){
    int n; cin >> n;
    int arr[N];
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        arr[x] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] != 1)
            cout << i << " ";
    }
}
using namespace std;
// Given the sum of four numbers and three of those numbers, find the missing number. All four numbers are positive integers
void MissingNum(){
    int sum, a, b, c; cin >> sum >> a >> b >> c;
    int res = sum - (a + b + c);
    cout << res;
}
using namespace std;
//If a word isn't a palindrome, print “Not Palindrome”.elseIfword is too long if its and length more than 7 characters.
//All too long words should be replaced with a special abbreviation.if it is plaindrome and length is less than or equal 7 characters.Then, print the word
void Ispalindrome(){
    string str; cin >> str;
    int IsPalindrome = 1, len = str.size();
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len - 1 - i]){
            IsPalindrome = 0;
            break;
        }
    }
    if(IsPalindrome){
        if(len > 7)
            cout << str[0] << " " << len - 2 << " " << str[len - 1];
        else
            cout << str;
    }
    else
        cout << "Not Palindrome";
}
using namespace std;
//Find the highest marks.and print the diffrence between another marks
void HighestMark(){
    int n; cin >> n;
    int mark[n];
    for(int i = 0; i < n; i++)
        cin >> mark[i];
    int tmp = mark[0];
    for(int i = 1; i < n; i++){
        if(tmp < mark[i])
            tmp = mark[i];
    }
    for(int i = 0; i < n; i++){
        cout << tmp - mark[i] << " ";
    }
}
using namespace std;
//modify an array so that it is increasing.every element at least as large as previous one.
//one each move you can increase the value of any element by one.what is the minimum move required.
void Incrarr(){
    int n; cin >> n;
    int arr[n], res = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1])
            res += arr[i - 1] - arr[i];
    }
    cout << res;
}
using namespace std;
bool IsPalindrome(string str){
    int n = str.size();
    int l = 0, r = n - 1;
    while(l < r){
        if(str[l] != str[r])
            return false;
        l++; r--;
    }
    return true;
}
bool IsPalindrome(string str){
    if(str == " " || str.size() == 1)
        return true;
    int n = str.size();
    string ing = str.substr(1, n - 1);
    return IsPalindrome(ing) && (str[0] == str.back())b;
}
