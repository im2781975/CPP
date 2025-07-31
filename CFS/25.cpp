using namespace std;
https://codeforces.com/problemset/problem/1/A
// A. Theatre Square
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
// B. Spreadsheets
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
const double eps = 1e-9;
double dist(double xa, double ya, double xb, double yb) {
    double dx = xa - xb, dy = ya - yb;
    return sqrt(dx * dx + dy * dy);
}
// Heron's formula for triangle area
double S(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
// Compute angle (in radians) using Law of Cosines
double angle(double a, double b, double c) {
    return acos((a * a + b * b - c * c) / (2 * a * b));
}
// Floating-point GCD of angles (in radians)
double fgcd(double a, double b) {
    if (fabs(b) < eps) return a;
    return fgcd(b, fmod(a, b));
}
int main() {
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    // Compute side lengths
    double ab = dist(xa, ya, xb, yb);
    double ac = dist(xa, ya, xc, yc);
    double bc = dist(xb, yb, xc, yc);
    // Compute triangle angles (radians), doubled
    double anga = 2 * angle(ab, ac, bc);
    double angb = 2 * angle(bc, ab, ac);
    double angc = 2 * angle(ac, bc, ab);
    // Circumradius using formula R = (abc) / (4 * Area)
    double radius = ab * bc * ac / (4 * S(ab, bc, ac));
    // Smallest angle that evenly divides all three
    double minAngle = fgcd(anga, fgcd(angb, angc));
    // Area of regular polygon with center at circumcircle and minAngle step
    double ans = radius * radius * sin(minAngle) * PI / minAngle;
    cout << fixed << setprecision(6) << ans << endl;
}
