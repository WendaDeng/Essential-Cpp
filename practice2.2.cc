#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool pent_seq(vector<int> &elems, int size) {
    const int max_size = 128;
    if (size <= 0 || size > max_size) {
        cerr << "pent_seq(): invalid size: "
             << size << " -- can't fulfill request.\n";
        return false;
    }

    for (int ix = elems.size() + 1; ix < size; ++ix)
        elems.push_back(ix * (3 * ix - 1) / 2);
    return true;
}

void display_elem(vector<int> &elems, const string &title, ostream &os=cout) {
    os << "\n" << title << "\n\t";
    for (int ix = 0; ix < elems.size(); ++ix)
        os << elems[ix] << " ";
    os << "\n";
}

int main() {
    vector<int> pent;
    const string title("Pentagonal  Numeric Series");
    if (pent_seq(pent, 0))
        display_elem(pent, title);

    if (pent_seq(pent, 8))
        display_elem(pent, title);

    if (pent_seq(pent, 14))
        display_elem(pent, title);

    if (pent_seq(pent, 130))
        display_elem(pent, title);

    if (pent_seq(pent, -1))
        display_elem(pent, title);

    return 0;
}
