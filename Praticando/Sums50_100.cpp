#include <iostream>



int main()
{
	int sum = 0, val = 50;

	while (val <= 100)
	{
		sum += val;
		++val;
	}


	std::cout << "The sum is: " << sum << "\n\n";
	std::cout << "The sum is: " << sum << "\n\n";

	return 0;
}

