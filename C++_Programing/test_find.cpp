#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item { int id, val; };
bool cmp(const Item& a, const Item& b) { return a.val < b.val; }

int main() {
    for (int n = 16; n <= 35; n++) {
        vector<Item> a, b;
        for (int i = 0; i < n; i++) {
            a.push_back({i, (i % 3) * 5});
        }
        b = a;
        stable_sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end(), cmp);
        bool diff = false;
        for (int i = 0; i < n; i++) {
            if (a[i].id != b[i].id) { diff = true; break; }
        }
        if (diff) {
            cout << "Found diff at n=" << n << endl;
            cout << "stable_sort IDs: ";
            for (auto& x : a) cout << x.id << " ";
            cout << "
sort IDs:        ";
            for (auto& x : b) cout << x.id << " ";
            cout << endl;
            break;
        }
    }
    return 0;
}
