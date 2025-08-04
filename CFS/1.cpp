http://codeforces.com/contest/9/problem/A
// Die Roll
using namespace std;
int main(){
    int y, w; cin >> y >> w;
    int maxi = max(y, w);
    int q = (6 - maxi) + 1;
    if(q == 1)    cout << "1/6" << endl;
    else if(q == 2)    cout << "1/3" << endl;
    else if(q == 3)    cout << "1/2" << endl;
    else if(q == 4)    cout << "2/3" << endl;
    else if(q == 5)    cout << "5/6" << endl;
    else if(q == 6)    cout << "1/1" << endl;
    else if(q == 0)    cout << "0/1" << endl; /*
    string arr[] = {"1/6", "1/3", "1/2", "2/3", "5/6", "1/1", "0/1"};
    cout << arr[maxi] << endl; */
}
