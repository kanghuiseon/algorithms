## 1920. 수찾기
전형적인 이분 탐색 문제 

A배열을 정렬하고 M개의 숫자를 받을 때마다 이분탐색을 실행해서 해당 숫자가 존재하는지 아닌지를 판단했다.
```cpp
bool binary_search(int num){
    int left = 0, right = n;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == num)
            return true;
        if(arr[mid] <= num){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}
```
