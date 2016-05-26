#include<bits/stdc++.h>

using namespace std;

int getMax(int arr[], int l, int h){
	int mid = l + (h-l)/2;

	if(l==h)	return arr[l];
	if(h==l+1)	return arr[h]>arr[l]?arr[h]:arr[l];

	//important case
	if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])	return arr[mid];

	if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1])	return getMax(arr, l, mid-1);
	else	return getMax(arr, mid+1,h);
}

//max element in array which is first increasing, then decreasing
int main(){
	int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};

	int len=sizeof(arr)/sizeof(int)-1;

	cout << getMax(arr, 0, len-1) << endl;
	return 0;
}