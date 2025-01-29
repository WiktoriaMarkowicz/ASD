#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    int n, m;
    cin >> n >> m;

    vector<vector<long long>> poziome(m);
    vector<vector<long long>> pionowe(n);


    for (int i = 0;  i < m; i++) {
        long long x = 0;
        for(int j = 0; j < n - 1; j++) {
            int a;
            cin >> a;
            x += a;
            poziome[i].push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        long long x = 0;
        for(int j = 0; j < m - 1; j++) {
            int a;
            cin >> a;
            x += a;
            pionowe[i].push_back(x);
        }
    }

    long long minimum = LONG_LONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        long long x = 0;
        x = poziome[0][i] + poziome[m - 1][n - 2] - poziome[m - 1][i]; 
        if (m > 1) x += pionowe[i + 1][m - 2];
        minimum = min(minimum, x);
    }

    for(int i = 0; i < m - 1; i++) {
        long long x = 0;
        x = pionowe[0][i] + pionowe[n - 1][m - 2] - pionowe[n - 1][i]; 
        if (n > 1) x += poziome[i + 1][n - 2];
        minimum = min(minimum, x);
    }

    cout << minimum << endl;

    // for (int i = 0; i < m;  i++) {
    //     for (int j = 0; j < n - 1; j++) {
    //         cout << poziome[i][j] << " ";
    //     }
    //     cout << endl;
    // }
   
    // for (int i = 0; i < m; i++) {
    //     int a;
    //     int x = 0;
    //     vector<int> nowy;
    //     for (int j = 0; j < n - 1; j++) {
    //         cin >> a;
    //         x += a;
    //         nowy.push_back(x);
    //     }
    //     poziome.push_back(nowy);
    // }

    
    // for (int i = 0; i < n; i++) {
    //     int a;
    //     int y = 0;
    //     vector<int> nowy;
    //     for (int j = 0; j < m - 1; j++) {
    //         cin >> a;
    //         y += a;
    //         nowy.push_back(y);
    //     }
    //     pionowe.push_back(nowy);
    // }

    // long long najkrotsza = INT_MAX;
    // for (int i = 0; i < m; i++) {
    //     long long pom = poziome[i][n - 2];
    //     //cout << pom << endl;
    //     if (i == 0) {
    //         pom += pionowe[n - 1][m - 2];
    //     } else if (i == m -1) {
    //         pom += pionowe[0][m - 2];
    //     } else {
    //         pom += pionowe[0][i - 1] + pionowe[n - 1][m - 2] - pionowe[n - 1][i - 1];
    //     }

    //     najkrotsza = min(najkrotsza, pom);
    // }

    // for (int i = 0; i < n; i++) {
    //     long long pom = pionowe[i][m - 2];
    //     //cout << pom << endl;
    //     if (i == 0) {
    //         pom += poziome[m - 1][n - 2];
    //     } else if (i == n - 1) {
    //         pom += poziome[0][n - 2];
    //     } else {
    //         pom  += poziome[0][i - 1] + poziome[m - 1][n - 2] - pionowe[n - 1][i - 1];
    //     }
    // }

    // cout << najkrotsza;

    return 0;
}