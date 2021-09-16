#include<iostream>
#include<vector>
using namespace std;

const int maxn = 100;
int tree[maxn];//树的高度
int n;//树的数目

int main(){
    //处理输入
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&tree[i]);

    //设置快慢指针
    int slow = 1;
    int fast = 2;

    //c标记前一轮的大小关系
    //进行c的初始化
    int c = 0;
    if(tree[1]-tree[0] == 0)
        c = 0;
    else if(tree[1]-tree[0] > 0)
        c = 1;
    else 
        c = -1;

    //每一轮连续的树的数目
    int ans = 0;
    if(c != 0)
        ans = 2;
    else
        ans = 0;

    vector<int> temp;//记录单调的值
    while(fast < n){
        //持续递增
        if((c == 1 && tree[fast]-tree[slow] > 0) || (c == -1 && tree[fast]-tree[slow] < 0)){
            
            //递减或递增
            ans++;
        }
        //转折但不为0
        else if((c == 1 && tree[fast]-tree[slow] < 0) || (c == -1 && tree[fast]-tree[slow] > 0)){
            temp.push_back(ans);//将此次记录下来
            c = -c;
            ans = 2;//重置计数器
        }
        //由0到非0
        else if(c == 0 && tree[fast]-tree[slow] != 0){
            ans = 2;
            if(tree[fast]-tree[slow] < 0)
                c = -1;
            else 
                c = 1;
        }
        //由非0到0
        else if(c != 0 && tree[fast]-tree[slow] == 0){
            temp.push_back(ans);
            c = 0;
        }
        fast++;
        slow++;
    }
    temp.push_back(ans);//存储最后一轮的结果

    int max = 0;//记录最终结果
    int t = temp.size();
    for(int i=0;i<t;i++){
        if(max < temp[i]){
            max = temp[i];
        }
    }

    //测试样例：1?1?2?2?3?4?4?4?4?5?6?7

    
    system("pause");
    return 0;
}

