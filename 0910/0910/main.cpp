#include<iostream>
using namespace std;

const int BUFFSIZE = 6;
void Selection_Sort(int Arr[]);

int main()
{
    int Arr[BUFFSIZE] = { 5,4,89,10,7,100}; //待排序元素
    Selection_Sort(Arr);
    
    return 0;
}

// 选择排序，从大到小排序
void Selection_Sort(int Arr[])
{
    for (int i = 0; i < BUFFSIZE-1 ; i++)
    {
        int index = i;
        for (int j = i + 1; j < BUFFSIZE; j++)
        {
            if (Arr[index] < Arr[j])
            {
                index = j;  //记录待排序元素中最大值的索引
            }
        }
        if (i != index)  // 将最大值移到前面
        {
            int tmp = Arr[i];
            Arr[i] = Arr[index];
            Arr[index] = tmp;
        }
    }
    //输出排序后的元素
    for (int i = 0; i < BUFFSIZE; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

