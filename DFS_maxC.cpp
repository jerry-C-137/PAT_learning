/*
    有n件物品，每件物品重量为w[i],价值为c[i]。现在需要选出若干件物品放入一个容量为V的背包中,
    使得在选入背包物品重量和不超过容量V的前提下，让背包中物品的价值之和最大
    求最大价值
*/

/*

5 8
3 5 1 2 2
4 5 2 1 3

*/

#include <iostream>

using namespace std;

const int maxn = 30;
void DFS(int index,int sumW,int sumC);

    int n,V;
    int ans = 0;//用于记录最终结果
    int w[maxn],c[maxn];//价值和重量数组
    int sumW,sumC = 0;//用于记录当下的重量总和和价值总和

int main(){
    //读入件数和最大容量
    scanf("%d %d",&n,&V);

    //读入两数组
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);    
    
    DFS(0,0,0);
    
    cout << ans << endl;
    system("pause");
    return 0;
}

void DFS(int index,int sumW,int sumC){
    if(index == n){
        if(sumW <= V && sumC > ans){
            ans = sumC;
        }
        return;
    }

    
    DFS(index+1,sumW,sumC);//选择第n件物品
    //剪纸
    if(sumW + w[index] <= V)
        DFS(index+1,sumW+w[index],sumC+c[index]);//不选择第n件物品
}