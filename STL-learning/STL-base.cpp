#include <bits/stdc++.h>
using namespace std;
int main(){
    /* 
    template<T>模板，用来构建可变类型的模板
    STL都是基于这种模板来建立的，所以一个容器可供不同容器使用
    所以STL的使用中全是.方法，而不是函数
    */

    // 1.vector
    cout << "---------------vector---------------" << endl;
    //声明
    vector<int> arr;
    vector<int> arr1(600, 6);
    cout << arr1[50] << endl;
    vector<vector<int>> arr2(10, vector<int>(6, 7));// 二维数组
    cout << arr2[6][5] << endl;
    vector<vector<vector<int>>> arr3(10,vector<vector<int>>(10,vector<int>(10,3))); //三维数组
    cout << arr3[1][2][3] << endl;
    // 常用方法
    arr1[0] = 1; cout << arr1[0] << endl;// 下标访问
    arr1.back();arr1.front();// 访问头尾元素
    arr1.push_back(1); cout << arr1[599] << endl << arr1[600]<<endl;// 在最后插入，会自动resize()
    arr1.insert(arr1.begin() + 1, 666);
    // .insert需要迭代器，同理.erase(a,b)两个迭代器，右边取不到
    cout << arr1.size() << endl; //601
    arr1.pop_back(); // 删除最后的一个，会自动resize()
    cout << arr1.size() << endl;// .size()返回数组长度600
    arr1.resize(666, 1);// 重新定义大小，后面的是多出来的初始化，如果len比已有size小，删到len
    arr1.clear();
    arr1.empty();// 清空和判断空

    // 2.stack
    cout << "---------------stack---------------" << endl;
    stack<int> stk; // 注意不能初始化
    // 常用方法
    stk.push(1);
    stk.push(2);// 后进先出，压栈
    stk.emplace(30);// 暂时等价于push
    // 注意栈没有下标访问！！！
    cout << stk.top() << endl;// top方法显示栈顶元素，有返回值
    cout << stk.size() << endl;
    stk.pop(); // 弹出栈顶，注意和python不同，没有返回值
    cout << stk.empty() << endl;  // 栈只有判断空，没有清空
    // 注意不能迭代访问stack内部元素
    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }

    // 3.queue
    cout << "---------------queue---------------" << endl;
    queue<double> que;
    que.push(1);
    que.emplace(2);
    que.push(3);
    cout << que.size() << endl;
    cout << que.front() << endl;// 先进先出
    cout << que.back() << endl;
    que.pop();// 弹出最先进的
    // 注意不能简单for循环访问stack内部元素
    while(!que.empty()){
        cout << que.front() << endl;
        que.pop();
    }

    // 4.priority_queue
    priority_queue<int> pque1;// 尖括号里是：类型，容器，比较器
    priority_queue<int, vector<int>, greater<int>> pque;
    // 优先队列相当于遵循某种排序的队列
    pque.push(1);
    pque.emplace(200);
    pque.emplace(10086);
    pque.push(66);
    cout << pque.top() << endl; // 但是这里是top而不是front
    pque.pop();
    cout << pque.empty() << endl;
    cout << pque.top() << endl;
    cout<< pque.size();

    // 5.set
    cout << "---------------set---------------" << endl;
    set<int> st{1,2,3,4,5};
    st.emplace(6);
    st.insert(9);
    cout << st.size() << endl;

    for (int x:st){
        cout << x << endl;
    } // 可以访问内部元素，但是只能迭代器访问，不能下标访问
    for (auto it = st.begin(); it != st.end();it++){
        cout << *it << endl;
    }
        cout << st.count(1) << endl; // 判断set里有没有某元素
    st.erase(1);
    st.erase(st.begin());
}
    // erase里既可以是元素也可以是迭代器
    /*
    这里详细讲解一下迭代器 iterator
    iterator实际上像是被STL类封装起来的专属指针
    iterator存储的也是地址( STL元素内的地址 )，但是它可以在STL容器里自动寻址、
    而原生指针的自加寻址p[x]或*(p+x)或*p++只能找连续的地址，但是STL的iterator可以自动地根据STL特性来向下一个元素寻址，哪怕它们不连续(比如链表)。迭代器可以找到链表下一个元素的地址（类内封装定义）
    声明迭代器的方法：
    1.set<int>::iterator it = st.begin(3);
    2.auto it = st.begin();
    3.auto it = next(st.begin(),3);这个是生成从begin开始往后3步的迭代器，即第4个元素开始
    4.auto it = st.rend();反向迭代器 
    迭代器的限制：有些迭代器只能++不能--，有些迭代器只能++/--不能+1/-1！！！注意这是不一样的。这里advance(it,2)是可以跳两个的，负数也可以。
    有些迭代器只能创建不能其他操作。（只读）
    */
