#include <iostream> 
using namespace std;

void move(int disk, int from, int to) {
    if ((from == 1 && to == 3) || (from == 3 && to == 1)) {
        return;
    }
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
}

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;
    if ((from == 1 && to == 3) || (from == 3 && to == 1)) {
        hanoi(n, from, aux, to);   
        hanoi(n, aux, to, from);   
    } else {
        if (n == 1) {
            move(1, from, to);
            return;
        }
        hanoi(n-1, from, aux, to);
        move(n, from, to);
        hanoi(n-1, aux, to, from);
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    return 0;
}
