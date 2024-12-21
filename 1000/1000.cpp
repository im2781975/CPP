// calculate and display the number of letters in the English word represent of a given number between 1 and 999
int d1[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4}; // 1-9
int d2[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8}; // 10-19
int d3[10] = {0, 3, 6, 6, 6, 5, 5, 7, 6, 6}; // 20 - 90
int d4[10] = {0, 10, 10, 12, 11, 11, 10, 12, 12, 11}; // 100 - 900
int letter_count(int n) {
    if (n == 0) 
        return 0;
    if (n <= 9)
        return d1[n];
    if (n >= 10 && n <= 19)
        return d2[n % 10];
    if (n >= 20 && n <= 99)
        return d1[n % 10] + d3[n / 10]; // Tens and units
    if (n % 100 == 0)
        return d4[n / 100]; // Exact hundreds
    if (n % 100 >= 10 && n % 100 <= 19)
        return d4[n / 100] + 3 + d2[n % 10]; // Hundreds and teen numbers
    
    if (n > 100 && n % 100 <= 9)
        return d4[n / 100] + 3 + d1[n % 10]; // Hundreds and single digit
    if (n % 100 > 19 && n % 100 <= 99)
        return d4[n / 100] + 3 + d3[(n % 100) / 10] + d1[n % 10]; // Hundreds, tens, and units
    return 0; // For any unhandled case (though there shouldn't be any)
}
__main() {
    int number;
    cout << "Enter a number between 1 and 999: ";
    cin >> number;
    if (number < 1 || number > 999)
        cout << "Number out of range. Please enter a number between 1 and 999." << "\n";
     else{
        int count = letter_count(number);
        cout << "The number of letters in the word representation of " << number << " is: " << count << "\n";
    }
}

// calculate and display 2^exponent (2 raised to the power of the given exponent)
//and to find the sum of the digits of the resulting number. 
int multiply(int digits[], int num_digits) {
    int carry = 0;
    for (int i = 0; i < num_digits; i++) {
        int product = digits[i] * 2 + carry;
        digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        digits[num_digits] = carry % 10;
        carry /= 10;
        num_digits++;
    }
    return num_digits;
}
void power2(int exponent) {
    int digits[500], num_digits = 1, digit_sum = 0;
    digits[0] = 1;
    for (int i = 1; i <= exponent; i++) {
        num_digits = multiply(digits, num_digits);
    }
    for (int i = num_digits - 1; i >= 0; i--) {
        cout << digits[i];
        digit_sum += digits[i];
    }
    cout << endl << digit_sum << endl;
}
__main() {
    int exponent;
    cout << "Enter the power: ";
    cin >> exponent;
    power2(exponent);
    return 0;
}
//0/1 knapsack
const int N = 1010;
int w, n;
int weight[N], item[N];
int dp[N][N];
void Knapsack(){
    cin >> w >> n;
    for(int i = 1; i <= n; i++)
        cin >> weight[i] << item[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= weight[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i] + item[i]]);
        }
    }
    cout << dp[n][w];
}

//Print & sum the prime number
const int N = 1e7;
bool mark[N];
int prime[N/10], cnt = 0;
void printPrime(){
    mark[0] = mark[1] = false;
    for(int i = 2; i < N; i++)
        mark[i] = true;
    //fill(mark, mark + N, true)
    for(int i = 2; i < N; i++){
        if(mark[i] == true){
            prime[++cnt] = i;
            for(int j = i*2; j < N; j+= i)
                mark[j] = false;
        }
    }
    int sum = 0;
    for(int i = 0; i < 25; i++){
        cout << prime[i] << " ";
        sum += prime[i];
    }
    cout << "\nSum of the prime is: " << sum;
}
void ExecuteString(){
    int n; cin >> n;
    string word;
    for(int i = 0; i < n; i++){
        cin >> word;
        if(word.size() > 10)
            cout << word[0] << " " << word.size() - 2 << " " << word[word.size() - 1];
        else
             cout << word;
    }
}

//find and print the 1-based index of the unique element in
void uniqueIdx(){
    int k; cin >> k;
    int tmp = k;
    int res[k];
    for(int t = 0; t < k; t++){
        int n; cin >> n;
        int cnt = 0;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int uniqueIdx = -1;
        if(arr[0] != arr[1]){
            if(arr[1] == arr[2])
                uniqueIdx = 1;
                //First element is unique
            else
                uniqueIdx = 0;
                //second element is unique
        }
        else {
            for(int i = 0; i < n - 1; i++){
                if(arr[i]!= arr[i + 1]){
                    uniqueIdx = i + 1;
                    break;
                }
            }
        }
        res[t] = uniqueIdx + 1;
        //1 based idx
    }
    for(int i = 0; i < tmp; i++)
        cout << res[i] << " ";
}

//find the first occurrence where adjacent elements are different
void SpyDetect(){
    int k; cin >> k;
    int tmp = k;
    int result[k];
        while(k--){
        int n; cin >> n;
        int arr[n], cnt = -1;
            for(int i = 0; i < n; i++)
                cin >> arr[i];
        for(int i = 0; i < n - 1; i++){
            if(arr[i]!= arr[i + 1]){
                cnt = (i == 0 || i == 1) ? i : i + 1;
                break;
            }
        }
        result[k--] = cnt;
    }
    for(int i = 0; i < tmp; i++)
        cout << result[i] << " ";
}
// determine the minimum number of steps required to make two integers equal. 
void CountStep(){
    int n; cin >> n;
    vector <int> result(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        int step = 0;
        if(a > b){
            int diff = a - b;
            (diff % 2 == 0)?step = 1: step = 2;
        }
        else if(a < b){
            int diff = b - a;
            (diff % 2 == 0)?step = 2: step = 1;
        }
        else
            step = 0;
        result[i] = step;
    }
    for(int i = 0; i < n; i++)
        cout << result[i] << " ";
}
//Sum consecutive integer Diffrence
void SumDiff(){
    int arr[3];
    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < 3; i++)
        arr[i] = abs(arr[i]);
    int x = abs(arr[1] - arr[0]);
    int y = abs(arr[2] - arr[1]);
    cout << x + y;
}
// find the smallest number greater than or equal to a given integer n 
// that consists of distinct digits in the range of 1000 to 9000
bool IsDistinct(int num){
    int w = num % 10; num /= 10;
    int x = num % 10; num /= 10;
    int y = num % 10; num /= 10;
    int z = num % 10;
    return (w != x && w != y && w != z && x != y && x != z && y != z);
}
__main(){
    int n; cin >> n;
    for(int i = n; i <= 9000; i++){
        if(IsDistinct(i)){
            cout << i;
            break;
        }
    }
}
// determine if all the levels from 1 to n are covered by the unique elements present in two given arrays. 
int RemoveDup(int *arr, int n){
    if(n == 0 || n == 1)
        return n;
    int tmp[n], j = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] != arr[i + 1])
            tmp[j++] = arr[i];
    }
    tmp[j++] = arr[n - 1];
    for(int i = 0; i < n; i++)
        arr[i] = tmp[i];
    return j;
}
__main(){
    int n; cin >> n;
    int a, b; cin >> a;
    int arr[a];
    for(int i = 0; i < a; i++)
        cin >> arr[i];
    a = RemoveDup(arr, a);
    cin >> b; int tmp[b];
    for(int i = 0; i < b; i++)
        cin >> tmp[i];
    b = RemoveDup(tmp, b);
    /*
    bool level[n + 1];
    for(int i = 0; i < a; i++)
        level[arr[i]] = true;
    for(int i = 0; i < b; i++)
        level[tmp[i]] = true;
    for(int i = 1; i <= n; i++){
        if(level[i] == false)
            return 0;
    }
    cout << "Here i am";
    */
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
    (cnt == 0)?cout << "Become the Guy" : cout << "No one";
}


void CheckDiagonal(){
    int n; cin >> n;
    vector <vector <char> >matrix(n, vector <char> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    char diagonal = matrix[0][0];
    for(int i = 0; i < n; i++){
        if(matrix[i][i]!= diagonal || matrix[i][n - i -1] != diagonal){
            cout << "No";
            return 0;
        }
    }
    char NotDiagonal = matrix[0][1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && i + j != n - 1){
                if(matrix[i][j] != NotDiagonal){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}
// fill a matrix with alternating 'B' and 'W' characters, starting from the given positions marked with a dot ('.'). 
void FillChar(){
    int n, m; cin >> n >> m;
    vector <string> matrix(n);
    for(int i = 0; i < n; i++){
        getline(cin, matrix[i]);
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == '.'){
                if((i + j) % 2 == 0)
                    matrix[i][j] = 'B';
                else
                    matrix[i][j] = 'W';
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
//an array representing the number of additional sockets available from various devices. 
//Each device can contribute a certain number of additional sockets.
//determine how many of these devices you need to use to ensure that you have enough sockets to accommodate a given number of devices.
void mergeSort(int *arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = right - mid;
    int leftarr[n1], rightarr[n2];
    for(int i = 0; i < n1; i++)
        leftarr[i] = arr[l + i];
    for(int i = 0; i < n2; i++)
        rightarr[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = mid;
    while(i < n1 && j < n2){
        if(leftarr[i] <= rightarr[j]){
            arr[k] = leftarr[i];
            i++;
        }
        else{
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = leftarr[i];
        i++; k++;
    }
    while(j < n2){
        arr[k] = rightarr[j];
        j++; k++;
    }
}
void merge(int *arr, int l, int r, int n){
    if(l < r){
        int mid = (left + right)/2;
        merge(arr, l, mid);
        merge(arr, mid + 1, r);
        mergeSort(arr, l, mid, r);
    }
}
__main(){
    int supply, device, socket;
    //supply :The number of devices (or array elements) available.
     // devices: The total number of devices you need to accommodate.
      // sockets: The initial number of available sockets.
    cin >> supply >> device >> socket;
    int arr[supply];
    //each integer arr[i] represents the number of additional sockets that the i-th device can contribute.
    for(int i = 0; i < supply ; i++)
        cin >> arr[i];
    merge(arr, 0, supply - 1, supply);
    if(device <= socket)
        cout << "0";
    else {
        int i = 0;
        while(socket < device && i < supply){
            socket += arr[i] - 1;
            i++;
        }
        if(i != supply)
            cout << i;
        else if(device <= socket)
            cout << i;
        else
            cout << -1;
    }
}
//Count Consecutive Duplicate & count the number of distinct contiguous segments in an array of integers
void CountDup(){
    int n; cin >> n;
    int arr[n], cnt = 0, cont = 0
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1])
            cnt++;
        if(arr[i]!= arr[i + 1])
            cont++;
    }
    cout << "Consecutive Duplicate: " << cnt << "\nUnique element is: " << cont + 1;
}
//count the number of times the x value from one input pair matches the
//y value from another input pair, excluding when they are at the same index. 
void MatchPair(){
    int n; cin >> n;
    int arr[n], tmp[n], cnt = 0;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr[i] = x; tmp[i] = y;
    }
    for(int i = 0, j = 0; i < n, j < n; i++, j++){
        if(arr[i] == tmp[j] && i != j)
            cnt++;
    }
    cout << cnt;
}
// Find the maximum sub array length
void SubarrLength(){
    int n; cin >> n;
    int arr[n], cnt = 1, maxLength = 1;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int diff = abs(arr[1] - arr[0]);
    for(int i = 1; i < n - 1; i++){
        int tmp = abs(arr[i + 1] - arr[i]);
        if(diff == tmp){
            cnt++;
            if(cnt > maxLength)
                maxLength = cnt;
        }
        else{
            diff = tmp; cnt = 1;
        }
    }
    cout << "Length Of the SubArray with Consistent diff is: " << maxLength;
}
//determine how dynamic the array is in terms of new highs and lows as you traverse it 
//from start to end. By counting the number of times the max and min values change,
//the program gives an insight into how the values fluctuate.
void cntMinMax(){
    int n; cin >> n;
    int arr[n], cntMin = 0, cntMax = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int maxi = arr[0], mini = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            cntMax++;
        }
        if(arr[i] < mini){
            mini = arr[i];
            cntMin++;
        }
    }
    cout << cntMax + cntMin;
}
// calculate the sum of the first two integers in each triplet, store these sums
//in an array, and then find and print the largest sum decreased by 1.
void MaxSum(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        c = a + b;
        arr[i] = c;
    }
    int maxi = arr[0];
    for(int i = 1; i < n; i++){
        if(maxi < arr[i])
            maxi = arr[i];
    }
    cout << maxi - 1;
}
void MaxSum(){
    int n; cin >> n;
    int a[n], b[n], c[n], sum = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i] >>b[i];
    for(int i = 0; i < n; i++){
        sum -= (a[i] + b[i]);
        c[i] = sum;
    }
    int maxi = c[0];
    for(int i = 1; i < n; i++){
        if(maxi < c[i])
            maxi = c[i];
    }
    cout << maxi;
}
//find the maximum gap between adjacent elements in an array after removing
//one element in a way that minimizes the maximum gap between the remaining adjacent elements. 
void MaxGap(){
    int n; cin >> n;
    int *arr = new int[n];
    int mini = INT_MAX, pos = -1;
    for(int i = 2; i < n; i++){
        if(arr[i] - arr[i - 2] < mini){
            mini = arr[i] - arr[i - 2];
            pos = i - 1;
        }
    }
    mini = -(1 << 28)
    for(int i = 0; i < n - 1; i++){
        if(i + 1 == pos){
            if(arr[i + 2] - arr[i] > mini){
                mini = arr[i + 2] - arr[i];
                i++;
            }
            else{
                if(arr[i + 1] - arr[i] > mini)
                    mini = arr[i + 1] - arr[i];
            }
        }
    }
    delete []arr;
    cout << mini;
}
//calculate the total exercise done for each muscle group over the n days 
//and determine which muscle group has the maximum exercise.
void Exercise(){
    int n; cin >> n;
    int *execise = new int[n];
    for(int i = 0; i < n; i++)
        cin >> exercise[i];
    int chest = 0, biceps = 0, back = 0;
    switch(i % 3){
        case 0:
            chest += exercise[i]; break;
        case 1:
            biceps += exercise[i]; break;
        case 2:
            back += exercise[i]; break;
    }
    if(chest > biceps && chest > back)
        cout << "chest: " << chest;
    else if(back > biceps && back > chest)
        cout << "back: " << back;
    else
        cout << "biceps: " << biceps;
}
//count and print the number of positive integers
void Count(){
    int n, k; cin >> n >> k;
    int arr[n + 1];
    if(k < n)
        return 1;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > 0 && (i <= k || arr[i] >= arr[k]))
            cnt++;
    }
    cout << cnt;
}
// implements the Number Theoretic Transform (NTT) algorithm, 
//which is a variant of the Fast Fourier Transform (FFT) used in modular arithmetic.
typedef long long ll;
const int MAX_SIZE = 1 << 18; 
// Maximum size (adjust based on the problem constraints)
const ll MOD = 998244353; 
// Example prime modulus (should be a prime of the form 2^k * p + 1)
// Function to perform modular exponentiation
ll bit_reversal[MAX_SIZE], poly_a[MAX_SIZE], poly_b[MAX_SIZE], poly_c[MAX_SIZE];
ll mod_exp(ll base, ll exp) {
    ll result = 1;
    while (exp) {
        if (exp & 1) result = result * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}
// Bit-reversal permutation
void compute_bit_reversal(int size) {
    int bit_count = 0;
    while ((1 << bit_count) < size) ++bit_count;
    for (int i = 0; i < size; ++i) {
        bit_reversal[i] = 0;
        for (int j = 0; j < bit_count; ++j) {
            if (i & (1 << j)) bit_reversal[i] |= (1 << (bit_count - j - 1));
        }
    }
}
void ntt(ll *poly, ll size, ll direction) {
    ll i, j, k, block_size, half_block_size, root, root_power, temp;
    // Perform bit-reversal permutation
    for (i = 0; i < size; ++i) {
        if (bit_reversal[i] < i) swap(poly[i], poly[bit_reversal[i]]);
    }
    // Perform the NTT or inverse NTT
    for (block_size = 2; block_size <= size; block_size <<= 1) {
        half_block_size = block_size >> 1;
        root = mod_exp(3, (MOD - 1) / block_size);
        for (i = 0; i < size; i += block_size) {
            root_power = 1;
            for (j = 0; j < half_block_size; ++j, root_power = root_power * root % MOD) {
                temp = root_power * poly[i + j + half_block_size] % MOD;
                poly[i + j + half_block_size] = (poly[i + j] - temp + MOD) % MOD;
                poly[i + j] = (poly[i + j] + temp) % MOD;
            }
        }
    }
    // If performing inverse NTT, reverse and scale
    if (direction == -1) {
        reverse(poly + 1, poly + size);
        ll inv_size = mod_exp(size, MOD - 2);
        for (i = 0; i < size; ++i) poly[i] = poly[i] * inv_size % MOD;
    }
}
__main() {
    // Define the polynomial degree (must be a power of 2)
    int degree = 1 << 10; 
    int size = degree;
    // Initialize bit-reversal permutation
    compute_bit_reversal(size);
    // Initialize polynomials with example values
    for (int i = 0; i < size; ++i){
        poly_a[i] = i + 1;
        poly_b[i] = i + 1;
    }
    // Perform forward NTT on poly_a
    ntt(poly_a, size, 1);
    cout << "Forward NTT of poly_a:" << endl;
    for (int i = 0; i < size; ++i)
        cout << poly_a[i] << " ";
    cout << endl;
    // Perform forward NTT on poly_b
    ntt(poly_b, size, 1);
    cout << "Forward NTT of poly_b:" << endl;
    for (int i = 0; i < size; ++i)
        cout << poly_b[i] << " ";
    cout << endl;

    // Perform inverse NTT on poly_a
    ntt(poly_a, size, -1);
    cout << "Inverse NTT of poly_a (should be the original):" << endl;
    for (int i = 0; i < size; ++i)
        cout << poly_a[i] << " ";
    cout << endl;
    // Perform inverse NTT on poly_b
    ntt(poly_b, size, -1);
    cout << "Inverse NTT of poly_b (should be the original):" << endl;
    for (int i = 0; i < size; ++i)
        cout << poly_b[i] << " ";
    cout << endl;
    return 0;
}

// Perform Fast Fourier Transform or Inverse Fast Fourier Transform
using Complex = complex<double>;
const double PI = 3.14159265358979323846;
// Perform bit-reversal permutation
void change(std::vector<Complex>& y, int len) {
    int i = 1, j = len / 2, k;
    while (i < len - 1) {
        if (i < j) std::swap(y[i], y[j]);
        k = len / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        if (j < k) j += k;
        i++;
    }
}
void FFTransform(vector<Complex>& y, int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w *= wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < len; i++)
            y[i] /= len;
    }
}
// Print complex number in a formatted manner
void printComplex(const Complex& c){
    cout << fixed << setprecision(3);
    cout << "(" << c.real() << ", " << c.imag() << "i)";
}
__main(){
    int n = 8;
    vector<Complex> data = {
        Complex(1, 0), Complex(1, 0), Complex(1, 0), Complex(1, 0),
        Complex(0, 0), Complex(0, 0), Complex(0, 0), Complex(0, 0)
    };
    // Perform forward FFT
    FFTransform(data, n, 1);
    cout << "FFT result:\n";
    for (const auto& c : data) {
        printComplex(c);
        cout << "\n";
    }
    // Perform inverse FFT
    FFTransform(data, n, -1);
    cout << "\nInverse FFT result:\n";
    for (const auto& c : data) {
        printComplex(c);
        cout << "\n";
    }
}

//implements a sieve algorithm to generate prime numbers and 
// calculate the Euler's Totient function (φ) for each number up to N
const int N = 1e7;
bool IsPrime[N];
    int prime[N/10], phi[N], arr[N], cnt = 0;
void EulerTotient(){
    fill(IsPrime, IsPrime + N, true);
    IsPrime[0] = IsPrime[1] = false;
    phi[1] = 1;
    for(int i = 2; i < N; i++){
        if(IsPrime[i]){
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < cnt && i * prime[j] < N; j++){
            int composite = i * prime[j];
            arr[composite] = prime[j];
            IsPrime[composite] = false;
            if(i % prime[j] == 0){
                phi[composite] = phi[i] * prime[j];
                break;
            }
            else   
                phi[composite] = phi[i] * (prime[j] - 1);
            
        }
    }
    for(int i = 0; i < 20; i++){
        cout << phi[i] << " ";
    }
}
