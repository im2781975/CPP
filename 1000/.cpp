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
using namespace std;
void cntDiv(int n){
    int cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            //if both divisors are same(ex: 9 / 3 = 3)
            (n / i == i) ? cnt++ : cnt += 2;
        }
    }
    return cnt;
}
using namespace std;
void sumOdd(int num){
    int sum = 0;
    for(int i = 2; i < num; i += 2){
        sum += i + 1;
        sum += i + 1;
    }
    return sum;
}
using namespace std;
void sumEven(int num){
    int sum = 0;
    for(int i = 4; i < num; i += 3){
        sum += i + 1;
        sum += i + 1;
    }
}
using namespace std;
void sumOfDigit(int num){
    return num == 0 ? 0 : num % 10 + sumOfDigit(num / 10);
}
#include<bits/stdc++.h>
using namespace std;
void trgSum(){
    int n;
    while(cin >> n){
        vector <int> price(n);
        for(int i = 0; i < n; i++)
            cin >> price[i];
        sort(price.begin(), price.end());
        int m; cin >> m;
        int left = 0, right = n - 1;
        int book1 = book2 = 0;
        while(left < right){
            int sum = price[left] + price[right];
        if(sum == m){
            book1 = price[left];
            book2 = price[right];
            left++; right--;
        }
        else if(sum < m)
            left++;
        else
            right--;
    }
    cout << "Peter should buy books whose prices are " << book1 << " and " << book2 ;
}
using namespace std;
void distance(){
    int tim, vel; cin >> tim >> val;
    int dist = 2 * tim * vel;
    cout << dist;
}
using namespace std;
void statement(){
    int row, maxi; cin >> row >> maxi;
    int cur = row;
    for(int i = 1; i <= row; i++){
        if(i > cur){
            cout << "\n";
            cur += row;
        }
        cout << i << " ";
    }
}
using namespace std;
void conversion(){
    int x = 10;
    float y = 2.5;
    float res = x / y;
    cout << x << " " << y << " " << res;
}
using namespace std;
void greaterLower(){
    int arr[100], ray[100];
    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    for(int i = 0; i < 3; i++)
        cin >> ray[i];
    int high = low = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > ray[i])
            high++;
        else if(arr[i] < ray[i])
            low++;
        else
            continue;
    }
    cout << high << " " << low;
}
using namespace std;
void printOdd(){
    int n; scanf("%d", &n);
    while(n >= 0){
        if(n % 2 == 0)
            continue;
        else
            cout << n;
        n--;
    }
}
using namespace std;
void statement(){
    int a, b; cin >> a >> b;
    if(a < 0 && b < 0)
        break;
    else
        cout << 100 - abs(a - b);
}
using namespace std;
void strlength(){
    char str[20]; getline(cin, str);
    int len = strlen(str);
    cout << len;
}
using namespace std;
void conversion(){
    int x = 10.5;
    cout << (int)x;
}
using namespace std;
void printvec(){
    vector <int> vec;
    vec.push_back(5);
    while(vec.back() > 0)
        vec.push_back(vec.back() - 1);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
    while(!vec.empty()){
        cout << vec.back() << " ";
        vec.pop_back();
    }
}
using namespace std;
void Insertvec(){
    vector <int> vec;
    for(int i = 0; i < 6; i++){
        int val; cin >> val;
        vec.push_back(val);
    }
    cout << "Even numbers: ";
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] % 2 == 0)
            cout << vec[i] << " ";
    }
    cout << "\nOdd numbers: ";
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] % 2 != 0)
            cout << vec[i] << " ";
    }
    cout << "\nElements are: ";
    while(!vec.back()){
        cout << vec.back();
        vec.pop_back();
    }
}
using namespace std;
template <class x>
void swapped(x &a, x &b){
    x tmp = a;
    a = b;
    b = tmp;
    cout << a << " " << b;
}
int main(){
    float a = 20.9, b = 17.45;
    swapped(a, b);
}
using namespace std;
void loop(){
    for(int i = 4; i <= 20; i++){
        for(int j = 1; j <= 20; j++){
            for(int k = 1; k <= 20; k++){
                if(i + j + k == 20 && (i / k + 2 * j + 3 * k) == 20)
                    cout << i << " " << j << " " << k << "\n";
            }
        }
    }
}
using namespace std;
void printDiv(){
    char str[200]; gets(str);
    int len = strlen(str);
    int res = 0;
    for(int i = 0; i < len ; i++){
        if(str[i] == 'a' || str[i] == 'd' || str[i] == 'g' || str[i] == 'j' || str[i] == 'm' || str[i] == 'p' || str[i] == 't' || str[i] == 'w' || str[i] == ' ')
            res += 1;
        else if(str[i] == 'b' || str[i] == 'e' || str[i] == 'h' || str[i] == 'k' || str[i] == 'n' || str[i] == 'q' || str[i] == 'u' || str[i] == 'x')
            res += 2;
        else if(str[i] == 'c' || str[i] == 'f' || str[i] == 'i' || str[i] == 'l' || str[i] == 'o' || str[i] == 'r' || str[i] == 'v' || str[i] == 'y')
            res += 3;
        else if(str[i] == 's' || str[i] == 'z')
            res += 4;
        cout << res;
}
using namespace std;
void revstr(){
    string str; cin >> str;
    for(int i = str.size() - 1; i >= 0; i--)
        cout << str[i];
}
void revstr(){
    char str[100]; gets(str);
    int len = strlen(str) - 1;
    for(int i = 0; i < len; i++){
        int tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        len--;
    }
    cout << str;
}
using namespace std;
void printArr(){
    int arr[100];
    while(true){
        int n; cin >> n;
        if(n == 0)
            break;
        arr[1] = 1;
        for(int i = 2; i <= 100; i++)
            arr[i] = i * i + arr[i - 1];
        cout << arr[n];
    }
}
using namespace std;
class student{
    char name[200];
    int mark1, mark2, mark3;
    friend class friendclass;
    public:
    void getData(){
        cin >> name;
        cin >> mark1 >> mark2 >> mark3;
    }
    void disp(int avg){
        cout << "Name: " << name;
        cout << "\nAvg: " << avg;
    }
};
class friendclass{
    public:
    void average(student &st){
        int avg = (st.mark1 + st.mark2 + st.mark3) / 3;
        st.disp(avg);
    }
};
int main(){
    student st; 
    st.getData();
    friendclass obj;
    obj.average(st);
    getch();
}
using namespace std;
void reversed(){
    int n; cin >> n;
    int tmp = n;
    while(n > 0){
        int rem = n % 10;
        cout << rem;
        n /= 10;
    }
}
void reversed(){
    int n; cin >> n;
    int rev = 0;
    while(n > 0){
        int rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    cout << rev
}
using namespace std;
void currentBill(){
    int unit; cin >> unit;
    int charge = subCharge = 0;
    if(unit <= 100) charge += unit 0.60;
    else if(unit > 100 && unit <= 300)
        charge += (100 * 0.60) + (unit - 100) * 0.80;
    else if(unit > 300)
        charge += (100 * 0.60) + (200 * 0.80) + (unit - 300) * 90;
    if(charge < 50)
        charge = 50;
    if(charge > 300){
        scharge = 0.5 * charge;
        charge += scharge;
    }
    cout << fixed << setprecision(2) << charge;
}
using namespace std;
void pattern(){
    int n; cin >> n;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= i; j++)
            cout << "*";
        cout << "\n";
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++)
            cout << "*";
        for(int k = 1; k <= i; k++)
            cout << " ";
        cout << "\n";
    }
}
using namespace std;
void Xmass(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++)
            cout << " ";
        for(int k = 1; k <= i; k++)
            cout << "*";
        cout << "\n";
    }
}
using namespace std;
void triangle(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= i; j++)
            cout << " ";
        for(int k = n; k >= i; k--)
            cout << "*";
        cout << "\n";
    }
}
using namespace std;
void triangle(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++)
            cout << '*';
        cout << "\n";
    }
}
using namespace std;
void triangle(){
    int n; cin >> n;
    for(int i = n; i >= 1; i--){
        for(j = 1; j <= i; j++)
            cout << '*';
        cout << "\n";
    }
}
using namespace std;
void Butterfly(){
    int n; cin >> n;
    for(int i = n; i >= 1; i--){
        for(int j = i; j >= 1; j--)
            cout << "*";
        cout << "\n";
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++)
            cout << "*";
        cout << "\n";
    }
}
using namespace std;
void reversed(){
    int n; cin >> n;
    while(n > 0){
        int mod = n % 10;
        cout << mod ;
        n /= 10;
    }
}
using namespace std;
void triangular(){
    int n; cin >> n;
    cout << (n * (n + 1)) / 2;
}
using namespace std;
//special number
int fact(int n){
    if(n == 0)
        return 1;
    return n * fact(n - 1);
}
int main(){
    int n; cin >> n;
    int tmp = n, sum = 0;
    while(n > 0){
        int rem = n % 10;
        n /= 10;
        sum += fact(n);
    }
    (sum == tmp) ? cout << "Special number" : cout << "Not special";
}
using namespace std;
void containDigits(){
    int n; cin >> n;
    int tmp = n;
    int a = n % 10;
    n /= 10;
    int b = n % 10;
    if((a + b) + (a * b) == tmp)
        cout << "Contain special digits";
    else
        cout << "Doesn't contain special digits";
}
using namespace std;
void PerfectDiv(){
    int n, sum = 0; cin >> n;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            int div1 = i, div2 = n / i;
            if(div1 * div2 == n)
                sum += div1;
            else
                sum += div1 + div2;
        }
    }
    if(sum == n) cout << "Perfect";
    else if(sum < n) cout << "Difficient";
    else cout << "Abumdant";
}
using namespace std;
void fibSeries(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        if(i == 0)
            arr[i] = 0;
        else if(i == 1)
            arr[i] = 1;
        else 
            arr[i] = arr[i - 1] + arr[i - 2];
        cout << arr[i] << " ";
    }
}
#include<bits/stdc++.h>
using namespace std;
void consecutiveSum(){
    int row; cin >> row;
    int arr[row];
    for(int i = 0; i < row; i++)
        cin >> arr[i];
    for(int i = 1; i < row; i++)
        arr[i] += arr[i - 1];
    int pos; cin >> pos;
    cout << arr[pos];
}
using namespace std;
void consecutiveSum(){
    int row, col; cin >> row >> col;
    int arr[row][col];
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++)
            cin >> arr[i][j];
    }
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++)
            arr[i][j] += arr[i][j - 1];
    }
    //positions
    int x, y; cin >> x >> y;
    cout << arr[x][y];
}
#include<bits/stdc++.h>
using namespace std;
void teamScore(){
    int n; cin >> n;
    int score[100200], maxi = 0, mini = INT_MAX, total = 0;
    for(int i = 0; i < n; i++){
        cin >> score[i];
        maxi = max(maxi, score[i]);
        mini = min(mini, score[i]);
        total += score[i];
    }
    double avg = static_cast <int>(total) / n;
    cout << maxi << " " << mini << " " << total << " " << avg;
}
using namespace std;
void Morse(){
    string str, ing; cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '.')
            ing += '0';
        else if(str[i] == '-'){
            if(i + 1 < len && str[i + 1] == '.'){
                ing += '1'; 
                i++; //skip this value
            }
            else if(i + 1 < len && str[i + 1] == '-'){
                ing += '2';
                i++; //skip this value;
            }
        }
    }
    cout << ing;
}
using namespace std;
int GCD(int a, int b){
    if(a % b == 0)
        return b;
    return GCD(b, a % b);
}
int main(){
    int cnt = 0;
    for(int i = 1; i <= 2020; i++){
        for(int j = 1; j <= 2020; j++){
            if(GCD(i, j) == 1)
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
//cnt remainder two containt digit
int remTwo(int n){
    int cnt = 0;
    while(n){
        if(n % 10 == 2)
            cnt++;
        n /= 10;
    }
    return cnt;
}
int main(){
    int res = 0;
    for(int i = 1; i <= 2020; i++){
        res += remTwo(i);
    }
    cout << res;
}
using namespace std;
//find the divisor of 100 that minimizes the value of the expression 100 / i + i
void findDiv(){
    int res = 0, sum = INT_MAX;
    for(int i = 1; i <= 100; i++){
        if(100 % i == 0){
            int cur = 100 / i + i;
            if(sum > cur){
                sum = cur;
                res = i;
            }
        }
    }
    cout << res;
}
using namespace std;
//convert number format to string format
void printChar(){
    string str; cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(i + 1 < str.size() && isdigit(str[i + 1])){
            int n = str[i + 1] - '0';
            for(int j = 0; j < n; j++)
                cout << str[i] << " ";
            i++; //skips over the digit because it has already been processed
        }
        else
            cout << str[i] << " ";
    }
}
using namespace std;
//Replace 'BG' with 'GB'
void replace(){
    int n; cin >> n;
    string str; cin >> str;
    size_t found = 0;
    while(found < str.size()){
        //Search for the substring "BG" starting from index `found`
        found = str.find("BG", found); 
        if(found != string :: npos){
            str[found] = 'G';
            str[found + 1] = 'B';
            found += 2;
        }
        else
            break;
    }
    cout << str;
}
using namespace std;
void statement(){
    int n; cin >> n;
    string str[n];
    for(int i = 0; i < n; i++)
        cin >> str[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((str[i][0] == str[j][0] && str[i][1]!= str[j][1]) || (str[i][0] != str[j][0] && str[i][1] == str[j][1]))
                cnt++;
        }
    }
    cout << cnt;
}
using namespace std;
void evenOddIdx(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    bool valid = true;
    int evenIdx = arr[0] % 2;
    for(int i = 0; i < n; i+= 2){
        if(arr[i] % 2 != evenIdx){
            valid = false;
            break;
        }
    }
    if(valid){
        int oddIdx = (n > 1) ? arr[1] % 2 : evenIdx;
        for(int i = 1; i < n; i += 2){
            if(arr[i] % 2 != oddIdx){
                valid = false;
                break;
            }
        }
    }
    cout << valid ? "Yes" : "No";
}
#include<bits/stdc++.h>
using namespace std;
void find3Consecutive(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(n < 3){
        cout << -1;
        continue;
    }
    sort(arr, arr + n);
    bool found = false;
    for(int i = 0; i < n - 2; i++){
        if(arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]){
            cout << arr[i];
            found = true;
            break;
        }
    }
    if(!found)
        cout << -1;
}
using namespace std;
void consecutive(){
    string str; cin >> str;
    int len = str.length();
    if(len == 1){
        cout << "No";
        return 0;
    }
    bool valid = true;
    for(int i = 0; i < len; i++){
        if(i == 0){
            if(str[i] != str[i + 1]){
                valid = false;
                break;
            }
        }
        else if(i == n - 1){
            if(str[i] != str[i - 1]){
                valid = false;
                break;
            }
        }
        else{
            if(str[i] != str[i - 1] && str[i] != str[i + 1])
                valid = false;
                break;
        }
    }
    cout << (valid) ? cout : "Yes" : cout << "No";
}
using namespace std;
string RemoveDup(string str){
    string res = "";
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(!res.empty() && res.back() == ch)
            res.pop_back();
        else
            res.push_back(ch);
    }
    return (res.empty()?"Empty" : res);
}
int main(){
    string str; cin >> str;
    cout << RemoveDup(str);
}
using namespace std;
bool sortbysec(const pair <string, int> &a, const pair <string, int> &b){
    //always return greater value
    if(a.second != b.second)
        return a.first > b.first;
    // if one is prefix of another return greater one
    if(a.first.find(b.first) == 0 || b.first.find(b.first) == 0)
        return a.first.size() > b.first.size();
    //return laxicografical order
    return a.first < b.first;
}
int main(){
    int n; cin >> n;
    vector <pair <string, int> > vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    //string represent the name & int represeng the mark
    sort(vec.begin(), vec.end(), sortbysec);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i].first << " " << vec[i].second << "\n";
}
using namespace std;
void windowsSum(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    int tmp[n];
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            if(i != j)
                sum += arr[j];
        }
        tmp[i] = sum;
        sum = 0;
    }
    for(int i = 0; i < n; i++)
        cout << tmp[i] << " ";
}
using namespace std;
//print prime numbers within range
int prime[100200];
int main(){
    int num; cin >> num;
    int k = 0;
    for(int i = 2; i <= num; i++){
        bool IsPrime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                IsPrime = false;
                break;
            }
        }
        if(IsPrime)
            prime[k++] = i;
    }
    for(int i = 0; i < k; i++)
        cout << prime[i] << " ";
}
using namespace std;
//find and output the maximum and minimum values in subarrays
void findMaxMin(){
    int n; cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int query; cin >> query;
    for(int i = 0; i < query; i++){
        int l, r; cin >> l >> r;
        if(l > r) swap(l, r);
        int first = l - 1, last = r - 1;
        int maxIdx = first, minIdx = first;
        for(int i = first + 1; i <= last; i++){
            if(arr[i] > arr[maxIdx])
                maxIdx = i;
            if(arr[i] < arr[minIdx])
                minIdx = i;
        }
        cout << arr[maxIdx] << " " << arr[minIdx];
    }
}
using namespace std;
void modifyStr(){
    int n; cin >> n;
    string str; cin >> str;
    string k = "Final";
    for(int i = 0; i < n; i++){
        if(i == 1){
            cout << str << "\n";
            str += '-';
        }
        else{
            str += k;
            if(i == n - 1)
                str += "Wally";
        }
    }
    cout << str << "\n";
}
using namespace std();
void printStr(){
    string str; cin >> str;
    string name[]{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int cnt[8] = {0};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < name[i].length(); j++){
            if(str[i] == name[i][j])
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
using namespace std;
void Operation(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int denom, numer; cin >> numer >> denom;
        char ch; cin >> ch;
        if(numer % denom == 0)
            cout << numer / denom << " ";
        else{
            if(denom == 1)
                cout << numer << " ";
            else if(numer == 1)
                cout << numer << " " << ch << " " << denom;
            else{
                int gcd = __gcd(numer, denom);
                cout << numer / gcd << " " << ch << " " << denom / gcd;
            }
        }
        if(i < n)
            cout << endl;
    }
}
using namespace std;
//determine how many ways stars ('*') can be added to a string of length n while keeping the total length below or equal to 20. 
void cntStar(){
    int n; cin >> n;
    string str; cin >> str;
    int notStar = 0, res = 1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '*')
            notStar++;
    }
    int remSlot = 20 - notStar;
    if(remSlot <= 0){
        cout << "Invalid";
        return;
    }
    int res = 1;
    for(int i = 0; i < n - notStar; i++){
        res *= remSlot;
        remSlot--;
        if(remSlot <= 0)
            break;
    }
    cout << res;
}
using namespace std;
// determine whether a given integer n can be expressed as the sum of i^j and j^i
void expressed(){
    int n;
    while(cin >> n){
        bool found = false;
        for(int i = 2; i <= 35 && !found; i++){
            for(int j = 2; j <= i; j++){
                int x = pow(i, j) + pow(j, i);
                if(x == n){
                    cout << "Yes " << x;
                    found = true;
                    break;
                }
                if(x > n) break;
            }
        }
        if(!found)
            cout << "No";
    }
}
using namespace std;
//Increment the adj matrix point & print the matrix
void minesWeeper(){
    int row, col; cin >> row >> col;
    char ch, arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> ch;
            if(ch == '.')
                arr[i][j] = '0';
            else 
                arr[i][j] = '*';
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int dx = -1; dx <= 1; dx++){
                //incr 8 direction
                for(int dy = -1; dy <= 1; dy++){
                    //skip the cur pos
                    if(dx == 0 && dy == 0)
                        continue;
                    int nx = i + dx;
                    int ny = j + dy;
                    //check bound
                    if(nx >= 0 && ny >= 0 && nx < row && ny < col && arr[nx][ny] != '*')
                        arr[nx][ny]++;
                }
            }
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}
using namespace std;
// count the number of elements in an array that are neither the min nor the max value of the array. 
void OathOfNightWatch(){
    int n; cin >> n;
    int arr[n], cnt = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 1; i < n - 1; i++){
        if(arr[0] < arr[i] && arr[n - 1] > arr[i])
            cnt++;
    }/*
    int mini = *min_element(arr, arr + n);
    int maxi = *max_element(arr, arr + n);
    for(int i = 0; i < n; i++){
        if(arr[i] > mini && arr[i] < maxi)
            cnt++;
    } */
    cout << cnt;
}
// its a variation of the knapsack problem which tries to maximize the number of items 
//included in a knapsack without exceeding its capacity, while minimizing the total weight.
void Knapsack(){
    int n; cin >> n;
    while(n--){
        int cap, numItem; cin >> cap >> numItem;
        int weight[numItem];
        for(int i = 0; i < numItem; i++)
            cin >> weight[i];
        int totalWeight = 0, itemInclude = 0;
        for(int i = 0; i < numItem; i++){
            int minIdx = i;
            for(int j = i + 1; j < numItem; j++){
                if(weight[i] > weight[j])
                    minIdx = j;
                swap(weight[i], weight[minIdx]);
            }
        }
        for(int i = 0; i < numItem; i++){
            if(totalWeight + weight[i] < cap){
                totalWeight += weight[i];
                itemInclude++;
            }
            else
                break;
        }
    }
    cout << totalWeight << " " << itemInclude;
}
using namespace std;
//simulates an array where each element of the array is reduced by a specified value and the remaining value is redistributed to neighboring elements
void distribute(){
    int n; cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int size; cin >> size; // number of shoots
    for(int i = 0; i < size; i++){
        //index of shoot & value
        int idx, val; cin >> idx >> val;
        
        --idx; //convert to 0-based index
        if(idx == 0){
            if(idx + 1 < n){
                arr[idx + 1] = arr[idx] - val;
                arr[idx] = 0;
            }
        }
        else if(idx == n - 1){
            if(idx - 1 >= 0){
                   arr[idx - 1] += arr[idx] - val;
                   arr[idx] = 0;
            }
        }
        else{
            if(idx + 1 < n)
                arr[idx + 1] += arr[idx] - val;
            if(arr[idx] - val == 0)
                arr[idx - 1] += 1;
            else
                arr[idx - 1] += arr[idx] - val - 1;
            arr[idx] = 0;
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
#include<bits/stdc++.h>
using namespace std;
void roundNum(){
    int n; cin >> n;
    vector <int> res(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 10000 != 0){
            cnt++;
            res[i] = (x / 10000) * 10000;
        }
        else if(x % 1000 != 0){
            cnt++;
            res[i] = (x / 1000) * 1000;
        }
        else if(x % 100 != 0){
            cnt++;
            res[i] = (x / 100) * 100;
        }
        else if(x % 10 != 0){
            cnt++;
            res[i] = (x / 10) * 10;
        }
        else
            res[i] = x; //No round need
    }
    cout << cnt << "\n";
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
//Determining a scaling factor based on the smallest number.
//Combining the scaling factor and the reductions to produce a final value.
using namespace std;
void produceVal(){
    int n = 3, res = 0;
    int arr[n];
    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    int minIdx = 0;
    for(int i = 1; i < 3; i++){
        if(arr[i] < arr[minIdx])
            minIdx = i;
    }
    int smallest = arr[minIdx];
    int factor = 0;
    while(smallest > 10){
        factor++;
        smallest /= 10;
    }
    int scaler = pow(10, factor - 1);
    for(int i = 0; i < 3; i++)
        arr[i] -= scaler;
    while(true){
        if(arr[0] == arr[1] && arr[0] == arr[2]){
            res += arr[0];
            break;
        }
        sort(arr, arr + 3);
        if(arr[0] == 0 && arr[1] == 0)
            break;
        if(arr[0] + arr[1] + arr[2] > 3){
            arr[2] -= 2;
            arr[1] -= 1;
            res++;
        }
        else
            break;
    }
    cout << scaler + res;
}
