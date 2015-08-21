#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//in place, merge sort, sort, inplace, mergesort
//only change in merge function
//add optimization checks
//move elements by 1 to crush the element being moved(j)
//then move it to the appropriate pos(i)

void merge(vector<int> &arr, int p, int mid, int q){
	int i=p,j=mid+1,k=0;
	if(arr[mid]<=arr[mid+1])
		return;

	while(i<=mid && j<=q){
		if(arr[i]<=arr[j]){
			i++;
		} else {
			int temp = arr[j];
			copy(arr.begin()+i, arr.begin()+mid+1, arr.begin()+i+1);
			//for(int x=mid;x>=i;x--)	arr[x+1] = arr[x];
			arr[i] = temp;
			i++, j++, mid++;
		}
	}
}

void mergeSort(vector<int> &arr, int p, int q){
	int mid = (p+q)/2;
	if(p<q){
		mergeSort(arr, p, mid);
		mergeSort(arr, mid+1, q);
		merge(arr, p, mid, q);
	}
}

void mergeSort(vector<int> &arr){
	mergeSort(arr, 0, arr.size()-1);
}

int main(){
	int arr[] = {5,1,3,4,2,0,6,7,8};
	vector<int> v(arr,arr+sizeof(arr)/sizeof(int));

	mergeSort(v);

	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		cout << v[i] << endl;
	return 0;
}
