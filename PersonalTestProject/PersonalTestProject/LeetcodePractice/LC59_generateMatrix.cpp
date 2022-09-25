//
//  LC59.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/8/23.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;
class Solution59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};
        
        vector<vector<int>> ans(n, vector<int>(n,0));
        int startRow = 0, endRow = n-1;
        int startCol = 0, endCol = n-1;
        int row, col;
        int num = 1;
        int mid = n/2;
        while (startRow<=endRow && startCol<=endCol) {
            for (col=startCol; col<endCol; col++) {
                ans[startRow][col] = num++;
            }
            for (row=startRow; row<endRow; row++) {
                ans[row][endCol] = num++;
            }
            if (startRow<endRow && startCol<endCol) {
                for (col=endCol; col>startCol; col--) {
                    ans[endRow][col] = num++;
                }
                for (row=endRow; row>startRow; row--) {
                    ans[row][startCol] = num++;
                }
            }
            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }
        // add one more mid node for n as an odd number
        if (n % 2 ) {
            ans[mid][mid] = num;
        }
        return ans;
    }
};

static void LCTester59() {
    Solution59 obj;
    vector<vector<int>> ans = obj.generateMatrix(3);
    for (vector<int> &v : ans) {
        CPPComUtils::printVector(v);
    }
}
