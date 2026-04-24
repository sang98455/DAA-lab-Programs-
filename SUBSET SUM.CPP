#include <iostream>
using namespace std;

int setArr[20];
int subset[20];
int n, target;

void subsetSum(int i, int sum, int count) {

    if (sum == target) {
        cout << "Subset found: ";
        for (int j = 0; j < count; j++) {
            cout << subset[j] << " ";
        }
        cout << endl;
        return;
    }

    if (i == n || sum > target)
        return;

    subset[count] = setArr[i];

    subsetSum(i + 1,
              sum + setArr[i],
              count + 1);

    subsetSum(i + 1,
              sum,
              count);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> setArr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    subsetSum(0, 0, 0);

    return 0;
}