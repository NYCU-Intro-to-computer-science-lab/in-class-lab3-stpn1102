#include <iostream> 
#include <cmath>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int sq = sqrt(n);
    for (int i = 3; i <= sq; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n/2; ++i) {
        if (isPrime(i) && isPrime(n - i)) {
            cout << i << " " << n - i << endl;
            break;
        }
    }
    return 0;
}
