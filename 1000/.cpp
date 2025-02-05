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
