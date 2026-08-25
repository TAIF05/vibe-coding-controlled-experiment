#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int minimum = 1000;
    int result;

    result = (n1 + n2) + n3;
    if (result >= 0 && result < minimum) minimum = result;

    result = (n1 + n2) - n3;
    if (result >= 0 && result < minimum) minimum = result;

    if (n3 != 0 && (n1 + n2) % n3 == 0) {
        result = (n1 + n2) / n3;
        if (result >= 0 && result < minimum) minimum = result;
    }

    result = (n1 + n2) * n3;
    if (result >= 0 && result < minimum) minimum = result;


    result = (n1 - n2) + n3;
    if (result >= 0 && result < minimum) minimum = result;

    result = (n1 - n2) - n3;
    if (result >= 0 && result < minimum) minimum = result;

    if (n3 != 0 && (n1 - n2) % n3 == 0) {
        result = (n1 - n2) / n3;
        if (result >= 0 && result < minimum) minimum = result;
    }

    result = (n1 - n2) * n3;
    if (result >= 0 && result < minimum) minimum = result;


    if (n2 != 0 && n1 % n2 == 0) {
        result = (n1 / n2) + n3;
        if (result >= 0 && result < minimum) minimum = result;

        result = (n1 / n2) - n3;
        if (result >= 0 && result < minimum) minimum = result;

        if (n3 != 0 && (n1 / n2) % n3 == 0) {
            result = (n1 / n2) / n3;
            if (result >= 0 && result < minimum) minimum = result;
        }

        result = (n1 / n2) * n3;
        if (result >= 0 && result < minimum) minimum = result;
    }

    result = (n1 * n2) + n3;
    if (result >= 0 && result < minimum) minimum = result;

    result = (n1 * n2) - n3;
    if (result >= 0 && result < minimum) minimum = result;

    if (n3 != 0 && (n1 * n2) % n3 == 0) {
        result = (n1 * n2) / n3;
        if (result >= 0 && result < minimum) minimum = result;
    }

    result = (n1 * n2) * n3;
    if (result >= 0 && result < minimum) minimum = result;


    cout << minimum << endl;
    return 0;
}
