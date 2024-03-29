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

static void CPPPrimerPractice2_27() {
//    int i = -1, &r = 0;     // error-> r must refer to an object
//    int *const p2 = &i2;    // ok (suppose i2 is defined)
//    const int i = -1, &r = 0;   // ok
//    const int *const p3 = &i2;      // ok (suppose i2 is defined)
//    const int *p1 = &i2;    // ok (suppose i2 is defined)
//    const int &const r2;    // error-> Declaration of reference variable 'r2' requires an initializer
//    const int i2 = i, &r2 = i;  // ok (suppose i is defined)
}

static void CPPPrimerPractice2_28() {
//    int i, *const cp;
    // Error: cp is const pointer to int -> must initialize
//    int *p1, *const p2;
    // Error: p2 is const pointer to int -> must initialize
//    const int ic, &r = ic;
    // Error: ic is const int, must initialize
//    const int *const p3;
    // Error: p3 is const pointer to const int, must initialize
    const int *p;
    // ok: p is pointer to const int
}

static void CPPPrimerPractice2_29() {
    int *p1;
    const int *const p3 = 0;
//    p1 = p3;
    // Error-> Assigning to 'int *' from 'const int *const' discards qualifiers
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

static void CPPPrimerPractice_2_36() {
    int a = 3, b = 4;
    decltype(a) c = a;
    // c is int, equal to a
    decltype((b)) d = a;
    // d is int&, binds to a
    ++c;
    // c = 4
    ++d;
    // d = a = 4;
}

static void CPPPrimerPractice_2_37() {
    int a = 3, b = 4;
    decltype(a) c = a;
    // c is int
    decltype(a = b) d = a;
    // d is int&, binds to a
}

static void CPPPrimerPractice_4_4() {
    int ans = 12/3*4+5*15+24%4/2;
    std::cout << "4.4 ans: " << ans << std::endl;
}

static void CPPPrimerPractice_4_5() {
    int ansA = -30*3+21/5;
    int ansB = -30+3*21/5;
    int ansC = 30/3*21%5;
    int ansD = -30/3*21%4;
    std::cout << "4.5 ansA: " << ansA << std::endl;
    std::cout << "4.5 ansB: " << ansB << std::endl;
    std::cout << "4.5 ansC: " << ansC << std::endl;
    std::cout << "4.5 ansD: " << ansD << std::endl;
}

static bool CPPPrimerPractice_4_6(int input) {
    return input & 0x1;
}

static void CPPPrimerPractice_4_7() {
    short svalue = 32767;
//    svalue++;  overflow
    unsigned uivalue = 0;
//    uivalue--; overflow
    unsigned short usvalue = 65535;
//    usvalue++; overflow
}

void CPPDataTypeTester::testCPPPrimerPractice() {
    CPPPrimerPractice_4_5();
}
