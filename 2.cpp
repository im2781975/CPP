using namespace std;
https://codeforces.com/problemset/problem/4/C
// 4C. Registration system
int main(){
    int t; cin >> t;
    map <string, int> mp;
    for(int i = 0; i < t; i++){
        string str; cin >> str;
        if(!mp[str]){
            cout << "OK" << endl;
            ++mp[str];
        }
        else{
            cout << str + to_string(mp[str]) << endl;
            ++mp[str];
        }
        /* if(mp[str] >= 1)
               cout << str << mp[str];
       else
            cout << "OK";
       mp[str]++; */
       /* if(mp[str] == 0)
            cout << "OK" << endl;
        else
            cout << str << mp[str] << endl;
        mp[str]++; */
    }
}
http://codeforces.com/contest/9/problem/A
// Die_Roll
using namespace std;
int main() {
    int y, w; cin >> y >> w;
    int z = max(y, w);
    int q = (6 - z) + 1;
    if(q == 1)    cout << "1/6";
    else if(q == 2)    cout << "1/3";
    else if(q == 3)    cout << "1/2";
    else if(q == 4)    cout << "2/3";
    else if(q == 5)    cout << "5/6";
    else if(q == 6)    cout << "1/1";
    else if(q == 0)    cout << "0/1";
}
using namespace std;
int main() {
    int y, w; cin >> y >> w;
    int maxVal = max(y, w);
    int favorable = 6 - maxVal + 1;
    string outcomes[] = {"0/1", "1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};
    cout << outcomes[favorable] << endl;
}

#include <iostream>
#include <string>
using namespace std;
http://codeforces.com/contest/16/problem/A
// A. Flag
int main() {
    int n, m; cin >> n >> m;
    string flag[n];
    for(int i = 0; i < n; ++i)
        cin >> flag[i];
    bool isValid = true;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < m; ++j){
            if(flag[i][j] != flag[i][0]){
                isValid = false;
                break;
            }
        }
        if(i > 0 && flag[i][0] == flag[i - 1][0]){
            isValid = false;
            break;
        }
    }
    cout << (isValid ? "YES" : "NO") << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/16/problem/B
// 16B - Burglar and Matches
// Comparator to sort boxes by matches per box in descending order
bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}
int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> boxes(m); 
    for (int i = 0; i < m; ++i)
        cin >> boxes[i].first >> boxes[i].second;
    sort(boxes.begin(), boxes.end(), comp);
    long long total_matches = 0;
    int remaining_capacity = n;
    for (int i = 0; i < m && remaining_capacity > 0; ++i) {
        int take = min(boxes[i].first, remaining_capacity);
        total_matches += 1LL * take * boxes[i].second;
        remaining_capacity -= take;
    }
    cout << total_matches << endl;
}
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}
int main() {
    unsigned long long sum = 0;
    int n, m; cin >> n >> m;
    pair<int, int> pa[m];
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        pa[i].first = x;
        pa[i].second = y;
    }
    sort(pa, pa + m, comp);
    int got = n;
    int len = m;
    for (int i = 0; i < len && got > 0; i++) {
        int first = pa[i].first;
        int second = pa[i].second;
        if (first <= got) {
            sum += (unsigned long long)first * second;
            got -= first;
        } else {
            sum += (unsigned long long)got * second;
            got = 0;
        }
    }
    cout << sum << endl;
}

using namespace std;
// A. IQ test
// problemset/problem/25/A
int main(){
    int n; cin >> n;
    int arr[n], even = 0, odd = 0;
    int evenIdx = -1, oddIdx = -1;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            even++;
            evenIdx = i + 1;
        }
        else{
            odd++;
            oddIdx = i + 1;
        }
    }
    (even == 1) ? cout << evenIdx : cout << oddIdx;
}
using namespace std;
http://codeforces.com/problemset/problem/25/A
// A. IQ test
int main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] = arr[i] % 2;
	}
	int one = count(arr, arr + n, 1);
	if (one > n - one) {
		for (int i = 0; i < n; i++) {
			if (!arr[i]) {
				cout << i + 1;
				break;
			}
		}
	} else{
		for (int i = 0; i < n; i++) {
			if (arr[i]) {
				cout << i + 1;
				break;
			}
		}
	}
	return 0;
}
using namespace std;
// problemset/problem/26/B
// B. Regular Bracket Sequence
int main(){
    string str; cin >> str;
    stack <char> st;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(ch == '(') st.push(ch);
        else if(ch == ')' && !st.empty() && st.top() == '('){
            st.pop();
            cnt++;
        }
        else
            st.push(ch);
    }
    cout << cnt * 2;
}
using namespace std;
http://codeforces.com/problemset/problem/32/B
// B. Borze
int main() {
    string s, result; cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '.')
            result += '0';
        else if (i + 1 < len && s[i] == '-' && s[i + 1] == '.') {
            result += '1';
            ++i;
        } 
        else if (i + 1 < len && s[i] == '-' && s[i + 1] == '-'){
            result += '2';
            ++i;
        }
    }
    cout << result;
}
using namespace std;
http://codeforces.com/contest/41/problem/A
// A. Translation
int main(){
    string str, ing; cin >> str >> ing;
    reverse(str.begin(), str.end());
    (str == ing) ? cout << "Yes" : cout << "No";
}
using namespace std;
https://codeforces.com/contest/43/problem/B
// 43B. Letter
int main(){
	string str, ing;
	getline(cin, str);
	getline(cin, ing);
	map <char, int> mp;
	int len = str.length();
	int len2 = ing.length();
	for(int i = 0; i < len; i++)
	    ++mp[str[i]];
	 int cnt = 0, res = 0;
	 for(int i = 0; i < len2; i++){
	     if(ing[i] != ' '){
	         ++res;
	         if(mp[ing[i]] > 0){
	             ++cnt;
	             --mp[ing[i]];
	         }
	     }
	 }
	 if(res == cnt) cout << "YES";
	 else cout << "NO";
}
using namespace std;
int main() {
    string magazine, letter;
    getline(cin, magazine);
    getline(cin, letter);

    map<char, int> charCount;

    // Count characters in the magazine string
    for (char c : magazine) {
        ++charCount[c];
    }

    // Check if we can form the letter
    for (char c : letter) {
        if (c == ' ') continue;

        if (charCount[c] > 0) {
            --charCount[c];
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/43/problem/A
// Football.cpp
int main() {
	int n; cin >> n;
	map <string, int> mp;
	map <string, int> ::iterator it;
	for(int i = 0; i < n; i++){
	    string str; cin >> str;
	    ++mp[str];
	}
	it = mp.begin();
	int len = mp.size();
	if(x != 1){
	    int val = (*it).second;
	    it++;
	    int val2 = (*it).second;
	    if(val2 > val) cout << (*it).first;
	}
	else if(val > val2){
	    it = mp.begin();
	    cout << (*it).first;
	}
	else cout << (*it).first;
}
using namespace std;
int main() {
    int n; cin >> n;
    map<string, int> teamGoals;
    string teamName;
    for (int i = 0; i < n; ++i) {
        cin >> teamName;
        teamGoals[teamName]++;
    }
    string winner;
    int maxGoals = 0;
    for (const auto& entry : teamGoals) {
        if (entry.second > maxGoals) {
            maxGoals = entry.second;
            winner = entry.first;
        }
    }
    cout << winner << endl;
}
using namespace std;
http://codeforces.com/contest/47/problem/B
// 47B. Coins;
int main() {
	string arr[3] = {};
	for(int i = 0; i < 3; i++)
	    cin >> arr[i];
	map <char, int> mp;
	mp['A'] = 0; mp['B'] = 0; mp['C'] = 0;
    for (int i = 0; i < 3; i++) {
        char a = arr[i][0];
        char b = arr[i][2];
        if (arr[i][1] == '>') {
            mp[a]++;
            mp[b]--;
        } else {
            mp[a]--;
            mp[b]++;
        }
    }
	if(mp['A'] > mp['B'] && mp['B'] > mp['C']) cout << "CBA";
    else if(mp['A'] > mp['C'] && mp['C'] > mp['B']) cout << "BCA";
	else if(mp['B'] > mp['C'] && mp['C'] > mp['A']) cout << "ACB";
    else if(mp['B'] > mp['A'] && mp['A'] > mp['C']) cout << "CAB";
	else if(mp['C'] > mp['B'] && mp['B'] > mp['A']) cout << "ABC";
    else if(mp['C'] > mp['A'] && mp['A'] > mp['B']) cout << "BAC";
	else cout << "IMPOSSIBLE";
}
using namespace std;
int main() {
    string arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    map<char, int> weight;
    weight['A'] = 0;
    weight['B'] = 0;
    weight['C'] = 0;
    for (int i = 0; i < 3; i++) {
        char a = arr[i][0];
        char b = arr[i][2];
        if (arr[i][1] == '>')
            weight[a]++;
        else
            weight[b]++;
    }
    vector<pair<int, char>> result;
    for (auto& p : weight)
        result.push_back({p.second, p.first});
    sort(result.begin(), result.end());
    if (result[0].first == result[1].first || result[1].first == result[2].first) {
        cout << "Impossible" << endl;
    } else {
        for (auto& p : result)
            cout << p.second;
        cout << endl;
    }
}

using namespace std;
// A. Domino piling
// problemset/problem/50/A
int main(){
    int m, n; cin >> m >> n;
    cout << (m * n) / 2;
}
http://codeforces.com/problemset/problem/58/A
// Chat_room.cpp
using namespace std;
bool valid(string s){
    string s2 = "hello";
    for(int i = 0; i < 5; i++){
        char trg = s2[i];
        int val = s.find(trg);
        if(val != -1)    s.erase(0, val + 1);
        else    return false;
    }
    return true;
}
int main(){
    string s; cin >> s;
    cout << (valid(s)) ? "YES" : "NO";
}
using namespace std;
bool isHelloSubsequence(const string& s) {
    string target = "hello";
    int j = 0;
    for (char ch : s) {
        if (ch == target[j])    j++;
        if (j == target.size())    break;
    }
    return j == target.size();
}
int main() {
    string input; cin >> input;
    cout << (isHelloSubsequence(input)) ? "YES" : "NO";
}
using namespace std;
http://codeforces.com/contest/59/problem/A
// A. Word
string toupp(string s){
	int len = s.length();
	for(int i = 0; i < len; i++)
		s[i] = toupper(s[i]);
	return s;
}
string tolow(string s){
	int len = s.length();
	for(int i = 0; i < len; i++)
		s[i] = tolower(s[i]);
	return s;
}
int main(){
	string s; cin >> s;
	int len = s.length();
	int upper = 0, lower = 0;
	for(int i = 0; i < len; i++){
	    if(isupper(s[i])) upper++;
	    else lower++;
	}
	if(upper > lower) s = toupp(s);
	else if(upper < lower) s = tolow(s);
	else s = tolow(s);
    cout << s;
}
using namespace std;
http://codeforces.com/problemset/problem/61/A
// Ultra-Fast Mathematician
int main() {
    string s1, s2, result = "";
    cin >> s1 >> s2;
    for (size_t i = 0; i < s1.length(); i++) {
        result += (s1[i] == s2[i]) ? '0' : '1';
    }
    cout << result << endl;
}
using namespace std;
int main(){
    string s, s1, s2;
    cin >> s >> s1;
    int len = s.length();
    for(int i = 0; i < len; i++){
	    if(s[i] != s1[i]) s2 += '1';
	    else s2 += '0';
	
    }
    cout << s2;
}
using namespace std;
http://codeforces.com/contest/66/problem/B
// 66B - Petya and Countryside
int arr[1005];
int solve(int n, int index) {
    int left = 0, right = 0;
    int refLeft = arr[index], refRight = arr[index];
    // Expand to the right
    for (int i = index; i < n; i++) {
        if (arr[i] > refRight) break;
        ++right;
        refRight = min(refRight, arr[i]);
    }
    // Expand to the left
    for (int i = index - 1; i >= 0; i--) {
        if (arr[i] > refLeft) break;
        ++left;
        refLeft = min(refLeft, arr[i]);
    }
    return left + right;
}
int main() {
    int n, maxLen = 0; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, solve(n, i));
    }
    cout << maxLen << endl;
    return 0;
}
using namespace std;
int arr[1005];
int solve(int n, int index){
	int right = 0, left = 0;
	int rigthreference = arr[index];
	int leftreference = arr[index];
	for(int i = index; i < n; i++){
		if(arr[i]>rigthreference)
			break;
		else {
			++right;
			if(arr[i] < rigthreference)
				rigthreference = arr[i];
		}
	}
	for(int i = index - 1; i >= 0; i--){
		if(arr[i] > leftreference)
			break;
		else {
			++left;
			if(arr[i]<leftreference)
				leftreference=arr[i];
		}
	}
	return right + left;
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
	    cin >> arr[i];
    int resultvalue = 0, resultindex = 0;
    for(int i = 0; i < n; i++){
	    int value = solve(n, i);
	    if(value > resultvalue){
		    resultindex = i;
		    resultvalue = value;
	    }
    }
    cout << resultvalue << endl;
}
using namespace std;
http://codeforces.com/contest/69/problem/A
// 69A - Young Physicist
int main() {
    int n; cin >> n;
    int x = 0, y = 0, z = 0;
    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        x += a; y += b; z += c;
    }
    if (x == 0 && y == 0 && z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
using namespace std;
http://codeforces.com/problemset/problem/69/A
// A. Young Physicist
int main() {
    int n; cin >> n;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        int xi, yi, zi; cin >> xi >> yi >> zi;
        x += xi; y += yi; z += zi;
    }
    if (x == 0 && y == 0 && z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
using namespace std;
// A. Way Too Long Words
// problemset/problem/71/A
int main() {
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string ch; getline(cin, ch);
        int l = ch.length();
        if (l > 10)
            cout << ch[0] << l - 2 << ch[l - 1] << endl;
        else
            cout << ch << endl;
    }
}
using namespace std;
http://codeforces.com/problemset/problem/71/A
//A. Way_Too_Long_Words
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int x = s.length();
		if(x <= 10) cout << s << endl;
		else
		    cout << s[0] << x - 2 << s[x-1] << endl;
	}
}
using namespace std;
char word[101];
int len = 0;
void result(){
    cout << word[0] << len - 2 << word[len - 1] << '\n';
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        len = strlen(thwword);
        if(len > 10) result();
        else cout << word << '\n';
    }
}
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		string s, s2; cin >> s;
		int len = s.length();
		if(len > 10)
			 cout << s[0] << len - 2 << s[len - 1] << '\n';
		else cout << s << '\n';
	}
}
https://codeforces.com/contest/75/problem/A
// A. Life Without Zeros
using namespace std;
int removezero(int a){
	string s = to_string(a);
	string s2;
	int n = s.length();
	for(int i = 0; i < n; i++){
	    if(s[i] != '0')    s2 += s[i];
	}
	return stoll(s2);
}
int main() {
	int a, b; cin >> a >> b;
	int result1 = a + b;
	int newa = removezero(a);
	int newb = removezero(b);
	int result2 = removezero(result1);
	if((newa + newb) == result2)    cout << "Yes";
	else    cout << "No";
}
using namespace std;
long long removeZeros(long long num) {
    string s = to_string(num), res;
    for (char c : s) {
        if (c != '0') res += c;
    }
    return stoll(res);
}
int main() {
    long long a, b; cin >> a >> b;
    long long sum = a + b;
    long long aNoZero = removeZeros(a);
    long long bNoZero = removeZeros(b);
    long long sumNoZero = removeZeros(sum);
    if (aNoZero + bNoZero == sumNoZero)    cout << "YES\n";
    else    cout << "NO\n";
}
using namespace std;
http://codeforces.com/problemset/problem/80/A
// 80A - Panoramix's Prediction
const int N = 55;
bool primecheck[N];
void seive(){
    primecheck[0] = 1; primecheck[1] = 1;
    for(int i = 2; i <= N; i++){
        if(primecheck[i])    continue;
        for(int j = i * i; j <= N; j += i)    primecheck[j] = 1;
    }
}
int nextprime(int n){
    int num = 0;
    for(int i = n + 1; i < N; i++){
        if(!primecheck[i]){
            num = i;
            break;
        }
    }
    return num;
}
int main(){
    sieve();
    int n, m; cin >> n >> m;
    int x = nextprime(n);
    if(x == m)    cout << "Yes";
    else    cout << "No";
}
using namespace std;
const int N = 55;
bool isNotPrime[N];
void sieve() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i * i < N; ++i) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j < N; j += i)
                isNotPrime[j] = true;
        }
    }
}
// Find the next prime greater than n
int nextPrime(int n) {
    for (int i = n + 1; i < N; ++i) {
        if(!isNotPrime[i])    return i;
    }
    return -1;
}
int main(){
    sieve();
    int n, m; cin >> n >> m;
    int next = nextPrime(n);
    if (next == m)    cout << "YES\n";
    else    cout << "NO\n";
}
http://codeforces.com/problemset/problem/96/A
// A. Football
using namespace std;
int main() {
    string s; cin >> s;
	int len = s.length();
	bool flag = 0;
	for(int i = 0; i < len; i++){
        int ones = count(s.begin() + i, s.begin() + i + 7, '1');
		int zeros = count(s.begin() + i, s.begin() + i + 7, '0');
		if(ones >= 7 || zeros >= 7)    flag = 1;
	}
	cout << (flag ? "Yes" : "NO");
	return 0;
}
using namespace std;
int main() {
    string s; cin >> s;
    int count = 1;
    bool danger = false;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            count++;
            if (count >= 7) {
                danger = true;
                break;
            }
        }
        else    count = 1;
    }
    cout << (danger ? "YES" : "NO") << endl;
}

using namespace std;
// contest/102/problem/B
// B. Sum of Digits
int main(){
    string str; cin >> str;
    int step = 0;
    while(str.length() > 1){
        int sum = 0;
        for(int i = 0; i < str.size(); i++)
            sum += str[i] - '0';
        str = to_string(sum);
        ++step;
    }
    cout << step;
}
using namespace std;
// A. Nearly Lucky Number
// problemset/problem/110/A
int main(){
    string str; cin >> str;
    int x = count(str.begin(), str.end(), '4');
    int y = count(str.begin(), str.end(), '7')
    ((x + y) == 4) ? cout << "YES" : cout << "NO";
}
using namespace std;
// A. Petya and Strings
// problemset/problem/112/A
int main(){
    string str, ing;
    getline(cin, str);
    getline(cin, ing);/*
    transform(str.begin(), str.end(), str.begin(), ::tolower)
    transform(ing.begin(), ing.end(), ing.begin(), ::tolower)
    if(str < ing) cout << -1;
    else if(str > ing) cout << 1;
    else cout << 0; */
    int len = strlen(str) - 1;
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') 
            str[i] += 32;
        if(ing[i] >= 'A' && ing[i] <= 'Z')
            ing[i] += 32;
    }
    for(int i = 0; i < len; i++){
        if(str[i] < ing[i]){
            cout << -1; return 0;
        }
        if(str[i] > ing[i]){
            cout << 1; return 0;
        }
    }
    cout << 0;
}
//https://codeforces.com/problemset/problem/112/A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >>a >>b;
    int n=min(a.size(), b.size());
    for(int i = 0; i <n; i++)
    {
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
    }
    if(a > b)
        cout << 1 ;
    else if(a < b)
        cout << -1 ;
    else
        cout << 0;
}
#include<bits/stdc++.h>
using namespace std;
string MakeLower(string s)
{
    for(int i =0; i< s.size(); i++)
    {
        if(s[i] >='A' && s[i] <='Z')
        {
            s[i]+='a'-'A';
        }
    }
    return s;
}
int main()
{
    string a, b;
    cin >>a >>b;
    a = MakeLower(a);
    b = MakeLower(b);
    int n =a.size() | b.size();
    for(int i =0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i] >b[i])
                return cout<< 1, 0;
            return cout<< -1, 0;
        }
    }
    cout<< 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 92)
            a[i] += 32;
        if (b[i] < 92)
            b[i] += 32;
    }
    if (a < b)
        cout << -1;
    else if (a > b)
        cout << 1;
    else
        cout << 0;
        
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    int n = a.compare(b);

    if (n < 0)
        cout << -1;
    else if (n > 0)
        cout << 1;
    else
        cout << 0;

    return 0;
}
http://codeforces.com/problemset/problem/112/A
// Petya_and_Strings.cpp
using namespace std;
int main() {
	string first, second; cin >> first >> second;
	for(int i = 0; i < first.length(); i++){
	    first[i] = tolower(first[i]);
	    second[i] = tolower(second[i]);
	}
	if(first == second)    cout << "0";
	else if(first > second)    cout << "1";
	else    cout << "-1";
}
using namespace std;
int main() {
    string first, second; cin >> first >> second;
    // Convert both strings to lowercase
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);
    if (first == second)    cout << 0;
    else if (first > second)    cout << 1;
    else    cout << -1;
}
http://codeforces.com/problemset/problem/112/A
// A. Petya and Strings
using namespace std;
int main() {
	string first, second; cin >> first >> second;
	for(int i = 0; i < first.length(); i++){
	    first[i] = tolower(first[i]);
	    second[i] = tolower(second[i]);
	}
	int x = first.length();
	int n = second.compare(0, x, first, 0, x);
	if(n == 0)    cout << 0;
	else if(n < 0)    cout << -1;
	else    cout << 1;
	return 0;
}
using namespace std;
string touppr(string s){
	int len = s.length();
	for(int i = 0; i < len; i++)
	    s[i] = toupper(s[i]);
	return s;
}
int main(){
    string s,s2; cin >> s >> s2;
	s = touppr(s);
	s2 = touppr(s2);
	if(s < s2)    cout << -1;
	else if(s > s2)    cout << 1;
	else    cout << 0;
}

using namespace std;
// problemset/problem/116/A
// A. Tram
int main(){
    int n; cin >> n;
    int cap = 0, remain = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        remain -= a;
        remain += b;
        cap = max(cap, remain);
    }
    cout << cap;
}
using namespace std;
// A. String Task
// problemset/problem/118/A
int main(){
    string str; cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'y') {
            cout << '.' << str[i]; 
        }
    }
    /**/
    string res;
    string vowel = "aeiouyAEIOUY";
    for(int i = 0; i < str.size(); i++){
        if (vowel.find(str[i]) == string::npos){ 
            res.append(".").append(1, tolower(str[i]));  
        }
    }
    cout << res;
}
using namespace std;
http://codeforces.com/problemset/problem/118/A
// String_Task.cpp
int main() {
    string input, result = "";
    cin >> input;
    for (char c : input) {
        c = tolower(c);
        if (c != 'a' && c != 'o' && c != 'y' && c != 'e' && c != 'u' && c != 'i') {
            result += '.';
            result += c;
        }
    }
    cout << result << endl;
}
using namespace std;
int main() {
	string x, result = "";
	cin >> x;
	int len = x.length();
	for(int i = 0; i < len; i++)
	    x[i] = tolower(x[i]);
	for(int i = 0; i < len; i++){
        if(x[i] != 'a' && x[i] != 'o' && x[i] != 'y' && x[i] !='e' &&  x[i] !='u' && x[i]!= 'i'){
            result += ".";
            result += x[i];
        }
	}
	cout << result;
	return 0;
}
using namespace std;
// problemset/problem/122/A
// A. Lucky Division
int main(){
    int n; cin >> n;
    bool flag = 0;
    int arr[12] = {4, 7, 47, 74, 44, 444, 447, 474, 477, 777, 774, 744};
    for(int i = 0; i < 12; i++){
        if(n % arr[i] == 0)
            flag = 1;
    }
    (flag) ? cout << "YES" : cout << "NO";
}
using namespace std;
http://codeforces.com/problemset/problem/131/A
// 131A - cAPS lOCK
int main() {
    string s; cin >> s;
    int len = s.length();
    if (len == 1) {
        s[0] = isupper(s[0]) ? tolower(s[0]) : toupper(s[0]);
    } 
    else {
        bool restUpper = true;
        for (int i = 1; i < len; ++i) {
            if (!isupper(s[i])) {
                restUpper = false;
                break;
            }
        }
        if (restUpper) {
            for (int i = 0; i < len; ++i) {
                s[i] = isupper(s[i]) ? tolower(s[i]) : toupper(s[i]);
            }
        }
    }
    cout << s << endl;
    return 0;
}
using namespace std;
int main(){
	string s; cin >> s;
	int len = s.length();
	int counter = 0;
	if(len == 1){
		if(isupper(s[0]))
			s[0] = tolower(s[0]);
		else if(islower(s[0]))
			s[0] = toupper(s[0]);
		cout << s;
	}
	else {
	    for(int i=1;i<len;i++){
		    if(isupper(s[i]))
			    counter++;
	    }
	    if(counter + 1 == len){
		    for(int i = 0; i < len; i++){
			    if(isupper(s[i]))
				    s[i] = tolower(s[i]);
			    else if(islower(s[i]))
				    s[i] = toupper(s[i]);
		    }
	    }
	    cout<<s;
	}
}
http://codeforces.com/problemset/problem/133/A
// A.HQ9+
using namespace std;
int main() {
    string s; cin >> s;
    if (s.find_first_of("HQ9") != string::npos)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    /*
    int i = s.find_first_of("HQ9");
    cout << (i != -1) ? "YES" : "NO"; */
}

using namespace std;
http://codeforces.com/contest/136/problem/A
// A. Presents
int main() {
	 string s1,s2; cin >> s1 >> s2;
	 if(s1 == s2) cout << "-1";
	 else
		cout << max(s1.length(),s2.length());q
}
http://codeforces.com/contest/339/problem/A
// A.HelpfulMaths
using namespace std;
int main() {
    string s, s2; cin >> s;
    int len = s.length();
	for(int i = 0; i < len; i++){
	    if(s[i] != '+')    s2 += s[i];
	}
	sort(s2.begin(), s2.end());
	len = s2.length();
	if(len > 1){
	    cout << s2[0];
	    for(int i = 1; i < len - 1; i++)    cout << '+' << s2[i];
	    cout << '+' << s2[len - 1];
	}
	else    cout << s;
}
using namespace std;
int main() {
    string s; cin >> s;
    string digits;
    for (char c : s) {
        if (c != '+')    digits += c;
    }
    sort(digits.begin(), digits.end());
    for (size_t i = 0; i < digits.size(); ++i) {
        if (i > 0) cout << '+';
        cout << digits[i];
    }
}
using namespace std;
int main(){
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++)
        sort(s.begin(), s.end());
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] != '+')    cout << s[i] << "+";
    }
    cout << s[s.size()-1];
}
using namespace std;
int main(){
    string s; cin >> s;
    int n = (s.size() + 1) / 2;
    int arr[n], x = 0, y = 0, min = 0;
    while(s.size() > x){
        arr[y++] = s[x];    x += 2;
    }
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min])    min = j;
        }
        swap(arr[min], arr[i]);
    }
    x = 0, y = 0;
    while(x < s.size()){
        s[x] = arr[y++];
        x += 2;
    }
    cout << s;
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >>s;
    int ones =0, twos =0, threes =0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1')
            ones++;
        if(s[i] == '2')
            twos++;
        if(s[i] == '3')
            threes++;
    }
    if(ones!=0)
    {
        cout <<1;
        for(int i=0; i<ones-1; i++)
            cout<< '+' << 1;
        for(int i=0; i<twos; i++)
            cout<< '+' <<2;
        for(int i=0; i<threes; i++)
            cout <<'+' <<3;
            
        return 0;
    }
    if(twos!=0)
    {
        cout <<2;
        for(int i=0; i<twos-1; i++)
            cout<<'+' <<2;
        for(int i=0; i<threes; i++)
            cout<<'+' <<3;
        return 0;
    }
    if(threes!=0)
    {
        cout <<3;
        for(int i=0; i<threes-1; i++)
                cout<<'+'<<3;
        return 0;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >>s;
    vector <int> ans;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
            ans.push_back(s[i]-'0');
    }
    sort(ans.begin(), ans.end());
    cout <<ans[0];
    for(int i=1; i<ans.size(); i++)
    {
        cout<<"+" <<ans[i];
    }
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >>s;
    vector<int>ans;
    for(int i=0; i<s.size(); i+=2)
    {
        int x=s[i] -'0';
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        cout<< ans[i];
        if(i!=ans.size()-1)
            cout<< "+";
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >>s;
    int n=s.length();
    for(int i=0; i< n-1; i++)
    {
        for(int j=0; j< n-i-1; j++)
        {
            if(s[j]!='+' && s[j] < s[j+2])
                    swap(s[j], s[j+2]);
        }
    }
    cout<< s;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    // Create a substring 'g' starting from the middle of the sorted string to the end.
    string g = s.substr(s.size() / 2, s.size());

    // Iterate through the characters in the substring 'g'.
    for(int i = 0; i < g[i]; i++)
    {
        // Print the current character.
        cout << g[i];
        if(i != g.size() - 1)
            cout << '+';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string s;
    cin >>s;
    sort(s.begin(), s.end());
    int n=s.size();
    for(i=(n-1)/2; i<n-1; i++)
        cout<< s[i] <<"+";
    cout<< s[i] <<" ";
}
using namespace std;
// http://codeforces.com/problemset/problem/141/A
// A. Amusing Joke
int main(){
    string st, ri, ng, res; cin >> st >> ri >> ng;
    string res += st + ri;
    sort(res.begin(), res.end());
    sort(ng.begin(), ng.end());
    if(res == ng) cout << "Yes";
    else cout << "No";
}
using namespace std;
// http://codeforces.com/problemset/problem/144/A
// A. Arrival of the General
int main(){
    int n; cin >> n;
    int maxval = 0, maxIdx = 0;
    int minval = 0, minIdx = 1000;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > maxval){
            maxIdx = i;
            maxval = x;
        }
        if(x <= minval){
            minIdx = i;
            minval = x;
        }
    }
    if(maxIdx > minIdx)
        cout << (maxIdx - 1) + (n - minIdx) - 1;
    else
        cout << (maxIdx - 1) + (n - minIdx);
}
using namespace std
http://codeforces.com/problemset/problem/148/A
// A. Insomnia cure
int main(){
    int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
    vector <bool> damaged(d, false);
    for(int i = 1; i <= d; i++){
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            damaged[i - 1] = true;
    }
    cout << count(damaged.begin(), damaged.end(), true);
}
using namespace std;
http://codeforces.com/problemset/problem/151/A
// A. Soft Drinking
int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int total_drink = (k * l) / nl; 
    int total_slices = c * d;      
    int total_salt = p / np;        
    int toasts = min({total_drink, total_slices, total_salt});
    cout << toasts / n << endl;
}
using namespace std;
http://codeforces.com/contest/155/problem/A
// A. I_love_%username%
int main(){
    int n; cin >> n;
    int cnt = 0;
    int mini; cin >> mini;
    int maxi = mini;
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        if(x > maxi){
            maxi = x; ++cnt;
        }
        else if(x < mini){
            mini = x; ++cnt;
        }
    }
    cout << cnt;
}
using namespace std;
// A. Next Round
// problemset/problem/158/A
int main(){
    int n, k; cin >> n >> k;
    int arr[n], res = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] >= arr[k] && arr[i] > 0)
            res++;
    }
    cout << res;
}
//  https://codeforces.com/contest/158/problem/A
#include <iostream>
#include <vector>
using namespace std;
 
void First()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((v[i] >= v[k-1]) && (k != 0 && v[i] != 0) ) {
            count += 1;
        } 
    }
    cout << count << endl;
}
void Second()
{
    int cnt = 0;
    int n, k;
    cin >> n >> k;
    
    int arr[n + 2];
    
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        int src = arr[k - 1];
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= src && arr[i] != 0)
                cnt++;
        }
        cout << cnt;
    }
}
void Third()
{
    const int MAXN = 1e2;
    int n, k, i = 0, j = 0, arr[MAXN];

    cin >> n >> k;

    while (n > i)
        cin >> arr[i++];

    while (arr[j] && arr[j] >= arr[k - 1])
        ++j;

    cout << j;
}
int main()
{
    First();
    Second();
    Third();
}
using namespace std;
http://codeforces.com/problemset/problem/158/B
// B. Taxi
int main() {
	int n; cin >> n;
	int taxicount = 0;
	int arr[5] = {0,0,0,0,0};
    for(int i = 0; i < n; i++){
	    int a; cin >> a;
		++arr[a];
	}
	taxicount += arr[4];
	arr[4] = 0;
	if(arr[2]){
	    int t = arr[2] >> 1;
		taxicount += t;
		arr[2] -= t*2;
	}
	if(arr[1] && arr[3]){
		 int mnivalue = min(arr[1], arr[3]);
		 taxicount += mnivalue;
		 arr[1] -= mnivalue;
		 arr[3] -= mnivalue;
	}
	if(arr[1] && arr[2]){
		if(arr[2] <= arr[1] >>1 &&barr[1] >> 1){
			taxicount += arr[2];
			arr[1] -= arr[2]*2;
			arr[2] -= arr[2];
		}
		else{
			int z = min(arr[1], arr[2]);
			taxicount += z;
			arr[1] -= z;
			arr[2]-=z;
		}
	}
	int y = arr[1]/4;
	taxicount += y;
	arr[1] -= y*4;
	if(arr[1] < 4 && arr[1]){
		 taxicount += 1;
		 arr[1] = 0;
	}
	for(int i = 1; i < 5; i++)
        taxicount += arr[i];
	cout << taxicount;
}
using namespace std;
int main() {
    int n; cin >> n;
    int count[5] = {0};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        count[x]++;
    }
    int taxis = 0;
    // Groups of 4 need a taxi each
    taxis += count[4];
    // Pair 3s with 1s
    int pair_3_1 = min(count[3], count[1]);
    taxis += pair_3_1;
    count[3] -= pair_3_1;
    count[1] -= pair_3_1;
    // Remaining 3s each need a taxi
    taxis += count[3];
    // Pair 2s together
    taxis += count[2] / 2;
    count[2] %= 2;
    if (count[2]) {
        // One group of 2 left
        taxis += 1;
        // Try to pair with up to two 1s
        count[1] = max(0, count[1] - 2);
    }
    // Remaining 1s can fit 4 per taxi
    taxis += (count[1] + 3) / 4;
    cout << taxis << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/158/problem/A
// 158 A. Next Round
int main(){
    int n, k; cin >> n >> k;
    int arr[n], cnt = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ref = arr[k - 1];
    for(int i = 0; i < n; i++){
        if(arr[i] >= ref && arr[i])
            ++cnt;
    }
    cout << cnt;
}
http://codeforces.com/problemset/problem/158/A
// A.Next_Round
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int scores[51];
    for (int i = 0; i < n; i++)    cin >> scores[i];
    int threshold = scores[k - 1];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= threshold && scores[i] > 0)    count++;
    }
    cout << count << endl;
}
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int counter = 0, arr[51];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] >= arr[k - 1] && arr[i] != 0)    counter += 1;
    }
    cout << counter;
}
using namespace std;
http://codeforces.com/contest/160/problem/A
// A.Twins
int arr[105], ray[105];
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ray[0] = arr[0];
    for(int i = 1; i < n; i++)
        ray[i] = ray[i - 1] + arr[i];
    int res = 0;
    for(int i = n - 1; i >= 0; i--){
        int left = ray[i - 1];
		int right = ray[n - 1] - ray[i - 1];
 		if(right > left){
			cout << n - i;
			break;
 		}
    }
}
using namespace std;
https://codeforces.com/problemset/problem/160/A
// A.Twins
int main() {
    int n; cin >> n;
    int coins[n];
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total_sum += coins[i];
    }
    sort(coins, coins + n, greater<int>());
    int my_sum = 0;
    int coin_count = 0;
    int half = total_sum / 2;
    for (int i = 0; i < n; ++i) {
        my_sum += coins[i];
        coin_count++;
        if (my_sum > half)
            break;
    }
    cout << coin_count << endl;
    return 0;
}
using namespace std;
int main() {
	 int n; cin >> n;
	 int arr[n];
	 int sum = 0, counter = 0;
	 for(int i = 0; i < n; i++){
	     cin >> arr[i];
	     sum += arr[i];
	 }
	sum /= 2;
	sort(arr, arr + n);
	int sum2 = 0;
	for(int i = n - 1; i >= 0; i--){
	    sum2 += arr[i]; ++counter;
	    if(sum2 > sum) break;
	}
	cout << counter;
}
using namespace std;
http://codeforces.com/problemset/problem/200/B
// B. Drinks
int main() {
    int n, x; cin >> n;
    double result = 0, final = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        result += (double)x / 100;
    }
	final = (double)(result / n) * 100;
	cout << setprecision(10) << final;
}
using namespace std;
int main() {
    int n; cin >> n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        int percentage; cin >> percentage;
        sum += percentage;
    }
    double average = sum / n;
    cout << fixed << setprecision(12) << average << endl;
}
http://codeforces.com/problemset/problem/208/A
// A. Dubstep
using namespace std;
int main(){
    string s1, s2; cin >> s1;
    while(s1.find("WUB") != -1){
        int x = s1.find("WUB");
        int(x == 0)    s1.erase(0, 3);
        else {
            s1.replace(x, 1, " ");
            s1.erase(x + 1, 2);
        }
    }
    cout << s1;
}
using namespace std;
int main() {
    string s; cin >> s;
    string result;
    size_t pos = 0;
    while (pos < s.length()) {
        // If "WUB" is found at current position, skip it
        if (s.substr(pos, 3) == "WUB") {
            pos += 3;
            if (!result.empty() && result.back() != ' ')    result += ' ';
        } else {
            result += s[pos];
            pos++;
        }
    }
    if (!result.empty() && result.front() == ' ')    result.erase(0, 1);
    if (!result.empty() && result.back() == ' ')    result.pop_back();
    cout << result << endl;
}

using namespace std;
// A. Mountain Scenery
https://codeforces.com/contest/218/problem/A
const int MAX = 105;
int height[MAX];
int main(){
    int n, k; cin >> n >> k;
    int total = 2 * n + 1;
    for(int i = 0; i < total; ++i)
        cin >> height[i];
    for(int i = 1; i < total - 1 && k > 0; i += 2){
        if(height[i] > height[i - 1] + 1 && height[i] > height[i + 1] + 1) {
            --height[i];
            --k;
        }
    }
    for (int i = 0; i < total; ++i)
        cout << height[i] << " ";
    cout << "\n";
}
using namespace std;
//B.Effective Approach
http://codeforces.com/problemset/problem/227/B
int main(){
    map <int, int> position;
    long long frontSteps = 0, backSteps = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        position[val] = i;
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int query; cin >> query;
        frontSteps += position[query] + 1;
        backSteps += n - position[query];
    }
    cout << frontSteps << " " << backSteps << "\n";
}
http://codeforces.com/contest/228/problem/A
// A. Is your horseshoe on the other hoof?
using namespace std;
int main() {
    set<int> colors;
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        colors.insert(x);
    }
    cout << 4 - colors.size();
    return 0;
}

using namespace std;
http://codeforces.com/contest/230/problem/A
// A. Dragons
int main() {
    int s, n;
    cin >> s >> n; // s = initial strength, n = number of dragons
    vector<pair<int, int>> dragons(n);
    // Read each dragon's strength and bonus
    for (int i = 0; i < n; ++i)
        cin >> dragons[i].first >> dragons[i].second;
    // Sort dragons by their strength (ascending order)
    sort(dragons.begin(), dragons.end());
    // Try to fight each dragon in order
    for (int i = 0; i < n; ++i) {
        int dragon_strength = dragons[i].first;
        int bonus = dragons[i].second;
        if (s > dragon_strength)
            s += bonus; // Kirito defeats the dragon and gains bonus
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
using namespace std;
// problemset/problem/231/A
// A. Team
int main(){
    int n; cin >> n;
    int solved = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int x; cin >> x;
            cnt += x;
        }
        if(cnt >= 2) solved++;
    }
    cout << solved;
}
using namespace std;
http://codeforces.com/contest/231/problem/A
// A.Team
int main() {
    int n; cin >> n;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a + b + c >= 2) ++counter;
    }
    cout << counter << endl;
}
using namespace std;
int main() {
	int n; cin >> n;
	int counter = 0;
	int arr[n][3];
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < 3; j++)
	        cin >> arr[i][j];
	}
	for(int i = 0; i < n; i++){
	    int x = 0;
	    for(int j = 0; j < 3; j++){
	        if(arr[i][j] == 1) x++;
	    }
	    if(x >= 2) counter += 1;
	}
	cout << counter;
	return 0;
}
using namespace std;
http://codeforces.com/contest/233/problem/A
// A - Perfect Permutation
int main() {
    int n;
    cin >> n;

    // If n is odd, no perfect permutation exists
    if (n % 2 == 1) {
        cout << -1 << endl;
    } else {
        // Generate a perfect permutation by swapping adjacent elements
        for (int i = 1; i <= n; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        cout << endl;
    }
    return 0;
}
using namespace std;
http://codeforces.com/contest/236/problem/A
// Boy_or_Girl
int main() {
    string s; cin >> s;
	int len = s.length();
	set <char> ma;
	for(int i = 0; i < len; i++)    ma.insert(s[i]);
	cout << (ma.size() % 2 == 0) ? "CHAT WITH HER" : "IGNORE HIM!";
	return 0;
}
using namespace std;
int main() {
    string username; cin >> username;
    set<char> uniqueLetters(username.begin(), username.end());
    if (uniqueLetters.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
}
using namespace std;
// A. Cupboards
// http://codeforces.com/contest/248/problem/A
int main() {
    int n;
    cin >> n;
    int leftOpen = 0, rightOpen = 0;
    for (int i = 0; i < n; ++i) {
        int left, right;
        cin >> left >> right;
        if (left) ++leftOpen;
        if (right) ++rightOpen;
    }
    int leftClosed = n - leftOpen;
    int rightClosed = n - rightOpen;

    // For each side, choose the minimal number of switches (either open or close)
    int minLeftOperations = min(leftOpen, leftClosed);
    int minRightOperations = min(rightOpen, rightClosed);
    cout << (minLeftOperations + minRightOperations) << endl;
}
http://codeforces.com/problemset/problem/253/A
// A. Boys and Girls
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	string s = "";
	int nn = n, mm = m;
	if(n > m){
	    for(int i = 0; i < n + m; i++){
	        if(nn > 0){
	            s += "B"; nn--;
	        }
	        if(mm > 0){
	            s += "G"; mm--;
	        }
	    }
	    cout << s;
	}
	else {
	    for(int i = 0; i < n + m; i++){
	        if(mm > 0){
	            s += "G"; mm--;
	        }
	        if(nn > 0){
	            s += "B"; nn--;
	        }
	    }
	}
}
using namespace std;
int main() {
    int boys, girls; cin >> boys >> girls;
    string result = "";
    char first, second;
    int firstCount, secondCount;
    // Decide the alternating order based on which group is larger
    if (boys >= girls) {
        first = 'B'; second = 'G';
        firstCount = boys; secondCount = girls;
    } else {
        first = 'G'; second = 'B';
        firstCount = girls; secondCount = boys;
    }
    // Alternate while both have members left
    while (firstCount > 0 || secondCount > 0) {
        if (firstCount > 0) {
            result += first;
            --firstCount;
        }
        if (secondCount > 0) {
            result += second;
            --secondCount;
        }
    }
    cout << result << endl;
}
http://codeforces.com/problemset/problem/263/A
// A. Beautiful Matrix
using namespace std;
int main() {
	int arr[5][5], ineed, jneed, tj=2, ti=2;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int x; cin >> x;
            if(x == 1){
                indeed = i; jneed = j;
            }
            arr[i][j] = x;
        }
    }
	int v1 = abs(ineed - ti);
	int v2 = abs(jneed - tj);
	cout << v1 + v2;
}
using namespace std;
int main() {
    int x;
    int row = 0, col = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> x;
            if (x == 1) {
                row = i; col = j;
            }
        }
    }
    cout << abs(row - 2) + abs(col - 2);
}

using namespace std;
// A. Beautiful Matrix
// problemset/problem/263/A
int main() {
    int x, y, ans;
    int arr[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }
    cout << abs(x - 2) + abs(y - 2);
}
http://codeforces.com/contest/265/problem/A
// A. Colorful Stones (Simplified Edition)
using namespace std;
int main() {
	string s1, s2; cin >> s1 >> s2;
	int pos = 0;
	int len = s2.length();
	for(int i = 0; i < len; i++){
	    if(s2[i] == s1[pos])    pos++;
	}
    cout << ++pos;
}
using namespace std;
int main() {
    string s1, s2; cin >> s1 >> s2;
    int pos = 0;
    for (char c : s2) {
        if (c == s1[pos]) ++pos;
    }
    cout << pos + 1 << endl;
    return 0;
}

using namespace std;
http://codeforces.com/contest/266/problem/A
// A. Stones on the Table
int main(){
    int n; cin >> n;
    string str; cin >> str;
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(str[i - 1] == str[i])
            cnt++;
    }
    cout << cnt;
  	return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/266/A
// Stones_on_the_Table.cpp
int main(){
    int n;
    char arr[51];
    cin >> n >> arr;
    int t = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == arr[i+1])
            t++;
    }
    cout << t;
}
using namespace std;
int main() {
    int length; cin >> length;
    string s; cin >> s;
    int counter = 0;
    for (int i = 1; i < length; ++i) {
        if (s[i] == s[i - 1])
            ++counter;
    }
    cout << counter << endl;
}
//https://codeforces.com/problemset/problem/266/A
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            cnt=cnt+1;
    }
    cout<<cnt;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    cin >>n;
    string a;
    cin >>a;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==a[i-1])
            cnt++;
    }
    cout<< cnt;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    cin >>n;
    string s;
    cin >>s;
    for(int i=0; i<n; i++)
    {
        if(i!= n-1 && s[i]==s[i+1])
            cnt++;
        else
        {
            cout << cnt;
                break;
        }
    }
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, cnt=0;
    cin >>n;
    string s;
    cin >>s;
    for(int i=0; i<n-1; i++)
        cnt+=s[i]==s[i+1];
    cout<<cnt;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    string st;
    cin>> n;
    cin>> st;
    for(int i=0; i<n; i++)
    {
        for(;i <n && st[i]==st[i+1]; i++)
            cnt++;
    }
    cout << cnt;
}
using namespace std;
http://codeforces.com/problemset/problem/266/B
// Queue at the School
int main() {
    int n, t; cin >> n >> t;
    string s; cin >> s;
    for (int i = 0; i < t; ++i) {
        for (int j = 1; j < n; ++j) {
            if (s[j - 1] == 'B' && s[j] == 'G') {
                swap(s[j - 1], s[j]);
                ++j; // Skip the next index to avoid double swap
            }
        }
    }
    cout << s;
}
http://codeforces.com/contest/268/problem/A
// Games.cpp
using namespace std;
int main() {
    int n; cin >> n;
	int gamescount = 0, arr1[n], arr2[n];
	for(int i = 0; i < n; i++)    cin >> arr1[i] >> arr2[i];
	for(int i = 0; i < n; i++)    gamescount += count(arr2, arr2 + n, arr1[i]);
	 cout << gamescount;
}
using namespace std;
int main() {
    int n; cin >> n;
    int home[n], away[n];
    for (int i = 0; i < n; ++i) 
        cin >> home[i] >> away[i];
    int gameCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (home[i] == away[j]) gameCount++;
        }
    }
    cout << gameCount << endl;
}
using namespace std;
// A. Fancy Fence
// contest/270/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        (360 % (180 - x)) ? cout << "No\n" : cout << "Yes\n";
    }
}
using namespace std;
http://codeforces.com/problemset/problem/271/A
// Beautiful Year
bool isBeautiful(int n) {
    string s = to_string(n);
    set<char> digits(s.begin(), s.end());
    return digits.size() == 4;
}
bool isBeautiful(int n){
	string str = to_string(n);
	int dig1 = count(str.begin(), str.end(),str[0]);
	int dig2 = count(str.begin(), str.end(), str[1]);
	int dig3 = count(str.begin(), str.end(), str[2]);
	int dig4 = count(str.begin(), str.end(), str[3]);
	if((dig1 == 1)&&(digt2=1)&&(digt3==1)&&(digt4==1))
		return 1;
    if((dig1 == 1) && (dig2 == 1) && (dig3 == 1) && (dig4 == 1)) return 1;
	else return 0;
}
int main() {
    int n; cin >> n;
    ++n;
    while(!isBeautiful(n))
        ++n;
    cout << n;
    return 0;
}
using namespace std;
// A. Word Capitalization
// problemset/problem/281/A
int main() {
    string ch; getline(cin, ch); 
    if (!ch.empty() && ch[0] >= 'a' && ch[0] <= 'z')
        ch[0] = ch[0] - 32; 
    cout << ch << endl;
}
using namespace std;
http://codeforces.com/contest/281/problem/A
// A. Word Capitalization
int main() {
	 string s; cin >> s;
	 s[0] = toupper(s[0]);
	 cout << s;
}
using namespace std;
char capitalize(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    return ch;
}
int main() {
    char word[1001]; cin >> word;
    word[0] = capitalize(word[0]);
    cout << word << endl;
}

using namespace std;
// A. Bit++
// contest/282/problem/A _have a programming language called Bit++ with one variable x, which starts at 0. consists of statements that either:
//Increase x by 1: "++X" or "X++".Decrease x by 1: "--X" or "X--".Execute all statements and print the final value of x.
int main(){
    int t, cnt = 0; cin >> t;
    while(t--){
        string str; cin >> str;
        if(str == "++X" || str == "X++")
            cnt++;
        else if(str == "--X" || str == "X--")
            cnt--;
    }
    cout << cnt;
}
using namespace std;
http://codeforces.com/contest/282/problem/A
// 282A - Bit++
int main() {
    int n, x = 0; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s[1] == '+') ++x;
        else --x;
    }
    cout << x << endl;
}
using namespace std;
int main() {
	int n; cin >> n;
	int x = 0;
	while(n--){
	    string s; cin >> s;
		if(s.find('+') != -1) x += 1;
		else x -= 1;
		cin.ignore();
	}
	cout << x;
}
using namespace std;
// http://codeforces.com/contest/289/problem/A
// A - Polo the Penguin and Segments
int main() {
    int n, k; cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        sum += (r - l + 1);
    }
    cout << (k - (sum % k)) % k << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/294/problem/A
// A. Shaass and Oskols
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        int r = arr[x - 1] - y;
        int l = y - 1;
	if(x - 1 >= 1) arr[x - 2] += l;
	if(x + 1 <= n) arr[x] += r;
	arr[x - 1] = 0;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
using namespace std;
http://codeforces.com/contest/294/problem/A
// Shaass_and_Oskols.cpp
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i]; 
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--;
        if (x > 0)
            arr[x - 1] += y - 1; // birds fly to the wire before

        if (x < n - 1)
            arr[x + 1] += arr[x] - y; // birds fly to the wire after
        arr[x] = 0; // all birds on wire x fly away
    }
    for (int i = 0; i < n; i++) 
        cout << arr[i] << '\n';
}
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        arr[x] += arr[x - 1] - y;
	    arr[x - 2] += y - 1;
	    arr[x - 1] = 0;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}
using namespace std;
http://codeforces.com/problemset/problem/318/A
// A. Even Odds
int main() {
    long long n, k; cin >> n >> k;
    long long mid = (n + 1) / 2;
    if (k <= mid)
        cout << 2 * k - 1;
    else
        cout << 2 * (k - mid);
}
using namespace std;
http://codeforces.com/problemset/problem/337/A
// 337A - Puzzles
int main() {
    int n, m; cin >> n >> m;
    int puzzles[m];
    for (int i = 0; i < m; ++i)
        cin >> puzzles[i];
    sort(puzzles, puzzles + m);
    int min_diff = puzzles[n - 1] - puzzles[0];
    for (int i = n; i < m; ++i)
        min_diff = min(min_diff, puzzles[i] - puzzles[i - n + 1]);
    cout << min_diff << endl;
    return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/337/A
// 337A - Puzzles
int main() {
    int n, m; cin >> n >> m;
    vector<int> puzzles(m);
    for (int i = 0; i < m; ++i)
        cin >> puzzles[i];
    sort(puzzles.begin(), puzzles.end());
    int min_diff = puzzles[n - 1] - puzzles[0];
    for (int i = 0; i <= m - n; ++i) {
        int current_diff = puzzles[i + n - 1] - puzzles[i];
        min_diff = min(min_diff, current_diff);
    }
    cout << min_diff << endl;
    return 0;
}
http://codeforces.com/contest/339/problem/A
// HelpfulMaths
using namespace std;
int main() {
    string s, s2; cin >> s;
    int len = s.length();
	for(int i = 0; i < len; i++){
	    if(s[i] != '+')    s2 += s[i];
	}
	sort(s2.begin(), s2.end());
	len = s2.length();
	if(len > 1){
	    cout << s2[0];
	    for(int i = 1; i < len - 1; i++)
	        cout << '+' << s2[i];
	    cout << '+' << s2[len - 1];
	}
	else    cout << s;
}
using namespace std;
int main() {
    string s; cin >> s;
    string digits;
    // Extract digits only (ignore '+')
    for (char c : s) {
        if (c != '+')    digits += c;
    }
    sort(digits.begin(), digits.end());
    for (size_t i = 0; i < digits.size(); ++i) {
        if (i > 0) cout << '+';
        cout << digits[i];
    }
}
using namespace std;
http://codeforces.com/problemset/problem/339/B
// 339B - Xenia and Ringroad
int main() {
    int n, m; cin >> n >> m;
    int current = 1;
    unsigned long long moves = 0;
    for (int i = 0; i < m; ++i) {
        int target; cin >> target;
        if (target >= current)
            moves += target - current;
        else
            moves += n - (current - target);
        current = target;
    }
    cout << moves << endl;
    return 0;
}
http://codeforces.com/problemset/problem/344/A
// A. Magnets
using namespace std;
int main(){
    int magnets; cin >> magnets;
    int counter = 1, arr[100000];
    for(int i = 0; i < magnets; i++)    cin >> arr[i];
    for(int i = 0; i < magnets - 1; i++){
        if(arr[i] != arr[i + 1])    counter++;
    }
    cout << counter;
}
using namespace std;
int main() {
    int n; cin >> n;
    int groups = 1;
    string prev, curr; cin >> prev;
    for (int i = 1; i < n; i++) {
        cin >> curr;
        if (curr != prev)    groups++;
        prev = curr;
    }
    cout << groups << endl;
}
http://codeforces.com/contest/344/problem/A
// Magnets.cpp
using namespace std;
int main() {
	int n; cin >> n;
	string s1, s2; cin >> s1;
	int magnetics = 1;
	for(int i = 1; i < n; i++){
	    cin >> s2;
	    if(s1[1] == s2[0])    ++magnetics++;
	    s1 = s2;
	}
	cout << magnetics;
	return 0;
}
using namespace std;
int main() {
    int n, groupCount = 1; cin >> n
    string prev, current; cin >> prev;
    for (int i = 1; i < n; ++i) {
        cin >> current;
        if (prev != current)    groupCount++;
        prev = current;
    }
    cout << groupCount << endl;
    return 0;
}

http://codeforces.com/contest/363/problem/B
// B. Fence
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int height; cin >> height;
        prefix[i] = prefix[i - 1] + height;
    }
    int min_index = 0;
    long long min_sum = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        long long sum = prefix[i + k] - prefix[i];
        if (sum < min_sum) {
            min_sum = sum;
            min_index = i;
        }
    }
    cout << (min_index + 1) << endl;
}
http://codeforces.com/contest/365/problem/A
// 365A. Good Number
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int good_count = 0;
    for (int i = 0; i < n; ++i) {
        string number;
        cin >> number;
        vector <bool> digit_present(10, false);
        for (char ch : number)
            digit_present[ch - '0'] = true;
        bool is_good = true;
        for (int d = 0; d <= k; ++d) {
            if (!digit_present[d]) {
                is_good = false;
                break;
            }
        }
        if (is_good)
            ++good_count;
    }
    cout << good_count << endl;
    return 0;
}
using namespace std;
int arr[10];
int main() {
	int n, k; cin >> n >> k;
	vector <string> vect;
	for(int i = 0; i < n; i++){
		string str; cin >> str;
		vect.push_back(str);
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		int val = 0;
		for(int j = 0; j <= k; j++){
		    if(vec[i].find(to_string(j)) != -1) ++val;
		}
 		if(val == k + 1) ++res;
	}
	cout << res;
}
using namespace std;
// 365A. Good Number 
http://codeforces.com/contest/365/problem/A
int main(){
    int n, k; cin >> n >> k;
    int res = 0;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        int len = str.length();
        int cnt = 0;
        for(int j = 0; j <= k; j++){
            if(str.find('0' + j) != -1)
                ++cnt;
        }
        if(cnt == k + 1) res++;
    }
    cout << res;
}
using namespace std;
// Valera and Plates
// problemset/problem/369/A _given n dishes, where each dish requires either a bowl or a plate 
// have a limited number of bowls and plates.determine how many dishes cannot be served due to a lack of resources.
int main(){
    int n, bowl, plate; cin >> n >> bowl >> plate;
    int arr[n + 5], b = 0, p = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] == 1)
            b++;
        else if(arr[i] == 2)
            p++;
    }
    int res = 0, ans = 0;
    if(bowl >= b) bowl -= b;
    else{
        ans = b - bowl;
        bowl = 0;
    }
    if(plate >= p) res = 0;
    else{
        p -= plate;
        if(bowl > 0){
            if(bowl >= p){
                bowl -= p; res = 0;
            }
            else res = p - bowl;
        }
        else res = p
    }
    cout << ans + res;
}
http://codeforces.com/problemset/problem/379/A
// New_Year_Candles.cpp
using namespace std;
int main() {
	int val, ref; cin >> val >> ref;
	int sum = val;
	int rem = 0;
	while(val / ref > 0){
	    rem = val % ref;
	    val /= ref;
	    sum += ceil(val);
	    val += rem;
	}
	cout << sum;
}
using namespace std;
int main() {
    int candles, exchange; cin >> candles >> exchange;
    int total = candles;
    while (candles >= exchange) {
        int new_candles = candles / exchange;
        total += new_candles;
        candles = new_candles + (candles % exchange);
    }
    cout << total << endl;
}

using namespace std;
http://codeforces.com/contest/381/problem/A
// A. Sereja and Dima
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int l = 0, r = n - 1;
    int sscore = 0, dscore = 0;
    for (int turn = 0; turn < n; ++turn) {
        int chosen;
        if (arr[l] >= arr[r])
            chosen = arr[l++];
        else
            chosen = arr[r--];
        if (turn % 2 == 0)
            sscore += chosen; 
        else
            dscore += chosen;
    }
    cout << sscore << " " << dscore << endl;
}
using namespace std;
https://codeforces.com/problemset/problem/381/A
// SerejaAndDima.cpp
int main() {
	int n; cin >> n;
	int snscore = 0,dimscore = 0,counter = 0, right = 0, left = n - 1;
	int arr[n];
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
	while(counter < n){
		if(counter % 2 == 0){
			if(arr[right] > arr[left]){
			    snscore += arr[rigtht];
				right++;
			}
			else
			    snscore += arr[left];
				left--;
		}
		else {
		    if(arr[right] > arr[left]){
			    dimscore += arr[right];
			  	rigtht++;
		    }
			else{
			    dimscore += arr[left];
			    left--;
			}
	    }
		counter++;
	}
	cout << snscore << " " << dimscore;
}
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = 0, right = n - 1;
    int sereja = 0, dima = 0;
    bool turn = true; // true = Sereja's turn, false = Dima's turn
    while (left <= right) {
        int chosen;
        if (arr[left] > arr[right])
            chosen = arr[left++];
        else
            chosen = arr[right--];
        if (turn)
            sereja += chosen;
        else
            dima += chosen;
        turn = !turn;
    }
    cout << sereja << " " << dima << endl;
}
using namespace std;
http://codeforces.com/contest/382/problem/A
// A. Ksenia and Pan Scales
int main() {
    string s, extra;
    cin >> s >> extra;
    size_t pipe_pos = s.find('|');
    string left = s.substr(0, pipe_pos);
    string right = s.substr(pipe_pos + 1);

    int left_len = left.length();
    int right_len = right.length();
    int extra_len = extra.length();

    int total_len = left_len + right_len + extra_len;
    if (total_len % 2 == 0 && abs(left_len - right_len) <= extra_len) {
        int target_len = total_len / 2;
        // Add characters from `extra` to the shorter side
        int to_add_left = target_len - left_len;
        left += extra.substr(0, to_add_left);
        right += extra.substr(to_add_left);

        cout << left << '|' << right << endl;
    } else
        cout << "Impossible" << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/404/problem/A
A. Valera and X
char arr[305][305];
int main(){
    int n, cnt = 0; cin >> n;
    set <char> se, se2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || j == n - 1 - i){
                ++cnt;
                se2.insert(arr[i][j]);
            }
            else
                se.insert(arr[i][j]);
        }
    }
    char x = *se.begin();
    char y = *se2.begin();
    if(se.size() == se2.size() && se.size() == 1 && count == (2*n) - 1 && x != y)
        cout<<"YES";
    else cout << "NO";
}
using namespace std;
int main() {
    int n;
    cin >> n;
    char matrix[305][305];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    char diag_char = matrix[0][0];      
    char non_diag_char = matrix[0][1];
    if (diag_char == non_diag_char) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || j == n - 1 - i) {
                if (matrix[i][j] != diag_char) {
                    cout << "NO\n";
                    return 0;
                }
            } else {
                if (matrix[i][j] != non_diag_char) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}
http://codeforces.com/problemset/problem/405/A
// GravityFlip.cpp
using namespace std;
int main(){
    int n; cin >> n;
    int arr[101];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)    cout << arr[i] << " ";
}
using namespace std;
http://codeforces.com/contest/408/problem/A
// A. Line to Cashier
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < arr[i]; j++){
            int x; cin >> x;
            sum += 15 + x * 15;
        }
        arr[i] = sum;
    }
    sort(arr, arr + n);
    cout << arr[0];
}
using namespace std;
http://codeforces.com/contest/408/problem/B
// B. Garland
int arr[26], arr2[26];
int main(){
    string s, s2; cin >> s >> s2;
    int sum = 0;
    int len1 = s.length();
    int len2 = s2.length();
    for(int i = 0; i < len1; i++)
        ++arr[s[i] - 'a'];
    for(int i = 0; i < len2; i++)
        ++arr2[s2[i] - 'a'];
    for(int i = 0; i < 26; i++){
        if(arr2[i]){
            if(arr[i])
                sum += min(arr[i], arr2[i]);
            else{
                sum = 0; break;
            }
        }
    }
    if(sum) cout << sum;
    else cout << -1;
}
using namespace std;
int main() {
    string s, s2; cin >> s >> s2;
    int freq_s[26] = {0};
    int freq_s2[26] = {0};
    for (char ch : s)
        ++freq_s[ch - 'a'];
    for (char ch : s2)
        ++freq_s2[ch - 'a'];
    int total = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq_s2[i] > 0) {
            if (freq_s[i] == 0) {
                cout << -1 << endl;
                return 0;
            }
            total += min(freq_s[i], freq_s2[i]);
        }
    }
    cout << total << endl;
    return 0;
}
using namespace std;
http://codeforces.com/contest/427/problem/A
//427 A. Police Recruits.cpp
int main() {
    int n; cin >> n;
    int availableOfficers = 0;
    int untreatedCrimes = 0;
    for (int i = 0; i < n; ++i) {
        int event; cin >> event;

        if (event > 0)
            availableOfficers += event;
        else{
            if (availableOfficers > 0)
                --availableOfficers; 
            else
                ++untreatedCrimes;
        }
    }
    cout << untreatedCrimes << endl;
}
http://codeforces.com/contest/427/problem/A
// PoliceRecruits.cpp
using namespace std;
int main() {
    int n; cin >> n;
    int officersAvailable = 0;
    int untreatedCrimes = 0;
    for (int i = 0; i < n; ++i) {
        int event; cin >> event;
        if (event == -1) {
            if (officersAvailable > 0)    --officersAvailable;
            else    ++untreatedCrimes;
        } else    officersAvailable += event;
    }
    cout << untreatedCrimes << endl;
    return 0;
}
using namespace std;
int main() {
	int n; cin >> n;
	int officersnow = 0, crimes = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    if(x == -1){
	        if(officersnow > 0)    officersnow--;
	        else    crimes++;
	    }
	    else    officersnow += x;
    }
	cout << crimes;
}

using namespace std;
http://codeforces.com/contest/431/problem/A
// A. Black Square
int main(){
    int arr[4], res = 0;
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    string str; cin >> str;
    int len = str.length();
	for(int i = 0; i < len; i++){
	    int z = str[i] - '0';
	    res += arr[z - 1];
	}
    cout << res;
}
http://codeforces.com/contest/431/problem/A
// Black_Square
using namespace std;
int main() {
	int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
	int calories = 0;
	string s; cin >> s;
	int len = s.length();
	for(int i = 0; i < len; i++){
	    if(s[i] == '1')    calories += a1;
        if(s[i] == '2')    calories += a2;
        if(s[i] == '3')    calories += a3;
        if(s[i] == '4')    calories += a4;
	}
	cout << calories;
}
http://codeforces.com/problemset/problem/432/A
// Choosing_Teams
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	int count = 0;
	int arr[n];
	for(int i = 0; i < n; i++)    cin >> arr[i];
	for(int i = 0; i < n; i++){
	    if(5 - arr[i] >= k)    count++;
	}
	cout << count / 3;
	return 0;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> availability(n);
    int eligibleCount = 0;
    for (int i = 0; i < n; ++i) {
        cin >> availability[i];
        if (5 - availability[i] >= k)    ++eligibleCount;
    }
    int teams = eligibleCount / 3;
    cout << teams << endl;
}
using namespace std;
http://codeforces.com/contest/433/problem/B
// 433B. Kuriyama Mirai's Stones
int main() {
    int n; cin >> n;
    vector<long long> original(n), sorted(n);
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i < n; ++i) {
        original[i] += original[i - 1];
        sorted[i] += sorted[i - 1];
    }
    int q; cin >> q;
    while (q--) {
        int type, l, r; cin >> type >> l >> r;
        l--, r--;
        if (type == 1){
            if (l == 0) cout << original[r] << endl;
            else cout << original[r] - original[l - 1] << endl;
        }else{
            if (l == 0) cout << sorted[r] << endl;
            else cout << sorted[r] - sorted[l - 1] << endl;
        }
    }
}
http://codeforces.com/problemset/problem/433/B
// Kuriyama_Mirai's_Stones
using namespace std;
int func(int l, int r, int r){
    if(l - 1 == 0)    return arr[r - 1];
    else    return arr[r - 1] - arr[l - 2];
}
int main() {
    //n is number of stones ,m is he number of Kuriyama Mirai's questions
	int n, m; cin >> n; 
	int arr[n], arr2[n];
    for(int i = 0; i < n; i++)    cin >> arr[i];
    copy(arr, arr + n, arr2);
    sort(arr2, arr2 + n);
	for(int i = 1; i < n; i++){
	    arr[i] += arr[i - 1];
	    arr2[i] += arr2[i - 1];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
	    int type, l, r, res; cin >> type >> l >> r;
	    if(type == 1)    res = func(l, r, arr);
	    else    res = func(l, r, arr2);
	    cout << res;
	}
	return 0;
}
using namespace std;
long long get_range_sum(int l, int r, const vectorb<long long>& prefix_sum) {
    if (l == 1) return prefix_sum[r - 1];
    return prefix_sum[r - 1] - prefix_sum[l - 2];
}
int main() {
    int n; cin >> n;
    vector<long long> original(n), sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i < n; i++) {
        original[i] += original[i - 1];
        sorted[i] += sorted[i - 1];
    }
    int m; cin >> m;
    while (m--) {
        int type, l, r; cin >> type >> l >> r;
        if (type == 1)
            cout << get_range_sum(l, r, original) << endl;
        else
            cout << get_range_sum(l, r, sorted) << endl;
    }
}

using namespace std;
http://codeforces.com/problemset/problem/439/A
// A. Devu, the Singer and Churu, the Joker
int main() {
    int n, k; cin >> n >> k;
    int totalSongDuration = 0;
    for (int i = 0; i < n; ++i) {
        int song; cin >> song;
        totalSongDuration += song;
    }
    int totalBreakTime = (n - 1) * 10; // 10 minutes break between songs
    if (totalSongDuration + totalBreakTime > k)
        cout << -1 << endl;
    else {
        int remainingTime = k - totalSongDuration;
        int maxJokes = remainingTime / 5;
        cout << maxJokes << endl;
    }
}
using namespace std;
codeforces.com/contest/439/problem/B
// 439B. Devu, the Dumb Guy
int main() {
	int n, x; cin >> n >> x;
	int arr[n];
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
	sort(arr, arr + n);
	int sum = 0;
	for(int i = 0; i < n; i++){
	    sum += arr[i] * x;
	    if(x > 1) --x;
	}
	cout << sum;
}
http://codeforces.com/contest/443/problem/A
// Anton_and_Letters.cpp
using namespace std;
int main() {
    string s; getline(cin,s);
	set <char> letters;
	int len = s.length();
	for(int i = 0; i < len; i++){
        if(s[i] == ',' || s[i] == '{' || s[i] == '}' || s[i] == ' ');
        else    letters.insert(s[i]);
	}
	cout << letters.size();
}
using namespace std;
int main() {
    string input; getline(cin, input);
    set<char> uniqueLetters;
    for (char ch : input) {
        if (isalpha(ch)) {
            uniqueLetters.insert(ch);
        }
    }
    cout << uniqueLetters.size() << endl;
}
using namespace std;
http://codeforces.com/problemset/problem/451/A
// 451A - Game With Sticks
int main() {
    int n, m;
    cin >> n >> m;
    if (min(n, m) % 2 == 1)
        cout << "Akshat" << endl;
    else
        cout << "Malvika" << endl;
}
using namespace std;
http://codeforces.com/contest/451/problem/B
// 451B - Sort the Array
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    //for (int& x : arr)
        //cin >> x;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    // Find the first and last position where arr and sorted_arr differ
    int l = 0, r = n - 1;

    while (l < n && arr[l] == sorted_arr[l]) ++l;
    while (r >= 0 && arr[r] == sorted_arr[r]) --r;

    if (l >= r) {
        // Already sorted or only one element needs to be reversed (no-op)
        cout << "yes\n1 1\n";
        return 0;
    }
    // Reverse the subarray and check if it matches the sorted version
    reverse(arr.begin() + l, arr.begin() + r + 1);

    if (arr == sorted_arr) {
        cout << "yes\n" << (l + 1) << " " << (r + 1) << "\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
using namespace std;
https://codeforces.com/contest/456/problem/A
// 456A.Laptops
int main(){
    int n; cin >> n;
    map <int, int> mp;
    vector <int> vec;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        mp[x] = y;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    bool check = 0;
    for(int i = 0; i < n - 1; i++){
        if(mp[vec[i]] > mp[vec[i + 1]])
            check = 1;
    }
    if(check) cout << "Happy Alex";
    else cout << "Poor Alex";
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int, int>> laptops(n);
    for (int i = 0; i < n; ++i) {
        cin >> laptops[i].first >> laptops[i].second; 
    }
    sort(laptops.begin(), laptops.end());
    for (int i = 0; i < n - 1; ++i) {
        if (laptops[i].second > laptops[i + 1].second) {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;
    return 0;
}
using namespace std;
http://codeforces.com/problemset/problem/460/A
// A. Vasya and Socks
int main() {
	int n, m; cin >> n >> m;
	int res = (n - 1) / (m - 1);
	cout << n + res;
}
using namespace std;
http://codeforces.com/contest/460/problem/A
// A. Vasya and Socks
int main() {
    int n, k; cin >> n >> k;
    int days = 0;
    while (n > 0) {
        ++days;
        --n;
        if (days % k == 0)
            ++n; // Vasya gets an extra sock every k days
    }
    cout << days << endl;
}
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int current = 0, lastbuy = 0;
    while(n > 0){
	    ++current;
	    --n;
	    if(current - lastbuy == k){
		    ++n;
		    lastbuy = current;
	    }
    }
	cout << current;
}
using namespace std;
http://codeforces.com/contest/463/problem/B
// 463B - Caisa and Pylons
int main() {
    int n; cin >> n;
    int energy = 0;
    long long money = 0;
    int currentHeight = 0;
    for (int i = 0; i < n; ++i) {
        int nextHeight; cin >> nextHeight;
        energy += (currentHeight - nextHeight);
        if (energy < 0) {
            money += -energy;
            energy = 0;
        }
        currentHeight = nextHeight;
    }
    cout << money << endl;
}
using namespace std;
https://codeforces.com/contest/466/problem/A
// 466A. Cheap Travel;
int main(){
	int n, m, a, b; cin >> n >> m >> a >> b;
	int res = 0;
	if(m * a <= b) res = n * a;
	else res = (n / m) * b + min((n % m) * a, b);
	cout << res;
}
using namespace std;
http://codeforces.com/problemset/problem/467/A
// A. George and Accommodation
int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(b - a >= 2) ++cnt;
    }
    cout << cnt;
}
http://codeforces.com/problemset/problem/467/b
// Fedor_and_New_Game.cpp
using namespace std;
int main() {
	 int n, m, k; cin >> n >> m >> k;
	 int count = 0, arr[m + 1];
	 for(int i = 0; i <= m; i++)    cin >> arr[i];
	for(int i = 0; i < m; i++){
        int w = arr[m]^arr[i];
		if(__builtin_popcount(w) <= k)
			 count++;
	}
	cout << count;
}
using namespace std;
int main() {
    int n, m, k; cin >> n >> m >> k;
    int armies[m + 1];
    for (int i = 0; i <= m; i++)    cin >> armies[i];
    int fedor = armies[m];
    int count = 0;
    for (int i = 0; i < m; i++) {
        int diff = fedor ^ armies[i]; // XOR to find differing bits
        if (__builtin_popcount(diff) <= k)     count++;
    }
    cout << count << endl;
    return 0;
}

using namespace std;
http://codeforces.com/contest/469/problem/A
// 469A - I Wanna Be the Guy
int main() {
    int n; cin >> n;
    set<int> levels;
    int p1, p2, level;
    cin >> p1;
    for (int i = 0; i < p1; ++i) {
        cin >> level;
        levels.insert(level);
    }
    cin >> p2;
    for (int i = 0; i < p2; ++i) {
        cin >> level;
        levels.insert(level);
    }
    if ((int)levels.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
}
http://codeforces.com/problemset/problem/469/A
// I_Wanna_Be_the_Guy.cpp
using namespace std;
int main() {
	int n, p, q; cin >> n >> p;
	int counter = 0;
	set <int> levels;
	set <int> ::iterator it, it2;
	if(p != 0){
	    for(int i = 0; i < p; i++){
	        int x; cin >> x;
	        levels.insert(x);
	    }
	}
	cin >> q;
	if(q != 0){
	    for(int i = 0; i < q; i++){
	        int x; cin >> x;
	        levels.insert(x);
	    }
	}
	if(p || q != 0){
	    it = levels.begin();
	    for(int i = 1; i <= n; i++, it++){
	        if(*it == i)    ++counter;
	    }
	    cout << (counter == n)? "I become the guy" : "Oh, my keyboard";
	}
	if(!p && !q)    cout << "Oh, my keyboard";
}
using namespace std;
int main() {
    int n, p, q;
    cin >> n >> p;
    set<int> levels;
    for (int i = 0; i < p; ++i) {
        int x; cin >> x;
        levels.insert(x);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        levels.insert(x);
    }
    if ((int)levels.size() == n) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
}

using namespace std;
http://codeforces.com/contest/469/problem/A
// 469A - I Wanna Be the Guy
int main() {
    int n; cin >> n;
    set <int> levels;
    for (int i = 0; i < 2; i++) {
        int count; cin >> count;
        for (int j = 0; j < count; j++) {
            int level; cin >> level;
            levels.insert(level);
        }
    }
    if ((int)levels.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
}
using namespace std;
http://codeforces.com/problemset/problem/472/A
// A. Design Tutorial: Learn from Math
const int N = 1e6;
bool arr[N + 5];
void seive(){
    arr[0] = 1; arr[1] = 1;
    for(int i = 2; i <= N; i++){
        if(arr[i]) continue;
        for(int j = i * i; j <= N; j += i)
            arr[j] = 1;
    }
}
int main() {
	seive();
	int n; cin >> n;
	int val = n >> 1;
	int val2 = n - val;
	while(arr[val] == 0 || arr[val2] == 0){
	    ++val; val2 = n - val;
	}
	cout << val << " " << val2;
}
using namespace std;
const int N = 1e6 + 5;
bool isPrime[N];
void sieve() {
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i * i < N; i++) {
        if (!isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = true;
            }
        }
    }
}
int main() {
    sieve();
    int n; cin >> n;
    for (int i = 4; i <= n / 2; i++) {
        if (isPrime[i] && isPrime[n - i]) { // both not prime ⇒ both composite
            cout << i << " " << n - i << endl;
            break;
        }
    }
}
using namespace std;
https://codeforces.com/contest/474/problem/A
// 474 A. Keyboard
string solve(string str, char ch){
	string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string res;
    int len = str.length();
	for(int i = 0; i < len; i++){
	    int idx = s.find(str[i]);
	    if(ch == 'R') res += s[idx - 1];
	    else res += s[idx + 1];
	}
    return res;
}
int main(){
    string str; cin >> str;
    char ch; cin >> ch;
    cout << solve(s2,c);
}
using namespace std;
string solve(const string& input, char direction) {
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string result;
    for (char ch : input) {
        size_t index = keyboard.find(ch);
        if (direction == 'R')
            result += keyboard[index - 1];
        else// direction == 'L'
            result += keyboard[index + 1];
    }
    return result;
}
int main() {
    char shift;
    string typed;
    cin >> shift >> typed;
    cout << solve(typed, shift) << endl;
    return 0;
}

using namespace std;
// A. Keyboard
// contest/474/problem/A
int main(){
    char shift;
    string str, res; 
    cin >> shift >> str;
    const string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    res.resize(str.size());
    for(int i = 0; i < str.size(); i++){
        int idx = keyboard.find(str[i]);
        res[i] = (shift == 'R') ? keyboard.at(idx - 1) : keyboard.at(idx + 1);
    }
    cout << res;
}
using namespace std;
http://codeforces.com/problemset/problem/479/A
// 479A - Expression
int main() {
    int a, b, c; cin >> a >> b >> c;
    int result = max({
        a + b + c,
        a * b * c,
        a + (b * c),
        (a + b) * c,
        a * (b + c),
        (a * b) + c
    });
    cout << result << endl;
}
using namespace std;
http://codeforces.com/problemset/problem/486/A
// CalculatingFunction.cpp
int main() {
    int n; cin >> n;
    if (n % 2 == 0) cout << n / 2 << endl;
    else cout << -(n + 1) / 2 << endl;
    // if(n & 1) cout << -((n + 1) >> 1);
	// else cout << n >> 1; 
}
using namespace std;
http://codeforces.com/contest/490/problem/A
// A. Team Olympiad
int main() {
	int n; cin >> n;
	int arr[n];
	vector <int> one, two, three;
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	    if(arr[i] == 1)
	        one.push_back(i + 1);
	    else if(arr[i] == 2)
	        two.push_back(i + 1);
	    else
	        three.push_back(i + 1);
	}
    // int teams = min({one.size(), two.size(), three.size()});
	int teams = min(t1, min(t2, t3));
	cout << teams << endl;
	for(int i = 0; i < teams; i++)
	    cout << one[i] << " " << two[i] << " " << three[i] << "\n";
}
using namespace std;
http://codeforces.com/problemset/problem/510/A
// A. Fox And Snake
int main(){
    int n, m; cin >> n >> m;
    int odd = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++)
                cout << "#";
        }
        else{
            ++odd;
            for(int j = 0; j < m; j++){
                if(odd % 2 == 1 && j == m - 1) cout << "#";
                else if(odd % 2 == 0 && j == 0) cout << "#";
                else cout << ".";
            }
        }
        cout << "\n";
    }
}
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) cout << "#";
        } else {
            for (int j = 0; j < m; ++j) {
                if ((i / 2) % 2 == 0 && j == m - 1) cout << "#";
                else if ((i / 2) % 2 == 1 && j == 0) cout << "#";
                else cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}
using namespace std;
https://codeforces.com/contest/514/problem/A
// 514A. Chewbaсca and Number
int main() {
    string s, s2; cin >> s;
    s2 = s;
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(i){
	        if(9 - (s[i] - '0') >= 0 && (9 - (s[i] - '0')) < s[i] - '0')
	            s[i] = (9 - (s[i] - '0')) + '0';
        }
        else{
            if(9 - (s[i] - '0') > 0 && (9 - (s[i] - '0')) < s[i] - '0')
	            s[i] = (9 - (s[i] - '0')) + '0';
        }
    }
if(s < s2) cout << s;
else cout << s2;
}
using namespace std;
int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        int digit = s[i] - '0';
        int flipped = 9 - digit;
        if (flipped < digit && (i > 0 || flipped > 0)) {
            s[i] = flipped + '0';
        }
    }
    cout << s << '\n';
    return 0;
}
using namespace std;
https://codeforces.com/problemset/problem/518/A
// A. Vitaly and Strings
int main() {
    string s, s2; cin >> s >> s2;
    int len = s.length();
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == 'z') s[i] = 'a';
        else {
            s[i]++;
            break;
        }
    }
    if (s < s2) cout << s;
    else cout << "No such string";
}
http://codeforces.com/problemset/problem/520/A
// Pangram.cpp
using namespace std;
int main(){   
    int n; cin >> n;
    string s; cin >> s;
    char j = 'A';
    for(int i = 0; i < n; i++)    s[i] = toupper(s[i]);
    if(n >= 26){
        for(int i = 0; i < 26; i++){
            if(s.find(j) != -1)    j++;
            else    cout << "No";
            return 0;
        }
        cout << "Yes";
    }
    else    cout << "No";
}
using namespace std;
int main() {
    int n;
    string s; cin >> n >> s;
    set<char> letters;
    for (char c : s)
        letters.insert(tolower(c));
    if (letters.size() == 26)    cout << "YES";
    else    cout << "NO";
    return 0;
}
http://codeforces.com/problemset/problem/520/A
// Pangram
using namespace std;
int main() {
	string s;
	int n; cin >> n >> s;
	set <char> se;
	for(int i = 0; i < n; i++){
	    s[i] = tolower(s[i]);
	    se.insert(s[i]);
	}
	cout << (se.size() == 26) ? "Yes" : "No";
}
using namespace std;
int main() {
    int n;
    string s; cin >> n >> s;
    set<char> se;
    for (char c : s)
        se.insert(tolower(c));
    cout << (se.size() == 26 ? "YES" : "NO") << endl;
}

using namespace std;
http://codeforces.com/problemset/problem/535/B
// B.Tavas_and_SaDDas
vector<int> lucky_numbers;
void generate_lucky(int num) {
    if (num > 100000000) return;
    if (num != 0) lucky_numbers.push_back(num);
    generate_lucky(num * 10 + 4);
    generate_lucky(num * 10 + 7);
}
int main() {
    int n; cin >> n;
    generate_lucky(0);
    sort(lucky_numbers.begin(), lucky_numbers.end());
    for (int i = 0; i < lucky_numbers.size(); ++i) {
        if (lucky_numbers[i] == n) {
            cout << i + 1 << endl;
            break;
        }
    }
}
using namespace std;
vector <int> vec;
void luck(int n){
	if(n > 100000000)
		return;
	vec.push_back(n * 10 + 4);
	vec.push_back(n * 10 + 7);
	int w = vec.size();
	luck(vec[w - 1]);
	luck(vec[w - 2]);
}
int main(){
    int n; cin >> n;
    luck(0);
    sort(vec.begin(), vec.end());
    int q = vec.size();
    for(int i = 0; i < q; i++){
        if(vec[i] == n)
            cout << i + 1;
    }
}
using namespace std;
http://codeforces.com/problemset/problem/546/A
// Soldier_and_Bananas.cpp
int main() {
    long long k, n, w;
    cin >> k >> n >> w;
    // Total cost using arithmetic series sum: k * (1 + 2 + ... + w) = k * w * (w + 1) / 2
    long long total_cost = k * w * (w + 1) / 2;
    long long needed = max(0LL, total_cost - n);
    cout << needed << endl;
}
using namespace std;
int main() {
	long long k, n, w; cin >> k >> n >> w;
	long long cost=0,needed=0;
	for(int i = 1; i <= w; i++)
	    cost += k * i;
	if(cost <=n)
		cout << "0";
	else {
		 needed = cost - n;
		 cout << needed;
	}
}
using namespace std;
http://codeforces.com/contest/556/problem/A
// A. Case of the Zeros and Ones
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int zeros = count(s.begin(), s.end(), '0');
    int ones  = n - zeros; 
    cout << abs(zeros - ones) << '\n';
    // int zers = count(s.begin(), s.end(), '0');
	// int ons = count(s.begin(), s.end(), '1');
	// cout<< n - (2* min(zers, ons));
    return 0;
}
using namespace std;
http://codeforces.com/contest/567/problem/A
// 567A - Lineland Mail
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        int minDist, maxDist;
        if (i == 0){
            minDist = abs(arr[i] - arr[i + 1]);
            maxDist = abs(arr[i] - arr[n - 1]);
        } else if (i == n - 1) {
            minDist = abs(arr[i] - arr[i - 1]);
            maxDist = abs(arr[i] - arr[0]);
        } else {
            minDist = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
            maxDist = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
        }
        cout << minDist << " " << maxDist << "\n";
    }
}
using namespace std;
int main() {
	 int n; cin >> n;
	 int arr[n];
	 for(int i=0;i<n;i++){
		 cin>>arr[i];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
	for(int i = 0; i < n; i++){
		long long  mini, maxi;
		if(!i){
			mini=abs(arr[i]-arr[i+1]);
			maxi=abs(arr[i]-arr[n-1]);
		}
		else if(i == n-1) {
			 maxi = abs(arr[i] - arr[0]);
			 mini = abs(arr[i] - arr[i - 1]);
		}
		else{
			 mini = min(abs(arr[i] - arr[i + 1]), abs(arr[i] - arr[i - 1]));
			 maxi = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
		}
		 cout<<mini<<" "<<maxi<<"\n";
	}
	return 0;
}
using namespace std;
http://codeforces.com/contest/567/problem/A
// A. Lineland Mail
int main() {
    int n; cin >> n;
    long long arr[n];
    for (int i = 0; i < n; ++i) 
        cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        long long mini, maxi;
        if (i == 0) {
            mini = abs(arr[i] - arr[i + 1]);
            maxi = abs(arr[i] - arr[n - 1]);
        }
        else if (i == n - 1) {
            mini = abs(arr[i] - arr[i - 1]);
            maxi = abs(arr[i] - arr[0]);
        }
        else {
            mini = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
            maxi = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
        }
        cout << mini << " " << maxi << '\n';
    }
}
using namespace std;
int main() {
	int n; cin >> n;
	long long arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++){
		long long mini = INT_MAX;
		long long maxi = INT_MIN;
		if(!i){
			mini = min(mini, min(abs(arr[i] - arr[n - 1]), abs(arr[i] - arr[i + 1])));
			maxi = max(maxi, max(abs( arr[i] - arr[n - 1]), max( abs(arr[i] - arr[i + 1]) , abs(arr[i] - arr[n - 1])) ));
		}
		else if(i == n - 1){
			mini = min(mini, min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[0])));
			maxi = max(maxi, max(abs( arr[i] - arr[i-1]), max(abs (arr[i] - arr[0]), abs( arr[i] - arr[n-1]))));
			
		}
		else{
			mini = min(mini, min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1])));
			maxi = max(maxi, max(abs(arr[i] - arr[i - 1]), max(abs(arr[i] - arr[i + 1]), max(abs(arr[i] - arr[n - 1]), abs(arr[i] - arr[0])))));
		}
		cout << mini << " " << maxi << "\n";
	}
}
using namespace std;
http://codeforces.com/problemset/problem/580/A
// A. Kefa and First Steps
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int maxLength = 1, currentLength = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1])
            currentLength++;
        else
            currentLength = 1;
        maxLength = max(maxLength, currentLength);
    }
    cout << maxLength << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    int maxlength = 0, start = 0, end = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i){
	        if(arr[i] < arr[i - 1]){
		        end = i - 1;
		        maxlength = max(maxlength, (end - start) + 1);
                start = i;
	        }
	        else{
		         end = i;
		         maxlength = max(maxlength, (end - start) + 1);
	        }
	    }
    }
    if(!start && !end) cout << n;
    else cout << maxlength;
}
using namespace std;
https://codeforces.com/problemset/problem/581/A
// 581A. Vasya the Hipster
int main(){
    int a, b; cin >> a >> b;
    int mini = min(a,b);
    int maxi = max(a,b);
    cout << mini << " " << (maxi - mini)/2 << endl;
}
using namespace std;
http://codeforces.com/contest/584/problem/A
// 584A - Olesya and Rodion
int main() {
    int n, d; cin >> n >> d;
    string s;
    // Case 1: Can't form a number with one digit divisible by 10
    if (d == 10 && n < 2)
        cout << "-1";
    // Case 2: d = 10 and n >= 2 => number must end in 0, rest can be 1s
    else if (d == 10) {
        s.append(n - 1, '1');
        s += '0'; cout << s;
    }
    // Case 3: Any other digit
    else {
        s.append(n, d + '0');
        cout << s;
    }
}
using namespace std;
int main() {
	int n, d; cin >> n >> d;
	string s;
	if(d == 10 && n < 2) cout << "-1";
	else if(d == 10 && n >= 2){
		for(int i = 0; i < n - 1; i++)
			s += 1 + '0';
		s += 0 + '0';
		cout << s;
	}
	else {
	    for(int i = 0; i < n; i++)
		    s += d + '0';
	    cout << s;
	}
	return 0;
}
http://codeforces.com/problemset/problem/588/A
// A. Duff and Meat
using namespace std;
int main(){
    int n; cin >> n;
    int amount, price;
    int minvalue = 100, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> amount >> price;
        minvalue = min(minvalue, price);
        sum += minvalue * amount;
    }
    cout <<sum << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    int totalCost = 0, minPrice = 1e9;
    for (int i = 0; i < n; ++i) {
        int amount, price; cin >> amount >> price;
        minPrice = min(minPrice, price);
        totalCost += minPrice * amount;
    }
    cout << totalCost << endl;
    return 0;
}

using namespace std;
http://codeforces.com/problemset/problem/615/A
// A. Bulbs
bool arr[101] = {false};
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        for (int j = 0; j < x; ++j) {
            int y; cin >> y;
            arr[y] = true;
        }
    }
    bool all_on = true;
    for (int i = 1; i <= m; ++i) {
        if (!arr[i]) {
            all_on = false;
            break;
        }
    }
    cout << (all_on ? "YES" : "NO") << endl;
    return 0;
}
using namespace std;
bool arr[101];
int main(){
    int n, m; cin >> n >> m;
    bool flag = true;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 0; j < x; j++){
            int y; cin >> y;
            arr[y - 1] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        if(!arr[i]) flag = false;
    }
    if(flag) cout << "Yes";
    else cout << "No";
    return 0;
}
using namespace std;
// problemset/problem/617/A
// A. Elephant
int main(){
    int n; cin >> n;
    int res = (n % 5 == 0) ? n / 5 : (n / 5) + 1;
    cout << res;
}
http://codeforces.com/problemset/problem/617/A
// Elephant
using namespace std;
int main(){
    int steps; cin >> steps;
    int ctr, flag = 1, output = 0;
    if(steps < 5)    cout << 1;
    else {
        if(steps % 5 == 0)    cout << steps / 5;
        else if(steps > 5 && steps % 5 != 0)    cout << (steps / 5) + 1;
    }
}
using namespace std;
int main() {
    int steps; cin >> steps;
    int moves = (steps + 4) / 5;
    cout << moves << endl;
}
using namespace std;
https://codeforces.com/contest/672/problem/A
// A. Summer Camp
int main() {
    int n; cin >> n;
    string sequence;
    for (int i = 1; sequence.length() < n; ++i) 
        sequence += to_string(i);
    cout << sequence[n - 1] << endl;
    return 0;
}
using namespace std;
int main() {
	int n; cin >> n;
	string s = "";
	for(int i = 1; i <= 1000; i++)
		s += to_string(i);
	cout << s[n - 1];
}
using namespace std;
// A. Vanya and Fence
// problemset/problem/677/A
int main(){
    int n, h; cin >> n >> h;
    int w = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > h) w += 2;
        else w += 1;
    }
    cout << w;
}
using namespace std;
http://codeforces.com/contest/677/problem/A
// A. Vanya and Fence
int main() {
	int n, h; cin >> n >> h;
	int width = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    if(x > h) width += 2;
	    else width += 1;
	}
	cout << width;
	return 0;
}
using namespace std;
http://codeforces.com/contest/680/problem/B
// Bear and Finding
int main() {
    int n, a, counter = 0; cin >> n >> a;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    a--; // Convert to 0-based index
    if (arr[a]) counter++; // Count criminal at initial position
    for (int i = 1; i < n; i++) {
        int left = a - i;
        int right = a + i;
        bool leftValid = (left >= 0);
        bool rightValid = (right < n);
        if (leftValid && rightValid) {
            if (arr[left] && arr[right]) counter += 2;
        else if (leftValid && arr[left]) 
            counter++;
        else if (rightValid && arr[right]) 
            counter++;
    }
    cout << counter << endl;
}
using namespace std;
int main() {
	int n, a, counter = 0; cin >> n >> a;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	--a;
	if(arr[a]) ++counter;
    for(int i = 1; i < n; i++){
	    int right, left;
		right = a + i;
		left = a - i;
		if(left >= 0 || right < n){
		    if(left >= 0 && right < n){
			    if(arr[right]&&arr[left]) counter += 2;
			}
			else if(left >= 0){
			    if(arr[left]) ++counter;
			}
			else if(right < n){
		        if(arr[right]) ++counter;
			}
		}
	}
	cout << counter;
}
http://codeforces.com/contest/686/problem/A
// A. Free Ice Cream
using namespace std;
int main() {
	int n, x; cin >> n >> x;
	int child = 0;
	for(int i = 0; i < n; i++){
	    char sign;
	    int d; cin >> sign >> d;
	    cin.ignore();
	    if(sign == '-'){
	        if(d > x)    child += 1;
	        else    x -= d;
	    }
	    else    x += d;
	}
	cout << x << " " << child;
}
using namespace std;
int main() {
    int n, x, distressedChildren = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        char op;
        long long amount;
        cin >> op >> amount;
        if (op == '+')    x += amount;
        else { // op == '-'
            if (x >= amount)    x -= amount;
            else    distressedChildren++;
        }
    }
    cout << x << " " << distressedChildren << endl;
}
using namespace std;
http://codeforces.com/contest/688/problem/A
// 688A. Opponents
int main() {
    int n, d; cin >> n >> d;
    int maxConsecutive = 0, currentStreak = 0;
    for (int i = 0; i < d; ++i) {
        string day; cin >> day;
        // If at least one opponent is not available (0 in string)
        if (day.find('0') != string::npos) {
            ++currentStreak;
            maxConsecutive = max(maxConsecutive, currentStreak);
        else  currentStreak = 0;
    }
    cout << maxConsecutive << endl;
}
using namespace std;
int main(){
    int n, d; cin >> n >> d;
    string ref = "";
    for(int i = 0; i < n; i++)
        ref += '1';
    string prv = "";
    int count = 0;
    vector <string> vect1;
    vector <int> vect;
    for(int i = 0; i < d; i++){
        string x; cin >> x;
        if(x == ref){
            vect.push_back(count);
            count = 0;
        }
        else ++count;
    }
    vect.push_back(count);
    int len = vect.size();
    if(len){
        sort(vect.begin(), vect.end());
        cout << vect[vect.size() - 1] << endl;
    }
    else cout << count;
}
using namespace std;
http://codeforces.com/contest/688/problem/B
// 688B. Lovely Palindromes 
int main(){
    string s; cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    cout << s + s2;
}
using namespace std;
http://codeforces.com/problemset/problem/705/A
// 705A. Hulk
int main() {
    int n; cin >> n;
    string s = "";
    for(int i = 0; i < n; i++){
        if(i % 2 == 0 && i != n - 1)
            s += "I hate that ";
        else if(i % 2 == 1 && i != n - 1)
            s += "I love that ";
        else if(i % 2 == 0)
            s += "I hate ";
        if(i % 2 == 1)
            s += "I love ";
    }
    s += "it";
    cout << s;
 	return 0;
}
using namespace std;
// A. Brain's Photos
// problemset/problem/707/A _ Brain has a photo represented as an n × m matrix, where each cell contains a letter representing a pixel's color.
// Colors in the photo: Black-and-white colors: 'W' (white), 'G' (grey), 'B' (black)
//Colored colors: 'C' (cyan), 'M' (magenta), 'Y' (yellow) Check if the photo is black-and-white or colored
int main(){
    int n, m; cin >> n >> m;
    char arr[n][m];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * m; j++)
            cin >> arr[i][j];
    }
    int flag = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * m; j++){
            if(arr[i][j] == 'C' || arr[i][j] == 'Y' || arr[i][j] == 'M')
                flag = 1;
        }
    }
    (flag == 0) ? printf("#Black&White\n") : printf("#Color\n");
}
http://codeforces.com/problemset/problem/707/A
// Brain's_Photos
using namespace std;
int main() {
	int m, k; cin >> m >> k;
	int count = 0;
	string arr[m][k];
	for(int i = 0; i < m; i++){
	    for(int j = 0; j < k; j++)
	        cin >> arr[i][j];
	}
    for(int i = 0; i < m; i++){
	    for(int j = 0; j < k; j++){
	        if(arr[i][j] == "C" || arr[i][j] == "M" || arr[i][j] == "Y")    ++count;
	    }
	}
	cout << (count > 0) ? "#Color" : "#Black&White";
}
using namespace std;
int main() {
    int m, n; cin >> m >> n;
    bool isColor = false;
    for (int i = 0; i < m * n; ++i) {
        string pixel; cin >> pixel;
        if (pixel == "C" || pixel == "M" || pixel == "Y")    isColor = true;
    }
    if (isColor)    cout << "#Color" << endl;
    else    cout << "#Black&White" << endl;
}
http://codeforces.com/contest/709/problem/A
// Juicer
using namespace std;
int main() {
	int n, b, d; cin >> n >> b >> d;
	int sum = 0, dtimes = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    if(x <= b)    sum += x;
	    if(sum > d){
	        dtimes++; sum = 0;
	    }
	}
	cout << dtimes;
}
using namespace std;
http://codeforces.com/problemset/problem/723/A
// A. The_New_Year_Meeting_Friends.cpp
int main() {
    int arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr + 3);
    cout << arr[2] - arr[0];
}
http://codeforces.com/contest/731/problem/A
// Night_at_the_Museum.cpp
using namespace std;
int clockwise(char first, char last){
	int var = (int)last - first;
		while(var < 0)    var += 26;
	return var;
}
int counterclockwise(char first, char last){
	int var = (int)first - last;
	while(var < 0)    var += 26;
    return var;
}
int main() {
	string s; cin >> s;
	int moves = 0;
	char start = 'a', end;
	int len = s.length();
	for(int i = 0; i < len; i++){
	    end = s[i];
        moves += min(clockwise(start, end), counterclockwise(start, end));
			start = end;
	}
	cout << moves;
}
using namespace std;
int main() {
    string s; cin >> s;
    char current = 'a';
    int total_moves = 0;
    for (char target : s) {
        int diff = abs(target - current);
        total_moves += min(diff, 26 - diff);
        current = target;
    }
    cout << total_moves << endl;
    return 0;
}

using namespace std;
http://codeforces.com/contest/732/problem/A
// A. Buy a Shovel
int main() {
	int value = 0, priceMade = 0;
	int k, r; cin >> k >> r;
	bool flag = 1;
	while(flag){
        if((priceMade % 10 == 0 && priceMade != 0) || priceMade % 10 == r) break;
        ++value;
        priceMade += k;
	}
	cout << value;
}
using namespace std;
int main() {
    int k, r; cin >> k >> r;
    int shovels = 1;
    while (true) {
        int total = k * shovels;
        if (total % 10 == 0 || total % 10 == r) {
            cout << shovels << endl;
            break;
        }
        ++shovels;
    }
}
http://codeforces.com/contest/732/problem/A
// Buy_A_Shovel
using namespace std;
int main() {
    int k, r; cin >> k >> r;
    int val = 1;
    int cost = val * k;
    while(true){
        if((cost - r) % 10 == 0 || cost % 10 == 0)    break;
        else    ++val;
    }
    cout << val;
}
using namespace std;
int main() {
    int k, r; cin >> k >> r;
    for (int i = 1; i <= 10; ++i) {
        int cost = i * k;
        if (cost % 10 == 0 || cost % 10 == r) {
            cout << i << endl;
            break;
        }
    }
}

using namespace std;
https://codeforces.com/contest/734/problem/B
// 734B. Anton and Digits
int main(){
    int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
    int num256 = min(k2, min(k6, k5));
    int rem = k2 - num256;
	int num32 = min(rem, k3);
	cout << 256 * (num256 + 32) * num32;
	
}
using namespace std;
int main() {
    int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
    // Count how many 256s can be made using 2, 5, and 6
    int count256 = min({k2, k5, k6});
    k2 -= count256;
    // Count how many 32s can be made using remaining 2s and available 3s
    int count32 = min(k2, k3);
    long long total = 256LL * count256 + 32LL * count32;
    cout << total << '\n';
    return 0;
}
https://codeforces.com/problemset/problem/734/A
// Anton_and_Danik.cpp
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int antonWins = count(s.begin(), s.end(), 'A');
    int danikWins = n - antonWins;
    if (antonWins > danikWins)    cout << "Anton";
    else if (danikWins > antonWins)    cout << "Danik";
    else    cout << "Friendship";
}
using namespace std;
int main() {
	int n; cin >> n;
	string s; cin >> s;
	int x = count(s.begin(), s.end(), 'A');
	int y = count(s.begin(), s.end(), 'D');
	if(x>y)
		cout<<"Anton";
	else if(y>x)
		cout<<"Danik";
	else if(x==y){
		cout<<"Friendship";
	}
	if(x > y)    cout << "Anton";
	else(y > x)    cout << "Danik";
	else if(x == y)    cout << "Friendship";
}
using namespace std;
http://codeforces.com/contest/746/problem/B
// B. Decoding
int main() {
    int len; cin >> len;
	string s; cin >> s;
	vector <char> vect;
	while(len != 0){
	    if(len % 2 == 1)    vect.push_back(s[0]);
	    else    vect.insert(vect.begin(), s[0]);
	}
	s.erase(0, 1);
	len = s.length();
	for(int i = 0; i < vect.size(); i++)
	    cout << vect[i] << " ";
	return 0;
}
using namespace std;
int main() {
    int len; cin >> len;
    string s; cin >> s;
    deque<char> result;
    for (int i = 0; i < len; ++i) {
        if ((len - i) % 2 == 1)    result.push_back(s[i]);
        else    result.push_front(s[i]);
    }
    for (char ch : result)
        cout << ch;
    return 0;
}
http://codeforces.com/problemset/problem/750/A
// New_Year_and_Hurry.cpp
using namespace std;
int main() {
    int n, k; cin >> n >> k;
	int rest = 240 - k, cnt = 0;
	for(int i = 1; i <= n; i++){
	    if(rest >= i * 5){
	        rest -= i * 5;
	        ++cnt;
	    }
	    else    break;
	}
	cout << cnt;
	return 0;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int remaining_time = 240 - k;
    int solved = 0;
    for (int i = 1; i <= n; ++i) {
        int time_needed = i * 5;
        if (remaining_time >= time_needed) {
            remaining_time -= time_needed;
            ++solved;
        } else    break;
    }
    cout << solved << endl;
    return 0;
}

using namespace std;
https://codeforces.com/problemset/problem/758/A
// 758A - Holiday Of Equality
int main() {
 	int n; cin >> n;
	int arr[n];
	int maxi = 0, res = 0;
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	    maxi = max(arr[i], maxi);
	}
	for(int i = 0; i < n; i++)
	    res += maxi - arr[i];
	cout << res << endl;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    int maxi = 0, answer = 0;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    for (int val : arr)
        answer += (maxi - val);
    cout << answer << endl;
}
using namespace std;
http://codeforces.com/problemset/problem/767/A
// 767 A. Snacktower
bool arr[100001];
int curr = 0;
void print(int x, int y){
	if(x == y){
        for(int i = y; i > 0; i--){
		    if(arr[i]) {
		        cout << i << " ";
		        arr[i] = 0; curr = i - 1;
		    }
		    else    break;
        }
	}
}
int main(){
    int n; cin >> n;
    curr = n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[x] = 1;
        print(x, curr);
    }
}
using namespace std;
const int MAXN = 100001;
bool present[MAXN];
void printTower(int& curr) {
    while (curr > 0 && present[curr]) {
        cout << curr << " ";
        present[curr] = false;
        --curr;
    }
    cout << "\n";
}
int main() {
    int n; cin >> n;
    int curr = n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        present[x] = true;
        printTower(curr);
    }
}
using namespace std;
http://codeforces.com/contest/768/problem/A
// 768A - Oath of the Night's Watch
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int minCount = upper_bound(arr.begin(), arr.end(), arr[0]) - arr.begin();
    int maxCount = arr.end() - lower_bound(arr.begin(), arr.end(), arr[n - 1]);
    int result = n - minCount - maxCount;
    cout << (result > 0 ? result : 0) << endl;
}
using namespace std;
int main(){
	int n; cin >> n;
	int counter = 0;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	/*counter = (lower_bound(arr, arr + n, arr[n - 1]) - arr) - (upper_bound(arr, arr + n, arr[0]) - arr);
	 if(counter > 0)
	     cout << counter;
	 else
		 cout << 0;*/
	for(int i = 0; i < n; i++){
	if(arr[i] > arr[0] && arr[i] < arr[n - 1])
	    counter++;
	 cout << counter;
}
using namespace std;
http://codeforces.com/contest/768/problem/A
// A. Oath of the Night's Watch
int main() {
	int n; cin >> n;
	vector <int> se;
	int res = 0;
	for(int i = 0; i < n; i++){
	    int x; cin >> x;
	    se.push_back(x);
	}
	sort(se.begin(), se.end());
	int min = se[0], max = se[n - 1];
	for(int i = 0; i < n; i++){
	    if(se[i] > min && se[i] < max)    res++;
	}
	cout << res;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector <int> se(n);
    for (int i = 0; i < n; ++i)
        cin >> se[i];
    sort(se.begin(), se.end());
    int minVal = se.front();
    int maxVal = se.back();
    int answer = 0;
    for (int x : se) {
        if (x > minVal && x < maxVal) {
            ++answer;
        }
    }
    cout << answer << endl;
    return 0;
}
using namespace std;
https://codeforces.com/contest/770/problem/A
// 770A. New Password
int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    string res = "";
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++)
        res += s[i % k];
    cout << res;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string password;
    for (int i = 0; i < n; ++i)
        password += alphabet[i % k];
    cout << password << endl;
    return 0;
}
http://codeforces.com/contest/770/problem/A
// New_Password.cpp
using namespace std;
int main() {
	string s, s2="abcdefghijklmnopqrstuvwxyz";
	int n, k; cin >> n >> k;
	for(int i = 0; i < k; i++)    s += s2[i];
	s2.erase(0, k);
	int i = s.length();
	for(int j = 0; j < n; i++, j++){
	    s += s[j];
	    if(j == k)    j = 0;
	}
	cout << s;
}
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    string base = "abcdefghijklmnopqrstuvwxyz";
    string pattern = base.substr(0, k);
    string result;
    for (int i = 0; i < n; ++i)
        result += pattern[i % k];
    cout << result << endl;
}

using namespace std;
https://codeforces.com/problemset/problem/785/A
// 785A. Anton and Polyhedrons
int main() {
    int n; cin >> n;
    map <string, int> mp;
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"]=8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    int sum = 0;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        sum += mp[str];
    }
    cout << sum;
}
using namespace std;
int main() {
    int n; cin >> n;
    map<string, int> faceCount = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };
    long long totalFaces = 0;
    for (int i = 0; i < n; ++i) {
        string polyhedron; cin >> polyhedron;
        totalFaces += faceCount[polyhedron];
    }
    cout << totalFaces << endl;
    return 0;
}
http://codeforces.com/contest/791/problem/A
// A. Bear and Big Brother
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	int count = 0;
	while(a < b || a == b){
	    ++count;
	    a *= 3; b *= 2;
	}
	cout << count;
	return 0;
}
http://codeforces.com/contest/799/problem/A
// Carrot_Cakes.cpp
using namespace std;
int main() {
	int n, k, t, d; cin >> n >> k >> t >> d;
	int groups = (n + k - 1) / k;
	int oven1 = 0, oven2 = d;
	for(int i = 0; i < groups; i++){
	    if(oven1 <= oven2)    oven1 += t;
	    else    oven2 += t;
	}
	if(max(oven1, oven2) < groups * t)    cout << "Yes";
	else    cout << "No";
	return 0;
}
using namespace std;
int main() {
    int n, t, k, d; cin >> n >> t >> k >> d;
    int singleOvenTime = ((n + k - 1) / k) * t;
    // If the second oven is built and starts working at time d,
    // check if two ovens working together can finish earlier
    if (d >= singleOvenTime) {
        // Oven is built after or when baking is done with one oven, so no gain
        cout << "NO" << endl;
    } else {
        // In time d, the first oven can bake floor(d / t) batches
        int cakesBeforeSecondOven = (d / t) * k;
        // Remaining cakes after second oven is ready
        int remainingCakes = n - cakesBeforeSecondOven;
        // If remaining cakes can be baked in less than singleOvenTime, print YES
        if (remainingCakes > 0 && (2 * t) < singleOvenTime)
            cout << "YES" << endl;
        else if (cakesBeforeSecondOven < n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
http://codeforces.com/contest/807/problem/A
// 807-A Is it rated
using namespace std;
int main() {
	int n; cin >> n;
	int counter = 0, counter2 = 0;
	int arr[n], arr2[n], arr3[n];
	for(int i = 0; i < n; i++){
	    int x, y; cin >> x >> y;
	    cin.ignore();
	    arr[i] = x; arr2[i] = y; arr3[i] = y;
	}
	for(int i = 0; i < n; i++){
	    if(arr[i] == arr2[i])    ++counter;
	}
	sort(arr2, arr2 + n);
	for(int i = n - 1, j = 0; i >= 0; i--, j++){
	    if(arr2[i] == arr3[j])    ++counter2;
	}
	if(counter != n)    cout << "rated";
	else if(counter == n && counter2 == n)    cout << "maybe";
	else    cout << "unrated";
 	return 0;
}
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> before(n), after(n);
    bool isRated = false;
    bool isSorted = true;
    for (int i = 0; i < n; ++i) {
        cin >> before[i] >> after[i];
        if (before[i] != after[i])    isRated = true;
        if (i > 0 && after[i] > after[i - 1])    isSorted = false;
    }
    if (isRated)    cout << "rated" << endl;
    else if (!isSorted)    cout << "unrated" << endl;
    else    cout << "maybe" << endl;
}

using namespace std;
http://codeforces.com/contest/828/problem/A
// Restaurant.cpp
int main() {
    int n, single_tables, double_tables;
    cin >> n >> single_tables >> double_tables;
    int half_occupied = 0; // number of double tables with one person already
    int rejected = 0;
    for (int i = 0; i < n; ++i) {
        int customer_type; cin >> customer_type;
        if (customer_type == 1) {
            if (single_tables > 0)
                single_tables--;
            else if (double_tables > 0) {
                double_tables--;
                half_occupied++;
            } else if (half_occupied > 0)
                half_occupied--;
            else
                rejected++;
        } else if (customer_type == 2) {
            if (double_tables > 0)
                double_tables--;
            else
                rejected += 2;
        }
    }
    cout << rejected << endl;
}
using namespace std;
int main(){
    int n, a, b; cin >> n >> a >> b;
	int bow = 0, people = 0;
	for(int i = 0; i < n; i++){
		int x; cin >>x;
		if(x == 1){
			if(a > 0)	a--;
			else{
				if(b > 0) {
					b--;
					bow++;
				}
				else if(bow > 0)    bow--;
				else    people++;
			}
		}
		else if(x == 2){
			if(b > 0)    b--;
			else    people += 2;
		}
	}
	cout << people;
}
http://codeforces.com/contest/831/problem/B
// Keyboard_Layouts.cpp
using namespace std;
int main(){
    string s, s2, trg; cin >> s >> s2 >> trg;
    string res = "";
    int len = trg.length();
	for(int i = 0; i < len; i++){
	    if(isupper(trg[i])){
	        trg[i] = tolower(trg[i]);
	        int idx = s.find(trg[i]);
	        res += toupper(s2[idx]);
	    }
	    else if(islower(trg[i])){
	        int idx = s.find(trg[i]);
	        res += s2[idx];
	    }
	    else    res += trg[i];
	}
	cout << res;
}
using namespace std;
int main() {
    string layout1, layout2, text;
    cin >> layout1 >> layout2 >> text;
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            bool isUpper = isupper(ch);
            char lowerCh = tolower(ch);
            size_t index = layout1.find(lowerCh);
            char mappedChar = layout2[index];
            result += isUpper ? toupper(mappedChar) : mappedChar;
        } else {
            result += ch;
        }
    }
    cout << result << endl;
    return 0;
}

http://codeforces.com/contest/844/problem/0
// A. Diversity
using namespace std;
int main() {
	string s; cin >> s;
	int n; cin >> n;
	int len = s.length();
	set <char> sa;
	for(int i = 0; i < len; i++)    sa.insert(s[i]);
	if(len < n)    cout << "impossible";
	else {
	    int size2 = sa.size();
	    if(size2 >= n)    cout << "0";
	    else    cout << n - size2;
	}
}
using namespace std;
int main() {
    string s; cin >> s;
    int n; cin >> n;
    int len = s.length();
    set<char> uniqueChars(s.begin(), s.end());
    if (len < n)    cout << "impossible" << endl;
    else {
        int distinctCount = uniqueChars.size();
        cout << max(0, n - distinctCount) << endl;
    }
}
http://codeforces.com/problemset/problem/854/A
// A. Fraction
using namespace std;
int main() {
    int n; cin >> n;
    int a = 0, b = 0;
    int maxa = 1;
    int z = n >> 1;
    for(int i = 1; i < z + 1; i++){
        bool flag = 1;
        a = i; b = n - a;
        for(int j = 2; j <= a; j++){
            if(a % j == 0 && b % j == 0)    flag = 0;
        }
        if(flag)    maxa = max(a, maxa);
    }
    cout << maxa << " " << n - maxa;
}
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b; a = t;
    }
    return a;
}
int main() {
    int n; cin >> n;
    int maxA = 1;
    for (int a = 1; a <= n / 2; ++a) {
        int b = n - a;
        if (gcd(a, b) == 1)    maxA = a;
    }
    cout << maxA << " " << n - maxA << endl;
}
http://codeforces.com/problemset/problem/869/A
// 869A. The Artful Expedient
using namespace std;
const int N = 1000000;
int freq[N] = {};
int main(){
    int n; cin >> n;
    int cnt = 0, arr[n], arr2[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ++freq[arr[i]];
    }
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
        ++freq[arr2[i]];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(freq[arr[i] ^ arr[j]])    ++cnt;
        }
    }
    if(cnt % 2 == 0)    cout << "karen";
    else    cout << "koyomi";
}
using namespace std;
int main() {
    int n; cin >> n;
    int a[n], b[n];
    unordered_set<int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        freq.insert(b[i]);
    }
    int count = 0;
    // Count pairs (i, j) where a[i] ^ b[j] exists in input
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (freq.count(a[i] ^ b[j]))
                ++count;
    cout << (count % 2 == 0 ? "Karen" : "Koyomi") << endl;
}
using namespace std;
http://codeforces.com/contest/876/problem/A
// A. Trip For Meal
int main() {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    int x = min(a, min(b, c));
    if(x == a || x == b || n == 1)    cout << (n - 1) * min(a, b);
    else    cout << min(a, b) + c * (n - 2);
}
using namespace std;
int main() {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    // If only one city, no travel needed
    if (n == 1)    cout << 0 << endl;
    else if (n == 2) {
        // Only one move needed, choose min of a and b
        cout << min(a, b) << endl;
    else {
        // First move: min of a or b
        // Remaining (n-2) moves: always take the cheaper round trip (min(a, b)) or two-step move (c)
        cout << min(a, b) + (n - 2) * min({a, b, c}) << endl;
    }
}
https://codeforces.com/contest/879/problem/A
// 879A. Borya's Diagnosis
using namespace std;
long long theday(int s ,int d, int curday){
    int day = 0, i = 0;
	while(true){
	    if((s + (i * d)) > curday){
	        day = s + i * d;
	        break;
	    }
	    ++i;
	}
	return day;
}
int main() {
    int n; cin >> n;
    int curday = 0;
    int arr[n + 1] = {};
    for(int i = 1; i <= n; i++){
        int s, d; cin >> s >> d;
        if(n > 1){
            curday = theday(s, d, curday);
            arr[i] = curday;
        }
        else    arr[i] = s;
    }
    cout << arr[n];
}
using namespace std;
long long getNextAvailableDay(int s, int d, long long curDay) {
    if (s > curDay) return s;
    long long i = (curDay - s) / d + 1;
    return s + i * d;
}
int main() {
    int n; cin >> n;
    int curDay = 0;
    for (int i = 0; i < n; ++i) {
        int s, d; cin >> s >> d;
        curDay = getNextAvailableDay(s, d, curDay);
    }
    cout << curDay << endl;
}
https://codeforces.com/contest/879/problem/B
// 879B. Table Tennis
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    queue <int> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push(x);
    }
    int winner = q.front();
    q.pop();
    int wins = 0;
    if (k >= n - 1) {
        // The maximum will win eventually
        int maxVal = winner;
        while (!q.empty()) {
            maxVal = max(maxVal, q.front());
            q.pop();
        }
        cout << maxVal << endl;
    } else {
        while (wins < k) {
            long long next = q.front();
            q.pop();
            if (winner > next) {
                ++wins;
                q.push(next);
            } else {
                q.push(winner);
                winner = next;
                wins = 1;
            }
        }
        cout << winner << endl;
    }
}
using namespace std;
int main() {
	 map <int, int> arr;
	 int n, k; cin >> n >> k;
	 int winer = 0;
	 queue <int> q;
	 for(int i = 0; i < n; i++){
	     int c; cin >> c;
	     q.push(c);
	 }
	 winer = q.front();
	 q.pop();
	 int times = 0;
	 if(n > 2){
	     for(int i = 0; i < 1000; i++){
	         int value = q.front();
	         q.pop();
	         if(value > winer){
	             if(times == k)    break;
	             winer = value;
	             times = 1;
	             q.push(winer);
	         }
	         else{
	             q.push(value);
	             ++times;
	             if(times == k)    break;
	         }
	     }
	     cout << winer;
	 }
	 else {
	     int value = q.front();
	     q.pop();
	     winer = max(winer, value);
	     cout << winer;
	 }
}

using namespace std;
// A. Wrong Subtraction
// problemset/problem/977/A?mobile=false
int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        if (n % 10 == 0) n /= 10;
        else n--;
    }
    cout << n << endl;
}
using namespace std;
// C. Alphabetic Removals
// contest/999/problem/C _From a string remove k characters.try to remove the leftmost 'a' first.
// if 'a' is not left, remove the leftmost 'b'.Continue in alphabetical order ('c', 'd', ..., 'z'),
//Repeat this process exactly k times.After removing k characters, print the remaining string.
int main(){
    int n, k; cin >> n >> k;
    string str; cin >> str;
    vector <int> freq(26, 0);
    for(int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;
    char eliminate = 'a';
    while(k > 0 && eliminate <= 'z'){
        int cnt = min(k, freq[eliminate - 'a']);
        k -= cnt;
        freq[eliminate - 'a'] -= cnt;
        eliminate++;
    }
    int remain[26] = {0};
    for(char ch = 'a'; ch <= 'z'; ch++)
        remain[ch - 'a'] = freq[ch - 'a'];
    for(int i = 0; i < str.size(); i++){
        if(remain[str[i] - 'a'] > 0){
            cout << str[i];
            remain[str[i] - 'a']--;
        }
    }
    //-----//
    int n, k; cin >> n >> k;
    string str; cin >> str;
    map <char, vector <int> > idx;
    for(int i = 0; i < n; i++)
        idx[str[i]].push_back(i);
    map <int, bool> visited;
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(int i = 0; i < idx[ch].size() && k >= 1; i++){
            int ix = idx[ch][i];
            visited[ix] = true; k--;
        }
    }
    for(int i = 0; i < n; i++){
        if(!visited[i])
            cout << str[i];
    }
}
using namespace std;
// A. In Search of an Easy Problem
// contest/1030/problem/A
int main(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
    }
    (sum) ? cout << "HARD" : cout << "EASY";
}
using namespace std;
// problemset/problem/1204/B
// B. Mislove Has Lost an Array
int main(){
    int n, l, r; cin >> n >> l >> r;
    int minsum = 0, maxsum = 0;
    int power = 1;
    for(int i = 1; i <= l; i++){
        minsum += power;
        power *= 2;
    }
    minsum += (n - l) * 1;
    power = 1;
    for(int i = 1; i <= r; i++){
        maxsum += power;
        power *= 2;
    }
    maxsum += (n - r) * (power / 2);
    cout << maxsum << " " << minsum;
}
using namespace std;
// C. Bad Sequence
// contest/1214/problem/C _check if can make a bracket sequence  correct by moving at most 
//one bracket to a different position (without flipping it).correct bracket sequence must:Have equal numbers of ( and ),
//Be balanced.Determine if moving one bracket to a different position can fix the sequence
int main(){
    int n; cin >> n;
    string str; cin >> str;
    stack <char> st;
    for(int i = 0; i < n; i++){
        if(i == 0) st.push(str[i]);
        else{
            if(st.size() >= 1 && st.top() == '(' && str[i] == ')')
                st.pop();
            else st.push(str[i]);
        }
    }
    int open = 0, close = 0;
    while(!st.empty()){
        if(st.top() == '(') open++;
        else close++;
        st.pop();
    }
    ((open == 0 && close == 0) || (open == 1 && close == 1)) ? cout << "Yes" : cout << "No";
}
using namespace std;
// contest/1257/problem/A
// A. Two Rival Students
int main(){
    int t; cin >> t; 
    while(t--){
        int n, x, a, b; cin >> n >> x >> a >> b;
        int curDist = abs(a - b);
        int maxDist = min(n - 1, curDist + x);
    }
    cout << maxDist;
}
using namespace std;
// B. Magic Stick
// contest/1257/problem/B
int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        if(x == 1 && y == 1) cout << "YES\n";
        else if((x == 2 || x == 3) && y < 4) cout << "YES\n";
        else if(x > 3) cout << "YES\n";
        else cout << "No\n";
    }
}
using namespace std;
// problemset/problem/1328/A
// A. Divisibility Problem
int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        if(x % y == 0)
            cout << 0;
        else
            cout << y - (x % y);
    }
}
using namespace std;
// A. Candies and Two Sisters
// problemset/problem/1335/A
int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        if(x > 2){
            if(x & 1) cout << (x >> 1) << "\n";
            else cout << (x >> 1) - 1 << "\n";
        }
        else cout << 0;
    }
}
//https://codeforces.com/problemset/problem/1352/A
// Sum of Round Numbers
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> vec;
        int j = 0;
        while(n > 0){
            if(n % 10){
                int res = pow(10, j);
                res *= n % 10;
                vec.push_back(res);
            }
            n /= 10; j++;
        }
        int len = vec.size();
        cout << len << "\n";
        for(int i = 0; i < len; i++)
            cout << vec[i] << " ";
        cout << "\n";
    }
}
using namespace std;
// https://codeforces.com/problemset/problem/1367/A
// Short Substrings
int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        int len = str.length();
        string res = "";
        for(int i = 0; i < len; i++){
            if(i % 2 == 0)
                res += str[i];
        }
        res += str[len - 1];
        cout << res << "\n";
    }
}
using namespace std;
// https://codeforces.com/problemset/problem/1409/A
// A. Yet Another Two Integers Problem
int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a == b) cout << "0";
        else{
            int diff = abs(a - b);
            int arr[11] = {};
            int res = 0;
            for(int i = 10; i > 0; i--){
                arr[i] = diff / i;
                diff -= arr[i] * i;
                res += arr[i];
            }
            cout << res;
        }
    }
}
using namespace std;
// C. Dominant Piranha
// problemset/problem/1433/C
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], res = -1, mx = 0;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int dup = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] != arr[0]){
                dup = 0;
                break;
                
            }
        }
        if(dup){
            cout << -1;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(arr[i] > mx) mx = arr[i];
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == mx){
                if ((i > 0 && arr[i] > arr[i - 1]) || (i < n - 1 && arr[i] > arr[i + 1])) {
                    res = i + 1;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}
using namespace std;
// problemset/problem/1454/A
// A. Special Permutation
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << n << " ";
        for(int i = 1; i < n; i++)
            cout << i << " ";
        cout << "\n";
    }
}
using namespace std;
// A. Cards for Friends
// contest/1472/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        int w, h, n; cin >> w >> h >> n;
        int cnt = 1;
        while(w % 2 == 0){
            w /= 2; cnt *= 2;
        }
        while(h % 2 == 0){
            h /= 2; cnt *= 2;
        }
        (cnt >= n) ? cout << "Yes\n" : cout << "No\n";
    }
}
using namespace std;
// contest/1475/problem/A 
// A. Odd Divisor
int powerOfTwo(int n){
    return (n & (n - 1)) == 0;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        (powerOfTwo(n)) ? cout << "No\n" : cout << "Yes\n";
    }
    while(t--){
        int i = 2, flag = 0;
        int n; scanf("%d", &n);
        while(i <= n){
            if(n % i == 0 && i % 2 != 0)
                flag = 1;
            i++;
        }
    }
}
using namespace std;
// D. Epic Transformation
// problemset/problem/1506/D
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map <int, int> freq;
        int maxfreq = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            freq[x]++;
            maxfreq = max(maxfreq, freq[x]);
        }
        int rem = n - maxfreq;
        cout << (maxfreq > rem) ? (maxfreq - rem) : n % 2 << "\n";
    }
}
using namespace std;
// A. Review Site
// problemset/problem/1511/A
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int up = 0, down = 0;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++){
            if(arr[i] != 2) up++;
        }
        cout << up << "\n";
    }
}
using namespace std;
// contest/1512/problem/A
// A. Spy Detected
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int maxi = 101, arr[n + 1];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int freq[maxi];
        for(int i = 0; i < maxi; i++)
            freq[i] = 0;
        for(int i = 0; i < n; i++)
            freq[arr[i]]++;
        int idx;
        for(int i = 0; i < n; i++){
            if(freq[arr[i]] == 1){
                idx = i; 
                break;
            }
        }
        cout << idx + 1 << "\n";
    }
}
using namespace std;
// problemset/problem/1553/A
// A. Digits Sum
int main(){
    int t; cin >> t;
    while(t--){
        int n, res; cin >> n;
        if(n % 10 < 9)
            res = n / 10;
        else
            res = (n / 10) + 1;
        cout << res;
    }
}
using namespace std;
// A. Dislike of Threes
// contest/1560/problem/A
int main(){
    int t; cin >> t;
    int res[2001], tmp = 1;
    for(int i = 1; tmp <= 2000; i++){
        if((i % 3 != 0) && (i % 10 != 3))
            res[tmp++] = i;
    }
    while(t--){
        int n; cin >> n;
        cout << res[n];
    }
    /*
    int n, k; cin >> n;
    for(int i = 1; i <= n; i++){
        while(i % 3 == 0 || i % 10 == 3){
            i++; n++;
        }
        k = i;
    }
    cout << k; */
}
using namespace std;
// Permutation Minimization by Deque
// contest/1579/problem/E1 _Given a permutation of size n,need to construct a deque by sequentially adding elements. starting smallest value.
// Before adding each value choose whether to add it to the front or the back of the deque.determine the final order of elements in the deque
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        list <int> lst;
        vector <int> vec(n);
        int i = 0;
        for(int i = 0; i < n; i++)
            cin >> vec[i];
        while(i < n){
            if(i == 0){
                lst.push_back(vec[i]);
                i++;
            }
            else{
                if (vec[i] < lst.front())
                    lst.push_front(vec[i]);
                else
                    lst.push_back(vec[i]);
                i++;
            }
        }
        while (!lst.empty()){
            cout << lst.front() << " ";
            lst.pop_front();
        }
        cout << "\n";
    }
}
using namespace std;
// A. Find Array
// contest/1608/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1){
            cout << 1 << " ";
            continue;
        }
        else{
            for(int i = 2; i <= n + 1; i++)
                cout << i << " ";
        }
        cout << "\n";
    }
}
using namespace std;
//A. Vasya and Coins
// problemset/problem/1660/A
int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a == 0) cout << 1;
        else cout << a + (b * 2) + 1;
    }
}
using namespace std;
// B. Equal Candies
// problemset/problem/1676/B
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], sum = 0, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] < mini)
                mini = arr[i];
        }
        for(int i = 0; i < n; i++)
            sum += arr[i] - mini;
        cout << sum << "\n";
    }
}
using namespace std;
// Eating Queries
//contest/1676/problem/E _Timur has n candies, each with a sugar content a[i]. He will ask q queries, where for each query x[j], 
//determine the minimum number of candies he needs to eat to consume at least x[j] sugar. If it's not possible, return -1
int main(){
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector <int> vec(n);
        for(int i = 0; i < n; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.end(), greater <int> ());
        vector <int> pref(n + 1, 0);
        for(int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + vec[i - 1];
        while(q--){
            int val; cin >> val;
            auto it = lower_bound(pref.begin(), pref.end(), val);
            if(it != pref.end())
                cout << it - pref.begin() << "\n";
            else
                cout << -1 << "\n";
        }
    }
}
using namespace std;
// Minimums and Maximums
//contest/1680/problem/A _calculate the minimum possible number of elements in a array by which range [l1, r1] elements 
// equal to its minimum and [l2, r2] elements in the array equal to its maximum.
int main(){
    int l1, l2, r1, r2, res;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l2 >= l1 && l2 <= r1) res = l2;
    else if(l1 >= l2 && l1 <= r2) res = l1;
    else res = l1 + l2;
    cout << res;
}
using namespace std;
// B. Card Trick
// problemset/problem/1681/B
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int m, sum = 0; cin >> m;
        for(int i = 0; i < m; i++){
            int suf; cin >> suf;
            sum += suf;
        }
        res = sum % n;
        cout << arr[res];
    }
}
using namespace std;
// A. Beat The Odds
// contest/1691/problem/A
int main() {
    int t; cin >> t;
    while (t--) {
        int n, even = 0, odd = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            if (num % 2 == 0) even++;
            else odd++;
        }
        cout << min(even, odd) << endl;
    }
}

using namespace std;
// C. Cypher
// problemset/problem/1703/C
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++){
            int moves; cin >> moves;
            string str; cin >> str;
            for(int j = 0; j < str.size(); j++){
                if(str[j] == 'U')
                    arr[i] = (arr[i] + 9) % 10;
                else if(str[i] == 'D')
                    arr[i] = (arr[i] + 1) % 10;
            }
        }
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
}
using namespace std;
// A. Difference Operations
// problemset/problem/1708/A
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int IsDiv = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] % arr[0] != 0){
                IsDiv = 0;
                break;
            }
        }
        printf(IsDiv ? "Yes" : "No");
    }
}
using namespace std;
// A. Three Doors
// problemset/problem/1709/A
int main(){
    int t; cin >> t;
    while(t--){
        int start; cin >> start;
        int keys[4];
        for(int i = 1; i <= 3; i++)
            cin >> keys[i];
        int first = keys[start];
        int second = (first != 0) ? keys[first] : 0;
        if(first != 0 && second != 0)
            cout << "Yes";
        else
            cout << "No";
    }
}
using namespace std;
// A. Planets
// problemset/problem/1730/A
int main(){
    int t; cin >> t;
    while(t--){
        int num, cost; cin >> num >> cost;
        unordered_map <int, int> freq;
        for(int i = 0; i < num; i++){
            int x; cin >> x;
            freq[x]++;
        }
        int res = 0;
        for(const auto &it : freq)
            res += min(it.second, cost);
        cout << res << "\n";
    }
}
using namespace std;
// problemset/problem/1734/A
// A. Select Three Sticks
void sorti(int *arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sorti(arr, n);
        int res = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            int diff = (arr[i] - arr[i - 1]) + (arr[i + 1] - arr[i]);
            if (diff < res) res = diff;
        }
        cout << res << "\n";
    }
}
using namespace std;
// B. Bright, Nice, Brilliant
// problemset/problem/1734/B  _There has a pyramid with n floors, numbered(1 to n).i-th floor has exactly i rooms.Each room (i, j) has two staircases leading to the two rooms directly below: (i+1, j) and (i+1, j+1).Each room can either have a torch or be empty.
//brightness of a room is the number of torches from which you can reach it using staircases. nice pyramid is one where all rooms in each floor have the same brightness.
//brilliance of a pyramid is the sum of brightness values of the leftmost rooms (1,1), (2,1), ..., (n,1).Fine  a torch arrangement that makes the pyramid nice and maximizes its brilliance.
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                (j > 1 && j < i) ? printf("0") : printf("1");
            }
            printf("\n");
        }
    }
}
// contest/1736/problem/A
// A. Make A Equal to B
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], ray[n];
        int z1 = 0, z2 = 0, o1 = 0, o2 = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 0) z1++;
            else o1++;
        }
        for(int i = 0; i < n; i++){
            cin >> ray[i];
            if(ray[i] == 0) z2++;
            else o2++;
        }
        int res = (z1 - z2 > o1 - o2) ? z1 - z2 : o1 - o2;
        int mismatch = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] != ray[i])
                mismatch++;
        }
        (mismatch < res) ? cout << res : cout << res + 1;
    }
}
using namespace std;
// A. Factorise N+M
// problemset/problem/1740/A?mobile=false
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int m = 2;
        while (is_prime(n + m)) {  
            m++;  
            while (!is_prime(m)) 
                m++;
        }
        cout << m << "\n";
    }/*
    while(t--){
        int n; cin >> n;
        if(n == 1 || n == 2)
            cout << "7\n";
        else if(is_prime(n))
            cout << n + 1 << "\n";
    } */
}
// contest/1741/problem/A
// A. Compare T-Shirt Sizes
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string str, ing; cin >> str >> ing;
        int len = str.length(), gth = ing.length();
        char ch = str[len - 1], ar = ing[gth - 1];
        if (ch == ar) {
            if (ch == 'S') {
                cout << (len > gth ? "<\n" : (len < gth ? ">\n" : "=\n"));
            }else {
                cout << (len > gth ? ">\n" : (len < gth ? "<\n" : "=\n"));
            }
        } else {
            if ((ch == 'L' && (ar == 'M' || ar == 'S')) || (ch == 'M' && ar == 'S'))
                cout << ">\n";
            else cout << "<\n";
        }
    }
}
using namespace std;
// Sum
//problemset/problem/1742/A _given three integers a Determine if one of them is the sum of the other two.
int main(){
    int t; cin >> t;
    while(t--){
        (a + b == c || b + c == a || a + c == b) ? cout << "Yes" : cout << "No";
    }
}
using namespace std;
// problemset/problem/1754/A
// A. Technical Support
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        stack <char> st;
        for(int i = 0; i < n; i++){
            char ch = str[i];
            if(ch == 'Q') st.push(ch);
            else{
                if(!st.empty())
                    st.pop();
            }
        }
        (st.empty()) ? cout << "Yes" : cout << "No";
    }
}
using namespace std;
// B. Kevin and Permutation
// contest/1754/problem/B
int main(){
    int n; cin >> n;
    int x = (n + 1) / 2;
    int y = n;
    for(int i = 1; i <= n / 2; i++){
        cout << x << " " << y << " ";
        x--; y--;
    }
    if(n % 2!= 0) cout << 1 << "\n";
}
using namespace std;
// A. SSeeeeiinngg DDoouubbllee
// contest/1758/problem/A
int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        cout >> str;
        reverse(str.begin(), str.end());
        cout << str;
    }
}
using namespace std;
// Medium Number
//problemset/problem/1760/A _find the medium number among three integers
int medium(int a, int b, int c){
    int maxi = a, mini = a;
    if(b > maxi) maxi = b;
    if(c > maxi) maxi = c;
    if(b < mini) mini = b;
    if(c < mini) mini = c;
    return a + b + c - maxi - mini;
}
int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        cout << medium(a, b, c));
    }
}
using namespace std;
// Koxia and Whiteboards
//contest/1770/problem/A _Kiyora has n whiteboards, each containban integer a[i]. she performs m operations, where each
// they choose any whiteboard and replace its number with b[j] from a given list. determine the maximum possible sum of the numbers 
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        long long sum = 0;
        list <int> lst;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            lst.push_back(x);
            sum += x;
        }
        lst.sort();
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            sum -= lst.front();
            sum += x;
            lst.pop_front();
            lst.push_front(x);
            lst.sort();
        }
        cout << sum << "\n";
    }
}
using namespace std;
// Hayato and School
//contest/1780/problem/A _find three indices in an array such that the sum of the elements at these indices is odd
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> odd, even;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            if(x % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }
        if(odd.size() >= 3){
            cout << "YES\n" << odd[0] << " " << odd[1] << " " << odd[2];
        }
        else if(odd.size() >= 1 && even.size() >= 2)
            cout << "Yes\n" << odd[0] << " " << even[0] << " " << even[1];
        else
            cout << "No";
    }
}
using namespace std;
// Matrix of Differences
// contest/1783/problem/B _Given an n × n matrix filled with integers from 1 to n*n.define its "beauty"
// as the number of unique absolute differences between adjacent elements (horizontally or vertically).
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        list <int> lst;
        for(int i = 1; i <= n * n; i++)
            lst.push_back(i);
        int grid[n][n];
        for(int i = 0; i < n; i++){
            if((i + 1) % 2 != 0){
                for(int j = 0; j < n; j++){
                    if((j + 1) % 2 != 0){
                        grid[i][j] = lst.back();
                        lst.pop_back();
                    }
                    else{
                        grid[i][j] = lst.front();
                        lst.pop_front();
                    }
                }
            }
            else{
                for(int j = n - 1; j >= 0; j--){
                    if((j + 1) % 2 != 0){
                        grid[i][j] = lst.front();
                        lst.pop_front();
                    }
                    else{
                        grid[i][j] = lst.back();
                        lst.pop_back();
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
    }
}
using namespace std;
// problemset/problem/1787/A
// A. Exponential Equation
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 2 == 0)
            cout << n / 2 << " " << 1 << "\n";
        else
            cout << -1 << "\n";
    }
}
using namespace std;
// Polycarp and the Day of Pi
//contest/1790/problem/A _print how many digits of PI will be matched
int main(){
    int t; cin >> t;
    while(t--){
        string PI = "314159265358979323846264338327";
        string str; cin >> str;
        int res = 0;
        for(int i = 0; i < str.size(); i++){
            if(PI[i] == str[i]) res++;
            else break;
        }
        cout << res;
    }
}
using namespace std;
// Teleporters (Easy Version)
// contest/1791/problem/G1 _Given (0 to n) points on a number line ,) each point i teleporter that costs a[i] coins to use. 
//Using a teleporter sends you back to point 0, but each teleporter can be used only once.move left or right on the number line at a cost of 1 coin per unit. 
//Starting at 0 with c coins, determine the maximum number of teleporters you can use.
int main(){
    int t; cin >> t;
    while(t--){
        int n, cost; cin >> n >> cost;
        vector <int> vec(n);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            vec[i] = i + 1 + x;
        }
        sort(vec.begin(), vec.end());
        int res = 0;
        for(int i = 0; i < vec.size(); i++){
            if(cost < vec[i])
                break;
            cost -= vec[i];
            res++;
        }
        cout << res << "\n";
    }
}
using namespace std;
// A. Two Towers
// problemset/problem/1795/A
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int dup1 = 0, dup2 = 0;
        string str, ing; cin >> str >> ing;
        for(int i = 0; i < m - 1; i++){
            if(str[i] == str[i + 1])
                dup1++;
        }
        for(int i = 0; i < n - 1; i++){
            if(ing[i] == ing[i + 1])
                dup2++;
        }
        if(dup1 == 0 && dup2 == 0) cout << "Yes\n";
        else if(dup1 >= 1 && dup2 >= 1) cout << "No\n";
        else if(dup1 >= 2 || dup2 >= 2) cout << "No\n";
        else{
            if(str[m - 1] == ing[n - 1]) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}
using namespace std;
// Array Coloring
//problemset/problem/1857/A _determine whether it is possible to color all its elements in two colors in such a way that the sums 
//of the elements of both colors have the same parity and each color has at least one element colored.
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], sum = 0;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++)
            sum += arr[i];
        (sum % 2 == 0) ? cout << "Yes\n" : cout << "No\n"
    }
}
