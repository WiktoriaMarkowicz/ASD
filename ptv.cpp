#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<tuple<int, int, int>> prezesowie;

    for (int j = 0; j < n; j++) {
        int p, k, i;
        cin >> p >> k >> i;
        prezesowie.push_back({p, 0, i});
        prezesowie.push_back({k, -1, i});
    }

    sort(prezesowie.begin(), prezesowie.end());

    // for(auto pom : prezesowie) {
    //     cout << get<0>(pom) << " " << get<1>(pom) << " " << get<2>(pom) << endl;
    // }

    map<int, int> liczba_prezesow;

    int akt = 0;
    int maks = 0;
    int moment = 0;
    int aktMoment = 0;
    for(auto pom : prezesowie) {
        //cout << "prezes: " << get<2>(pom) << " ";
        auto it = liczba_prezesow.find(get<2>(pom));
        if (it != liczba_prezesow.end()) {
            //cout << " jest ";
            int ile = it->second;
            if (get<1>(pom) == 0) {
                liczba_prezesow.erase(it);
                liczba_prezesow.insert({get<2>(pom), ile + 1});
            } else {
                liczba_prezesow.erase(it);
                if (ile - 1 != 0) liczba_prezesow.insert({get<2>(pom), ile - 1});
                else {
                    //cout << " zmniejszamy ";
                    akt--;
                }
            }
        } else {
            liczba_prezesow.insert({get<2>(pom), 1});
            akt++;
        }
        //cout << akt << endl;

        if (akt > maks ){
            maks = akt;
            moment = get<0>(pom);
        }
        //aktMoment = get<0>(pom);
    }


    // set<tuple<int, int , int>> prez;
    // int n;
    // cin >> n;

    // for (int i = 0; i < n; i++) {
    //     int p, k, j;
    //     cin >> p >> k >> j;
    //     auto it = prez.lower_bound({j, 0, 0});
    //     bool ok = true;
    //     if (it != prez.end() && get<0>(*it) == j) {
    //         if ((p < get<1>(*it) && k > get<1>(*it)) || (p <= get<2>(*it) && k > get<2>(*it))) {
    //             p = min(p, get<1>(*it));
    //             k = max(k,  get<2>(*it));
    //             prez.erase(it);
    //         } else if (p >= get<1>(*it) && k <= get<2>(*it)) {
    //             ok = false;
    //         }
    //     }
        
    //     if (ok) prez.insert({j, p, k}); 
    // }

    // map<int, int> poslowie;
    
    // for(auto it: prez) {
    //     int a = get<1>(it);
    //     int b = get<2>(it);
    //     auto it1 = poslowie.find(a);
    //     auto it2 = poslowie.find(b);
    //     int x = 0;
    //     int y = 0;
    //     if (it1 != poslowie.end()) {
    //         x = it1->second;
    //         poslowie.erase(a);
    //     }
    //     if (it2 != poslowie.end()) {
    //         y = it2->second;
    //         poslowie.erase(b);
    //     }
    //     if (x - 1 != 0) poslowie.insert({a, x + 1});
    //     if (y - 1 != 0) poslowie.insert({b, y - 1});
    // }

    // // for (const auto& [key, value] : poslowie) {
    // //     cout << key << " " << value << endl;
    // // }

    // int moment = 0;
    // int akt = 0;
    // int maks = 0;
    // for (const auto& [key, value] : poslowie) {
    //     akt += value;
    //     if (akt > maks) {
    //         maks = akt;
    //         moment = key;
    //     }
    // }
    

    cout << moment << " " << maks << endl;
    return 0;
}