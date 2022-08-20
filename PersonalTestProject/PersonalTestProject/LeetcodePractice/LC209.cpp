#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT32_MAX;
        int left = 0, right = 0;
        int sum = 0;
        for (right; right<nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right-left+1);
                sum -= nums[left];
                left++;
            }   
        }
        return (ans==INT32_MAX) ? 0 : ans;
    }
};