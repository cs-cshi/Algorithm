#include <iostream>

using namespace std;

template<typename type1, typename type2>
type1 max(type1 num1, type2 num2){
    return num1 > num2 ? num1 : num2;
}