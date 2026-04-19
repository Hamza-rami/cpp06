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
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

public:
    static void convert(const std::string& literal);
};

