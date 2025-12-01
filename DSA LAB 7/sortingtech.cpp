#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    
    for(int i=0; i<n1; i++) L[i]=arr[l+i];
    for(int i=0; i<n2; i++) R[i]=arr[m+1+i];
    
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    
    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void improvedSelectionSort(int arr[], int n){
    for(int i=0; i<n/2; i++){
        int min_idx = i;
        int max_idx = i;
        
        for(int j=i; j<n-i; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
            if(arr[j] > arr[max_idx]){
                max_idx = j;
            }
        }
        
        swap(arr[i], arr[min_idx]);
        
        if(max_idx == i){
            max_idx = min_idx;
        }
        swap(arr[n-1-i], arr[max_idx]);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = 7;
    
    cout << "Original: ";
    printArray(arr1, n1);
    
    int arr2[7];
    for(int i=0; i<7; i++) arr2[i]=arr1[i];
    selectionSort(arr2, n1);
    cout << "Selection Sort: ";
    printArray(arr2, n1);
    
    for(int i=0; i<7; i++) arr2[i]=arr1[i];
    insertionSort(arr2, n1);
    cout << "Insertion Sort: ";
    printArray(arr2, n1);
    
    for(int i=0; i<7; i++) arr2[i]=arr1[i];
    bubbleSort(arr2, n1);
    cout << "Bubble Sort: ";
    printArray(arr2, n1);
    
    for(int i=0; i<7; i++) arr2[i]=arr1[i];
    mergeSort(arr2, 0, n1-1);
    cout << "Merge Sort: ";
    printArray(arr2, n1);
    
    for(int i=0; i<7; i++) arr2[i]=arr1[i];
    quickSort(arr2, 0, n1-1);
    cout << "Quick Sort: ";
    printArray(arr2, n1);
    
    for(int i=0; i<7; i++) arr2[i]=arr1[i];
    improvedSelectionSort(arr2, n1);
    cout << "Improved Selection Sort: ";
    printArray(arr2, n1);
    
    return 0;
}