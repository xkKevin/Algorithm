#include<iostream>
using namespace std;

void Merge(int A[], int p, int q, int r) {
	int n = q - p + 1;
	int m = r - q;
	int *left = new int[n+1];
	int *right = new int[m+1];
	for (int i = 0; i < n; i++) {
		left[i] = A[p + i];
	}
	for (int i = 0; i < m; i++) {
		right[i] = A[q + i + 1];
	}
	left[n] = INT_MAX;
	right[m] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if (left[i] > right[j]) {
			A[k] = right[j];
			j++;
		}
		else {
			A[k] = left[i];
			i++;
		}
	}
	delete left;
	delete right;
	return;
}

void MergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
		return;
	}
	return;
}

int main() {
	int A[8] = { 5,6,8,7,12,3,9,10 };
	MergeSort(A, 0, 7);
	for(int i=0;i<8;i++)
		cout << A[i] << " ";
	system("pause");
	return 0;
}