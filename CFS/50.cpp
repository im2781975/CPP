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
// C. Ancient Berland Circus
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
// A. Winner
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
        int score; cin >> name >> score;
        rounds[i] = {name, score};
        points[name] += score;
    }
    int sign = INT_MIN;
    for(map <string, int> ::iterator it = points.begin(); it!= points.end(); ++it)
        sign = max(sign, it->second);
    map <string, int> entrant;
    for(map <string, int> ::iterator it = points.begin(); it != points.end(); ++it){
        if(it->second == sign)
            entrant[it->first] = 0;
    }
    for(vector <pair <string, int> > ::iterator it = rounds.begin(); it != rounds.end(); it++){
        const string &name = it->first;
        int score = it->second;
        if(entrant.count(name)){
            entrant[name] += score;
            if(entrant[name] >= sign){
                cout << name;
                break
            }
        }
    }*/
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
