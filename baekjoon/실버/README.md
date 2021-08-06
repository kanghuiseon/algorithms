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


## 2110. 공유기 설치 (실버 1)
### 시간 복잡도
이분 탐색 문제!

문제를 보고 처음에는 인덱스 0 부터 마지막 집의 인덱스까지를 보고 거리를 하나하나 계산하는 생각을 했다.

근데 이렇게 되면 집의 좌표의 최대가 십억이라 O(N)으로 봐도 10초가 걸리기 때문에 시간 초과가 나올 것이다.

그래서 이분 탐색을 이용해서 logN, 집의 개수 만큼 보니까 N, 합해서 O(NlogN)이면 되겠다 싶었다.

### 구현
**두 공유기 사이의 최대 거리**를 구하는 것이니까 이걸 기준으로 이분 탐색을 진행하였다.

 우선 배열에서 나올 수 있는 최대 거리를 right로 잡고 최소 거리를 left로 설정했다.

Mid 값을 최대 거리로 보고, 첫번째 집부터 최대 거리 이상의 거리에 있는 집에 공유기를 놓도록 했다.

for문을 다 돌고나서 공유기의 수가 c보다 크거나 같다면 공유기를 놓을 수 있다는 말이니까 최대 공유기 수를 조금 늘려도 되겠지? 하면서 left = mid + 1을 해준다.

물론 이 부분에 mid 값과 Max값을 비교해서 더 큰 값을 Max에 넣어준다.

만약 공유기 수가 c보다 작으면 최대 공유기 수가 크구나! 그럼 줄여야지 라고 해서 right = mid - 1 을 해준다.

```cpp
int left = 1; int right = arr.back();
    int Max = -1;
    while(left <= right){
        int mid = (left + right)/2;
        int start = arr[0];
        int cnt = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-start >= mid){
                start = arr[i];
                cnt++;
            }
        }
        if(cnt >= c){
            left = mid + 1;
            Max = max(Max, mid);
        }
        else{
            right = mid - 1;
        }
}
```
