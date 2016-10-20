//
// Created by wh on 2016-10-20.
// ref: http://blog.csdn.net/candyliuxj/article/details/4396666
//

#include <cstdlib>
#include <ctime>
#include "NumberGenerator.h"


NumberGenerator::NumberGenerator() {
    srand((unsigned)time(NULL));
}

int NumberGenerator::GetRandom(int min, int max) {
    if(min>max) swap(min, max);
    return rand()%(max-min+1) + min;
}

void NumberGenerator::swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
