#include <gtest/gtest.h>
#include "../List_lib.h"
#include <list>
template<typename t>
void EqualList ( MyList test, std::list<t> &ex,int size)
{
    int sum  = 0;
    int index = 0;
    for (auto i = ex.cbegin(); i!=ex.cend(); i++)
    {
        if(test[index]== *i)
        {
            sum++;
            index++;
        }
    }
    assert(sum==size);
}
struct ListPub
{
    int si;
    Node *head;
    Node *tail;
    ListPub(Node *head,Node *tail,int si);
};
int GetHeadData (MyList &head) {
    void* voidptr = static_cast<void*>(&head);
    ListPub * p = static_cast<ListPub*>(voidptr);
    return p->head->data;
}
Node* GetHeadBegin (MyList &head) {
    void* voidptr = static_cast<void*>(&head);
    ListPub * p = static_cast<ListPub*>(voidptr);
    return p->head;
}
int GetTailData (MyList &tail) {
    void* voidptr = static_cast<void*>(&tail);
    ListPub * p = static_cast<ListPub*>(voidptr);
    return p->tail->data;
}
Node* GetTailEnd (MyList &tail) {
    void* voidptr = static_cast<void*>(&tail);
    ListPub * p = static_cast<ListPub*>(voidptr);
    return p->tail;
}
MyList  Init(int size, int arg)
{
    MyList o;
    for (int i = 0; i<size; i++)
    {
        o.PushBack(arg);
    }

    return o;
}

TEST(ListTestsSize, CreatingZero) {
    MyList test;
    std::list<int> ex_lis;
    assert(test.Size() == ex_lis.size());
}
TEST(ListTests, Empety) {
    MyList test;
    assert(test.IsEmpety() == 1);
}
TEST(ListTests, NotEmpety) {
    MyList test;
    test.PushBack(2);
    assert(test.IsEmpety() == 0);
}
TEST(ListTests, GeHead) {
    MyList test;
    test = Init(5,1);
    assert(test.Front() == GetHeadData(test));
}
TEST(ListTests, GeBegin) {
    MyList test;
    test = Init(5,1);
    assert(test.Begin() == GetHeadBegin(test));
}
TEST(ListTests, GeTail) {
    MyList test;
    test = Init(5,1);
    assert(test.Back() == GetTailData(test));
}
TEST(ListTests, GeEnd) {
    MyList test;
    test = Init(5,1);
    assert(test.End() == GetTailEnd(test));
}
TEST(ListTests, PushBack) {
    MyList test;
    test = Init(5,1);
    test.PushBack(2);
    std::list<int> ex_list = {1,1,1,1,1};
    ex_list.push_back(2);
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, PushFront) {
    MyList test;
    test = Init(5,1);
    test.PushFront(2);
    std::list<int> ex_list = {1,1,1,1,1};
    ex_list.push_front(2);
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, PopBack) {
    MyList test;
    test = Init(5,1);
    test.PopBack();
    std::list<int> ex_list = {1,1,1,1,1};
    ex_list.pop_back();
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, PopFront) {
    MyList test;
    test = Init(5,1);
    test.PopFront();
    std::list<int> ex_list = {1,1,1,1,1};
    ex_list.pop_front();
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, Claen) {
    MyList test;
    test = Init(5,1);
    test.clean();
    std::list<int> ex_list = {1,1,1,1,1};
    ex_list.clear();
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, ResizeLess) {
    MyList test;
    test = Init(5,1);
    test.Resize(4);
    std::list<int> ex_list = {1,1,1,1,1};
    ex_list.resize(4);
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, ResizeBetter) {
    MyList test;
    test = Init(5,1);
    test.Resize(6,2);
    std::list<int> ex_list = {1,1,1,1,1};
    ex_list.resize(6,2);
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, Swap) {
    MyList test1;
    test1 = Init(5,1);
    MyList test2 = Init(5,2);
    test1.Swap(test2);
    std::list<int> ex_list1 = {1,1,1,1,1};
    std::list<int> ex_list2 = {2,2,2,2,2};
    ex_list1.swap(ex_list2);
    EqualList(test1,ex_list1,test1.Size());
}
TEST(ListTests, Unique) {
    MyList test;
    test.PushBack(1);
    test.PushBack(2);
    test.PushBack(2);
    test.PushBack(1);
    test.PushBack(3);
    test.Unique();
    std::list<int> ex_list = {1,2,2,1,3};
    ex_list.unique();
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, Insert) {
    MyList test;
    test = Init(5,1);
    test.Insert(1,10);
    std::list<int> ex_list = {1,1,1,1,1};
    auto it = ex_list.cbegin();
    it++;
    ex_list.insert(it,10);
    EqualList(test,ex_list,test.Size());
}
TEST(ListTests, Erase) {
    MyList test;
    test = Init(5,1);
    test.Erase(1);
    std::list<int> ex_list = {1,1,1,1,1};
    auto it = ex_list.cbegin();
    it++;
    ex_list.erase(it);
    EqualList(test,ex_list,test.Size());
}
