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
