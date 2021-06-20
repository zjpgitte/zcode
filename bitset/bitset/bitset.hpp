#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace zjp
{

	class bitset
	{
	public:
		bitset(int bitCount = 8)
			:_bitCount(bitCount)
		{
			_v.resize(_bitCount / 8 + 1, 0);
		}

		void set(int which) // which位置1
		{
			int size = which / 8;
			int num = which % 8;
			if (which > _bitCount)
			{
				// 扩容
				_v.resize(size + 1);
				_bitCount = which;
			}

			_v[size] |= (1 << num);
		}
		void reset(int which) // which位置0
		{
			int size = which / 8;
			int num = which % 8;
			if (which > _bitCount)
			{
				_v.resize(size);
				_bitCount = which;
			}

			_v[size] &= (~(1 << num));
		}
		bool test(int which) // which位是否为1
		{
			if (which > _bitCount)
			{
				return false;
			}

			int size = which / 8;
			int num = which % 8;

			return _v[size] & (1 << num);
		}
		size_t size() // 总的比特位
		{
			return _bitCount;
		}
		size_t count() // 比特位为1的位总数
		{
			int bitCnttable[256] = {
				0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
				3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
				3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
				4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
				3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
				6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
				4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
				6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
				3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
				4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
				6, 7, 6, 7, 7, 8 };
			
			size_t count = 0;
			//遍历vector
			for (size_t i = 0; i < _v.size(); i++)
			{
				if (i == _v.size() - 1)
				{
					int num = 0;
					while (num < 8)
					{
						if (_v[i] & (1 << num))
						{
							count++;
						}
						++num;
					}
					break;
				}

				count += bitCnttable[_v[i]];
			}
			return count;
		}

	private:
		vector<char> _v;
		int _bitCount;
	};

}