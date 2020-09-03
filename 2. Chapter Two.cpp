// 例

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	//
	cout << "Please enter your first name : ";
	
	//
	string name;
	cin >> name;

	//
	const string greeting = "Hello, " + name + "!";

	//围住问候语的空白个数
	const int pad = 1;

	//
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	//
	cout << endl;

	//
	//不变式：到目前为止，我们已经输出了r行
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;

		//不变式：到目前为止，在当前行我们已经输入了c个字符
		while (c != cols) {
			
			//应该输出问候语了吗？
			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {

				//我们是位于边界上吗？
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}

		cout << endl;
	}

	return 0;
}



// 2 - 1

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name : ";

	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";
	//pad == 0时没有间隔
	const int pad = 0;

	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {

			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	return 0;
}



// 2 - 2.1
//让空行变为上下各两行

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name : ";

	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";
	const int pad = 1;
	
	//
	const int rows = pad * 4 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {
			
			//
			if (r == pad + 2 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	return 0;
}



// 2 - 2.2
//让空列变为两列
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name : ";

	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";
	const int pad = 1;

	const int rows = pad * 2 + 3;
	//
	const string::size_type cols = greeting.size() + pad * 4 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {
			//
			if (r == pad + 1 && c == pad + 2) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	return 0;
}



// 2 - 3

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name : ";

	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";
	//
	int pad;
	cout << "Please enter the custom pad (recommend 1) : ";
	cin >> pad;
	

	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {

			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	return 0;
}



// 2 - 4

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name : ";

	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";
	const int pad = 1;

	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	
	//
	const string spaces(greeting.size() + pad * 2, ' ');

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {

			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
					cout << "*";
					//
					++c;
				}
				//
				else {
					if (r == pad + 1) {
						cout << ' ';
						++c;
					}
					else {
						cout << spaces;
						c += spaces.size();
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}



// 2 - 5.1
//输出一个四周*数相同的正方形

#include<iostream>
using namespace std;

int main()
{
	int length;
	cout << "Please enter the length of square : ";
	cin >> length;

	cout << endl;

	for (int i = 0; i != length; ++i) {
		
		int j = 0;
		while (j != length) {

			if (i == 0 || i == length - 1 || j == 0 || j == length - 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
			++j;
		}
		cout << endl;
	}

	return 0;
}



// 2 - 5.2
//这个正方形更像是正方形了

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int length;
	cout << "Please enter the length of square : ";
	cin >> length;

	string starpace = "* ";
	cout << endl;

	for (int i = 0; i != length; ++i) {
		
		int j = 0;
		while (j != length * 2) {

			if (i == 0 || i == length - 1 || j == 0 || j == length * 2 - 2) {
				cout << starpace;
				j += 2;
			}
			else {
				cout << ' ';
				++j;
			}
		}
		cout << endl;
	}
	return 0;
}



// 2 - 5.3
//生成一个长方形

#include<iostream>
using namespace std;

int main()
{
	int length, width;
	cout << "Please enter the length of rectangle : ";
	cin >> length;
	cout << "Please enter the width of rectangle : ";
	cin >> width;

	cout << endl;

	for (int i = 0; i != width; ++i) {

		int j = 0;
		while (j != length) {

			if (i == 0 || i == width - 1 || j == 0 || j == length - 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
			++j;
		}
		cout << endl;
	}
	return 0;
}



// 2 - 5.4
//现在更像一个长方形了

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int length, width;
	cout << "Please enter the length of rectangle : ";
	cin >> length;
	cout << "Please enter the width of rectangle : ";
	cin >> width;

	string starpace = "* ";

	cout << endl;

	for (int i = 0; i != width; ++i) {

		int j = 0;
		while (j != length * 2) {

			if (i == 0 || i == width - 1 || j == 0 || j == length * 2 - 2) {
				cout << starpace;
				j += 2;
			}
			else {
				cout << ' ';
				++j;
			}
			
		}
		cout << endl;
	}
	return 0;
}



// 2 - 5.5
// 直角三角形

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 1;
	int length;
	cout << "Please enter the length of right triangle : ";
	cin >> length;

	cout << endl;

	for (int i = 0; i != length; ++i) {

		int j = 0;
		while (j != a) {
			
			if (i == 0 || i == length - 1 || j == 0 || j == a - 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
			++j;
		}
		cout<<endl;
		++a;
	}
	return 0;
}



// 2 - 5.6
// 等腰三角形

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int length;
	cout << "Please enter the base length of isosceles triangle : ";
	cin >> length;

	cout << endl;
	int i, j;
	if (length % 2 == 0) {
		
		for (i = 0; i != length / 2; ++i) {

			for (j = 0; j != length; ++j) {

				if (i == length / 2 - 1 || j == length / 2 - i - 1 || j == length / 2 + i) {
					cout << '*';
				}
				else {
					cout << ' ';
				}
			}
			cout << endl;
		}
	}
	else {

		for (i = 0; i != length / 2 + 1; ++i) {

			for (j = 0; j != length; ++j) {

				if (i == 0 && j == length / 2) {
					cout << '*';
				}
				else {
					if (i == length / 2 || j == length / 2 - i || j == length / 2 + i) {
						cout << '*';
					}
					else {
						cout << ' ';
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}



// 2 - 7
// 依次输出10到-5的所有整数

#include<iostream>
//#include<string>
using namespace std;

int main()
{
	int i = 11;
	while (i != -5) {
		cout << --i << endl;
	}
	return 0;
}



// 2 - 8
// 计算1到9的乘积

#include<iostream>
//#include<string>
using namespace std;

int main()
{
	int i = 1;
	int sum = 1;
	while (i != 10) {
		sum *= i;
		i++;
		cout << sum << endl;
	}
	return 0;
}



// 2 - 9
// 比较用户输入的两个值

#include<iostream>
//#include<string>
using namespace std;

int main()
{
	int a, b;
	char choice = 'Y';
	
	//加了让用户选择是否继续的循环
	while (choice == 'Y' || choice == 'y') {

		cout << "Please enter the number you want to compare : ";
		cin >> a >> b;

		if (a == b)
			cout << "They are same." << endl;
		else {
			if (a < b)
				cout << a << " is smaller than " << b << "." << endl;
			else
				cout << a << " is bigger than " << b << "." << endl;
		}

		cout << endl;

		cout << "Do you want to repeat ? (Y/N) ";
		cin >> choice;
		cout << endl;
	}



	return 0;
}



