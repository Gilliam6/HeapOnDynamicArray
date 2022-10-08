#include "BinaryHeap.hpp"

int main() {
	ft::BinaryHeap t1(3);

	t1.push(5);
	t1.push(5);
	t1.push(10);
	t1.push(4);
	t1.push(2);
	t1.push(3);

	t1.print();
	t1.pop();
//	t1.pop();
//	t1.pop();
//	t1.pop();
//	t1.pop();
//	t1.pop();
//	t1.pop();
//	t1.pop();

	t1.print();
	return (0);
}
