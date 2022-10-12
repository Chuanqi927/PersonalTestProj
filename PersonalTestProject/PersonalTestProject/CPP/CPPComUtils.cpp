//
//  CPPComUtils.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/08/23.
//

#include "CPPComUtils.hpp"
#include <random>
#include <time.h>

#pragma mark - Helper Functions

//MARK: Vector
void CPPComUtils::printVector(std::vector<int> &input) {
    std::cout << "---------Start Printing the Vector---------" << std::endl;
    int size = (int)input.size();
    for (int i=0; i<size; i++) {
        if (i == size-1) {
            std::cout << "[" << input[i] << "]" << std::endl;
        }
        else {
            std::cout << "[" << input[i] << "] ";
        }
    }
    std::cout << "---------Finished Printing the Vector---------" << std::endl;
    std::cout << "" << std::endl;
}

std::vector<int> CPPComUtils::generateRandomVectorOfSize(int size) {
    std::vector<int> ret;
    srand((unsigned)time(NULL));
    for (int i=0; i<size; i++) {
        int randomN = rand();
        ret.push_back(randomN);
    }
    return ret;
}

std::vector<int> CPPComUtils::generateRandomVector() {
    return generateRandomVectorOfSize(10);
}

//MARK: LinkedList
void CPPComUtils::printLinkedList(ListNode *head) {
    std::cout << "---------Start Printing the LinkedList---------" << std::endl;
    while (head != nullptr) {
        if (head->next == nullptr) {
            std::cout << head->val << std::endl;
        }
        else {
            std::cout << head->val << "->";
        }
        head = head->next;
    }
    std::cout << "---------Finished Printing the LinkedList---------" << std::endl;
    std::cout << "" << std::endl;
}

using namespace std;

vector<string> strSplit(string s, string delimiter) {
    size_t start = 0, end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((end = s.find(delimiter, start)) != string::npos) {
        token = s.substr(start, end - start);
        start = end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(start));
    return res;
}
