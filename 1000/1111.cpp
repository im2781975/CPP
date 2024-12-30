using namespace std;
int main() {
    string str; 
    int n; cin >> str >> n;
    cin >> str >> n;      
    vector <string> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    // Check the position of the wildcard '*' in the pattern
    bool startsWith = (str[0] == '*');
    bool endsWith = (str[str.size() - 1] == '*');

    if (startsWith && !endsWith) { // Case: *suffix
        string suffix = str.substr(1); 
        // Remove '*' to get the suffix
        for (const auto& word : vec){
            if (word.size() >= suffix.size() &&
                word.compare(word.size() - suffix.size(), suffix.size(), suffix) == 0)
                cout << word << endl;
        }
    } else if (!startsWith&& endsWith) { 
        // Case: prefix*
        string prefix = k.substr(0, k.size() - 1); 
        // Remove '*' to get the prefix
        for (const auto& word : vec) {
            if (word.size() >= prefix.size() &&
                word.compare(0, prefix.size(), prefix) == 0)
                cout << word << endl;
        }
    } else { 
        // Case: No wildcard or invalid pattern
        for (const auto& word : vec)
            cout << word << endl;
    }
    return 0;
}
using namespace std;
void solve() {
    string s;
    cin >> s;
    if (s == "PAS") {
        // Pascal code generation
        cout << "var data: array[1..10000] of longint;" << endl;
        cout << "    n, i, j, temp: longint;" << endl;
        cout << "begin" << endl;
        cout << "    readln(n);" << endl;
        cout << "    for i := 1 to n do readln(data[i]);" << endl;
        cout << "    for i := 1 to n - 1 do" << endl;
        cout << "        for j := i + 1 to n do" << endl;
        cout << "            if (data[i] > data[j]) then" << endl;
        cout << "            begin" << endl;
        cout << "                temp := data[i];" << endl;
        cout << "                data[i] := data[j];" << endl;
        cout << "                data[j] := temp;" << endl;
        cout << "            end;" << endl;
        cout << "    for i := 1 to n do writeln(data[i]);" << endl;
        cout << "end." << endl;
    } else {
        // C code generation
        cout << "#include <stdio.h>" << endl;
        cout << "int data[10001];" << endl;
        cout << "int n, i, j, temp;" << endl;
        cout << "int main() {" << endl;
        cout << "    scanf(\"%d\", &n);" << endl;
        cout << "    for (i = 1; i <= n; i++) scanf(\"%d\", &data[i]);" << endl;
        cout << "    for (i = 1; i <= n - 1; i++)" << endl;
        cout << "        for (j = i + 1; j <= n; j++)" << endl;
        cout << "            if (data[i] > data[j]) {" << endl;
        cout << "                temp = data[i];" << endl;
        cout << "                data[i] = data[j];" << endl;
        cout << "                data[j] = temp;" << endl;
        cout << "            }" << endl;
        cout << "    for (i = 1; i <= n; i++) printf(\"%d\\n\", data[i]);" << endl;
        cout << "    return 0;" << endl;
        cout << "}" << endl;
    }
}
// Pola string
using namespace std;
void main(){
    string str; cin >> str;
    int len = ceil(sqrt(str.length()));
    for(int i = str.length(); i < len * len; i++)
        str[i] += ".";
    for(int i = 0; i < len; i++){
        if(i % 2 == 0){
            for(int j = i * len; j < (i + 1) * len; j++)
                cout << str[j] << " ";
        }
        else{
            for(int j = (i + 1)* len - 1; j > i * len - 1; j--)
                cout << str[j] << " ";
        }
    }
}
// wildcard
using namespace std;
int main(){
    int n; cin >> n;
    string str, tmp[n]; cin >> str;
    string bg = str.find("*");
    string x = str.substr(0, bg);
    string y = str.substr(bg + 1);
    int len = y.length();
    for(int i = 0; i < len; i++){
        string ing; cin >> ing;
        if(str.length() - 1 > ing.length())
            continue;
        string c = ing.substr(0, bg);
        string d = ing.substr(str.length() - len, len);
        if(x == c && y == d)
            tmp[i] = ing;
    }
    for(int i = 0; i < n; i++)
        cout << tmp[i] << " ";
}
using namespace std;
int newNum(int x){
    if(x % 4 == 0)
        return x;
    if(x % 4 == 1)
        return 1;
    if(x % 4 == 2)
        return x + 1;
    return 0;
}
int main(){
    int x, y; cin >> x >> y;
    cout << newNum(x - 1) ^ newNum(y);
}
void FindStr(){
    int n; cin >> n;
    vector <string> vec(n);
    for(int i = 0; i < n; i++)
        cout << vec[i];
    int m; cin >> m;
    vector <string> name(m);
    vector <int> src(m, 0);
    for(int i = 0; i < m; i++){
        cin >> name[i];
        int x; cin >> x;
        for(int j = 0; j < x; j++){
            string str; cin >> str;
            for(int k = 0; k < n; k++){
                if(str == vec[k])
                    src[i]++;
            }
        }
    }
    int maxIdx = 0;
    for(int i = 1; i < m; i++){
        if(src[i] > src[maxIdx])
            maxIdx = i;
    }
    cout << name[maxIdx];
}
using namespace std;
void main(){
    int n; cin >> n;
    vector <pair <int, int> >pr(n);
    for(int i = 0; i < n; i++)
        cin >> pr[i].first << " " << pr[i].second;
    sort(pr.rbegin(), pr.rend());
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
void main(){
    string str; getline(cin, str);
    if(str.find("molla") != -1)
        cout << str.find("molla") + 1;
    else
        cout << -1;
}
using namespace std;
void main(){
    double n; cin >> n;
    cout << fixed << setprecision(2) << (n - 1)/2 * n/2;
}
using namespace std;
void main(){
    int n, k; cin >> n >> k;
    cout << fixed << setprecision(5) << (1 / n) *(n - k - 1) / (n - 1);
}
using namespace std;
void main(){
    int n; cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++){
        res += i;
        cout << res;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    /*
    for(int i = 0; i < n / 2; i++)
        cout << arr[i] << "\n" << arr[n - 1 - i] << "\n";
    if(n % 2 != 0)
        cout << arr[n / 2] << "\n";
    */
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
void main(){
    int n, k; cin >> n >> k;
    int ans = 1, mx = 0, cnt = 0;
    while(n--){
        cnt++;
        int x; cin >> x;
        mx = max(mx, x);
        if(cnt == k){
            ans += mx + 1;
            cnt = mx = 0;
        }
    }
    if(cnt > 0)
        ans += mx + 1;
    cout << ans;
}
using namespace std;
void main(){
    int n, a, b; cin >> n >> a >> b;
    int x = n *(a / 100);
    int y = n - x;
    int z = y * b/100;
    cout << y + z;
}
using namespace std;
void main(){
    string res = "molla vai";
    string str; getline(cin, str);
    int i = 10, cnt = 0;
    while(i--){
        if(str[i] == res[i] || str[i] + 32 = res[i])
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void main(){
    string str; getline(cin, str);
    int res = 1, len = str.length;
    for(int i = 0; i < len; i++){
        if(str[i] == 'e'){
            if(str[i] == 'u')
                res *= 3;
            else
                res *= 2;
        }
    }
    cout << res;
}
using namespace std;
void processDenom(int n, int denom){
    if(n >= denom){
        cout << denom << " " << n / denom << "\n";
        n %= denom;
    }
}
int main(){
    int n; cin >> n;
    processDenom(n, 1000);
    processDenom(n, 500);
    processDenom(n, 200);
    processDenom(n, 100);
    processDenom(n, 50);
    processDenom(n, 20);
    processDenom(n, 10);
    processDenom(n, 5);
    processDenom(n, 2);
    processDenom(n, 1);
}
using namespace std;
void main()
{
    string num1, num2, digit1, digit2;
    vector<short> vec1, vec2, result;
    short i, carry, len1, len2, maxLength;
    short temp;
    cin >> num1 >> num2;
    len1 = num1.length();
    len2 = num2.length();
    maxLength = max(len1, len2);
    
    vec1.resize(100000);
    vec2.resize(100000);
    result.resize(maxLength + 1);

    for (i = 0; i < len1; i++){
        digit1 = num1[i];
        vec1[len1 - 1 - i] = stoi(digit1);
    }
    // Reverse and store digits of num2
    for (i = 0; i < len2; i++)
    {
        digit2 = num2[i];
        vec2[len2 - 1 - i] = stoi(digit2);
    }
    // Perform addition with carry
    carry = 0;
    for (i = 0; i <= result.size(); i++){
        result[i] = vec1[i] + vec2[i] + carry;
        carry = result[i] / 10;
        result[i] = result[i] % 10;
    }
    // Find the highest non-zero index in result
    for (i = result.size() - 1; i >= 0; i--){
        if (result[i] > 0)
            break;
    }
    // Print the result in reverse order
    for (short j = i; j >= 0; j--)
        cout << result[j];
}
using namespace std;
void main(){
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    int a = n / a * m / b;
    int b = n / b * m / a;
    cout << max(a, b);
}
using namespace std;
void main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0){
            if(i % 3 == 0)
                cout << "Three ";
            if(i % 5 == 0)
                cout << "Five ";
            if(i % 7 == 0)
                cout << "Seven ";
        }
        else
            cout << i << " ";
    }
}
using namespace std;
int main(){
    int n; cin >> n;
    vector <int> vec;
    for(int i = 0; i < n*2; i++){
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
void main(){
    string str, ing; cin >> str >> ing;
    cout << str + ing << "\n";
    int tmp = str.find(ing);
    if(tmp != -1)
        cout << "No";
    else
        cout << "Yes" << "\n" << str + "molla";
    
}
using namespace std;
void main(){
    int x, y, n; cin >> x >> y >> n;
    int arr[2006], res = 0;
    for(int i = 0; i < n * n; i++){
        if(arr[x] == 0){
            arr[x]++;
            res++;
        }
        int tmp = (x + y) % m;
        x = y; y = tmp;
    }
    cout << res;
}
using namespace std;
void main(){
    int n; cin >> n;
    int prv = -1;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0 || x != prv)
            vec.push_back(x);
    }
    if (vec.size() < n)
        cout << 0 << endl;
    else if (vec.size() == n)
        cout << 1 << endl;
    else
        cout << n + 1 << endl;
}
using namespace std;
void main() {
    int t;  cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        // Number of participants and threshold

        int id; cin >> id; 
        // The ID to evaluate
        vector<int> x(n), s1(n), s2(n), s3(n);
        // Input details for all participants
        for (int j = 0; j < n; j++)
            cin >> x[j] >> s1[j] >> s2[j] >> s3[j];
        // Find rank of the participant with the given ID
        int rank = 1;
        // Start with rank 1 (best possible)
        for (int j = 0; j < n; j++) {
            if (id == x[j]) { // Find the target participant
                for (int k = 0; k < n; k++) {
                    if (j == k) continue; // Skip comparing the participant with themselves
                    // Compare s3, then s2, then s1
                    if (s3[k] > s3[j] || 
                        (s3[k] == s3[j] && s2[k] > s2[j]) || 
                        (s3[k] == s3[j] && s2[k] == s2[j] && s1[k] > s1[j]))
                        rank++;
                }
                break; 
                // Found the target participant, no need to continue
            }
        }
        // Output result based on rank and threshold
        if (rank <= m) 
            cout << "YA" << endl;
        else
            cout << "TIDAK" << endl;
    }
    return 0;
}
using namespace std;
void main(){
    int n, arr[10000], res = 0; cin >> n;
    vector <int> vec[10000];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vec[arr[i]].push_back(x);
    }
    priority_queue <int> pq;
    for(int i = 100000; i >= 1; i--){
        for(int j : vec[i])
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
void main(){
    int n; cin >> n;
    pair <int, int> pr[n];
    for(int i = 0; i < n; i++)
        cin >> pr[i].first >> pr[i].second;
    sort(pr, pr + n);
    int cur = n - 2;
    for(int i = n - 1; i >= 0; i--){
        if(i == cur) cur--;
        while(pr[i].first == pr[cur].first){
            if(pr[i].second > pr[cur].second)
                pr[cur].first--;
            else
                pr[i].first--;
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(pr[i].first != 0)
            res += pr[i].second;
    }
    cout << res;
}
using namespace std;
void main(){
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
void main(){
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
void main(){
    int n, m, mn; cin >> n >> m;
    int mx = (n - m) / 4;
    if(n > 5 * m || m > n)
        cout << -1;
    else{
        if(n <= 4 * m)
            mn = 0;
        else
            mn = n - 4 * m;
    }
    cout << mn;
}
#include<bits/stdc++.h>
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
void main(){
    int a, b; cin >> a >> b;
    int gcd = __gcd(a, b);
    int lcm = a * b/gcd;
    cout << (lcm / a) + (lcm / b);
}
using namespace std;
void main(){
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
void solve(int x){
    if(x <= 1)
        return 1;
    else
        return solve(x / 2) * 2 + x;
}
using namespace std;
void main(){
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
    sort(renge.begin(), range.end());
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
using namespace std;
using ll = long long;
int main() {
    ll numElements, maxDifference, numQueries;
    cin >> numElements >> maxDifference >> numQueries;
    vector<pair<int, int>> elements(numElements + 1);
    for (int i = 1; i <= numElements; i++)
        cin >> elements[i].first;
        elements[i].second = i;
    sort(elements.begin() + 1, elements.end());

    // Priority queue to keep track of the max range size
    priority_queue<pair<int, int>> maxRangeQueue;
    // Result array to store answers
    vector<int> results(numElements + 1, 0);
    for (int i = 1, j = 1; i <= numElements; i++) {
        // Expand the window [i, j] as long as the difference is <= maxDifference
        while (j <= numElements && elements[j].first - elements[i].first <= maxDifference) {
            j++;
        }
        j--;
        // Push the current range size into the priority queue
        maxRangeQueue.push({j - i + 1, j});
        // Remove ranges that are no longer valid (left index < i)
        while (maxRangeQueue.top().second < i) {
            maxRangeQueue.pop();
        }
        // Store the maximum range size for the current element
        results[elements[i].second] = maxRangeQueue.top().first;
    }
    for (int i = 0; i < numQueries; i++) {
        int queryIndex; cin >> queryIndex;
        cout << results[queryIndex] << endl;
    }
    return 0;
}
using namespace std;
void main(){
    int n; cin >> n;
    vector <int> vec(26, 0);
    string str; cin >> str;
    for(int i = 0; i < n; i++)
        vec[str[i] - 'A']++;
    sort(vec.begin(), vec.end());
    int a = v[25];
    // Massimo valore
    int b = v[24]; 
    // Secondo massimo valore
    int c = v[23]; 
    // Terzo massimo valore
    if (c == 0) {
        cout << -1 << endl;
        return 0;
    }
    int hasil = 3 * c;
    if (a > c) hasil++;
    if (b > c) hasil++;
    cout << hasil;
}
using namespace std;
//OSP 2022 (mengangkut bebek)
void main(){
    int n, k; cin >> n >> k;
    pair <int, int> pr[n];
    int arr[k];
    for(int i = 0; i < n; i++)
        cin >> pr[i].first >> pr[i].second;
    for(int i = 0; i < k; i++)
        cin >> arr[k];
    sort(pr, pr + n);
    sort(arr, arr + k);
    int r = n - 1, res = i = 0;
    while(r >= 0){
        if(pr[i].second > 0){
            res += pr[i].first * arr[r];
            r--;
            pr[i].second--;
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
        bool flag = 0;
        int l = 0, r = n - 1;
        while(l < r){
            int sum = arr[l] + arr[r];
            if(sum == x){
                flag = 1;
                break;
            }
            else if(sum < x)
                l++;
            else
                r--;
        }
    }
    (flag) ? cout << "Ya" : cout << "Tidak";
}
using namespace std;
void main() {
    int n, x, y;  cin >> n >> x >> y;
    int a, b, c, d;
    int s = abs(x);
    int r = abs(y);
    int t = s + r;
    // Check if the Manhattan distance exceeds the total moves
    if (t > n) {
        cout << -1;
        return 0;
    }
    // Check if the remaining moves can be evenly distributed
    if ((n - t) % 2 != 0) {
        cout << -1;
        return 0;
    }
    // Calculate additional moves to distribute
    int extraMoves = (n - t) / 2;
    // Assign moves based on the signs of x and y
    if (x >= 0) {
        b = s + extraMoves; // Right moves
        d = extraMoves;     // Left moves
    } else {
        b = extraMoves;     // Right moves
        d = s + extraMoves; // Left moves
    }
    if (y >= 0) {
        a = r;              // Up moves
        c = 0;              // Down moves
    } else {
        a = 0;              // Up moves
        c = r;              // Down moves
    }
    cout << a << " " << b << " " << c << " " << d;
    return 0;
}
using namespace std;
// OSP 2021 (buah)
void main(){
    int n, a, b; cin >> n >> a >> b;
    int lcm = a * b/__gcd(a, b);
    cout << lcm / a + lcm / b;
}
// OSP 2021 (kartu)
using namespace std;
void main(){
    int a, b; cin >> a >> b;
    int mx = max(a, b), mn = min(a, b);
    while(mx % mn != 0){
        int tmp = mx - mn;
        mx = max(mn, tmp);
        mn = min(mn, tmp);
    }
    cout << mn;
}
// OSP 2022 (lampu hias)
using namespace std;
void main(){
    int n, a, b, c; cin >> n >> a >> b >> c;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % a == 0 && x % b == 0 && x % c == 0)
            cout << "YA";
        else
            cout << "No";
    }
}
// OSP 2020 (lari jauh)
using namespace std;
void main(){
    int n, k; cin >> n >> k;
    int arr[n];
    cin >> arr[0];
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
void main(){
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
void main(){
    int n, m; cin >> n >> m;
    (n % m == 0) ? cout << "Yes" : cout << "No";
}
using namespace std;
void main(){
    int n; cin >> n;
    if(n % 4 == 0)
        cout << "Yes";
    else if(n % 2 == 0)
        cout << "No";
    else{
        if((n - 1) % 4 == 0)
            cout << "No";
        else
            cout << "Yes";
    }
}
using namespace std;
void main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j % 2 == 0)
                cout << "W";
            else
                cout << "B";
        }
    }
}
using namespace std;
void main(){
    int n, m, x, y; cin >> n >> m >> x >> y;
    int res = (n - x) + (m - y) * 2;
    (res > 20) ? cout << "Yes": cout << "No";
}
using namespace std;
void main(){
    int m, a, b; cin >> m >> a >> b;
    if(a + b == 2 * m){
        if(a % 2 == 1 && b % 2 == 1)
            cout << "1";
        else
            cout << "0";
        cout << min(a, b);
    }
    else
        cout << "0" << " " << min(a, b);
}
using namespace std;
void main(){
    int n; cin >> n;
    cout << (n % 10 ? cout << "Yes": cout << "No");
}
using namespace std;
void main(){
    int n, cnt = 1; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt *= x;
    }
    cout << cnt;
}
using namespace std;
void main() {
    int n, x, y; cin >> n >> x >> y;
    int a, b, c, d;

    int s = abs(x), r = abs(y);
    int t = s + r;
    // Check if t exceeds n or if the remaining steps are odd
    if (t > n || (n - t) % 2 != 0) {
        cout << -1;
        return 0;
    }
    int extra = (n - t) / 2;
    // Assign values to b and d based on the sign of x
    if (x >= 0) {
        b = s + extra;
        d = extra;
    } else {
        b = extra;
        d = s + extra;
    }
    // Assign values to a and c based on the sign of y
    if (y >= 0) {
        a = r;
        c = 0;
    } else {
        a = 0;
        c = r;
    }
    cout << a << " " << b << " " << c << " " << d;
    return 0;
}
using namespace std;
void main(){
    string str; cin >> str;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'o')
            cnt++;
        if(cnt > 1)
            break;
    }
    (cnt == 1) ? cout << "Yes" : cout << "No";
}
using namespace std;
void main(){
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
void main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)   
        cin >> arr[i];
    int id = 0;
    while(id < n && arr[id] == 1)
        id++;
    id %= n;
    int i = id, res = 0, cnt = 0;
    do {
        if (arr[i] == 1) {
            cnt++;  
            res += cnt;
        } else
            cnt = 0;
        i = (i + 1) % n;
        // Move to the next index circularly
    } while (i != id);
    cout << res << endl;
}
using namespace std;
void main(){
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
using namespace std;
void main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        cout << 2 *min(a, b);
    }
}
using namespace std;
void main(){
    int n; cin >> n;
    int even = odd = 0;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if((x + y) % 2 == 0)
            even++;
        else
            odd++;
    }
    if(even == 0 || odd == 0)
        cout << "No";
    else
        cout << "Yes";
}
using namespace std;
void main(){
    int n, m, cnt = 0; cin >> n >> m;
    int arr[n];
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
void main(){
    int n; cin >> n;
    int tmp = 2, cnt = 0;
    while(tmp <= n)
        tmp *= 2;
    cout << tmp - n;
}
using namespace std;
void main(){
    int x, y; cin >> x >> y;
    int mn = min(x, y);
    int mx = max(x, y);
    cout << (mn - 1) * mx;
}
using namespace std;
void main(){
    int a, b; cin >> a >> b;
    int arr[a][b];
    int x, y = z = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1)
                x = (i + j) % 2;
            else if((i + j) % 2 == 0)
                y += arr[i][j];
            else
                z += arr[i][j];
        }
    }
    if(x == 0)
        (y > z)? cout << "No\n" : cout << "Yes\n" << z - y;
    else
        (y < z)? cout << "No\n" : cout << "Yes\n" << y - z;
}
using namespace std;
void main(){
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
void main(){
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
void main(){
    int n, m; cin >> n >> m;
    cout << n + (n - 3) - m;
}
using namespace std;
void main(){
    int n, m; cin >> n >> m;
    int ans = 1;
    for(int i = 1; i <= n * m - 1; i++)
        ans *= 2;
    cout << ans;
}
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    bool hasDecrease = false, hasIncrease = false, hasEqual = false;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0) {
            if (arr[i] < arr[i - 1])
                hasDecrease = true;
            else if (arr[i] > arr[i - 1])
                hasIncrease = true;
            else
                hasEqual = true;
        }
    }
    if (hasIncrease && hasDecrease)
        cout << "NONE";
    else if (hasEqual) {
        if (hasDecrease)
            cout << "NONINCREASING";
        else if (hasIncrease)
            cout << "NONDECREASING";
        else
            cout << "EQUAL";
    }else if (hasIncrease)
        cout << "NONDECREASING";
    else if (hasDecrease)
        cout << "NONINCREASING";
    else
        cout << "NONE";
}
using namespace std;
void main(){
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
void main(){
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
void main(){
    double d; cin >> d;
    cout << fixed << setprecision(1) << n *(n + 1) /2;
}
using namespace std;
void main(){
    int n, m, r; cin >> n >> m >> r;
    int mn = min(n, m);
    cout << (mn - 1) / (2 * r + 1) + 1;
}
using namespace std;
void main(){
    int p, q, r, s, t; cin >> p >> q >> r >> s >> t;
    int x = sqrt(p * q * r * s * t);
    cout << x/(q*s) << " " << x/(r*t) << " " << x/(p*s) << " " << x/(q*t) << " " << x/(p*r);
}
// find the position of the nearest 'E' (for example, an 'E' might represent an "Emergency" or an "Element") in a 2D grid. 
void FindPos(){
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
    (cnt == 0)?cout << -1 : cout << MinRow << " " << MinCol;
}
void FindTrgIdx(){
    int n, TrgIdx, cnt = 0;
    cin >> n >> TrgIdx;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(TrgIdx < 1 || TrgIdx > n){
        cout << "OutOf Bound";
        return 0;
    }
    if(arr[TrgIdx - 1] == 0){
        for(int i = 0; i < n; i++){
            if(arr[i] > 0)
                cnt++;
        }
    }
    else{
        cnt = TrgIdx;
        for(int i = TrgIdx; i < n; i++){
            if(arr[TrgIdx - 1] <= arr[i])
                cnt++;
        }
    }
    cout << cnt << "\n" << arr[TrgIdx - 1] << "\n";
    if(TrgIdx < n)
        cout << arr[TrgIdx] << "\n";
    else
        cout << "Idx OutOfBound";
}

//output the sequence of unique number
const int MAX = 1001;
void Unique(){
    int n, cnt = 0, arr[MAX] = {0};
    cin >> n;
    int Unique[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(arr[x] == 0)
            arr[x] = 1;
        Unique[cnt++] = x;
    }
    for(int i = 0; i < cnt; i++)
        cout << Unique[i] << " ";
}

void ChangePos(){
    int n; cin >> n;
    char ch[26];
    vector <char> arr(n);
    vector <int> tmp(n);
    vector <bool> used(n, false);
    vector <int> res(n);
    for(int i = 0; i < 26; i++)
        ch[i] = 'a' + i;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(arr[i] == ch[j]){
                tmp[i] = j + 1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        int minIdx = -1;
        for(int j = 0; j < n; j++){
            if(!used[j] && (minIdx == - 1 || tmp[j] < tmp[minIdx]))
                minIdx = j;
        }
        res[minIdx] = n - i;
        used[minIdx] = true;
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
// determine process a list of integers representing the positions of 
//citizens in Lineland and determine two values for each citizen: minimum & maximum distance to any other citizen.
void LinelandMail(){
    int n; cin >> n;
    int arr[n], maxi[n], mini[n], res[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    /*for(int i = 0; i < n; i++){
        maxi[i] = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
        if(i == 0)
            mini[i] = abs(arr[i] - arr[i + 1]);
        else if(i == n - 1)
            mini[i] = abs(arr[i] - arr[i - 1]);
        else
            mini[i] = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
    }
    for(int i = 0; i < n; i++)
        cin << maxi[i] << " " << mini[i];*/
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            if(arr[i] == arr[j])
                continue;
            if(arr[i] > arr[j])
                res[j] = arr[i] - arr[j];
            else
                res[j] = arr[j] - arr[i];
                
        }
    }
    sort(res, res + n);
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}

// create as many complete teams as possible where each team consists of 
//one student with each of three different types of gifts. Each team should have one student 
//with gift type 1, one student with gift type 2, and one student with gift type 3.
void TeamOlympiad(){
    int n; cin >> n;
    vector <int> count(4, 0);
    vector <vector <int> >student(4, vector <int> (5001));
    for(int i = 1; i <= n; i++){
        //loop runs n times for each student.each iteration, it reads the type of gift from the input.
        int gift; cin >> gift;
        count[gift]++;
        student[gift][count[gift]] = i;
    }
    //teams is calculated as the minimum value among the counts of gift types 1, 2, and 3.
    // it is the maximum number of teams that can be formed, where each team has one student with each type of gift.
    int team = min({count[1], count[2], count[3]});
    for(int i = 1; i <= team; i++){
    //prints the index of a student with gift type 1, gift type 2, and gift type 3.
        cout << student[1][i] << "\n";
        cout << student[2][i] << "\n";
        cout << student[3][i] << "\n";
    }
}
void Presents(){
    int n; cin >> n;
    int arr[n], freq[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] >= 1 && arr[i] <= n)
            freq[arr[i] - 1] = i + 1;
    }
    for(int i = 0; i < n; i++)
        cout << freq[i] << " ";
}
void NewPassword(){
    int TotalLength, CycleLength, i;
    cin >> TotalLength >> CycleLength;
    char alpha[26] = {0};
    for(int i = 0; i <  26; i++){
        alpha[i] = 'a' + i;
    }
    /*for(i = 97; i <= 122; i++)
        alpha[i - 97] = i;
    alpha[i] = '\0';*/
    int CompleteCycle = TotalLength / CycleLength;
    for(int i = 0; i < CompleteCycle; i++){
        for(int j = 0; j < CycleLength; j++) 
            cout << alpha[j] << " ";
    }
    cout << "\n";
    int remainChar = TotalLength % CycleLength;
    for(int i = 0; i < remainChar; i++)
        cout << alpha[i] << " ";
    cout << "\n";
}
using namespace std;0
typedef long long ll;
// Extended Euclidean Algorithm
// This function returns the gcd of a and b, and updates x and y with the coefficients such that: ax + by = gcd(a, b)
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    // if a is 0, then gcd is b, and the coefficients are (0, 1)
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    // To store results of recursive call
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
// Function to find modulo inverse of b under modulo m
// This returns -1 if the inverse doesn't exist (i.e., if gcd(b, m) != 1)
ll modInverse(ll b, ll m) {
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    // Return -1 if b and m are not coprime (gcd != 1)
    if (g != 1)
        return -1;
    // Handle negative x by ensuring result is positive
    return (x % m + m) % m;
}
// compute a / b under modulo m.This function returns (a * b^(-1)) % m if the modular inverse exists; otherwise, -1
ll modDivide(ll a, ll b, ll m) {
    a = a % m;
    ll inv = modInverse(b, m);

    // Check if the modular inverse exists
    if (inv == -1) {
        printf("Division not defined\n");
        return -1;
    }
    else
        return (inv * a) % m;
}
int main() {
    ll a = 10, b = 3, m = 13;
    ll result = modDivide(a, b, m);
    if (result != -1) {
        printf("Result of %lld / %lld under modulo %lld is %lld\n", a, b, m, result);
    }
    return 0;
}
using namespace std;
void check(){
    int n; string str;
    cin >> n >> str;
    if(n == 1){
        if(str == "W")
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
    if(n == 2){
        if(str == "WW" || str == "RB" || str == "BR")
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
    int len = str.size();
    bool flag = true;
    for(int i = 0; i < len;){ 
        //skip white
        while(i < len && str[i] == 'W')
            i++;
        if(i == n)
            break;
        int blue = 0, red = 0;
        while(i < len && str[i]!= 'W'){
            if(str[i] == 'B')
                blue++;
            else if(str[i] == 'R')
                red++;
            i++;
        }
        if(blue == 0 || red == 0){
            flag = false;
            break;
        }
    }
    (flag)? cout << "Yes" : cout << "No";
}
using namespace std;
//determine if a string composed of the characters 'R', 'B', and 'W' satisfies 
// specific adjacency rules for the characters 'R' and 'B'.
void isSatisfied(){
    string str; cin >> str;
    bool valid = true;
    int len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] == 'R' || str[i] == 'B'){
            bool validVicino = false;
            if(i > 0 && (str[i - 1] == 'R' || str[i - 1] == 'B'))
                validVicino = true;
            if(i < len - 1 && (str[i + 1] == 'R' || str[i + 1] == 'B'))
                validVicino = true;
            if(str[i] == 'R'){
                if(i > 0 && str[i - 1] == 'W' && str[i + 1] != 'B')
                    validVicino = false;
                if(i < len - 1 && str[i + 1] == 'W' && str[i - 1]!= 'B')
                    validVicino = false;
            }
           else if(str[i] == 'B'){
                if(i > 0 && str[i - 1] == 'W' && str[i + 1] != 'R')
                    validVicino = false;
                if(i < len - 1 && str[i + 1] == 'W' && str[i - 1]!= 'R')
                    validVicino = false;
            }
            if(!validVicino){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}
using namespace std;
//finds the next palindromic date that is larger than n.
int arr[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int rev(int x){
    int ans = 0;
    while(x){
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}
bool IsLeap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool check(int x, int n){
    if(x <= n)
        return false;
    int day = x % 100;
    x /= 100;
    int month = x % 100;
    int year = x / 100;
    if(month < 1 && month > 12)
        return false;
    if(IsLeap(year) && month == 2)
        return day <= 29;
    return day <= arr[month];
}
int main(){
    int n; cin >> n;
    for (int i = n / 10000; i <= 9999; i++) {
        int x = i * 10000 + rev(i);
        if (check(x, n)) {
            cout << x << endl;
            break;
        }
    }
    for (int i = n / 1000000; i <= 9999; i++) {
        int x = i * 1000000 + i * 10000 + rev(i) * 100 + rev(i);
        if (check(x, n)) {
            cout << x << endl;
            break;
        }
    }
}
using namespace std;
bool UniqueDigit(int year){
    int digits[10] = {0};
    while(year > 0){
        int dig = year % 10;
        if(digits[dig] > 0)
            return false;
        digits[dig]++;
        year /= 10;
    }
    return true;
}
int main(){
    int y; cin >> y;
    int n = y + 1;
    while(true){
        if(UniqueDigit(n)){
            cout << n;
            break;
        }
        n++;
    }
}
using namespace std;
void CountChar(){
    string str; cin >> str;
    int upper = 0, lower = 0, num = 0, special = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            lower++;
        else if(str[i] >= '0' && str[i] <= '9')
            num++;
        else
            special++;
    }
    if(upper > lower)
 	transform(str.begin(), str.end(), str.begin(), ::toupper);
   else if(lower > upper)
 	transform(str.begin(), str.end(), str.begin(), ::tolower);
   else if(upper == lower)
 	transform(str.begin(), str.end(), str.begin(), ::tolower);
   cout << str;
   cout << "\nUpper case letters: " << upper << "\nLower case letters : " << lower  << "\nNumber : " << num << "\nSpecial characters : " << special;
}
using namespace std;
void LuckyDigit(){
    int n, digit, cnt = 0;
    cin >> n;
    while(n){
        digit = n % 10; n /= 10;
        if(digit == 4 || digit == 7)
            cnt++;
    }
    (cnt == 4 || cnt == 7) ? cout << "Yes" : cout << "No";
}
using namespace std;
int main(){
    int n, m, idx; cin >> n >> m;
    int arr[n], tmp[m];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ForwardSteps, ForwardCnt = 0, BackwardCnt = 0;
    for(int i = 0; i < m; i++){
        cin >> tmp[i];
        idx = -1;
        for(int j = 0; j < n; j++){
            if(arr[j] = tmp[i]){
                idx = j;
                break;
            }
        }
        if(idx != -1){
            ForwardSteps = idx + 1;
            ForwardCnt += ForwardSteps;
            ForwardSteps = n - idx;
            BackwardCnt += ForwardSteps;
        }
    }
    cout << ForwardCnt << " " << BackwardCnt;
}
using namespace std;
long BinPow(int a, int b, int m){
    a %= m;
    if(b == 0)
        return 1;
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res = res * a % m;
        a = a * a % m;
        b >> = 1;
    }
    return res;
}
long BinPow(int a, int b){
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res *= a;
        a *= a;
        b >> = 1;
    }
    return res;
}
long long nCr(int n, int p, int r){
    if(n < r)
        return 0;
    if(r == 0)
        return 1;
    int fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % p;
    return (fact[n] * BinPow(fact[r], p - 2, p) % p * BinPow(fact[n - r], p - 2, p) % p) % p;
}
using namespace std;
bool prime[100100];
void isprime(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int p = 2; p * p <= 100100; p++){
        if(prime[p]){
            for(int i = p * p; i <= 100100; i+= p)
                prime[i] = false;
        }
    }
}
using namespace std;
void PrimeFactor(int n, vector <int> &vec){
    while(n % 2 == 0){
        vec.push_back(2);
        n /= 2;
    }
    for(int i = 3; i <= sqrt(n); i+= 2){
        while(n % i == 0){
            vec.push_back(i);
            n /= i;
        }
    }
    if(n > 2)
        vec.push_back(n);
}
using namespace std;
int smallestDiv(int n){
    if(n % 2 == 0)
        return 2;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0)
            return i;
    }
    return n;
}
using namespace std;
vector <pair <int, int> findSubarr(int arr[], int n){
    unordered_map <int, vector <int> > mp;
    vector <pair <int, int> >vec;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0)
            vec.push_back(make_pair(0, i));
        if(mp.find(sum) != mp.end()){
            vector <int> vc = mp[sum];
            for(auto it = vc.begin(); it != vc.end(); ++it)
                vec.push_back(make_pair(*it + 1, i));
        }
        mp[sum].push_back(i);
    }
    return vec;
}
int cntDisjoint(const vector <pair <int, int> > &vec){
    int cnt = 1;
    int prev = -1;
    for(const auto &it : vec){
        if(it.first > prev){
            cnt++;
            prev = it.second;
        }
    }
    return cnt;
}
using namespace std;
int longestSubseq(vector <int> vec){
    vector <int> ans;
    for(int i = 0; i < vec.size(); i++){
        auto it = upper_bound(ans.begin(), ans.end(), vec[i]);
        if(it == ans.end())
            ans.push_back(vec[i]);
        else
            *it = vec[i];
    }
    return ans.size();
}
using namespace std;
int getmid(int l, int r){
    return l + (r - l)/2;
}
int Util(const vector <int> &arr, int s, int e, vector <int> &st, int cur){
    if(s == e){
        st[cur] = arr[s];
        return st[cur];
    }
    int mid = getmid(s, e);
    st[cur] = max(Util(arr, s, mid, st, 2 * cur + 1), Util(arr, mid + 1, e, st, 2 *cur + 2));
    return st[cur];
}
vector <int> constructSt(const vector <int> &arr){
    int n = arr.size();
    int x = (int)(ceil(log2(n)));
    int maxSize = 2 * (int)pow(2, x) - 1;
    vector <int> st(maxSize, INT_MIN);
    Util(arr, 0, n - 1, st, 0);
    return st;
}
int MaxUtil(const vector <int> &st, int s, int e, int l, int r, int node){
    if(l <= s && r >= e)
        return st[node];
    if(s > r || e < l)
        return INT_MIN;
    int mid = getmid(s, e);
    return max(MaxUtil(st, s, mid, l, r, 2 * node + 1), MaxUtil(st, mid + 1, e, l, r, 2 * node + 2 ));
}
int getMax(vector <int> st, int n, int l, int r){
    if(l < 0 || r >= n || l > r){
        return INT_MIN;
    }
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
void update(vector <int> &arr, vector <int> &st, int s, int e, int idx, int val, int node){
    if(idx < s || idx > e)
        return;
    if(s == e){
        arr[idx] = val;
        st[node] = val;
    }
    else{
        int mid = getmid(s, e);
        if(idx <= mid)
            update(arr, st, s, mid, idx, val, 2 * node + 1);
        else
            update(arr, st, mid + 1, e, idx, val, 2 * node + 2);
        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }
}
int main(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    vector <int> st = constructSt(vec);
    while(true){
        int choice; cin >> choice;
        if(choice == 1){
            int l, r; cin >> l >> r;
            cout << "Maximum val between " << l << " & " << r << " is" << getMax(st, n, l, r);
        }
        else if(choice == 2){
            int idx, val; cin >> idx >> val;
            update(vec, st, 0, n - 1, idx, val, 0);
        }
        else if(choice == 3)
            break;
        else
            cerr << "Invalid input";
    }
}
using namespace std;
bool IsKthBit(int n, int k){
    if(n & (1 << k))
        return true;
    return false;
}
//print prime factors and their powers using Sieve Of Eratosthenes
using namespace std;
void sieve(int n, int arr[]){
    vector <bool> prime(n + 1, false);
    for(int i = 2; i <= n; i += 2)
        arr[i] = 2;
    for(int i = 3; i <= n; i+= 2){
        if(!prime[i]){
            arr[i] = i;
            for(int j = i; j * i <= n; j += 2){
                if(!prime[i * j]){
                    prime[i * j] = true;
                    arr[i * j] = i;
                }
            }
        }
    }
}
map <int, int> generatePrime(int n){
    //arr store smallest prime factors & factor store prime factors;
    map <int, int> factor;
    int arr[n + 1] = {0};
    sieve(n, arr);
    int cur = arr[n];
    int power = 1;
    while(n > 1){
        n /= arr[n];
        if(cur == arr[n])
            power++;
        else{
            factor[cur] = power;
            cur = arr[n];
            power = 1;
        }
    }
    return factor;
}
void print(map <int, int> &factor){
    for(const auto & [fact, power] : factor)
        cout << fact << " " << power << "\n";
}
int main(){
    int n = 100;
    map <int, int> factors = generatePrime(n);
    print(factors);
}
using namespace std;
//Returns count of subarrays of arr with XOR
int SubarrXor(int arr[], int n, int m){
    int ans = 0;
    // Map to store frequency of prefix XOR values
    // Create a prefix xor-sum array such that xorArr[i] has value equal to XOR
    // of all elements in arr[] vector<ll>xorArr(n);
    unordered_map <int, int> ump;
    // Initialize cumulative XOR
    int cx = 0;
    for(int i = 0; i < n; i++){
        cx ^= arr[i];
        if(cx == m)
            ans++;
        // Find XOR of current prefix with m
        int tmp = cx ^ m;
        // Add the frequency of the required XOR value
        if(ump.find(tmp)!= ump.end())
        // Increment the count of current XOR in the map
            ump[cx]++;
    }
    return ans;
}
//count all subarrays having XOR of elements as given value m with
// Returns count of subarrays of arr with XOR value equals to m
long long subarrayXor(int arr[], int n, int m)
{
	int ans = 0; 

	// Create a prefix xor-sum array such that xorArr[i] has value equal to XOR of all elements in arr[]
	// vector<ll>xorArr(n);
	// Create map that stores number of prefix array elements corresponding to a XOR value
	unordered_map<int, int> mp;
	// Initialize first element of prefix array [xorArr[0] = arr[0]]
	ll cx = arr[0];
	ll px = cx;
	// Computing the prefix array.
	// for (ll i = 1; i < n; i++)
	// 	xorArr[i] = xorArr[i - 1] ^ arr[i];
	// Calculate the answer
	for (ll i = 0; i < n; i++){
		px = cx;
		if (i != 0)
			cx = px ^ arr[i];
		// Find XOR of current prefix with m.
		// int tmp = m ^ xorArr[i];
		int tmp = m ^ cx;
		// If above XOR exists in map, then there is another previous prefix with same XOR,
		//there is a subarray ending at i with XOR equal to m.
		ans = ans + ((long long)mp[tmp]);
		// If this subarray has XOR equal to m itself.
		if (cx == m)
			ans++;
		// Add the XOR of this subarray to the map
		mp[cx]++;
	}
	// Return total count of subarrays having XOR of elements as given value m
	return ans;
}
using namespace std;
const int MAXN = 1e3;
int Factor[MAXN];
// Calculating SPF (Smallest Prime Factor) for every number till MAXN.
void sieve(){
    Factor[1] = 1;
    for(int i = 2; i < MAXM; i++)
        Factor[i] = i;
    for(int i = 4; i < MAXN; i+= 2)
        Factor[i] = 2;
    for(int i = 3; i * i < MAXN; i++){
        if(Factor[i] == i){
            for(int j = i * i; j < MAXN; j+= i){
                if(Factor[j] == j)
                    Factor[j] = i;
            }
        }
    }
}
vector <int> Factorization(int x){
    vector <int> res;
    while(x != 1){
        res.push_back(Factor[x]);
        x /= Factor[x];
    }
    return res;
}
int main(){
    sieve();
    int num; cin >> num;
    if(num < 1 || num >= MAXN) 
        return 1;
    vector <int> fac = Factorization(num);
    for(int i = 0; i < fac.size(); i++)
        cout << fac[i] << " ";
}
