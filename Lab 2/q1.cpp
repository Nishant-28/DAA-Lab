#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
  int comp = 0;
  while (l <= r) {
    int m = l + (r - l)/2;
    comp++;
    if (arr[m] == x) {
      if (m == 0 || arr[m-1] != x)
        return m;
      else
        r = m - 1; 
    }
    else if (arr[m] > x)
      r = m - 1;
    else  
      l = m + 1;
  }
  return -1;
}

int main() {
  int n, x;
  
  cout << "Enter size of array: ";
  cin >> n;
  
  int arr[n];
  
  cout << "Enter elements of array: ";
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }

  cout << "Enter key to search: ";
  cin >> x;

  int result = binarySearch(arr, 0, n-1, x);

  if (result == -1) 
    cout << "Element not found";
  else
    cout << x << " found at index " << result << endl;

  cout << "Number of comparisons: " << result+1;

  return 0;  
}
