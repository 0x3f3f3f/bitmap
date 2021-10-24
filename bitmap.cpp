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
    vector<size_t> _v; // һ��int�����ά��һ��Ԫ��
public:
    bitmap(size_t si)
    {
        // ��Ϊbitmap��Ҫ��ǰ֪���������ݣ������ά��Ԫ�ظ�����+1�Ƿ�ֹ�߽�
        _v.resize(si >> 32 + 1); 
    }

    void set(size_t i)
    {
        int n = i / 32; 
        int m = i % 32;
        _v[n] |= 1 << m; // Ϊʲô����1 << (m - 1)��Ϊ���޷���������0�����������ƶ���ʱ�����m = 2ֱ�������ƶ�2����һλ��ʾ0�ǲ��Ǵ���
    }

    // ɾ������Ҳ����Ҫ����һά�Ͷ�ά�����꣬Ȼ�����ƣ�ȡ���������������������һλ��1��0�Ĳ�����
    void _delete(size_t i)
    {
        int n = i / 32;
        int m = i % 32; 
        _v[n] &= ~(1 << m);
    }
    // ��ѯ�������������ƣ�ֻ��Ҫ�жϱ�ʾ�ǲ���1�Ϳ���
    void find(size_t i)
    {
        int n = i / 32;
        int m = i % 32;
        if ((_v[n] >> m) & 1)
        {
            cout << "���ݴ���" << endl;

        }
        else {
            cout << "���ݲ�����" << endl;
        }
    }
};

 int main(int argc, char* argv[])
 {

     ifstream infile;
     string str = "E:\\�о���\\ʵ���㷨\\ʵ��lab\\ʵ��2 ˫��������ۺ�Ӧ��\\lab2extend.txt";
     infile.open(str.data());   //���ļ����������ļ��������� 
     assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

     string s;
     bitmap b(1.5e5 + 10);
     // �ļ������ݶ������
     while (getline(infile, s))
     {
         b.set(stoi(s));
     }
     
     b.find(1234);
     infile.close();             //�ر��ļ������� 
     return (EXIT_SUCCESS);
 }
