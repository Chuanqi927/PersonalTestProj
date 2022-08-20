#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // two pointer loop from end of string together
        int i = s.size()-1;
        int j = t.size()-1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s.at(i) == '#') {
                    skipS++;
                    i--;
                }
                else if (skipS) {
                    i--;
                    skipS--;
                }
                else {
                    break;
                }
            }
            while (j >= 0) {
                if (t.at(j) == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT) {
                    j--;
                    skipT--;
                }
                else {
                    break;
                }
            }
            if (i >= 0 && j >= 0 && s.at(i) != t.at(j)) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--; 
            j--;
        }
        return true;
    }
};