#include<stdio.h>
#include<string.h>
#define LEN 100005

/*プロセスを表す構造体*/
typedef struct pp{
  char name[100];
  int t;
} P;

P Q[LEN];
int head, tail, n;

void enqueue(P x){
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

P dequeue() {
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

/*最小値を返す*/
int min(int a, int b) { return a < b ? a : b; }

int main(){
  int elaps = 0, c;
  int i, q;
  P u;
  scanf("%d %d", &n, &q);

  /*すべてのプロセスをキューに順番に追加する*/
  for (i = 1; i <= n; i++){
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }
  head = 1; tail = n + 1;

  /*シミュレーション*/
  while( head != tail){
    u = dequeue();
    /*qまたは必要時間u.tだけ処理を行う*/
    c = min(q, u.t);
    /*残り必要時間を計算*/
    u.t -= c;
    /*経過時間を加算*/
    elaps += c;
    /*処理が完了しなければキューに追加*/
    if (u.t > 0 ) enqueue(u);
    else{
      printf("%s %d", u.name, elaps);
    }
  }
  return 0;
}