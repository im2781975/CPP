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

