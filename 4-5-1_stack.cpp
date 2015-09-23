#include<iostream>
#include<stack>
using namespace std;

int main(){
  stack<int> S;

  S.push(3);  //スタックに３を積む
  S.push(7);  //スタックに７を積む
  S.push(1);  //スタックに１を積む
  cout << S.size() << endl;

  cout << S.top() << " ";
  S.pop();

  cout << S.top() << " ";
  S.pop();

  cout << S.top() << " ";

  S.push(5);

  cout << S.top() << " ";
  S.pop();

  cout << S.top() << endl;

  return 0;
}