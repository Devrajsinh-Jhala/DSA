#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 6;

    // Operators ^, |, &, ~
    cout << "a&b " << (a & b) << endl;
    cout << "a|b " << (a | b) << endl;
    cout << "a^b " << (a ^ b) << endl;

    // Operators: Left Shift and Right Shift
    cout << (17 >> 1) << endl;
    cout << (5 << 2) << endl;

    // Precedance Operators
    int i = 4;
    cout << i << endl;   // 4
    i++;                 // 5
    cout << ++i << endl; // 6

    return 0;
}
