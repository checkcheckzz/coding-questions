/*

Implement bubble sort and merge sort

*/

/*

solution: bubble sort O(n^2) time, O(1) space, mergesort O(nlogn) average time, O(n) space

*/

#include<iostream>
using namespace std;


void BubbleSort(int arr[], int len) {

	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}

}
int *MergeInner(int arr1[], int len1, int arr2[], int len2) {
	int *res = new int[len1 + len2];
	int i = 0, j = 0, k = 0;
	while (i < len1 && j < len2) {
		if (arr1[i] < arr2[j]) {
			res[k++] = arr1[i++];
		} else {
			res[k++] = arr2[j++];
		}
	}
	while (i < len1) {
		res[k++] = arr1[i++];
	}
	while (j < len2) {
		res[k++] = arr2[j++];
	}

	return res;
}

void MergeSort(int arr[], int len) {
	if (len <= 1) return;
	int len1 = len / 2;
	int len2 = len - len1;
	int *arr1 = new int[len1];
	int *arr2 = new int[len2];

	int i = 0, k = 0;
	for (; i < len1; i++)
		arr1[k++] = arr[i];
	for (k = 0; i < len; i++)
		arr2[k++] = arr[i];

	MergeSort(arr1, len1);
	MergeSort(arr2, len2);

	int *res = MergeInner(arr1, len1, arr2, len2);
	for (int i = 0; i <len; i++)
		arr[i] = res[i];

	delete res;
	delete[] arr1;
	delete[] arr2;

}

void PrintArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main() {
    cout<<"Origal array is:"<<endl;
	
    int a[6] = {-1, 2, -8, 7, 6, 4};
    int b[6] = {-1, 2, -8, 7, 6, 4};
    PrintArr(a, 6);
    cout<<"After the bubblesort:"<<endl;
    BubbleSort(a,6);
    PrintArr(a, 6);
    cout<<"After the mergesort:"<<endl;
    MergeSort(b,6);
    PrintArr(b, 6);
    return 0;

}