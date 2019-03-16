#define CONST_LITERAL 21

#include <iostream>

void passByValue(int param);
void passByConstValue(const int param);
void passByPointer(int * param);
void passByConstPointer(const int * param);
void passByReference(int& param);
void passByConstReference(const int& param);

int main()
{
    int i = 2;
    std::cout << "tests for an int variable" << std::endl;
    std::cout << "variable value: " << i << std::endl;
    std::cout << "variable's address: " << &i << std::endl;            
    passByValue(i);
    passByConstValue(i);
    passByPointer(&i);
    passByConstPointer(&i);
    passByReference(i);
    passByConstReference(i);
    std::cout << std::endl;

    const int j = 2;
    std::cout << "tests for a const int variable" << std::endl;
    std::cout << "variable value: " << j << std::endl;
    std::cout << "variable's address: " << &j << std::endl;            
    passByValue(j);
    passByConstValue(j);
    // passByPointer(&j);
    passByConstPointer(&j);
    // passByReference(j);
    passByConstReference(j);
    std::cout << std::endl;
    
    std::cout << "tests for a const literal" << std::endl;
    std::cout << "variable value: " << CONST_LITERAL << std::endl;
    passByValue(CONST_LITERAL);
    passByConstValue(CONST_LITERAL);
    // passByPointer(CONST_LITERAL);
    // passByConstPointer(CONST_LITERAL);
    // passByReference(CONST_LITERAL);
    passByConstReference(CONST_LITERAL);
    std::cout << std::endl;


    // char a = ''; //error: empty character constant
}

void passByValue(int param){
        std::cout << "function passByValue" << std::endl;
        std::cout << "parameter value: " << param << std::endl;
        std::cout << "parameter's address: " << &param << std::endl;    
        std::cout << std::endl;
    }

void passByConstValue(const int param){
        std::cout << "function passByConstValue" << std::endl;
        std::cout << "parameter value: " << param << std::endl;
        std::cout << "parameter's address: " << &param << std::endl;    
        std::cout << std::endl;
    }
void passByPointer(int * param){
        std::cout << "function passByPointer" << std::endl;
        std::cout << "parameter value: " << param << std::endl;
        std::cout << "parameter's address: " << param << std::endl;    
        std::cout << std::endl;
    }
void passByConstPointer(const int * param){
        std::cout << "function passByConstPointer" << std::endl;
        std::cout << "parameter value: " << param << std::endl;
        std::cout << "parameter's address: " << param << std::endl;    
        std::cout << std::endl;
    }
void passByReference(int& param){
        std::cout << "function passByReference" << std::endl;
        std::cout << "parameter value: " << param << std::endl;
        std::cout << "parameter's address: " << &param << std::endl;
        std::cout << std::endl;
    }
void passByConstReference(const int& param){
        std::cout << "function passByConstReference" << std::endl;
        std::cout << "parameter value: " << param << std::endl;
        std::cout << "parameter's address: " << &param << std::endl;
        std::cout << std::endl;
    }