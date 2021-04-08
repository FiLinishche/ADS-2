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
  int count = 0, left = 0, right = len - 1;
    while (left < right - 1) {
        int middle = (left + right) / 2;
        if (arr[middle] <= value)
            left = middle;
        else
            right = middle;
    }
    len = right - 1;
  for (int i = 0; i <len; i++) {
        left = i+1, right = len-1;
        int num = 0;
        while (left < right) {
            int m = (left + right) / 2;
            if (arr[m] < (value-arr[i]))
                left = m + 1;
            else
                right = m;
        }
    while (arr[left] == (value - arr[i])) {
        num++;
        left++;
    }
        count += num;
    }
    return count;
}
