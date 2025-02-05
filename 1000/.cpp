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
