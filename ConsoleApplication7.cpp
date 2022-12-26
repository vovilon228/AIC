#include <iostream>
using namespace std;
void swapping(int& a, int& b) {    
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void display(int* array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void merge(int* array, int l, int m, int r) {
    int i, j, k, nl, nr;
    //розмір зліва на право
    nl = m - l + 1; nr = r - m;
    int larr[nl], rarr[nr];
    //заповнити з ліва на право
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0; j = 0; k = l;
    //розміри до початкового
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        }
        else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {       //зайві елементи зліва
        array[k] = larr[i];
        i++; k++;
    }
    while (j < nr) {     //зайві елементи зправа
        array[k] = rarr[j];
        j++; k++;
    }
}
void mergeSort(int* array, int l, int r) {
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;
        //1 2 рядок
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];     //нумеруємо
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    display(arr, n);
    mergeSort(arr, 0, n - 1);     //(n-1) 
    cout << "Array after Sorting: ";
    display(arr, n);
}
