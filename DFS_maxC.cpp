/*
    ��n����Ʒ��ÿ����Ʒ����Ϊw[i],��ֵΪc[i]��������Ҫѡ�����ɼ���Ʒ����һ������ΪV�ı�����,
    ʹ����ѡ�뱳����Ʒ�����Ͳ���������V��ǰ���£��ñ�������Ʒ�ļ�ֵ֮�����
    ������ֵ
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
    int ans = 0;//���ڼ�¼���ս��
    int w[maxn],c[maxn];//��ֵ����������
    int sumW,sumC = 0;//���ڼ�¼���µ������ܺͺͼ�ֵ�ܺ�

int main(){
    //����������������
    scanf("%d %d",&n,&V);

    //����������
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

    
    DFS(index+1,sumW,sumC);//ѡ���n����Ʒ
    //��ֽ
    if(sumW + w[index] <= V)
        DFS(index+1,sumW+w[index],sumC+c[index]);//��ѡ���n����Ʒ
}