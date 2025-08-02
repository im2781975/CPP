http://codeforces.com/gym/101575/problem/B
// B. Merge Grids.cpp
using namespace std;
int main(){
    char arr[3][3], arr2[3][3], result[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
    string s; getline(cin, s);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cin >> arr2[i][j];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            char mat1 = arr[i][j];
		    char mat2 = arr2[i][j];
		    if(mat1 == mat2)    result[i][j] = mat1;
            else if(mat1 != mat2 && mat1 == '.')    result[i][j]=mat2;
		    else if(mat1 != mat2 && mat2 == '.')    result[i][j]=mat1;
		    else    result[i][j] = 'X';
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}
using namespace std;
int main() {
    char a[3][3], b[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> b[i][j];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c1 = a[i][j];
            char c2 = b[i][j];
            if (c1 == c2) {
                cout << c1;
            } else if (c1 == '.') {
                cout << c2;
            } else if (c2 == '.') {
                cout << c1;
            } else {
                cout << 'X';
            }
        }
        cout << "\n";
    }
}

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
