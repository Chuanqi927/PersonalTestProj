//
//  LC71_simplifyPath.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/10/7.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        string ans;
        
        for (int i=0; i<path.size(); ++i) {
            if (path[i] == '/') {
                continue;
            }
            
            string filePath;
            while (i < path.size() && path[i] != '/') {
                filePath += path[i];
                ++i;
            }
            
            if (filePath == ".") {          // current folder, do nothing
                continue;
            }
            else if (filePath == "..") {    // parent folder, pop
                if (!pathStack.empty()) {
                    pathStack.pop();
                }
            }
            else {                          // new path, push
                pathStack.push(filePath);
            }
        }
        
        // adding all the stack elements to res
        while(!pathStack.empty()) {
            ans = "/" + pathStack.top() + ans;
            pathStack.pop();
        }

        // if no directory or file is present
        if(ans.size() == 0) {
            return "/";
        }
        
        return ans;
    }
};
