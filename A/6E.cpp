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
using namespace std;
// Determine x can be written as the sum of two even numbers. If such pair found,print 'Yes' else 'No'.
void EvenPair(){
    int n; cin >> n;
    for(int i = 2; i < x; i+= 2){
        if((n - i) % 2 == 0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
using namespace std;
//Seperate into Even & Odd, and sort them.
void SeperateEvenOdd(){
    int n; cin >> n;
    int Ec = Oc = -1;
    int *Even = new int[n];
    int *Odd = new int[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 2 == 0)
            Even[Ec++] = x;
        else
            Odd[Oc++] = x;
    }
    if(Oc > -1){
        for(int i = Oc; i >= 0; i--)
            cout << Odd[i] << " ";
    }
    if(Ec > -1){
        for(int i = 0; i <= Ec; i++)
            cout << Even[i] << " ";
    }
    delete []Odd;
    delete []Even;
}
using namespace std;
void Manhatten(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int x; cin >> x;
            if(x == 1){
                cout << abs(i - 2) + abs(j - 2);
                return 0;
            }
        }
    }
}
void Manhatten(){
    int arr[5][5];
    int row, col;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                row = i; col = j;
            }
        }
    }
    cout << abs(row - 2) + abs(col - 2);
}
using namespace std;
//determine how many iterations takes for the length to become greater than breadth
void MakeEqual(){
    int len, breadth; cin >> len >> breadth;
    while(true){
        if(len > breadth)
            break;
        else{
            len *= 3;
            breadth *= 2;
            cnt++;
        }
    }
    cout << cnt;
}
//calculates the total width required to pass through a checkpoint based on their heights.
//Each person either takes 1 unit or 2 units of width depending on 
//whether they are taller than a specified height limit.
using namespace std;
void calculateWidth(){
    int num, limit; cin >> num >> limit;
    int width = 0
    for(int i = 0; i < num; i++){
        int height; cin >> height;
        if(height > limit)
            width += 2;
        else
            width += 1;
    }
    cout << width;
}
using namespace std;
//calculate how many sub-blocks can fit into a larger grid of size x * y, 
// and to account for any additional blocks needed if there are leftover spaces along the edges of the grid.
void calculateSubBlock(){
    int x, y, z; cin >> x >> y >> z;
    int a = x / z;
    int b = y / z;
    int cnt = a * b;
    if(x % z != 0)
        cnt += b;
    if(y % z != 0)
        cnt += a;
    if(x % z != 0 && y % z != 0)
        cnt += 1;
    cout << cnt;
}
using namespace std;
void BankersAlgo(){
    int num; cin >> num;
    vector <vector <int> >allocation(num, vector <int> (3));
    vector <vector <int> > maximum(num, vector <int> (3));
    vector <int> available(3);
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 3; j++)
            cin >> allocation[i][j];
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 3; j++)
            cin >> maximum[i][j];
    }
    for(int i = 0; i < 3; i++)
        cin >> available[i];
    vector <vector <int> >need(num, vector <int> (3));
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 3; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }
    vector <bool> finished(num, false);
    vector <int> safeseq;
    for(int k = 0; k < num; k++){
        bool found = false;
        for(int i = 0; i < num; i++){
            if(!finished[i]){
                bool canAllocate = true;
                for(int j = 0; j < 3; j++){
                    if(need[i][j] > available[j]){
                        canAllocate = false;
                        break;
                    }
                }
                if(canAllocate){
                    for(int j = 0; j < 3; j++)
                        available[j] += allocation[i][j];
                    safeseq.push_back(i);
                    finished[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "The system is not in a safe state\n";
            return 0;
        }
    }
    cout << "The system is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < safeseq.size(); i++) {
        cout << "P" << safeseq[i] + 1;
        if (i != safeseq.size() - 1) 
            cout << " -> ";
    }
    cout << endl;
}
using namespace std;
// determine if the total sums of three series of integers are all zero
void checkSum(){
    int n; cin >> n;
    int suma = sumb = sumc = 0;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        suma += a; sumb += b; sumc += c;
    }
    (suma == sumb == sumc == 0) ? cout << "Yes" : cout << "No";
}
using namespace std;
//counting occurrences of the integer 1 among three given numbers for each test case. 
void CountOne(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int cntOne = 0;
        for(int j = 0; j < 3; j++){
            int x; cin >> x;
            if(x == 1) cntOne++;
        }
        if(cntOne > 1)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
//Increment if positive else decreament.return count
void countPositive(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        char ch; cin >> ch;
        if(ch == '+')
            cnt++;
        if(ch == '-')
            cnt--;
    }
    cout << cnt;
}
void countPositive(){
    int n; cin >> n;
    int cnt = 0; char arr[3];
    for(int i = 0; i < n; i++){
        cin >> arr;
        int idx = 0;
        while(idx < 2){
            if(arr[idx] == '+'){
                cnt++;
                break;
            }
            if(arr[idx] == '-'){
                cnt--;
                break;
            }
            idx++;
        }
    }
    cout << cnt;
}
void countPositive(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        if(str.find('+') != string::npos)
            cnt++;
        if(str.find('-') != string::npos)
            cnt--;
    }
    cout << cnt;
}
using namespace std;
//determine if the square of l is less than or equal to half the square of r.
void IsEqual(){
    int l, r; cin >> l >> r;
    int x = l * l;
    int y = 0.5 * r * r;
    (x <= y) ? cout << "Yes": cout << "No";
}
using namespace std;
void collatzLength(int num){
    int len = 1;
    while(num > 1){
        if(num % 2 != 0)
            num = num * 3 + 1;
        else
            num /= 2;
        len++;
    }
    return len;
}
int main(){
    int start, end, maxL = -1;
    for(int i = start; i < end; i++){
        int len = collatzLength(i);
        if(len > maxL)
            maxL = len;
    }
    cout << maxL;
}
void collatzLength(){
    int x, y; cin >> x >> y;
    int maxi = 1;
    for(int i = x; i <= y; i++){
        int tmp = i, cnt = 1;
        while(tmp > 1){
            if(tmp % 2 != 0)
                tmp = tmp * 3 + 1;
            else
                tmp /= 2;
            cnt++;
        }
        if(cnt > maxi)
            maxi = cnt;
    }
    cout << maxi;
}
using namespace std;
//determine how many of these scores fall into specific ranges
//and then calculate and display the percentages of scores
void calculatePercent(){
    int n; cin >> n;
    int Top = Avg = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > 85){
            Top++; Avg++;
        }
        else if(x >= 60 && x < 85)
            Avg++;
    }
    double b = (Top / (n * 1.0) * 100);
    double c = (Top / (n * 1.0) * 100);
    ((b - int(b)) >= 0.5)? Top = int(b) + 1 : Top = int(b);
    ((c - int(c)) >= 0.5)? Avg = int(c) + 1 : Avg = int(c);
    //Top = round(b);
    //Avg = round(c);
    cout << Top << '%' << "\n" << Avg << '%';
}
using namespace std;
//determine the minimum number of boxes required to store a certain number of balls of  three different colors.
//Each type of ball has a specific quantity requirement based on a given integer n, and the boxes have a capacity of k balls.
void main(){
    int n, k; cin >> n >> k;
    int blue, green, red;
    blue = (8 * n) / k;
    green = (5 * n) / k;
    red = (2 * n) / k;
    if(8 * n % k != 0)
        blue += 1;
    if(5 * n % k != 0)
        green += 1;
    if(2 * n % k != 0)
        red += 1;
    /*blue = (8 * n + k - 1) / k;
    green = (5 * n + k - 1) / k;
    red = (2 * n + k - 1) / k;*/
    cout << blue + green + red;
}
using namespace std;
void GCD(int a, int b){
    if(b > a)
        return GCD(b, a);
    if(b == 0)
        return a;
    return GCD(b, a % b);
}
using namespace std;
//find the maximum sum of a contiguous subarray in an array
void maxSubarrSum(int *arr, int n){
    int maxi = INT_MIN, cursum = 0;
    for(int i = 0; i < n; i++){
        cursum += arr[i];
        if(cursum > maxi)
            maxi = cursum;
        if(cursum < 0)
            cursum = 0;
    }
    cout << maxi;
}
using namespace std;
void primeFactor(){
    int n; cin >> n;
    int cnt = 0;
    while(n % 2 == 0){
        cnt++;
        n /= 2;
    }
    for(int i = 3; i <= sqrt(n); i+= 2){
        while(n % i == 0){
            cnt++;
            n /= i;
        }
    }
    if(n > 2)
        cnt++;
    cout << cnt;
}
using namespace std;
//partition an number into two nearly equal parts.
void MakePartition(){
    int n; cin >> n;
    //Bitwise And operation if n becomes odd returns true(0011 & 0001 = 0001)
    if(n & 1)
        cout << n / 2 << " " << n / 2 + 1;
    else
        cout << n / 2;
}
using namespace std;
void sqrt(){
    int x; cin >> x;
    int res = 0;
    for(int i = 1 << 15; i > 0; i >>= 1){
        if((res + i) * (res + i) <= x)
            res += i;
    }
    cout << res << " ";
}
using namespace std;
//computes the binomial coefficient C(n,r) using a recursive
int fact(int n, int r, vector <vector <int> >dp){
    if(r > n) return 0;
    if(r == 0 || r == 1) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    // Use the recursive relation: nCr = (n-1)Cr + (n-1)C(r-1)
    dp[n][r] = fact(n - 1, r, dp) + fact(n - 1, r - 1, dp);
    return dp[n][r];
}
int main(){
    int n, r; cin >> n >> r;
    vector <vector <int> >dp(n, vector <int> (r + 1, 1))
    cout << fact(n, r, dp);
}
using namespace std;
void BubbleSort(){
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < arr[i + 1])
            continue;
        else
            cnt = -1;
    }
    if(cnt == 0){
        cout << "Ordered";
        return 0;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1- i; i++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void Bubblesort(){
    int n; cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(abs(arr[i]) > abs(arr[j]))
                swap(arr[i], arr[j]);
        }
    }
    for(int i = 0; i < n - 1; i++)
        cout << arr[i] << " ";
    cout << arr[n - 1] << " ";
}
using namespace std;
//count how many times a sequence is greater or less than the previous integer in the sequence.
void cntGreaterLess(){
    int n; cin >> n;
    int greater = 0, less = 0;
    int prv; cin >> prv;
    for(int i = 0; i < n; i++){
        int cur; cin >> cur;
        if(cur > prv)
            greater++;
        else if(cur < prv)
            less++;
        prv = cur;
    }
    cout << greater << " " << less;
}
using namespace std;
//count the consecutive integers that are divisors of n
//Find the max length of such consecutive divisors and prints this max length.
void cntMaxLen(){
    int n; cin >> n;
    int cnt = mxsz = 0;
    int sqrt_ = sqrt(n);
    for(int i = 1; i <= sqrt_; i++){
        if(n % i == 0)
            cnt++;
        else{
            mxsz = max(mxsz, cnt);
            cnt = 0;
        }
    }
    mxsz = max(mxsz, cnt);
    cout << mxsz;
}
using namespace std;
//Is the string contain NonZero
bool check(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i]!= '0')
            return true;
    }
    return false;
}
using namespace std;
//determines whether a vector of integers has any local maximum
//A local maximum is an element that is greater than its immediate neighbors
bool LocalMax(vector <int> vec){
    for(int i = 1; i < vec.size(); i++){
        if(i != vec.size() - 1){
            if(vec[i] > vec[i - 1] && vec[i] < vec[i + 1])
                return true;
        }
        return false;
    }
}
using namespace std;
bool IsSorted(vector <int> vec){
    for(int i = 1; i < vec.size(); i++){
        if(vec[i - 1] > vec[i])
            return false;
    }
    return true;
}
using namespace std;
//Find Kth element which is not divisible by n
void kthElement(){
    int n, k; cin >> n >> k;
    cout << k + ((k - 1) / (n - 1));
}
using namespace std;
//determine whether the Equity(even or odd nature) of the input
//matches the parity of their positions (index)
void checkEquity(){
    int num; cin >> num;
    int cur, idx = 1, cnt = 0;
    for(int i = 0; i < num; i++){
        cin >> cur;
        if((cur % 2 == 0 && idx % 2 == 0) || (cur % 2 != 0 && idx % 2 != 0))
            cnt++;
        idx++;
    }
    (cnt == num) ? cout << "Yes" : cout << "No";
}
using namespace std;
void Operation(){
    int n; cin >> n;
    vector <char> str(n);
    vector <double> dbl(n + 1);
    for(int i = 0; i < n; i++)
        cin >> str[i];
    for(int i = 0; i <= n; i++)
        cin >> dbl[i];
    for(int i = 0; i < n; i++){
        switch(str[i]){
            case '+': dbl[i + 1] = dbl[i] + dbl[i + 1]; break;
            case '-': dbl[i + 1] = dbl[i] - dbl[i + 1]; break;
            case '*': dbl[i + 1] = dbl[i] * dbl[i + 1]; break;
            case '/': 
                if(dbl[i + 1] != 0)
                    dbl[i + 1] = dbl[i] / dbl[i + 1];
                else{
                    cout << "Division By Zero";
                    return 1;
                }
                break;
            default:
                cout << "Invalid Operator";
                return 1;
        }
    }
    cout << dbl[n];
}
//print the unique integers in sorted order
void uniqueInt(){
    const int maxi = 1001;
    int n; cin >> n;
    vector <int> vec(maxi, -1);
    for(int i = 0; i < maxi; i++){
        int x; cin >> x;
        vec[x] = x;
    }
    for(int i = 0; i < maxi; i++){
        if(vec[i] != -1)
            cout << vec[i] << " ";
    }
}
using namespace std;
// check if there is any row or column in a grid that is  filled with '*'.
void fillChar(){
    char arr[10][10];
    int rowCnt[10] = {0}, colCnt[10] = {0};
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(arr[i][j] == '*')
                rowCnt++; colCnt++;
        }
    }
    for(int i = 0; i < 10; i++){
        if(rowCnt[i] == 10 || colCnt[i] == 10)
            cout << "Yes"
        else
            cout << "No";
    }
}
using namespace std;
// count the occurance of trg & print the first idx of trg
void cntPos(){
    int n, trg, pos = -1;
    int idx = cnt = 0;
    while(cin >> n >> trg && n > 0 && trg > 0){
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x == trg){
                if(cnt == 0)
                    pos = idx;
                cnt++;
            }
            idx++;
        }
    }
    (cnt == 0) ? cout << -1 : cout << pos << " " << cnt;
}
using namespace std;
//Count hididng places & positions in a grid which is represent by '#'
void hidingPlaces(){
    int row; cin >> row;
    if(row <= 0){
        cout << "Invalid input";
        return 0;
    }
    vector <string> grid(row);
    for(int i = 0; i < row; i++){
        cin >> grid[i];
        if(grid[i].length() != row){
            cout << "row didn't match";
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
    (cnt == 0)? cout << "No Hiding Places" : cout << "Hiding places are: " << cnt;
}
using namespace std;
//implementation of the modular exponentiation algorithm, which efficiently computes (a^b) % c
void Exponentiation(){
    int a, b, mod; cin >> a >> b >> mod;
    int res = 1;
    a %= mod;
    while(b){
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    cout << res;
}
using namespace std;
//compute the result of raising a base a to an exponent b under a modulus mod
bool powerMod(int a, int b, int mod){
    if(b == 0)
        return 1;
    int k = powerMod(a, b / 2, mod);
    k = (k * k) % mod;
    if(b & 1)
        k = (k * a) % mod;
    return k;
}
bool Isprime(int n, int iter = 5){
    if(n < 4)
        return n == 3 || n == 2;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    srand(time(nullptr));
    for(int i = 0; i < iter; i++){
        int a = 2 + rand() % (n - 2);
        if(powerMod(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
int main(){
    int num; cin >> num;
    (Isprime(num)) ? cout << "Yes": cout << "No";
    int a, b, mod; cin >> a >> b >> mod;
    cout << powerMod(a, b, mod);
}
using namespace std;
void Power(){
    int a, b; cin >> a >> b;
    int res = 1;
    while(b){
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    cout << res;
}
void FindSqrt(){
    int n; cin >> n;
    int l = 1, r = n;
    while(l > r){
        r = l + (r - l) / 2;
        l = n / r;
    }
    cout << r;
}
void countCeil(){
    int a, b; cin >> a >> b;
    (a % b == 0) ? cout << a / b : cout << a / b + 1;
}
using namespace std;
//Count the number of times the digit '2' appears in the loop
void cntTwo(){
    int res = 0;
    for(int i = 1; i <= 2020; i++){
        int tmp = i;
        while(tmp){
            cout << tmp << " ";
            if(tmp % 10 == 2)
                res++;
            tmp /= 10;
        }
    }
    cout << res;
}
//counts the number of pairs  within the range that are coprime (they share no common divisors other than 1).
using namespace std;
int gcd(int a, int b){
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main(){
    int cnt = 0;
    for(int i = 1; i <= 2020; i++){
        for(int j = 1; j <= 2020; j++){
            if(gcd(i, j) == 1)
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
//check if all numbers in the range [x,y], transformed by f(i)=i^2 + i + 41 result in prime numbers.if match outputs "ok"; else  "Break out".
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
    int x, y;
    while(cin >> x >> y && x != 0 && y != 0){
        bool flag = true;
        for(int i = x; i <= y; i++){
            if(!Isprime(i * i + i + 41)){
                flag = false;
                break;
            }
        }
        (flag) ? cout << "Ok" : cout << "Breakout";
    }
}
using namespace std;
//check if all numbers in the range [x,y], transformed by f(i)=i^2 + i + 41 result in prime numbers.if match outputs "ok"; else  "Break out".
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
    int x, y;
    while(cin >> x >> y && x != 0 && y != 0){
        bool flag = true;
        for(int i = x; i <= y; i++){
            if(!Isprime(i * i + i + 41)){
                flag = false;
                break;
            }
        }
        (flag) ? cout << "Ok" : cout << "Breakout";
    }
}
//Divide n in even pair
using namespace std;
void DivideEvenPair(){
    int n; cin >> n;
    for(int i = 2; i < n; i+= 2){
        if((n - i) % 2 == 0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
using namespace std;
//determine whether there exists an integer i in range[0, 65] such that the expression (n * i + 18) % 65 == 0 will true
void determineCond(){
    int n; cin >> n;
    bool flag = false;
    for(int i = 0; i < 66; i++){
        if((n * i + 18) % 65 == 0){
            flag = true;
            cout << i << " ";
            break;
        }
    }
    (flag) ? cout << "Yes" : cout << "No";
}
using namespace std;
//calculates the area of the smallest square that can completely cover two given rectangles on a 2D plane. 
void CoveredRect(){
    int x1, x2, x3, x4; cin >> x1 >> x2 >> x3 >> x4;
    int y1, y2, y3, y4; cin >> y1 >> y2 >> y3 >> y4;
    int a = max(x2, x4) - min(x1, x3);
    int b = max(y2, y4) - min(y1, y3);
    int c = max(a, b);
    cout << c * c;
}
using namespace std;
//wether sum of the three num less than two
void cond(){
    int n; cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        if((a + b + c) <= 2)
            res++;
    }
    cout << res;
}
#include <bits/stdc++.h>
//determine if a & b form an amicable pair. Amicable numbers are two different numbers so related that 
// the sum of the proper divisors (excluding the number itself) of each is equal to the other number

using namespace std;
int IsAmicable(int x){
    int res = 1;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            res += i;
            if(i != x / i)
                res += x /i;
        }
    }
    return res;
}
int main(){
    int a, b; cin >> a >> b;
    (IsAmicable(a) == b && IsAmicable(b) == a) ? cout << "Yes" : cout << "No";
}
using namespace std;
void timeAdd(){
    int Sec, Min, Hrs; cin >> Sec >> Min >> Hrs;
    int addHrs, addMin, addSec; cin >> addHrs >> addMin >> addSec;
    Sec += addSec;
    if(Sec >= 60){
        Min += Sec /60;
        Sec %= 60;
    }
    Min += addMin;
    if(Min >= 60){
        Hrs += Min / 60;
        Min %= 60
    }
    Hrs += addHrs;
    cout << "\nHours: " << Hrs << "\nMinutes: " << Min << "\nSecond: " << Sec;
}
using namespace std;
void Fibonacci(){
    int n; cin >> n;
    int a = 0, b = 1, c;
    for(int i = 0; i < n; i++){
        c = a + b;
        a = b; b = c;
    } 
    cout << c;
}
using namespace std;
//perform operations on the last two digits of two numbers & print the sum as the result
void operation(){
    int a, b; cin >> a >> b;
    a %= 100; b %= 100;
    a += b;
    cout << a % 100;
}
using namespace std;
//process a list of arithmetic operations and output their results in fraction format
void fractionFormat(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if(y == 0){
            cout << "Undefined";
            return 0;
        }
        else if(x % y == 0)
            cout << x / y << " ";
        else{
            int divi = __gcd(x, y);
            cout << x / divi << "/" << y / divi ;
        }
    }
}
using namespace std;
void BitManipulation(){
    int x = -2147483647;
    long z = 4294967296U;
    unsigned int y = static_cast <unsigned int> (x);
    cout << "x: " << x << "\n" << "y (unsigned version of x): " << y << "\n";
    cout << "z: " << z << "\n" << "z - (-x): " << z - (-x) << "\n";
    cout << "Enter integer for see binary rep: ";
    cin >> x;
    for(int i = 31; i >=0; i--){
        if(x & (1 << i))
            cout << "1";
        else
            cout << "0";
    }
    //set bits of a & b
    int a = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int b = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    int c = a | b;
    cout << "\nposition of " << c << " is: " ;
    for(int i = 0; i < 32; i++){
        if(c & (1 << i))
            cout << i << " ";
    }
}
using namespace std;
void CountSetBits(){
    int num, cnt = 0; cin >> num;
    while(num){
        cnt += (num & 1);
        num >>= 1;
    }
    cout << cnt;
}
using namespace std;
void BinConv(){
    int num; cin >> num;
    for(int i = 31; i >= 0; i--){
        if(num & (1 << i))
            cout << "1";
        else
            cout << "0";
    }
}
