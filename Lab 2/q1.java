import java.util.Scanner;

class Main {
  public static int binarySearch(int[] arr, int l, int r, int x) {
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

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    System.out.print("Enter size of array: ");
    int n = sc.nextInt();
    
    int[] arr = new int[n];
    
    System.out.print("Enter elements of array: ");
    for(int i=0; i<n; i++) {
      arr[i] = sc.nextInt();
    }

    System.out.print("Enter key to search: ");  
    int x = sc.nextInt();

    int result = binarySearch(arr, 0, n-1, x);

    if (result == -1)
      System.out.println("Element not found");
    else
      System.out.println(x + " found at index " + result);
    
    System.out.println("Number of comparisons: " + (result + 1));
  }
}
