#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& nums, int l, int r){
	if (l >= r) return;
	int i = l, j = r, pivote = nums[l];
	while (i < j){
		while (i < j && pivote <= nums[j]) j--;
		nums[i] = nums[j];
		while (i < j && nums[i] <= pivote) i++;
		nums[j] = nums[i];
	}
	nums[i] = pivote;
	quickSort(nums, l, i-1);
	quickSort(nums, i+1, r);
}

int main(){
	int n, x;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	quickSort(nums, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << nums[i] << ' ';
	cout << endl;
	return 0;
}