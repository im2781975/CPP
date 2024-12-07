using namespace std;
//Find the minimum difference between the largest & 2nd smallest and
//the difference between the second largest & the smallest element.
void FindMinDiff(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    if(n < 2){
        cout << "Not Enough Elements";
        return;
    }
    cout << "Minimum Diff is: " << min((vec[n - 1] - vec[1]), (vec[n - 2] - vec[0]));
}
using namespace std;
//calculates the difference between the sum of the max and sum of the min elements
void maxDiffrence(){
    int n; cin >> n;
    if(n < 2){
        cout << "Invalid Input";
        return;
    }
    int mid = n / 2;
    vector <int> vec(mid), cev(mid);
    for(int i = 0; i < mid; i++)
        cin >> vec[i];
    for(int i = 0; i < mid; i++)
        cin >> cev[i];
    sort(vec.begin(), vec.end())
    sort(cev.begin(), cev.end());
    int maxSum = vec[mid - 1] + cev[mid - 1];
    int minSum = vec[0] + cev[0];
    cout << maxSum - minSum;
}
using namespace std;
void multMaxInt(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int x = vec[n - 1] * vec[n - 2];
    int y = vec[0] * vec[1];
    (x >= y) ? cout << x : cout << y;
}
using namespace std;
//determines the minimum number of elements needed such that 
//their sum is greater than the sum of the remaining elements in the vector.
void CntElements(){
    int n; cin >> n;
    int sum = 0, cnt = 0, tmp = 0;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        vec.push_back(val);
        sum += val;
    }
    sort(vec.begin(), vec.end());
    for(int i = n - 1; i >= 0; i--){
        tmp += vec[i]; cnt++;
        if(tmp > (sum - tmp))
            break;
    }
    cout << "Maximum Sum elements Count are: " << cnt;
}
using namespace std;
//calculates the length of the longest contiguous subarray that excludes the min & max values
void lengthSubarr(){
    int n, res = 0; cin >> n;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    auto it = upper_bound(vec.begin(), vec.end(), vec[0]);
    int dist1 = it - vec.begin();
    it = lower_bound(vec.begin(), vec.end(), vec[vec.size() - 1]);
    it--;
    int dist2 = it - vec.begin();
    cout << "Diff between upper & lower bound is: " << max(res, dist2 - dist1 + 1);
}
using namespace std;
// Determine weither a vector decreasing or not
void IsDecreasing(){
    int n, m, val; cin >> n >> m;
    vector <int> vec, cev;
    for(int i = 0; i < n; i++){
        cin >> val; vec.push_back(val);
    }
    for(int i = 0; i < m; i++){
        cin >> val; cev.push_back(val);
    }
    sort(cev.begin(), cev.end(), greater <int> ());
    int j = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] == 0 && j < m){
            vec[i] = cev[j];
            j++;
        }
    }
    bool IsDecrease = true;
    for(int i = 1; i < n ; i++){
        if(vec[i] >= vec[i - 1])
            IsDecrease = false;
    }
    (IsDecrease)? cout << "Yes" : cout << "No";
}
using namespace std;
//find and print the absolute diff between consecutive elements, 
//the absolute diff between each element and the max & min values in the sequence, 
// the diff between the min and max values in the sequence.
void AbsDiff(){
    int x = INT_MIN, y = INT_MAX;
    int n, val; cin >> n;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        cin >> val; vec.push_back(val);
        x = max(x, val);
        y = min(y, val);
    }
    cout << abs(vec[0] - vec[1]) << "\n" << abs(vec[1] - x) << "\n";
    for(int i = 1; i < n - 1; i++){
        cout << min(abs(vec[i] - vec[i - 1]), abs(vec[i] - vec[i + 1])) << "\n";
        cout << max(abs(vec[i] - x), abs(vec[i] - y)) << "\n";
    }
    cout << abs(vec[n - 1] - vec[n - 2]) << "\n" << y - x;
}
using namespace std;
//count sequences of consecutive 'B's in a given string 
//and output the number of such sequences along with their lengths.
void cntConsecutiveLen(){
    int n, cnt = 0; cin >> n;
    string str; cin >> str;
    vector <int> vec;
    for(int i = 0; str[i]; i++){
        if(str[i] == 'B')
            cnt++;
        else if(cnt != 0){
            vec.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt != 0)
        vec.push_back(cnt);
    cout << vec.size() << " ";
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
using namespace std;
//counts consecutive zeros and outputs the length of
//longest such consecutive zero sequence for each test case
void cntZeroLen(){
    int n, cnt = 0; cin >> n;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0) cnt++;
        else if(cnt != 0){
            vec.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt > 0)
        vec.push_back(cnt);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
using namespace std;
// Determines whether it's possible to split a string of digits into two increasing subsequences. 
//If possible, outputs a vector indicating which subsequence each digit belongs to (1 or 2). else outputs "-".
void splitString(){
    int n; cin >> n;
    string str; cin >> str;
    bool found = false;
    for(int i = 0; i <= 9; i++){
        string a, b;
        vector <int> vec;
        bool validSplit = true;
        bool added = false;
        for(int j = 0; j < n; j++){
            int cur = str[j] - '0';
            if(cur > i){
                if(!a.empty() && a.back() > str[j]){
                    validSplit = false;
                    break;
                }
                vec.push_back(2);
                a += str[j];
                added = true;
            }
            else if(cur < i){
                if(!b.empty() && b.back() > str[j]){
                    validSplit = false;
                    break;
                }
                vec.push_back(1);
                b += str[j];
            }
            else{
                if(added){
                    if (!b.empty() && b.back() > str[j]) {
                        validSplit = false;
                        break;
                    }
                    vec.push_back(1);
                    b += str[j];
                }
                else{
                    if (!a.empty() && a.back() > str[j]) {
                        validSplit = false;
                        break;
                    }
                    vec.push_back(2);
                    a += str[j];
                    added = true;
                }
            }
        }
        if(validSplit){
            for(int i = 0; i < vec.size(); i++)
                cout << vec[i] << " ";
            found = true;
            break;
        }
    }
    if(!found)
        cout << "-";
}
using namespace std;
//print first positive and negetive integer
void print(){
    int n; cin >> n;
    vector <int> vec;
    int pos = neg = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > 0){
            if(pos == 0) pos = x;
            else vec.push_back(x);
        }
        else if(x < 0){
            if(neg == 0) neg = x;
            else vec.push_back(x);
        }
        //zero case
        else vec.push_back(x);
    }
    sort(vec.begin(), vec.end(), greater <int> ());
    //first positive number
    cout << 1 << " " << pos << "\n";
    if(neg != 0)
        cout << 1 << " " << neg << "\n";
    else{
        // If no negative number, select the last two elements from `vec`
        int a = vec.back(); vec.pop_back();
        int b = vec.back(); vec.pop_back();
        cout << 2 << " " << a << " " << b << "\n";
    }
    cout << vec.size() << " ";
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
using namespace std;
//takes three integer and determine if it's possible to represent sum of distinct integers from 1 to n excluding the integer x
void forbiddenInteger(){
    int sum, n, x; cin >> sum >> n >> x;
    vector <int> vec(n), res;
    for(int i = 0; i < n; i++)
        vec[i] = i + 1;
    for(int i = 0; i < n; i++){
        while(sum >= vec[i] && vec[i] != x){
            sum -= vec[i];
            res.push_back(vec[i]);
        }
    }
    if(sum == 0){
        cout << "Yes, size is: " << vec.size() << "\n";
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    }
    else
        cout << "No";
}
using namespace std;
//determine whether there exists a pair such that elements of the vector vec at those indices are equal (vec[i]==vec[j]),
//but the corresponding elements of the vector cev are different (cev[i]!=cev[j]). 
//If such a pair is found, the code outputs "Yes", otherwise it outputs "No".
void varifyPair(){
    int n, cnt = 0; cin >> n;
    vector <int> vec(n), cev(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    for(int i = 0; i < n; i++)
        cin >> cev[i];
    for(int i = 0; i < n; i++){
        int x = vec[i], y = cev[i];
        for(int j = 1; j < n; j++){
            if(vec[i] == x && cev[i] != y)
                cnt++;
        }
    }
    (cnt > 0) ? cout << "Yes" : cout << "No";
}
using namespace std;
//if contain odd or even or diffrence between consecutive odd or even print 'Yes' else 'No'
void containOddOrEven(){
    int n; cin >> n;
    vector <int> vec(n);
    bool hasOdd = hasEven = diffOdd = diffEven = false;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        if(vec[i] > 0)
            (vec[i] % 2 == 0) ?  hasEven = true :  hasOdd = true;
        if(i > 0){
            int diff = abs(vec[i] - vec[i - 1])
            if(diff > 0){
                (diff % 2 == 0) ? diffEven = true : diffOdd = true;
            }
        }
    }
    (hasOdd || hasEven || diffOdd || diffEven) ? cout << "Yes" : cout << "No";
}
using namespace std;
void Manipulate(){
    int n, k; cin >> n >> k;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    int res = 0;
    while(true){
        sort(vec.begin(), vec.end());
        if(vec[n - 1] > k)
            break;
        vec[1] += vec[0];
        vec[0] = 0;
        res++;
    }
    cout << "Number of operation: " << res << "\n";
    print(vec); cout << "\n";
    int trv = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            trv = i;
            break;
        }
    }
    cout << "First Even occuring idx is: " << trv << "\n";
    int mini = *min_element(vec.begin(), vec.end());
    int maxi = *max_element(vec.begin(), vec.end());
    cout << (mini != 1)? cout << maxi : cout << mini + 1;
    int cnt = 0;
    while(accumulate(vec.begin(), vec.end(), 0) > n){
        print(vec); cout << "\n";
        cout << "Sum is: " << accumulate(vec.begin(), vec.end(), 0) << "\n";
        for(int i = 0; i < n; i++){
            if(vec[i] > mini)
                vec[i] -= mini;
        }
        print(vec); cout << "\n";
        cnt++; break;
    }
    cout << "Count of iteration is: " << cnt + 1;
}
using namespace std;
//solve a problem involving selecting items with
// certain properties and minimizing the cost.
void MinimizeCost(){
    int n; cin >> n;
    vector <pair <int, string> >vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    int cnt01 = found01 = 0, cont01 = tmp1 = tmp2 = INT_MAX;
    for(int i = 0; i < n; i++){
        if(vec[i].second == "01"){
            cnt01++;
            cont01 = min(cont01, vec[i].first);
            found01 = 1;
        }
        else if(vec[i].second == "10"){
            cnt10++;
            cont10 = min(cont10, vec[i].first);
            found10 = 1;
        }
        else if(vec[i].second == "11"){
            cnt01++; cnt10++;
            tmp1 = min(tmp1, vec[i].first);
        }
    }
    if(found01 > 0 && found10 > 0)
        tmp2 = min(tmp2, cont01 + cont10);
    if(tmp1 == INT_MAX && tmp2 = INT_MAX)
        cout << -1;
    else
        cout << min(tmp1, tmp2);
}
using namespace std;
int Fact(int n){
    if(n == 0 || n == 1)
        return 1;
    return n * Fact(n - 1);
}
int main(){
    int n; cin >> n;
    cout << Fact(n);
}
using namespace std;
void CntDigit(){
    int n, cnt = 0; cin >> n;
    while(n != '\0'){
        n /= 10;
        cnt++;
    }
    cout << cnt;
}
using namespace std;
void LuckyDigit(){
    int x; cin >> x;
    int arr[] = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
    bool flag = false;
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if(x % arr[i]){
            flag = true;
            break;
        }
    }
    (flag)? cout << "Yes" : cout << "No";
}
using namespace std;
void reverse(){
    int n; cin >> n;
    int rev = 0;
    while(n!= '\0'){
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    cout << rev;
}
using namespace std;
//count 1's in Binary
int Binary(int n){
    int cnt = 0;
    while(n > 0){
        if(n % 2 == 1)
            cnt++;
        n /= 2;
    }
    return cnt;
}
int Hex(int n){
    int res = 0, cnt = 0;
    while(n > 0){
        res += (n % 10) * pow(16,  cnt++);
        n /= 10;
    }
    return Binary(res);
}
int main(){
    int n; cin >> n;
    cout << Hex(n);
}
using namespace std;
void SubArrSum(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int q; cin >> q;
    while(q--){
        int x, y, sum = 0; cin >> x >> y;
        //converst 1th based to 0th based idx
        x--; y--;
        if(x > y) swap(x, y);
        int maxi = x, mini = x;
        for(int i = x; i <= y; i++){
            sum += arr[i];
            if(arr[i] > maxi)
                maxi = i;
            if(arr[i] < mini)
                mini = i;
        }
    }
    cout << arr[maxi] << " " << arr[mini] << " " << sum;
}
using namespace std;
void BinToDecimal(){
    int n; cin >> n;
    int sum = 0, cnt = 0;
    while(n > 0){
        sum += (n % 10) * pow(2, cnt++);
        n /= 10;
    }
    cout << sum;
}
using namespace std;
//transform a given string into a palindrome with the minimum number of
//character changes & then output the number of changes
void TransformStr(){
    int n; cin >> n;
    char *str = new char[n + 1];
    cin >> str;
    if(strlen(str) != n){
        cout << "Size Mismatch";
        delete []arr;
        return 0;
    }
    int cnt = 0; //count transform
    int l = 0, r = n - 1;
    while(l < r){
        if(arr[l] != arr[r]){
            cnt++;
            if(arr[l] < arr[r])
                arr[r] = arr[l];
            else
                arr[l] = arr[r];
        }
        l++; r--;
    }
    cout << cnt << " " << str;
    delete []str;
}
using namespace std;
//Subtract n among a & b.in which player n will be zero,He will 
//be win.If neg another player will be win
void FindWinner(){
    int a, b, n; cin >> a >> b >> n;
    while(true){
        if(n >= __gcd(a, b))
            n -= __gcd(a, b);
        else{
            cout << "Second Win";
            break;
        }
        if(n >= __gcd(b, a))
            n -= __gcd(b, a);
        else
            cout << "First win";
            break;
    }
}
