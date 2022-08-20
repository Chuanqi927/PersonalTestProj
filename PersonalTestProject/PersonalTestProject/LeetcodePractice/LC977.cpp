#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int leftPtr = 0, rightPtr = nums.size()-1;
        vector<int> newArr(nums.size());
        for (int i=nums.size()-1; i>=0; i--) {
            if (abs(nums[leftPtr]) > abs(nums[rightPtr])) {
                newArr[i] = nums[leftPtr] * nums[leftPtr];
                leftPtr++;
            }
            else {
                newArr[i] = nums[rightPtr] * nums[rightPtr];
                rightPtr--;
            }
        }
        return newArr;
    }
    
    int main () {
        vector<int> nums;
        nums.push_back(-4);
        nums.push_back(-1);
        nums.push_back(0);
        nums.push_back(3);
        nums.push_back(10);

        Solution *obj = new Solution();
        vector<int> ret = obj->sortedSquares(nums);

        for (int num : ret) {
            std::cout << num << std::endl;
        }
        return 0;
    }
};


