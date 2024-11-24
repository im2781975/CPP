using namespace std;
void HelpfulMath(){
    string str, ans, res; cin >> str;
    if(str.size() == 1){
        cout << str;
        return 0;
    }
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '+')
            res += str[i];
        else
            ans += str[i];
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i == ans.size() - 1)
            return 0;
        else
            cout << '+';
    }
}
using namespace std;
void WannaBeTheGuy(){
    int n, p, q; cin >> n >> p >> q;
    int freq[101]{0};
    vector <int> vec(p), tmp(q);
    for(int i = 0; i < p; i++){
        cin >> vec[i];
        freq[vec[i]]++;
    }
    for(int i = 0; i < q; i++){
        cin >> tmp[i];
        freq[tmp[i]]++;
    }
    bool flag = false;
    for(int i = 1; i <= n; i++){
        if(freq[i] == 0){
            flag = false;
            break;
        }
    }
    (flag)? cout << "Become the guy" : cout << "Oh, no";
}
using namespace std;
void BalckSqr(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    string str; cin >> str;
    int calorie = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] - '0' == 1)
            calorie += a;
        else if(str[i] - '0' == 2)
            calorie += b;
        else if(str[i] - '0' == 3)
            calorie += c;
        else
            calorie += d;
    }
    cout << calorie;
}
using namespace std;
void GoodNumber(){
    int n, k; cin >> n >> k;
    int cnt = 0;
    while(n--){
        string str; cin >> str;
        sort(str.begin(), str.end());
        int freq[10]{0};
        bool flag = true;
        for(int i = 0; i < str.size(); i++)
            freq[str[i] - '0']++;
        for(int i = 0; i <= k; i++){
            if(freq[i] == 0 && i <= k){
                flag = false;
                break;
            }
        }
        if(flag)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void Team(){
    int n, cnt = 0; cin >> n;
    while(n--){
        int x, y, z; cin >> x >> y >> z;
        if(x + y + z > 1)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void AntonAndLetter(){
    string str, res; cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            res += str[i];
    }
    sort(res.begin(), res.end());
    int cnt = 0;
    for(int i = 0; i < res.size(); i++){
        if(res[i] != res[i + 1])
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void AntonAndPolyhedron(){
    int n; cin >> n;
    int cnt = 0;
    string str;
    while(n--){
        cin >> str;
        if(str == "Tetrahedron") cnt += 4;
        else if(str == "Cube") cnt += 6;
        else if(str == "Octahedron") cnt += 8;
        else if(str == "Dodecahedron") cnt =+ 12;
        else if(str == "Icosahedron") cnt += 20;
    }
    cout << cnt;
}
using namespace std;
void BuyShovel(){
    int k, r; cin >> k >> r;
    for(int i = 1; i <= 1000; i++){
        int shovel = i * k;
        if(shovel % 10 == r || shovek % 10 == 0){
            cout << i << " ";
            return 0;
        }
    }
}
using namespace std;
void BoyOrGirl(){
    string str; cin >> str;
    vector <int> freq(26);
    int cnt = 0;
    for(int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;
    for(int i = 0; i < 26; i++){
        if(freq[i])
            cnt++;
    }
    (cnt % 2 == 0)? cout << "chat with her" : cout << "Ignore him";
}
using namespace std;
void FreeIceCreem(){
    int n, x; cin >> n >> x;
    int cnt = 0, sum = x;
    char ch;
    while(n--){
        cin >> ch >> x;
        if(ch == '+')
            sum += x;
        else{
            if(sum - x < 0)
                cnt++;
            else
                sum -= x;
        }
    }
    cout << sum << " " << cnt;
}
using namespace std;
void HorseShoweOnHoof(){
    int arr[4], cnt = 0;
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    sort(arr, arr + 4);
    for(int i = 0; i < 3; i++){
        if(arr[i] == arr[i + 1])
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void Juicer(){
    int n, b, d;cin >> n >> b >> d;
    vector <int> vec(n);
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        if(vec[i] <= b)
            sum += vec[i];
        if(sum > d){
            cnt++;
            sum = 0;
        }
    }
    cout << cnt;
}
using namespace std;
void VanyaAndFence(){
    int n, h; cin >> n >> h;
    int res = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x <= h)
            res++;
        else
            res += 2;
    }
    cout << res;
}
using namespace std;
void Juicer(){
    int n, b, d; cin >> n >> b >> d;
    vector <int> vec(n);
    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        if(vec[i] <= b)
            sum += vec[i];
        if(sum > d){
            cnt++;
            sum = 0;
        }
    }
    cout << cnt;
}
using namespace std;
void YoungPhysicist(){
    int n; cin >> n;
    int sumx = 0, sumy = 0, sumz = 0;
    while(n--){
        int x, y, z; cin >> x >> y >> z;
        sumx += x; sumy += y; sumz += z;
    }
    if(sumx == 0 && sumy == 0 && sumz)
        cout << "Yes";
    else
        cout << "No";
}
using namespace std;
void SirajaAndDima(){
    int n; cin >> n;
    deque <int> dq(n);
    int siraj = 0, Dima = 0;
    for(int i = 0; i < n; i++)
        cin >> dq[i];
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(dq.back() > dq.front()){
                siraj += dq.back();
                dq.pop_back();
            }
            else{
                siraj += dq.front();
                dq.pop_front();
            }
        }
        else{
            if(dq.back() > dq.front()){
                Dima += dq.back();
                dq.pop_back();
            }
            else{
                Dima += dq.front();
                dq.pop_front();
            }
        }
    }
    cout << siraj << " " << Dima;
}
using namespace std;
void Pangram(){
    int n; cin >> n;
    if(n < 26){
        cout << "No";
        return 0;
    }
    set <char> st;
    for(int i = 0; i < n; i++){
        char ch; cin >> ch;
        if(ch >= 'A' && ch <= 'Z')
            ch += 32;
        st.insert(ch);
    }
    (st.size() == 26) ? cout << "Yes" : cout << "No";
}
using namespace std;
void wrongSubtract(){
    int n, k; cin >> n >> k;
    while(k--){
        if(n % 10 == 0)
            n /= 10;
        else
            n--;
    }
    cout << n;
}
using namespace std;
void ultraFast(){
    string str, tmp;
    cin >> str >> tmp;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != tmp[i])
            cout << "1";
        else
            cout << "0";
    }
}
using namespace std;
void EqualCandies(){
    int n; cin >> n;
    vector <int> vec(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    int mini = *min_element(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        vec[i] -= mini;
        sum += vec[i];
    }
    cout << sum;
}
using namespace std;
void colorfulStone(){
    string str, tmp; cin >> str >> tmp;
    int pos = 0;
    for(int i = 0; i < tmp.size(); i++){
        if(str[pos] == tmp[i])
            pos++;
    }
    cout << pos + 1;
}
using namespace std;
void GresWorkout(){
    int n; cin >> n;
    vector <int> vec(n);
    int chest = 0, biceps = 0, back = 0;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        if(i % 3 == 0)
            chest += vec[i];
        else if(i % 3 == 1)
            biceps += vec[i];
        else
            back += vec[i];
    }
    if(chest >= biceps && chest >= back)
        cout << "chest";
    else if(biceps >= chest && biceps >= back)
        cout << "biceps";
    else
        cout << "back";
}
using namespace std;
void SoldierAndBanana(){
    int k, n, w; cin >> k >> n >> w;
    int total = 0;
    for(int i = 1; i <= w; i++)
        total += i * k;
    if(total <= n)
        cout << "0";
    else
        cout << abs(total - n);
}
using namespace std;
void Flag(){
    int n, m; cin >> n >> m;
    bool Isvalid = true;
    char c1 = '#', c2 = '@';
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < str.size() - 1; j++){
            if(str[j]!= str[j + 1]){
                cout << "No";
                return 0;
            }
        }
        if(i % 2 == 0)
            c1 = str[0];
        else
            c2 = str[0];
        if(c1 == c2)
            Isvalid = false;
        if(!Isvalid){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
using namespace std;
void IsItRated(){
    int n; cin >> n;
    vector <int> vec(n), tmp(n);
    bool flag = false, bandi = false;
    for(int i = 0; i < n; i++)
        cin >> vec[i] >> tmp[i];
    for(int i = 0; i < n; i++){
        if(vec[i] != tmp[i]){
            flag = true;
            break;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(vec[i] < vec[i + 1]){
            bandi = true;
            break;
        }
    }
    if(flag)
        cout << "rated";
    else if(bandi)
        cout << "Unrated";
    else
        cout << "maybe";
}
using namespace std;
void BrainsPhoto(){
    int n, m, freq[26]{0}; cin >> n >> m;
    char ch;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ch;
            freq[ch - 'A']++;
        }
    }
    //('C', cyan), ('M', magenta), ('Y', yellow), ('W', white), ('G', grey), ('B', black)
	if ((freq['C' - 'A']) || (freq['M' - 'A']) || (freq['Y' - 'A']))
		cout << "#Color" << endl;
	else
		cout << "#Black&White" << endl;
}
using namespace std;
void ArpasExam(){
    int n; cin >> n;
    if(n == 0)
        cout << "1";
    else{
        int res;
        if(n % 4 == 0) res = 6;
        else if(n % 4 == 1) res = 8;
        else if(n % 4 == 2) res = 4;
        else res = 2;
    }
    cout << res;
}
using namespace std;
void SecondOrderStatics(){
    int n; cin >> n;
    set <int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }
    set <int> ::iterator it = st.begin();
    if(st.size() == 1)
        cout << "No";
    else{
        advance(it, 1);
        cout << *it << " ";
    }
}
using namespace std;
void GoodContest(){
    int n, l, r; cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str >> l >> r;
        if(r >= 2400 && l > r){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
using namespace std;
void OathOfNightWatch(){
    int n, cnt = 0; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 1; i < n; i++){
        if(vec[i] > vec[0] && vec[n - 1] > vec[i])
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void main(){
    string str; cin >> str;
    int x = str.length();
    for(int i = 0; i < x - 1; i++){
        for(int j = 0; j < x - i - 1; j++){
            if(str[j] != '+'){
                char tmp = str[j];
                str[j] = str[j + 2]; 
                str[j + 2] = tmp;
            }
        }
    }
    cout << str;
}
using namespace std;
void PetyaString(){
    string str, tmp; cin >> str >> tmp;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    int x = str.compare(tmp);
    if(x > 0)
        cout << "1";
    else if(x < 0)
        cout << "-1";
    else
        cout << "0";
}
using namespace std;
void main(){
    string str, res; cin >> str;
    int len = str.length();
    if(len > 10)
        res = str[0] + to_string(len - 2) + str[len - 1];
    else
        res = str;
    cout << res;
}
using namespace std;
void PhoenixAndBalance(){
    int n; cin >> n;
    int x = 0;
    for(int i = 0; i <= n; i++){
        if(n == 2)
            x = 2;
        else if(n == i)
            x = 2 * (i - 1) - 2;
    }
    cout << x;
}
using namespace std;
void BlackSqr(){
    int arr[5], sum = 0;
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    string str; cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '1' && str[i] <= '4')
            sum += arr[str[i] - '1'];
        else{
            cerr << "Invalid";
            return 1;
        }
    }
    cout << sum;
}
using namespace std;
void main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 2; i++){
        if(arr[i] != arr[i + 1] && arr[i + 1] != arr[i + 2]){
            cout << i + 2;
            break;
        }
        if(arr[i] != arr[i + 1] && arr[i + 1] == arr[i + 2])
            cout << i + 1;
            break;
    }
}
using namespace std;
void spyDetect(){
    int n, cnt = 0; cin >> n;
    int arr[n], res[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if((i > 0 && arr[i] != arr[i - 1] && (i == n - 1 || arr[i] != arr[i + 1])) || (i == 0 && arr[i] != arr[i + 1])){
                    cnt = i + 1;
                    break;
        }
    }
    for(int i = 0; i < n; i++)
        res[i] = cnt;
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
using namespace std;
void NewYearMeeting(){
    int arr[3];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2 - i; j++){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    cout << abs(arr[1] - arr[0]) + abs(arr[2] - arr[1]);
}
void NewYearMeeting(){
    vector <int> vec(3);
    for(int i = 0; i < 3; i++)
        cin >> vec[i];
    cout << *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end());
}
using namespace std;
void main(){
    int num; cin >> num;
    int cnt = 0;
    while(num != 0){
        int rem = num % 10;
        num /= 10;
        if(rem == 4 || rem == 7)
            cnt++;
    }
    if(cnt == 4 || cnt == 7)
        cout << "Yes";
    else
        cout << "No";
}
using namespace std;
void WrongSubtraction(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++){
        if(n % 10 == 0)
            n /= 10;
        else
            n--;
    }
    cout << n;
}
using namespace std;
void Elephent(){
    int n; cin >> n;
    int x = n / 5;
    if(n % 5 != 0)
        x++;
    cout << x;
}
void Elefent(){
    float n; cin >> n;
    cout << ceil(n / 5);
}
using namespace std;
void addOddOrSubtractEven(){
    int a, b; cin >> a >> b;
    int cnt = 0;
    if(a > b){
        int c = a - b;
        (c % 2 == 0) ? cnt = 1 :  cnt = 2;
    }
    else if(a < b){
        int c = b - a;
        (c % 2 == 0) ? cnt = 2 : cnt = 1;
    }
    else 
        cnt = 0;
    cout << cnt;
}
using namespace std;
//1659A
//distribute a given number of ('R') & ('B') characters across a sequence of specified length as@
//evenly as possible, with the goal of minimizing large clusters of 'R's between each 'B'.
void DistributeChar(){
    int n, r, b; cin >> n >> r >> b;
    int segment = r / (b + 1);
    int extraRed = r % (b + 1);
    string res = " ";
    for(int i = 0; i < b + 1; i++){
        res += string(segment + (extraRed > 0 ? 1 : 0), 'R');
        if(extraRed > 0)
            extraRed--;
        if(i < b)
            res += 'B';
    }
    cout << res;
}
using namespace std;
//352B
void JeffAndPeriod(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<int, int> idx;
    for(int i = 0; i < n; i++){
        if(idx.find(arr[i]) != idx.end()){
            int dist = i - idx[arr[i]];
            cout << "Distance between repeated element " << arr[i] << " id " << dist;
        }
        idx[arr[i]] = i;
    }
}
using namespace std;
//977C
void LessOrEqual(){
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    if(k == 0){
        int res = arr[0] - 1;
        cout << (res > 0) ? res : -1;
    }
    else if(k == n)
        cout << arr[n - 1];
    else{
        if(arr[k - 1] == arr[k])
            cout << -1;
        else
            cout << arr[k - 1];
    }
}
using namespace std;
//1325B
void CopyCopy(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int cnt = n;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1])
            cnt--;
    }
    cout << cnt;
}
using namespace std;
void AlyonaAndNumbers(){
    int n, m; cin >> n >> m;
    int arr[5] = {0}, tmp[5] = {0};
    for(int i = 1; i <= n; i++)
        arr[i % 5]++;
    for(int i = 1; i <= m; i++)
        tmp[i % 5]++;
    cout << arr[0] * tmp[0] + arr[1] * tmp[4] + arr[2] * tmp[3] + arr[3] * tmp[2] + arr[4] * tmp[1];
}
using namespace std;
void PenguinAndSegments(){
    int n, k, sum = 0; cin >> n >> k;
    while(n--){
        int l, r; cin >> l >> r;
        sum += r - l + 1;
    }
    if(sum % k == 0)
        cout << "0";
    else
        cout << k - (sum % k);
}
using namespace std;
void LuckyTicket(){
    int n, sum1 = 0, sum2 = 0;
    string str; cin >> n >> str;
    for(int i = 0; i < n / 2; i++){
        if(str[i] == '7' || str[i] == '4')
            sum1 += str[i] - '0';
        else{
            cout << "No";
            return 0;
        }
    }
    for(int i = n - 1; i >= n / 2; i--){
        if(str[i] == '7' || str[i] == '4')
            sum2 += str[i] - '0';
        else{
            cout << "No";
            return 0;
        }
    }
    (sum1 == sum2) ? cout << "Yes" : cout << "No";
}
using namespace std;
void LunchRush(){
    int n, k, mx = INT_MIN;
    cin >> n >> k;
    while(n--){
        int x, y; cin >> x >> y;
        if(y > k) 
            mx = max(mx, x - (y - k));
        else
            mx = max(mx, x);
    }
    cout << mx;
}
using namespace std;
void AmusingJoke(){
    string a, b, c, str = " ";
    cin >> a >> b >> c;
    str = a + b;
    if(str.size() > c.size()){
        cout << "No";
        return 0;
    }
    sort(c.begin(), c.end());
    sort(str.begin(), str.end());
    //(str == c) ? cout << "Yes" : cout << "No";
    int arr[26] = {0}, tmp[26] = {0};
    for(int i = 0; i < str.size(); i++)
        arr[str[i] - 'A']++;
    for(int i = 0; i < c.size(); i++)
        tmp[c[i] - 'A']++;
    for(int i = 0; i < 26; i++){
        if(arr[i] != tmp[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
using namespace std;
void SystemEquation(){
    int n, m, cnt = 0; cin >> n >> m;
    for(int i = 0; i <= mac(m, n); i++){
        for(int j = 0; j <= max(m, n); j++){
            if((i * i + j == n) && (j * j + i == m))
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
void CandyBags(){
    int n; cin >> n;
    for(int i = 1, j = n * n; i <= j; i++, j--)
        cout << i << " " << j << "\n";
}
using namespace std;
void LLPS(){
    string str; cin >> str;
    int freq[26] = {0};
    for(int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;
    while(freq[str[str.size() - 1] - 'a']--)
        cout << str[str.size() - 1];
}
using namespace std;
void ChewbaсcaAndNumber(){
    string str; cin >> str;
    if(str[0] != '9' && str[0] >= 5)
        str[0] = '9' - str[0] + '0';
    cout << str[0];
    for(int i = 1; i < str.size(); i++){
        if(str[i] >= 5)
            str[i] = '9' - str[i] + '0';
        cout << str[i];
    }
}
void ChewbaсcaAndNumber(){
    string str; cin >> str;
    if(str[0] == '9')
        cout << str[0];
    else
        cout << (str[0] < '5' ? str[0] : '9' - (str[0] - '0'));
    for(int i = 1; i < str.size(); i++)
        cout << (str[i] < '5' ? str[i] : '9' - (str[i] - '0'));
}
using namespace std;
void BoredLife(){
    int a, b, fact = 1; cin >> a >> b;
    for(int i = 1; i <= min(a, b); i++)
        fact *= i;
    cout << fact;
}
using namespace std;
void NextRound(){
    int n, k, cnt = 0; cin >> n >> k;
    k--;
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    for(int i = 0; i < n; i++){
        if(vec[i] && vec[i] >= vec[k])
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void LongestUncommonSubsequence(){
    string a, b; cin >> a >> b;
    if(a == b)
        cout << "-1";
    else
        cout << max(a.size(), b.size());
}
using namespace std;
//1450B
void BallsOfSteel(){
    int n, k; cin >> n >> k;
    int x[n], y[n];
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    bool found = false;
    for(int i = 0; i < n; i++){
        bool withDist = true;
        for(int j = 0; j < n; j++){
            if(i != j){
                long long dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if(d > k){
                    withDist = false;
                    break;
                }
            }
        }
        if(withDist){
            found = true;
            break;
        }
    }
    if(found)
        cout << 1;
    else
        cout << -1;
}
using namespace std;
//1453A
void CancelTheTrain(){
    int m, n, cnt = 0; cin >> m >> n;
    int bottom[n], left[m];
    for(int i = 0; i < n; i++)
        cin >> bottom[i];
    for(int i = 0; i < m; i++)
        cin >> left[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(bottom[i] == left[j])
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
void Games(){
    int n, cnt = 0;
    cin >> n;
    int arr[n], tmp[n];
    for(int i = 0; i < n; i++){
        int x, int y; cin >> x >> y;
        arr[i] = x; 
        tmp[i] = y;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] == tmp[j] && i != j)
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
void Game(){
    int n, cnt = 0; cin >> n;
    vector <int> vec(n), tmp(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i] >> tmp[i];
    sort(vec.begin(), vec.end());
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vec[i] == tmp[j])
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
void Megnets(){
    int n, cnt = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++){
        if(arr[i] != arr[i - 1])
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void BitsPlus(){
    int n, cnt = 0;
    cin >> n;
    string a = "++X", b = "X++", c = "--X", d = "X--";
    while(n--){
        string str; cin >> str;
        if(str == a || str == b)
            cnt++;
        else if(str == c || str == d)
            cnt--;
    }
    cout << cnt;
}
using namespace std;
void BeautifulMatrix(){
    int x, y;
    int arr[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] == 1){
                x = i; y = j;
        }
    }
    cout >> abs(x - 2) + abs(y - 2);
}
using namespace std;
void StoneOnTable(){
    int n, cnt = 0; cin >> n;
    char arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1])
            cnt++;
    }
    cout << cnt;
}
using namespace std;
void BearAndBigBrother(){
    int a, b, cnt = 0;
    cin >> a >> b;
    while(a <= b){
        a *= 3;
        b *= 2;
        cnt++;
    }
    cout << cnt;
}
using namespace std;
void candiesAndASisters(){
    int t; cin >> t;
    int res[t];
    for(int i = 0; i < t; i++){
        int candies; cin >> candies;
        res[i] = (candies - 1)/2;
    }
    for(int i = 0; i < t; i++)
        cout << res[i] << " ";
}
using namespace std;
void loveUsername(){
    int n, cnt = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++){
        int tmp = abs(arr[i + 1] - arr[i]);
        if(tmp > 1)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
int main(){
    int n, cntMin = 0, cntMax = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int maxi = arr[0];
    int mini = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxi){
            cntMax++;
            maxi = arr[i];
        }
        if(arr[i] < mini){
            cntMin++;
            mini = arr[i];
        }
    }
    cout << cntMax + cntMin;
}
using namespace std;
int main(){
    int n, cnt = 0; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] == 1)
            cnt++;
    }
    (cnt == 0) ? cout << "Easy" : cout << "Hard";
}
using namespace std;
void PoliceRecruits(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int available = 0, crimes = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0)
            available += arr[i];
        else{
            if(available > 0)
                available--;
            else
                crimes++;
        }
    }
    cout << crimes;
	
}
using namespace std;
void PoliceRecruite(){
    int n; cin >> n;
    int police = 0, crime = 0, cnt = 0;
    vector <int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        if(vec[i] < 0){
            crime++;
            if(police == 0)
                cnt++;
            else if(police && crime){
                police--;
                crime--;
            }
        }
        else
            police += vec[i];
    }
    cout << cnt;
}
using namespace std;
int removeDup(int arr[], int n){
    if(n == 0 || n == 1)
        return n;
    int j = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] != arr[i + 1])
            arr[j++] = arr[i];
    }
    arr[j++] = arr[n - 1];
    return j;
}
void WannaGuy(){
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int arr[a], tmp[b];
    for(int i = 0; i < a; i++)
        cin >> arr[i];
    for(int i = 0; i < b; i++)
        cin >> tmp[i];
    removeDup(&arr[a], a);
    removeDup(&arr[b], b);
    int cnt = n;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] == j)
                cnt--;
        }
    }
    for(int i = 0; i < b; i++){
        for(int j = 0; j < n; j++){
            if(tmp[i] == j)
                cnt--;
        }
    }
    (cnt == 0) ? cout << "Wann be guy" : cout << "Oh! keyboard";
}

using namespace std;
void Drinks(){
    int n; cin >> n;
    float sum = 0;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        sum += arr[i];
    cout << sum / n;
}
using namespace std;
void main(){
    int n; cin >> n;
    vector <int> vec;
    int val = 1;
    while(n > 0){
        int dig = n % 10;
        if(dig != 0)
            vec.push_back(dig * val);
        n /= 10;
        val *= 10;
    }
    cout << vec.size();
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
using namespace std;
void main(){
    int n; cin >> n;
    int res[10000], cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        while(x > 0){
            int pos = 1;
            while(pos * 10 <= x){
                pos *= 10;
            }
            res[cnt++] = pos;
            x -= pos;
        }
    }
    cout << cnt << "\n";
    for(int i = 0; i < cnt; i++)
        cout << res[i] << " ";
}
using namespace std;
void sumOfRound(){
    int n; cin >> n;
    int ans[n], cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ans[i] = 0;
        if(x % 10 == 0){
            cnt++;
            ans[i] = x;
        }
        else{
            while(x != 0){
                cnt++;
                x /= 10;
            }
        }
    }
    cout << "Count of Operation: " << cnt << "\n";
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
using namespace std;
void VasyaTheHipster(){
    int a, b, c; cin >> a >> b;
    if(a <= b)
        c = a;
    else
        c = b;
    cout << c << " " << (a + b - 2 * c) / 2;
}
using namespace std;
void main(){
    int n; cin >> n;
    int arr[n], tmp[n];
    int cur = 0, maxi = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i] >> tmp[i];
    for(int i = 0; i < n; i++){
        cur -= arr[i] + tmp[i];
        if(cur > maxi)
            maxi = cur;
    }
    cout << maxi;
}
using namespace std;
void Tram(){
    int n; cin >> n;
    int ans[n];
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ans[i] = a + b;
    }
    int maxi = ans[0];
    for(int i = 1; i < n; i++){
        if(ans[i] > maxi)
            maxi = ans[i];
    }
    cout << maxi - 1;
}
using namespace std;
void main(){
    int n, sum = 0, cnt = 0, cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            cnt++; 
            sum = 0;
        }
    }
    cout << cnt;
}p
