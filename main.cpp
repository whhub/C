#include <iostream>
using namespace std;

void Reverse(char * str);

int main() {

    char a[] = "012";
    Reverse(a);
    printf("%s", a);
    return 0;
}

int Len(const char * str)
{
    int count = 0;
    while(*str++) count++;
    return count;
}

void swap(char& a, char& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void Reverse(char * str)
{
    int len = Len(str);
    int middle = len/2;
    for (int i = 0; i < middle; ++i) {
        int i_opposite = len - 1 - i;
        swap((char&)str[i], (char&)str[i_opposite]);
    }
}
