#include <iostream>
using namespace std;

void inc(int &x)
{
	x++;
}

void print(int x)
{
	cout << x << ", ";
}

template<typename T, typename OP>
void ForEach(T arr[], size_t size, OP &op)
{
	for (size_t i = 0; i < size; i++)
	{
		op(arr[i]);
	}
}

class SumClass {
private:
	double sum = 0;
public:
	void operator()(double& val) {
		sum += val;
	}
	double GetSum() { return sum; }
};

int main()
{
	int arr1[] = { 1, 2, 3, 4 };
	cout << "Print 1: ";
	ForEach(arr1, 4, print);
	cout << endl;
	
	ForEach(arr1, 4, inc);
	cout << "Print 2: ";
	ForEach(arr1, 4, print);
	cout << endl;

	double arr2[]{ 3.2, 5.9, 3.7, 9.6 };
	SumClass sum;
	ForEach(arr2, 4, sum);
	cout << "Sum: " << sum.GetSum() << endl;

	return 0;
}
