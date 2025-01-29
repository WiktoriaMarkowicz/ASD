#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    int n, m;
    cin >> n >> m;
    map<int, int> konceprzedzialow;
    map<int, int> poczatkiprzedzialow;

    for(int i = 0; i < m; i++) {
        int l, r;
        char c;
        cin >> c >> l >> r;
        int l1;
            int r1;
            char c1;
        if (i == 0) {
            l1 = l;
            r1 = r;
            c1 = c;
        }
        
        if (c == '+') {
            if (l == 1) {
                auto it = konceprzedzialow.find(r);
                if (it == konceprzedzialow.end()) {
                    konceprzedzialow.insert({r, 1});
                }
                
            } else {
                auto it = poczatkiprzedzialow.find(l);
                if (it == poczatkiprzedzialow.end()) {
                    poczatkiprzedzialow.insert({l, 1});
                }
                
            }
            
        } else {
            if (l == 1) {
                auto it = konceprzedzialow.find(r);
                if (it != konceprzedzialow.end()) {
                    int ile = it->second;
                    konceprzedzialow.erase(it);
                    if (ile - 1 > 0) konceprzedzialow.insert({r, ile - 1});
                }
            } else {
                auto it = poczatkiprzedzialow.find(l);
                if (it != poczatkiprzedzialow.end()) {
                    int ile = it->second;
                    poczatkiprzedzialow.erase(it);
                    if (ile - 1 > 0) poczatkiprzedzialow.insert({l, ile - 1});
                }
            }
        }
        
        int koniec = (!konceprzedzialow.empty()) ?  konceprzedzialow.rbegin()->first : 0;
        int poczatek = (!poczatkiprzedzialow.empty()) ? poczatkiprzedzialow.begin()->first : n + 1;
        int wynik = 0;
        if (koniec == 0 && poczatek == n + 1) {
            wynik = n;
        } else if (koniec == 0) {
            wynik = poczatek - 1;
        } else if (poczatek == n + 1) {
            wynik = poczatek - koniec - 1;
        } else if (koniec < poczatek) {
            wynik = poczatek - koniec - 1;
        }
        // if (i == 1) {
        //     cout << c1 << "," << l1 << "," << r1 << "," << c << "," << l << "," << r << endl;
        // }
        //cout << koniec << " " << poczatek << endl;
        cout << wynik << endl;
    }

    return 0;
}