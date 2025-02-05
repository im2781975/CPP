using namespace std;
//wildcard
int main(){
    string str; int n;
    cin >> str >> n;
    vector <string> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    bool start = (str[0] == '*');
    bool end = (str[str.size() - 1] == '*');
    if(start && !end){
        string suffix = str.substr(1);
        for (const auto &word : vec){
            if (word.size() >= suffix.size() &&
                word.compare(word.size() - suffix.size(), suffix.size(), suffix) == 0)
                cout << word << "\n";
        }
    }
    else if(!start && end){
        string prefix = str.substr(0, str.size() - 1);
        for (const auto &word : vec) {
            if (word.size() >= prefix.size() &&
                word.compare(0, prefix.size(), prefix) == 0)
                cout << word << "\n";
        }
    }
    else{
        for (const auto &word : vec)
            cout << word << "\n";
    }
}
using namespace std;
// arrange a string characters in a square grid, and then prints them in a zigzag pattern (
int main(){
    string str; cin >> str;
    int len = ceil(sqrt(str.length()));
    while(str.length() < len * len)
        str += '.';
    for(int i = 0; i < len; i++){
        if(i % 2 == 0){
            for(int j = i * len; j < (i + 1) * len; j++)
                cout << str[j] << " ";
        }
        else{
            for(int j = (i + 1) * len - 1; j > i * len - 1; j--)
                cout << str[j] << " ";
        }
        cout << "\n";
    }
}
using namespace std;
//wildcard
int main(){
    int n; cin >> n;
    string str; cin >> str;
    int dv = str.find("*");
    string first = str.substr(0, dv);
    string sec = str.substr(dv + 1);
    int len = sec.length();
    vector <string> tmp;
    for(int i = 0; i < n; i++){
        string ing; cin >> ing;
        if(str.length() - 1 > ing.length())
            continue;
        string c = ing.substr(0, dv);
        string d = ing.substr(ing.length() - len);
        if(first == c && sec == d)
            tmp.push_back(ing);
    }
    for(int i = 0; i < tmp.size(); i++)
        cout << tmp[i] << " ";
}
