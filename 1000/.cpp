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
