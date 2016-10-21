//
// Created by wh on 2016-10-20.
//

#ifndef SNIPPET_NUMBERGENERATOR_H
#define SNIPPET_NUMBERGENERATOR_H

#include "GlobalDefinition.h"

class NumberGenerator
{
public:
    NumberGenerator();
    int GetRandom(int min, int max);

private:
    void swap(int &a, int &b);
    DISABLE_ASSIGN_AND_COPY(NumberGenerator)
};
#endif //SNIPPET_NUMBERGENERATOR_H
