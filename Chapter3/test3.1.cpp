#if 0
#include <iostream>
#include <string>
// ʹ�� using ����ʹ�����µ������ڳ����пɼ�
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Sales_data {
	friend istream& operator >> (istream&, Sales_data&);
	friend ostream& operator << (ostream&, const Sales_data&);
	friend bool operator < (const Sales_data&, const Sales_data&);
	friend bool operator == (const Sales_data&, const Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string &book) : bookNo(book) {}
	Sales_data(istream &is) { is >> *this; }
public:
	Sales_data& operator += (const Sales_data&);
	string isbn() const { return bookNo; }
private:
	string bookNo;
	unsigned unites_sold = 0;	// ������
	double sellingprice = 0.0;	// ԭʼ�۸�
	double saleprice = 0.0;		// ʵ�ۼ۸�
	double discount = 0.0;		// �ۿ�
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.unites_sold == rhs.unites_sold &&
		lhs.sellingprice == rhs.sellingprice &&
		lhs.saleprice == rhs.saleprice &&
		lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

Sales_data& Sales_data::operator += (const Sales_data &rhs)
{
	unites_sold += rhs.unites_sold;
	saleprice = (rhs.saleprice * rhs.unites_sold + saleprice * unites_sold)
		/ (rhs.unites_sold + unites_sold);
	if (sellingprice != 0) {
		discount = saleprice / sellingprice;
	}
	return *this;
}

Sales_data operator + (const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data ret(lhs);
	ret += rhs;
	return ret;
}

istream& operator >> (istream &in, Sales_data &s)
{
	in >> s.bookNo >> s.unites_sold >> s.sellingprice >> s.saleprice;
	if (in && s.sellingprice != 0) {
		s.discount = s.saleprice / s.sellingprice;
	} else {
		s = Sales_data();
	}
	return in;
}

ostream& operator << (ostream &out, const Sales_data &s)
{
	out << s.isbn() << " " << s.unites_sold << " "
		<< s.sellingprice << " " << s.saleprice << " " << s.discount;
	return out;
}

int main()
{
	Sales_data book;
	cout << "��������������" << endl;
	while (cin >> book) {
		cout << " ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ "
			<< book << endl;
	}

	Sales_data trans1, trans2;
	cout << "����������ISBN��ͬ�����ۼ�¼��" << endl;
	cin >> trans1 >> trans2;
	if (compareIsbn(trans1, trans2))
		cout << "������ϢΪ��ISBN���۳�������ʵ�ۼ۸��ۿ�Ϊ"
		<< trans1 + trans2 << endl;
	else
		cout << "�������ۼ�¼��ISBN��ͬ" << endl;

	Sales_data total, trans;
	cout << "�����뼸��ISBN��ͬ�����ۼ�¼��" << endl;
	if (cin >> total) {
		while (cin >> trans) {
			if (compareIsbn(total, trans)) {
				total = total + trans;
			} else {
				cout << "��ǰ�鼮ISBN��ͬ" << endl;
				break;
			}
			cout << "��Ч������Ϣ��ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ"
				<< total << endl;
		}
	} else {
		cout << "û������" << endl;
		return -1;
	}

	int num = 1;
	cout << "������������������" << endl;
	if (cin >> trans1) {
		while (cin >> trans2)
			if (compareIsbn(trans1, trans2))
				num++;
			else {
				cout << trans1.isbn() << "����"
					<< num << "�����ۼ�¼" << endl;
				trans1 = trans2;
				num = 1;
			}
			cout << trans1.isbn() << "����"
				<< num << "�����ۼ�¼" << endl;
	} else {
		cout << "û������" << endl;
		return -1;
	}

	return 0;
}
#endif 