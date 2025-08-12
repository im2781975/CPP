using namespace std;
https://codeforces.com/problemset/problem/1/A
// 1A. Theatre Square
int main(){
    unsigned long long n, m, a; cin >> n >> m >> a;
    cout << ceil((double)n / a) * ceil((double)m / a);
    // cout << ceil(0.1 * (n / a)) * ceil(0.1  * (m / a));
    //cout << (n / a + (n % a != 0)) * (m / a + (m % a != 0))
    int r1 = n / a, r2 = m / a;
    if(n % a != 0)    r1++;
    if(m % a != 0)    r2++;
    cout << r1 * r2;
}
using namespace std;
https://codeforces.com/problemset/problem/1/B
// 1B. Spreadsheets
bool determine(const string &str){
    if(str[0] != 'R' || !(str[1] >= '0' && str[1] <= '9'))    return true;
    int i = 1;
    while(i < str.size() && isdigit(str[i]))    i++;
    if(i < str.size() && str[i] == 'C')    return false;
    return true;
}
// Converts Excel style "BC23" to RC format like "R23C55"
string ExToRc(const string &str){
    int sum = 0, cnt = 0;
    int len = str.size();
    for(int i = len - 1; i >= 0; i--){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            sum += (str[i] - 64) + pow(26, cnt);
            cnt++;
        }
    }
    string ing = "R";
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9')    ing += str[i];
    }
    ing += 'C' + to_string(sum);
    return ing;
    /*
    int col = 0, i = 0;
    while(i < str.size() && isalpha(str[i])){
        col = col * 26 + (str[i] - 'A' + 1);
        i++;
    }
    string row = str.substr(i);
    return "R" + row + "C" + to_string(col); */
}
// Converts RC format like "R23C55" to Excel style "BC23"
string RcToEx(const string &str){
    int len = str.length();
    string ing = "";
    for(int i = len - 1; i >= 0; i--){
        if(isdigit(str[i]))    ing += str[i];
        else    break;
    }
    int col = stoi(ing);
    string colletter = "";
    while(col > 0){
        int rem = col % 26;
        if(rem == 0){
            colletter += 'Z';
            col = (col / 26) - 1;
        }
        else {
            colletter += char('A' + rem - 1);
            col /= 26;
        }
    }
    reverse(colletter.begin(), colletter.end());
    string rowstr = "";
    bool collected = false;
    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])){
            rowstr += str[i];
            collected = true;
        }
        else if(collected)    break;
    }
    return colletter + rowstr;
    /*
    size_t pos = str.find('C');
    int row = stoll(str.substr(1, pos - 1));
    int col = stoll(str.substr(pos + 1));
    string ing = "";
    while(col > 0){
        col--;
        ing += char('A' + col % 26);
        col /= 26;
    }
    reverse(ing.begin(), ing.end());
    return ing + to_string(row);    */
}
string Exel(int col){
    string res = "";
    while(col > 0){
        col--;
        res += char('A' + col % 26);
        col /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}
int rowCol(const string &str){
    int res = 0;
    for(int i = 0; i < str.size(); i++)
        res = (res * 26) + (str[i] - 'A' + 1);
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        // if(determine(str))    cout << ExToRc(str);
        // else    cout << RcToEx(str);
        
        if(str[0] == 'R' && isdigit(str[1])){
            size_t pos = str.find('C');
            if(pos != string::npos){
                string row = str.substr(1,  pos - 1);
                int col = stoi(str.substr(pos + 1));
                cout << Exel(col) << row << "\n";
            }
        }
        else{
            int i = 0;
            while(isalpha(str[i]))    ++i;
            string colstr = str.substr(0, i);
            string rowstr = str.substr(i);
            cout << "R" << rowstr << "C" << rowCol(colstr);
        }
    }
}
https://codeforces.com/problemset/problem/1/C
// 1C. Ancient Berland Circus
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-8;
double gcd(double a, double b){
    while(fabs(b) > EPS){
        double r = fmod(a, b);
        a = b; b = r;
    }
}
int main(){
    double x1, x2, x3, y1, y2, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = hypot(x2 - x3, y2 - y3);
    double b = hypot(x1 - x3, y1 - y3);
    double c = hypot(x1 - x2, y1 - y2);
    double s = (a + b + c) / 2;
    double s = sqrt(s * (s - a) * (s - b) * (s - c));
    double R = (a * b * c) / (4 * area);

    double ang1 = 2 * asin(a / (2 * R));
    double ang2 = 2 * asin(b / (2 * R));
    double ang3 = 2 * asin(c / (2 * R));
    double mini = gcd(ang1, gcd(ang2, ang3));
    int n = round(2 * round / mini);
    double poligon = 0.5 * n * R * R * sin(2 * PI / n);
    cout << fixed << setprecision(10) << poligon;
}
https://codeforces.com/problemset/problem/2/A
// 2A. Winner
using namespace std;
int main(){
    int n; cin >> n;
    vector <pair <string, int> >rounds(n);
    map <string, int> points;
    for(int i = 0; i < n; i++){
        cin >> rounds[i].first >> rounds[i].second;
        points[rounds[i].first] += rounds[i].second;
    }
    int sign = INT_MIN;
    set <string> winner;
    for(map <string, int> ::iterator it = points.begin(); it != points.end(); ++it){
        if(it->second > sign){
            sign = it->second;
            winner.clear();
            winner.insert(it->first);
        }
        else if(it->second == sign)    winner.insert(it->first);
    }/*
    for(const auto &[name, score] : points){
        if(score > sign){
            sign = score;
            winner.clear();
            winner.insert(name);
        }
        else if(score == sign)    winner.insert(name)
    }*/
    if(winner.size() > 1){
        points.clear();
        for(vector <pair <string, int> > ::iterator it = rounds.begin(); it != rounds.end(); ++it){
            points[it->first] += it-> second;
            if(points[it->first] >= sign && winner.count(it->first) == 1){
                winner.clear();
                winner.insert(it->first);
                break;
            }
        }/*
        for(const auto &[name, score] : rounds){
            points[name] += score;
            if(points[name] >= sign && winner.count(name) == 1){
                winner.clear();
                winner.insert(name);
                break;
            }
        } */
    }
    cout << *winner.begin();
    /*
    for(int i = 0; i < n; i++){
        string name;
        int score;
        rounds[i] = {name, score};
        points[name] += score;
    }
    map <string, int> candid;
    int sign = INT_MIN;
    for(auto it = points.begin(); it != points.end(); it++)
        sign = max(sign, it->second);
    for(auto it = points.begin(); it != points.end(); it++){
        if(sign == it->second)
            candid[it->first] = 0;
            // prepare for tie-break replay
    }
    for(auto it = rounds.begin(); it != rounds.end(); it++){
        const string &name = it->first;
        int score = it->second;
        if(candid.count(name)){
            candid[name] += score;
            if(candid[name] >= sign){
                cout << name;
                break;
            }
        }
    } */
}
https://codeforces.com/problemset/problem/2/B
// 2B. The least round way
using namespace std;
vector <vector <pair <int, int>>>matrix;
int power(int num, int base){
    int cnt = 0;
    while(num % base == 0){
        num /= base;
        cnt++;
    }
    return cnt;
}
int getmatrix(bool five, int r, int c){
    return five ? matrix[r][c].second : matrix[r][c].first;
}
int findpath(int r, int c, bool five, vector <vector <int> >&dp){
    // dp[r][c] = minimum total cost from (0,0) to (r,c) when counting either 2’s or 5’s
    string path = "";
    // If that cost matches the value in dp[r-1][c], then 
    // the optimal path came from above (r-1, c) else (r, c - 1)
    if(r > 0 && dp[r][c] - getmatrix(five, r, c) == dp[r - 1][c]){
        r--; path += "D";
    }
    else{
        c--; path += "R";
    }
}
int main(){
    int n; cin >> n;
    int row = -1, col = -1;
    bool hasZero = true;
    matrix.assign(n, vector <pair <int, int> >(n));
    vector <vector <int>>dp2(n, vector <int>(n, INT_MAX));
    vector <vector <int>>dp5(n, vector <int>(n, INT_MAX));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int k; cin >> k;
            if(k == 0){
                row = i; col = j;
                k = 10;
                hasZero = false;
            }
            matrix[i][j] = {power(k, 2), power(k, 5)};
        }
    }
    dp2[0][0] = matrix[0][0].first;
    dp5[0][0] = matrix[0][0].second;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > 0){
                dp2[i][j] = min(dp[i][j], dp[i - 1][j] + matrix[i][j].first);
                dp5[i][j] = min(dp[i][j], dp[i- 1][j] + matrix[i][j].second);
            }
            if(j > 0){
                dp2[i][j] = min(dp[i][j], dp[i][j - 1] + matrix[i][j].first);
                dp5[i][j] = min(dp[i][j], dp[i][j - 1] + matrix[i][j].second);
            }
        }
    }
    int minDecimal = min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]);
    string path;
    if(hasZero && minDecimal > 1){
        minDecimal = 1;
        // Create a path that goes through the zero cell
        path = string(col - 1, 'R') + string(n - 1, 'D') + string(n - 1 - col, 'R');
    }
    else{
        if(dp5[n - 1][n - 1] == minDecimal)
            path = findpath(n - 1, n - 1, true, dp5);
        else
            path = findpath(n - 1, n - 1, false, dp2);
    }
    cout << minDecimal << "\n" << path;
}
using namespace std;
const int peak = 1010;
int n;
int grid[peak][peak];
int dp[2][peak][peak];
bool path[2][peak][peak];
int printpath(int row, int col){
    // Start at (top-left) and move down until we reach the row containing the zero cell.
    for(int i = 1; i < row; i++)    cout << 'D';
    for(int j = 1; j < col; j++)    cout << 'R';
    // After touching the zero, keep moving down until we hit the last row.
    for(int i = row; i < n; i++)    cout << 'D';
    for(int j = col; j < n; j++)    cout << 'R';
}
void cntfactors(int num, int cnt2, int cnt5){
    cnt2 = cnt5 = 0;
    while(num && num % 2 == 0){
        num /= 2; cnt2++;
    }
    while(num && num % 5 == 0){
        num /= 5; cnt5++;
    }
}
int main(){
    int n; cin >> n;
    int row = 0, col = 0;
    bool hasZero = false;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 0){
                hasZero = true;
                row = i; col = j;
            }
        }
    }
    if(grid[1][1] = 0){
        printpath(1, 1);
        return 0;
    }
    // k loop is used for 2 dimention(2's & 5's factors)
    for(int k = 0; k < 2; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++)
                dp[k][i][j] = INT_MAX;
        }
    }
    int cnt2, cnt5;
    cntfactors(grid[1][1], cnt2, cnt5);
    dp[0][1][1] = cnt2; dp[1][1][1] = cnt5;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!(i == 1 && j == 1) && grid[i][j]){
                cntfactors(grid[i][j], cnt2, cnt5);
                if(dp[0][i - 1][j] < dp[0][i][j - 1]){
                    dp[0][i][j] = dp[0][i - 1][j] + cnt2;
                    path[0][i][j] = false;
                }
                else{
                    dp[0][i][j] = dp[0][i][j - 1] + cnt2;
                    path[0][i][j] = true;
                }
                if(dp[1][i - 1][j] < dp[1][i][j - 1]){
                    dp[1][i][j] = dp[1][i - 1][j] + cnt5;
                    path[1][i][j] = false;
                }
                else{
                    dp[1][i][j] = dp[1][i][j - 1] + cnt5;
                    path[1][i][j] = true;
                }
            }
        }
    }
    int type = (dp[0][n][n] > dp[1][n][n]) ? 1 : 0;
    int minZeros = min(dp[0][n][n], dp[1][n][n]);
    if(minZeros >= 1 && hasZero){
        printpath(row, col);
        return 0;
    }
    cout << minZeros << '\n';
    stack <char> st;
    while(i > 1 || j > 1){
        if(path[type][i][j]){
            st.push('R'); j--;
        }
        else{
            st.push('D'); i--;
        }
    }
    while(!st.empty()){
        cout << st.top(); st.pop();
    }
    cout << '\n';
}
https://codeforces.com/problemset/problem/3/A
// A. Shortest path of the king
using namespace std;
int main(){
    string start, end; cin >> start >> end;
    // dx counts columns (horizontal distance) because it's based on letter differences.
    // dy counts rows (vertical distance) because it's based on digit differences.
    int dx = abs(start[0] - end[0]);
    int dy = abs(start[1] - end[1]);
    cout << max(dx, dy) << '\n';
    while(start != end){
        string move = "";
        if(start[0] < end[0]){
            move += 'R'; start[0]++;
            // cout << 'R';
        }
        else if(start[0] > end[0]){
            move += 'L'; start[0]--;
            // cout << 'L';
        }
        if(start[1] < end[1]){
            move += 'U'; start[1]++;
            // cout << 'U';
        }
        else if(start[1] > end[1]){
            move += 'D'; start[1]--;
            // cout << 'D';
        }
        // cout << endl;
        cout << move << '\n';
    }
}
using namespace std;
typedef pair <int, int> square;
int main(){
    square start, end; 
    list <string> res;
    
    string str; cin >> str;
    start.first = str[1] - '1';
    start.second = str[0] - 'a';
    cin >> str;
    end.first = str[1] - '1';
    end.second = str[0] - 'a';
    while(start != end){
        string move = "";
        if(start.first < end.first){
            move += 'U'; start.first++;
        }
        else if(start.first > end.first){
            move += 'D';  start.first--;
        }
        if(start.second < end.second){
            move += 'R'; start.second++;
        }
        else if(start.second > end.second){
            move += 'L'; start.second--;
        }
        res.push_back(move);
    }
    cout << res.size() << "\n";
    for(auto it = res.begin(); it!= res.end(); ++it)
        cout << *it << "\n";
}
https://codeforces.com/problemset/problem/4/C
// 4C. Registration system
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        map <string, int> mp;
        if(!mp[str])    cout << "OK" << endl;
        else    cout << str + to_string(mp[str]);
        /*
        if(mp[str] >= 1)    cout << str << mp[str] << endl;
        else    cout << "Ok" << endl;
        if(mp[str] == 0)    cout << "Ok" << endl;
        else    cout << str << mp[str] << endl;    */
        ++mp[str];
    }
}
http://codeforces.com/contest/9/problem/A
// 9A. Die Roll
using namespace std;
int main(){
    int y, w; cin >> y >> w;
    int maxi = max(y, w);
    int q = (6 - maxi) + 1;
    if(q == 1)    cout << "1/6" << endl;
    else if(q == 2)    cout << "1/3" << endl;
    else if(q == 3)    cout << "1/2" << endl;
    else if(q == 4)    cout << "2/3" << endl;
    else if(q == 5)    cout << "5/6" << endl;
    else if(q == 6)    cout << "1/1" << endl;
    else if(q == 0)    cout << "0/1" << endl; /*
    string arr[] = {"1/6", "1/3", "1/2", "2/3", "5/6", "1/1", "0/1"};
    cout << arr[maxi] << endl; */
}
http://codeforces.com/contest/16/problem/A
// 16A. Flag
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int flag[n];
    for(int i = 0; i < n; i++)    cin >> flag[i];
    bool Isvalid = true;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if(flag[i][j] != flag[i][0]){
                Isvalid = false;
                break;
            }
        }
        if(i > 0 && flag[i][0] == flag[i - 1][0]){
            Isvalid = false;
            break;
        }
    }
    cout << Isvalid ? "YES" : "NO";
}
http://codeforces.com/contest/16/problem/B
// 16B. Burglar and Matches
using namespace std;
bool comp(pair <int, int> a, pair <int, int> b){
    return a.second > b.second;
}
int main(){
    int n, m; cin >> n >> m;
    vector <pair <int, int> >boxes(m);
    for(int i = 0; i < m; i++)    cin >> boxes[i].first >> boxes[i].second;
    sort(boxes.begin(), boxes.end(), comp);
    int total_matches = 0, rem = n;
    for(int i = 0; i < m && rem > 0; i++){
        int take = min(boxes[i].first, rem);
        total_matches += 1LL * take * boxes[i].second;
        rem -= take;
    }
    cout << total_matches;
}
