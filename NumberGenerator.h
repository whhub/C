//
// Created by wh on 2016-10-20.
//

#ifndef SNIPPET_NUMBERGENERATOR_H
#define SNIPPET_NUMBERGENERATOR_H
class NumberGenerator
{
public:
    NumberGenerator();
    int GetRandom(int min, int max);

private:
    void swap(int &a, int &b);
};
#endif //SNIPPET_NUMBERGENERATOR_H
