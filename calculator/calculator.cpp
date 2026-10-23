#include <iostream>
#include <string>

int main()
{
	while (true)
	{
		double a, b;
		int choice;
		std::cout << "Enter two numbers: ";
		if(!(std::cin >> a >> b))
		{ 
			std::cout << "wrong!" << std::endl;
			break;
		}
		std::cout << "Choise minus - 1 , plus - 2, multiplication - 3, division - 4: ";
		if (!(std::cin >> choice)) 
		{
			std::cout << "wrong" << std::endl;
			break;
		}		
		if (choice == 1)
		{
			std::cout << a << "-" << b << "=" << a - b << std::endl;
		}
		else if (choice == 2)
		{
			std::cout << a << "+" << b << "=" << a + b << std::endl;
		}
		else if (choice == 3)
		{
			std::cout << a << "*" << b << "=" << a * b << std::endl;
		}
		else if (choice == 4)
		{	
			if (b == 0) {
				std::cout << "wrong!" << std::endl;
					break;
			}
			else 
			{
				std::cout << a << "/" << b << "=" << a / b << std::endl;
			}
		}
		else
		{
			std::cout << "wrong" << std::endl;
		}
	}
	return 0;
}
