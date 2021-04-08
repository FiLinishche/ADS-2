// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = j + 1; j < len; j++) {
      count = count + 1;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count, right = len, left = 0;
  int mid;
  while (left < right - 1) {
    mid = (left + right) / 2;
    if (arr[mid] <= value)
      left = mid;
    else
      right = mid;
  }
  len = right;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count = count + 1;
    }
  }
  return count;
  
}

int countPairs3(int *arr, int len, int value) {
  int left = 0, right = len, middle;
  while (left < right - 1) {
    middle = (left + right) /2;
    if (arr[middle] <= value)
      left = middle + 1;
    else
      right = middle;
  }
  len = right;
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (left < right - 1) {
      middle = (left + right) / 2;
      if (arr[i] + arr[middle] == value) {
        counter++;
        int j = middle + 1;
        while (arr[i] + arr[j] == value && j < right) {
          counter++;
          j++;
        }
        j = middle - 1;
        while (arr[i] + arr[j] == value && j > left) {
          counter ++;
          j--;
        }
        break;
      }
      if (arr[i] + arr[middle] > value)
        right = middle;
      else
        left = middle;
    }
  }
  return counter;
}
