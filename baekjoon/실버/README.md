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
## 1654. 랜선 자르기
이분 탐색의 기준을 랜선의 길이라고 생각하고 문제를 풀었다.

우선 K개의 랜선 중에서 최대 길이를 Right값으로 잡는다. 그 이유는 이 최대 길이보다 긴 랜선으로는 자를 수가 없기 때문이다.

그리고나서 mid값을 잡고 K개의 랜선을 Mid값으로 몇개를 만들 수 있는지를 세고나서 이 갯수가 N보다 작으면 랜선의 길이를 좀 더 줄이고 (right = mid), N보다 크면 랜선의 길이를 좀 더 늘린다. (Left = mid + 1) (최대 랜선의 길이를 찾고 싶으므로.)

```cpp
while(left < right){
        long long int mid = (left + right)/2;
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            cnt += arr[i] / mid;
        }
        if(cnt < n){
            right = mid;
        }
        else if(cnt >= n){
            left = mid + 1;
            answer = max(answer, mid);
        }
}
```
