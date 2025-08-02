http://codeforces.com/gym/101575/problem/0
// A. Beautiful Necklace.cpp
using namespace std;
bool isbeautiful(string s){
	int n = s.length();
	char y = s[0];
	int cou = count(s.begin(), s.end(), y);
	if(n == cou)    return 1;
	else    return 0;
}
int main(){
    int n; cin >> n;
    int counter = 0, maxlength = 0;
    for(int i = 0; i < n; i++){
	    string s; cin >> s;
	    if(isbeautiful(s)){
	        ++counter;
	        int x = s.length();
	        maxlength = max(maxlength, x);
	    }
	    if(counter)    cout << maxlength;
	    else    cout << 0;
    }
}
using namespace std;
// Check if all characters in the string are the same
bool isBeautiful(const string &s) {
    return count(s.begin(), s.end(), s[0]) == (int)s.size();
}
int main() {
    int n; cin >> n;
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (isBeautiful(s))
            maxLen = max(maxLen, (int)s.size());
    }
    cout << maxLen << "\n";
}
