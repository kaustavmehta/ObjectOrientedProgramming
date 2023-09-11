#include "calculator.h"


double Calculator::add(){
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    return num1 + num2;
}

double Calculator::subtract(){
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    return num1 - num2;
}

double Calculator::multiply(){
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    return num1 * num2;
}

double Calculator::divide(){
    double num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    
    if (num2 != 0) {
        return num1 / num2;
    } else {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
};

double Calculator::modulus(){
    double num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    if (num2 != 0) {
        return fmod(num1, num2);
    } else {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
};

double Calculator::square(){
    double num;
    
    std::cout << "Enter a number: ";
    std::cin >> num;
    
    return num * num;
};

double Calculator::power(){
    double num1, num2;
    
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    return pow(num1, num2);
};

double Calculator::sqroot(){
    double num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    
    if (num >= 0){
        return sqrt(num);
    } else {
        std::cout << "Error: Square root of a negative number!" << std::endl;
        return 0;
    }
};

double Calculator::natlog(){
    double num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    
    if (num > 0){
        return log(num);
    } else {
        std::cout << "Error: Logarithm of a non-positive number!";
        return 0;
    }
};

double Calculator::logarithm(){
    double num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    
    if (num > 0){
        return log10(num);
    } else {
        std::cout << "Error: Logarithm of a non-positive number!" << std::endl;
        return 0;
    }
};