#ifndef xUNORDEREDVECTOR_H
#define xUNORDEREDVECTOR_H

#include <vector>
using std::vector;

template <typename T>
class S2 {
public:
	// 构造函数.
	S2();
	// 将key放入集合中.
	void insert(const T& key);
	// 将pos位置所在的元素删除, 前提是pos在0到size() - 1之间.
	void erase(int pos);
	// 若key在集合中则返回其位置, 否则返回size().
	int search(const T& key) const;
	// 返回集合中最大元素的位置, 若集合为空则返回size().
	int maximum_at() const;
	// 返回集合中最小元素的位置, 若集合为空则返回size().
	int minimum_at() const;
	// 返回pos位置元素的常量引用, 注意未提供非常量版本
	const T& operator()(int pos) const;
	// 返回集合中元素的个数.
	int size() const;
private:
	vector<T> data;
	int count;					// 实有数据个数
};

template <typename T>
S2<T>::S2()
	: count(0), data(1024)
{
	// 为其设置较大容量, 初始向量长度定为1024, 元素个数定为0
}

template <typename T>
void S2<T>::insert(const T& key)
{
	if (count == data.size())
		data.resize( 2 * data.size() );
	data[count] = key;
	count++;
}

template <typename T>
void S2<T>::erase(int pos)
{
	// 注意执行erase的前提是count > 0
	count--;
	data[pos] = data[count];
}

template <typename T>
int S2<T>::search(const T& key) const
{
	// 这里采用比较直接的策略, 后文会给出较好的程序实现(哨兵技术)
	int i = 0;
	int pos = count;
	while (i < count)
	{
		if (data[i] == key)
		{
			pos = i;
			i = count;
		}
		else
			i++;
	}
	return pos;
}

template <typename T>
int S2<T>::maximum_at() const
{
	int max_pos = 0;
	if (count > 0)
		for (int i = 1; i < count; i++)
			if (data[max_pos] < data[i])
				max_pos = i;
	return max_pos;
}

template <typename T>
int S2<T>::minimum_at() const
{
	int min_pos = 0;
	if (count > 0)
		for (int i = 1; i < count; i++)
			if (data[i] < data[min_pos])
				min_pos = i;
	return min_pos;
}

template <typename T>
const T& S2<T>::operator()(int pos) const
{
	return data[pos];
}

template <typename T>
int S2<T>::size() const
{
	return count;
}

#endif  // xUNORDEREDVECTOR_H
