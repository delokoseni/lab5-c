#pragma once
#include <fstream>
using namespace std;

class EmpException : public exception{
public:
	EmpException(const char* const& message);
};