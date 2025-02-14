
#include <iostream>


class Tower
{
	int arr[100];
	int size;

public:
	Tower() :arr{ 0 }, size{ -1 } {}

	int Remove()
	{
		return arr[size--];
	}
	void Add(int num)
	{
		arr[++size]=num;
	}

	void Print()
	{
		for (int i = 0;i <= size;i++)
			std::cout << arr[size-i] << "\n";
		std::cout << std::endl;
	}
}A, B, C;


void DoTower(int n, Tower& source, Tower& intermediate, Tower& destination)
{
	if (!n) return;

	DoTower(n - 1, source, destination, intermediate);

	destination.Add(source.Remove());

	DoTower(n - 1, intermediate, source, destination);

}



int main()
{
	const int N = 7;

	for (int i = N; i > 0; i--)
		A.Add(i);

	std::cout << "Source Tower :" << std::endl;
	A.Print();

	DoTower(N, A, B, C);

	std::cout << "Destination Tower :" << std::endl;
	C.Print();

	std::cin.get();
	return 0;
}