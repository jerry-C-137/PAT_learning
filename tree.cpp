#include<iostream>
#include<vector>
using namespace std;

const int maxn = 100;
int tree[maxn];//���ĸ߶�
int n;//������Ŀ

int main(){
    //��������
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&tree[i]);

    //���ÿ���ָ��
    int slow = 1;
    int fast = 2;

    //c���ǰһ�ֵĴ�С��ϵ
    //����c�ĳ�ʼ��
    int c = 0;
    if(tree[1]-tree[0] == 0)
        c = 0;
    else if(tree[1]-tree[0] > 0)
        c = 1;
    else 
        c = -1;

    //ÿһ��������������Ŀ
    int ans = 0;
    if(c != 0)
        ans = 2;
    else
        ans = 0;

    vector<int> temp;//��¼������ֵ
    while(fast < n){
        //��������
        if((c == 1 && tree[fast]-tree[slow] > 0) || (c == -1 && tree[fast]-tree[slow] < 0)){
            
            //�ݼ������
            ans++;
        }
        //ת�۵���Ϊ0
        else if((c == 1 && tree[fast]-tree[slow] < 0) || (c == -1 && tree[fast]-tree[slow] > 0)){
            temp.push_back(ans);//���˴μ�¼����
            c = -c;
            ans = 2;//���ü�����
        }
        //��0����0
        else if(c == 0 && tree[fast]-tree[slow] != 0){
            ans = 2;
            if(tree[fast]-tree[slow] < 0)
                c = -1;
            else 
                c = 1;
        }
        //�ɷ�0��0
        else if(c != 0 && tree[fast]-tree[slow] == 0){
            temp.push_back(ans);
            c = 0;
        }
        fast++;
        slow++;
    }
    temp.push_back(ans);//�洢���һ�ֵĽ��

    int max = 0;//��¼���ս��
    int t = temp.size();
    for(int i=0;i<t;i++){
        if(max < temp[i]){
            max = temp[i];
        }
    }

    //����������1?1?2?2?3?4?4?4?4?5?6?7

    
    system("pause");
    return 0;
}

