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
