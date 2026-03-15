#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

int check_float(const std::string& literal)
{
    int f = 0;
    int p = 0;
    size_t i = 0;
    int digits = 0;
    if (literal[literal.size() -1] != 'f')
        return 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    while (i < literal.size())
    {
        if(literal[i] == '.')
            p++;
        else if(literal[i] == 'f')
            f++;
        else if(!isdigit(literal[i]))
            return 0;
        else
            digits++;
        if(p > 1 || f > 1)
            return 0;
        i++;
    }
    if (digits == 0)
        return 0;
    return 1;
}


int check_double(const std::string& literal)
{
    int p = 0;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    while (i < literal.size())
    {
        if(literal[i] == '.')
            p++;
        else if(!isdigit(literal[i]))
            return 0;
        if(p > 1)
            return 0;
        i++;
    }
    if (p)
        return 1;
    return 0;
}

int check_int(const std::string& literal)
{
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    while (i < literal.size())
    {
        if(!isdigit(literal[i]))
            return 0;
        i++;
    }
    return 1;
}

std::string detectType(const  std::string& literal)
{
    if (literal.size() == 3 && literal[0] == '\'' && literal[literal.size()-1] == '\'')
        return "char";
    else if (literal.size() == 1 && !isdigit(literal[0]))
        return "char";
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return "float";
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return "double";
    else if (check_float(literal))
            return "float";
    else if(check_double(literal))
        return "double";
    else if(check_int(literal))
        return "int";
    else
        return "NON";
}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << std::fixed << std::setprecision(1);
    if (literal.size() == 0)
    {
        std::cout << "type unknown\n";
        return;
    }
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
    double check = atof(literal.c_str());
    if (check > INT_MAX || check < INT_MIN)
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << static_cast<float>(check) << "f\n";
        std::cout << "double: " << check << "\n";
    }
    else
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

        if (std::isnan(a) || std::isinf(a) || a < -2147483648.0 || a > 2147483647.0)
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

        if (std::isnan(a) || std::isinf(a) || a < -2147483648.0 || a > 2147483647.0)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(a) << "\n";

        std::cout << "float: " << static_cast<float>(a) << "f\n";
        std::cout << "double: " << a << "\n";
    }
    else
        std::cout << "type unknown\n";
}