#include <iostream>
#include <string>
#include <vector>
using namespace std;

void really_calc_elems(vector<int>&, int);
inline bool calc_elems(vector<int> &elems, int size) {
    const int max_size = 128;
    if (size <= 0 || size > max_size) {
        cerr << "calc_elems(): invalid size: "
             << size << " -- can't fulfill request.\n";
        return false;
    }

    if (elems.size() < size)
        really_calc_elems(elems, size);
    return true;
}

void really_calc_elems(vector<int> &elems, int size) {
    for (int ix = elems.size() + 1; ix < size; ++ix)
        elems.push_back(ix * (3 * ix - 1) / 2);
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
    if (calc_elems(pent, 0))
        display_elem(pent, title);

    if (calc_elems(pent, 8))
        display_elem(pent, title);

    if (calc_elems(pent, 14))
        display_elem(pent, title);

    if (calc_elems(pent, 130))
        display_elem(pent, title);

    if (calc_elems(pent, -1))
        display_elem(pent, title);

    return 0;
}
