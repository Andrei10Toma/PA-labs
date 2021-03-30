#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x;
    vector<int> v;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        for (int i = 0, e; i < n; i++) {
            fin >> e;
            v.push_back(e);
        }
        fin >> x;
        fin.close();
    }

    int find_first() {
        int left = 0, right = n - 1, mid, res = -1;
        // TODO: Cautati prima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1
        while (left <= right) {
            mid = (left + right) / 2;
            if (v[mid] < x) {
                left = mid + 1;
            }
            else if (v[mid] > x) {
                right = mid - 1;
            }
            else if (v[mid] == x) {
                right = mid - 1;
                res = mid;
            }
        }
        return res;
    }

    int find_last() {
        // TODO: Cautati ultima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1
        int left = 0, right = n - 1, mid, res = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (v[mid] > x) {
                right = mid - 1;
            }
            else if (v[mid] < x) {
                left = mid + 1;
            }
            else if (v[mid] == x) {
                res = mid;
                left = mid + 1;
            }
        }
        return res;
    }

    int get_result() {
        // TODO: Calculati numarul de aparitii ale lui x in vectorul v
        int last = find_last();
        int first = find_first();
        if (last == -1 || first == -1) {
            return 0;
        }
        return last - first + 1;
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (std::nothrow) Task{}; // hint: cppreference/nothrow
    if (!task) {
        std::cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
