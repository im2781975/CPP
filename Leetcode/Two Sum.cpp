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
