//
//  CPPDataTypeTest.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/6/29.
//

#include "CPPDataTypeTest.hpp"
#include <iostream>

static CPPDataTypeTester* sDataTypeTester = nullptr;

CPPDataTypeTester* CPPDataTypeTester::getInstance() {
    if (sDataTypeTester == nullptr) {
        sDataTypeTester = new CPPDataTypeTester();
    }
    return sDataTypeTester;
}

void CPPDataTypeTester::testUnsignedDataTypes()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;       // 32
    std::cout << u - u2 << std::endl;       // (-32)---unsigned-->4294967264(2^32-32)
    
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;       // 32
    std::cout << i - i2 << std::endl;       // -32
    std::cout << i - u << std::endl;        // 0
    std::cout << u - i << std::endl;        // 0
}

void CPPDataTypeTester::testPointerDeletion() {
    int *a = new int;
    int *b = a;
    delete a;
    a = nullptr;
    if (a != nullptr) {
        delete b;
    }
}

void CPPDataTypeTester::testVariableInitialization() {
//    ======== Practice 2.9 ========
//    std::cin >> int input_value;
    // -> Expected '(' for function-style cast or type construction
    
//    int i = {3.14};
    // -> Type 'double' cannot be narrowed to 'int' in initializer list
    // -> Insert an explicit cast to silence this issue
    
//    double salary = wage = 999.99;
    // -> error: Use of undeclared identifier 'wage'
    
    int j = 3.14;
    // -> ok: j = 3;
//    std::cout << j <<std::endl;
    
//    ======== Practice 2.10 ========
    std::string globale_str;            // -> ""
    int global_int;                     // -> 0
//    int main () {
//        int local_int;              // -> undefined
//        std::string local_str;     // -> undefined
//    }
    
//    ======== Practice 2.11 ========
//    extern int ix = 1024;
    // -> 'extern' variable cannot have an initializer
    
    int iy;
    // -> declare + define
    
    extern int iz;
    // -> declare
    
    int i=100, sum=0;
    for (int i=0; i!=10; i++) {
        sum+=i;
    }
    std::cout << i << " " << sum << std::endl;
    // -> i=100, sum=45
    
    //    ======== Practice 2.11 ========
    int num, &numRef = num;
    num = 5;
    numRef = 10;
    std::cout << num << " " << numRef << std::endl;
    
//MARK: Practice 2.21
    int ival = 0;
//    double *dp = &ival; Cannot initialize a variable of type 'double *' with an rvalue of type 'int *'
//    int *ip = ival; Cannot initialize a variable of type 'int *' with an lvalue of type 'int'
    int *p = &ival;
    
}

static void CPPPrimerPractice_2_32() {
//    int null = 0, *p = null;
//     error-> Cannot initialize a variable of type 'int *' with an lvalue of type 'int'
    
    // fix:
//    int null = 0, *p = &null;
    
    // or:
//    int null = 0, *p = nullptr;
}

static void CPPPrimerPractice_2_35() {
    // i is const int
    const int i = 42;
    
    // j is int
    auto j = i;
    
    // k is const int reference
    const auto &k = i;
    
    // p i s pointer to const int
    auto *p = &i;
    
    // j2 is const int, k2 is const int reference
    const auto j2 = i, &k2 = i;
    
    // print i means int, and PKi means pointer to const int.
    std::cout   << "j is "      << typeid(j).name()
                << "\nk is "    << typeid(k).name()
                << "\np is "    << typeid(p).name()
                << "\nj2 is "   << typeid(j2).name()
                << "\nk2 is "   << typeid(k2).name()
                << std::endl;
}

void CPPDataTypeTester::testCPPPrimerPractice() {
    CPPPrimerPractice_2_35();
}
