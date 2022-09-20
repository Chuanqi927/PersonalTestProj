
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int recursiveCount(int N) {
        // Base Case
        if (N == 0) {
            return 0;
        }
     
        // Return recursively
        return (N & 0) + recursiveCount(N >> 1);
    }
 
    int zeroCount(int n, int a0, int a1) {
        int ans = 0;
        int bitOrNum = a0 | a1;
        while (n > 2) {
            int aN = a0 + a1;
            bitOrNum = bitOrNum | aN;
            a0 = a1;
            a1 = aN;
            n--;
        }
        ans = recursiveCount(bitOrNum);
        return ans;
    }

};


//int main(int argc, char const *argv[])
//{
//    int array[3];
//    std::for_each(std::begin(array), std::end(array), [](auto& element) {
//        cin >> element;
//    });
//    
//    int testcaseCount;
//    cin >> testcaseCount;
//    for (int i = 0; i < testcaseCount; ++i) {
//        int n, a0, a1;
//        cin >> n;
//        cin >> a0;
//        cin >> a1;
//        Solution obj;
//        int zeroCount = obj.zeroCount(n, a0, a1);
//        cout << zeroCount << endl;
//    }
//    return 0;
//}
