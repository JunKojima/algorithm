#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  int n, q, t;
  string name;

  //標準ライブラリからqueueを使用
  queue<pair<string, int> > Q;

  cin >> n >> q;

  //すべてのプロセスをキューに順番に追加する
  for (int i = 0; i < n; i++){
    cin >> name >> t;
    Q.push(make_pair(name,t));
  }

  pair<string, int> u;
  int elaps = 0, a;

  //シミュレーション
  while ( !Q.empty()){
    u = Q.front(); Q.pop();
    a = min(u.second, q); //qまたは必要時間u.tだけ処理を行う
    u.second -= a;        //残り時間を計算
    elaps += a;         //経過時間を加算
    if ( u.second > 0){
      Q.push(u);  //処理が完了していない場合はキューに追加
    }else{
      cout << u.first << " " << elaps << endl;
    }
  }

  return 0;
}