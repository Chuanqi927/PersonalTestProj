//
//  LC54.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/8/20.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        vector<int> ans;
        // 按顶点位置来遍历(index)
        int startRow = 0, endRow = (int)matrix.size()-1;
        int startCol = 0, endCol = (int)matrix[0].size()-1;
        
        while (startRow <= endRow && startCol <= endCol) {
            // 下面开始的四个for就是模拟转了一圈
            int row, col;
            // 模拟填充上行从左到右(左闭右闭)
            for (col=startCol; col<=endCol; col++) {
                ans.push_back(matrix[startRow][col]);
            }
            // 模拟填充右列从上到下(左开右闭)
            for (row=startRow+1; row<=endRow; row++) {
                ans.push_back(matrix[row][endCol]);
            }
            if (startRow<endRow && startCol<endCol) {
                // 模拟填充下行从右到左(左开右开)
                for (col=endCol-1; col>startCol; col--) {
                    ans.push_back(matrix[endRow][col]);
                }
                // 模拟填充左列从下到上(左闭右开)
                for (row=endRow; row>startRow; row--) {
                    ans.push_back(matrix[row][startCol]);
                }
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return ans;
    }
};

static void LCTester54() {
    Solution obj;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans1 = obj.spiralOrder(matrix);
    
    for (auto &num : ans1) {
        std::cout << num << std::endl;
    }
}
