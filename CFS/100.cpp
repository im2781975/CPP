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
// 3A. Shortest path of the king
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
https://codeforces.com/problemset/problem/3/B
// 3B. Lorry
using namespace std;
int main(){
    // v -> volume of the lorry
    int n, v; cin >> n >> v;
    vector <pair <int, int> >kayak, catamaran;
    for(int i = 0; i < n; i++){
        int type, cap; cin >> type >> cap;
        if(type == 1) kayak.emplace_back(cap, i + 1);
        else catamaran.emplace_back(cap, i + 1);
    }
    sort(kayak.rbegin(), keyak.rend());
    sort(catamaran.rbegin(), catamaran.rend());
    int cur = 0, best = 0, kayak_peak = 0, catamaran_peak = 0;
    int k = min((int)kayak.size(), v);
    for(int i = 0; i < k; i++)    cur += kayak[i].first;
    int c = min((int)catamaran.size(), (v - k) / 2);
    for(int i = 0; i < c; i++) cur += catamaran[i].first;
    best = cur;
    kayak_peak = k; catamaran_peak = c;
    while(k > 0 && c < (int)catamaran.size()){
        --k;
        cur -= kaya[k].first;
        if(k + (c + 1) * 2 <= v){
            ++c;
            cur += catamaran[c].first;
        }
        if(cur > best){
            best = cur;
            kayak_peak = k; catamaran_peak = c;
        }
    } /*
    vector <int> sumkayak(kayak.size() + 1, 0), sumcatamaran(catamaran.size() + 1, 0);
    for(int i = 1; i <= (int)kayak.size(); i++)
        sumkayak[i] = sumkayak[i - 1] + kayak[i - 1].first;
    for(int i = 1; i <= (int)catamaran.size(); i++)
        sumcatamaran[i] = sumcatamaran[i - 1] + catamaran[i - 1].first;
    for(int k = 0; k <= (int)kayak.size(); ++k){
        if(k > v)    break;
        int rem = v - k;
        int c = min((int)catamaran.size(), rem / 2);
        int val = sumkayak[k] + sumcatamaran[c];
        if(val > best){
            best = val;
            kayak_peak = k;
            catamaran_peak = c;
        }
    } */
    cout << best << "\n";
    for(int i = 0; i < kayak_peak; i++)    cout << kayak[i].second << "\n";
    for(int i = 0; i < catamaran_peak; i++)    cout << catamaran[i].second << "\n";
}
https://codeforces.com/problemset/problem/3/C
// 3C. Tic-tac-toe
using namespace std;
int main(){
    vector <string> board(3);
    int x = 0, o = 0, xwin= 0, owin = 0;
    // x3, o3 represent winning lines
    for(int i = 0; i < 3; i++){
        cin >> board[i];
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'X')    x++;
            else if(board[i][j] == '0') o++;
        }
    }
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == 'X')    xwin++;
            else if(board[i][0] = '0')    owin++;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if(board[0][i] == 'X')    xwin++;
            else if(board[0][i] == '0')    owin++;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[1][1] == 'X')    xwin++;
        else if(board[1][1] == '0')    owin++;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[1][1] == 'X')    xwin++;
        else if(board[1][1] == '0')    owin++;
    }
    //x < o -> 'X' move first.so diffrent should be minimum 1.if any of them win diffrent should be zero.
    //x3 && o3 -> both win impossible
    if((x < o || x - o > 1) || (xwin && owin) || (xwin && x - o != 1) || (owin && x != o)    cout << "illigel";
    else if(xwin)    cout << "First player won";
    else if(owin)    cout << "second player won";
    //x - o -> next turn to the first player
    else if(x == o)    cout << "first";
    // x + o < 9 -> not finished the game
    else if((x + o < 9) && (x - o) == 1)    cout << "second";
    else    cout << "draw";
    cout << endl;
}
https://codeforces.com/problemset/problem/3/D
// 3D. Least Cost Bracket Sequence
using namespace std;
int main(){
    // '?' -> jokers
    string pattern; cin >> pattern;
    int m = count(pattern.begin(), pattern.end(), '?');
    vector <pair <int, int> >jokers(m);
    for(int i = 0; i < m; i++){
        cin >> jokers[i].first >> jokers[i].second;
        /* int open, close; cin >> open >> close;
        jokers[i] = {open, close}; */
    }
    vector <bool> isjoker(patter.size(), false);
    int sum = 0;// total cost so far (starting with all ')' replacements)
    for(int i = 0, j = 0; i < pattern.size(); i++){
        if(pattern[i] == '?'){
            isjoker[i] = false;
            sum += joker[j++].second;
            pattern[i] = ')';
        }
    }
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <>>Q;
    // min-heap storing (diff, position) for each '?'
    int st = 0; // balance counter for parentheses
    for(int i = 0, k = 0; i < pattern.size(); i++){
        if(isjoker[i]){
            Q.push({joker[k].first - joker[k].second, i});
            k++;
        } /*
        if (isjoker[i]) {
            int diff = jokers[k].first - jokers[k].second;
            pq.push({diff, i});
            k++;
        }*/
        if(pattern[i] == '(')    ++st;
        else    --st;
        if(st < 0){
            if(!Q.empty()){
                auto [diff, pos] = Q.top();
                Q.pop();
                sum += diff; st += 2;
                pattern[pos] = '(';
            }/*
            if(!Q.empty()){
                pair <int, int> j = Q.top(); Q.pop();
                sum += j.first;
                patter[j.second] = '(';
                st += 2;
            } */
            else    break;
        }
    }
    if(st != 0)    cout << -1;
    else    cout << sum << "\n" << pattern << "\n";
}
using namespace std;
int main(){
    string str; cin >> str;
    int flag = 0, val = 0;
    priority_queue <pair <int, int> >pq;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(')    flag++;
        else if(str[i] == ')')    flag--;
        else{
            flag--;
            int a, b; cin >> a >> b;
            val += b; str[i] = ')';
            q.push(make_pair(b - a, i));
        }
        if(flag < 0){
            if(q.empty())    break;
            flag += 2;
            pair <int, int> tmp = q.top();
            q.pop();
            val -= tmp.first;
            str[tmp.second] = '(';
        }
    }
    if(flag != 0)    cout << -1;
    else    cout << val << "\n" << str << "\n";
}
https://codeforces.com/problemset/problem/4/B
// 4B. Before an Exam
using namespace std;
int main(){
    int days, totaltime; cin >> days >> totaltime;
    vector <int> mintime(days), maxtime(days);
    for(int i = 0; i < days; i++)
        cin >> mintime[i] >> maxtime[i];
    int totalmintime = accumulate(mintime.begin(), mintime.end(), 0);
    int totalmaxtime = accumulate(maxtime.begin(), maxtime.end(), 0);
    if(totaltime < totalmintime || totaltime > totalmaxtime){
        cout << "No"; return 0;
    }
    cout << "YES";
    vector <int> res(days);
    // totaltime - totalmintime = how many hours left to assign beyond the minimum total.
    // maxtime[i] - mintime[i] = how many hours we can still add to this day before hitting its max.
    // extra = min(remaining hours, possible extra for this day).
    for(int i = 0; i < days; i++){
        int extra = min(totaltime - totalmintime, maxtime[i] - mintime[i]);
        res[i] = mintime[i] + extra;
        totaltime -= extra;
        totalmintime += extra;
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    /*
    if(totalmintime <= totaltime && totalmaxtime >= totaltime){
        cout << "YES\n";
        for(int i = 0; i < days; i++){
            int t = min(mintime[i] + totaltime - totalmintime, maxtime[i])
            cout << t << (i + 1 < days) ? ' ' : '\n';
            totaltime -= (t - mintime[i]);
        }
    }
    else    cout << "NO"; */
}
using namespace std;
int main(){
    int day, sum; cin >> day;
    vector <pair <int, int> >vec(day);
    vector <int> res(day);
    int maxtime = 0, mintime = 0;
    for(int i = 0; i < day; i++){
        cin >> a[i].first >> a[i].second;
        mintime += a[i].first;
        maxtime += a[i].second;
        res[i] = a[i].first;
    }
    if(sum < mintime || sum > maxtime){
        cout << "NO";    return 0;
    }
    cout << "YES\n";
    int extra = sum - mintime;
    for(int i = 0; i < day && extra > 0; i++){
        int add = min(a[i].second - a[i].first, extra);
        res[i] += add;
        extra -= add;
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
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
https://codeforces.com/problemset/problem/4/D
// 4D. Mysterious Present
using namespace std; /*
#define MAX 501
int w[MAX], h[MAX];
bool cmp(const int a, const int b){
    if(w[a] == w[b]) return h[a] > h[b];
    else    return w[a] > w[b];
}*/
int main(){
    int n, W, H; cin >> n >> W >> H;
    vector <int> w(n), h(n), idx(n), cnt(n, 1), path(n, -1);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> h[i];
        idx[i] = i;
    }
    // sort(idx, idx + n, cmp);
    //sort discending order
    sort(idx.begin(), idx.end(), [&](int a, int b){
        if(w[a] == w[b])    return h[a] > h[b];
        return w[a] > w[b];
    });
    // check if i can fit inside j.
    // cnt[j] = maximum stack length ending at rectangle j.
    // path[i] = previous rectangle in the stack, initialized to -1 (no previous rectangle).
    //i = 0 is bigger.for that it was skipped
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(w[idx[i]] < w[idx[j]] && h[idx[i]] < h[idx[j]]){
                if(cnt[j] + 1 > cnt[i]){
                    cnt[j] = cnt[i] + 1;
                    path[i] = j;
                }
            }
        }
    }
    int res = 0, best = -1;
    for(int i = 0; i < n; i++){
        if(w[idx[i]] > W && h[idx[i]] > H && cnt[i] > res){
            res = cnt[i];
            best = i;
        }
    }
    cout << res;
    if(best != -1){
        vector <int> seq;
        while(best != -1){
            seq.push_back(idx[best] + 1);
            best = path[best];
        }
        reverse(seq.begin(), seq.end());
        for(size_t i = 0; i < seq.size(); i++){
            if(i > 0)    cout << " ";
            cout << seq[i];
        }
    }/*
    if(best != -1){
        bool check = false;
        while(best != -1){
            if(y)    cout << " ";
            cout << idx[best] + 1;
            best = path[best];
            check = true;
        }
        cout << endl;
    }*/
}
using namespace std;
const int peak = 5010;
int w[peak], h[peak], vis[peak], m = 0;
int index[peak]; //an array of indices used to sort envelopes without moving w[] and h[].
int dp[peak];// stores the maximum chain length starting at envelope u
int pos[peak]; //stores the next envelope in the optimal chain from u.
int idx[peak];// original 1-based indices of envelopes (to print at the end).
int dfs(int u) {
    if (vis[u]) return dp[u];
    vis[u] = 1;
    dp[u] = 1; pos[u] = -1;
    for (int i = u + 1; i < m; i++) {
        if (w[index[i]] > w[index[u]] && h[index[i]] > h[index[u]]) {
            int tmp = dfs(i);
            if (dp[u] < tmp + 1) {
                dp[u] = tmp + 1;
                pos[u] = i;
            }
        }
    }
    return dp[u];
}
int main(){
    int n, W, H; cin >> n >> W >> H;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(a <= W || b <= H)    continue;
        w[m] = a; h[m] = b;
        idx[m] = i + 1; // store original 1-based index
        index[m] = m; // store index for sorting
        m++;
    }
    sort(index, index + m, [&](int x, int y){
        return w[x] < w[y];
    });
    memset(vis, 0, sizeof(vis));
    int res = 0; start = -1;
    for(int i = 0; i < m; i++){
        int tmp = dfs[i];
        if(res < tmp){
            res = tmp; start = i;
        }
    }
    if(res == 0)    cout << "0";
    else{
        cout << res << endl;
        cout << idx[index[start]];
        start = pos[start];
    }
    cout << " ";
}
https://codeforces.com/problemset/problem/5/A
// 5A. Chat Server's Outgoing Traffic
using namespace std;
int main(){
    string str; int len = 0;
    set <string> user;
    while(getline(cin, str)){
        if(str.empty())    continue;
        if(str[0] == '+'){
            str[0] = '@';
            user.insert(str);
        }
        if(str[0] == '-'){
            str[0] = '@'; 
            user.erase(str);
        }
        else {
            size_t pos = str.find(':');
            if(pos != string::npos){
                int strlength = str.size() - pos - 1;
                len += strlength * user.size();
            }
        }
    }
    cout << len;
}
https://codeforces.com/problemset/problem/5/B
// 5B. Center Alignment
using namespace std;
int main(){
    string str; vector <string> vec;
    int maxlen = 0, k;
    while(getline(cin, str)){
        vec.push_back(str);
        k = str.length();
        maxlen = max(maxlen, k);
    } /*
    bool toggle = false;
    for (const string& text : vec) {
        int spaces = maxlen - text.size();
        int left = (spaces + (toggle ? 1 : 0)) / 2;
        int right = spaces - left;

        cout << '*' << string(left, ' ') << text << string(right, ' ') << '*' << '\n';

        if (!text.empty() && spaces % 2) {
            toggle = !toggle;
        }
    }
    cout << string(maxWidth + 2, '*') << '\n'; */
    int len = vec.size();
    int left[len], right[len];
    int flag = 0;
    for(int i = 0; i < vec.size(); i++){
        k = maxlen - vec[i].length();
        if(k % 2 == 0)    left[i] = k / 2;
        else{
            left[i] = (k / 2) + flag;
            flag = 1 - flag;
        }
        right[i] = k - left[i];
    }/*
    cout << string(maxlen + 2, '*') << "\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << '*' << string(left[i], ' ')
        << vec[i] << string(right[i], ' ') << '*' << "\n";
    }
    cout << string(maxlen + 2, '*') << "\n";*/
    for(int i = 0; i < maxlen + 2; i++)
        cout << '*';
    cout << endl;
    for(int i = 0; i < vec.size(); i++){
        cout << '*';
        for(int j = 0; j < left[i]; j++)
            cout << ' ';
        cout << vec[i];
        for(int j = 0; j < right[i]; j++)
            cout << ' ';
        cout << '*';
    }
    for(int i = 0; i < maxlen + 2; i++)
        cout << '*';
}
using namespace std;
int main(){
    string str;
    vector <string> vec;
    int mexlength = 0;
    while(getline(cin, str)){
        vec.push_back(str);
        maxlength = max(maxlength, (int)str.length());
    }
    int flag = 1;
    for(int i = 0; i < maxlength + 2; i++)
        cout << '*';
    cout << endl;
    for(int i = 0; i < vec.size(); i++){
        cout << '*';
        int k = maxlength - vec[i].size();
        int left = k / 2;
        int right = k - left;
        if(k & 1){
            if(flag){
                swap(left, right);
                flag = 0;
            }
            else    flag = 1;
        }
        for(int j = 0; j < left; j++)    cout << " ";
        cout << vec[i];
        for(int j = 0; j < right; j++)    cout << " ";
        cout << "*";
    }
    for(int i = 0; i < maxlength + 2; i++)
        cout << "*";
    cout << endl;
}
https://codeforces.com/problemset/problem/5/C
// 5C. Longest Regular Bracket Sequence
using namespace std;
int main(){
    string str; getline(cin, str);
    int res = 0;
    // set <int> st; st.insert(-1); st.insert(str.size());
    set <int> st{-1, static_cast <int> (str.size)};
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(')    res += 1;
        else    res -= 1;
        if(res < 0){
            st.insert(i); res = 0;
        }
    }
    res = 0;
    for(int i = str.size(); i > 0; i--){
        if(str[i] == ')')    res += 1;
        else    res -= 1;
        if(res < 0){
            st.insert(i); res = 0;
        }
    }
    int maxlen = 0, cnt = 0, lastcut = -1;
    for(auto it = st.begin(); it!= st.end(); it++){
        int len = *it - lastcut - 1;
        if(len > maxlen){
            maxlen = 1;
            cnt = 1;
        }
        else if(len == maxlen && len > 0)    ++cnt;
        lastcut = *it;
    }
    cout << maxlen << " " << (cnt > 0 ? cnt : 1);
}
https://codeforces.com/problemset/problem/5/E
// 5E. Bindian Signalizing
using namespace std;
int main(){
    int n; cin >> n;
    vector <int> a(n), b(n), left(n), right(n), countequal(n + 1);
    int maxval = 0, maxpos = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > maxval){
            maxval = a[i]; maxpos = i;
        }
    }
    // Rotate array so that max element starts at position 0 in 'b'
    for(int i = maxpos; i < n; i++)    b[i - maxpos] = a[i];
    for(int i = 0; i <= maxpos; i++)    b[i + n - maxpos] = a[i];
    countequal[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        right[i] = i + 1;
        while(right[i] < n && b[i] > b[right[i]])
            right[i] = right[right[i]];
        if(right[i] < n && b[i] == b[right[i]]){
            countequal[i] = countequal[right[i]] + 1;
            right[i] = right[right[i]];
        }
    }
    for(int i = 1; i < n; i++){
        left[i] = i - 1;
        while(left[i] > 0 && b[i] >= b[left[i]])
            left[i] = left[left[i]];
    }
    int res = 0;
    for(int i = 1; i < n; i++){
        res += countequal[i];
        if(left[i] == 0 && right[i] == n)    res++;
        else    res += 2;
    }
    cout << res;
}
https://codeforces.com/problemset/problem/6/A
// 6A. Triangle
using namespace std;
int main(){
    int len[4];
    bool segment = false, triangle = false;
    for(int i = 0; i < 4; i++)    cin >> len[i];/*
    sort(len, len + 4);
    for(int i = 0; i < 2; i++){
        int a = len[i], b = len[i + 1], len[i + 2];
        if(a + b > c)    triangle = true;
        else if(a + b == c)    segment = true;
    } */
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            int low_bound = abs(len[i] - len[j]);
            int upper_bound = len[i] + len[j];
            for(int k = j + 1; k < 4; k++){
                if(len[k] == low_bound || len[k] == upper_bound)    segment = true;
                else if(len[k] > low_bound || len[k] < upper_bound)    triangle = true;
            }
        }
    }
    if(triangle)    cout << "TRIANGLE";
    else if(segment)    cout << "SEGMENT";
    else    cout << "IMMPOSSIBLE";
}
using namespace std;
bool istriangle(int a, int b, int c){
    return (a + b > c && b + c > a && c + a > b);
}
bool issegment(int a, int b, int c){
    return ((a + b == c) || (b + c == a) || (c + a == b));
}
int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    vector <int> len = {a, b, c, d};
    bool triangle = false, segment = false;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 4; k++){
                int x = len[i], y = len[j], z = len[k];
                if(istriangle(x, y, z))    triangle = true;
                else if(issegment(x, y, z))    segment = true;
            }
        }
    }
    if(triangle)    cout << "TRIANGLE";
    else if(segment)    cout << "SEGMENT";
    else    cout << "IMMPOSSIBLE";
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
