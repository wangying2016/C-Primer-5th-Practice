#include "Sales_data.h"
#include <iostream>

int main()
{
	Sales_data data1, data2;
	// ��ȡ����ISBNһ��������
	double price = 0;
	std::cin >> data1.bookNo >> data1.unites_sold >> price;
	data1.revenue = data1.unites_sold * price;
	std::cin >> data2.bookNo >> data2.unites_sold >> price;
	data2.revenue = data2.unites_sold * price;
	if (data1.bookNo != data2.bookNo) {
		std::cerr << "�������ݵ�ISBN��һ��" << std::endl;
		return -1;
	}
	else {
		std::cout << data1.bookNo << " " << data1.unites_sold + data2.unites_sold
			<< " " << data1.revenue + data2.revenue << std::endl;
	}
	return 0;
}