#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x, y;

    void read_input() {
        ifstream fin("in");
        fin >> n >> x >> y;
        fin.close();
    }

    void get_value(int n, int x, int y, int left_x, int right_x, int left_y, int right_y, int &acumulator) {
        int mid_x, mid_y;
        if (n == 0) return;
        mid_x = (left_x + right_x) / 2;
        mid_y = (left_y + right_y) / 2;
        int acc = (1 << (n - 1)) * (1 << (n - 1));
        if (x <= mid_x && y <= mid_y) {
            get_value(n - 1, x, y, left_x, mid_x - 1, left_y, mid_y - 1, acumulator);
        }
        else if (x <= mid_x && y > mid_y) {
            acumulator += acc;
            get_value(n - 1, x, y, left_x, mid_x - 1, mid_y + 1, right_y, acumulator);   
        }
        else if (x > mid_x && y <= mid_y) {
            acumulator += 2 * acc;
            get_value(n - 1, x, y, mid_x + 1, right_x, left_y, mid_y - 1, acumulator);
        }
        else if (x > mid_x && y > mid_y) {
            acumulator += 3 * acc;
            get_value(n - 1, x, y, mid_x + 1, right_x, mid_y + 1, right_y, acumulator);
        }
    }

    int get_result() {
        int acumulator = 1;
        get_value(n, x - 1, y - 1, 0, (1 << n) - 1, 0, (1 << n) - 1, acumulator);
        return acumulator; 
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
