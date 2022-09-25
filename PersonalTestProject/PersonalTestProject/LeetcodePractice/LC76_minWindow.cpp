#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution1 {
public:

    bool validate(unordered_map<char, int> &charsInSubstr, unordered_map<char, int> &charsInT) {
        for (auto iterator : charsInT) {
            if (charsInSubstr[iterator.first] < iterator.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) {
            return "";
        }

        unordered_map<char, int> charsInT;
        for (auto &ch : t) {
            // int originalCount = charsInT.find(t.at(i))->second;
            // charsInT.insert(pair<char, int>(t.at(i), originalCount+1));
            charsInT[ch]++;
        }

        unordered_map<char, int> charsInSubstr;
        int left = 0, right = 0;
        int ansSubStrPos = -1, ansSubStrSize = INT32_MAX;
        for (; right<s.size(); right++) {
            // check if this char is needed --> only add needed char to map
            if (charsInT.find(s.at(right)) != charsInT.end()) {
                charsInSubstr[s.at(right)]++;
            }

            while (validate(charsInSubstr, charsInT) && left<=right) {
                int substrSize = right-left+1;
                if (substrSize < ansSubStrSize) {
                    ansSubStrPos = left;
                    ansSubStrSize = substrSize;
                }
                if (charsInT.find(s.at(left)) != charsInT.end()) {
                    charsInSubstr[s.at(left)]--;
                }
                left++;
            }
        }
        return ansSubStrPos==-1 ? "" : s.substr(ansSubStrPos, ansSubStrSize);
    }
};

class Solution2 {
public:
    unordered_map <char, int> charsInT, charsInSubstr;

    bool check() {
        for (const auto &iterator: charsInT) {
            if (charsInSubstr[iterator.first] < iterator.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            charsInT[c]++;
        }

        int left = 0, right = 0;
        int ansSize = INT_MAX, ansPos = -1;

        while (right < int(s.size())) {
            if (charsInT.find(s[right]) != charsInT.end()) {
                charsInSubstr[s[right]]++;
            }
            while (check() && left <= right) {
                if (right - left + 1 < ansSize) {
                    ansSize = right - left + 1;
                    ansPos = left;
                }
                if (charsInT.find(s[left]) != charsInT.end()) {
                    charsInSubstr[s[left]]--;
                }
                left++;
            }
            right++;
        }

        return ansPos == -1 ? "" : s.substr(ansPos, ansSize);
    }
};


static int LCTester76() {
    Solution1 *obj = new Solution1();
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string ans1 = obj->minWindow(s, t);
    std::cout << ans1 << std::endl;
    
    return 0;
}

