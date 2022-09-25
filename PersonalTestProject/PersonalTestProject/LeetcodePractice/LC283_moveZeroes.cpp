#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        for (fast; fast<nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for (slow; slow<nums.size(); slow++) {
            nums[slow] = 0;
        }
    }
};