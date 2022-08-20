#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = (int)nums.size();
        if (size <= 1) return size;

        int oldIndex = 1;
        int newIndex = 0;
        for (oldIndex; oldIndex<size; oldIndex++) {
            if (nums[oldIndex] != nums[newIndex]) {
                newIndex++;
                nums[newIndex] = nums[oldIndex];
            }
        }

        // the last two nodes can not be the same due to problem description
        return newIndex+1;
    }
};