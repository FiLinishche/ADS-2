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
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int num = value - arr[i];
    int l = i + 1, r = len - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (arr[m] < num)
        l = m + 1;
      else
        r = m;
    }
    if (arr[l] == num) {
      while (arr[l] == num) {
        count++;
        l++;
      }
    }
  }
  return count;
}
