//Simulate two scheduling algorithms for process management in operating systems
//: First-Come, First-Served (FCFS) and Shortest Job First (SJF) non-preemptive.
void Simulate() {
    int num;
    // Represent the num of programs
    cin >> num;
    if (num <= 0) {
        cout << "Should be Greater than zero" << endl;
        return 1;
    }
    float *arrTime = new float[num];
    float *executeTime = new float[num];
    int i = 0;
    while (i < num) {
        cout << "\nArrival & Exit of programme " << i + 1 << " is: ";
        cin >> arrTime[i];
        cin >> executeTime[i];
        //execute time represent the finishing time while the code finished
        i++;
    }
    // FCFS -> First Come First Served
    // SJF -> Shortest Job First (non-preemptive)
    cout << "Enter 1 for FCFS or 2 for SJF-non preemptive: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        float curTime = 0, turnTime = 0, waitTime = 0;
        float totalTurnTime = 0, totalWaitTime = 0;
        //curTime ->when the code finished for execution
        //arrTime ->when the code start for execution
        // TurnTime is the total time taken from arrival to completion.
        // WaitTime (T(w)) is the total time a program spends waiting in the ready queue.
        for (i = 0; i < num; i++) {
            if (curTime < arrTime[i]) {
                curTime = arrTime[i]; // Process starts at the arrival time if the CPU is idle
            }
            curTime += executeTime[i];
            turnTime = curTime - arrTime[i];
            waitTime = turnTime - executeTime[i];
            cout << "The Turnaround time (T(a)) of program " << i + 1 << " = " << turnTime << endl;
            cout << "The Waiting time (T(w)) of program " << i + 1 << " = " << waitTime << endl;
            totalTurnTime += turnTime;
            totalWaitTime += waitTime;
        }
        cout << "Average Turnaround time (T(a)) = " << totalTurnTime / num << endl;
        cout << "Average Waiting time (T(w)) = " << totalWaitTime / num << endl;
    } else if (choice == 2) {
        int curTime = 0;
        // store the time at which each process finishes execution. The index of the array corresponds to the process number.
        float *completionTime = new float[num];
        //array of booleans to keep track of whether each process has been processed or not.initially declared false
        bool *processed = new bool[num]();
        for (int i = 0; i < num; ++i) {
            int minIdx = -1;
            for (int j = 0; j < num; ++j) {
                if (!processed[j] && arrTime[j] <= curTime && 
                   (minIdx == -1 || executeTime[j] < executeTime[minIdx])) {
                    minIdx = j;
                }
            }
            if (minIdx != -1) {
                processed[minIdx] = true;
                curTime += executeTime[minIdx];
                completionTime[minIdx] = curTime;
            } else {
                // If no process is ready to execute, advance the current time to the next arrival time
                curTime++;
                i--; // Retry current iteration as no process was executed
            }
        }
        float totalTurnTime = 0, totalWaitTime = 0;
        for (int i = 0; i < num; ++i) {
            float turnTime = completionTime[i] - arrTime[i];
            float waitTime = turnTime - executeTime[i];
            cout << "The Turnaround time (T(a)) of program " << i + 1 << " = " << turnTime << endl;
            cout << "The Waiting time (T(w)) of program " << i + 1 << " = " << waitTime << endl;
            totalTurnTime += turnTime;
            totalWaitTime += waitTime;
        }
        cout << "Average Turnaround time (T(a)) = " << totalTurnTime / num << endl;
        cout << "Average Waiting time (T(w)) = " << totalWaitTime / num << endl;
        delete[] completionTime;
        delete[] processed;
    } else
        cout << "Invalid Choice";
    delete[] arrTime;
    delete[] executeTime;
    return 0;
}

//mix of round-robin and shortest remaining time first (SRTF) principles. 
void RoundRobin(){
    int num; cin >> num;
    float *arrTime = new float[num];
    float *ExecutionTime = new float[num];
    float *RemainExecution = new float[num];
    //used to keep track of how much execution time is left for each process 
    //at any given moment in the simulation. Initially, this will be set equal to the 
    //execution times, and it will be decremented as the processes execute.
    float *CompletionTime = new float[num];
    //used to store the completion times of each process.initially will be set -1
    bool *ready = new bool[num];
    //creates a boolean array to track whether each process is ready to execute
    for(int i = 0; i < num; i++){
        cin >> arrTime[i];
        cin >> ExecutionTime[i];
        RemainExecution[i] = ExecutionTime[i];
        ready[i] = false;
        //Completion times are initialized to -1, indicating that no process has completed yet.
        CompletionTime[i] = -1;
    }
    //time quantum is the maximum amount of time a process can run before the scheduler moves on to the next process in the queue.
    int Quantum; cin >> Quantum;
    float TotalExecuteTime = 0;
    for(int i = 0; i < num; i++){
        TotalExecuteTime += ExecutionTime[i];
    }
    int CurTime = 0;
    while(CurTime < TotalExecuteTime){
        for(int i = 0; i < num; i++){
            if(arrTime[i] <= CurTime && CompletionTime[i] == -1)
                ready[i] = true;
        }
        int minIdx = -1;
        for(int i = 0; i < num; i++){
            if(ready[i] == true &&(minIdx == -1 || RemainExecution[i] < RemainExecution[minIdx]))
                minIdx = i;
        }
        if(minIdx == -1){
            CurTime++;
            continue;
        }
        if(RemainExecution[minIdx] > Quantum){
            RemainExecution[minIdx] -= Quantum;
            CurTime+= Quantum;
        }
        else {
            CurTime += RemainExecution[minIdx];
            RemainExecution[minIdx] = 0;
            CompletionTime[minIdx] = CurTime;
            ready[minIdx] = false;
        }
    }
    for(int i = 0; i < num; i++){
        float TurnTime = (CompletionTime[i] - arrTime[i]);
        float WaitTime = TurnTime - ExecutionTime[i];
        cout << "T(a) of p" << i + 1 << " = " << TurnTime << endl;
        cout << "T(w) of p" << i + 1 << " = " << WaitTime << endl;
    }
    delete []arrTime;
    delete []ExecutionTime;
    delete []RemainExecution;
    delete []CompletionTime;
    delete []ready;
}

using namespace std;
void BankesAlgo() {
    int numProcesses;
    cin >> numProcesses;
    vector<vector<int>> allocation(numProcesses, vector<int>(3));
    vector<vector<int>> maximum(numProcesses, vector<int>(3));
    vector<int> available(3);

    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter the allocation of P" << i + 1 << " separated by spaces: ";
        for (int j = 0; j < 3; j++) {
            cin >> allocation[i][j];
        }
    }
    // Input maximum matrix
    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter the maximum of P" << i + 1 << " separated by spaces: ";
        for (int j = 0; j < 3; j++) {
            cin >> maximum[i][j];
        }
    }
    // Input available resources
    cout << "Enter the available resources separated by spaces: ";
    for (int j = 0; j < 3; j++) {
        cin >> available[j];
    }

    // Calculate the need matrix
    vector<vector<int>> need(numProcesses, vector<int>(3));
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < 3; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    vector<bool> finished(numProcesses, false);
    vector<int> safeSequence;

    // Loop to check the safe sequence
    for (int k = 0; k < numProcesses; k++) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                bool canAllocate = true;
                for (int j = 0; j < 3; j++) {
                    if (need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // Allocate resources to this process
                    for (int j = 0; j < 3; j++) {
                        available[j] += allocation[i][j];
                    }
                    safeSequence.push_back(i);
                    finished[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "The system is not in a safe state\n";
            return 0;
        }
    }
    // Print the safe sequence
    cout << "The system is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < safeSequence.size(); i++) {
        cout << "P" << safeSequence[i] + 1;
        if (i != safeSequence.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}
int Factorial(int n){
    if(n == 0 || n == 1)
        return 1;
    return n * Factorial(n - 1);
}
main(){
    int n; cin >> n;
    cout << Factorial(n);
}

void CountDigit(){
    int n; cin >> n;
    int cnt = 0;
    while(n !='\0'){
        n /= 10; cnt++;
    }
    cout << cnt;
}

void Lucky(){
    int x; cin >> x;
    int arr[]{4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
    bool flag = false;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n && arr[i] <= x; i++){
        if(x % arr[i] == 0){
            flag = true;
            break;
        }
    }
    (flag)?cout << "Yes":cout << "No";
}

void Reverse(){
    int n; cin >> n;
    int rev = 0;
    while(n!='\0'){
        rev = rev * 10 + (n% 10);
        n/= 10;
    }
    cout << rev;
}

//Count 1's in Binary
int Binary(int x) {
    int cnt = 0;
    while(x > 0){
        if(x % 2 == 1)
            cnt++;
        x /= 2;
    }
    return cnt;
}
int hex(int n){
    int x = 0, cnt = 0;
    while(n > 0){
        x += (n % 10) * pow(16 ,  cnt++);
        n /= 10;
    }
    return Binary(x);
}
main(){
    int n; cin >> n;
    cout << "Total 1s is: " << hex(n);
}

//determine maximum, minimum & subarray sum
void SubArraySum(){
    int n; cin >> n;
    int arr[n + 2];
    int i = 1;
    while(i++ < n)
        cin >> arr[i -1];
    int query; cin >> query;
    while(query--){
        int x, y, sum = 0;
        cin >> x >> y;
        if(x > y)
            swap(x, y);
        int first = x - 1;
        int last = y - 1;
        int maxi = first, mini = first;
        for(int i = first; i <= last; i++) {
            sum += arr[i];
            if(arr[i] > arr[maxi])
                maxi = i;
            if(arr[i] < arr[mini])
                mini = i;
        }
        cout << arr[maxi] <<  " " << arr[mini] << " " << sum;
    }
}

// Convert Binary To Decimal
void BinaryToDeciaml(){
    int n, sum = 0, i = 0;
    cin >> n;
    while(n > 0) {
        sum += (n % 10) * pow(2, i++);
        n /= 10;
    }
    cout << sum;
}

//transform a given string into a palindrome with the minimum number of
//character changes & then output the number of changes
void Transform(){
    int n; cin >> n;
    char *arr = new char[n + 1];
    cin >> arr;
    int i = 0, cnt = 0, last = n -1;
    while(i++ < n /2){
        if(arr[i] != arr[last]){
            cnt++;
            if(arr[i] < arr[last])
                arr[last] = arr[i];
            else
                arr[i] = arr[last];
        }
        i++; last--;
    }
    cout << cnt <<  " " << arr;
    delete []arr;
}

//Subtract n among a & b.in which player n will be zero,He will 
//be win.If neg another player will be win
void Distribute(){
    int a, b, n;
    cin >> a >> b >> n;
    while(true) {
        if(n  >= __gcd(a, n))
            n -= __gcd(a, n);
        else {
            cout << "Second Player wins";
            break;
        }
        if(n == 0) {
            cout << "First Player wins";
            break;
        }
        if(n >= __gcd(b, n))
            n -= __gcd(b, n);
        else {
            cout << "First Player win";
            break;
        }
        if(n == 0) {
            cout << "Second Player Wins";
            break;
        }
    }
    return 0;
}

// Determine x can be written as the sum of two even numbers.
//If such a pair is found,print 'Yes' else 'No'.
void IsEven(){
    int x; cin >> x;
    for(int i = 2; i < x; i+= 2){
        if((x - i) % 2 == 0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}

//Seperate into Even & Odd, and sort them.
void Seperate(){
    int n, x, Ec = -1, Oc = -1;
    cin >> n;
    int *Even = new int[n];
    int *Odd = new int[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 2 == 0)
            Even[++Ec] = x;
        else 
            Odd[++Oc] = x;
    }
    if(Oc > -1){
        for(int i = Oc; i >= 0; i--){
            cout << Odd[i];
            if(i > 0)
                cout << " ";
        }
    }
    if(Oc > -1 && Ec > -1)
        cout << " ";
    if(Ec > -1){
        for(int i = 0; i <= Ec; i++){
            cout << Even[i];
            if(i < Ec)
                cout << " ";
        }
    }
    delete []Odd;
    delete []Even;
}

//prints the Manhattan distance from the position of 1 to the center of the matrix (5 * 5 matrix)(which is at coordinates (2, 2)), and then exits.
void CountDst(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int x; cin >> x;
            if(x == 1){
                cout << abs(i - 2) + abs(j -2);
                return 0;
            }
        }
    }
}
void Manhatten(){
    int arr[5][5];
    int row = -1, col = -1;
    for(int i = 0, j = 0, i < 5, j < 5; i++, j++){
        cin >> arr[i][j];
        if(arr[i][j] = 1){
            row = i; col = j;
        }
    }
    int Distance = abs(row - 2) + abs(col - 2);
    cout << Distance;
}

//determine how many iterations it takes for the length to become greater than the breadth
//if, in each iteration, the length is tripled and the breadth is doubled
void MakeEqual(){
    int length, breadth, cnt = 0;
    cin >> length >> breadth;
    while(true){
        if(length > breadth)
            break;
        else {
            lenth *= 3;
            breadth *= 2;
            cnt++;
        }
    }
    cout << cnt;
}
//calculates the total width required for n people to pass through a checkpoint 
//based on their heights. Each person either takes 1 unit or 2 units of width depending on 
//whether they are taller than a specified height limit. The final total width is then output.
void CalculateWidth(){
    int num, heightLimit, width = 0;
    cin >> num >> heightLimit;
    for(int i = 0; i < num; i++){
        int height; cin >> height;
        if(height > heightLimit)
            width += 2;
        else
            width += 1;
    }
    cout << width;
}
//calculate how many sub-blocks of size z * z can fit into a larger grid of size x * y, and to account for any additional blocks needed if there are leftover spaces along the edges of the grid.
void CalculateSubBlock(){
    int x, y, z;
    //x*y represent the grid & z*z represent the sub-block
    cin >> x >> y >> z;
    int a = x / z;
    int b = y / z;
    int cnt = a * b;
    if(x % z !=0)
        cnt += y;
    if(y % z !=0)
        cnt += x;
    if(x % z !=0 && y % z !=0)
        cnt+= 1;
    cout << cnt;
}
// determine if the total sums of three series of integers are all zero
void CheckSum(){
    int n, suma = 0, sumb = 0, sumc = 0; 
    cin >> n;
    for(int i =0; i < n; i++){
        int a, b, c; cin >> a >> b >>c;
        suma += a;
        sumb += b;
        sumc += c;
    }
    (suma == 0 && sumb == 0 && sumc == 0)?cout << "Yes":cout << "No";
}
//determine how many test cases satisfy a specific condition related to 
//counting occurrences of the integer 1 among three given numbers for each test case. 
void CountOnes(){
    int n, cnt = 0; cin >> n;
    for(int i = 0; i < n; i++){
        int OneCnt = 0;
        for(int j = 0; j < 3; j++){
            int x; cin >> x;
            if(x == 1)
                ++OneCnt;
        }
        if(OneCnt > 1)
            cnt++;
    }
    cout << cnt;
}

//Count '+' in the char arr.if found '-' cnt will be decreament
void CountPositive(){
    int n, cnt = 0; 
    cin >> n;
    char ch;
    for(int i = 0; i < n; i++){
        cin >> ch;
        if(ch== '+')
            cnt++; 
        if(ch == '-')
            cnt--;
    }
    cout << cnt;
    //*****//
    int n, cnt = 0;
    char arr[3];
    for(int i = 0; i < n; i++){
        cin >> arr;
        int Ind = 0;
        while(Ind < 2){
            if(arr[Ind] == '+'){
                cnt++; 
                break;
            }
            if(arr[Ind] == '-'){
                cnt--;
                break;
            }
            Ind++;
        }
    }
    cout << cnt;
    //****//
    int n, cnt = 0;
    string str;
    for(int i = 0; i < n; ++i){
        cin >> str;
        if(str.find('+') !=string::npos)
            cnt++;
        else if(str.find('-') != string::npos)
            cnt--;
    }
    cout << cnt;
}

//determine if the square of the value l is less than or equal to half the square of the value r.
void IsEqual(){
    int l, r;
    cin >> l >> r;
    int x = l * l;
    int y = 0.5 * r * r;
    (x <= y) ? cout << "Yes":cout << "No";
}

//calculates the max length of the Collatz sequence for a range of numbers
void collatzLength(int num){
    int length = 1;
    while(num > 1){
        if(num % 2 != 0)
            num = 3 *num + 1;
        else
            num /= 2;
        length++;
    }
    return length;
}
main(){
    int start, end, maxL = -1;
    cin >> start >> end;
    for(int i = start; i < end; i++){
        int length = collatzLength(i);
        if(length > maxL)
            maxL = length;
    }
    cout << maxL;
    //****//
    int x, y, maxi = 1, cnt = 0;
    cin >> x >> y;
    int tmp = x;
    while(tmp <= y){
        x = tmp;
        cnt = 1;
        while(x > 1){
            if(x % 2 !=0)
                x = 3 * x +1;
            else
                x /= 2;
            cnt++;
        }
        if(cnt > maxi)
            maxi = cnt;
    }
    cout << maxi;
}
