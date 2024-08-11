//classify and count sets of color information based on specific conditions, 
void CountColor() {
    int numSets;
    cin >> numSets;
    char colors[1000][3];
    char *results = new char[numSets];
    int resultsIndex = 0, greenCount = 0, pinkCount = 0, greenTotal = 0, pinkTotal = 0;
    for (int i = 0; i < numSets; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> colors[i][j];
        }
    }
    for (int i = 0; i < numSets; i++) {
        int greenInSet = 0, blueInSet = 0;
        // Check if pink or green count has reached 5
        if (pinkCount == 5) {
            results[resultsIndex++] = 'g';
            greenTotal++;
            pinkCount = 0;
            i--; // Don't skip the current set
            continue;
        }
        if (greenCount == 5) {
            results[resultsIndex++] = 'p';
            pinkTotal++;
            greenCount = 0;
            i--;
            continue;
        }
        // Check the conditions for green or pink
        for (int j = 0; j < 3; j++) {
            if (colors[i][j] == 'G') {
                greenInSet++;
                break;
            }
            if (colors[i][j] == 'B')
                blueInSet++;
        }
        if (greenInSet == 1) {
            results[resultsIndex++] = 'g';
            greenCount++;
            greenTotal++;
        } else if (blueInSet == 3) {
            results[resultsIndex++] = 'p';
            pinkCount++;
            pinkTotal++;
        }
    }
    cout << pinkTotal * 3 << " " << greenTotal * 3 << endl;
    for (int i = 0; i < resultsIndex; i++) {
        if (results[i] == 'g')
            cout << "Green" << endl;
        else if (results[i] == 'p')
            cout << "Pink" << endl;
    }
    delete[] results;
    return 0;
}

void Operation(){
    int n = 3, res = 0;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int Idx = 0;
    int minIdx = 0;
    while(Idx < 3){
        if(arr[Idx] < arr[minIdx])
            minIdx = Idx;
        Idx++;
    }
    int Factor = 0;
    float smallest = arr[minIdx], base = 10;
    while(smallest > 10){
        smallest /= 10;
        Factor++;
    }
    smallest = pow(base, Factor - 1);
    Idx = 0;
    while(Idx < 3){
        arr[Idx] -= smallest;
        Idx++;
    }
    while(true){
        if(arr[0] == arr[1] && arr[0] == arr[2]){
            res += arr[0];
            break;
        }
        sort(arr, arr + n);
        if(arr[0] == 0 && arr[1] == 0)
            break;
        if(arr[0] + arr[1] + arr[2] > 3){
            arr[2] -= 2; arr[1] -= 1;
            res++;
            break;
        }
        else 
            break;
    }
    cout << smallest + res;
}

void RoundNum(){
    int n; cin >> n;
    int res[n], cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 10000 != 0){
            cnt++;
            res[i] = (x /10000) * 10000;
        }
        else if(x % 1000 != 0){
            cnt++;
            res[i] = (x /1000) * 1000;
        }
        else if(x % 100 != 0){
            cnt++;
            res[i] = (x /100) * 100;
        }
        else if(x % 10 != 0){
            cnt++;
            res[i] = (x /10) * 10;
        }
        else
            res[i] = x;
    }
    cout << cnt;
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
// count the number of elements in an array that are neither the min nor the max value of the array. 
void OathOfTheNightWatch(){
    int n, cnt = 0, flagMin, flagMax; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    /*for(int i = 1; i < n - 1; i++){
        if(arr[0] < arr[i] && arr[n  - 1] > arr[i])
            cnt += 1;
    }*/
    for(int i = 1; i < n - 1; i++){
        int tmp = arr[i];
        for(int j = 0; j < n; j++){
            if(arr[j] < tmp){
                flagMin = 1; break;
            }
        }
        for(int j = 0; j < n; j++){
            if(arr[j] > tmp){
                flagMax = 1; break;
            }
        }
    }
    if(flagMin == 1 && flagMax == 1)
        cnt += 1;
    cout << cnt;
}
// its a variation of the knapsack problem which tries to maximize the number of items 
//included in a knapsack without exceeding its capacity, while minimizing the total weight.
void Knapsack(){
    int n;cin >> n;
    while(n-- > 0){
        int cap, NumItem;
        cin >> cap >> NumItem;
        int *weight = new int[NumItem];
        int TotalWeight = 0, ItemCnt = 0, ItemInclude = 0;
        for(int i = 0; i < NumItem; i++)
             cin >> weight[i];
        for(int i = 0; i < NumItem; i++){
            int minIdx = i;
            for(int j = i + 1; j < NumItem; j++){
                if(weight[j] < weight[minIdx])
                    minIdx = j;
            }
            swap(weight[minIdx], weight[i]);
        }
        for(int i = 0; i < NumItem; i++){
            if(TotalWeight + weight[i] <= cap ){
                TotalWeight += weight[i];
                ItemInclude++;
            }
            else 
                break;
        }
        cout << TotalWeight << " " << ItemInclude << "\n";
    }
}
// find the position of the nearest 'E' (for example, an 'E' might represent an "Emergency" or an "Element") in a 2D grid. 
void FindPos(){
    int row, col, cnt = 0, mini = INT_MAX, MinRow = -1, MinCol = -1;
    cin >> row >> col;
    char arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j <col; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == 'E'){
                int dist = i + j;
                if(distance < mini){
                    //convert to 1-Based Idx
                    MinRow = i + 1;
                    MinCol = j + 1;
                }
                cnt++;
            }
        }
    }
    (cnt == 0)?cout << -1 : cout << MinRow << " " << MinCol;
}
void FindTrgIdx(){
    int n, TrgIdx, cnt = 0;
    cin >> n >> TrgIdx;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(TrgIdx < 1 || TrgIdx > n){
        cout << "OutOf Bound";
        return 0;
    }
    if(arr[TrgIdx - 1] == 0){
        for(int i = 0; i < n; i++){
            if(arr[i] > 0)
                cnt++;
        }
    }
    else{
        cnt = TrgIdx;
        for(int i = TrgIdx; i < n; i++){
            if(arr[TrgIdx - 1] <= arr[i])
                cnt++;
        }
    }
    cout << cnt << "\n" << arr[TrgIdx - 1] << "\n";
    if(TrgIdx < n)
        cout << arr[TrgIdx] << "\n";
    else
        cout << "Idx OutOfBound";
}

//output the sequence of unique number
const int MAX = 1001;
void Unique(){
    int n, cnt = 0, arr[MAX] = {0};
    cin >> n;
    int Unique[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(arr[x] == 0)
            arr[x] = 1;
        Unique[cnt++] = x;
    }
    for(int i = 0; i < cnt; i++)
        cout << Unique[i] << " ";
}

void ChangePos(){
    int n; cin >> n;
    char ch[26];
    vector <char> arr(n);
    vector <int> tmp(n);
    vector <bool> used(n, false);
    vector <int> res(n);
    for(int i = 0; i < 26; i++)
        ch[i] = 'a' + i;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(arr[i] == ch[j]){
                tmp[i] = j + 1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        int minIdx = -1;
        for(int j = 0; j < n; j++){
            if(!used[j] && (minIdx == - 1 || tmp[j] < tmp[minIdx]))
                minIdx = j;
        }
        res[minIdx] = n - i;
        used[minIdx] = true;
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}

// determine process a list of integers representing the positions of 
//citizens in Lineland and determine two values for each citizen: minimum & maximum distance to any other citizen.
void LinelandMail(){
    int n; cin >> n;
    int arr[n], maxi[n], mini[n], res[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    /*for(int i = 0; i < n; i++){
        maxi[i] = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
        if(i == 0)
            mini[i] = abs(arr[i] - arr[i + 1]);
        else if(i == n - 1)
            mini[i] = abs(arr[i] - arr[i - 1]);
        else
            mini[i] = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
    }
    for(int i = 0; i < n; i++)
        cin << maxi[i] << " " << mini[i];*/
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            if(arr[i] == arr[j])
                continue;
            if(arr[i] > arr[j])
                res[j] = arr[i] - arr[j];
            else
                res[j] = arr[j] - arr[i];
                
        }
    }
    sort(res, res + n);
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}

// create as many complete teams as possible where each team consists of 
//one student with each of three different types of gifts. Each team should have one student 
//with gift type 1, one student with gift type 2, and one student with gift type 3.
void TeamOlympiad(){
    int n; cin >> n;
    vector <int> count(4, 0);
    vector <vector <int> >student(4, vector <int> (5001));
    for(int i = 1; i <= n; i++){
        //loop runs n times for each student.each iteration, it reads the type of gift from the input.
        int gift; cin >> gift;
        count[gift]++;
        student[gift][count[gift]] = i;
    }
    //teams is calculated as the minimum value among the counts of gift types 1, 2, and 3.
    // it is the maximum number of teams that can be formed, where each team has one student with each type of gift.
    int team = min({count[1], count[2], count[3]});
    for(int i = 1; i <= team; i++){
    //prints the index of a student with gift type 1, gift type 2, and gift type 3.
        cout << student[1][i] << "\n";
        cout << student[2][i] << "\n";
        cout << student[3][i] << "\n";
    }
}
void Presents(){
    int n; cin >> n;
    int arr[n], freq[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] >= 1 && arr[i] <= n)
            freq[arr[i] - 1] = i + 1;
    }
    for(int i = 0; i < n; i++)
        cout << freq[i] << " ";
}
void NewPassword(){
    int TotalLength, CycleLength, i;
    cin >> TotalLength >> CycleLength;
    char alpha[26] = {0};
    for(int i = 0; i <  26; i++){
        alpha[i] = 'a' + i;
    }
    /*for(i = 97; i <= 122; i++)
        alpha[i - 97] = i;
    alpha[i] = '\0';*/
    int CompleteCycle = TotalLength / CycleLength;
    for(int i = 0; i < CompleteCycle; i++){
        for(int j = 0; j < CycleLength; j++) 
            cout << alpha[j] << " ";
    }
    cout << "\n";
    int remainChar = TotalLength % CycleLength;
    for(int i = 0; i < remainChar; i++)
        cout << alpha[i] << " ";
    cout << "\n";
}
//find the smallest positive integer i such that the last digit of the product x×i is either y or 0
void FindSmall(){
    int x, y;
    cin >> x >> y;
    while(true){
        if((x * i) % 10 == y || (x * i) % 10 == 0){
            cout << i;
            break;
        }
        else
            i += 1;
    }
}
void insert(){
    set <int> st;
    int arr[4];
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    st.insert(arr, arr + 4);
    cout << 4 - st.size();
}
void Insert(){
    set <char> st;
    string str;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '{' || str[i] == '}' || str[i] == ',' || str[i] == ' ')
            continue;
        else
            st.insert(str[i]);
    }
    cout << st.size();
}
//determine how many characters from the string ing need to be checked to 
//find a sequence that matches the entire string str in order.
void Matching(){
    int tmp = 0;
    string str, ing;
    cin >> str >> ing;
    for(int i = 0; i < ing.length(); i++){
        if(str(tmp) == ing(i))
            tmp++;
        if(tmp == str.length())
            break;
    }
    cout << tmp + 1;
}
// calculates the probability of rolling a number greater than or equal to the maximum of two given numbers on a six-sided die. 
void probabilities(){
    int x, y; cin >> x >> y;
    int maxi = (x > y) ? x : y;
    int tmp = (6 - maxi) + 1;
    if(tmp == 6)
        cout << "1";
    else if(tmp == 5)
        cout << "5/6";
    else if(tmp == 4)
        cout << "2/3";
    else if(tmp == 3)
         cout << "1/2";
    else if(tmp == 2)
         cout << "1/3";
    else if(tmp == 1)
        cout << "1/6";
}
void ShotsValue(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int Noshots; cin >> Noshots;
    for(int i = 0; i < Noshots ; i++){
        int idx, shotsval; cin >> idx >> shotsval;
        --idx;
        /*if(idx != 0)
            arr[idx - 1] += shotsval - 1;
        if(idx != n - 1)
            arr[idx + 1] += arr[idx] - shotsval;
        arr[idx] = 0;*/
        if (idx == 0){ 
            // First element
            arr[idx + 1] += arr[idx] - shotsval;
            arr[idx] = 0;
        } 
        else if (idx == n - 1){ 
            // Last element
            arr[idx - 1] += arr[idx] - shotsval;
            arr[idx] = 0;
        } 
        else{ 
            // Middle elements
            arr[idx + 1] += arr[idx] - shotsval;
            if (arr[idx] - shotsval == 0) {
                arr[idx - 1] += 1;
            } else {
                arr[idx - 1] += arr[idx] - shotsval - 1;
            }
            arr[idx] = 0;
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
//count how many times the cumulative sum of a sequence of integers exceeds a specified limit. 
void CountSum(){
    int n, x, y, sum = 0, cnt = 0;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a > x)
            continue;
        sum += a;
        if(sum > y){
            sum = 0;
            cnt++;
        }
    }
    cout << cnt;
}
void CakeMaking(){
    int numOfCakes, BakeTime, CakesPerBatch, OvenDelay;
    // NumOfCakes:total number of cakes that need to be baked
    // BakeTime:the time it takes to bake one batch of cakes
    // CakesPerBatch:stores the number of cakes that can be baked in one batch.
    // OvenDelay:stores the time delay after which the second oven can start baking.
    cin >> numOfCakes >> BakeTime >> CakesPerBatch >> OvenDelay;
    // Calculate the time taken by one oven
    int TotalBatches = (numOfCakes + CakesPerBatch - 1)/CakesPerBatch;
    int singleOven = TotalBatches * BakeTime;
    int FirstOven = 0, SecondOven = OvenDelay;
    for(int i = 0; i < TotalBatches; i++){
        if(FirstOven <= SecondOven)
            FirstOven += BakeTime:
        else
            SecondOven += BakeTime;
    }
    (max(FirstOven, SecondOven) < singleOven)? cout << "Yes": cout << "No";
}
void FreeIceCream(){
    int num, stock, amount, DistressCount;
    char Type;
    // distressCount variable is used to track the number of times a distress situation occurs.
    //A distress situation is defined as a scenario where an attempt is made to 
    //subtract more ice cream (amount) from the iceCreamStock than is currently available.
    cin >> num >> stock >> amount >> DistressCount;
    for(int i = 0; i < num; i++){
        cin >> Type >> amount;
        // If operation is '+', add amount to ice cream stock
        // If operation is '-', check if there is enough ice cream to subtract
        if(Type == '+')
            stock += amount;
        else{
            if(stock >= amount)
                stock -= amount;
            else
                DistreessCount++;
        }
    }
    cout << stock << " " << DistreessCount;
}
void HelpFulMath(){
    char str[100], arr[100];
    int j = 0;
    cin >> str;
    for(int i = 0; str[i]!= '\0'; i++){
        if(str[i] != '\0')
            arr[j++] = str[i];
    }
    str[j] = '\0';
    sort(arr, arr + j);
    for(int i = 0; i < j; i++){
        if(i > 0)
            cout << "+";
        cout << arr[i];
    }
}
void LongestUncommonSubsequence(){
    string str, ing;cin >> str >> ing;
    if(str == ing)
        cout << -1;
    else if(str.length() > ing.length())
        cout << str.length();
    else
        cout << ing.length();
}
void SnackTower(){
    int n; cin >> n;
    int arr[n + 1];
    bool tmp[n + 1] = {false};
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int t = n;
    for(int i = 1; i <= n; i++)
        tmp[arr[i]] = true;
    while(t > 0 && tmp[t] == true)
        cout << t-- << " ";
}
void UpperToLower(){
    string str; cin >> str;
    for(int i = 0; str[i]!= '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    cout << str;
}

//check if the count of the character 'F' in a given array of characters is one of the specific values (1, 2, 5, 8, or 9).
void CountChar(){
    int n, cnt = 0; cin >> n;
    char arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == 'F')
            cnt++;
    }
    (cnt == 1 || cnt == 2 || cnt == 5 || cnt == 8 || cnt == 9)? cout << "No": cout << "Yes";
}
// find and print the indices (1-based) of the pair of elements in the array whose 
//sum is greater than trg and has the smallest combined index sum
void MinIdxSum(){
    int arr[15], trg;
    cin >> trg;
    for(int i = 0; i < 12; i++)
        cin >> arr[i];
    int MinSumIdx = 1e2, idx = 0, idx1 = 0, PairCnt = 0;
    for(int i = 0; i < 11; i++){
        for(int j = i + 1; j < 12; j++){
            if(arr[i] + arr[j] > trg){
                PairCnt++;
                if((i + j) < MinSumIdx)
                    MinSumIdx = i + j;
                    idx = i; idx1 = j;
            }
        }
    }
    (PairCnt == 0)?cout << "NULL": cout << idx + 1 << " " << idx1 + 1;
}
void Find3rdSmallest(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < 5; i++){
        int minIdx= i;
        for(int j = i + 1; j < 5; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[minIdx], arr[i]);
    }
    cout << arr[2];
}
