#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

std::string detectType(const std::string& literal)
{
    if (literal.size() == 3 && literal[0] == '\'' && literal[literal.size()-1] == '\'')
        return "char";
    else if (literal.size() == 1 && isalpha(literal[0]))
        return "char";
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return "float";
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return "double";
    else if (literal.size() > 1 && literal[literal.size()-1] == 'f')
        return "float";
    else if (literal.find('.') != std::string::npos)
        return "double";
    else
        return "int";
}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << std::fixed << std::setprecision(1);
    std::string type = detectType(literal);
    
    if (type == "char")
    {
        char a;
        if (literal.size() == 1)
            a = literal[0];
        else
            a = literal[1];
        std::cout << "char: " << a << "\n";
        std::cout << "int: " << static_cast<int>(a) << "\n";
        std::cout << "float: " << static_cast<float>(a) << "f\n";
        std::cout << "double: " << static_cast<double>(a) << "\n";
    }
    else if (type == "int")
    {
        int a = atoi(literal.c_str());
        if (a >= 32 && a <= 126)
            std::cout << "char: " << static_cast<char>(a) << "\n";
        else
            std::cout << "char: Non displayable\n";

        std::cout << "int: " << a << "\n";

        std::cout << "float: " << static_cast<float>(a) << "f\n";
        std::cout << "double: " << static_cast<double>(a) << "\n";
    }
    else if (type == "float")
    {
        float a = (float)atof(literal.c_str()); 
        if (std::isnan(a) || std::isinf(a))
            std::cout << "char: impossible\n";
        else if (a >= 32 && a <= 126)
            std::cout << "char: " << static_cast<char>(a) << "\n";
        else
            std::cout << "char: Non displayable\n";

        if (std::isnan(a) || std::isinf(a) || a < (float)INT_MIN || a > (float)INT_MAX)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(a) << "\n";

        std::cout << "float: " << a << "f\n";
        std::cout << "double: " << static_cast<double>(a) << "\n";

    }
    else if (type == "double")
    {
        double a = atof(literal.c_str()); 
        if (std::isnan(a) || std::isinf(a))
            std::cout << "char: impossible\n";
        else if (a >= 32 && a <= 126)
            std::cout << "char: " << static_cast<char>(a) << "\n";
        else
            std::cout << "char: Non displayable\n";

        if (std::isnan(a) || std::isinf(a) || a < (double)INT_MIN || a > (double)INT_MAX)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(a) << "\n";

        std::cout << "float: " << static_cast<float>(a) << "f\n";
        std::cout << "double: " << a << "\n";
    }
}