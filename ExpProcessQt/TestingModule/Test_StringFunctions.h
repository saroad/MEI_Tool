#pragma once

#include "ExpProcessQt\StringFunctions.h"

class Test_StringFunctions
{
public:
	Test_StringFunctions(void);
	~Test_StringFunctions(void);

protected:
	void test_removeWhiteSpaces();
	void test_match();
	void test_replaceAll();
	void test_countSubstr();
};
