#if !defined(TEST_STRINGFUNCTIONS_H_INCLUDED)
#define TEST_STRINGFUNCTIONS_H_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "StringFunctions.h"

class Test_StringFunctions : public CppUnit::TestCase
{

	CPPUNIT_TEST_SUITE(Test_StringFunctions);
		CPPUNIT_TEST(test_removeWhiteSpaces);
		CPPUNIT_TEST(test_match);
		CPPUNIT_TEST(test_replaceAll);
		CPPUNIT_TEST(test_countSubstr);
	CPPUNIT_TEST_SUITE_END();

public:
	Test_StringFunctions(void);
	~Test_StringFunctions(void);

protected:
	void test_removeWhiteSpaces();
	void test_match();
	void test_replaceAll();
	void test_countSubstr();
};

#endif