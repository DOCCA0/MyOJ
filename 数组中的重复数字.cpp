#include <vector>
#include <set>
using namespace std;
class Solution {
    set<int>s;
    vector<int >res;
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])){
                return nums[i];
            }else{
                s.insert(nums[i]);
            }
        }
    }
};