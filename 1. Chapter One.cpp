// 例1
// 请求某人输入其姓名，然后像这个人发出问候

#include<iostream>
#include<string>
//using namespace std;

int main()
{
	//请某人输入姓名
	std::cout << "Please enter your first name: ";

	//读姓名
	std::string name;    //定义变量name
	std::cin >> name;    //把姓名读入name

	//输出对这个人的问候
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}



//例2
#include<iostream>
#include<string>
//using namespace std;

int main()
{
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;

	//
	const std::string greeting = "Hello, " + name + "!";

	//
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";

	//
	const std::string first(second.size(), '*');

	//
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
	return 0;
}



// 1 - 3

#include<iostream>
#include<string>
//using namespace std;

int main()
{
	{
		const std::string s = "a string";
		std::cout << s << std::endl; }
	{
		const std::string s = "another string";
		std::cout << s << std::endl; }
	return 0;
}



// 1 - 4

#include<iostream>
#include<string>
//using namespace std;

int main()
{
	{
		const std::string s = "a string";
		std::cout << s << std::endl;
		{
			const std::string s = "another string";
			std::cout << s << std::endl; }; }
	return 0;
}



// 1 - 5

#include<iostream>
#include<string>
//using namespace std;

int main()
{
	{
		std::string s = "a string";
		{
			std::string x = s + ", really";
			std::cout << s << std::endl;
			std::cout << x << std::endl;
		}
	}
	return 0;
}



// 1 - 6

#include<iostream>
#include<string>
//using namespace std;

int main()
{
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
		<< std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name
		<< "; nice to meet you too! " << std::endl;
	return 0;
}
