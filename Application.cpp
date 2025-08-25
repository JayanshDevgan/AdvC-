#include "Application.h"

int Application::Reading_N_Numbers()
{
	int sum = 0, value = 0;
	
	while (std::cin >> value)
		sum += value;
	
	std::cout << "Sum is: " << sum << std::endl;
	
	return 0;
}

int Application::Count_Occurance()
{
	int current_value = 0, val = 0;
	if (std::cin >> current_value)
	{
		int count = 1;
		while (std::cin >> val)
		{
			if (val == current_value)
				++count;
			else {
				std::cout << current_value << " occurs "
					<< count << " times" << std::endl;
				current_value = val;
				count = 1;
			}
		}
	}
	return 0;
}

void Application::Sales_item_exec()
{
	Sales_item book;
	std::cin >> book;
	std::cout << book << std::endl;
}

void Application::Run()
{
	//Reading_N_Numbers();
	//Count_Occurance();
	Sales_item_exec();
}