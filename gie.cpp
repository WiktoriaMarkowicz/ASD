#include<iostream>


using namespace std;


int main() {

    long long n;
    cin >> n;
    long long prev;
    if (n >= 1) cin >> prev;
    long long zysk = 0; 
    long long akt;
    long long kupno = -1;
    for (long long i = 1; i < n; i++) {
        cin >> akt;
        if (akt < prev && kupno != -1) { // zaczyna spadać cena, więc chcemy sprzedać po starej cenie(o ile mamy coś kupione)
            zysk += prev - kupno;
            kupno = -1;
        }
        if (akt > prev && kupno == -1) {
            kupno = prev;
        }
        if (i == n - 1 && kupno != -1) {
            zysk += akt - kupno;
        }
        prev = akt;
    }

    cout << zysk << endl;

    return 0;
}