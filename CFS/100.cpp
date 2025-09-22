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
// fabs = absolute value for doubles.
// fmod(a, b) computes the floating-point remainder of a / b. Equivalent to a % b but for doubles.
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
    int n = round(2 * PI / mini);
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
                dp2[i][j] = min(dp2[i][j], dp[i - 1][j] + matrix[i][j].first);
                dp5[i][j] = min(dp5[i][j], dp[i- 1][j] + matrix[i][j].second);
            }
            if(j > 0){
                dp2[i][j] = min(dp2[i][j], dp[i][j - 1] + matrix[i][j].first);
                dp5[i][j] = min(dp5[i][j], dp[i][j - 1] + matrix[i][j].second);
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
    vector <pair <int, int> >joker(m);
    for(int i = 0; i < m; i++){
        cin >> joker[i].first >> joker[i].second;
        /* int open, close; cin >> open >> close;
        joker[i] = {open, close}; */
    }
    vector <bool> isjoker(patter.size(), false);
    int sum = 0;// total cost so far (starting with all ')' replacements)
    for(int i = 0, j = 0; i < pattern.size(); i++){
        if(pattern[i] == '?'){
            isjoker[i] = true;
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
            int diff = joker[k].first - joker[k].second;
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
                pattern[j.second] = '(';
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
            // Every '?' can either become '(' or ')', with associated costs.
			//If replaced with '(' → cost = a,If replaced with ')' → cost = b
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
    vector <pair <int, int> >a(day);
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
                    cnt[i] = cnt[j] + 1;
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
int main(){
    int n, W, H; cin >> n >> W >> H;
    vector <int> w(n), h(n), id(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(a > W && b > H){
            w.push_back(a);
            h.push_back(b);
            id.push_back(i + 1);
        }
    }
    int m = w.size();
    vector <int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){
        if(w[i] == w[j])    return h[i] < h[j];
        return w[i] < w[j];
    });
    vector <int> dp(m, 1), parent(m, -1);
    int res = 0, best = -1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < i; j++){
            if(w[idx[i]] > w[idx[j]] && h[idx[i]] > h[idx[j]]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if(dp[i] > res){
            res = dp[i];
            best = i;
        }
    }
    cout << res << endl;
    vector <int> seq;
    for(int cur = best; cur != -1; cur = parent[cur])
        seq.push_back(id[idx[cur]]);
    reverse(seq.begin(), seq.end());
    for(int i = 0; i < seq.size(); i++)
        cout << seq[i] << " ";
    cout << endl;
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
        // Between each pair of consecutive cuts, we get a valid region.
        // Its length = *it - lastcut - 1.
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
https://codeforces.com/problemset/problem/5/D
// 5D. Follow Traffic Rules
using namespace std;
int main() {
    double accel, vmax, totalDist, limitPos, limitSpeed;
    cin >> accel >> vmax >> totalDist >> limitPos >> limitSpeed;

    cout << fixed << setprecision(12);

    // Helper: distance needed to reach a given speed from rest
    auto distToSpeed = [&](double speed) {
        return (speed * speed) / (2.0 * accel);
    };

    // Case 1: cannot exceed limitSpeed at all
    if (limitSpeed >= vmax || limitPos <= distToSpeed(limitSpeed)) {
        if (distToSpeed(vmax) >= totalDist) {
            cout << sqrt((2.0 * totalDist) / accel) << "\n";  // never reach vmax
        } else {
            double t_acc = vmax / accel;  // accelerate to vmax
            double t_const = (totalDist - distToSpeed(vmax)) / vmax;
            cout << t_acc + t_const << "\n";
        }
        return 0;
    }

    // Case 2: we can accelerate to limitSpeed before limitPos
    double distAccLimit = distToSpeed(limitSpeed);   // distance to reach limitSpeed
    double distAccMax = distToSpeed(vmax);           // distance to reach vmax
    double distDecMaxToLimit = (vmax * vmax - limitSpeed * limitSpeed) / (2.0 * accel);

    if (limitPos - distAccLimit <= distDecMaxToLimit) {
        // cannot reach vmax before limitPos
        if (distDecMaxToLimit > totalDist - limitPos) {
            // after limitPos, can't reach vmax either
            double t1 = (sqrt(2.0 * accel * limitPos + limitSpeed * limitSpeed / 2.0) - limitSpeed) / accel;
            double t2 = limitSpeed / accel;
            double t3 = (sqrt(2.0 * accel * (totalDist - limitPos) + limitSpeed * limitSpeed) - limitSpeed) / accel;
            cout << 2 * t1 + t2 + t3 << "\n";
        } else {
            // after limitPos, can reach vmax
            double t1 = (sqrt(2.0 * accel * limitPos + limitSpeed * limitSpeed / 2.0) - limitSpeed) / accel;
            double t2 = limitSpeed / accel;
            double t3 = (vmax - limitSpeed) / accel;
            double t4 = (totalDist - limitPos - distDecMaxToLimit) / vmax;
            cout << 2 * t1 + t2 + t3 + t4 << "\n";
        }
    } else {
        // can reach vmax before limitPos
        if (distDecMaxToLimit > totalDist - limitPos) {
            // after limitPos, can't reach vmax
            double t1 = (limitPos - distAccLimit - distDecMaxToLimit) / vmax;
            double t2 = 2 * (vmax - limitSpeed) / accel;
            double t3 = limitSpeed / accel;
            double t4 = (sqrt(2.0 * accel * (totalDist - limitPos) + limitSpeed * limitSpeed) - limitSpeed) / accel;
            cout << t1 + t2 + t3 + t4 << "\n";
        } else {
            // after limitPos, can reach vmax
            double t1 = (limitPos - distAccLimit - distDecMaxToLimit) / vmax;
            double t2 = 3 * (vmax - limitSpeed) / accel;
            double t3 = limitSpeed / accel;
            double t4 = (totalDist - limitPos - distDecMaxToLimit) / vmax;
            cout << t1 + t2 + t3 + t4 << "\n";
        }
    }
    return 0;
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
https://codeforces.com/problemset/problem/6/B
// 6B. President's Office
using namespace std;
int main(){
    int n, m;
    char president; cin >> n >> m >> president;
    vector <string> room(n);
    for(int i = 0; i < n; i++)    cin >> room[i];
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
    set <char> deputies;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(room[i][j] == president){
                for(int d = 0; d < 4; d++){
                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];
                    // int ni = i + dx[d], nj = j + dy[d];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                        char neighbor = room[ni][nj];
                        if(neighbor != president && neighbor != '.')
                            deputies.insert(neighbor);
                    }
                }
            }
        }
    }
    cout << deputies.size();
}
using namespace std;
int n, m; char ch;
vector <vector <char> >vec;
set <char> colors;
void neighbor(int i, int j){
    if(vec[i][j] != '.' && vec[i][j]!= ch)
        colors.insert(vec[i][j]);
}
int main(){
    cin >> n >> m >> ch;
    vec.assign(n + 4, vector <char> (m + 4, '.'));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> vec[i][j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vec[i][j] == ch){
                neighbor(i + 1, j);
                neighbor(i - 1, j);
                neighbor(i, j + 1);
                neighbor(i, j - 1);
            }
        }
    }
    cout << (int)colors.size();
}
https://codeforces.com/problemset/problem/6/C
// 6C. Alice, Bob and Chocolate
using namespace std;
int main(){
    int n; cin >> n;
    vector <int> choco(n);
    for(int i = 0; i < n; i++)    cin >> choco[i];
    int left = 0, right = n - 1;
    int cntalice = 0, cntbob = 0;
    int timealice = 0, timebob = 0;
    while(left <= right){
        if(timealice <= timebob){
            timealice += choco[left++];
            cntalice++;
        }
        else{
            timebob += choco[right--];
            cntbob++;
        }
    }
    cout << cntalice << " " << cntbob << endl;
    // cout << left << " " << n - left << endl;
    /*
    vector <int> choco(n + 5, 0);
    for(int i = 1; i <= n; i++){
        int beat; cin >> beat;
        choco[i] = choco[i - 1] + beat;
    }
    choco[n + 1] = choco[n];
    int left = 0, right = n + 1;
    while(right > left){
        int alice = choco[left];
        int bob = choco[n + 1] - choco[right];
        if(alice <= bob)    left++;
        else if(alice > bob)    right--;
    }
    cout << left << " " << n - left;
    */
}
https://codeforces.com/problemset/problem/6/D
// 6D. Lizards and Basements 2
using namespace std;
const int ax = 25;
bool vis[ax][ax][ax];
int n, a, b; //number of monster, main attack damage, splash attack damage
int health[ax]; // health of each monster
int dp[ax][ax][ax];
// dp[idx][cur][pre] → minimum attacks needed starting from monster idx when:
// cur, pre = current monster's remaining health, previous(idx - 1) monster's remaining health
int path[ax][ax][ax];
int dfs(int idx, int cur, int pre){
    cur = max(cur, 0); pre = max(pre, 0);
    if(idx == n) //last monster
        return (cur = 0) ? 0 : INT_MAX;
    if(vis[idx][cur][pre])    return vis[idx][cur][pre];
    //mark as visited
    vis[idx][cur][pre] = true;
    int &res = dp[idx][cur][pre];
    res = INT_MAX;
    int lb = (pre + b - 1) / b; // hits needed to kill the previous monster via splash:
    // upper bound = max hits needed to ensure current and next monster are not left with huge health:
    int hb = max(lb, max((cur + a - 1) / a, (health[idx + 1] + b) / b));
    for(int j = lb; j <= hb; j++){
        int cost = j + dfs(idx + 1, health[idx + 1] + 1 - j * b, cur - j * a);
        if (cost < res) {
            res = cost;
            path[idx][cur][pre] = j;
        }
        return res;
    }
}
void printPath(int idx, int cur, int pre) {
    cur = max(cur, 0);
    pre = max(pre, 0);
    if (idx == n) return;
    int hits = path[idx][cur][pre];
    for (int i = 0; i < hits; i++)
        cout << idx << " ";
    printPath(idx + 1, health[idx + 1] + 1 - hits * b, cur - hits * a);
}
int main(){
    cin >> n >> a >> b
    // start considering from the second monster (because the first attack is handled as part of initialization).
    for(int i = 1; i <= n; i++)    cin >> health[i];
    memset(vis, false, sizeof(vis));
    int res = dfs(2, health[2] + 1, health[1] + 1);
    cout << res << endl;
    printPath(2, health[2] + 1, health[1] + 1);
    cout << endl;
}
https://codeforces.com/problemset/problem/6/E
// 6E. Exposition
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)    cin >> vec[i];
    int left = 0, lenght = 0;
    multiset <int> window(n);
    vector <int> start;
    for(int right = 0; right < n; right++){
        window.insert(vec[right]);
        while(!window.empty() && (*window.rbegin() - *window.begin()) > k){
            window.erase(window.find(vec[left]));
            left++;
        }
    }
    int cur = (int)window.size();
    if(cur > length){
        length = cur;
        start.clear();
        start.push_back(left);
    }
    else if(cur == length)    start.push_back(left);
    cout << length << " " << (int)start.size() << "\n";
    for(int i = 0; i < start.size(); i++)
        cout << i + 1 << " " << i + length << endl;
}
https://codeforces.com/problemset/problem/7/A
// 7A. Kalevitch and Chess
using namespace std;
int main(){
    vector <bool> row(8, false), col(8, false);
    // bool row[8] = {false}, col[8] = {false};
    string str;
    for(int i = 0; i < 8; i++){
        cin >> str;
        for(int j = 0; j < 8; j++){
            if(str[j] == 'W'){
                row[i] = true; col[j] = true;
            }
        }
    }
    int blockedrow = count(row.begin(), row.end(), true);
    int blockedcol = count(col.begin(), col.end(), true);
    // If all rows and columns are unblocked, output should be 8
    int res = 16 - blockedrow - blockedcol;
    // int res = 16 - count(row, row + 8, true) - count(col, col + 8, true);
    if(res == 16)    res = 8;
    cout << res;
}
https://codeforces.com/problemset/problem/7/B
// 7B. Memory Manager
using namespace std;
int main(){
    int t, m, token = 1; cin >> t >> m;
    vector <int> mem(m, 0);
    while(t--){
        // n = number of consecutive memory blocks to allocate.
        // cntfree = counter of consecutive free blocks found.
        // start = index where free block sequence started
        // m = sizeof the memory
        string cmd; cin >> cmd;
        if(cmd == "alloc"){
            int n; cin >> n;
            int cntfree = 0, start = -1;
            for(int i = 0; i < m; i++){
                if(mem[i] == 0){
                    if(cntfree == 0) start = i;
                    cntfree++;
                    if(cntfree == n){
                        for(int j = start; j < start + n; j++)
                            mem[j] = token;
                        cout << token++ << endl;
                        start = -1;
                        break;
                    }
                }
                else    cntfree = 0;
            }
            if(start != -1 && cntfree < n)
                cout << "NULL" << endl;
        } /*
        if(cmd == "alloc"){
            int n; cin >> n;
            bool allocated = false;
            for(int start = 0; start <= m - n; start++){
                bool canalloc = true;
                for(int j = start; j < start + n; j++){
                    if(mem[j]!= 0){
                        canalloc = false;
                        break;
                    }
                }
                if(canalloc){
                    cout << token << endl;
                    for(int j = start; j < start + n; j++)
                        mem[j] = token;
                    token++;
                    allocated = true;
                    break;
                }
            }
            if(!allocated)    cout << "NULL" << endl;
        } */
        else if(cmd == "erase"){
            int x; cin >> x;
            if(x <= 0){
                cout << "ILLEGEL ERASE ARGUMENT";
                continue;
            }
            bool erased = false;
            for(int i = 0; i < mem.size(); i++){
                if(mem[i] == x){
                    mem[i] = 0;
                    erased = true;
                }
            }
            if(!erased) cout << "ILLEGEL ERASE ARGUMENT";
        } /*
        else if (cmd == "erase") {
            int id; cin >> id;
            if (id < 1) {
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
                continue;
            }
            bool found = false;
            for(int i = 0; i < mem.size(); i++){
                if(mem[i] == id){
                    memory[i] = 0;
                    found = true;
                }
            }
            if (!found) cout << "ILLEGAL_ERASE_ARGUMENT\n";
        } */
        else if(cmd == "defragment"){
           /* int pos = 0;
            for(int i = 0; i < m; i++){
                if(i != pos){
                    mem[pos] = mem[i];
                    mem[i] = 0;
                }
                pos++;
            } */
            vector <int> compacted;
            for(int i = 0; i < mem.size(); i++){
                if(mem[i] != 0)    compacte.push_back(mem[i]);
                while((int)compacted.size() < m)    compacted.push_back(0);
                mem.swap(compacted);
            }
        } /*
        else if (cmd == "defragment") {
            int pos = 0;
            for (int i = 0; i < k; i++) {
                if (mem[i] != 0) {
                    if (pos != i) {
                        mem[pos] = mem[i];
                        mem[i] = 0;
                    }
                    pos++;
                }
            }
        } */
    }
}
https://codeforces.com/problemset/problem/7/C
// 7C. Line
using namespace std;
int gcdext(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0; y = 1;
        return b;
    } /*
    a * x + b * y = gcd(a, b);
    (b mod a) * x1 + a * y1 = gcd(a, b);
    (b mod a) * x1 + a * y1 = (b - (b / a) * a) * x1 + a * y1;
    ax + by = b * x1 + a * (y1 - (b / a) * x1); */
    x = y1 - (b / a) * x1;
    y = x1;

    int x1, y1;
    int g = gcdext(a, b, x1, y1);
    return g;
}
int extgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    int res = extgcd(b, a % b, x, y);
    y -= (a / b) * x; // ax + by = gcd(a, b)
    return res;
}
int main(){
    int a, b, c; cin >> a >> b >> c;
    int x, y;
    // g = gcd(a, b) and some initial (x, y) such that: ax + by = g
    int g = gcdext(a, b, x, y);
    if(c % g != 0){
        cout << -1; // No Solution
        return 0;
    }
    int k = c / g;
    x * = k; y *= k;
    cout << x << " " << y;
    /*
    c = - c; // ax + by + c = 0
    int gcd = extgcd(a, b, x, y);
    if(c % gcd != 0){
        cout << -1;
        return 0;
    }
    x *= c / gcd;
    y *= c / gcd; 
    cout << x << " " << y << endl;
    */
}
https://codeforces.com/problemset/problem/7/D
// 7D. Palindrome Degree
using namespace std;
using ul = unsigned long long int;
const int ax = pow(5, 8);
const int base = pow(5, 3);
int dp[ax];
ul power[ax], hash[2][ax];
// hash[0] -> forward hash for str, hash[1] -> backward hash for str
// dp[] = stores palindromic degrees for prefixes.
// power[] = stores powers of base for hashing
int main(){
    string str; cin >> str;
    int n = (int)str.size();
    string ing = str;
    reverse(ing.begin(), ing.end());
    str = ' ' + str; ing = ' ' + ing;
    power[0] = 1;
    for(int i = 1; i <= n; i++)
        power[i] = power[i - 1] * base;
    for(int i = 1; i <= n; i++)
        hash[0][i] = hash[0][i - 1] * base + (unsigned char)(str[i]);
    for(int i = 1; i <= n; i++)
        hash[1][i] = hash[1][i - 1] * base + (unsigned char)(ing[i]);
    auto get = [&](ul hash[], int l, int r) -> ul{
        if(l > r)    return 0;
        return hash[r] - hash[l - 1] * power[r - l + 1];
    }
    // dp[i] = dp[i/2] + 1 because the first half of a palindrome contributes to its degree.
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(get(hash[0], 1, i) == get(hash[1], n - i + 1, n){
            dp[i] = dp[i / 2] + 1;
            res += dp[i];
        }
    }
    cout << res << endl;
}
using namespace std;
const int ax = pow(5, 8);
//const int modu = pow(5, 8);
const int base = pow(5, 3);
int power[ax];
int main(){
    string str; cin >> str;
    int n = str.size();
    /*vector <int> dp(n + 1, 0);
    int fwdhash = 0, revhash = 0, power = 1;
    int res = 0;
    for(int i = 1; i <= n; i++){
        int x = (unsigned char)(str[i] - 'a');
        fwdhash = (fwdhash * base + x) % modu;
        revhash = (revhash + power * x) % modu;
        if(fwdhash == revhash){
            dp[i] = dp[i / 2] + 1;
            res += dp[i];
        }
        power = (power * base) % modu;
    }
    cout << res; */
    power[0] = 1;
    // power[1] = base, power[2] = base^2
    for(int i = 1; i <= n; i++)
        power[i] = power[i - 1] * base;
    int fwdhash = 0, revhash = 0, len = 0;
    auto extend = [&](int x){
        fwdhash += x * power[len]; // multiply character by base^len and add.
        (revhash *= base) += x;// shift rev_hash left & add char
        ++len;
    }
    vector <int> res(n);
    extend(str[0]);
    res[0] = 1;
    for(int i = 1; i < n; i++){
        extend(str[i]);
        if(revhash == fwdhash)
            res[i] = res[(i - 1) / 2] + 1
    }
    cout << accumulate(begin(res), end(res), 0);
}
https://codeforces.com/problemset/problem/7/E
// 7E. Defining Macros
using namespace std;
map <string, int> mp;
int eval(const string &str, int l, int r){
    // '+', '-'
    for(int i = r - 1, wt = 0; i >= l; i--){
        if(str[i] == ')')    wt++;
        if(str[i] == '(')    wt--;
        if(!wt && (str[i] == '+' || str[i] == '-')){
            int L = eval(str, l, i);
            int R = eval(str, i + 1, r);
            //If operator is - → right-hand side must be “complex enough” (R > 1)
            return L && R && (str[i] != '-' || R > 1);
            
        }
    }
    // '*', '/'
    for(int i = r - 1, wt = 0; i >= l; i--){
        if(str[i] == ')')    wt++;
        if(str[i] == '(')    wt--;
        if(!wt && (str[i] == '*' || str[i] == '/')){
            int L = eval(str, l, i);
            int R = eval(str, i + 1, r);
            // L > 1 && R > 1 → both sides must be "complex enough"
            
            return (L > 1 && R > 1 && (str[i] != '/' || R > 2)) ? 2 : 0;
        }
    }
    // ')', '('
    if(str[l] == '(' && str[r - 1] == ')')
        return eval(str, l + 1, r - 1) ? 3 : 0;
    // variable
    string u = str.substr(l, r - l);
    return mp.count(u) ? mp[u] : 3;
}
int getexpr(){
    string line, cleaned; getline(cin, line);
    for(int i = 0; i < line.size(); i++){
        if(line[i] != ' ')    cleaned += line[i];
    }
    return eval(cleaned, 0, cleaned.size());
}
int main(){
    int n; cin >> n;
    string dummy, name; getline(cin, dummy);
    while(n--){
        cin >> dummy >> name;
        getline(cin, dummy);
        mp[name] = getexpr();
    }
    cout << (getexpr() ? "Ok" : "suspicious");
}
https://codeforces.com/problemset/problem/8/A
// 8A. Train and Peter
using namespace std;
bool func(const string &station, const string &stop1, const station &stop2){
    //station.find(stop1) returns the first index where stop1 occurs, or string::npos if not found.
    size_t pos = station.find(stop1);
    if(pos = string::npos)    return false;
    // check if stop2 occurs after stop1 ends.
    return station.find(stop2, pos + stop1.size()) != station::npos;
}
int main(){
    string station, stop1, stop2; cin >> station >> stop1 >> stop2; /*
    auto func = [](const string &station, const string &stop1, const string &stop2) {
        size_t pos = str.find(stop1);
        return pos != string::npos && station.find(stop2, pos + stop1.size()) != string::npos;
    }; */ /*
    bool forward = false, backward = false;
    size_t pos = s.find(stop1);
    if (pos != string::npos && station.find(stop2, pos + stop1.size()) != string::npos)
        forward = true;
    // check backward
    reverse(station.begin(), station.end());
    pos = station.find(stop1);
    if (pos != string::npos && station.find(stop2, pos + stop1.size()) != string::npos)
        backward = true; */
    bool forward = func(station, stop1, stop2);
    reverse(station.begin(), station.end());
    bool backward = func(station, stop1, stop2);
    
    if (forward && backward) cout << "both";
    else if (forward)        cout << "forward";
    else if (backward)       cout << "backward";
    else                     cout << "fantasy";
    return 0;
}
https://codeforces.com/problemset/problem/8/B
// 8B. Obsession with Robots
using namespace std;
int main(){
    string str; cin >> str;
    set <pair <int, int>> visited;
    bool ok = true;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    /*set<pair<int,int>> visited;
    pair<int,int> pos = {0,0};
    visited.insert(pos);
    for (char c : s) {
        if (c == 'L') pos.first--;
        else if (c == 'R') pos.first++;
        else if (c == 'U') pos.second++;
        else if (c == 'D') pos.second--;
        int cnt = visited.count(pos);
        for (int i = 0; i < 4; i++)
            cnt += visited.count({pos.first + dx[i], pos.second + dy[i]});
        if (cnt > 1) {
            ok = false;
            break;
        }
        visited.insert(pos);
    }*/
    int x = 0, y = 0;
    visited.insert({x, y});
    for(int i = 0; i < str.size(); i++){
        if(str[i] == "L") x--;
        else if(str[i] == "R") x++;
        else if(str[i] == "U") y++;
        else if(str[i] == "D") y--;
        bool ok = true;
        if(visited.count({x, y})) ok = false;
        //count the visited cell
        int cnt = 0;
        for(int i = 0; i < 4; i++)
            cnt += visited.count({x + dx[i], y + dy[i]});
        if(cnt > 1) ok = false;
        visited.insert({x, y});
    }
    cout << (ok ? "OK" : "BUG") << endl;
}
https://codeforces.com/problemset/problem/8/C
// 8C. Looking for Order
using namespace std;
const int ax = 1e5;
int main(){
    int n, X, Y; cin >> n >> X >> Y;
    // n, X, Y -> total points, starting coordinates
    int arr[30], ray[30]; // coordinates they can move
    arr[0] = X; ray[0] = Y;
    // must visit all n points by making multiple trips starting and ending at 0.
    for(int i = 1; i <= n; i++)
        cin >> arr[i] >> ray[i];
    int full = (1 << n); // n =3, full = 8
    vector <int> dp(full, ax); // dp[S] = minimum cost to visit all points in S.
    //s represent the bitmask of full(range) visited points
    vector <int> lst(full, -1); // previous state (for path reconstruction).
    dp[0] = 0;
    int dist[30][30]; //squared dist between i & j
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)
            dist[i][j] = (arr[i] - arr[j]) * (arr[i] - arr[j]) + (ray[i] - ray[j]) * (ray[i] - ray[j]);
    }
    // s -> bitmask of visited points
    for(int s = 0; s < full; s++){
        if(dp[s] == ax)    continue;
        int i;
        //find first unvisited point
        for(int i = 1; i <= n; i++){
            if(!(s & (1 << (i - 1))))
                break;
        }
        if(i > n) continue;
        {   //visit i alone
            // mark point i as visited in the new set T.
            int T = s | (1 << (i - 1));
            //(1 << (i - 1)) = bitmask representing point i.
            int cost = dp[s] + dist[0][i] + dist[i][0];
            if(cost < dp[T]){
                dp[T] = cost;
                lst[T] = s;
            }
        }
        //visit i & j togeather
        for(int j = i + 1; j <= n; j++){
            if(s & (1 << (j - 1))) continue;
            int T = s | (1 << (i - 1)) | (1 << (j - 1));
            int cost = dp[s] + dist[0][i] + dist[i][j] + dist[j][0];
            if (cost < dp[T]) {
                dp[T] = cost;
                lst[T] = s;
            }
        } /*
        for (int j = i; j <= n; j++) {
            if (s & (1 << (j - 1))) continue;
            int T = s | (1 << (i - 1)) | (1 << (j - 1));

            int dx1 = arr[0] - art[i], dy1 = ray[0] - ray[i];
            int dx2 = arr[i] - arr[j], dy2 = ray[i] - ray[j];
            int dx3 = arr[0] - arr[j], dy3 = ray[0] - ray[j];

            int val = dp[s] + dx1*dx1 + dy1*dy1 + dx2*dx2 + dy2*dy2 + dx3*dx3 + dy3*dy3;
            if (val < dp[T]) {
                dp[T] = val;
                lst[T] = s;
            }
        } */
    }
    //output minimum cost
    cout << dp[full - 1] << endl;
    for(int s = full - 1; s; s = lst[s]){
        for(int i = 1; i <= n; i++){
            if((s ^ lst[s]) & (1 << (i - 1)))
                cout << i << " ";
        }
        cout << "0";
    }
    cout << endl;
    /*vector<int> path;
    for (int S = full - 1; S; S = lst[S]){
        path.push_back(0);
        for (int i = 1; i <= n; i++) {
            if ((S ^ lst[S]) & (1 << (i - 1))) 
                path.push_back(i);
        }
        path.push_back(0);
    }
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    cout << endl; */
}
https://codeforces.com/problemset/problem/8/E
// 8E. Beads
using namespace std;
int n, m; // length of the bin string, string what we want
// Counts how many valid canonical strings of length len start with a given ing.
bool valid(const string &str){
    string ing = str;
    string rev = ing; reverse(rev.begin(), rev.end());
    string comp = ing;
    // complement (flip with comp ^= 1, since '0' ^ 1 = '1', '1' ^ 1 = '0')
    for(int i = 0; i < comp.size(); i++)
        comp[i] ^= 1;
    string revcomp = comp; reverse(revcomp.begin(), revcomp.end());
    return (ing < rev && ing < comp && ing < revcomp);
}
long long validcnt(const string &ing, int len){
    // number of positions left to fill after the ing.
    int rem = len - ing.size();
    //mask represents all binary combinations of the remaining positions. There are 2^rem combinations.
    int cnt = 0;
    for(int mask = 0; mask < (1 << rem); ++mask){
        string str = ing;
        for(int i = 0; i < rem; i++)
            str += ((mask >> i) & 1) + '0';
        if(valid(str))    cnt++;
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    string res = "";
    for(int i = 1; i < n; i++){
        int cnt = validcnt(res + "0", n);
        if(m <= cnt) res += '0';
        else {
            m -= cnt; res += '1';
        }
    }
    cout << res;
}
using namespace std;
int n, m;
int arr[55]; //store bits
int dp[55][2][2];
// dp[pos][l][r]
// pos, l, r-> current position in the string, boolean indicating whether the left-side constraint is active or ride sided
// counts the number of valid binary strings from position pos down to the middle, considering symmetry constraints.
int dfs(int pos, int l, int r){
    // If we’ve crossed the middle of the string, the prefix fully determines the string.
    if(pos < n - pos + 1) return 1;
    if(dp[pos][l][r] != -1) return dp[pos][l][r];
    int res = 0;
    // candidate bit at position pos.
    for(int i = 0; i <= 1; i++){
        if(arr[pos]!= -1 && arr[pos] != i)
            continue;
        // candidate bit at mirror position n - pos + 1.
        for(int j = 0; j <= 1; j++){
            if(arr[n - pos - 1] != -1 && arr[n - pos - 1] != j)
                continue;
        }
        // (l && i > j) → If left-limit is active, i cannot exceed its mirror j.
        // (r && i > 1 - j) → If right-limit is active, i cannot exceed complement of mirror.
        // (pos == n - pos + 1 && i != j) → At the exact middle, the digit must mirror itself.
        if((l && i > j) || (r && i > 1 - j) || (pos == n - pos + 1) || (i != j))
            continue;
        // recursive call for next smaller pos
        res += dfs(pos - 1, l && (i == j), r && (i != j));
    }
    return dp[pos][l][r] = res;
}
int main(){
    int n, m; cin >> n >> m;
    m++; //for 1 base indexing
    memset(arr, -1, sizeof(arr));
    memset(dp, -1, sizeof(dp));
    arr[n] = 0; // Start with the last bit a[n] = 0.
    // If the total number of valid strings is less than m
    if(dfs(n, 1, 1) < m) {
        cout << -1 << endl;
        return 0;
    }
    cout << "0"; //first digit
    for(int i = n - 1; i >= 1; i--){
        memset(dp, -1, sizeof(dp));
        arr[i] = 0;
        int sum = dfs(n, 1, 1);
        if(m > sum) {
            m -= sum; arr[i] = 1;
            cout << "1";
        }
        else    cout << "0";
    }
    cout << endl;
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
https://codeforces.com/problemset/problem/9/B
// 9B. Running Student
using namespace std;
int main(){
    int n, busvt, stdvt, ux, uy;
    cin >> n >> busvt >> stdvt >> xu >> yu;
    // n, busvt, stdvt, xu, yu -> total stops, bus velocity, student volocity, coordinates of university
    //bus stops
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    cin >> ux >> uy; //university coordinates
    int idx = 0;
    double mintime = DBL_MAX;
    //took the bus from second stop
    for(int i = 1; i < n; i++){
        double bustime = vec[i] / busvt;
        // distance between stop(which stop the student take bus)to university / stdvt
        double runtime = sqrt(pow(ux - vec[i], 2) + (pow(uy - 0), 2)) / stdvt;
        double totaltime = bustime + runtime;
        if(totaltime <= mintime){
            mintime = totaltime;
            idx = i;
        }
    }
    cout << idx + 1 << endl;
}
https://codeforces.com/contest/9/problem/C
// 9C. Hexadecimal's Numbers
using namespace std;
int n, cnt = 0;
void dfs(int x){
    if(x > n)    return;
    cnt++;
    dfs(x * 10); // append '0'
    dfs(x * 10 + 1); // append '1'
}
int main(){
    cin >> n;
    // dfs(1); cout << cnt;
    queue <long long> q; q.push(1);
    int cnt = 1;
    while(!q.empty()){
        int num = q.front(); q.pop();
        if(num > n)     continue;
        q.push(num * 10); // append '0'
        q.push(num * 10 + 1); // append '1'
        cnt++;
    }
    cout << cnt << endl;
    /* int res = 0;
    for (int len = 1; len <= 9; len++) {
        for (int mask = 0; mask < (1 << (len - 1)); mask++) {
            long long num = 1; 
            for (int k = 0; k < len - 1; k++) {
                num = num * 10 + ((mask >> k) & 1);
            }
            if (num <= n) ans++;
        }
    }
    cout << res << endl; */
}
https://codeforces.com/problemset/problem/9/D
// 9D. How many trees?
using namespace std;
int dp[100][100]; // dp[n][h] = number of binary trees with n nodes and height ≤ h
int main(){
    int n, h; cin >> n >> h; // node,  height
    for(int height = 1; height <= n; ++height){
        dp[0][height - 1] = 1; // For 0 nodes, there’s exactly 1 tree: the empty tree.
        for(int nodes = 1; nodes <= n; nodes++){
            for(int left = 0; left < nodes; ++nodes){
                int right = nodes - left - 1;
                dp[nodes][height] += dp[left][height - 1] * dp[right][height - 1];
            }
        }
    }
    cout << dp[n][n] - dp[n][h - 1];
}
using namespace std;
int main(){
    int n, h; cin >> n >> h;
    // dp[nodes][height]
    vector <vector <int>> dp(n + 1, vector <int> (n + 1, 0));
    dp[0][0] = 1;
    for(int left = 0; left <= n; left++){
        for(int lh = 0; lh <= left; lh++){
            for(int right = 0; right <= n - left; ++right){
                for(int rh = 0; rh <= right; ++rh){
                    int nodestotal = left + right + 1;
                    int totalheight = max(lh, rh) + 1;
                    if(nodestotal <= n)
                        dp[nodestotal][totalheight] += dp[left][lh] * dp[right][rh];
                }
            }
        }
    }
    int res = 0;
    for(int height = h; height <= n; ++height)
        res += dp[n][height];
    cout << res << endl;
}
https://codeforces.com/problemset/problem/9/E
// 9E. Interesting Graph and Apples
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    set<pair<int, int>> edges;
    int selfLoops = 0, multiEdges = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if (u == v) selfLoops++;
        if (edges.count({u, v}) || edges.count({v, u})) multiEdges++;
        edges.insert({u, v});
    }

    // Case 1: self-loop
    if (selfLoops) {
        cout << ((n == 1 && selfLoops == 1) ? "YES\n0" : "NO") << "\n";
        return;
    }

    // Case 2: multiple edges between 2 nodes
    if (multiEdges) {
        cout << ((n == 2 && multiEdges == 1) ? "YES\n0" : "NO") << "\n";
        return;
    }

    set<pair<int, int>> endpoints;
    vector<bool> visited(n + 1, false);

    // DFS to check each component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            stack<int> st;
            st.push(i);
            int start = -1, end = -1;

            while (!st.empty()) {
                int node = st.top();
                st.pop();
                visited[node] = true;

                if ((int)adj[node].size() > 2) {
                    cout << "NO\n";
                    return;
                }

                if ((int)adj[node].size() <= 1) {
                    if (start == -1) start = node;
                    else if (end == -1) end = node;
                    else {
                        cout << "NO\n";
                        return;
                    }
                }

                for (int nei : adj[node]) {
                    if (!visited[nei]) st.push(nei);
                }
            }

            if (end == -1) end = start;
            if (start > end) swap(start, end);
            if (start != -1) endpoints.insert({start, end});
        }
    }

    vector<pair<int, int>> result;
    while (endpoints.size() > 1) {
        auto e1 = *endpoints.begin();
        endpoints.erase(endpoints.begin());
        auto e2 = *endpoints.begin();
        endpoints.erase(endpoints.begin());

        result.push_back({min(e1.first, e2.first), max(e1.first, e2.first)});
        endpoints.insert({max(e1.second, e2.second), max(e1.first, e2.first)});
    }

    if (!endpoints.empty()) {
        auto [s, e] = *endpoints.begin();
        result.push_back({min(s, e), max(s, e)});
    }

    cout << "YES\n";
    cout << result.size() << "\n";
    sort(result.begin(), result.end());
    for (auto [u, v] : result) {
        cout << u << " " << v << "\n";
    }
}
https://codeforces.com/problemset/problem/10/A
// 10A. Power Consumption Calculation
using namespace std;
int main(){
    int n, p1, p2, p3, t1, t2; 
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    vector <pair <int, int>> arr;
    int res = 0, prv = 0;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r; 
        arr.push_back({l, r});
        res += (r - l) * p1;
        
        if(i == 0) continue; 
        //time gap between two mode
        int diff = arr[i].first - arr[i - 1].second;
        // We only want to bill up to t1 minutes at the higher p1 mode
        int left = min(t1, diff);
        res += p1 * left;
        diff -= left;
        //next t2 minutes
        left = min(t2, diff);
        diff -= left;
        res += (p2 * left);
        //remaining minutes
        res += (p3 * diff); /*
        if(i > 0) {
            int diff = l - prv;
            if(gap > t1) {
                res += t1 * p1;
                diff -= t1;
                if(gap > t2) {
                    res += t2 * p2;
                    diff -= t2;
                    res += diff * p3;
                }
                else    res += diff * p2;
            }
            else    res += gap * p1;
        }
        res += (r - l) * p1;
        prv = r; */
    }
    cout << res << endl;
}
https://codeforces.com/problemset/problem/10/B
// 10B. Cinema Cashier
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    // n, k -> number of groups (requests). number of seats per row and also number of rows.
    int mid = (k + 1) / 2;
    // pref[] stores the total "distance" from mid for columns 
    vector <int> pref(k + 1, 0);
    for(int i = 1; i <= k; i++)
        pref[i] = pref[i - 1] + int(abs(i - mid));
    // taken[row][col] = 1 means that seat is already occupied.
    vector <vector <char>> taken(k + 1, vector <char> (k + 1, 0));
    for(int req = 0; req < n; ++req){
        // Each group wants m contiguous seats in the same row.
        int m; cin >> m;
        int mincost = INT_MAX;
        // store the row and column of the best block found.
        int bestrow = -1, beststart = -1;
        for(int row = 1; row <= k; ++row){
            for(int start = 1; start + m - 1 <= k; ++start){
                // start -> leftmost column of a block.
                // end -> last column of the block.
                end = start + m - 1;
                bool isfree = true;
                for(int col = 1; col <= k; ++col){
                    // If any seat is already taken, mark isfree = false. If not free, skip (continue) and move to next block
                    if(taken[row][col]){
                        isfree = false;
                        break;
                    }
                }
                if(!isfree)    continue;
                // Every seat in that block is in the same row, so we just multiply the distance of that row from the middle by m(seats required)
                int rowcost = m * abs(row - mid);
                // computes the column distance cost of a contiguous block of seats in one row.
                int colcost = pref[end] - pref[start - 1];
                int totalcost = rowcost + colcost;
                if(totalcost < mincost){
                    mincost = totalcost;
                    bestrow = row;
                    beststart = start;
                }
            }
        } /*
    // dp[row][col] = 1; seat taken
    vector <vector <int>> dp(k + 2, vector <int> (k + 2, 0));
    int mid = (k + 1) / 2;
    for(int d = 0; d < n; ++d) {
        int m; cin >> m;
        int mincost = INT_MAX;
        int bestrow = -1, beststart = -1;
        for(int row = 1; row <= k; ++row){
            for(int start = 1; start <= k - m + 1; start++){
                bool isfree = true;
                int sum = 0;
                for(int col = start; col < start + m; ++col){
                    if(dp[row][col]){
                        isfree = false;
                        break;
                    }
                    sum += abs(row - mid) + abs(col - mid);
                }
                if(isfree && sum < mincost){
                    mincost = sum;
                    bestrow = row;
                    beststart = start;
                }
            }
        }
    } */
        if(int bestcost == INT_MAX)    cout << -1 << endl;
        else {
            for(int col = beststart; col < beststart + m; ++col)
                taken[bestrow][col] = 1;
                // dp[bestrow][col] = 1;
            cout << bestrow << ' ' << beststart << ' ' << beststart + m - 1 << endl;
        }
    }
}
https://codeforces.com/problemset/problem/10/C
// 10C. Digital Root
using namespace std;
const int MAXN = 1e7;
long long countRoot[10];  // count of numbers with each digital root
int divisors[MAXN+1];     // number of divisors for each number
int primes[MAXN], isComposite[MAXN];
int digitRoot(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return (sum < 10) ? sum : digitRoot(sum);
}
void precomputeDivisors() {
    divisors[1] = 1;
    int totalPrimes = 0;

    for (int i = 2; i <= MAXN; i++) {
        if (!isComposite[i]) {
            divisors[i] = 2;     
            primes[totalPrimes++] = i;
        }
        for (int j = 0; j < totalPrimes; j++) {
            int p = primes[j];
            if (i * p > MAXN) break;
            isComposite[i * p] = 1;

            if (i % p == 0) {
                int temp = i;
                while (temp % p == 0) temp /= p;
                divisors[i * p] = (divisors[i / temp] + 1) * divisors[temp];
                break;
            } else {
                divisors[i * p] = divisors[i] * divisors[p];
            }
        }
    }
}
int main() {
    precomputeDivisors();

    int n; cin >> n;
    long long divisorSum = 0;
    for (int i = 1; i <= n; i++) {
        countRoot[digitRoot(i)]++;
        divisorSum += divisors[i];
    }
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int k = digitRoot(i * j);
            long long pairs = countRoot[i] * countRoot[j];
            ans += pairs * countRoot[k];
        }
    }
    cout << ans - divisorSum << "\n";
    return 0;
}
using namespace std;
int root(int x){
    while(x >= 10){
        int tmp = 0;
        while(x) {
            tmp += x % 10;
            x /= 10;
        }
        x = tmp;
    }
    return x;
}
int main(){
    int n; cin >> n;
    vector <int> freq(n);
    for(int i = 1; i <= n; i++){
        freq[root(i)]++;
        // freq[i % 9]++;
    }
    int sum1 = 0, sum2 = 0;
    // count by digital root freq
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            sum1 += freq[root(i * j)] * freq[i] * freq[j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(root(j) == root(root(i) * root(j / i)))
                sum2++;
        }
    }
    cout << sum1 - sum2 << endl;
    /* int res = 0;
    // count valid triplets(x, y, z)
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            for(int z = 0; z < 9; z++){
                if((x * y - z) % 9 == 0)
                    res += freq[x] * freq[y] * freq[z];
            }
        }
    }
    for(int a = 1; a <= n; a++)
        res -= n / a << " ";
    cout << endl; */
}
https://codeforces.com/problemset/problem/10/D
// 10D. LCIS
using namespace std;
const int ax = 510;
int a[ax], b[ax];
int dp[ax][ax], path[ax][ax];
int n, m;
void printPath(int i, int j, int prev) {
    if (i == 0 || j == 0) return;
    if (path[i][j] == 0) {
        if (j != prev) cout << b[j] << " ";
        return;
    }
    printPath(i - 1, path[i][j], j);
    if (j != prev) cout << b[j] << " ";
}
int main(){
    cin >> n; vector <int> a(n);
    for(int i = 0; i < n; i++)    cin >> a[i];
    cin >> m; vector <int> b(m);
    for(int i = 0; i < m; i++)    cin >> b[i];
    /*
    memset(dp, 0, sizeof(dp));
    memset(path, 0, sizeof(path));
    for(int i = 1; i <= n; i++) {
        int tmp = 0, k = 0;
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            path[i][j] = j;
            if(a[i] > b[j] && tmp < dp[i - 1][j]) {
                tmp = dp[i - 1][j];
                k = j;
            }
            if(a[i] == b[j]) {
                dp[i][j] = tmp + 1;
                path[i][j] = k;
            } 
        }
    }
    // Find the max LCIS length and endpoint
    int ans = 0, pos = 0;
    for (int j = 1; j <= m; j++) {
        if (dp[n][j] > ans) {
            ans = dp[n][j];
            pos = j;
        }
    }
    cout << ans << endl;
    if (ans > 0) {
        printPath(n, pos, 0);
        cout << endl;
    } */
    vector <vector <int>> dp(n + 1, vector <int>(m + 1, 0));
    vector <int> parent(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1;
                for(int k = 1; k < i; k++){
                    if(a[k - 1] < a[i - 1] && dp[k][j] + 1 > dp[i][j]){
                        dp[i][j] = dp[k][j] + 1;
                        parent[i] = k;
                    }
                }
            }
            else    dp[i][j] = dp[i][j - 1];
        }
    }
    // find position of LCIS
    int pos = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i][m] > dp[pos][m])    pos = i;
    }
    vector <int> LCIS;
    while(pos) {
        LCIS.push_back(a[pos - 1]);
        pos = parent[pos];
    }
    reverse(LCIS.begin(), LCIS.end());
    for(int i = 0; i < LCIS.end(); i++)
        cout << LCIS[i] << " ";
    cout << endl;
}
https://codeforces.com/problemset/problem/10/E
// 10E. Greedy Change
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 1; i <= n; i++)    cin >> arr[i];
    int res = -1;// res will store the smallest counterexample number
    // i represents the coin you are testing (arr[i]), and j represents another coin smaller than it.
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int rem = arr[i] - 1;
            int tmp = 1;
            for(int k = i + 1; k <= j; k++){
                // counts how many coins are used (non-greedy strategy).
                tmp += rem / arr[k];
                rem %= arr[k];
            }
            int cnt = rem = arr[i] - 1 - rem + arr[j];
            int greedy = 0;
            for(int k = 1; k <= n; k++) {
                // number of coins greedy uses.
                greedy += rem / arr[k];
                rem %= arr[k];
            }
            if(tmp < greedy && (res == -1 || cnt < res))    res = cnt;
        }
    }
    cout << res << endl;
}
https://codeforces.com/problemset/problem/11/A
// 11A. Increasing Sequence
using namespace std;
int main(){
    int n, d; cin >> n >> d;
    int a[2001];
    for(int i = 0; i < n; i++)    cin >> a[i];
    int ans = 0, div = 0, sub = 0;
    for(int i = 1; i < n; i++){
        if(a[i-1] >= a[i]){
            sub = a[i-1] - a[i];
            if(sub == 0){
                ans++;
                a[i] += d;
            }
            else{
                sub++;
                div = sub / d;
                if(sub % d != 0)    div++;
                a[i] += div * d;
                ans += div;
            }
        }
    }
    cout << ans << endl;
}
using namespace std;
int main(){
    int n, d; cin >> n >> d;
    vector <int> vec(n);
    for(int i = 1; i < n; i++)    cin >> vec[i];
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(vec[i] <= vec[i - 1]){
            int need = vec[i - 1] + 1 - vec[i];
            int steps = (need + d - 1) / d;
            vec[i] += steps * d;
            cnt += steps;
        }
    }
    cout << cnt << endl;
}
https://codeforces.com/problemset/problem/11/B
// 11B. Jumping Jack
using namespace std;
int main(){
    int n; cin >> n;
    n = abs(n);
    int res = 0, steps = 0;
    for(int i = 1;; i++) {
        sum += i;
        if(sum >= n && (sum - n) % 2 == 0) {
            cout << i << endl;
            break;
        }
    }/*
    while(res < n || (res - n) % 2 != 0) {
        steps++;
        res += steps;
    }
    cout << steps; */
}
https://codeforces.com/problemset/problem/11/C
// 11C. How Many Squares?
using namespace std;
int main(){
    set <pair <int, int>> vertics;
    set <vector <int>> edges;
    for(int i = 0; i < 4; i++){
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        edges.insert({x1, y1, x2, y2});
        edges.insert({x2, y2, x1, y1});
        vertics.insert({x1, y1});
        vertics.insert({x2, y2});
    }
    bool ok = (vertics.size() == 4);
    int minx = INT_MAX, maxx = INT_MIN;
    int miny = INT_MAX, maxy = INT_MIN;
    for(auto &p : vertics) {
        x = p.first; y = p.second;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    vector <vector <int>> req = {
        {minx, miny, minx, maxy}, {minx, miny, maxx, miny}, 
        {minx, maxy, maxx, maxy}, {maxx, maxy, maxx, miny} 
    };
    for(auto &e : req) {
        if(!edges.count(e))
            ok = false;
    }
    cout << (ok ? "YES" : "NO");
}
using namespace std;
int main(){
    vector <pair <pair <int, int>, pair <int, int>>> seg(4);
    for(int i = 0; i < 4; i++){
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        seg[i] = { {x1, y1}, {x2, y2} };
    }
    // collect unique points
    set <pair <int, int>> points;
    for(auto &s : seg) {
        points.insert(s.first);
        points.insert(s.second);.
    }
    if(points.size() != 4) {
        cout << "NO" << endl;
        return 0;
    }
    // compute bounding rectangle
    int minx = INT_MAX, maxx = INT_MIN;
    int miny = INT_MAX, maxy = INT_MIN;
    for(auto &p : points) {
        x = p.first; y = p.second;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    // corners of the axis aligned rectangle
    vector <pair <int, int>> corners = { 
        {minx, miny}, {minx, maxy}, 
        {maxx, miny}, {maxx, maxy} };
    set <pair <int, int>> setcorner(corner.begin(), corner.end());
    if(setcorner != points) {
        cout << "NO" << endl;
        return 0;
    }
    // expected four rectangle side
    set <pair <pair <int, int>, pair <int, int>>> ex;
    auto addedge = [&](pair <int, int> &a, pair <int, int> &b) {
        if(a > b)    swap(a, b);
        ex.insert({a, b});
    };
    addedge({minx, miny}, {minx, maxy});
    addedge({minx, miny}, {maxx, miny});
    addedge({maxx, maxy}, {minx, maxy});
    addedge({maxx, maxy}, {maxx, miny});
    set <pair <pair <int, int>, pair <int, int>>> given;
    for(auto &s : seg) {
        pair <int, int> a = s.first;
        pair <int, int> b = s.second;
        if(a == b) {
            cout << "NO" << endl;
            return 0;
        }
        if(a > b) swap(a, b);
        given.insert({a, b});
    }
    cout << (given == ex ? "YES" : "NO");
}
https://codeforces.com/problemset/problem/11/D
// 11D. A Simple Task
using namespace std;
const int ax = 20;
// vector <vector <int>>grid[ax];
vector <int> adj[ax];
int dp[1 << ax][ax];
int dfs(int start, int node, int parent, int mask){
    if(dp[mask][node] != -1)
        return dp[mask][node];
    int cnt = 0;
    for(int next : adj[node]){
        if(next == parent)    continue;
        //cycle
        if(next == start)    cnt++;
        //already visited
        else if(mask & (1 << next))
            continue;
        else cnt += dfs(start, next, node, mask | (1 << next));
    }
    return dp[mask][node] = cnt;
}
int cntcycle(int node, int mask, int parent){
    if(dp[node][mask] != -1)
        return dp[node][mask];
    int res = 0;
    for(int child : grid[node]){
        if(mask & (1 << child)){
            if(child == parent && __builtin_popcount(mask) > 2)
                res++; //completed cycle
        }
        else{
            if(child > parent) //avoid double counting
                res += cntcycle(child, mask | (1 << child), parent);
        }
    }
    return dp[node][mask] = res;
}
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // grid[u].push_back(v);
        // grid[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for(int i = 0; i < n; i++){
        res += dfs(i, i, -1, 1 << i);
        // cntcycle(i, 1 << i, i);
        // res += dp[i][1 << i] / 2; // each cycle counted twice
    }
    cout << res / 2 << endl;
}
using namespace std;
using LL = long long;
const int MAXN = 19;
LL dp[1 << MAXN][MAXN];
bool visited[1 << MAXN][MAXN];
int adj[MAXN][MAXN];
int n, m;
// Count cycles using bitmask DP
LL dfs(int mask, int start, int u) {
    if (visited[mask][u]) return dp[mask][u];
    visited[mask][u] = true;

    LL &ans = dp[mask][u];
    ans = 0;

    for (int v = start; v < n; v++) {
        if (!adj[u][v]) continue;

        // If we reached start and it's not just the edge start-u
        if (v == start && mask != ((1 << v) | (1 << u))) {
            ans++;
        }
        // Visit unvisited node
        else if (v != start && !(mask & (1 << v))) {
            ans += dfs(mask | (1 << v), start, v);
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u][v] = adj[v][u] = 1;
    }
    LL totalCycles = 0;
    for (int i = 0; i < n; i++) {
        totalCycles += dfs(1 << i, i, i);
    }

    // Each cycle counted twice (once in each direction)
    cout << totalCycles / 2 << "\n";
    return 0;
}
using namespace std;
const int MAXN = 19;
int n, m;
int g[MAXN][MAXN];
long long dp[1<<MAXN][MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--; 
        g[u][v] = g[v][u] = 1;
    }
    long long ans = 0;
    for (int s = 0; s < n; s++) {
        int maskSize = 1 << s;
        for (int i = 0; i < maskSize; i++)
            for (int j = 0; j <= s; j++)
                dp[i][j] = 0;

        dp[0][s] = 1;
        for (int mask = 0; mask < maskSize; mask++) {
            for (int last = 0; last <= s; last++) {
                if (!dp[mask][last]) continue;
                // count cycles back to starting node
                if (g[last][s]) ans += dp[mask][last];

                for (int next = 0; next < s; next++) {
                    if ((mask & (1 << next)) == 0 && g[last][next]) {
                        dp[mask | (1 << next)][next] += dp[mask][last];
                    }
                }
            }
        }
    }
    // Each cycle is counted twice in undirected graph
    cout << (ans - m) / 2 << "\n";
}
https://codeforces.com/problemset/problem/11/E
// 11E. Forward, march!
using namespace std;
int main() {
    string s; cin >> s;
    int n = s.size();
    string t;
    vector<int> insertPos; // positions where we inserted 'X'
    int pos = 0; 
    string need = "LR";

    auto prev = [&](int i) { return i == 0 ? n - 1 : i - 1; };

    for (int i = 0; i < n; i++) {
        if (s[i] != 'X' && s[i] != need[t.size() % 2]) {
            t += 'X';
            if (s[i] != s[prev(i)]) insertPos.push_back(pos);
        }
        if (s[i] != 'X') pos++;
        t += s[i];
    }

    if (t.size() % 2) {
        if (s[0] != s[n - 1] || s[0] == 'R') insertPos.push_back(pos);
        t += 'X';
    }
    int m = t.size();
    int match = 0;

    for (int i = 0; i < m; i++) {
        if (t[i] != 'X' && t[i] == need[i % 2]) match++;
    }

    for (int i = 0; i + 1 < insertPos.size(); i++) {
        if (2 * match > m && insertPos[i] == insertPos[i + 1] - 1) {
            match--;
            m -= 2;
            i++;
        }
    }

    int result = match * 100000000ll / m;
    printf("%d.%06d", result / 1000000, result % 1000000);

    return 0;
}
using namespace std;
using ld = long double;
const ld eps = 5e-10;

// Check function: whether a given mid value is feasible
bool check(const vector<char>& a, int n, ld mid) {
    vector<ld> dpL(n + 1, 0), dpR(n + 1, 0);
    dpL[0] = 0;
    dpR[0] = -mid;

    for (int i = 1; i <= n; i++) {
        dpL[i] = max(dpR[i-1] - mid, 0.0L);
        dpR[i] = max(dpL[i-1] - mid, 0.0L);

        if (a[i] == 'L') dpR[i] += 1;
        if (a[i] == 'R') dpL[i] += 1;
    }

    return dpL[n] > 0;
}
int main() {
    string s; cin >> s;
    vector<char> a;
    int n = s.size();
    // Insert 'X' at needed positions
    if (s.front() == s.back() && s.front() == 'R') a.push_back('X');

    for (int i = 0; i < n; i++) {
        a.push_back(s[i]);
        if (i + 1 < n && s[i] == s[i+1] && s[i] != 'X') a.push_back('X');
    }

    if (a.front() == a.back() && a.back() == 'L') a.push_back('X');
    n = a.size();
    a.insert(a.begin(), ' '); // 1-based indexing

    ld l = 0, r = 1;
    while (r - l >= eps) {
        ld mid = (l + r) / 2;
        if (check(a, n, mid)) l = mid;
        else r = mid;
    }
    int x = (l + eps) * 1e8;
    printf("%d.%06d\n", x / 1000000, x % 1000000);
    return 0;
}
using namespace std;
const int N = 2e6 + 5;
const double eps = 1e-8;
int n;
char a[N];
string s;
double dp[N][2];

bool check(double mid) {
    dp[0][0] = 0;
    dp[0][1] = -mid;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1] - mid + (a[i] == 'R'), dp[i-1][0] - mid);
        dp[i][1] = max(dp[i-1][0] - mid + (a[i] == 'L'), dp[i-1][1] - mid);
    }
    return dp[n][0] >= 0;
}

int main() {
    cin >> s;
    int len = s.size();
    s = " " + s; // make 1-based indexing
    n = 0;

    if (s[1] == 'R' && s[len] == 'R') a[++n] = 'X';
    a[++n] = s[1];
    for (int i = 2; i <= len; i++) {
        if (s[i] != 'X' && s[i] == s[i-1]) a[++n] = 'X';
        a[++n] = s[i];
    }
    if (s[1] == 'L' && s[len] == 'L') a[++n] = 'X';

    double l = 0, r = 100;
    while (r - l >= eps) {
        double mid = (l + r) / 2.0;
        if (check(mid / 100.0)) l = mid;
        else r = mid;
    }
    printf("%.6f\n", floor(r * 1e6) / 1e6);
    return 0;
}
https://codeforces.com/problemset/problem/12/A
// 12A. Super Agent
using namespace std;
int main(){
    vector <vector <char>> grid(3, vector <char> (3));
    // vector <string> grid(3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cin >> grid[i][j];
    }
    //for(int i = 0; i < 3; i++)
        //cin >> grid[i];
    bool ok = true; /*
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == 'X' && grid[2 - i][2 - j] != 'X'){
                    ok = false; break;
            }
        }
        if(!ok) break;
    } */
    for(int i = 0; i < 3 && ok; i++){
        for(int j = 0; j < 3 && ok; j++){
            if(grid[i][j] == 'X' && grid[2 - i][2 - j] != 'X'){
                ok = false;
            }
        }
    } /*
    for(int i = 0; i < 3 && ok; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] != grid[2 - i][2 - j]){
                ok = false; break;
            }
        }
    } */
    cout << (ok ? "YES" : "NO");
}
https://codeforces.com/problemset/problem/12/B
// 12B. Correct Solution?
using namespace std;
int main(){
    string str, ing; cin >> str >> ing;
    sort(str.begin(), str.end());
    if(str[0] == '0') {
        for(size_t i = 1; i < str.size(); i++){
            if(str[i] != '0') {
                swap(str[0], str[i]);
                break;
            }
        }
    }
    int i = 0; /*
    while(i < str.size() && str[i] == '0')
        i++;
    if(i < str.size())    swap(str[0], str[i]); */ /*
    while (str.size() > 1 && str[0] == '0')
        next_permutation(str.begin(), str.end()); */
    cout << (str == ing ? "Ok" : "Wrong answer");
}
using namespace std;
int main(){
    int n; string str; cin >> n >> str;
    string tmp = "";
    while(n > 0){
        tmp += char('0' + n % 10); n /= 10;
    }
    sort(tmp.begin(), tmp.end());
    if (tmp[0] == '0') {
        for (size_t i = 1; i < tmp.size(); ++i) {
            if (tmp[i] != '0') {
                swap(tmp[0], tmp[i]);
                break;
            }
        }
    }
    cout << (tmp == str ? "OK" : "WRONG_ANSWER") << endl;
}
https://codeforces.com/problemset/problem/12/C
// 12C. Fruits
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector <int> vec(n), tor;
    for(int i = 0; i < n; i++) cin >> vec[i];
    map <string, int> freq;
    for(int i = 0; i < k; i++){
        string str; cin >> str;
        freq[str]++;
    }
    for(auto &p : freq) tor.push(p.second);
    // for(auto &[key, val] : freq) tor.push_back(val);
    sort(vec.begin(), vec.end());
    sort(tor.begin(), tor.end(), greater <int> ());
    int minsum = 0, maxsum = 0;
    int sz = tor.size();
    for(int i = 0; i < sz; i++) {
        minsum += tor[i] * vec[i];
        maxsum += tor[i] * vec[n - 1 - i];
    }
    cout << maxsum << " " << minsum << endl;
}
https://codeforces.com/problemset/problem/12/D
// 12D. Ball
using namespace std;
int fenwick[1e4];
void update(int idx, int val, int n){
    while(idx <= n){
        fenwick[idx] = max(fenwick[idx], val);
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx > 0){
        res = max(res, fencwick[idx]);
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    int n; cin >> n;
    vector <int> vec(n + 1), tor(n + 1), val(n + 1);
    vector <int> comp;
    for(int i = 1; i <= n; i++)    cin >> vec[i];
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        comp.push_back(val[i]);
    }
    for(int i = 1; i <= n; i++)    cin >> tor[i];
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    /*
    for(int i = 1; i <= n; i++) {
        val[i] = n - (lower_bound(comp.begin(), comp.end(), val[i]) - comp.begin());
    } */
    vector <int> idx(n);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(), [&](int x, int y){
        //if(vec[x] != vec[y]) return vec[x] > vec[y]; 
        if(vec[x] != vec[y]) return vec[x] < vec[y];
        if(val[x] != val[y]) return val[x] > val[y];
        // return tor[x] > tor[y];
        return tor[x] < tor[y];
    }); /*
    int alive = 0, i = 0;
    while(i < n) {
        int j = i;
        while(j < n && vec[idx[j]] == vec[idx[i]])    j++;
        // check alive
        for(int k = j - 1; k >= i; k--) {
            if(query(val[idx[k]] - 1) <= tor[idx[k]])
                alive++;
        }
        for(int k = i; k < j; k++)
            update(val[idx[k]], tor[idx[k]], n);
        i = j;
    }
    cout << n - alive << endl; */
    map<int, int> ma; // key: intelligence, value
    ma[-1e9] = 1e9; 
    ma[1e9] = -1e9;
    int count = 0;
    for (int k = n-1; k >= 0; k--) {
        int idx_k = idx[k];
        auto it = ma.upper_bound(val[idx_k]);
        if (it->second > r[idx_k])
            count++; 
        else {
            if (ma[val[idx_k]] < tor[idx_k])
                ma[val[idx_k]] = tor[idx_k];
            it = ma.lower_bound(val[idx_k]);
            auto prev = it; prev--;
            while (prev->second < tor[idx_k]) {
                auto to_erase = prev;
                if (prev == ma.begin()) break;
                prev--;
                ma.erase(to_erase);
            }
        }
    }
    cout << count << "\n";
}
using namespace std;
const int maxn = 5e5 + 100;
int a[maxn], b[maxn], c[maxn], id[maxn], num[maxn], vis[maxn], t[maxn], tmp_id[maxn];
int BIT[maxn], cnt;
map<int,int> mp;
int lowbit(int x){ return x & -x; }
void update(int x, int d){
    while(x <= cnt){
        BIT[x] += d;
        x += lowbit(x);
    }
}
int query(int x){
    int ret = 0;
    while(x){
        ret += BIT[x];
        x -= lowbit(x);
    }
    return ret;
}

void cdq(vector<int>& idx, int l, int r){
    if(l == r) return;
    int m = (l + r) / 2;
    cdq(idx, l, m);
    cdq(idx, m+1, r);

    int i = l, j = m+1, p = 0;
    vector<int> tmp(r-l+1);
    while(i <= m || j <= r){
        if(i <= m && (j > r || b[idx[i]] > b[idx[j]])){
            update(t[idx[i]], num[idx[i]]);
            tmp[p++] = idx[i++];
        } else {
            vis[idx[j]] += query(cnt) - query(t[idx[j]]);
            tmp[p++] = idx[j++];
        }
    }
    for(int k = l; k <= m; k++) update(t[idx[k]], -num[idx[k]]);
    for(int k = 0; k < r-l+1; k++) idx[l+k] = tmp[k];
}
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++){
        cin >> c[i];
        id[i] = i;
        num[i] = 1;
    }
    // compress c
    vector<int> tmp_c(c+1, c+n+1);
    sort(tmp_c.begin(), tmp_c.end());
    tmp_c.erase(unique(tmp_c.begin(), tmp_c.end()), tmp_c.end());
    for(int i=1; i<=n; i++)
        t[i] = lower_bound(tmp_c.begin(), tmp_c.end(), c[i]) - tmp_c.begin() + 1;
    cnt = tmp_c.size();

    // sort by a desc, b asc, c asc
    sort(id+1, id+n+1, [&](int x, int y){
        if(a[x] != a[y]) return a[x] > a[y];
        if(b[x] != b[y]) return b[x] < b[y];
        return c[x] < c[y];
    });
    // merge duplicates
    int tot = 1;
    for(int i=2; i<=n; i++){
        if(a[id[i]] == a[id[tot]] && b[id[i]] == b[id[tot]] && c[id[i]] == c[id[tot]]){
            num[id[tot]]++;
        } else {
            tot++;
            id[tot] = id[i];
        }
    }

    cdq(vector<int>(id+1, id+tot+1), 0, tot-1);
    int ans = 0;
    for(int i=1; i<=tot; i++) if(vis[id[i]]) ans += num[id[i]];
    cout << ans << "\n";
}
using namespace std;
const int maxn = 500010;
int n;
int A[maxn], B[maxn], C[maxn];
int h[maxn], idx[maxn];
// Compare indices instead of struct
bool cmp(int i, int j) {
    return (A[i] == A[j] && B[i] < B[j]) || (A[i] > A[j]);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        h[i] = B[i];
    }
    for (int i = 0; i < n; i++) cin >> C[i];

    // Sort by A desc, then B asc, using indices
    iota(idx, idx + n, 0);
    sort(idx, idx + n, cmp);

    // Coordinate compress B
    sort(h, h + n);
    for (int i = 0; i < n; i++) {
        B[i] = n - (lower_bound(h, h + n, B[i]) - h);
    }
    // BIT array stored in h
    memset(h, 0, sizeof(int) * (n + 1));

    int ans = 0;
    for (int t = 0; t < n; t++) {
        int i = idx[t];
        int tmp = 0;
        for (int j = B[i] - 1; j; j -= j & -j) {
            tmp = max(tmp, h[j]);
        }
        if (tmp > C[i]) ans++;
        for (int j = B[i]; j <= n; j += j & -j) {
            h[j] = max(h[j], C[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
https://codeforces.com/problemset/problem/12/E
// 12E. Start of the season
using namespace std;
int main(){
    int n; cin >> n;
    int m = n - 1;
    vector <vector <int>>vec(n, vector <int> (n));
    for(int i = 0; i < m; i++){
        int val = i + 1;
        for(int j = 0; j < m; j++){
            vec[i][j] = val; val++;
            if(val > m) val = 1;
        }
    }
    for(int i = 0; i < m; i++){
        vec[i][i] = 0;
        vec[i][m] = vec[i][i];
        vec[m][i] = vec[i][i];
    }
    vec[m][m] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
using namespace std;
vector <vector <int>> matching(int n){
    assert(n % 2 == 0);
    int m = n - 1;
    vector <vector <pair <int, int>>>match(m);
    for(int a = 0; a < m; ++a){
        match[a].push_back({n - 1, a});
        int x = a, y = a;
        for(int i = 0; i < n / 2 - 1; ++i){
            --x; if(x < 0)    x += m;
            ++y; if(y >= m)    y -= m;
            match[a].push_back({x, y});
        }
    }
    //convert to adj matrix
    vector <vector <int>> mat(n, vector <int> (n));
    for(int k = 0; k < m; ++k){
        for(auto [i, j] : match[k])
            mat[i][j] = mat[j][i] = k + 1;
    }
    return mat;
}
vector <vector <int>>symmsqr(int n){
    vector <vector <int>> mat(n, vector <int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            mat[i][j] = (i + j) % n;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
            mat[j][i] = mat[i][j];
    }
    return mat;
}
int main(){
    int n; cin >> n;
    assert(n % 2 == 0) // only even complete graph
    auto graph = matching(n);
    //auto graph = symmsqr(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}
https://codeforces.com/problemset/problem/13/A
// 13A. Numbers
using namespace std;
int main(){
    int n; cin >> n;
    int sum = 0;
    for(int base = 2; base < n; ++base) {
        int x = n;
        while(x) {
            sum += x % base;
            x /= base;
        }
    }
    int denom = n - 2;
    int g = gcd(sum, denom);
    cout << sum / g << " " << denom / g << endl;
}
https://codeforces.com/problemset/problem/13/B
// 13B. Letter A
using namespace std;
int dot(pair <int, int> &p, pair <int, int> &q) {
    return p.first * q.first + p.second * q.second;
}
int cross(pair <int, int> &p, pair <int, int> &q) {
    return p.first * q.second - p.second * q.first;
}
bool checkratio(pair <int, int> &p, pair <int, int> &q) {
    int a = dot(p, q), b = dot(q, q);
    return cross(p, q) == 0 && b <= 5 * a && 5 * a <= 4 * b;
}
bool func(pair <int, int> ma, pair <int, int> mb, pair <int, int> la, pair <int, int> lb, pair <int, int> ra, pair <int, int> rb) {
    pair <int, int> lv = {
        lb.first - la.first, lb.second - la.second };
    pair <int, int> rv = {
        rb.first - ra.first, rb.second - ra.second };
    pair <int, int> mav = {
        ma.first - la.first, ma.second - la.second };
    pair <int, int> mbv = {
        mb.first - ra.first, mb.second - ra.second };
    return (la == ra && cross(lv, rv) != 0 && dot(lv, rv) >= 0 &&
    checkratio(mav, lv) && checkratio(mbv, rv);
}
int main(){
    int t; cin >> t;
    while(t--) {
        pair <int, int> grid[3][2];
        for(int i = 0; i < 3; i++)
            cin >> grid[i][0].first >> grid[i][0].second >> grid[i][1].first >> grid[i][1].second;
        bool ok = false;
        for(int i = 0; i < 2 && !ok; ++i) {
            if(i)    swap(grid[0][0], grid[0][1]);
            for(int j = 0; j < 2 && !ok; ++j) {
                if(j)    swap(grid[1][0], grid[1][1]);
                for(int k = 0; k < 2 && !ok; ++k) {
                    if(k)    swap(grid[2][0], grid[2][1]);
                    for(int l = 0; l < 3 && !ok; l++) {
                        if(func(grid[l][0], grid[l][1], grid[(l + 1) % 3][0], grid[(l + 1) % 3][1], grid[(l + 2) % 3][0], grid[(l + 2) % 3][1]))
                            ok = true;
                    }
                    if(k)    swap(grid[2][0], grid[2][1]);
                }
                if(j)    swap(grid[1][0], grid[1][1]);
            }
            if(i)    swap(grid[0][0], grid[0][1]);
        }
        cout << (ok ? "YES" : "NO");
    }
}
https://codeforces.com/problemset/problem/13/C
// 13C. Sequence
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int res = 0, det = 0;
    priority_queue <int> pq;
    /*for(int i = 1; i <= n; i++){
        if(!pq.empty() && pq.top() > arr[i]) {
            res += pq.top() - arr[i];
            pq.pop();
            pq.push(arr[i]);
        }
        pq.push(arr[i]);
    } */
    for(int i = 1; i <= n; i++){
        int pos = arr[i] - det;
        res += pos;
        pq.push(pos); pq.push(pos);
        pq.pop();
        b[i] = pq.top() + det;
    }
    for(int i = n - 1; i >= 1; i--) 
        b[i] = min(b[i], b[i + 1] - 1);
    vector <int> tmp;
    while(!pq.empty()) {
        tmp.push_back(pq.top());
        pq.pop();
    }
    int last = 0;
    while(!tmp.empty()){
        res -= (tmp.back() - last) * tmp.size();
        last = tmp.back();
        tmp.pop_back();
    }
    cout << res << endl;
}
https://codeforces.com/problemset/problem/13/D
// 13D. Triangles
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector <int> ax(n), ay(n), bx(m), by(m);
    for(int i = 0; i < n; i++) cin >> ax[i] >> ay[i];
    for(int i = 0; i < m; i++) cin >> bx[i] >> by[i];
    
    // precompute blue points between red points
    vector <vector <vector <bool>>> dp(n, vector <vector <bool>>(n, vector <bool>(m, false)));
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = 0; k < m; k++){
                int tmp = (ax[j] - ax[i]) * (by[k] - ay[i]) - (bx[k] - ax[i]) * (ay[j] - ay[i]);
                if(tmp > 0) dp[i][j][k] = true;
                else dp[j][i][k] = true;
            }
        }
    }
    auto cross = [&](int i, int j, int k) ->int {
            (ax[j] - ax[i]) * (ay[k] - ay[i]) - (ax[k] - ax[i]) * (ay[j] - ay[i]); };
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = i + 1; k < n; k++){
                if(cross(i, j, k) > 0) {
                    bool valid = true;
                    for(int t = 0; t < m; ++t){
                        if(dp[i][j][t] && dp[j][k][t] && dp[k][i][t])
                            valid = false;
                    }
                    if(valid) res++;
                }
                else {
                    bool valid = true;
                    for(int t = 0; t < m; ++t){
                        if(dp[i][k][t] && dp[k][j][t] && dp[j][i][t])
                            valid = false;
                        
                    }
                    if(valid) res++;
                }
            }
        }
    }
    cout << res << endl;
}
using namespace std;
const int MAXN = 505;
int ax[MAXN], ay[MAXN];   // points in set A
int bx[MAXN], by[MAXN];   // points in set B
int f[MAXN][MAXN];
int n, m, s;
// cross product (u × v > 0)
inline bool vec(int ux, int uy, int vx, int vy) {
    return ux * vy - vx * uy > 0;
}
// check if c lies inside triangle (a,b,vertical strip)
inline bool calc(int ax, int ay, int bx, int by, int cx, int cy) {
    if (cy < ay || cy >= by) return false;
    return vec(cx - ax, cy - ay, bx - ax, by - ay);
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> ax[i] >> ay[i];
    for (int i = 1; i <= m; i++)
        cin >> bx[i] >> by[i];

    // sort by y-coordinate
    vector<int> idxA(n), idxB(m);
    iota(idxA.begin(), idxA.end(), 1);
    iota(idxB.begin(), idxB.end(), 1);

    sort(idxA.begin(), idxA.end(), [&](int i, int j){ return ay[i] < ay[j]; });
    sort(idxB.begin(), idxB.end(), [&](int i, int j){ return by[i] < by[j]; });
    // remap arrays according to sorting
    vector<int> tmpx(n+1), tmpy(n+1);
    for (int i = 1; i <= n; i++) { tmpx[i] = ax[idxA[i-1]]; tmpy[i] = ay[idxA[i-1]]; }
    for (int i = 1; i <= n; i++) { ax[i] = tmpx[i]; ay[i] = tmpy[i]; }

    tmpx.resize(m+1); tmpy.resize(m+1);
    for (int i = 1; i <= m; i++) { tmpx[i] = bx[idxB[i-1]]; tmpy[i] = by[idxB[i-1]]; }
    for (int i = 1; i <= m; i++) { bx[i] = tmpx[i]; by[i] = tmpy[i]; }

    // precompute f[i][j]
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                f[i][j] += calc(ax[i], ay[i], ax[j], ay[j], bx[k], by[k]);
            }
        }
    }
    // count triangles
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                s += (f[i][j] + f[j][k] == f[i][k]);
            }
        }
    }
    cout << s << endl;
    return 0;
}
https://codeforces.com/problemset/problem/13/E
// 13E. Holes
using namespace std;
const int ax = 1e5;
const int tim = 447;
int n, m, arr[ax], lst[ax], cnt[ax];
void update(int i) {
    if(i + arr[i] > n || (i / tim)!= (i + arr[i]) / tim){
        lst[i] = i; cnt[i] = 0;
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = n; i >= 1; i--)
        update(i);
    while(m--) {
        int type, x, y; cin >> type >> x;
        if(type == 0) {
            cin >> y; arr[x] = y;
            for(int i = x; i >= 1 && i / tim == x / tim; i--)
                update(i);
        }
        else {
            int last = lst[x], res = 0;
            while(x <= n) {
                res += cnt[x] + 1;
                last = lst[x];
                x = last + arr[last];
            }
            cout << last << " " << res;
        }
    }
}
using namespace std;
const int MAXN = 1e6 + 123;
int block = 320; // sqrt(n) block size
int n, q;
int a[MAXN], cnt[MAXN], nxt[MAXN], last[MAXN];
// Perform jump query
void query(int id) {
    int ans = 0;
    while (id <= n) {
        ans += cnt[id];
        if (nxt[id] > n) break;
        id = nxt[id];
    }
    cout << last[id] << ' ' << ans << '\n';
}
// Update value at position id
void update(int id, int val) {
    a[id] = val;
    // Update current block from id backward
    for (int i = id; i >= 1 && i / block == id / block; i--) {
        if (i + a[i] > n) {
            nxt[i] = n + 1;
            last[i] = i;
            cnt[i] = 1;
        } else if (i / block == (i + a[i]) / block) {
            nxt[i] = nxt[i + a[i]];
            last[i] = last[i + a[i]];
            cnt[i] = cnt[i + a[i]] + 1;
        } else {
            nxt[i] = i + a[i];
            last[i] = i;
            cnt[i] = 1;
        }
    }
}
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // process blocks
    for (int i = n; i >= 1; i--) {
        if (i + a[i] > n) {
            nxt[i] = n + 1;
            last[i] = i;
            cnt[i] = 1;
        } else if (i / block == (i + a[i]) / block) {
            nxt[i] = nxt[i + a[i]];
            last[i] = last[i + a[i]];
            cnt[i] = cnt[i + a[i]] + 1;
        } else {
            nxt[i] = i + a[i];
            last[i] = i;
            cnt[i] = 1;
        }
    }
    while (q--) {
        int t, x, y; cin >> t;
        if (t == 1) {
            cin >> x; query(x);
        } else {
            cin >> x >> y;
            update(x, y);
        }
    }
}
int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
#include <bits/stdc++.h>
using namespace std;

const int mum = 350;
const int MAXN = 101000;

int a[MAXN], store[MAXN], nxt[MAXN], n;
// Preprocess one block
void calc(int blockIdx) {
    int start = blockIdx * mum;
    int end = min(n, (blockIdx + 1) * mum);
    for (int i = end - 1; i >= start; --i) {
        int nextIdx = i + a[i];
        if (nextIdx < end && nxt[nextIdx] < end) {
            store[i] = store[nextIdx] + 1;
            nxt[i] = nxt[nextIdx];
        } else {
            nxt[i] = nextIdx;
            store[i] = 1;
        }
    }
}
// Perform jump query from index idx
void get(int idx) {
    int steps = 0;
    while (nxt[idx] < n) {
        steps += store[idx];
        idx = nxt[idx];
    }
    steps += store[idx];
    cout << idx + 1 << " " << steps << "\n";
}
int main() {
    int m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    // Preprocess all blocks
    for (int i = (n + mum - 1) / mum - 1; i >= 0; --i) {
        calc(i);
    }
    while (m--) {
        int type; cin >> type;
        if (type == 1) {
            int p; cin >> p;
            get(p - 1);
        } else {          // Update
            int p, q; cin >> p >> q;
            a[p - 1] = q;
            calc((p - 1) / MAGIC);
        }
    }
    return 0;
}
https://codeforces.com/problemset/problem/14/A
// 14A. Letter
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector <string> grid(n);
    for(int i = 0; i < n; i++)    cin >> grid[i];
    int minrow = n, maxrow = -1;
    int mincol = m, maxcol = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '*'){
                minrow = min(minrow, i);
                maxrow = max(maxrow, i);
                mincol = min(mincol, j);
                maxcol = max(maxcol, j);
            }
        }
    }
    // if there are '*' char do nothing
    if(maxrow == -1)    return 0;
    for(int i = minrow; i <= maxrow; i++){
        for(int j = mincol; j <= mincol; j++)
            cout << grid[i][j] << ' ';
        cout << endl;
    }
}
https://codeforces.com/problemset/problem/14/B
// 14B. Young Photographer
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    // Intersection of all intervals[L, R]
    int l = INT_MIN, r = INT_MAX;
    //vector <pair <int, int>> segs(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        //segs.emplace_back(a, b);
        l = max(l, a);
        r = min(r, b);
    }
    if(l > r)    cout << -1 << endl;
    if(x >= l && r <= r)    cout << 0 << endl;
    else    cout << min(abs(x - l), abs(x - r));
    /*
    sort(segs.begin(), segs.end());
    for(int i = 0; i < segs.size(); ++i) {
        int a = segs[i].first;
        int b = segs[i].second;
        //Intersections become empty
        if(b < l || a > r) {
            cout << -1 << endl;
            return 0;
        }
        l = max(l, a); r = min(r, b);
    }
    if(x >= l && x <= r) cout << 0 << endl;
    else cout << min(abs(x - l), abs(x - r)) << endl; */
}
https://codeforces.com/problemset/problem/14/C
// 14C. Four Segments
using namespace std;
int sqrdist(pair <int, int> &a, pair <int, int> &b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}
int main(){
    vector <pair <int, int>>vec(4);
    for(int i = 0; i < 4; i++){
        // int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        // vec.push_back({x1, y1});
        // vec.push_back({x2, y2});
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    if(unique(vec.begin(), vec.end()) != vec.end()){
        cout << "NO" << endl;
        return 0;
    }
    vector <int> dists;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++)
            dists.push_back(sqrdist(vec[i], vec[j]));
    }
    sort(dists.begin(), dists.end());
    // square condition: four equal sides, two equal diag, diag = 2 * sides
    if(dists > 0 && dists[0] == dists[1] &&
    dists[1] == dists[2] && dists[2] == dists[3] &&
    dists[4] == dists[5] && dists[4] == 2 * dists[0])
        cout << "YES" << endl;
    else    cout << "NO" << endl;
    /*
    map <pair <int, int> int>freq;
    int xcnt = 0, ycnt = 0;
    for(int i = 0; i < 4; i++){
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        freq[{x1, y1}]++;
        freq[{x2, y2}]++;
        // segments must not be points
        if(x1 == x2 && y1 || y2) {
            cout << "NO" << endl;
            return 0;
        }
        // check if vertical or horizontal
        if(x1 == x2)    ycnt++;
        else if(y1 == y2)    xcnt++;
        else {
            cout << "NO"; return 0;
        }
    }
    //every corner must be appear exactly twice
    for(int i = 0; i < freq.size(); i++){
        if(freq[i].second != 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    // must have two horizontal or two vertical segments
    if(xcnt != 2 || ycnt != 2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES"; */
}
https://codeforces.com/problemset/problem/14/D
// 14D. Two Paths
using namespace std;
pair <int, int> dfs(int u, int p) {
    // best1 = longest child path from u.
    // best2 = second longest child path from u.
    // diameter = best diameter found in subtrees or through u.    
    int best1 = 0, best2 = 0, diameter = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        auto [len, sub] = dfs(v, u);
        len++;
        if (len > best1) {
            best2 = best1; best1 = len; 
        }
        else if (len > best2) best2 = len;
        diameter = max(diameter, sub);
    }
    diameter = max(diameter, best1 + best2);
    return {best1, diameter};
}
// BFS that avoids traversing the forbidden edge (u,v) in either direction
pair<int,int> farthest_from(int src, const vector<vector<int>>& adj, pair<int,int> forbidden) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0; q.push(src);
    int farNode = src, farDist = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] > farDist) {
            farDist = dist[u];
            farNode = u;
        }
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if ((u == forbidden.first && v == forbidden.second) ||
                (u == forbidden.second && v == forbidden.first)) {
                continue;
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {farNode, farDist};
}
// farthest from start -> u
// farthest from u -> diameter
int diameter(int start, const vector <vector <int>> &adj, pair <int, int> forbidden) {
    pair <int, int> p = fartest(start, adj, forbidden);
    pair <int, int> q = fartest(p.first, adj, forbidden);
    return q.second;
}
int main(){
    int n; cin >> n;
    vector <vector <int>> adj(n + 1);
    vector <pair <int, int>> edges(n - 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }
    int best = 0;
    for(int i = 0; i < edges.size(); i++){
        // compute component diameter that contain e.first when edge e is removed
        pair <int, int> e = edges[i];
        pair <int, int> forbid = e;
        int d1 = diameter(e.first, adj, forbid);
        int d2 = diameter(e.second, adj, forbid);
        // diameter in component at rooted u without edge(u, v)
        //int d1 = dfs(edges[i].first, edges[i].second).second;
        // diameter in component at rooted v without edge(u, v)
        //int d2 = dfs(edges[i].second, edges[i].first).second;
        best = max(best, d1 * d2);
    }
    cout << best;
}
https://codeforces.com/problemset/problem/14/E
// 14E. Camels
using namespace std;
int dp[21][4][21]; // dp[len][last][turns]
// turn happen when change direction
// how many ways you can walk n steps in 4 directions, making exactly 2t-1 turns.
int main(){
    int n, t; cin >> n >> t; // length, turn
    for(int d = 0; d < 4; ++d)
        dp[1][d][0] = 1;
    // len, last -> he current sequence length we’re building up to.the direction of the last step in the current sequence
    //prv, k -> the direction of the second-to-last step, he number of turns so far in the shorter sequence (len-1 length).
    for(int len = 2; len <= n; ++len) {
        for(int last = 0; last < 4; last++){
            for(int prv = 0; prv < 4; ++prv){
                //no turns
                if(last = prv)    continue;
                for(int k = 0; k < 20; ++k){
                    // last < prev -> is this a left turn
                    // k % 2 -> what type of turn we expect next (even = left, odd = right).
                    int add = ((last < prv) != (k % 2));
                    dp[len][last][k + add] += dp[len - 1][prv][k];
                }
            }
        }
    }
    int res = 0; 
    for(int d = 0; d < 4; ++d)
        res += dp[n][d][2 * t - 1];
    cout << res << endl;
    /*int dp[25][15][5][2]; // dp[length][turn][last][state]
    // state = 0(non turn) 1(turn)
    for(int last = 2; last <= 4; ++last)
        dp[2][0][last][0] = last - 1;
    for(int len = 3; len <= n; ++len){
        for(int turn = 0; turn <= t; ++turn){
            for(int last = 1; last <= 4; ++last){
                for(int prv = 1; prv <= 4; prv++){
                    if(prv == last) continue;
                    if(prv < last) {
                        dp[len][turn][last][0] = dp[len - 1][turn][prv][0];
                     dp[len][turn][last][1] = dp[len - 1][turn][prv][0];
                    }
                    else {
                        if(turn > 0){
                            dp[len][turn][last][1] += dp[len - 1][turn][prv][1];
                     dp[len][turn][last][1] += dp[len - 1][turn - 1][prv][0];
                        }
                        
                    }
                }
            }
        }
    }
    int res = 0;
    for(int last = 1; last <= 4; ++last)
        res += dp[n][t][last][1];
    cout << res << endl; */
}
https://codeforces.com/problemset/problem/15/A
// 15A. Cottage Village
using namespace std;
int main(){
    int n, t; cin >> n >> t;
    vector <float> pos(n), width(n);
    for(int i = 0; i < n; i++)
        cin >> pos[i] >> width[i];
    // at least 2 gaps: before the first house and after the last houses
    int cnt = 2; 
    /* vector <float> ordi(n);
    iota(ordi.begin(), ordi.end(), 0);
    sort(ordi.begin(), ordi.end(), [&](int i, int j){
        return pos[i] < pos[j];
    });
    for (int i = 1; i < n; i++) {
        int dist = 2 * (pos[ordi[i]] - pos[ordi[i - 1]]);
        int sum = width[ordi[i]] + width[ordi[i - 1]];
        if (dist > 2 * t + sum) cnt += 2;   // enough for two extra gaps
        else if (dist == 2 * t + sum) cnt += 1; // exactly one extra gap
    } */
    vector <pair <float, float>> houses;
    for(int i = 0; i < n; i++)
        houses.push_back({pos[i], width[i]});
    sort(houses.begin(), houses.end());
    for(int i = 1; i < n; i++) {
    // houses[i].second / 2.0 -> half the width = how far the house extends from its center
        float gap = houses[i].first - houses[i - 1].first - (houses[i].second / 2.0) - (houses[i - 1].second / 2.0);
        if (fabs(gap - t) < 1e-6) cnt += 1;   // exactly fits one house
        // enough space for two houses
        else if (gap > t) cnt += 2;
    }
    /* vector <pair <long double, long double >>houses;
    for(int i = 0; i < n; i++){
        long double x, y; cin >> x >> y;
        houses.push_back({x - y / 2, x + y / 2});// store left and right edges
    }
    sort(houses.begin(), houses.end());
    int cnt = 2;
    for (int i = 0; i < n - 1; i++) {
        long double gap = houses[i + 1].first - houses[i].second;
        if (fabs(gap - t) < 1e-9) cnt += 1;
        else if (gap > t) cnt+= 2;       
    } */
    cout << cnt << endl;
}
https://codeforces.com/problemset/problem/15/B
// 15B. Laser
using namespace std;
int main(){
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    /*
    int dy = abs(y1 - y2); // vertical dst
    int dx = abs(x1 - x2); // horizontal dst
    int res = 2 * dx * dy; //covered area
    
    if(dy * 2 > m && dx * 2 > n)
        res -= (2 * dy - m) * (2 * dx - n);
    else if(dy * 2 > m && dx * 2 < n)
        res += (2 * dy - m) * (n - 2 * dx);
    else if(dy * 2 < m && dx * 2 > n)
        res += (m - 2 * dy) * (2 * dx - n);
    */
    int res = n * m - 2 * (n - dx) * (m - dy);
    // (n - dx) * (m - dy) = size of the unlit central area (the “hole” where the laser never goes).
    if(2 * dx < n && 2 * dy < m)
        res += (n - 2 * dx) * (m - 2 * dy);
    cout << res << endl;
}
https://codeforces.com/problemset/problem/15/C
// 15C. Industrial Nim
using namespace std;
int func(int x) {
    switch(x % 4) {
        case 0 : return x;
        case 1 : return 1;
        case 2 : return x + 1;
        default : return 0;
    }
}
int main(){
    int n; cin >> n;
    int nim = 0;
    for(int i = 0; i < n; i++){
        // intervals
        int x, len; cin >> x >> len;
        nim ^= func(x - 1);
        nim ^= func(x + len - 1);
        // nim ^= func(x + len - 1) ^ func(x - 1);
        /*
        // if x is odd shift to even start
        if(x & 1) {
            nim ^= x; --m; ++x;
        }
        // contribution from pair of numbers
        if((len >> 1) & 1) nim ^= 1;
        // contribution from last odd elements
        if(len & 1) nim ^= (x + len - 1); */
    }
    cout << (nim ? "tolik" : "bolik");
}
https://codeforces.com/problemset/problem/15/D
// 15D. Map
using namespace std;
using ll = long long;
using Item = tuple<ll,int,int>; // (cost, r, c)
// build 2D prefix sums (pre has size (n+1)x(m+1))
vector<vector<ll>> build_prefix(const vector<vector<int>>& G){
    int n = G.size(), m = G[0].size();
    vector<vector<ll>> pre(n+1, vector<ll>(m+1,0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + G[i][j];
    return pre;
}
ll rect_sum(const vector<vector<ll>>& pre, int r, int c, int a, int b){
    // sum of a x b block with top-left (r,c), 0-based
    return pre[r+a][c+b] - pre[r][c+b] - pre[r+a][c] + pre[r][c];
}

// sliding minimum by rows (window width = b)
vector<vector<int>> row_min_sliding(const vector<vector<int>>& G, int b){
    int n = G.size(), m = G[0].size(), W = m - b + 1;
    vector<vector<int>> H(n, vector<int>(W));
    for(int i=0;i<n;i++){
        deque<int> dq;
        for(int j=0;j<m;j++){
            while(!dq.empty() && G[i][dq.back()] >= G[i][j]) dq.pop_back();
            dq.push_back(j);
            if(j >= b-1){
                if(dq.front() <= j-b) dq.pop_front();
                H[i][j-(b-1)] = G[i][dq.front()];
            }
        }
    }
    return H;
}
// sliding minimum by columns on H (window height = a) -> M size (n-a+1) x (m-b+1)
vector<vector<int>> col_min_sliding(const vector<vector<int>>& H, int a){
    int n = H.size(), W = H[0].size(), R = n - a + 1;
    vector<vector<int>> M(R, vector<int>(W));
    for(int j=0;j<W;j++){
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && H[dq.back()][j] >= H[i][j]) dq.pop_back();
            dq.push_back(i);
            if(i >= a-1){
                if(dq.front() <= i-a) dq.pop_front();
                M[i-(a-1)][j] = H[dq.front()][j];
            }
        }
    }
    return M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    if(!(cin >> n >> m >> a >> b)) return 0;
    vector<vector<int>> G(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> G[i][j];

    auto pre = build_prefix(G);
    auto H   = row_min_sliding(G, b); // n x (m-b+1)
    auto M   = col_min_sliding(H, a); // (n-a+1) x (m-b+1)

    int R = n - a + 1, C = m - b + 1;
    vector<Item> items; items.reserve(max(0,R*C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            ll s = rect_sum(pre, i, j, a, b);
            ll mn = M[i][j];
            ll cost = s - mn * 1ll * a * b;
            items.emplace_back(cost, i, j);
        }
    }

    sort(items.begin(), items.end()); // by cost, then r, then c

    vector<vector<char>> used(R, vector<char>(C, 0));
    vector<tuple<int,int,ll>> answer;
    int need = (n*m) / (a*b); // optional upper bound

    for(auto &it : items){
        if((int)answer.size() >= need) break;
        ll cost; int i,j;
        tie(cost, i, j) = it;
        if(used[i][j]) continue;

        // region of top-lefts that would overlap this block
        int rlo = max(0, i - a + 1), rhi = min(R-1, i + a - 1);
        int clo = max(0, j - b + 1), chi = min(C-1, j + b - 1);

        bool conflict = false;
        for(int ii=rlo; ii<=rhi && !conflict; ++ii)
            for(int jj=clo; jj<=chi; ++jj)
                if(used[ii][jj]) { conflict = true; break; }
        if(conflict) continue;

        for(int ii=rlo; ii<=rhi; ++ii)
            for(int jj=clo; jj<=chi; ++jj)
                used[ii][jj] = 1;

        answer.emplace_back(i+1, j+1, cost); // output 1-based
    }

    cout << answer.size() << '\n';
    for(auto &t : answer){
        int x,y; ll c; tie(x,y,c) = t;
        cout << x << ' ' << y << ' ' << c << '\n';
    }
    return 0;
}
https://codeforces.com/problemset/problem/15/E
// 15E. Triangles
using namespace std;
const int mod = 1e9 + 9;
const int ax = 1e5;
int add(int a, int b) {
    a += b;
    if(a >= mod)    a -= mod;
    return a;
}
int mul(int a, int b) {
    return (int)a * b % mod;
}
int power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = mul(res, a);
        a = mul(a, a); b >>= 1;
    }
    return res;
}
int main(){
    int n; cin >> n;
    int arr[n];
    arr[0] = 1;
    for(int i = 1; i <= n; i++)
        arr[i] = add(arr[i - 1], arr[i - 1]);
    int now = 4, cnt = 0;
    for(int i = 2; i <= n / 2; i++) {
        now = mul(now, sub(arr[i], 3));
        cnt = add(cnt, now);
    }
    int res = add(mul(mul(cnt, cnt), 2), mul(cnt, 8));
    res = add(res, 10);
    cout << res << endl;
    /*
    int res = 2;
    int curr = 1, sum = 1, prv = 1;
    for(int i = 4; i <= n; i += 2){
        res = (res + sum * 4 % mod) % mod;
        prv = (prv + curr * 4 % mod) % mod;
        curr = (curr * 2) % mod;
        sum = (sum * prv) % mod;
    }
    cout << (2 * res * res + 2) % mod; */
}

https://codeforces.com/problemset/problem/15/A
// 15A. Cottage Village
using namespace std;
int main(){
    int n; cin >> n; // number of intervals
    double k; cin >> k; // required distance between points placed outside intervals.
    vector <pair <double, double>> interval(n);
    for(int i = 0; i < n; i++){
        double x, y; cin >> x >> y;
        intervals[i] = {x - y / 2, x + y / 2};
    }
    sort(intervals.begin(), intervals.end());
    int res; = 2;
    for(int i = 1; i < n; i++){
        double gap = intervals[i].first - intervals[i - 1].second;
        if(gap == k)    res += 1;
        else if(gap > k)    res += 2;
    }
    cout << res;
}
https://codeforces.com/problemset/problem/15/B
// 15B. Laser
using namespace std;
int main(){
    int n, m, x1, x2, y1, y2;
    cin >> n >> m >> x1 >> x2 >> y1 >> y2;
    // n, m = number of rows & columns
    // (x1, y1) and (x2, y2) = coordinates of two given cells
    int dxl = min(x1, x2) - 1;// columns are left of the leftmost of the two x’s.
    int dxr = n - max(x1, x2); // columns are right of the rightmost of the two x’s.
    int dyu = m - max(y1, y2); // rows are above the higher of the two y’s.
    int dyd = min(y1, y2) - 1; // rows are below the lower of the two y’s.
    int res = n * m - 2 * (1 + dxl + dxr) * (1 + dyd + dyu);
    int sx = max(0LL, 1 + min(x1, x2) + dxr - max(x1, x2) + dxl); // overlap width along x.
    int sy = max(0LL, 1 + min(y1, y2) + dyd - max(y1, y2) + dyu; // overlap height along y.
    res += sx * sy; //overlapping region
    cout << res;
}
https://codeforces.com/problemset/problem/15/C
// 15C. Industrial Nim
using namespace std;
int XOR(int x){
    if(x % 4 == 0) return x;
    if(x % 4 == 1) return 1;
    if(x % 4 == 2) return x + 2;
    return 0;
    /* int ones = (x + 1) / 2;
    int res = ones & 1;
    if((x + 1) % 2)    res ^= x;
    return res; */
}
int main(){
    int n; cin >> n;
    int res = 0;
    while(n--){
        int a, b; cin >> a >> b;
        b += a - 1;
        res ^= (XOR(b) ^ XOR(a - 1));
    }
    cout << (res ? "tolik" : "bolik") << endl;
}
https://codeforces.com/problemset/problem/16/A
// 16A. Flag
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    char arr[101][101];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == arr[i + 1][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            if(arr[i][j] != arr[i][j + 1]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES";
}
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector <string> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i]; 
    /*
    for(int i = 0; i < n; i++){
        char ch = vec[i][0];
        for(int j = 0; j < m; j++){
            if(vec[i][j] != ch){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(vec[i][0] == vec[i + 1][0]){
            cout << "NO" << endl;
            return 0;
        }
    } */
    for(int i = 0; i < n; i++){
        if(!all_of(vec[i].begin(), vec[i].end(), [&](char ch){
            return ch = vec[i][0];
        })){
            cout << "NO" << endl;
            return 0;
        }
        if(i > 0 && vec[i][0] == vec[i - 1][0]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    string prevRow;
    bool valid = true;
    for (int i = 0; i < n; ++i) {
        string row; cin >> row;
        for (int j = 1; j < m; ++j) {
            if (row[j] != row[0]) {
                valid = false;
                break;
            }
        }
        if (i > 0 && row[0] == prevRow[0]) 
            valid = false;
        if (!valid) break;
        prevRow = row;
    }
    cout << (valid ? "YES" : "NO") << endl;
}
https://codeforces.com/problemset/problem/16/B
// 16B. Burglar and Matches
using namespace std;
int main(){
    //n -> capacity
    int n, m; cin >> n >> m;
    vector <pair <int, int>> matches(m);
    for(int i = 0; i < m; i++){
        cin >> matches[i].second >> matches[i].first;
        //prices, boxes -> value, quantity
        /*int boxes, prices; cin >> boxes >> prices;
        matches[i] = {prices, boxes}; */
    }
    // sort(matches.begin(), matches.end());
    // reverse(matches.begin(), matches.end());
    /*sort(matches.begin(), matches.end(), [](pair <int, int> &x, pair <int, int> &y){
        return x.first > y.first;
    });
    int res = 0;
    for(int i = 0; i < m && n > 0; i++){
        int take = min(n, matches[i].second);
        res += take * matches[i].first;
        n -= take;
    } */
    sort(matches.begin(), matches.end(), greater <pair <int, int>>());
    int res = 0;
    for(int i = 0; i < m; i++){
        if(matches[i].second <= n){
            res += matches[i].second * matches[i].first;
            n -= matches[i].second;
        }
        else {
            res += n * matches[i].first;
            n = 0;
        }
        if(n == 0)    break;
    }/*
    multimap <int, int, greater<int>> marr;
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        marr.insert(pair <int, int> (y, x));
    }
    multimap <int, int> ::iterator itr;
    int count = 0, res = 0;
    for (itr = marr.begin(); itr != marr.end(); ++itr){
        count += itr->second;
        if(count >= n){
            itr->second = itr->second - (count - n);
            res += itr->first * itr->second;
            break;
        }
        sum += itr->first * itr->second;
    }*/
    cout << res;
}
https://codeforces.com/problemset/problem/16/C
// 16C. Monitor
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int x, y, a, b; cin >> x >> y >> a >> b;
    int g = gcd(a, b);
    // int g = __gcd(a, b);
    a /= g; b /= g;
    
    int mini = min(x / a, y / b);
    cout << a * k << " " << b * k << endl;
}
https://codeforces.com/problemset/problem/16/D
// 16D. Logging
int getTime(const string &s) {
    int h = stoi(s.substr(1, 2)) % 12; 
    // 12-hour format
    int m = stoi(s.substr(4, 2));
    if (s[7] == 'p') h += 12;          
    // add 12 hours for PM
    return h * 60 + m;                  
    // total minutes since midnight
}
using namespace std;
int main(){
    //number of message
    int n; cin >> n;
    cin.ignore();
    //day ->counts the number of days needed
    // prv ->stores the time of the previous message
    // cnt-> counts how many consecutive messages have the exact same timestamp.
    int day = 1, prv = -1, cnt = 0;
    string str;
    for(int i = 0; i < n; i++){
        getline(cin, str);
        /* int h = (str[1] - '0') * 10 + (str[2] - '0');
        h %= 12;
        int m = (str[4] - '0') * 10 + (str[5] - '0');
        if(str[7] == 'p')    h += 12;
        int now = h * 60 + m; */
        int now = getTime(str);
        if(prv != -1){
            if(now < prv){
                day++; cnt = 1;
            }
            else if(now == prv){
                cnt++;
                if(cnt == 1){
                    // same time appears 11 time -> new day
                    day++; cnt = 1;
                }
            }
            else    cnt = 1;
        }
        prv = now;
    }
    cout << day;
}
using namespace std;
int main(){
    int n; cin >> n;
    int day = 1, cnt = 1, prv = -1;
    for(int i = 0; i < n; i++){
        char dummy, maridiem;
        int h, m; string str;
        cin >> dummy >> h >> dummy >> m >> meridiem;
        getline(cin, str);
        if(h == 12)    h = 0;
        if(meridiem == 'p')    h += 12;
        int time = h * 60 + m;
        if (i > 0) {
            if (time < prevTime || (time == prevTime && count == 10)) {
                days++;
                count = 1;
            else if (time == prevTime)
                count++;
            else count = 1;
        }
        prevTime = time;
    }
    cout << days << endl;
}
https://codeforces.com/problemset/problem/16/E
// 16E. Fish
using namespace std;
int n;// number of fish
double grid[20][20];
int dp[1 << 20]; // subset of alive fish.
double transition(int prvmask, int fish){
    int alivecnt = __builtin_popcount(prvmask);
    double den = alivecnt * (alivecnt - 1);
    double chance = 0;
    for(int i = 0; i < n; i++){
        if(prvmask && (1 << i))
            // i can eat `fish`
            chance += grid[i][fish]; 
    }
    return chanse / den;
}
double DP(int mask){
    if(_builtin_popcount(mask) == n)    return 1.0;
    if(dp[mask] > -0.5)    return dp[mask];
    double res = 0;
    for(int fish = 0; fish < n; fish++){
        if(!(mask && (1 << fish))){
            int prvmask = mask | (1 << fish);
            res += transition(prvmask, fish) * DP(prvmask);
        }
    }
    return dp[mask] = res;
}
int main(){
    cin >> n; //number of fish
    //probability that fish i eats fish j
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    fill(dp, dp + (1 << n), -1.0);
    cout << fixed << setprecision(6);
    // compute probability for each fish being the last survivor
    for(int i = 0; i < n; i++)
        cout << DP(1 << i) << " ";
    cout << endl;
}
https://codeforces.com/problemset/problem/17/A
// 17A. Noldbach problem
using namespace std;
const int ax = 1001;
int main(){
    int n, k; cin >> n >> k;
    vector <bool> isprime(ax, true);
    isprime[0] = isprime[1] = false;
    for(int i = 2; i * i < ax; i++){
        if(isprime[i]){
            for(int j = i * i; j < ax; j += i)
                isprime[j] = false;
        }
    }
    vector <int> prime;
    for(int i = 2; i <= n; i++){
        if(isprime[i])    prime.push_back(i);
    }
    int cnt = 0;
    for(int i = 2; i + 1 < (int)prime.size(); i++){
        int special = 1 + prime[i] + prime[i + 1];
        if(special <= n && isprime[special])    cnt++;
    }
    cout << (cnt >= k ? "YES" : "NO") << endl;
    /*
    int ax = 1001; bool isprime[ax];
    memset(isprime, true, sizeof(isprime));
    for(int i = 2; i * i <= ax; i++){
        if(isprime[i] == true){
            for(int j = i; j < ax; j += i)
                isprime[j] = false;
        }
    }
    vector <int> vec, hold, ::iterator it;
    for(int i = 2; i < ax; i++){
        if(isprime[i])    vec.push_back(i);
    }
    int sum = 0;
    for(int i = 0; i < (int)vec.size(); i++){
        sum = 1 + vec[i] + vec[i + 1];
        it = find(vec.begin(), vec.end(), find);
        if(it != vec.end())    hold.push_back(sum);
    }
    int cnt = 0;
    for(int i = 0; i < (int)hold.size(); i++){
        if(hold[i] <= n)    cnt++;
        else    break;
    }
    cout << (cnt >= k ? "YES" : "NO") << endl;
    // duplicate check
    cout << (cnt >= k ? "YES" : "NO") << endl; */
}
https://codeforces.com/problemset/problem/17/B
// 17B. Hierarchy
using namespace std;
int main(){
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)    cin >> vec[i];
    
    int m; cin >> m;
    vector <vector <pair <int, int>>> twin(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        twin[b].push_back({a, c});
    }
    int cnt = 0, idx = -1;
    for(int i = 1; i <= n; i++){
        // Counts how many nodes have no incoming edges
        if(twin[i].empty()){
            cnt++; idx = i;
        }
        if(cnt >= 2)    break;
    }
    if(cnt >= 2){
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(i == idx)    continue;
        int add = INT_MAX;
        for(int j = 0; j < twin[j].size(); j++)
            // Take the cheapest incoming edge (min(c)).
            add = min(add, twin[i][j].second);
        //for(auto &[a, c] : twin[i])
            //add = min(add, c);
        res += add;
    }
    cout << res << endl;
    /*
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        twin[a].push_back({b, c});
        indegree[b]++;
    }
    queue <int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i); cost[i] = 0;
        }
    }
    if(q.size() != 1){
        cout << -1 << endl;
        return 0;
    }
    while(!q.empty()){
        int u = q.front(); q.pop(); /*
        for (auto [v, c] : adj[u]) {
            cost[v] = min(cost[v], (ll)c);
            if (--indegree[v] == 0) 
                q.push(v);
        } */
        for(int i = 0; i < (int)twin[u].size(); i++){
            int v = twin[u][i].first;
            int c = twin[u][i].second;
            cost[v] = min(cost[v], (int)c);
            if(--indegree[v] == 0)    q.push(v);
        }
    }
    int sum = 0;
    sum += accumulate(cost.begin(), cost.end(), 0);
    */ /*
    vector <int> cost(n, INT_MAX);
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        cost[y] = min(cost[y], z);
    }
    int res = 0, missing = 0;
    for(int i = 1; i <= n; i++){
        if(cost[i] == INT_MAX)    missing++;
        else    res += cost[i];
    }
    if(missing > 1)    cout << -1 << endl;
    else    cout << res; */
}
https://codeforces.com/problemset/problem/17/C
// 17C. Balance
using namespace std;
const int ax = 157, modu = 51123987;
int arr[3][ax], route[ax][ax][ax][ax];
int main(){
    int n; // lenght of the string
    string str; cin >> n >> str;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j < 3; j++)
            arr[j][i] = arr[j][i + 1];
            // arr[j][i] = 0[out of bound]
        arr[str[i - 1] - 'a'][i]= i;
    }
    int type = ceil(n / 3.0);
    // route[pos][a][b][c] = number of ways to reach state pos using a items of type 1, b of type 2, and c of type 3.
    route[1][0][0][0] = 1;
    int res = 0;
    for(int pos = 1; pos <= n; pos++){
        for(int a = 0; a <= m; a++){
            for(int b = 0; b <= m; b++){
                for(int c = 0; c <= m; c++){
                    int ways = route[pos][a][b][c];
                    if(!ways) continue;
                    if(a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1)
                        res = (res + ways) % modu;
                        if(a + 1 <= m && arr[0][pos])
                            route[arr[0][pos]][a + 1][b][c] = (route[arr[0][pos]][a + 1][b][c] + ways) % modu;
                        if(b + 1 <= m && arr[1][pos])
                            route[arr[1][pos]][a][b + 1][c] = (route[arr[1][pos]][a][b + 1][c] + ways) % modu;
                        if(c + 1 <= m && arr[2][pos])
                            route[arr[2][pos]][a][b][c + 1] = (route[arr[2][pos]][a][b][c + 1] + ways) % modu;
                }
            }
        }
    }
    cout << res;
}
https://codeforces.com/problemset/problem/17/D
// 17D. Notepad
using namespace std;
int strmod(string &str, int ber){
    int res = 0;
    for(int i = 0; i < str.size(); i++)
        res = (res * 10 + (str[i] - '0')) % ber;
    return res;
}
int euler(int n){
    int res = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            res -= res / i;
            while(n % i == 0)    n /= i;
        }
    }
    if(n > 1)    res -= res / n;
    return res;
}
int modpow(int a, int b, int mod){
    int res = 1;
    int base = a % mod;
    while(b){
        if(b & 1)    res = (res * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    string str, ing; cin >> str >> ing;
    int ber; cin >> ber;
    int n = strmod(str, ber);
    int pre = (n - 1 + ber) % ber;
    int phi = euler(ber);
    int num; 
    if(ing.size() <= 4){
        int N = stoll(ing);
        int res = pre * modpow(n, N - 1, ber) % ber;
        if(res == 0)    res = ber;
        cout << res;
        return 0;
    }
    if(ing == "1")    num = 0;
    else {
        num = strmod(ing, phi);
        num = (num - 1 + phi) % phi;
    }
    int res = pre * modpow(n, num, ber) % ber;
    if(res == 0)    res = ber;
    cout << res << endl;
}
https://codeforces.com/problemset/problem/18/A
// 18A. Triangle
using namespace std;
int dist2(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool isRightTriangle(int ax, int ay, int bx, int by, int cx, int cy) {
    int ab = dist2(ax, ay, bx, by);
    int bc = dist2(bx, by, cx, cy);
    int ac = dist2(ax, ay, cx, cy);
    if (ab == 0 || bc == 0 || ac == 0) return false;
    return (ab + bc == ac) || (ab + ac == bc) || (ac + bc == ab);
}
int main() {
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if (isRightTriangle(ax, ay, bx, by, cx, cy)) {
        cout << "RIGHT\n";
        return;
    }
    vector <pair <int, int>> moves = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
    for (size_t i = 0; i < moves.size(); i++) {
        for (size_t j = 0; j < moves.size(); j++) {
            for (size_t k = 0; k < moves.size(); k++) {
                int dx1 = moves[i].first, dy1 = moves[i].second;
                int dx2 = moves[j].first, dy2 = moves[j].second;
                int dx3 = moves[k].first, dy3 = moves[k].second;

                if (dx1 == 0 && dy1 == 0 && dx2 == 0 && dy2 == 0 && dx3 == 0 && dy3 == 0)
                    continue; 
                if (isRightTriangle(ax + dx1, ay + dy1, bx + dx2, by + dy2, cx + dx3, cy + dy3)) {
                    cout << "ALMOST\n";
                    return;
                }
            }
        }
    } /*
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto [dx, dy] : moves) {
        if (isRightTriangle(ax + dx, ay + dy, x2, y2, x3, y3) ||
            isRightTriangle(x1, y1, bx + dx, by + dy, x3, y3) ||
            isRightTriangle(x1, y1, x2, y2, cx + dx, cy + dy)) {
            cout << "ALMOST";
            return;
        }
    } */
    cout << "NEITHER\n";
}
https://codeforces.com/problemset/problem/18/B
// 18B. Platforms
using namespace std;
int main(){
    int n, d, m, l; cin >> n >> d >> m >> l;
    // n, m-> number of platforms, distance between the start of consecutive platforms.
    // d, l -> exactly jumping units, length of each platforms 
    /*
    if(m - l <= 1){
        int tmp = n * m;
        int res = ((tmp + d - 1) / d) * d;
        cout << res << endl;
        return 0;
    }
    int i = 0;
    while((i % m) <= l && (i / m) < n)
        i += d;
    cout << i << endl; */
    /* for (int i = 0; i < n; i++) {
        int lst = (m * (i + 1)) / d * d;
        if (lst == m * (i + 1)) lst -= d;
        if (lst > m * i + l) {
            while (lst - d > m * i + l)
                lst -= d;
            cout << lst << "\n";
            return;
        }
    }
    int q = (m * n) / d * d;
    if (q < m * n) q += d;
    cout << q << endl; */
    int cur = 0;
    for(int i = 0; i < n; i++){
        // end of platform i (i*m + l)
        int a = i * m + l;
        // start of next platform ((i+1)*m)
        int b = (i + 1) * m;
        if(cur >= b)    continue;
        if(cur > a){
            cout << cur << endl;
            return 0;
        }
        int steps = (a - cur) / d;
        cur += steps * d;
        if(cur < b){
            cout << cur << endl;
            return 0;
        }
    }
    cout << cur;
    return 0;
}
https://codeforces.com/problemset/problem/18/C
// 18C. Stripe
using namespace std;
int main(){
    int n, cnt = 0; cin >> n;
    vector <int> vec(n + 1), prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> vec[i];
        prefix[i] = prefix[i - 1] + vec[i];
    }
    int total = prefix[n];
    for(int i = 1; i < n; i++){
        if(prefix[i] = total - prefix[i])
            cnt++;
    }/*
    for(int i = 0; i < n; i++)    cin >> vec[i];
    partial_sum(vec.begin(), vec.end(), prefix.begin());
    for(int i = 0; i < n - 1; i++){
        if(2 * prefix[i] == prefix[n - 1])    cnt++;
    } */
    cout << cnt;
}
https://codeforces.com/problemset/problem/18/D
// 18D. Seller Bob
using namespace std;
const int ax = 2005;
using ll = long long;
vector <string> pow2(ax); // stores powers of 2 as strings (st2[i] = 2^i).
vector <string> ing(ax, "0"); // stores intermediate values, all initialized to "0". 
/*
string add(string a, string b){
    if(a.size() < b.size())    swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res; int carry = 0;
    for(size_t i = 0; i < a.size() || carry; i++){
        int sum = 0;
        if(i < a.size())    sum += a[i] - '0';
        if(i < b.size())    sum += b[i] - '0';
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
} */
string add(string a, string b){
    if(a.size() < b.size())    swap(a, b);
    string res;
    int carry = 0, n = a.size(), m = b.size();
    for(int i = 0; i < n; i++){
        int x = a[n - 1 - i] - '0'; //'0' converts character to integer.
        int y = (i < m) ? b[m - 1 - i] - '0' : 0;
        int sum = x + y + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if(carry)    res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    pow2[0] = "1";
    // loop is precomputing powers of 2 as strings,Instead of multiplying by 2 each time the code uses addition
    for(int i = 1; i < ax; i++)
        pow2[i] = add(pow2[i - 1], pow2[i - 1]);
    int n; cin >> n;
    string ans = "0";
    for(int i = 0; i < n; i++){
        int x; 
        string s; cin >> s >> x;
        if(s == "win")    ing[x] = add(ans, pow2[x]);
        // Compare pow2[x] and ans.first length.if equal than size[]
        if(ing[x].size() > ans.size() || (ing[x].size() == ans.size() && ing[x] > ans))
            ans = ing[x];
    }
    cout << ans;
}
https://codeforces.com/problemset/problem/18/E
// 18E. Flag 2
using namespace std;
const int ax = 505;
int row, col;
int cnt[ax][2][26]; // cnt[row][parity][char] → frequency of each char in even/odd col
int dp[ax][26][26] //min changes up to this row with pattern (char1, char2)
int arr[ax], ray[ax]; //chosen char from each row
// char input[ax]; pair <int, int> ans[ax];
int main(){
    cin >> row >> col;
    for(int i = 1; i <= row; i++){
        for(int j = 0; j < col; j++){
            char ch; cin >> ch;
            cnt[i][j % 2][ch - 'a']++;
        }
    } /*
    for(int i = 1; i <= row; i++){
        cin >> input + 1;
        for(int j = 1; j <= col; j++){
            int ch = input[j] - 'a';
            cnt[i][ch][j % 2]++;
        }
    } */
    for(int i = 1; i <= row; i++){
        //c1->etter for even columns (positions j % 2 == 0) & c2 → letter for odd column
        for(int c1 = 0; c1 < 26; c1++){
            for(int c2 = 0; c2 < 26; c2++){
                // Characters for even and odd columns must differ
                if(c1 == c2)    continue;
                dp[i][c1][c2] = INT_MAX;
                //previous row
                for(int p1 = 0; p1 < 26; p1++){
                    if(p1 == c1)    continue;
                    for(int p2 = 0; p2 < 26; p2++){
                        if(p2 == c2 || p1 == p2)    continue;
                        if(dp[i][c1][c2] > dp[i - 1][p1][p2]){
                            dp[i][c1][c2] = dp[i - 1][p1][p2];
                            parent[i][c1][c2] = {p1, p2};
                            
                        }
                    }
                }
                int changes = col - cnt[i][0][c1] - cnt[i][1][c2];
                dp[i][c1][c2] += changes;
            }
        }
    }
    int res = INT_MAX;
    int x, y = 0, 1;
    pair <int, int> best{x, y};
    for(int c1 = 0; c1 < 26; c1++){
        for(int c2 = 0; c2 < 26; c2++){
            if(c1 == c2)    continue;
            if(dp[row][c1][c2] < res){
                res = dp[row][c1][c2];
                x = c1; y = c2;
                best = {x, y};
            }
        }
    }
    cout << res << "\n";
    /*
    for(int i = row; i >= 1; i--){
        ans[i] = {x, y};
        auto prv = parent[i][x][y];
        x = prv.first;
        y = prv.second;
    }
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            char ar = (j % 2 ? ans[i].first : ans[i].second) + 'a';
            cout << ar;
        }
        cout << endl;
    } */
    int tmp = row;
    while(tmp >= 1){
        arr[tmp] = best.first;
        ray[tmp] = best.second;
        best = parent[row][best.first][best.second];
        --row;
    }
    for(int i = 1; i <= row; i++){
        for(int j = 0; j < col; j++){
            char c = (j % 2 == 0 ? arr[i] : ray[i]) + 'a';
            cout << c;
        }
        cout << endl;
    }
}
using namespace std;
const int ax = 510, INF = 0x3f3f3f3f;
char grid[ax][ax];
int row, col;
int dp[ax][26][26]; //dp[row][char][char]
pair <int, int> parent[ax][26][26];
int compute(int i, int a, int b){
    int changes = 0;
    for(int j = 1; j <= col; j++){
        char ch = ((j % 2) ? (a + 'a') : (b + 'a'));
        if(grid[i][j] != ch)    changes++;
    }
    return changes;
}
int main(){
    cin >> row >> col;
    for(int i = 1; i <= row; i++)    cin >> (grid[i] + 1);
    memset(dp, 0x3f, sizeof(dp));
    for(int a = 0; a < 26; a++){
        for(int b = 0; b < 26; b++){
            if(a == b)    continue;
            dp[1][a][b] = compute(1, a, b);
        }
    }
    for(int i = 2; i <= n; i++){
        for(int a = 0; a < 26; a++){
            for(int b = 0; b < 26; b++){
                if(a == b)    continue;
                int cost = compute(i, a, b);
                for(int x = 0; x < 26; x++){
                    if(x == a)    continue;
                    for(int y = 0; y < 26; y++){
                        if(y == b || x == y)    continue;
                        if(dp[i][a][b] > dp[i - 1][x][y] + cost){
                            dp[i][a][b] = dp[i - 1][x][y] + cost;
                            parent[i][a][b] = {x, y};
                        }
                    }
                }
            }
        }
    }
    int res = INF;
    pair <int, int> last = {0, 1};
    for(int a = 0; a < 26; a++){
        for(int b = 0; b < 26; b++){
            if(a == b)    continue;
            if(dp[n][a][b] < res){
                res = dp[n][a][b];
                last = {a, b};
            }
        }
    }
    cout << res << "\n";
    int r = row;
    while(r >= 1){
        int a = last.first, b = last.second;
        for(int j = 1; j <= col; j++)
            grid[row][j] = ((j % 2) ? (a + 'a') : (b + 'a'));
        last = pair[row][a][b];
        row--;
    }
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
https://codeforces.com/problemset/problem/19/A
// 19A. World Football Cup
/*
map <string, int> goals, points, diffgoal;
bool cmp(const string &a, const string &b){
    if(points[a] != points[b])    return points[a] > points[b];
    else if(goals[a] != goals[b])    return goals[a] > goals[b];
    else    return diffgoal[a] > diffgoal[b];
} */
using namespace std;
int main(){
    int n; cin >> n;
    /*
    int team[2 * n];
    for(int i = 0; i < n; i++)    cin >> team[i]; */
    vector <string> team(n);
    unordered_map <string, int> points, goals, diffgoal;
    for(int i = 0; i < n; i++){
        cin >> team[i];
        points[team[i]] = 0;
        goals[team[i]] = 0;
        diffgoal[team[i]] = 0;
    }
    int totalmatches = n * (n - 1) / 2;
    for(int i = 0; i < totalmatches; i++){
        string match; int goal1, goal2;
        char ch; cin >> match >> goal1 >> ch >> goal2;
        string str = match.substr(0, match.find('-'));
        string ing = match.substr(match.find('-') + 1);
        if(goal1 == goal2){
            points[str]++; points[ing]++;
        }
        else if(goal1 > goal2)    points[str] += 3;
        else    points[ing] += 3;
        goals[str] += goal1;
        goals[ing] += goal2;
        diffgoal[str] += (goal1 - goal2);
        diffgoal[ing] += (goal2 - goal1);
        // sort(team, team + n, cmp);
        sort(team.begin(), team.end(), [&](const string &a, const string &b){
            if(points[a] != points[b])    return points[a] > points[b];
            if(diffgoal[a] != diffgoal[b])    return diffgoal[a] > diffgoal[b];
            return goals[a] > goals[b];
        });
    }
    /*
    vector <string> qualified(team, team + n / 2);
    sort(qualified.begin(), qualified.end());
    for(int i = 0; i < qualified.size(); i++)
        cout << qualified[i] << " "; */
    vector <string> qualified(team.begin(), team.begin() + n / 2);
    sort(qualified.begin(), qualified.end());
    for (int i = 0; i < (int)qualified.size(); i++)
        cout << qualified[i] << " ";
    cout << endl;
}
https://codeforces.com/problemset/problem/19/B
// 19B. Checkout Assistant
using namespace std;
int dp[2005][2005];
void knapsack(int idx, int need, vector <int> &item, vector <int> &cost, int n){
    if(need <= 0) return 0;
    if(idx == n) return 1e18;
    if(dp[idx][need] != -1) return dp[idx][need];
    int take = knapsack(idx, need - item[idx], item, cost, n);
    int nottake = knapsack(idx + 1, need, item, cost, n) + cost[idx];
    return dp[idx][need] = min(take, nottake);
}
int main(){
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    vector <int> item(n), cost(n);
    for(int i = 0; i < n; i++)    cin >> item[i] >> cost[i];
    int res = knapsack(0, n, item, cost, n);
    cout << res;
}
using namespace std;
int main(){
    int n; cin >> n;
    vector <pair <int, int>> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    const int N = 2017, M = 4017;
    vector <vector <int>>dp(N, vector <int> (M, INT_MAX));
    for(int i = 0; i < M; i++){
        if(i >= 2000)    dp[n][i] = 0;
        else    dp[n][i] = INT_MAX;
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            int take = dp[i + 1][min(j + vec[i].first, M - 1)] + vec[i].second;
            int nottake = dp[i + 1][j];
            dp[i][j] = min(take, nottake);
        }
    }/*
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            ll cost_skip = (j > 0) ? dp[i + 1][j - 1] : INF;
            ll cost_take = dp[i + 1][min(j + vec[i].first, M - 1)] + ves[i].second;
            dp[i][j] = min(cost_skip, cost_take);
        }
    }*/
    cout << dp[0][2000];
}
https://codeforces.com/problemset/problem/19/C
// 19C. Deletion of Repeats
using namespace std;
const int N = 2e5 + 5;
const int M = 20;
typedef long long ll;
void count_sort(vector<int>& p, vector<int>& c) {
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c) cnt[x]++;
    vector<int> p_new(n), pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
    for (auto x : p) {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}
vector<int> lcp_construction(vector<int>& s, vector<int>& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n - 1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
ll sp[N][M], lg[N];
vector<ll> a;
void buildSparse(ll n) { // zero based
    lg[1] = 0;
    for (ll i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (ll i = 0; i < n; i++) sp[i][0] = a[i];
    for (ll j = 1; (1 << j) <= n; j++) {
        for (ll i = 0; i + (1 << j) <= n; i++) {
            sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll queryMn(ll l, ll r) {
    if (l > r) return 0;
    ll j = lg[r - l + 1];
    return min(sp[l][j], sp[r - (1 << j) + 1][j]);
}
int main() {
    ll n_input;
    cin >> n_input;
    map<int, vector<int>> ma;
    vector<int> s(n_input + 1);
    for (int i = 0; i < n_input; i++) {
        cin >> s[i];
        ma[s[i]].push_back(i);
    }
    s[n_input] = -1; // sentinel
    ll n = s.size();
    vector<int> p(n), c(n);
    vector<pair<int, int>> tmp(n);
    for (int i = 0; i < n; i++) tmp[i] = {s[i], i};
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) p[i] = tmp[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++)
        c[p[i]] = c[p[i - 1]] + (tmp[i].first != tmp[i - 1].first);
    // Build suffix array
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++) p[i] = (p[i] - (1 << k) + n) % n;
        count_sort(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            c_new[p[i]] = c_new[p[i - 1]] + (now != prev);
        }
        c = c_new;
        k++;
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[p[i]] = i;
    // Build LCP and Sparse Table
    vector<int> lcp = lcp_construction(s, p);
    a.assign(lcp.begin(), lcp.end());
    buildSparse(a.size());
    ll start = 0;
    set<pair<int, int>> se;
    for (auto &item : ma) {
        auto &indices = item.second;
        for (size_t i = 0; i < indices.size(); i++) {
            for (size_t j = i + 1; j < indices.size(); j++) {
                ll st = rev[indices[i]];
                ll en = rev[indices[j]];
                if (st > en) swap(st, en);
                ll len = queryMn(st, en - 1);
                if (len >= indices[j] - indices[i]) {
                    se.insert({indices[j] - indices[i], indices[i]});
                }
            }
        }
    }
    for (auto &item : se) {
        if (item.second < start) continue;
        start = item.second + item.first;
    }
    cout << n - 1 - start << '\n';
    for (ll i = start; i < n - 1; i++) cout << s[i] << ' ';
    cout << '\n';
}
using namespace std;
int n;
vector<int> suffix, order, neword, lcp, logs;
vector<vector<int>> table;
vector<int> vec;
int getOrder(int idx) {
    return idx < n ? order[idx] : -1;
}
void radix_sort(int len) {
    vector<int> func(n + 1), newsuff(n);
    for (int i = 0; i < n; i++) func[getOrder(suffix[i] + len) + 1]++;
    for (int i = 1; i <= n; i++) func[i] += func[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        newsuff[--func[getOrder(suffix[i] + len) + 1]] = suffix[i];
    }
    suffix = newsuff;
}
void buildsuffix(const vector<int> &v) {
    vec = v;
    n = vec.size() + 1;
    vec.push_back(-1);

    suffix = order = neword = vector<int>(n);
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i++) tmp.emplace_back(vec[i], i);
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) suffix[i] = tmp[i].second;
    order[suffix[0]] = 0;
    for (int i = 1; i < n; i++)
        order[suffix[i]] = order[suffix[i - 1]] + (tmp[i].first != tmp[i - 1].first);

    int len = 1;
    while (order[suffix[n - 1]] != n - 1) {
        for (int i = 0; i < n; i++) {
            suffix[i] -= len;
            if (suffix[i] < 0) suffix[i] += n;
        }
        radix_sort(len);
        neword[suffix[0]] = 0;
        for (int i = 1; i < n; i++) {
            neword[suffix[i]] = neword[suffix[i - 1]] +
                                (order[suffix[i - 1]] != order[suffix[i]] ||
                                 getOrder(suffix[i - 1] + len) != getOrder(suffix[i] + len));
        }
        order = neword;
        len <<= 1;
    }
}
void buildLCP() {
    lcp = vector<int>(n);
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        int pos = order[i];
        int j = suffix[pos - 1];
        while (vec[i + k] == vec[j + k]) k++;
        lcp[pos] = k;
        k = max(0, k - 1);
    }
    int LOG = 32 - __builtin_clz(n);
    table.assign(n, vector<int>(LOG + 1));
    logs.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;

    for (int i = 0; i < n; i++) table[i][0] = lcp[i];
    for (int j = 1; j <= logs[n]; j++) {
        for (int i = 0; i + (1 << j) <= n; i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
}
int LCP(int i, int j) {
    if (i == j) return n - i - 1;
    int l = order[i], r = order[j];
    if (l > r) swap(l, r);
    l++;
    int len = logs[r - l + 1];
    return min(table[l][len], table[r - (1 << len) + 1][len]);
}
int compare_substrings(int l1, int r1, int l2, int r2) {
    int k = min({LCP(l1, l2), r1 - l1 + 1, r2 - l2 + 1});
    l1 += k; l2 += k;
    if (l1 > r1 && l2 > r2) return 0;
    if (l1 > r1) return -1;
    if (l2 > r2) return 1;
    return (vec[l1] > vec[l2] ? 1 : -1);
}
int main() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    buildsuffix(a);
    buildLCP();
    map<int, vector<int>> idx;
    priority_queue<array<int, 3>> pq;

    for (int i = n - 2; i >= 0; i--) {
        for (int j : idx[a[i]]) {
            int l1 = i, r1 = j - 1, l2 = j, r2 = l2 + r1 - l1;
            if (r2 >= n - 1 || compare_substrings(l1, r1, l2, r2) != 0) continue;
            pq.push({l1 - r1, -l2, l1});
        }
        idx[a[i]].push_back(i);
    }
    int cur = 0;
    while (!pq.empty()) {
        auto [d, new_cur, start] = pq.top(); pq.pop();
        if (start >= cur) cur = -new_cur;
    }
    cout << n - 1 - cur << '\n';
    for (int i = cur; i < n - 1; i++)
        cout << a[i] << " \n"[i == n - 2];
}
https://codeforces.com/problemset/problem/19/D
// 19D. Points
using namespace std;
const int ax = 0x3f3f3f3f;
int n;
vector <string> type;
vector <int> x, y, coords;
vector <set <pair <int, int> > >tree;
void add(int idx, pair <int, int> val){
    while(idx > 0){
        tree[idx].insert(val);
        idx -= idx & -idx; //go downwards
    }
}
void cancel(int idx, pair <int, int> val){
    while(idx > 0){
        tree[idx].erase(val);
        idx += idx & -idx; //go upwards
    }
}
void findnext(int x, int y){
    pair <int, int> best = {ax, ax};
    for(int i = y + 1; i < (int)tree.size(); i += i && -i){
        // find the immediate next point
        auto it = tree[i].lower_bound({x + 1, y});
        if(it != tree[i].end())    best = min(*it, best);
    }
    if(best.first == ax)    cout << -1;
    else    cout << best.first << " " << coords[best.second];
}
int main(){
    cin >> n;
    type.resize(n + 1); 
    x.resize(n + 1); y.resize(n + 1);
    //assign based over y coordinates
    for(int i = 1; i <= n; i++){
        cin >> type[i] >> x[i] >> y[i];
        coords.push_back(y[i]);
    }
    sort(coords.begin(), coords.end());
    // remove duplicats
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    tree.assign(coords.size() + 5, {});
    for(int i = 1; i <= n; i++){
        if(op[i][0] == 'a')    add(y[i], {x[i], y[i]});
        else if(op[i][0] == 'r')    cancel(y[i], {x[i], y[i]});
        else    findnext(x[i], y[i]);
    }
}
using namespace std;
int n;
vector <int> xs, tree;
vector <set <int>>rel;
void compress(vector<pair<string, pair<int,int>>> &ps){
    for(int i = 0; i < n; i++)    xs.push_back(ps[i].second.first);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for(int i = 0; i < n; i++)
        ps[i].second.first = lower_bound(xs.begin(), xs.end(), ps[i].second.first) - xs.begin();
}
void update(int node, int b, int e, int p, int val) {
    if (b == e - 1) {
        tree[node] = val;
        return;
    }
    int mid = (b + e) >> 1;
    if (p < mid) update(node << 1, b, mid, p, val);
    else update(node << 1 | 1, mid, e, p, val);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}
// Segment tree query: find first index >= p with max y >= val
int query(int node, int b, int e, int p, int val) {
    if (e <= p || tree[node] < val) return -1;
    if (b == e - 1) return b;
    int mid = (b + e) >> 1;
    int left = query(node << 1, b, mid, p, val);
    if (left != -1) return left;
    return query(node << 1 | 1, mid, e, p, val);
}
int main(){
    cin >> n;
    vector <pair <string, pair<int, int>>> ps(n);
    for(int i = 0; i < n; i++)
        cin >> ps[i].first >> ps[i].second.first >> ps[i].second.second;
    compress(ps);
    int sz = xs.size();
    tree.assign(4 * sz, -1); rel.assign(sz, {});
    for(int i = 0; i < n; i++){
        string type = ps[i].first;
        int x = ps[i].second.first;
        int y = ps[i].second.second;
        if (type == "add") {
            rel[x].insert(y);
            update(1, 0, sz, x, *rel[x].rbegin());
        }
        else if (type == "remove") {
            rel[x].erase(y);
            if (rel[x].empty()) update(1, 0, sz, x, -1);
            else update(1, 0, sz, x, *rel[x].rbegin());
        }
        else if (type == "find") {
            int pos = query(1, 0, sz, x + 1, y + 1);
            if (pos == -1)    cout << "-1\n";
            else {
                if (it == rel[pos].end())    cout << "-1\n";
                else    cout << xs[pos] << " " << *it << "\n";
            }
        }
    }
}
https://codeforces.com/problemset/problem/19/E
// 19E. Fairy
using namespace std;
int n, m;
vector <vector <int> > graph;
vector <int> visited, delta, depth, res;
int cntevencycle = 0;
// delta[] = contribution counter (used later to decide which edges are part of solutions).
void dfs(int u, int parent){
    visited[u] = 1;
    // graph[u] is a vector<int> containing all neighbors of node u.
    for(int v : graph[u]){
        if(v == parent)    continue;
        if(!visited[v]){
            depth[v] = depth[u] + 1;
            dfs(v, u);
            delta[u] += delta[v];
        }// odd cycle
        if((depth[u] - depth[v]) % 2 != 0){
            delta[u]--; delta[v]++;
        }
        else {
            delta[u]++; delta[v]--;
            cntevencycle++;
        }
    }
}
int main(){
    cin >> n >> m;
    graph.assing(n + 1, {});
    depth.assing(n + 1, 0);
    visited.assing(n + 1, 0);
    delta.assing(n + 1, 0);
    vector <pair <int, int >> edge(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edge[i] = {u, v};
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            depth[i] = 0;
            dfs(i, -1);
        }
    }
    // All edges valid
    if(cntevencycle == 0){
        cout << m << "\n";
        for(int i = 1; i <= m; i++)    cout << i << " ";
    }
    else {
        for(int i = 1; i <= m; i++){
            u = edges[i].first; v = edges[i].second;
            if(depth[u] > depth[v])    swap(u, v);
            if(delta[v] == cntevencycle)    res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    for(auto id : res) cout << id << " ;"
}
https://codeforces.com/problemset/problem/20/A
// 20A.BerOS file system
using namespace std;
int main(){
    string str; cin >> str;
    string tmp = "";
    vector <string> vec;
    for(int i = 0; i < vec.size(); i++){
        if(str[i] != '/') tmp += str[i];
        else {
            if(!tmp.empty())    vec.push_back(tmp);
            tmp.clear();
        }
    }
    if(!tmp.empty())    vec.push_back(tmp);
    cout << "/";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if(i != vec[i].size())    cout << "/";
    }
    cout << endl;
}
https://codeforces.com/problemset/problem/20/B
// 20B. Equation
using namespace std;
int main(){
    cout << fixed << setprecision(12);
    // a * x * x + b * x + c = 0
    int a, b, c; cin >> a >> b >> c;
    if(a == 0 && b == 0 && c == 0){
        cout << -1;
        return 0;
    }
    if(a == 0){
        if(b == 0)    cout << "0\n" << endl;
        else    cout << "-1\n" << (-c * 0.1) / b << endl;
    }
    double d =(double)b * b - 4.0L * a * c;
    if(d < 0){
        // No real solution
        cout << "0\n"; return;
    }
    vector <double> res;
    double x1 = (-b + sqrt(d)) / (2.0L * a);
    double x2 = (-b - sqrt(d)) / (2.0L * a);
    res.push_back(x1);
    if(d > 0)    res.push_back(x2);
    sort(res.begin(), res.end());
    for(auto x : res)    cout << x << " ";
}
https://codeforces.com/problemset/problem/20/C
// 20C. Dijkstra?
using namespace std;
int main(){
    // n, m -> vertex, edges
    int n, m, u, v, w; cin >> n >> m >> u >> v >> w;
    vector <vector <pair <int, int> > >adj(n);
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    vector <int> dst(n, INT_MAX), pred(n, -1);
    //pred(n) -> for looking backtrack
    dst[0] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater<> >pq;
    pq.push({0, 0});
    while(!pq.empty()){
        pair <int, int> top = pq.top();
        pq.pop();
        int d = top.first; // u
        int from = top.second; // v
        // Sometimes the same vertex can be pushed multiple times into the priority queue (if we later found a shorter path). Only the most recent shortest distance is valid.
        if(d != dst[from])    continue;
        for(size_t i = 0; i < adj[from].size(); i++){
            int to = adj[from][i].first;
            //weight
            int len = adj[from][i].second;
            if (dist[to] > dist[from] + len) {
                dist[to] = dist[from] + len;
                pred[to] = from;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
    if(dist[n - 1] == INT_MAX){
        cout << -1 << "\n"; return 0;
    }
    for(int v = n - 1; v != -1; v = pred[v])
        path.push_back(v + 1);
    reverse(path.begin(), path.end());
    for(auto x : path)    cout << x + 1;
}
using namespace std;
#define x 100005
int main(){
    int u, v, w, n, m; cin >> n >> m;
    int d[x], pred[x];
    vector <pair <int, int> >adj[x];
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <>> pq;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++){
        d[i] = INT_MAX;    pred[i] = -1;
    }
    d[1] = 0; pq.push({0, 1});
    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        int dist_u = top.first;
        int u = top.second;
        if(dist_u > d[u])    continue;
        for(size_t i = 0; i < adj[u].size(); i++){
            int v = adj[u].first;
            int wt = adj[u].second;
            if (d[u] + wt < d[v]) {
                d[v] = d[u] + wt;
                pred[v] = u;
                pq.push({d[v], v});
            }
        }
    }
    vector <int> path;
    if (d[n] == INF) cout << -1 << "\n";
    else {
        for (int v = node; v != -1; v = pred[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        for (int v : path) cout << v << " ";
        cout << "\n";
    }
}
