//1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        classfor(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    return{i, j};
                    break;
                }
            }
        }
        return {};
    }
};
//860.Lemonade
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        iclassnt n = bills.size() ;
        int cnt5 = 0, cnt10 = 0, cnt20 = 0;
        for(int i = 0; i < n; i++){
            if(cnt5 < 0) return false;
            if(cnt5 < 0 && (cnt10 <= 0 || cnt20 <= 0)) return false;
            if(bills[i] == 5)
                cnt5 += 1;
            else if(bills[i] == 10){
                cnt5 -= 1;
                cnt10 += 1;
            }
            else if(bills[i] == 20){
                cnt20 += 1;
                if(cnt5 != 0 && cnt10 != 0){
                    cnt5 -= 1;
                    cnt10 -= 1;
                }
                else if(cnt10 == 0 && cnt5 >= 3)
                    cnt5 -= 3;
                else 
                    return false;
            }
        }
        if(cnt5 < 0) return false;
        if(cnt5 < 0 && (cnt10 <= 0 || cnt20 <= 0)) return false;
    return true;
    }
};
// 852.peak index and mountain array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
        }
        return 0;
    }
};
https://leetcode.com/problems/add-to-array-form-of-integer/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
    unsigned long long tmp = k;
    while(i >= 0 || tmp > 0){
        if(i >= 0) {
            tmp += num[i];
            num[i] = tmp % 10;
            tmp /= 10; i--;
        }
        else {
            num.insert(num.begin(), tmp % 10);
            tmp /= 10;
        }
    }
    return num;
    }
};
https://leetcode.com/problems/diagonal-traverse
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(); 
        int n = mat[0].size();
        vector <int> res;
        for(int d = 0; d < m + n - 1; d++){
            int r = (d < n) ? 0 : d - n + 1;
            int c = (d < n) ? d : n - 1;
            vector <int> tmp;
            while(r < m && c >= 0) {
                tmp.push_back(mat[r][c]);
                r++; c--;
            }
            if(d % 2 == 0)
                reverse(tmp.begin(), tmp.end());
            for(int x : tmp)
                res.push_back(x);
        }
        return res;
    }
};
