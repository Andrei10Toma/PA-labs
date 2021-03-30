#include <bits/stdc++.h>
using namespace std;

struct Object {
    int weight;
    int price;

    Object(int _weight, int _price)
        : weight(_weight)
        , price(_price) { }
};


bool compare_by_price_per_weight(const Object &a, const Object &b) {
    double price_per_weight_a = (double)a.price / (double)a.weight;
    double price_per_weight_b = (double)b.price / (double)b.weight;
    return price_per_weight_a > price_per_weight_b;
}

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, w;
    vector<Object> objs;

    void read_input() {
        ifstream fin("in");
        fin >> n >> w;
        for (int i = 0, weight, price; i < n; i++) {
            fin >> weight >> price;
            objs.push_back(Object(weight, price));
        }
        fin.close();
    }

    double get_result() {
        double profit = 0;
        sort(objs.begin(), objs.end(), compare_by_price_per_weight);
        for (auto i = objs.begin(); i != objs.end(); i++) {
            cout << i->weight << " " << i->price << endl;
        }
        for (auto i = objs.begin(); i != objs.end(); i++) {
            if (w <= 0) {
                break;
            }
            if (i->weight < w) {
                profit += i->price;
                w -= i->weight;
            }
            else {
                profit += (double)i->price * w / (double)i->weight;
                w -= i->weight;
            }
        }
        return profit;
    }

    void print_output(double result) {
        ofstream fout("out");
        fout << setprecision(4) << fixed << result;
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
