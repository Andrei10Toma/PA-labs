#include <bits/stdc++.h>

using namespace std;

ifstream fin("in");

struct Product {
    int first_price;
    int discount_price;
    Product(int _first_price, int _discount_price)
        : first_price(_first_price)
        , discount_price(_discount_price) {}
};

bool compare_2_products(Product a, Product b) {
    return a.first_price - a.discount_price <= b.first_price - b.discount_price;
}

int main() {
    int n, k, i, x, selected_products = 0, minimum_sum = 0;
    vector<int> a;
    vector<int> b;
    vector<Product> products;
    fin >> n >> k;
    for (i = 0; i < n; i++) {
        fin >> x;
        a.push_back(x);
    }
    for (i = 0; i < n; i++) {
        fin >> x;
        b.push_back(x);
    }
    for (i = 0; i < n; i++) {
        products.push_back(Product(a[i], b[i]));
    }
    sort(products.begin(), products.end(), compare_2_products);
    while ((selected_products < n) 
    && (selected_products < k
    || products[selected_products].first_price - products[selected_products].discount_price <= 0)) {
        minimum_sum += products[selected_products].first_price;
        selected_products++;
    }
    if (selected_products < n) {
        for (i = selected_products; i < n; i++) {
            minimum_sum += products[i].discount_price;
        }   
    }
    cout << minimum_sum << endl;
    return 0;
}