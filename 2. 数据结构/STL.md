# vector（变长数组）

倍增的思想，支持比较运算（按字典序）。

## 定义

```cpp
vector <int> a;			// 一个vector数组a
vector <int> a(10);		// 一个长度为10的vector数组a
vector <int> a(10, 3);	// 一个长度为10的vector数组a，并且所有元素都为3
```

## 常用函数

- `size()` ：返回元素个数（所有容器都有）
- `empty()` ：返回是否是空（所有容器都有）
- `clear()` ：清空
- `front()` ：返回 `vector` 的第一个数
- `back()` ： 返回 `vector` 的最后一个数
- `push_back()` ： 向 `vector` 的最后插入一个数
- `pop_back()` ： 把 `vector` 的最后一个数删掉
- `begin()` ： `vector` 的第0个数
- `end()` ： `vector` 的最后一个的数的后面一个数

## 倍增的思想

系统为某一程序分配空间时，所花费的时间，与空间大小无关，与申请次数有关。

## 遍历方法

假设有个`vector <int> a`

- 第一种

  ```cpp
  for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
  ```

- 第二种

  ```cpp
  for(vector <int>::iterator i = a.begin(); i != a.end(); i++) cout << *i << " ";
  ```

- 第三种

  ```cpp
  for(auto x : a) cout << x << " "; 
  ```



# pair

支持比较运算，以 `first` 为第一关键字，以 `second` 为第二关键字（按字典序）

## 定义

```cpp
pair <type1, type2> 变量名;
```

## 初始化方式

假设有个`pair <int, string> p`

- 第一种

  ```cpp
  p = make_pair(10, "abc");
  ```

- 第二种

  ```cpp
  p = {10, "abc");
  ```

## 常用函数

- `p.first()` ：第一个元素
- `p.second()` ：第二个元素



# string（字符串）

## 常用函数

- `s.substr()` ：返回指定区间的子串（可以有一个/两个参数）
- `s.c_str()` ：返回这个`string`对应的字符数组的头指针，可以用 `printf()` 来输出
- `s.size()` ：返回字母个数
- `s.length()` ：返回字母个数
- `s.empty()` ：返回字符串是否为空
- `s.clear()` ：把字符串清空

## 其他用法

```cpp
string a = "yxc";
a += "hh";
a += 'h';
```



# queue（队列）

## 定义

```cpp
queue <类型> 变量名;
```

## 常用函数

- `push()` ： 往队尾插入一个元素
- `front()` ： 返回队头元素
- `back()` ： 返回队尾元素
- `pop()` ： 把队头弹出

注意：队列没有clear函数。

清空：

```cpp
q = queue <int> ();
```



# priority_queue（优先队列，堆）

默认是大根堆

## 定义

大根堆：

```cpp
priority_queue <类型> heap;
```

小根堆：

```cpp
priority_queue <类型, vecotr <类型>, greater <类型>> heap;
```

如果插入的是数字，可以使用大根堆，在插入时加负号

## 常用函数

- `size()` ：这个堆的长度
- `empty()` ：返回这个堆是否为空
- `push()` ：往堆里插入一个元素
- `top()` ：返回堆顶元素
- `pop()` ：弹出堆顶元素

注意：堆没有 `clear()` 函数。



# stack（栈）

## 常用函数

- `push()` ：向栈顶插入一个元素
- `top()` ：返回栈顶元素
- `pop()` ：弹出栈顶元素



# deque（双端队列）

## 常用函数

- `clear()` ：清空这个双端队列
- `front()` ：返回第一个元素
- `back()` ：返回最后一个元素
- `push_back()` ：向最后插入一个元素
- `pop_back()` ：弹出最后一个元素
- `push_front()` ：向队首插入一个元素
- `pop_front()` ：弹出第一个元素
- `begin()/end()` ：迭代器
- `[]`



# set/map/multiset/multimap

基于平衡二叉树（红黑树），动态维护有序序列。

set不允许元素重复，如果有重复就会被忽略，但multiset允许

## 常用函数

- `clear()` ：清空
- `begin()` ：第0个数，支持 `++` 或 `--` ，返回前驱和后继
- `end()` ：最后一个的数的后面一个数，支持 `++` 或 `--` ，返回前驱和后继

### set/multiset

- `insert()` ：插入一个数
- `find()` ：查找一个数（如果没有则返回 `end()` 迭代器）
- `count()` ：返回某一个数的个数
- `erase()` ：
  - 输入是一个数 `x`，删除所有 `x`
  - 输入一个迭代器，删除这个迭代器
- `lower_bound(x)` ：返回大于等于 `x` 的最小的数的迭代器
- `upper_bound(x)` ：返回大于 `x` 的最小的数的迭代器

### map/multimap

- `​insert()` ：插入一个数，插入的是一个 `pair`
- `erase()` ： 
  - 输入是 `pair`
  - 输入一个迭代器，删除这个迭代器
- `find()` ：查找一个数
- `lower_bound(x)/upper_bound(x)`
- 可以像用数组一样使用 `map`



# unordered_set/map/multiset/multimap

基于哈希表，和上面类似，增删改查的时间复杂度是O(1)。

不支持 `lower_bound()` 和 `upper_bound()`（底层无序）和迭代器的 `++` `--`



# bitset 压位

## 定义

```cpp
bitset <个数> 变量名;
bitset <10000> S;
```

## 支持

`~`，`&`，`|`，`^`

``>>`，`<<`
`==`，`!=`
`[]`

## 常用函数

- `count()` ：返回有多少个1
- `any()` ：判断是否至少有一个1
- `none()` ：判断是否全为0
- `set()` ：把所有位置赋值为1
- `set(k, v)` ：将第k位变成v
- `reset()` ：把所有位变成0
- `flip()` ：把所有位取反，等价于 `~`
- `flip(k)` ：把第k位取反