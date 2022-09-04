//
//  CPPDataTypeTest.hpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/6/29.
//

#ifndef CPPDataTypeTest_hpp
#define CPPDataTypeTest_hpp

#include <stdio.h>

class CPPDataTypeTester
{
public:
    static CPPDataTypeTester* getInstance();
    void testUnsignedDataTypes();
    void testPointerDeletion();
    void testVariableInitialization();
    void testCPPPrimerPractice();
};

#endif /* CPPDataTypeTest_hpp */
