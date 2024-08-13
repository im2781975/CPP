void MinesWeeper(){
    int n, m; cin >> n >> m;
    char arr[n][m], ch;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ch;
            if(ch == '.')
                arr[i][j] = '0';
            else
                arr[i][j] = ch;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '*'){
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy++){
                        int nx = i + dx;
                        int ny = i + dy;
                        if(nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] != '*')
                        arr[nx][ny]++;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
    }
}
// determine whether a given integer n can be expressed as the sum of i^j and j^i
void Expressed(){
    int n;
    while(cin >> n){
        bool found = false;
        for(int i = 2; i < 35 &&! found; i++){
            for(int j = 2; j <= i; j++){
                int x = pow(i, j) + pow(j, i);
                if(x == n){
                    cout << "Yes" << " " << x;
                    found = true;
                    break;
                }
                if(x > n)
                    break;
            }
        }
        if(!found)
            cout << "No" << endl;
    }
}
void CountStar(){
    int n; cin >> n;
    string str; cin >> str;
    int cnt = 0, res = 1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '*')
            cnt++;
    }
    int remain = 20 - cnt;
    if(remain <= 0){
        cout << "Invalid Calculation";
        return 1;
    }
    for(int i = 0; i < n - cnt; i++){
        res *= remain;
        remain--;
        if(remain <= 0)
            break;
    }
    cout << res;
}
void Operation(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int nume, denom; 
        char ch;
        cin >> nume >> denom >> ch;
        if(nume % denom == 0)
            cout << nume / denom;
        else{
            if(denom == 1)
                cout << nume << " ";
            else if(nume == 1)
                cout << nume << " " << ch << " " << denom << "\n";
            else{
                int gcdVal = __gcd(nume, denom);
                cout << nume / gcdVal << " " << ch << " " << denom / gcdVal;
            }
        }
        if(i < n)
            cout << endl;
    }
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
void FindStr(){
    string str; cin >> str;
    string name[] {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int cnt[8] = {0};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < name[i].length(); i++){
            if(str[j] == name[i][j])
                cnt[i]++;
        }
    }
    int maxIdx = 0;
    for(int i = 0; i < 8; i++){
        if(cnt[i] > cnt[maxIdx])
            maxIdx = i;
    }
    cout << name[maxIdx];
}
void ModifyString(){
    int n; cin >> n;
    string str; cin >> str;
    string k = "Final";
    for(int i = 0; i < n; i++){
        if(i == 1){
            cout << str << "\n";
            str+= '-';
        }
        else{
            str += k;
            if(i == n - 1)
                str += "Wally";
        }
        cout << str << "\n";
    }
}
//find and output the maximum and minimum values in subarrays
void FindMaxMin(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int query; cin >> query;
    for(int i = 0; i < query; i++){
        int l, r; cin >> l >> r;
        if(l > r) swap(l, r);
        int first = l - 1, last = r - 1;
        int maxIdx = first, minIdx = first;
        int sum = 0;
        for(int i = first + 1; i <= last; i++){
            sum += arr[i];
            if(arr[i] > arr[maxIdx])
                maxIdx = i;
            if(arr[i] < arr[minIdx])
                minIdx = i;
        }
        cout << arr[maxIdx] << " " << arr[minIdx];
    }
}
void Operation(){
    int x; cin >> x;
    int ans = pow(x, 2) + x + 41;
    cout << ans;
}
void BinarySum(){
    int x; cin >> x;
    int sum = 0, i = 0;
    while(x > 0){
        sum += (x % 10) * pow(2, i++);
        x /= 10;
    }
    cout << sum;
}
//distribute a total amount (TotalL) into a specified number of parts (num),
//with each part not exceeding a maximum limit (maxiL). 
void distributeLength(){
    int TotalL, maxiL, num;
    cin >> Total >> maxiL >> num;
    for(int i = 1; i < num; i++){
        if(TotalL >= maxiL){
            cout << maxiL << " ";
            TotalL -= maxiL;
        }
        else if(TotalL > 0){
            cout << TotalL << " ";
            TotalL = 0;
        }
        else
            cout << 0;
    }
}
//determine which of these arrays have at least one element smaller than a given limit.
void GetGreater(){
    int num, limit; cin >> num >> limit;
    vector <int> status(n, 1);
    for(int i = 0; i < num; i++){
        int x; cin >> x;
        bool smaller = false;
        for(int j = 0; j < x; j++){
            int element; cin >> element;
            if(trg > element){
                smaller = true;
                break;
            }
        }
        if(smaller == true)
            status[i] = 0;
    }
    int ZeroCnt = 0;
    int FirstZeroIdx = -1;
    for(int i = 0; i < num; i++){
        if(status[i] == 0){
            ZeroCnt++;
            if(FirstZeroIdx == -1)
                FirstZeroIdx = i;
        }
    }
    cout << ZeroCnt;
    if(ZeroCnt > 1)
        cout << FirstZeroIdx + 1 ;
    for(int i = 0; i < num; i++){
        if(i!= FirstZeroIdx && status[i] == 0)
            cout << " " << i + 1 << " ";
    }
}
//find the index of the element in the array arr that has the minimum absolute difference from a given value n. 
void MinDiff(){
    int x, y; 
    cin >> x >> y;
    int res = x / y;
    int arr[3] = { abs(res - 1)*y,  res * y, (res + 1)* y};
    int tmp[3] = {abs(x - arr[0]), abs(x - arr[1]), abs(x - arr[2])};
    int minIdx = 0;
    for(int i = 1; i < 3; i++){
        if(tmp[i] < tmp[minIdx] || (tmp[i] == tmp[minIdx] && arr[i] > arr[minIdx]))
            minIdx = i;
    }
    cout << minIdx;
}
// count how many elements from the first list (l) do not have a matching element in the second list (r). 
void CountMatch(){
    int n;
    while(cin >> n){
        vector <int> l(n), r(n);
        for(int i = 0; i < n; i++)
            cin >> l[i];
        for(int i = 0; i < n; i++)
            cin >> r[i];
        int UnMatched = 0;
        for(int i = 0; i < n; i++){
            bool Matched = false;
            for(int j = 0; j < n; j++){
                if(l[i] == r[j]){
                    r[j] = 0;
                    Matched = true;
                    break;
                }
            }
            if(Matched == false)
                UnMatched++;
        }
    }
    cout << UnMatched;
}
void GradeCalculate(){
    int sum = 0, arr[5];
    for(int i = 0; i < 4; i++){
        int x; cin >> x;
        sum += x;
    }
    int minIdx = 0;
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
        if(arr[i] < arr[minIdx])
            minIdx = i;
    }
    float remain = 0;
    for(int i = 0; i < 3; i++){
        if(i == minIdx)
            continue;
        remain += arr[i];
    }
    sum += remain/2;
    if(sum >= 90) cout << "A";
    else if(sum >= 80) cout << "B";
    else if(sum >= 70) cout << "C";
    else if(sum >= 60) cout << "D";
    else cout << "F";
    return 0;
}
// count how many times a number is greater than or less than the previous number 
//in the sequence, starting from a specified initial limit.
void CountLimit(){
    int n, limit; cin >> n >> limit;
    int hight = 0, weidth = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > limit) hight++;
        if(x < limit) weidth++;
        limit = x;
    }
    cout << hight << " " << weidth;
}
void Operation(){
    int x, y, maxi = 1, cnt = 0, Ind = 0;
    cin >> x >> y;
    while(x <= y){
        int tmp = x;
        cnt = 1;
        while(tmp > 1){
            if(tmp % 2 != 0)
                tmp = 3 * tmp + 1;
            else
                tmp /= 2;
            cnt++;
        }
        if(cnt > maxi)
            maxi = cnt++;
        Ind++;
    }
    cout << Ind;
}
void ProcessOperation(){
    int n, x = 0; cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str.length() != 1){
            cout << "Can't exceed";
            return 1;
            
        }
        char ch = str[0];
        if(ch == '+')
            x++;
        else if(ch == '-')
            x--;
        else{
            cout << "Invalid Operation";
            return 1;
        }
    }
    cout << x;
}
