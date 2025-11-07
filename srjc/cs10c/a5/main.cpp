#include <iostream>
#include "ArrayStack.h"
using namespace std;
using namespace cs_stack;

int main() {
    ArrayStack<int> aStack;
    aStack.push(1);
    aStack.push(2);
    aStack.push(3);
    aStack.push(4);
    aStack.push(5);
    ArrayStack<int> aStack2(aStack);
    aStack2 = aStack;
    aStack.push(6);  
}
