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
const int MAX_SIZE = 100;
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int counter = 0, groupSize = 0, column = 0;
    for (int i = size - 1; i >= 0; i--, counter = 0, column++)
    {
        while (counter < pow(3, size))
        {
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 1;
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 2;
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 3;
        }
    }
}

main()
{
    int x, y;
    cin >> x >> y;

    int matrix[MAX_SIZE][MAX_SIZE];
    fillMatrix(matrix, y);

    int n = 0;
    while (cin >> n)
    {
        int dimension = pow(3, n);
        int **dynamicMatrix = new int *[dimension];
        for (int row = 0; row < dimension; ++row)
        {
            dynamicMatrix[row] = new int[n];
            fillMatrix(dynamicMatrix, n);
            for (int r = 0; r < pow(3, n); r++)
            {
                for (int c = 0; c < n; c++)
                    cout << dynamicMatrix[r][c];
                cout << "\n";
            }
        }
        for (int q = 0; q < dimension; ++q)
            delete[] dynamicMatrix[q];
        delete[] dynamicMatrix;
        cout << endl;
    }
    return 0;
}
// Function to calculate 3^m using integer arithmetic
int pow3(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 3;
    }
    return result;
}

// Function to fill the array according to the pattern
void fillArray(int **array, int size) {
    int rowIndex = 0, groupIndex = 0, segmentIndex = 0;
    int totalRows = pow3(size);
    for (int colIndex = size - 1; colIndex >= 0; colIndex--, rowIndex = 0, segmentIndex++) {
        while (rowIndex < totalRows) {
            for (groupIndex = 0; groupIndex < pow3(segmentIndex); groupIndex++) array[rowIndex++][colIndex] = 1;
            for (groupIndex = 0; groupIndex < pow3(segmentIndex); groupIndex++) array[rowIndex++][colIndex] = 2;
            for (groupIndex = 0; groupIndex < pow3(segmentIndex); groupIndex++) array[rowIndex++][colIndex] = 3;
        }
    }
}

int main() {
    int size = 0;
    while (cin >> size) {
        if (size <= 0) {
            cout << "Please enter a positive integer.\n";
            continue;
        }

        int totalRows = pow3(size);
        // Allocate memory for the 2D array
        int **array = new int*[totalRows];
        for (int i = 0; i < totalRows; ++i)
            array[i] = new int[size];
        
        // Fill the array with the pattern
        fillArray(array, size);
        
        // Print the array
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < size; j++)
                cout << array[i][j];
            cout << "\n";
        }
        
        // Deallocate memory
        for (int i = 0; i < totalRows; ++i)
            delete[] array[i];
        delete[] array;
        
        cout << endl;
    }
    return 0;
}


//calculates the sum of the integers a for which the corresponding string r starts with the character ch and prints this sum.
struct X{
    char r[100], int a;
}
main(){
    int n; cin >> n;
    struct X arr[100];
    //reads a character & integer from the array
    for(int i = 0; i < n; i++)
        cin >> arr[i].r >> arr[i].a;
    char ch; cin >> ch;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].r[0] == ch)
            cnt += arr[i].a;
    }
    cout << cnt;
}

#include<iostream>
using namespace std;
//manipulate the values of x and y through a series of recursive calls.
int cnt = 0, odd = 0;
int request(int x, int y){
    if(y == 1)
        return x;
    if(x + y + 1 == y)
        return (pow(2, cnt - 1) + odd);
    if(x + odd == y)
        return pow(2, cnt);
    if(x == y)
        return pow(pow(2, cnt) + odd);
    if(x <= y && odd > y)
         return (pow(2, cnt) + odd / y + (odd % y));
    if(x <= y && odd > y)
        return (pow(2, cnt) + 1);
    if(x % 2 == 0){
        x /= 2;
        cnt++;
    }
    else {
        x = (x + 1)/2;
        cnt++; odd++;
    }
    return request(x, y);
}
main(){
    int x, y;
    cin >> x >> y;
    cout << request(x, y);
}
