/*
描述
把代码补充完整，定义Array类，以实现如下的输出。Array类只保存构造函数的数组参数中不重复的数字，Array类的add方法用于把参数中新出现的数字保存在已有数字的后面，Array类的display方法用于显示保存的所有数字。其他地方不得添加代码。

#include<iostream>
using namespace std;
//这里应该是Array类的定义
int main()
{
 int a[] = { 4,1,2,3,4,1,3,5,1 };
 int b[] = { 5,4,10,4,2,7,7 };
 Array array1(a, sizeof(a) / sizeof(int)); //这时array1里应当保存4、1、2、3、5
 Array array2(b, sizeof(b) / sizeof(int)); //这时array2里应当保存5、4、10、2、7
 array1.display(); //按照保存的先后顺序输出所有数字，用空格相隔 4 1 2 3 5
 array2.display(); // 5 4 10 2 7
 array1.add(&array2); //把array2中的数字加入到array1中，但不包括已经在array1中出现的数字
 array1.display(); //4 1 2 3 5 10 7
 return 0;
}


输入
无

输出
4 1 2 3 5
5 4 10 2 7
4 1 2 3 5 10 7


样例输入


样例输出
4 1 2 3 5
5 4 10 2 7
4 1 2 3 5 10 7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 这里应该是Array类的定义
class Array
{
    vector<int> vec;

public:
    Array(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int key = arr[i];
            if (find(vec.begin(), vec.end(), key) == vec.end())
            {
                vec.push_back(key);
            }
        }
    }
    
    void display()
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i == vec.size() - 1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }

    void add(Array *arr)
    {
        for (int i = 0; i < arr->vec.size(); i++)
        {
            int key = arr->vec[i];
            if (find(vec.begin(), vec.end(), key) == vec.end())
            {
                vec.push_back(key);
            }
        }
    }
};
int main()
{
    int a[] = {4, 1, 2, 3, 4, 1, 3, 5, 1};
    int b[] = {5, 4, 10, 4, 2, 7, 7};
    Array array1(a, sizeof(a) / sizeof(int)); // 这时array1里应当保存4、1、2、3、5
    Array array2(b, sizeof(b) / sizeof(int)); // 这时array2里应当保存5、4、10、2、7
    array1.display();                         // 按照保存的先后顺序输出所有数字，用空格相隔 4 1 2 3 5
    array2.display();                         // 5 4 10 2 7
    array1.add(&array2);                      // 把array2中的数字加入到array1中，但不包括已经在array1中出现的数字
    array1.display();                         // 4 1 2 3 5 10 7
    return 0;
}
