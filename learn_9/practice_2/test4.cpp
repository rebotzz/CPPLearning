#include <iostream>
#include <time.h>
using namespace std;


////编号为1到n的n个人围成一圈。从编号为1的人开始报数1，依次下去，
////报到m的人离开，问最后留下的一个人，编号是多少？
//int main() {
//    int n, m;
//    while (cin >> n >> m) { // 注意 while 处理多个 case
//
//        size_t begin = clock();
//        //数组
//        int* arr = new int[n];
//        //初始化
//        for (int i = 0; i < n; i++)
//        {
//            arr[i] = i ;
//        }
//
//        //遍历
//        int i = 0;
//        int num = 1;
//        int size = n;
//        while (size > 1)
//        {
//            if (arr[i] != -1)
//            {
//                i++;
//                if (i >= n) {
//                    i = 0;
//                }
//                num++;
//                if (num == m) {
//                    while (arr[i] == -1)
//                    {
//                        i++;
//                        if (i >= n)
//                        {
//                            i = 0;
//                        }
//                    }
//                    arr[i] = -1;
//                    size--;
//                    num = 1;
//                    i++;
//                    //if (size == 1)
//                    //{
//                    //    while (arr[i] == -1)
//                    //    {
//                    //        i++;
//                    //        if (i >= n)
//                    //        {
//                    //            i = 0;
//                    //        }
//                    //    }
//                    //    cout << arr[i] << endl;
//                    //    break;
//                    //}
//                }
//            }
//            else
//            {
//                i++;
//            }
//
//            if (i >= n) {
//                i = 0;
//            }
//        }
//
//
//        for (i = 0; i < n; i++)
//        {
//            if (arr[i] != -1)
//            {
//                cout << arr[i] << endl;
//            }
//        }
//        size_t end = clock();
//        cout << end - begin << endl;
//
//        delete[] arr;
//
//
//    }
//}


#include <iostream>
#include <time.h>
using namespace std;

//算法优化2.0    之前时间复杂度O(N!)
//环形链表
#include <assert.h>
//链表    cpp类封装,带头,双向,循环

//template<class T>
typedef int T;
//节点
class ListNode {
    friend class List;
public:
    //构造函数  初始化
    ListNode()
        : _val(0)
        , _prev(nullptr)
        , _next(nullptr)
    {}

    //private:
    T _val;
    ListNode* _prev;
    ListNode* _next;
};

//链表
//template<class T>
class List {
public:
    //构造函数  初始化
    List(ListNode* plist)
        : _phead(plist)
        , _size(0) {
        //_phead = (ListNode*)malloc(sizeof(ListNode));
        _phead->_next = _phead;
        _phead->_prev = _phead;
    }

    //析构函数  释放资源
    ~List() {
        //ListNode* cur = _phead->_next;
        //while (cur != _phead)
        //{
        //  ListNode* next = cur->_next;
        //  free(cur);
        //  cur = next;     //指向next
        //}
        //free(_phead);
    }

    //pos之前插入
    void PushInsert(T x, ListNode* pos) {
        //assert(pos);
        _size++;

        ListNode* newnode = BuyNode(x);
        ListNode* prev = pos->_prev;

        prev->_next = newnode;
        newnode->_next = pos;
        pos->_prev = newnode;
        newnode->_prev = prev;
    }

    ////pos之后插入
    //void PushAfter(const T x, ListNode* pos)
    //{
    //  //复用
    //  PushInsert(x, pos->_next);
    //}

    //BUG修复:逻辑修改,不是删除pos之前,是删除pos此位置
    void PopInsert(ListNode* pos) {
        //assert(pos);
        //assert(pos != _phead);
        _size--;

        ListNode* prev = pos->_prev;
        ListNode* next = pos->_next;
        //free(pos);
        prev->_next = next;
        next->_prev = prev;

    }

    //void PopAfter(ListNode* pos)
    //{
    //  //复用
    //  PopInsert(pos->_next);
    //}

    void PushBack(const T x) {
        PushInsert(x, _phead);
    }

    //void PushFront(const T x)
    //{
    //  PushAfter(x, _phead);
    //}

    void PopBack() {
        PopInsert(_phead->_prev);
    }

    //void PopFront()
    //{
    //  PopAfter(_phead);
    //}

    //元素个数
    int Size() {
        //ListNode* cur = _phead->next;
        //int size = 0;
        //while (cur != _phead)
        //{
        //  size++;
        //  cur = cur->_next;
        //}
        return _size;
    }

    //是否为空
    bool Empty() {
        return Size() == 0;
    }

    //ListNode* Find(const T x)
    //{
    //  ListNode* cur = _phead->_next;
    //  while (cur != _phead)
    //  {
    //      if (x == cur->_val)
    //      {
    //          return cur;
    //      }
    //      cur = cur->_next;
    //  }
    //  return nullptr;
    //}

    ////ListNode 有访问限定,不能直接修改数据,需要接口函数
    //void Change(const T x, ListNode* pos)
    //{
    //  pos->_val = x;
    //}

    void Print() {
        ListNode* cur = _phead->_next;
        while (cur != _phead) {
            cout << cur->_val << " ";
            cur = cur->_next;
        }
        cout << endl;
    }
protected:
    ListNode* BuyNode(T x) {
        //ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
        //if (nullptr == newnode)
        //{
        //  perror("BuyNode");
        //  exit(-1);
        //}

        ListNode* newnode = _phead + _size;

        newnode->_val = x;
        return newnode;
    }

    //private:
public:
    ListNode* _phead;
    int _size;
};

//int main() {
//    int n, m;
//    ListNode* plist = new ListNode[1000000 + 1];
//    List s(plist);
//
//    while (cin >> n >> m) { // 注意 while 处理多个 case
//        //初始化
//        //优化,一次开辟大空间,内存池
//        s._size = 0;
//        for (int i = 0; i < n; i++) {
//            s.PushBack(i + 1);
//        }
//        //s.Print();
//
//
//        //循环判断
//        ListNode* cur = s._phead->_next;
//        int count = 1;
//        while (1) {
//            //找到第m个序号的人
//            while (count < m) {
//                cur = cur->_next;
//                count++;
//
//                //跳过头节点
//                if (cur == s._phead) {
//                    if (!s.Empty()) {
//                        cur = cur->_next;
//                    }
//                    else {
//                        break;
//                    }
//                }
//            }
//
//            //杀掉序号第m个
//            if (s.Size() > 1 && cur != s._phead) {
//                //s.Print();
//                ListNode* next = cur->_next;
//                s.PopInsert(cur);
//                cur = next;
//                //跳过头节点
//                if (cur == s._phead && !s.Empty()) {
//                    cur = cur->_next;
//                }
//            }
//            count = 1;
//
//            //判断是否只剩一个人
//            if (s.Size() == 1) {
//                break;
//            }
//        }
//
//        //输出结果
//        s.Print();
//        //cout << s._phead->_next->_val;
//
//    }
//
//    delete[] s._phead;
//}
////优化,内存池