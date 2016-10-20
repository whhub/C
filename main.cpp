#include <iostream>
#include "NumberGenerator.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto numberGenerator = new NumberGenerator();


    for (int i = 0; i < 10; ++i) {
        int a = numberGenerator->GetRandom(0, 100);
        int b = numberGenerator->GetRandom(100, 0);
        cout << "Between " << a << " and " << b << " , random : " << numberGenerator->GetRandom(a, b) << endl;
    }
    return 0;
}