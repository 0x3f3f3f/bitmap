/*--- lldriver.c -------------------------- Listing 2-5 -------
 *  Reads in text words from the file specified on the command
 *  line and places them into two linked lists. Then exercises
 *  a variety of linked-list activities, printing the results
 *  at every step.
 *  Must be linked to linked-list primitives in Listings 2-2
 *  through 2-4b.
 *-------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class bitmap {
private:
    vector<size_t> _v; // 一个int代表二维的一个元素
public:
    bitmap(size_t si)
    {
        // 因为bitmap需要提前知道多少数据，构造二维的元素个数，+1是防止边界
        _v.resize(si >> 32 + 1); 
    }

    void set(size_t i)
    {
        int n = i / 32; 
        int m = i % 32;
        _v[n] |= 1 << m; // 为什么不是1 << (m - 1)因为，无符号数包括0，所以向左移动的时候，如果m = 2直接向左移动2，第一位表示0是不是存在
    }

    // 删除操作也是需要计算一维和二维的坐标，然后左移，取反操作，进行相与完成那一位从1到0的操作。
    void _delete(size_t i)
    {
        int n = i / 32;
        int m = i % 32; 
        _v[n] &= ~(1 << m);
    }
    // 查询操作和上面类似，只需要判断表示是不是1就可以
    void find(size_t i)
    {
        int n = i / 32;
        int m = i % 32;
        if ((_v[n] >> m) & 1)
        {
            cout << "数据存在" << endl;

        }
        else {
            cout << "数据不存在" << endl;
        }
    }
};

 int main(int argc, char* argv[])
 {

     ifstream infile;
     string str = "E:\\研究生\\实用算法\\实用lab\\实验2 双向链表的综合应用\\lab2extend.txt";
     infile.open(str.data());   //将文件流对象与文件连接起来 
     assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

     string s;
     bitmap b(1.5e5 + 10);
     // 文件的数据读入操作
     while (getline(infile, s))
     {
         b.set(stoi(s));
     }
     
     b.find(1234);
     infile.close();             //关闭文件输入流 
     return (EXIT_SUCCESS);
 }
