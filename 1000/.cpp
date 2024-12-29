using namespace std;
void freeIcecreem(){
    int num, stock, amount, distressCount = 0;
    //A distressCnt is defined as a scenario where an attempt is made to 
    //subtract more ice cream (amount) from the stock than is currently available
    char Type;
    cin >> num >> stock;
    for(int i = 0; i < num; i++){
        cin >> Type >> amount;
        if(Type == '+')
            stock += amount;
        else{
            if(stock >= amount)
                stock -= amount;
            else
                distressCnt++;
        }
    }
    cout << stock << " " << distressCnt;
}
using namespace std;
//determine if using two ovens can bake a given number of cakes faster than using just one oven
void CakeBaking(){
    int numOfCake, batchTime, cakePerBatch, ovenDelay;
    // NumOfCakes:total cakes need to be baked, (BatchTime) :time takes to bake one batch
    // CakesPerBatch:number of cakes that can be baked in one batch.(OvenDelay):time delay after which the second oven can start baking.
    cin >> numOfCake >> batchTime >> cakePerBatch >> ovenDelay;
    //For round the batch it add (cakePerBatch - 1)
    int totalBatch = (numOfCake + cakePerBatch - 1) / cakePerBatch;
    int singleOven = totalBatch * batchTime;
    int firstOven = 0, secondOven = ovenDelay;
    for(int i = 0; i < totalBatch; i++){
        if(firstOven <= secondOven)
            firstOven += batchTime;
        else
            secondOven += batchTime;
    }
    (max(firstOven, secondOven) < singleOven)? cout << "Yes" : cout << "No";
}
using namespace std;
//determine how many characters from a string need to be checked to find a sequence that matches the entire another string in order.
void Matching(){
    string str, ing; cin >> str >> ing;
    int cnt = 0;
    for(int i = 0; str[i]; i++){
        if(str[i] == ing[cnt])
            cnt++;
        if(ing.length() == cnt)
            break;
    }
    cout << cnt;
}
using namespace std;
void insert(){
    set <char> st;
    string str; getline(cin, str);
    for(int i = 0; str[i]; i++){
        if(str[i] == '{' || str[i] == '}' || str[i] == " " || str[i] == ',')
            continue;
        st.insert(str[i]);
    }
    cout << st.size();
}
using namespace std;
void insert(){
    set <int> st;
    int arr[4];
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    st.insert(arr, arr + 4);
    cout << 4 - st.size();
}
using namespace std;
//find the smallest positive integer i such that the last digit of the product x×i is either y or 0
void findSmall(){
    int x, y; cin >> x >> y;
    int i = 1;
    while(true){
        if((x * i) % 10 == 0 || (x * i) % 10 == y){
            cout << i;
            break;
        }
        i++;
    }
}
using namespace std;
//count how many times the cumulative sum of a sequence of integers exceeds a specified limit. 
int cntSum(){
    int n, tmp, limit; cin >> n >> tmp >> limit;
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > tmp) continue;
        sum += x;
        if(sum > limit){
            cnt++;
            sum = 0;
        }
    }
    cout << cnt;
}
using namespace std;
// calculates the probability of rolling a number greater than or equal to the maximum of two given numbers on a six-sided die. 
void probabilities(){
    int x, y; cin >> x >> y;
    int maxi = max(x, y);
    int tmp = (6 - maxi) + 1;
    if(tmp == 6) cout << "1";
    else if(tmp == 5) cout << "5 / 6";
    else if(tmp == 4) cout << "2 / 3";
    else if(tmp == 3) cout << "1 / 2";
    else if(tmp == 2) cout << "1 / 3 ";
    else if(tmp == 1) cout << "1 / 6";
}
using namespace std;
void helpfulMath(){
    string str, ing; cin >> str;
    int j = 0;
    for(int i = 0; str[i]; i++){
        if(isdigit(str[i]))
            ing += str[i];
    }
    sort(ing.begin(), ing.end());
    for(int i = 0; ing[i]; i++){
        if(i > 0)
            cout << "+";
        cout << ing[i];
    }
}
using namespace std;
void longestUncmmonSubseq(){
    string str, ing; cin >> str >> ing;
    if(str == ing)
        cout << -1;
    else
    //If strings are different, LUS will be the length of the longer string
        cout << max(str.length(), ing.length());
}
using namespace std;
//determine which of these arrays have at least one element smaller than a given limit.
void getGreater(){
    int num, limit; cin >> num >> limit;
    vector <int> zeroIdx(num);
    //sets number is num
    for(int i = 0; i < num; i++){
        //size of the set is x;
        int x; cin >> x;
        bool smaller = false;
        for(int j = 0; j < x; j++){
            //element value
            int val; cin >> val;
            if(val < limit){
                smaller = true;
                break;
            }
        }
        if(smaller)
            zeroIdx.push_back(i + 1);
    }
    cout << zeroIdx.size() << "\n";
    for(int i = 0; i < zeroIdx.size(); i++)
        cout << i << " ";
}
// find the index of the element in the array arr that has the minimum absolute difference from a given value n. 
using namespace std;
void minDiff(){
    int x, y; cin >> x >> y;
    int res = x / y;
    int arr[3] = { abs(res - 1) * y, res * y, (res + 1) * y};
    int minIdx = 0;
    for(int i = 0; i < 3; i++){
        if(abs(x - arr[i]) < abs(x - arr[minIdx]) || (abs(x - arr[i]) == abs(x - arr[minIdx]) && arr[i] > arr[minIdx]))
            minIdx = i;
    }
    cout << minIdx;
}
// count how many elements from the first vector do not have a matching element in the second vector . 
using namespace std;
void cntUnmatched(){
    int n;
    while(cin >> n){
        vector <int> vec(n), tor(n);
        for(int i = 0; i < n; i++)
            cin >> vec[i];
        for(int i = 0; i < n; i++)
            cin >> tor[i];
        int Unmatched = 0;
        bool match = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vec[i] == tor[j]){
                    tor[j] = 0;
                    match = true;
                    break;
                }
            }
            if(!match)
                Unmatched++;
        }
        cout << Unmatched;
    }
}
using namespace std;
//calculate a student's final grade based over four scores and three additional values that represent some assessment or performance metrics. 
void gradeCalculation(){
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
    int remain = 0;
    for(int i = 0; i < 3; i++){
        if(i == minIdx)
            continue;
        remain += arr[i];
    }
    sum += remain / 2;
    if(sum >= 90) cout << "A";
    else if(sum >= 80) cout << "B";
    else if(sum >= 70) cout << "C";
    else if(sum >= 60) cout << "D";
    else cout << "F";
}
using namespace std;
// count how many times a number is greater or less than the prv one in the sequence, starting from a specified initial limit.
void cntLimit(){
    int n, limit; cin >> n >> limit;
    int high = 0, low = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > limit) high++;
        else if(x < limit) low++;
        limit = x;
    }
    cout << high << " " << low;
}
using namespace std;
void incrDecr(){
    int n, x = 0; cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        if(str.length() != 1){
            cout << "its exceed";
            return 1;
        }
        if(str[i] == '+')
            x++;
        else if(str[i] == '-')
            x--;
        else{
            cout << "Invalid";
            return 1;
        }
    }
    cout << x;
}
using namespace std;
//find how many steps are required for each number in a given range [x,y] to reach 1 under the Collatz conjecture and identifying the maximum step count.
void cntMaxStep(){
    int x, y; cin >> x >> y;
    int maxi = 0, idx = 0;
    if(x > y)
        swap(x, y);
    for(int i = x; i <= y; i++){
        int tmp = i, cnt = 1;
        while(tmp > 1){
            if(tmp % 2 != 0)
                tmp = tmp * 3 + 1;
            else
                tmp /= 2;
            cnt++;
        }
        if(cnt > maxi){
            maxi = cnt;
            idx = i;
        }
    }
    cout << "Number with maximum steps: " << idx << " (Steps: " << maxi << ")" << endl;
}
using namespace std;
// snacks arrive in random order and must be placed on a table in descending order from the largest to the smallest. 
//Each time a snack arrives, it determines how many snacks can now be placed on the table and prints them.
void snackTower(){
    int n; cin >> n;
    int arr[n];
    bool tmp[n] = {false};
    int cnt = n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        tmp[arr[i]] = true;
        while(cnt > 0 && tmp[cnt] == true)
            cout << cnt-- << " ";
        cout << "\n";
    }
}
using namespace std;
void upperTolower(){
    string str; cin >> str;
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    cout << str;
}
using namespace std;
void cntChar(){
    int n; cin >> n;
    char arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 'F')
            cnt++;
    }
    (cnt == 1 || cnt == 2 || cnt == 5 || cnt == 8 || cnt == 9)? cout << "No" : cout << "Yes";
}
using namespace std;
//find the pair of minimum index which element sum is greater than trg.
void IdxSum(){
    int n, trg; cin >> n >> trg;
    int arr[n + 1], pairCnt = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int Idxsum = INT_MAX, idx1 = 0, idx2 = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] < trg){
                pairCnt++;
                if((i + j) < Idxsum){
                    Idxsum = i + j;
                    idx1 = i, idx2 = j;
                }
            }
        }
    }
    (pairCnt == 0)? cout << "NUll" << idx1 + 1 << " " << idx2 + 1;
}
using namespace std;
//classify and count sets of color information based on specific conditions, 
void cntColoring(){
    int num; cin >> num;
    char color[1000][3];
    char res[num];
    int idx = 0, greencnt = pinkcnt = 0, greentotal = pinktotal = 0;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 3; j++)
            cin >> color[i][j];
    }
    for(int i = 0; i < num; i++){
        int greenset = blueset = 0;
        if(pinkcnt == 5){
            res[idx++] = 'g';
            greentotal++;
            pinkcnt = 0; i--;
            // Don't skip the current set
            continue;
        }
        if(greencnt == 5){
            res[idx++] = 'p';
            pinktotal++;
            greencnt = 0;
            i--; continue;
        }
        for(int j = 0; j < 3; j++){
            if(color[i][j] == 'G'){
                greenset++;
                break;
            }
            if(color[i][j] == 'B')
                blueset++;
        }
        if(greenset == 1){
            res[idx++] = 'g';
            greencnt++;
            greentotal++;
        }
        else if(blueset == 3){
            res[idx++] = 'p';
            pinkcnt++;
            pinktotal++;
        }
    }
    cout << greentotal * 3 << "  " << pinktotal * 3;
    for(int i = 0; i < idx; i++){
        if(res[i] == 'g')
            cout << "Green";
        else if(res[i] == 'p')
            cout << "Pink";
    }
}
using namespace std;
void Find3rdsmallest(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int minIdx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
    cout << arr[2];
}
using namespace std;
//print the idx where string matches
vector <int> matchIdx(string txt, string str){
    int n = txt.size(), m = str.size();
    vector <int> vec;
    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(txt[i + j] != str[j])
                break;
        }
        // means the entire substring str matches the corresponding portion of txt.
        if(j == m)
            vec.push_back(i);
    }
    /*for(int i = 0; i <= n - m; i++){
        if(txt.substr(i, m) == str)
            vec.push_back(i);*/
    }
    return vec;
}
int main(){
    string txt = "ABABDABACDABABCABAB";
    string str = "ABABCABAB";  
    vector <int> res = matchIdx(txt, str);
    for(int i = 0; i < res.size(); i++)
        cout << res[i];
}
