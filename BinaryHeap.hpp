#include <iostream>
#include <math.h>

namespace ft{

	class BinaryHeap {
		public:
			BinaryHeap(): arr(0), size(0), cap(0) {};
			~BinaryHeap() { if (arr) {delete [] arr;}};
			
			BinaryHeap(size_t s) {
				arr = new int[s];
				size = 0;
				cap = s;
			};

			void swap(int &a, int &b) {
				int c = a;
				a = b;
				b = c;
			};

			void pop() {
				if (size <= 1)
				{
					size = 0;
					return;
				}
				int index = 1;
				arr[index - 1] = arr[--size];
				while ((index < size) && (arr[index >> 1] > arr[index] || arr[index >> 1] > arr[index + 1])) 
				{
					if (arr[index] < arr[index + 1])
					{
						swap(arr[index], arr[index >> 1]);
						index = index << 1;
					}
					else
					{
						swap(arr[index + 1], arr[index >> 1]);
						index = index << 1;
					}
				}
			}

			void resize(size_t cap)
			{
				if (!cap)
					cap = 1;
				
				int *newArr = new int[cap];
				int index = 0;

				while (index < size)
				{
					newArr[index] = arr[index];
					index++;
				}

				delete [] arr;
				arr = newArr;
			}

			void push(int a) {
				if (size == cap)
					resize(cap * 2);

				arr[size++] = a;
				int tmp = size;
				
				while (tmp > 1 && arr[(tmp >> 1) - 1] > arr[tmp - 1])
				{
					swap(arr[(tmp >> 1) - 1], arr[tmp - 1]);
					tmp = tmp >> 1;
				}
			};
			
			void print() {
				int k = 0;

				std::cout << "INDEXES\n";
				while (k < size)
					std::cout << k++ << " ";
				std::cout << "\n";

				k = 0;
				std::cout << "VALUES\n";
				while (k < size)
					std::cout << arr[k++] << " ";
				std::cout << "\n";
			}

		private:
		int		*arr;
		size_t	size;
		size_t	cap;
	};
};
