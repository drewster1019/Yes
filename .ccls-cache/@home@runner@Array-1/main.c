#include <stdio.h>
#define SIZE 200

int isPrime(int x) {
    if (x <= 1) {
      return 0;
    }

    for (int i = 2; i < x; i++) {
      if (x % i == 0) {
        return 0;
      }
    }

    return 1;
  }

void PrimeMatching(int arr1[], int size1, int arr2[], int size2) {
  int commonPrimes[SIZE];
  int commonCount = 0;

  for (int i = 0; i < size1; i++) {
    for (int j = 0; j < size2; j++) {
      if (arr1[i] == arr2[j] && isPrime(arr1[i])) {
        commonPrimes[commonCount] = arr1[i];
        commonCount++;
      }
    }
  }

  printf("Common prime numbers are:");
  for (int i = 0; i < commonCount; i++) {
    printf(" %d", commonPrimes[i]);
  }
  printf("\nCommon count: %d\n", commonCount);
}

int findSmallest(int arr[], int size) {
  int smallest = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] < smallest) {
      smallest = arr[i];
    }
  }

  return smallest;
}
int findLargest(int arr[], int size) {
  int largest = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }

  return largest;
}

int main(void) {

  int n, m;

  printf("Enter n and m: ");
  scanf("%d %d", &n, &m);

  int arr1[SIZE], arr2[SIZE];

  printf("Enter data for first list: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr1[i]);
  }

  printf("Enter data for second list: ");
  for (int i = 0; i < m; i++) {
    scanf("%d", &arr2[i]);
  }
  
  PrimeMatching(arr1, n, arr2, m);

  int smallest = findSmallest(arr2, m);
  int largest = findLargest(arr2, m);

  printf("Smallest number in the second list: %d\n", smallest);
  printf("Largest number in the second list: %d\n", largest);

  return 0;
}
