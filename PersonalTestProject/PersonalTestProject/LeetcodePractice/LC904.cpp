#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = INT32_MIN;
        int left = 0, right = 0;
        unordered_map<int, int> basket;

        for (; right<fruits.size(); right++) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
    
    int main() {
        vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
        Solution *obj = new Solution();
        cout << obj->totalFruit(fruits) << endl;
        return 0;
    }

};

