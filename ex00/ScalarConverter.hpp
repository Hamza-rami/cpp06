#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <sstream>

class ScalarConverter
{
private:
    ScalarConverter();
public:
    static void convert(const std::string& literal);
};

