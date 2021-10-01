# 알고리즘 설명! (골드) (스터디용은 제외)
## 16236. 아기 상어 (골드 4)
어렵다… 응용이 왜이렇게 안될까… 열심히 풀어야겠다….ㅠㅠ

### 구현
1. 현재 위치에서 bfs 하기
2. bfs에서 먹을 수 있는 물고기를 eating vector에 넣는다.
3. 만약 0이거나 사이즈가 같으면 그냥 check만 해주고 queue에만 넣는다.
4. bfs가 끝나면 check배열 초기화하고 만약 eating 배열이 비어있지 않다면 (먹을게 있다면) eat++, tt+=eating[0].first, 먹은 곳은 0으로 처리해주고 아기 상어의 위치도 현재 먹은 위치로 업데이트 해준다.

여기서 tt는 전체 걸린 시간인데, 전역으로 tt++을 해줬더니 같은 시간으로 이동했지만 다른 위치에 있는 경우에 먼저 본 경우가 시간이 더 짧은 경우가 생겼다.

그래서 queue<pair<**int**, pair<**int**, **int**>>> q; 로 queue를 선언하고 가장 앞의 부분을 time으로 넣어주고, eating배열에 넣을 때 시간도 같이 넣어줘서 eating배열에서 뺄때 tt값을 더해줬다.

6. 만약 eating배열이 비었다면 더 이상 먹을게 없다는 말이니까 while문을 나간다.

### 사족
처음에 풀때 엄청 헤맸다. 한번의 bfs로 어떻게든 해보려고 용쓰다가 못하겠어서 거의 포기 직전까지 갔었다….

체크배열을 사용하면 이전에 체크되어 있는 곳은 못가고 체크 배열을 사용하지 않으면 무한루프돌고…..

친구가 그럼 체크배열을 초기화하고 다시 bfs를 돌면 어때? 라고 해주지 않았다면 시간이 오래 지나고 난 후에야 풀 수 있었을 것이다….

고착된 방식에서 머물러 있지 않고 방식의 추가나 제거에 대해서 좀 더 넓게 생각해야겠다는 생각(?)을 했다.



## 15683. 감시 (골드 5)
처음에는 현재의 cctv위치 사방을 보고 최대로 많이 볼 수 있는 방향으로 cctv의 방향을 설정했다. (모든 cctv에 대해서)

이렇게 하면 현재는 가장 많이 0을 채울 수 있을 지는 몰라도 전체적으로 봤을때는 최적의 답이 아닐 수 있게 된다.
```cpp
반례
4 6
2 6 0 3 0 2
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 6 1
8
```

그래서 dfs를 이용해서 전체의 경우의 수를 봐서 완전탐색으로 문제를 풀었다.
```cpp
case 4:
        fill_cctv(x, y, 0);
        fill_cctv(x, y, 1);
        fill_cctv(x, y, 3);
        dfs(cnt+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = tmp[i][j];
            }
        }
        fill_cctv(x, y, 0);
        fill_cctv(x, y, 2);
        fill_cctv(x, y, 3);
        dfs(cnt+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = tmp[i][j];
            }
        }
        fill_cctv(x, y, 0);
        fill_cctv(x, y, 1);
        fill_cctv(x, y, 2);
        dfs(cnt+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = tmp[i][j];
            }
        }
        fill_cctv(x, y, 1);
        fill_cctv(x, y, 2);
        fill_cctv(x, y, 3);
        dfs(cnt+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = tmp[i][j];
            }
        }
        break;
```
Cctv 4의 경우만 보자. (0, 1, 2, 3 순서대로 오른쪽, 왼쪽, 아래, 위를 의미)

Cctv4에서 보는 각 방향에 따라서 cctv가 닿는 곳에 -1을 넣어준다.
그리고나서 Dfs(cnt+1)를 들어가서 다음 cctv를 본다.

dfs가 끝나면 이전의 배열로 다시 만들어주고 다시 다른 방향을 본다. 이렇게 전체 방향에 대한 완전탐색을 진행한다.


아직 많이 부족하다!!!!

## 2580. 스도쿠 (골드 4)
0인 부분만 따로 zero벡터에 넣어서 진행했다.

0인 부분에 숫자 1~9를 차례대로 넣어보고 만약 넣는게 가능하다면 해당 숫자를 넣고 dfs를 들어갔다. 나왔을때는 꼭 0으로 초기화해줘야 한다.

체크를 할 때는 가로,세로,정사각형을 본다.

코드는 아래와 같다.
```cpp
bool checkSquare(int x, int y, int num){
    for(int i=x/3*3; i<x/3*3+3; i++){
        for(int j=y/3*3; j<y/3*3+3; j++){
            if(arr[i][j] == num)
                return false;
        }
    }
    return true;
}

bool checkLine(int x, int y, int num){
    // 가로
    for(int i=0; i<9; i++){
        if(arr[x][i] == num){
            return false;
        }
    }
    // 세로
    for(int i=0; i<9; i++){
        if(arr[i][y] == num){
            return false;
        }
    }
    return true;
}
```
* 정사각형 : 각각의 인덱스는 무조건 (0, 3, 6)부터 시작해야 하고, (3, 6, 9) 보다 작아야 한다.

파라미터로 들어오는 x, y값을 3으로 나누면 정사각형에 있는 숫자들은 다 같은 값을 가지게 되는데 이것을 이용하면 된다.

예를 들어서 x,y가 4,6이고 3으로 나누면 각각 1, 2이다. 
여기에 3을 곱하면 각각의 시작 인덱스가 나오고 거기에 3을 더하면 마지막 인덱스가 나온다. x의 경우 : 3 ~ 6(6은 포함 안함), y의 경우 : 6 ~ 9(9는 포함 안함)

이렇게 해서 만약 num이 존재 하면 그냥 return false 해버린다.

* 가로, 세로 : 가로 세로는 간단하게, x축만 움직이고, y축만 움직이는 식으로 진행하면 된다.

## 1939. 중량제한 (골드 4)
### 이분탐색 + bfs
입력 값 중 가장 큰 엣지 값을 Max값으로 가진다.

그리고 이 값을 물품의 무게라고 생각하고 이분 탐색을 진행한다.

만약 mid값 무게를 가지고 시작 지점에서 끝 지점으로 갈 수 있다면 mid 이후의 무게를 보고, 그렇지 않다면 mid 이전의 무게를 본다.

### 사족
처음에는 그냥 이전의 무게만을 가지고 bfs만으로 풀었다. 그런데 틀렸습니다가 나왔다.. 아직 왜 틀렸는지는 잘 모르겠다 좀 더 공부해야 겠다고 생각했다..


### 크루스칼
중량 제한이 큰 순으로 정렬을 하고, 만약 시작지와 도착지가 같은 집합에 속해 있지 않다면 두 노드를 합친다.

그리고 만약 같은 집합에 속해 있다면 바로 For문을 끝낸다. (이미 가장 큰 중량 제한을 찾았으므로)

## 1759. 암호 만들기 (골드 5)
우선 순열 + 증가하는순서로 코드를 짤려면 dfs들어가기 전에 정렬을 먼저 해준다.

모음이 최소 한개 있어야 하고, 자음이 최소 두개 있어야 하니까 파라미터로 현재까지의 갯수를 받도록 하고 현재까지의 String도 받도록 한다.

그리고 string의 수가 l 개면 모음, 자음 갯수를 체크하고 오름차순인지도 체크하고 만약 조건을 모두 충족하면 출력하고 리턴한다.

dfs가 끝나면 모음, 자음 갯수 원래대로 해주고 check를 풀어준다.

## 1261. 알고스팟 (골드 4)
### 구현
Priority queue를 이용한다. 

기존의 Max heap인 pq를 Min heap으로 바꾸고, 벽을 가장 적게 부신 부분이 가장 먼저 나오도록 한다.

나머지는 기본 Bfs와 동일!

## 2467. 용액 (골드 5)
### 구현
배열의 가장 첫번째를 left, 마지막을 right으로 설정한다.

만약 arr[left] + arr[right] 의 값이 마이너스이면 left++하고, 플러스이면 right- -를 한다.(값을 더 줄여서 0이랑 가까운 수가 있는지 없는지 체크하기 위함).

값을 비교할 때마다 차이의 최소를 계산해준다.

```cpp
int Min = 0x7fffffff;
int a=0, b=0;
int left = 0, right = arr.size()-1;
while(left < right){
    if(arr[left] + arr[right] < 0){
        if(Min > abs(arr[left]+arr[right])){
            Min = abs(arr[left] + arr[right]);
            a = arr[left]; b = arr[right];
        }
        left++;
    }
    else if(arr[left] + arr[right] > 0){
        if(Min > abs(arr[left]+arr[right])){
            Min = abs(arr[left] + arr[right]);
            a = arr[left]; b = arr[right];
        }
        right--;
    }
    else{
        printf("%d %d\n", arr[left], arr[right]);
        return 0;
    }
}
printf("%d %d\n", a, b);
```

## 2295. 세 수의 합
### 구현
N이 1000이므로 N^2은 시간 초과가 되지 않는다.

여기서 주요할 점은 v[I]+v[j]+v[k] = v[l]을 v[i] + v[j] = v[l] - v[k]로 보는 것이다.

그래서 두 수의 합을 먼저 구하도록 한다.

만약 v[l]-v[k]값이 앞서 구한 합 배열에 존재한다면 세 수의 합이 같은 배열에 존재한다는 얘기이다.

그러기 위해서 v를 내림차순으로 정렬하고 v2(sum 배열)를 오름차순으로 정렬한다.  

v를 내림차순으로 정렬하는 이유는 k번째 수가 가장 큰 수를 먼저 찾기 위해서이다.
 
그리고 binary_search함수를 이용해서 만야 v[i]-v[j]가 v2배열에 존재한다면 바로 출력하고 끝내도록 한다.
```cpp
vector<long long int> v2;
for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
        long long int sum = v[i] + v[j];
        v2.push_back(sum);
    }
}
sort(v.rbegin(), v.rend());
sort(v2.begin(), v2.end());
bool flag = false;
for(int i=0; i<v.size(); i++){
    for(int j=i; j<v.size(); j++){
        if(binary_search(v2.begin(), v2.end(), v[i]-v[j])){
            printf("%lld\n", v[i]);
            flag = true;
            break;
        }
    }
    if(flag)
        break;
}
```

### binary_search 함수
이진 탐색으로 값의 유무를 찾는 함수이다. 헤더 algorithm에 있다.

binary_search(arr.begin, arr.end, value)

배열 arr에서 찾으려는 value가 있다면 True, 그렇지 않으면 false를 리턴한다.

### 시간 초과
두 개의 합을 먼저 구하려고 이중 포문 안에 set.insert를 했다.

근데 set.insert가 nlogn이고 이중포문이 n^2이니까 총 n^3long이 걸려서 시간초과가 났다..

## 2470. 두 용액 (골드 5)
2467. 용액과 풀이 과정이 똑같음..! 처음에 배열 정렬만 추가해준다.

## 2473. 세 용액 (골드 4)
가장 바깥쪽에 for문으로 값을 하나 잡고, 그 안에서 left, right 이분 탐색을 진행한다. 

이렇게 되면 바깥 포문 N, 이분 탐색 (정렬 포함) NlogN 이므로 N^2logN이 된다.

그렇게 해서 가장 0에 가까운 세 수를 구한다.

그리고 세 수의 합이라 세 개 다 십억에 가까운 수면 대충 삼십억이 되므로 long long int로 해야 한다.

```cpp
sort(v.begin(), v.end());
long long int Min = 1e18;
long long int a=0, b=0, c=0;
for(int i=0; i<n-2; i++){
    long long int mid = v[i];
    int left = i+1;
    int right = n-1;
    while(left < right){
        if(abs(mid + v[left] + v[right]) < Min){
            Min = abs(mid + v[left] + v[right]);
            a=mid; b=v[left]; c=v[right];
        }
        if(mid + v[left] + v[right] < 0){
            left++;
        }
        else if(mid + v[left] + v[right] > 0){
            right--;
        }
        else{
            printf("%lld %lld %lld\n", mid, v[left], v[right]);
            return 0;
        }
    }
}
```

## 1477. 휴게소 세우기 (골드 4)
### 구현
고속도로의 정보를 벡터에 넣는다.

그리고 나서 이분탐색을 진행하는데 mid값이 의미하는 것은 **새로 지을 휴게소와 기존의 휴게소 사이의 거리** 이다.

그리고 휴게서 사이의 거리내에서 몇 개의 휴게소를 지을 것인지 결정하고 만약 기존에 존재하는 휴게소 위치이면 cnt- - 를 한다.
```cpp
int dist = v[i] - v[i-1];
cnt += dist/mid;
if(dist % mid == 0){
    cnt--;
}
```
만약 cnt가 지으려는 m보다 크다면 간격을 늘리고 (left = mid+1), m보다 작다면 현재 간격(mid)가 넓다는 얘기니까 줄인다. (right = mid)

### 사족
파라메트릭 서치가 좀 어려운것 같아서 더 공부해야겠다는 생각을 했다!

## 9084. 동전
현재 dp의 값이 의미하는 것은 해당 인덱스의 값을 만드는 방법의 수이다.

기존의 상태에서 현재 코인을 이용해 해당 금액을 만들고 싶다고 생각을 하면 될것같다.

냅색 문제는 어려워서 다른 분의 블로그 도움을 좀 받았는데 

그 분의 말에 의하면 현재 코인을 최종적으로 사용해서 현재 금액을 만들기라고 생각하면 된다고 한다.

```cpp
dp[0] = 1;
for(int i=0; i<coins.size(); i++){
    for(int j=coins[i]; j<=m; j++){
        dp[j] = dp[j] + dp[j-coins[i]];
    }
}
```

[얍문's Coding World..](https://yabmoons.tistory.com/556) 이분께 받았다!

## 2157. 여행 (골드4)
### 구현
dp[i][j]가 의미하는 것은 i번째 도시를 j번째로 도착했을때의 기내식 점수이다.
```cpp
int dfs(int cnt, int current){
    if(current == n){
        return 0;
    }
    if(cnt == m){
        return -MAX;
    }
    if(dp[current][cnt] != 0){
        return dp[current][cnt];
    }
    dp[current][cnt] = -MAX;
    for(int i=0; i<v[current].size(); i++){
        int next = v[current][i].first;
        int c = v[current][i].second;
        dp[current][cnt] = max(dp[current][cnt], dfs(cnt+1, next) + c);
    }
    return dp[current][cnt];
}
```
1. 현재 위치가 목적지이면 0을 리턴한다.
2. 목적지가 아닌데 방문한 도시의 수가 m이 되면 최저 값을 리턴한다.
3. 만약 현재 디피의 값이 0이 아니면 최대 기내식 점수가 있다는 말이므로 그 값을 리턴한다.
4. 그렇지 않으면 최저 값을 저장한다.
5. 현재 도시에서 갈 수 있는 도시들을 하나 씩 본다. 현재 디피의 값에는 현재의 값과 다음 목적지의 값에 다음 목적지의 기내식 값을 더한 값 중 **최대 값** 을 저장한다.
6. dp[1][1]에는 기내식의 가장 최대값이 저장될 것이다.

### 사담
디피… 언제쯤 잘하게 될까 아직도 너무 어렵다.

## 1103. 게임 (골드 2)
DP + DFS 문제
### 구현
```cpp
int dfs(int x, int y){
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    for(int i=0; i<4; i++){
        int num = arr[x][y];
        int nx = x + dx[i]*num;
        int ny = y + dy[i]*num;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 0){
            continue;
        }
        if(check[nx][ny]){
            printf("-1\n");
            exit(0);
        }
        check[nx][ny] = true;
        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
        check[nx][ny] = false;;
    }
    return dp[x][y];
}
```
기본적인 dp + dfs 문제이다. 

여기서 **키 포인트는** 갔던 길을 다시 갔는지를 체크하는 것이다. 만약 방문한 곳을 다시 한번 더 방문했다면 동전을 무한히 움직일 수 있다는 얘기니까 바로 -1 을 출력하고 끝내도록 한다.

 ## 17090. 미로 탈출하기 (골드 2)
DP + DFS 문제!
### 구현
dfs내에서 현재 위치의 문자열에 따라서 새로운 위치 값을 다르게 설정한다.

dp[x][y]의 값이 의미하는 바는 
1. 0 : 이미 방문한 곳인데 무한루프가 도는 곳이다.
2. 1 : 이미 방문한 곳인데 범위 밖으로 나갈 수 있다. (탈출할 수 있다.)
3. -1 : 아직 탐색하지 못한 곳이다.
```cpp
int dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 0;
    int nx, ny;
    switch(arr[x][y]){
        case 'U':
            nx = x-1; ny = y;
            break;
        case 'R':
            nx = x; ny = y+1;
            break;
        case 'D':
            nx = x+1; ny = y;
            break;
        case 'L':
            nx = x; ny = y-1;
            break;
        default:
            nx = -1; ny = -1;
            break;
    }
    dp[x][y] = dfs(nx, ny);
    return dp[x][y];
}
```
만약 범위를 벗어나면 1을 리턴하고 현재 위치가 이미 방문한 곳이면 바로 디피의 값을 리턴한다.


## 22254. 공정 컨설턴트 호석 (골드 4) 
이분탐색의 기준을 공정 라인의 수이다.

처음에는 mid값 크기의 배열을 새로 만들어서 작은곳을 계속 찾는? 방법으로 코드를 짜려고했는데 너무 비효율적인것 같다고 생각을 했다. (시간초과도 남 : 십만X십만이니까)

그래서 priority_queue를 이용해서 가장 작은 값을 뽑아서 그곳에다가 현재 공정의 시간을 더한 값을 더해서 다시 pq에 넣어주는 식으로 했다.

```cpp
bool process(int cnt){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<cnt; i++){
        pq.push(0);
    }
    for(int i=0; i<n; i++){
        int t = pq.top();
        pq.pop();
        pq.push(t+arr[i]);
    }
    int Max = 0;
    while(!pq.empty()){
        Max = pq.top();
        pq.pop();
    }
    if(Max > x){
        return false;
    }else{
        return true;
    }
}
```
1. 기존의 pq는 maxheap이니까 minheap으로 바꾸기 위해 greater조건을 넣었다.
2. 공정 라인 개수만큼 pq에 넣고 top을 빼서 거기에 현재 시간을 더해서 pq에 다시 넣는다. 이 과정을 n번 한다. (top의 값은 가장 작은 값임)
3. 그리고 pq의 가장 마지막 값(가장 큰 값)을 뽑고, 이 값이 x(시간 제한)보다 크면 false를 리턴하고 그렇지 않으면 true를 리턴한다.

### 사담
가장 작은 값을 다루는 문제가 나온다면 priority_queue를 사용하는 방법을 생각해보자!

## 1956. 운동 (골드 4)
이것도 기본적인 플로이드-와샬문제인데 거기에 사이클체크를 포함한다.

arr[i][i]는 현재 위치에서 운동을 시작해서 다시 시작점으로 돌아왔을 때의 거리의 최소값을 의미한다.

만약 여기의 값이 여전히 최대값이고 변하지 않았다면 현재위치로 다시 돌아오는 경우는 없다는 의미이다. (사이클이 존재하지 않는다는 의미)

이 값들 중 가장 작은 값을 출력하고 사이클이 아예 없는 경우에는 -1을 출력하도록 한다.

## 10159. 저울 (골드 3)
플로이드 와샬 문제!

물건의 크기가 큰 것을 작은 것의 부모로 두어서 트리를 만들었다.

플로이드 와샬 알고리즘을 사용하면 arr[i][j]는 i->j로 가는 최소의 길이 값을 가지는데 

만약 해당 노드에서 다른 어떤 노드로 가는 값이 여전히 MAX값을 가진다면 i->j , j->i 의 값을 몰라서 비교 결과를 알 수 없다는 말이므로 cnt++해준다.
```cpp
for(int i=1; i<=n; i++){
    int cnt = 0;
    for(int j=1; j<=n; j++){
        if(i == j)
            continue;
        if(arr[i][j] == MAX && arr[j][i] == MAX){
            cnt++;
        }
    }
    printf("%d\n", cnt);
}
```

## 1504. 특정한 최단 경로 (골드 4)
### 구현
1, v1, v2, n 이 네 가지 노드는 무조건 지나야 해서 처음에는 priority_queue에 1을 지났는지, v1을 지났는지, v2를 지났는지를 체크하는? 방식으로 진행을 했었는데, 메모리 초과가 계속 났다…

추측해보자면, queue에 너무 많이 들어갔거나..하는 이유인거 같은데 도저히 모르겠어서 

1->v1->v2->n or 1->v2->v1->n 이렇게는 무조건 나와야 하니까

각각의 경우에 대해서 다익스트라를 구현하는 방식으로 다시 코드를 바꿨다.

1->v1, v1->v2, v2->n, 1->v2, v1->n 이렇게 구했다. (V2->v1을 구하지 않은 이유가 양방향이어서 굳이 구할 필요가 없기 때문이다!)

그래서 1->v1->v2->n or 1->v2->v1->n 둘 중에 가장 거리가 짧은 값을 Min 변수에 넣고 

v1->v2가 무한대거나 (v1, v2가 이어지지 않은 경우), Min값이 MAX인 경우(1에서 n까지 못가는 경우) 에는 -1을 출력하고 그렇지 않으면 거리를 출력하도록 했다.

### Dijkstra 코드
```cpp
void dijkstra(int start){
    for(int i=1; i<=n; i++){
        dp[i] = MAX;
    }
    priority_queue<tt, vector<tt>, greater<tt>> pq;
    pq.push(make_pair(0, start));
    dp[start] = 0;
    while(!pq.empty()){
        int distance = get<0>(pq.top());
        int node = get<1>(pq.top());
        pq.pop();
        for(int i=0; i<arr[node].size(); i++){
            int nextNode = arr[node][i].first;
            int nextDistance = arr[node][i].second;
            if(dp[nextNode] > distance + nextDistance){
                dp[nextNode] = distance + nextDistance;
                pq.push(make_pair(distance + nextDistance, nextNode));
            }
        }
    }
}
```

### main 코드
```cpp
dijkstra(1);
int oneToV1 = dp[v1];
int oneToV2 = dp[v2];

dijkstra(v1);
int v1ToV2 = dp[v2];
int v1ToN = dp[n];

dijkstra(v2);
int v2ToN = dp[n];

int Min = MAX;
Min = min(Min, oneToV1 + v1ToV2 + v2ToN);
Min = min(Min, oneToV2 + v1ToV2 + v1ToN);
if(Min == MAX || v1ToV2 == MAX)
    printf("-1\n");
else{
    printf("%d\n", Min);
}
```

# 1719. 택배 (골드4)
플로이드 와샬 문제!

어떤 노드를 거쳐가는 값이 현재 위치의 값보다 작을 때, 거쳐가는 k값을 저장해준다.

만약 k를 거쳐가기 전에 거쳐간 노드가 존재한다면 그 노드의 숫자를 저장한다.

(if(arr[i][k] != MAX)	factory[i][j] = factory[i][k];)
```cpp
for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] > arr[i][k] + arr[k][j]){
                arr[i][j] = arr[i][k] + arr[k][j];
                if(arr[i][k] != MAX){
                    factory[i][j] = factory[i][k];
                }else{
                    factory[i][j] = k;
                }
            }
        }
    }
}
```

## 3109. 빵집 (골드 2)
dfs문제, 골드2번인데 너무 기본적인 dfs문제라서 왜 골드 2인지 잘 파악이 안됐던 문제.

### 구현
첫번째 열부터 dfs돌면서 오른쪽 위, 오른쪽, 오른쪽 아래 순서대로 확인한다.

만약 건물이거나 이미 앞에서 방문한 곳이면 가지 않는다. 이렇게 해서 마지막 열까지 도착하면 true를 리턴하고 이것의 개수를 센다.
