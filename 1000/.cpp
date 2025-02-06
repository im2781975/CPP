using namespace std;
//wildcard
int main(){
    string str; int n;
    cin >> str >> n;
    vector <string> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    bool start = (str[0] == '*');
    bool end = (str[str.size() - 1] == '*');
    if(start && !end){
        string suffix = str.substr(1);
        for (const auto &word : vec){
            if (word.size() >= suffix.size() &&
                word.compare(word.size() - suffix.size(), suffix.size(), suffix) == 0)
                cout << word << "\n";
        }
    }
    else if(!start && end){
        string prefix = str.substr(0, str.size() - 1);
        for (const auto &word : vec) {
            if (word.size() >= prefix.size() &&
                word.compare(0, prefix.size(), prefix) == 0)
                cout << word << "\n";
        }
    }
    else{
        for (const auto &word : vec)
            cout << word << "\n";
    }
}
using namespace std;
// arrange a string characters in a square grid, and then prints them in a zigzag pattern (
int main(){
    string str; cin >> str;
    int len = ceil(sqrt(str.length()));
    while(str.length() < len * len)
        str += '.';
    for(int i = 0; i < len; i++){
        if(i % 2 == 0){
            for(int j = i * len; j < (i + 1) * len; j++)
                cout << str[j] << " ";
        }
        else{
            for(int j = (i + 1) * len - 1; j > i * len - 1; j--)
                cout << str[j] << " ";
        }
        cout << "\n";
    }
}
using namespace std;
//wildcard
int main(){
    int n; cin >> n;
    string str; cin >> str;
    int dv = str.find("*");
    string first = str.substr(0, dv);
    string sec = str.substr(dv + 1);
    int len = sec.length();
    vector <string> tmp;
    for(int i = 0; i < n; i++){
        string ing; cin >> ing;
        if(str.length() - 1 > ing.length())
            continue;
        string c = ing.substr(0, dv);
        string d = ing.substr(ing.length() - len);
        if(first == c && sec == d)
            tmp.push_back(ing);
    }
    for(int i = 0; i < tmp.size(); i++)
        cout << tmp[i] << " ";
}
using namespace std;
int delta(int x){
    if(x % 4 == 0) return x;
    if(x % 4 == 1) return 1;
    if(x % 4 == 2) return x + 1;
    return 0;
}
int main(){
    int x, y; cin >> x >> y;
    cout << delta(x - 1) ^ delta(y);
}
using namespace std;
int main(){
    string str, ing; cin >> str >> ing;
    int len1 = str.length(), len2 = ing.length();
    int maxL = max(len1, len2);
    vector <int> vec(maxL, 0), tor(maxL, 0), res(maxL + 1, 0);
    for(int i = 0; i < len1; i++)
        vec[len1 - 1 - i] = str[i] - '0';
    for(int i = 0; i < len2; i++)
        tor[len2 - 1 - i] = ing[i] - '0';
    int carry = 0;
    for(int i = 0; i < maxL; i++){
        sum = vec[i] + tor[i] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
    }
    if(carry > 0)
        res[maxL] = carry;
    int highestIndex = maxL;
    while (highestIndex > 0 && res[highestIndex] == 0)
        highestIndex--;
    for (int i = highestIndex; i >= 0; i--)
        cout << res[i] << " ";
}
using namespace std;
// identify the name that has the highest number of matching strings from a given list.
void FindStr() {
    int n; cin >> n;
    vector <string> vec(n);
    unordered_set <string> st;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        st.insert(vec[i]);
    }
    int m; cin >> m;
    vector <string> name(m);
    vector <int> src(m, 0);  
    for (int i = 0; i < m; i++) {
        cin >> name[i];
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            string str; cin >> str;
            if (st.count(str)) {
                src[i]++;
            }
        }
    }
    int maxIdx = 0;
    for (int i = 1; i < m; i++) {
        if (src[i] > src[maxIdx])
            maxIdx = i;
    }
    cout << name[maxIdx] << endl;
}
using namespace std;
int main(){
    int n; cin >> n;
    vector < pair < int, int> > pir(n);
    for(int i = 0; i < n; i++)
        cin >> pir[i].first >> pir[i].second;
    sort(pir.rbegin(), pir.rend());
    int mx = pr[0].second, res = 1;
    for(int i = 1; i < n; i++){
        if(pr[i].second > mx){
            mx = pr[i].second;
            res++;
        }
    }
    cout << res;
}
using namespace std;
int main(){
    string str; getline(cin, str);
    (str.find("molla") != -1) ? cout << str.find("molla") + 1 : cout << -1;
    double n; cin >> n;
    cout << fixed << setprecision(2) << (n - 1)/2 * n/2;
    int x, k; cin >> x >> k;
    cout << fixed << setprecision(5) << (1 / x) * (x - k - 1) / (x - 1);
}
using namespace std;
int main(){
    int n; cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    /*for(int i = 0; i < n / 2; i++)
        cout << arr[i] << "\n" << arr[n - 1 - i] << "\n";
    if(n % 2 != 0)
        cout << arr[n / 2] << "\n"; */
    if(n % 2 == 1){
        for(int i = 1; i <= n /2; i++)
            swap(arr[i], arr[n - i]);
    }
    else{
        for(int i = 1; i < n /2; i++)
            swap(arr[i], arr[n - i]);
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
using namespace std;
// process a list of n integers in groups of size k, adding the max value of each group plus 1 
//to an accumulator, and finally output the accumulated result.
int main(){
    int n, k; cin >> n >> k;
    int mx = 0, cnt = 0, res = 1;
    while(n--){
        cnt++;
        int x; cin >> x;
        mx = max(mx, x);
        if(cnt == k){
            res += mx + 1;
            mx = 0; cnt = 0;
        }
    }
    if(cnt > 0)
        res += mx + 1;
    cout << res;
}
using namespace std;
// determine whether a student, identified by their id, ranks within the top m students based on their scores in three subjects (sub1, sub2, and sub3).
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m; 
        // number of student & thereshold
        int id; cin >> id;
        vector <int> dent(n), sub1(n), sub2(n), sub3(n);
        for(int i = 0; i < n; i++)
            cin >> dent[i] >> sub1[i] >> sub2[i] >> sub3[i];
        for (int j = 0; j < n; j++) {
            if (id == dent[j]) { 
                for (int k = 0; k < n; k++) {
                    if (j == k) continue;  
                    if (sub3[k] > sub3[j] || 
                        (sub3[k] == sub3[j] && sub2[k] > sub2[j]) || 
                        (sub3[k] == sub3[j] && sub2[k] == sub2[j] && sub1[k] > sub1[j]))
                        rank++;
                }
                break; 
               
            }
        }
        (rank <= m) ? cout << "YA" : cout << "TIDAK" ;
    }
}
using namespace std;
int main(){
    int n, a, b; cin >> n >> a >> b;
    int x = n - (n * (a / 100));
    int y = x * (b / 100);
    cout << x + y;
}
using namespace std;
int main(){
    string str; getline(cin, str);
    string ing = "mollav ai";
    int i = 10, cnt = 0, res = 1;
    while(i--){
        if(str[i] == ing[i] || str[i] + 32 = ing[i])
            cnt++;
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'e'){
            if(str[i] == 'u') res *= 3;
            else res *= 2;
        }
    }
    cout << cnt << " " << res;
    string str, ing; cin >> str >> ing;
    cout << str + ing << "\n";
    int tmp = str.find(ing);
    if(tmp != -1)
        cout << "No";
    else
        cout << "Yes" << "\n" << str + "molla";
}
using namespace std;
void func(int n, int denom){
    if(n >= denom){
        cout << denom << " " << n / denom << "\n";
        n %= denom;
    }
}
int main(){
    int n; cin >> n;
    func(n, 1000);  func(n, 500);
    func(n, 200);   func(n, 100);
    func(n, 50);    func(n, 20);
    func(n, 10);    func(n, 5);
    func(n, 2);     func(n, 1);
}
using namespace std;
int main(){
    int n, m, x, y; cin >> n >> m >> x >> y;
    int a = (n / x) * (m / y);
    int b = (n / y) * (m / x);
    cout << max(a, b);
}
using namespace std;
int main(){
    int x, y, n; cin >> x >> y >> n;
    int arr[2006], res = 0;
    for(int i = 0; i < n * n; i++){
        if(arr[x] == 0){
            arr[x]++; res++;
        }
        int tmp = (x + y) % m;
        x = y; y = tmp;
    }
    cout << res;
}
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0){
            if(i % 3 == 0) cout << "Three";
            else if(i % 5 == 0) cout << "Five";
            else if(i % 7 == 0) cout << "seven";
        }
        else
            cout << " " << i;
    }
}
using namespace std;
int main(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n * 2; i++){
        int x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int res = 0, tmp = 2 * n - 1;
    for(int i = tmp; i >= n; i--)
        res += vec[i];
    cout << res;
}
using namespace std;
int main(){
    int n, prv = -1; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0 || x != prv)
            vec.push_back(x);
    }
    if(vec.size() < n) cout << "0";
    else if(vec.size() == n) cout << "1";
    else cout << n + 1;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10000], n; cin >> n;
    vector <int> vec[10000];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vec[arr[i]].push_back(x);
    }
    priority_queue <int> pq;
    for(int i = 10000; i >= 1; i--){
        for(auto j : vec[i])
            pq.push(j);
        if(!pq.empty()){
            res += pq.top(); pq.pop();
        }
    }
    cout << res;
}
using namespace std;
void main(){
    int n, d, a; cin >> n >> d >> a;
    int cur = a, res = 1;
    for(int i = 1; i < n; i++){
        cin >> a;
        if(a - cur >= d)
            res++;
        cur = a;
    }
    cout << res;
}
using namespace std;
int main(){
    int cur; cin >> cur;
    int peak = lowest = prv = cur;
    int maxDiff = 0, nxtVal;
    while(cin >> nxtVal){
        if(nxt > prv){
            peak = nxt;
            maxDiff = max(maxDiff, peak - lowest);
        }
        else if(nxt < prv){
            lowest = nxt;
            maxDiff = max(maxDiff, abs(lowest - peak));
        }
        prv = nxt;
    }
    cout << maxDiff;
}
using namespace std;
int main(){
    int n; cin >> n;
    pair <int, int> pir[n];
    for(int i = 0; i < n; i++)
        cin >> pir[i].first >> pir[i].second;
    sort(pir, pir + n);
    int cur = n - 2;
    for(int i = n - 1; i >= 0; i--){
        if(i == cur) cur--;
        while(pir[i].first == pir[cur].first){
            if(pir[i].second > pir[cur].second)
                pir[cur].first--;
            else
                pir[i].first--;
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(pir[i].first != 0)
            res += pir[i].second;
    }
    cout << res;
}
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n][1000];
    for(int i = 0; i < n; i++)
        cin >> arr[0][i];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = arr[i - 1][j + 1] - arr[i - 1][j];
    }
    for(int i = 0; i < n; i++)
        cout << arr[i][0] << " ";
}
using namespace std;
int main(){
    int n; cin >> n;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n / 2; i++)
        cout << vec[i] << "\n" << vec[n - 1 - i];
    if(n % 2 != 0)
        cout << vec[n / 2];
}
using namespace std;
int main(){
    int x, y, mn; cin >> x >> y;
    int mx = (x - y) / 4;
    if(x > 5 * y || y > x)
        cout << -1;
    else{
        if(x <= 4 * y)
            mn = 0;
        else
            mn = x - 4 * y;
    }
    cout << mn;
}
using namespace std;
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int main(){
    int x, y; cin >> x >> y;
    if(x % y != 0){
        cout << -1;
        return 0;
    }
    int a, b, tmp = x / y;
    for(int i = 1; i <= sqrt(tmp); i++){
        if(gcd(i, tmp/i) == 1 && tmp % i == 0){
            a = i; b = tmp / i;
        }
    }
    cout << a * x << " " << b * x;
}
using namespace std;
int main(){
    int a, b; cin >> a >> b;
    int gcd = __gcd(a, b);
    int lcm = a * b/gcd;
    cout << (lcm / a) + (lcm / b);
}
using namespace std;
int main(){
    int n, cnt = 1; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    string str; str += "G";
    n = n / 2 + 1;
    while(cnt++ < n)
        str += "LG";
    cout << str.size() << "\n" << str;
}
using namespace std;
int solve(int x){
    if(x <= 1)
        return 1;
    else
        return solve(x / 2) * 2 + x;
}
using namespace std;
int main(){
    int n, m, ans = 0; cin >> n >> m;
    vector <int> freq(10005, 0);
    vectror <pair <int, int> >range;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        range.push_back({r, l});
    }
    sort(range.begin(), range.end());
    for(int i = 0; i < m; i++){
        int l = range[i].second;
        int r = range[i].first;
        for(int j = l; j <= r; j++){
            if(freq[j] > 0){
                freq[j]--;
                ans++;
                break;
            }
        }
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int num, maxDiff, Query; cin >> num >> maxDiff >> Query;
    vector <pair <int, int> >twin(num + 1);
    for(int i = 1; i <= num; i++){
        cin >> twin[i].first;
        twin[i].second = i;
    }
    sort(twin.begin() + 1, twin.end());
    priority_queue <pair <int, int> > pq;
    vector <int> res(num + 1, 0);
    for (int i = 1, j = 1; i <= num; i++) {
        while (j <= num && twin[j].first - twin[i].first <= maxDiff)
            j++;
        j--;
        pq.push({j - i + 1, j});
        while (pq.top().second < i)
            pq.pop();
        res[twin[i].second] = pq.top().first;
    }
    for (int i = 0; i < Query; i++) {
        int idx; cin >> idx;
        cout << res[idx] << endl;
    }
}
using namespace std;
int main(){
    int n; cin >> n;
    string str; cin >> str;
    vector <int> vec(26, 0);
    for(int i = 0; i < n; i++)
        vec[str[i] - 'A']++;
    sort(vec.begin(), vec.end());
    int a = vec[25], b = vec[24], c = [23];
    if(c == 0){
        cout << -1;
        return 0;
    }
    int res = 3 * c;
    if(a > c) res++;
    if(b > c) res++;
    cout << res;
}
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    pair <int, int> twin[n];
    int arr[k];
    for(int i = 0; i < n; i++)
        cin >> twin[i].first >> twin[i].second;
    for(int i = 0; i < k; i++)
        cin >> arr[i];
    sort(twin, twin + n); sort(arr, arr + k);
    int r = n - 1, res = i = 0;
    while(r >= 0){
        if(twin[i].second > 0){
            res += twin[i].first * arr[r];
            r--; twin[i].second--;
        }
        else
            i++;
    }
    cout << res;
}
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        int l = 0, r = n - 1;
        bool flag = 0;
        while(l < r){
            int sum = arr[l] + arr[r];
            if(sum == x){
                flag = 1; break;
            }
            else if(sum < x) l++;
            else r--;
        }
    }
    (flag) ? cout << "Yes" : cout << "No";
}
using namespace std;
int main() {
    int n, x, y; cin >> n >> x >> y;
    int s = abs(x), r = abs(y);
    int t = s + r;   
    // Minimum required moves (Manhattan distance)
    if (t > n) {
        cout << -1;
        return 0;
    }
    // If the remaining moves (n - t) is odd, we cannot distribute evenly
    if ((n - t) % 2 != 0) {
        cout << -1;
        return 0;
    }
    int extraMoves = (n - t) / 2;
    // Assign moves
    int a = (y >= 0) ? r + extraMoves : extraMoves;
    int c = (y < 0) ? r + extraMoves : extraMoves;  
    int b = (x >= 0) ? s + extraMoves : extraMoves; 
    int d = (x < 0) ? s + extraMoves : extraMoves; 
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
using namespace std;
int main(){
    int n, a, b; cin >> n >> a >> b;
    int lcm = a * b/__gcd(a, b);
    cout << lcm / a + lcm / b;
}
using namespace std;
int main(){
    int a, b; cin >> a >> b;
    int mx = max(a, b), mn = min(a, b);
    while(mx % mn != 0){
        int tmp = mx - mn;
        mx = max(mn, tmp);
        mn = min(mn, tmp);
    }
    cout << mn;
}
using namespace std;
int main(){
    int n, a, b, c; cin >> n >> a >> b >> c;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        (x % a == 0 && x % b == 0 && x % c == 0) ? cout << "YA\n" : cout << "No\n";
    }
}
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int arr[n]; cin >> arr[0];
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        arr[i] = arr[i - 1] + x;
    }
    for(int i = 0; i < k; i++){
        int y; cin >> y;
        cout << upper_bound(arr, arr + n, y) - arr;
    }
}
using namespace std;
int main(){
    int n; cin >> n;
    multiset <int> mset;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(mset.lower_bound(x) != mset.end())
            mset.erase(mset.lower_bound(x));
        mset.insert(x);
    }
    cout << mset.size();
}
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    (n % m == 0) ? cout << "Yes" : cout << "No";
}
using namespace std;
int main(){
    int n; cin >> n;
    if(n % 4 == 0) cout << "Yes";
    else if(n % 2 == 0) cout << "No";
    else{
        ((n - 1) % 4 == 0) cout << "No" : cout << "Yes";
    }
}
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            (j % 2 == 0) ? cout << "W" : cout << "B";
        }
    }
}
using namespace std;
int main(){
    int n, m, x, y; cin >> n >> m >> x >> y;
    int res = (n - x) + (m - y) * 2;
    (res > 20) ? cout << "Yes": cout << "No";
}
using namespace std;
int main(){
    int m, a, b; cin >> m >> a >> b;
    if(a + b == 2 * m){
        (a % 2 == 1 && b % 2 == 1) ? cout << "1" : cout << "0";
        cout << min(a, b);
    }
    else
        cout << "0" << " " << min(a, b);
}
using namespace std;
int main(){
    int n; cin >> n;
    cout << (n % 10 ? cout << "Yes": cout << "No");
}
using namespace std;
int main(){
    int n, cnt = 1; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt *= x;
    }
    cout << cnt;
}
using namespace std;
int main(){
    int n; cin >> n;
    char ch[26];
    vector <bool> visited(n, false);
    vector <char> arr(n);
    vector <int> vec(n), res(n);
    for(int i = 0; i < 26; i++)
        ch[i] = 'a' + i;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(arr[i] == ch[j]){
                vec[i] = j + 1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        int minIdx = -1;
        for(int j = 0; j < n; j++){
            if(!visited[j] && (minIdx == - 1 || vec[j] < vec[minIdx]))
                minIdx = j;
        }
        res[minIdx] = n - i;
        visited[minIdx] = true;
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
// output the sequence of unique number
using namespace std;
int main(){
    int n; cin >> n;
    int arr[1001] = {0}, unique[n], cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(arr[x] == 0){
            arr[x] = 1;
            unique[cnt++] = x;
        }
    }
    for(int i = 0; i < cnt; i++)
        cout << unique[i] << " ";
}
using namespace std;
//find index
int main(){
    int n, trgIdx; cin >> n >> trgIdx;
    int arr[n], cnt = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(arr[trgIdx - 1] == 0){
        for(int i = 0; i < n; i++){
            if(arr[i] > 0) cnt++;
        }
    }
    else{
        cnt = trgIdx;
        for(int i = trgIdx; i < n; i++){
            if(arr[trgIdx - 1] <= arr[i])
                cnt++;
        }
    }
    cout << cnt << "\n" << arr[TrgIdx - 1] << "\n";
    (trgIdx < n) ? cout << arr[trgIdx] : cout << "Idx OutOfBound";
}
using namespace std;
//Findpos
int main(){
    int row, col, cnt = 0, mini = INT_MAX, MinRow = -1, MinCol = -1;
    cin >> row >> col;
    char arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j <col; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == 'E'){
                int dist = i + j;
                if(distance < mini){
                    //convert to 1-Based Idx
                    MinRow = i + 1;
                    MinCol = j + 1;
                }
                cnt++;
            }
        }
    }
    (cnt == 0) ? cout << -1 : cout << MinRow << " " << MinCol;
}
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = n; i > 0; i--){
        int cnt = 0;
        for(int j = n; j > 0; j--){
            for(int k = n; k > 0; k--){
                if(k * k + j * j == i * i)
                    cnt++;
            }
        }
        if(cnt == 2){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
using namespace std;
int main(){
    int a, b, c; cin >> a >> b >> c;
    int mx = max(a, max(b, c));
    for(int i = mx; i <= 100; i++){
        if(i % a != 0 && i % b != 0 && i % c != 0){
            cout << i;
            break;
        }
    }
}
using namespace std;
int main(){
    double d; cin >> d;
    cout << fixed << setprecision(1) << n *(n + 1) /2;
    int n, m, r; cin >> n >> m >> r;
    int mn = min(n, m);
    cout << (mn - 1) / (2 * r + 1) + 1;
}
using namespace std;
int main(){
    int p, q, r, s, t; cin >> p >> q >> r >> s >> t;
    int x = sqrt(p * q * r * s * t);
    cout << x / (q * s) << " " << x / (r * t) << " " << x / (p * s) << " " << x / (q * t) << " " << x / (p * r);
}
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    bool isDecr = false, isIncr = false, isEqual = false;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0){
            if(arr[i] < arr[i - 1]) isDecr = true;
            else if(arr[i] > arr[i - 1]) isIncr = true;
            else isEqual = true;
        }
    }
    if(isIncr && isDecr) cout << "NONE";
    else if (isEqual){
        if(isDecr) cout << "NONINCREASING";
        else if (isIncr) cout << "NONDECREASING";
        else cout << "EQUAL";
    }else if (hasIncrease) cout << "NONDECREASING";
    else if (hasDecrease) cout << "NONINCREASING";
    else cout << "NONE";
}
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    cout << n + (n - 3) - m;
    int ans = 1;
    for(int i = 1; i <= n * m - 1; i++)
        ans *= 2;
    cout << ans;
}
using namespace std;
int main(){
    int n; cin >> n;
    if(n >= 100)
        cout << 9;
    else if(n >= 19 && n <= 99){
        string str = to_string(n);
        if(str[1] == '9')
            cout << n / 10;
        else
            cout << n / 10 -1;
    }
    else
        cout << "0";
}
using namespace std;
int main(){
    int n; cin >> n;
    int a = b = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(n > 2){
            a += x * pow(-1, i % 2);
            b += x * pow(-1, (i + 1) % 2);
        }
        else{
            b += x * pow(-1, (i + 1) % 2);
            a = INT_MIN;
        }
    }
    cout << max(a, b);
}
using namespace std;
int main(){
    int a, b; cin >> a >> b;
    int arr[a][b];
    int x, y = z = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1) x = (i + j) % 2;
            else if((i + j) % 2 == 0) y += arr[i][j];
            else z += arr[i][j];
        }
    }
    if(x == 0)
        (y > z)? cout << "No\n" : cout << "Yes\n" << z - y;
    else
        (y < z)? cout << "No\n" : cout << "Yes\n" << y - z;
}
using namespace std;
int main(){
    int n; cin >> n;
    int tmp = 2, cnt = 0;
    while(tmp <= n)
        tmp *= 2;
    cout << tmp - n;
    int x, y; cin >> x >> y;
    int mn = min(x, y), mx = max(x, y);
    cout << (mn - 1) * mx;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        cout << 2 * min(a, b);
}
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int arr[n], cnt = 0;
    for(int i = 1; i <= n; i++)
        arr[i] = 0;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        arr[x] = (arr[x] + 1) % 4;
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] == 2 || arr[i] == 3)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
int main(){
    int n; cin >> n;
    int even = odd = 0;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if((x + y) % 2 == 0) even++;
        else odd++;
    }
    (even == 0 || odd == 0) ? cout << "No" : cout << "Yes";
}
using namespace std;
int main(){
    string str; cin >> str;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'o') cnt++;
        if(cnt > 1) break;
    }
    (cnt == 1) ? cout << "Yes" : cout << "No";
}
using namespace std;
int main(){
    int n; cin >> n;
    double r, v; cin >> r >> v;
    int arr[n];
    for(int i = 0; i < n; i++){
        if(arr[i] == v){
            cout << "-1";
            return 0;
        }
    }
    double res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, r / abs(arr[i] - v));
    cout << setprecision(9) << res;
}
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)   
        cin >> arr[i];
    int id = 0;
    while(id < n && arr[id] == 1)
        id++;
    id %= n;
    int i = id, res = 0, cnt = 0;
    do{
        if (arr[i] == 1){
            cnt++;  
            res += cnt;
        }else cnt = 0;
        i = (i + 1) % n;
    }while (i != id);
    cout << res << endl;
}
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int cnt = 1, res = 0;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        if(cnt < l){
            res += abs(cnt - l);
            cnt = l;
        }
        else if(cnt > r){
            res += abs(cnt - r);
            cnt = r;
        }
    }
    cout << res;
}
