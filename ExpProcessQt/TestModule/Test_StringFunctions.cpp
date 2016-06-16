#include "StdAfx.h"
#include "Test_StringFunctions.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_StringFunctions);

Test_StringFunctions::Test_StringFunctions(void)
{
}

Test_StringFunctions::~Test_StringFunctions(void)
{
}

void Test_StringFunctions::test_removeWhiteSpaces(){

	CPPUNIT_ASSERT(StringFunctions::removeWhiteSpaces("x = ( -b+-sqrt(b^2+4ac) )  /2a")=="x=(-b+-sqrt(b^2+4ac))/2a");
	CPPUNIT_ASSERT(StringFunctions::removeWhiteSpaces("x = ( -b+-sqrt(b^2+4ac) )  /2a ")=="x=(-b+-sqrt(b^2+4ac))/2a");
	CPPUNIT_ASSERT(StringFunctions::removeWhiteSpaces(" x = ( -b+-sqrt(b^2+4ac) )  /2a ")=="x=(-b+-sqrt(b^2+4ac))/2a");
	CPPUNIT_ASSERT(StringFunctions::removeWhiteSpaces("x=(-b+-sqrt(b^2+4ac))/2a")=="x=(-b+-sqrt(b^2+4ac))/2a");

}

void Test_StringFunctions::test_countSubstr(){

	CPPUNIT_ASSERT(StringFunctions::countSubstr("x=(-b+-sqrt(b^2+4ac))/2a", "-")==2);
	CPPUNIT_ASSERT(StringFunctions::countSubstr("x=(-b+-sqrt(b^2+4ac))/2a", "sqrt")==1);
	CPPUNIT_ASSERT(StringFunctions::countSubstr("x=(-b+-sqrt(b^2+4ac))/2a", "y")==0);
	CPPUNIT_ASSERT(StringFunctions::countSubstr("x=(-b+-sqrt(b^2+4ac))/2a", "2a")==1);

}

void Test_StringFunctions::test_replaceAll(){

	CPPUNIT_ASSERT(StringFunctions::replaceAll("x=(-b+-sqrt(b^2+4ac))/2a", "(", "[")=="x=[-b+-sqrt[b^2+4ac))/2a");
	CPPUNIT_ASSERT(StringFunctions::replaceAll("x=(-b+-sqrt(b^2+4ac))/2a", "2a", "")=="x=(-b+-sqrt(b^2+4ac))/");
	CPPUNIT_ASSERT(StringFunctions::replaceAll("x=(-b+-sqrt(b^2+4ac))/2a", "gh", "[")=="x=(-b+-sqrt(b^2+4ac))/2a");
	CPPUNIT_ASSERT(StringFunctions::replaceAll("x=(-b+-sqrt(b^2+4ac))/2a", "sr", "SR")=="x=(-b+-sqrt(b^2+4ac))/2a");

}

void Test_StringFunctions::test_match(){

	CPPUNIT_ASSERT(StringFunctions::match("x=#", "x=(-b+-sqrt(b^2+4ac))/2a"));
	CPPUNIT_ASSERT(StringFunctions::match("#sqrt#", "x=(-b+-sqrt(b^2+4ac))/2a"));
	CPPUNIT_ASSERT(StringFunctions::match("#sqrt#b^2#", "x=(-b+-sqrt(b^2+4ac))/2a"));
	CPPUNIT_ASSERT(!StringFunctions::match("#sqrt#b^4#", "x=(-b+-sqrt(b^2+4ac))/2a"));

}