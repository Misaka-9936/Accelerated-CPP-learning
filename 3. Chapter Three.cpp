//Example One
//累次相加求和计算家庭作业的平均值

#include<iostream>
#include<iomanip>
#include<ios>
#include<string>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;
//using std::precision;              (E0135	namespace "std" 没有成员 "precision")，Accelerated C++上有这行代码
using std::setprecision;
using std::string;
using std::streamsize;

int main()
{

	//请求输入并读入学生的姓名
	cout << "Please enter your name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//请求输入并读入期中和期末成绩
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//请求输入家庭作业成绩
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	//到目前为止，读到的家庭作业成绩的个数及总和
	int count = 0;
	double sum = 0;

	//把家庭作业成绩读到变量x中
	double x;
	
	//不变式
	//到目前为止，我们已经读到了count个家庭作业成绩
	//而且sum等于头count个成绩的总和
	while (cin >> x) {
		++count;
		sum += x;
	}
	
	//输出结果
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * sum / count
		<< setprecision(prec) << endl;

	return 0;
}



//Example Two
//用向量记录学生的家庭作业的成绩，并计算中位数，输出总成绩的程序

#include<algorithm>
#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
//using std::precision;              (E0135	namespace "std" 没有成员 "precision")，Accelerated C++上有这行代码
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
	
	//请求输入并读入学生的姓名
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//请求输入并读入期中和期末成绩
	cout << "Please enter your midterm and final exam grades : ";
	double midterm, final;
	cin >> midterm >> final;

	//请求输入家庭作业成绩
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	vector<double> homework;
	double x;

	//不变式: home包含了所有的家庭作业成绩
	while (cin >> x)
		homework.push_back(x);

	//检查homework是否为空
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your homework grades. "
			<< "Please try again. " << endl;
		return 1;
	}

	//对成绩进行排序
	sort(homework.begin(), homework.end());

	//计算家庭作业成绩的中值
	vec_sz mid = size / 2;
	double median;
	median = (size % 2 == 0) ? (homework[mid] + homework[mid - 1]) / 2
		: homework[mid];

	//计算并输出总成绩
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
}



// 3 - 2
//把一个整数集合分为个数相等的四部分，而且第一部分含有的整数值比其他各部分的都大，第二部分的值比第一部分的小比其他两部分的大，
//剩下的两部分则以此类推。按照上面的要求，编写一个程序来计算并且打印这四部分。

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main()
{
	
	vector<int> integers;
	int x;

	cout << "Please enter the Integers (*4), followed by end-of-file: ";
	while (cin >> x) {
		integers.push_back(x);
	}

	typedef vector<int>::size_type vec_sz;
	vec_sz size = integers.size();
 
	if (size % 4 != 0) {
		cout << endl << "The numbers you enter must be a multiple of four" << endl;
		return 1;
	}

	if (size == 0) {
		cout << endl << "You must enter at least four integers !" << endl;
		return 2;
	}

	//排逆序：sort(integers.rbegin(), integers.rend());
	sort(integers.begin(), integers.end());

	cout << "1st quartile : ";
	for (vec_sz i = size - 1; i != size * 3 / 4 - 1; --i) {
		cout << integers[i] << " ";
	}
	cout << endl;

	cout << "2ed quartile : ";
	for (vec_sz j = size * 3 / 4 - 1; j != size / 2 - 1; --j) {
		cout << integers[j] << " ";
	}
	cout << endl;

	cout << "3rd quartile : ";
	for (vec_sz k = size / 2 - 1; k != size / 4 - 1; --k) {
		cout << integers[k] << " ";
	}
	cout << endl;

	cout << "4th quartile : ";
	for (vec_sz l = size / 4 - 1; l != -1; --l) {
		cout << integers[l] << " ";
	}
	cout << endl;

	return 0;
}



// 3 - 3
//编写一个程序来计算在它的输入中的每个不同的单次所出现的次数。

#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{

	string str;
	vector<string> word;     //记录出现过的单词
	vector<int> counts;      //记录对应单词的出现次数
	cout << "You can enter a sentence(s) here : ";
	
	//定义vec_sz为vector<string>::size_type无符号整数类型的替代名
	typedef vector<string>::size_type vec_sz;

	while (cin >> str) {
		
		//相当于一个flag标志，作为下面新单词的判断条件
		bool found = false;

		//实际上i定义为int类型也没错
		for (vec_sz i = 0; i != word.size(); ++i) {

			if (str == word[i]) {
				++counts[i];
				found = true;
			}
		}

		//只有当遇到新单词的时候才压入vector中
		if (!found) {
			word.push_back(str);
			counts.push_back(1);
		}
	}
	
	cout << endl;
	for (vec_sz i = 0; i != word.size(); ++i) {
		cout << word[i] << " appears " << counts[i] << " times." << endl;
	}
	return 0;
}



// 3 - 4
//编写一个程序来报告它的输入中最长的以及最短的字符串的长度。

#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int max_size = 0, min_size = 0;
	string str;
	cout << "You can enter strings here : ";
	
	while (cin >> str) {

		//解决了初始化为0时会造成的问题
		if (max_size == 0 || max_size < str.size())
			max_size = str.size();
		if (min_size == 0 || min_size > str.size())
			min_size = str.size();
	}
	
	cout << endl;
	cout << "The longest size is " << max_size << endl;
	cout << "The shortest size is " << min_size << endl;

	return 0;
}



// 3 - 5
//编写一个程序来跟踪n个学生的成绩。要求程序能够保持两个向量的同步：
//第一个应保存学生的姓名；第二个保存总成绩，而这个总成绩能根据读到的输入来计算。
//读者应假定家庭作业成绩的个数是固定的。

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>     //该库声明了precision和setprecision
#include<ios>         //该库声明了streamsize类型

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
//using std::precision;      (E0135	namespace "std" 没有成员 "precision")，Accelerated C++上有这行代码
using std::setprecision;
using std::streamsize;

int main()
{
	int n = 0;     //统计人数
	int i = 1;     //i标识正在输入的学生编号
	string name;
	double exam, homework;
	vector<string> name_list;
	vector<double> grade;
	bool proceed = true;     //判断用户是否循环的标识符

	while (proceed) {

		proceed = false;      //默认置不循环

		cout << "please enter No." << i << " student's name : ";
		cin >> name;
		cout << "please enter No." << i << " student's exam and homework grade : ";
		cin >> exam >> homework;

		name_list.push_back(name);
		grade.push_back(exam + homework);

		n = i;     //n记录学生人数
		++i;

		//询问用户是否循环（继续输入）
		cout << "Do you want to go on ? (Y/N):";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			proceed = true;
			cout << endl;
		}
	}
	
	cout << endl;
	cout << "Thanks for you using, the students' grade will show below : " << endl;
	
	//保存当前输出流的精度
	streamsize prec = cout.precision();
	for (int j = 0; j != n; ++j) {
		cout << "No." << j + 1 << ": " << name_list[j]
			<< "'s grade is " << setprecision(3) << grade[j] << setprecision(prec)
			<< "." << endl;
	}

	return 0;
}
