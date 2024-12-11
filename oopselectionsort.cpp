#include<iostream>
using namespace std;
int n;
#define size 10
template <class T>
T sort(T arr[size]) {
    int i, j, min;
    T temp;
	for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "Sorted Array:" << endl;
    for (i = 0; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    int arr[size];
    float arr1[size];
    int i;
    int ch;

    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Selection sort on Integer values" << endl;
        cout << "2. Selection sort on Float values" << endl;
        cout << "3. Exit" << endl;
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number of elements:" << endl;
                cin >> n;
                cout << "Enter integer elements:" << endl;
                for (i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                sort(arr);
                break;

            case 2:
                cout << "Enter number of elements:" << endl;
                cin >> n;
                cout << "Enter float elements:" << endl;
                for (i = 0; i < n; i++) {
                    cin >> arr1[i];
                }
                sort(arr1);
                break;

            case 3:
                exit(0);
        }
    } while (ch != 3);

    return 0;
}

