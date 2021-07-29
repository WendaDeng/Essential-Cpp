#include <iostream>
using namespace std;

bool fibon_elem(int pos, long &elem) {
    if (pos <= 0 || pos > 1024) {
        elem = 0;
        return false;
    }

    elem = 1;
    long n_2 = 1, n_1 = 1;

    for (int idx = 3; idx <= pos; idx++) {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }

    return true;
}

int main() {
    int pos;
    while (true) {
        cout << "Please enter a position (0 for exit): ";
        cin >> pos;
        if (pos == 0)
            break;

        long elem;
        if (fibon_elem(pos, elem))
            cout << "element # " << pos << " is " << elem << endl;
        else
            cout << "Sorry, could not calculate element # " << pos << endl;
    }
}

