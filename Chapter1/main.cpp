#include <stdlib.h>
#include "Sales_item.h"

int main()








{
	Sales_item total, trans;
	if (std::cin >> total) {
		while (std::cin >> trans) {
			if (compareIsbn(total, trans)) {
				total = total + trans;
			}
			else {
				std::cout << "isbn�˺Ų�һ��" << std::endl;
				return -1;
			}
		}
		std::cout << total << std::endl;
	} 
	else {
		std::cout << "����Ϊ��" << std::endl;
		return -1;
	}
	system("pause");
	return 0;
}