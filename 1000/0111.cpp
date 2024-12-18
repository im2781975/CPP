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

// Bubble Sort
void sorte(int **arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1- i; j++){
            if(arr[j][0] > arr[j + 1][0]){
                //First Element
                swap(arr[j][0], arr[j + 1][0]);
                //second Element
                swap(arr[j][1], arr[j + 1][1]);
            }
        }
    }
}
__main(){
    int data[4][2] = {{3, 2}, {1, 4}, {4, 1}, {2, 3}};
    int *ptr[4];
    for(int i = 0; i < 4; i++)
        ptr[i] = data[i];
    sorte(ptr, 4);
    for(int i = 0; i < 4; i++)
        cout << ptr[i][0] << " " << ptr[i][1] << "\n";
}

void QuickSort(int *arr, int left, int right){
    int mid, tmp;
    int l = left, r = right;
    mid = arr[l + (l + r)/2];
    do{
        while(arr[l] < mid) l++;
        while(arr[r] > mid) r--;
        if(l <= r){
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++; r--;
        }
    }while(l <= r);
    if(left < r)
        QuickSort(arr, left, r);
    if(l < right)
        QuickSort(arr, l, right);
}

//find the maximum sum of a specific sequence from a 2D array
const int N = 5;
void FindSum(){
    int arr[N][N], maxi = INT_MIN, cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            arr[i][j] = i + j;
    }
    for(int i = 0; i <= 1; i++){
        for(int j = i; j <= 2; j++){
            if(j > i + 1)
                j = 3;
            for(int k = j; k <= 3; k++){
                if(k > j + 1)
                    k = 4;
                for(int l = k; l <= 4; l++){
                    if(l > k + 1)
                        l = 5;
                    int sum = arr[0][0] + arr[1][i] + arr[2][j] + arr[3][k] + arr[4][l] ;
                    if(sum > maxi)
                        maxi = sum;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << " " << maxi << "\n";
}

//count how many numbers within a given range [a,b] (inclusive) do not contain the digit '4' and do not have the digit '2' immediately followed by the digit '6'. 
const int MAX = 1e5;
void CountRange(){
    int arr[MAX];
    arr[0] = 1;
    for(int i = 1; i <= MAX; i++){
        int tmp = i;
        bool Forbidden = false;
        while(tmp){
            if(tmp % 10 == 4){
                Forbidden = true;
                break;
            }
            if(tmp % 10 == 2 && (tmp /10) % 10 == 6){
                Forbidden = true;
                break;
            }
            tmp /= 10;
        }
        if(Forbidden == true)
            arr[i] = arr[i - 1];
        else
            arr[i] = arr[i - 1] + 1;
    }
    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0)
            break;
        if(a > b)
            swap(a, b);
        cout << arr[b] - arr[a - 1];
    }
}

bool ContainDup(int *arr, int n){
    int tmp = arr[0];
    for(int i = 0; i < n; i++){
        if(tmp != arr[i])
            return false;
    }
    return true;
}
bool ContainZero(int *arr, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] !=0)
            return false;
    }
    return true;
}
bool IsSorted(int *arr, int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
            swap(arr[i], arr[i + 1]);
        }
    }
    return true;
}

//counting how many times an element in the guest array matches an element in the host array
void CountMatch(){
    int n; cin >> n;
    int cnt = 0;
    int host[n], guest[n];
    for(int i = 0; i < n; i++){
        int tmp = guest[i];
        for(int j = 0; j < n; j++){
            if(tmp == host[i])
                cnt++;
        }
    }
    cout << cnt;
}
void Transform(){
    int n; cin >> n;
    int ans[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int a = (x + 1)/2;
        ans[i] = a - 1;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

void SubArraySum(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int i = 1, j = n - 1, k = 5;
    while(k > 0 && i < n - 1 && j >= 0){
        if(arr[i] + arr[i - 1] < arr[j]){
            i += 2; k--;
        }
        else if(arr[i] + arr[i - 1] > arr[j]){
            j--; k--;
        }
        else if(arr[i] + arr[i - 1] == arr[j] && k >= 2){
            i += 2; j--; k -= 2;
        }
        else{
            j--; k--;
        }
    }
    i = max(0, i - 1);
    int sum = 0;
    for(int idx = i; idx <= j; idx++)
        sum += arr[idx];
    cout << sum;
}

//counts how many times the subsequent elements are greater than or equal to the 
//current element, adjusts the count based on certain conditions, and
//then prints n - cnt for each outer loop iteration.
void SubSequent(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] >= arr[i]){
                cnt++;
                if(j == n - 1)
                    cnt--;
            }
            else{
                i = j - 1;
                if(cnt > 0)
                    cnt--;
                break;
            }
        }
    }
    cout << n - cnt;
}

// determine how many participants in a competition will advance to the next round based on their scores.
void NextRound(){
    int n, k; cin >> n >> k;
    int arr[n + 10];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int tmp = arr[k - 1], cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= tmp && arr[i] > 0)
            cnt++;
    }
    cout << cnt;
}

//display Pascal's Triangle up to n rows. Pascal's Triangle is a triangular array of binomial coefficients
void PescalTriangle(){
    int n, arr[33][33];
    arr[1][1] = 1;
    arr[2][1] = arr[2][2] = 1;
    for(int i = 3; i <= 30; i++){
        for(int j = 1; j <= i; j++)
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1]
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << arr[i][1];
        for(int j = 2; j <= n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

// demonstrate how to append an integer to an array, sort the array, and print it in sorted order.
void Operation(){
    int n, m; cin >> n >> m;
    int arr[n + 10];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = m;
    sort(arr, arr + n + 1);
    cout << arr[0] << " ";
    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

//finds the element with the largest absolute value in the array and outputs its 1-based position along with its value.
void FindLargest(){
    int row, col;
    cin >> row >> col;
    if(row == 0 && col == 0)
        return 0;
    int arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
    int ans = arr[0][0];
    int x = 0, y = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(abs(arr[i][j]) > abs(ans)){
                 ans = arr[i][j];
                 x = i + 1; y = j + 1;
            }
        }
    }
    cout << x << " " << y << " " << ans;
}

//print Minimum value
void Minvalue(){
    int n; cin >> n;
    int arr[n + 10];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int minIdx = 0, mini = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < mini){
            mini = arr[i];
            minIdx = i;
        }
    }
    if(minIdx != 0)
        swap(arr[0], arr[minIdx]);
    cout << arr[0] << "\n";
    for(int i = 1; i < n; i++)
        cout << arr[i] << " ";
}

const int N = 20100;
// find the minimal unused capacity of a knapsack of size m given n items of various sizes. 
void RemainCap(){
    // capacity of the knapsack (m) and the number of items (n) are read.Each item size x
    int m, n, arr[N];
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        for(int j = m; j >= x; j--){
            arr[j] = max(arr[j - x] + x, arr[j]);
        }
    }
    cout << m - arr[m];
}

void DivisibleByTen(){
    int n; cin >> n;
    int *arr = new int[n];
    int k = 0, r = 0;
    //k -> Count of numbers divisible by 10
    //r-> Count of digits in numbers not divisible by 10
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 10 == 0)
            arr[k++] = x;
        else {
            tmp = x;
            while(tmp != 0){
                r++;
                tmp /= 10;
            }
        }
    }
    cout << "Numbers Divisible by 10: ";
    for(int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << "\nNumber Divisible not by 10 is: " << r;
}
//calculates the minimum cost of traveling a given number of units, 
//given the cost of single tickets and special tickets. The special tickets cover 
//multiple units at a potentially reduced cost
void CountTravelCost(){
//n ->Total units of travel required. m -> Number of units covered by the special ticket.
//a is the Cost of a single ticket. and b is the Cost of the special ticket.
    int n, m, a, b;
    cout << n << m << a << b;
    int price = 0;
    // Cost of 'm' single tickets
    int CostSingleTicket = a * m;
    if(CostSingleTicket <= b)
        price = a * n;
    else {
        int SpecialTickets = n/m
        int RemainingUnit = n % m;

        int x = (SpecialTickets + 1) * b;
        int y = SpecialTickets * b + RemainingUnit * a;
        price = min(x, y);
    }
    cout << price;
}
//check if there is at least one item where the price does not match the quality. 
void checkQuality(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int price, quality;
        cin >> price >> quality;
        if(price != quality)
            cout << "Happy";
        return 0;
    }
    cout << "Poor";
    return 0;
}
//Compressed Letter
struct CompressedLetter{
    int num;
    char letter;
};
vector <CompressedLetter> Process(const string &str){
    vector <CompressedLetter> res;
    int pos = 0;
    while(pos < str.length()){
        int len = 0;
        while(str[pos]>= '0' && str[pos] <= '9'){
            len = len * 10 + (str[pos] - '0');
            pos++;
        }
        if(len == 0)
            len = 1;
        if(pos < str.length()){
            res.push_back({len, str[pos]});
            pos++;
        }
    return res;
}
//Sum Between Ranges
int SumRanges(int l, int r){
    if(r < l)
        return 0;
    if(l > 1)
        return SumRanges(1, r) - SumRanges(1, l - 1);
    if(r % 2 == 1)
        return SumRanges(1, r - 1) + r;
    else
        return r * (r + 1)/2;
}

//compute specific values related to the movement or relationship between two points on a 2D grid
void GridMove(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int IsDiffrent = (a != c && b != d) ? 2 : 1;
    int SameParity = ((a + b) % 2 == (c + d) % 2) ? 1 : 0;
    int DiffrentDirection = (a - b == c - d || a + b == c + d) ? 1 : 0;
    int res = IsDiffrent * (2 - DiffrentDirection);
    int maxDist = max(abs(c - a), abs(d - b));
    cout << res << " " << SameParity * res << " " << maxDist ;
}
//determine how many times each die wins, and how many times there is a draw, 
// when compared to a series of possible dice outcomes (from 1 to 6).
void CompareDice(){
    int dice1, dice2; cin >> dice1 >> dice2;
    int dice1Win = 0, dice2Win = 0, draw = 0;
    for(int i = 1; i <= 6; i++){
        if(abs(dice1 - i) > abs(dice2 - i))
            dice2Win++;
        else if(abs(dice1 - i) < abs(dice2 - i))
            dice1Win++;
        else
            draw++;
    }
    cout << dice1Win << " " << draw << " " << dice2Win;
}
void verify(){
    int n, k; cin >> n >> k;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if(k >= y){
            if(x > maxi)
                maxi = x;
        }
        else {
            if((x - (y - k)) > maxi)
                maxi = x - (y - k);
        }
    }
    cout << maxi;
}
//output the position of the unique number (either odd or even) in a sequence of integers. 
void FindUnique(){
    int n, x;
    cin >> n;
    int even = 0, odd = 0, pos1 = -1, pos2 = -1;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x % 2 == 0){
            even++; pos1 = i + 1;
        }
        else {
            odd++; pos2 = i + 2;
        }
    }
    (odd == 1) ? cout << pos2 :cout << cout << pos1;
}
void SnakePattern(){
    int row, col; cin >> row >> col;
    for(int i = 0; i < row; i++){
        if(i % 2 == 0){
            for(int j = 0; j < col; j++)
                cout << "#";
        }
        else {
            if((i / 2) % 2 == 0){
                for(int j = 0; j < col - 1; j++)
                    cout << ".";
                cout << "#";
            }
            else {
                cout << "#";
                for(int j = 1; j < col; j++)
                    cout << ".";
            }
        }
        cout << "\n";
    }
}
