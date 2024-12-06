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
