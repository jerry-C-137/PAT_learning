#include <iostream>
#include <vector>

using namespace std;
/*
   从n整数中选择k个数，使得和为m，取平方和最大的数
*/
const int maxn = 30;
int n,k,m;

//获取n个数的输入
int A[maxn];

int maxSqu = 0;

vector<int> temp,ans;//存放输入

void DFS(int index,int nowK,int sum,int sumSqu);
int main(){
    scanf("%d %d %d",&n,&k,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

    DFS(0,0,0,0);
    
    int len =  ans.size();
    for(int i=0;i<len;i++)
        cout << " " << ans[i];

    system("pause");
    return 0;
}

void DFS(int index,int nowK,int sum,int sumSqu){
    if(nowK == k && sum == m){
        if(sumSqu > maxSqu){
            maxSqu = sumSqu;
            ans = temp;
        }
    }

    if(index == n || sum > m || nowK > k){
        return;
    }

    temp.push_back(A[index]);
    DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
    temp.pop_back();

    DFS(index+1,nowK,sum,sumSqu);//不选
}