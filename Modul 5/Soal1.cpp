#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void insertionSort(vector<char>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<char>& arr, size_t l, size_t m, size_t r) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
    vector<char> L(n1), R(n2);
    for (size_t i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (size_t i = 0; i < n2; ++i)
        R[i] = arr[m + 1 + i];
    size_t i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<char>& arr, size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void shellSort(vector<char>& arr) {
    for (size_t gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < arr.size(); ++i) {
            char temp = arr[i];
            size_t j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int partition(vector<char>& arr, int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(vector<char>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void selectionSort(vector<char>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void printVector(const vector<char>& arr) {
    for (char c : arr)
        cout << c;
    cout << endl;
}

int main() {
    string nama = "Muhammad Fadillah";
    string nim = "2410817210001";
    vector<char> namaVec(nama.begin(), nama.end());
    vector<char> nimVec(nim.begin(), nim.end());

    while (true) {
        cout << "\n--- MENU SORTING ---\n";
        cout << "1. Insertion Sort (Nama)\n";
        cout << "2. Merge Sort (Nama)\n";
        cout << "3. Shell Sort (Nama)\n";
        cout << "4. Quick Sort (NIM)\n";
        cout << "5. Bubble Sort (NIM)\n";
        cout << "6. Selection Sort (NIM)\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";

        int pilih;
        cin >> pilih;

        switch (pilih) {
            case 1: {
                auto temp = namaVec;
                insertionSort(temp);
                cout << "Hasil Insertion Sort (Nama): ";
                printVector(temp);
                break;
            }
            case 2: {
                auto temp = namaVec;
                mergeSort(temp, 0, temp.size() - 1);
                cout << "Hasil Merge Sort (Nama): ";
                printVector(temp);
                break;
            }
            case 3: {
                auto temp = namaVec;
                shellSort(temp);
                cout << "Hasil Shell Sort (Nama): ";
                printVector(temp);
                break;
            }
            case 4: {
                auto temp = nimVec;
                quickSort(temp, 0, temp.size() - 1);
                cout << "Hasil Quick Sort (NIM): ";
                printVector(temp);
                break;
            }
            case 5: {
                auto temp = nimVec;
                bubbleSort(temp);
                cout << "Hasil Bubble Sort (NIM): ";
                printVector(temp);
                break;
            }
            case 6: {
                auto temp = nimVec;
                selectionSort(temp);
                cout << "Hasil Selection Sort (NIM): ";
                printVector(temp);
                break;
            }
            case 7:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}