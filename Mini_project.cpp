#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define PI 3.14159265


bool chooser(void)
{
	double val_1, val_2;
	std::string answer;
	bool flag = false;
	std::cout << "Do u want to play? [Yes/No]\nAnswer: "; std::cin >> answer;
	if (answer != "Yes" && answer != "No")
		for (;;)
		{
			std::cout << "I don't get you. Repeat please.\n";
			std::cout << "Do u want to play? [Yes/No]\nAnswer: "; std::cin >> answer;
			if (answer == "Yes" || answer == "No")
			{
				if (answer == "Yes") return true;
				break;
			}
		}
	if (answer == "Yes") return true;
	return flag;
}


std::vector <double> values(std::string op)
{
	std::vector <double> vec;
	double x, y;
	if (op == "sqrt" || op == "degree" || op == "sin" || op == "cos" || op == "tg" || op == "cos_a" || op == "sin_a" || op == "tg_a")
	{
		double val;
		std::cout << "Choose letter: "; std::cin >> val;
		vec.push_back(val);
		return vec;
	}
	else
	{
		std::cout << "Choose 1st value: "; std::cin >> x;
		std::cout << "Choose 2nd value: "; std::cin >> y;
		vec.push_back(x); vec.push_back(y);
		return vec;
	}
}


std::string operation(void)
{
	std::vector <std::string> arr(10);
	arr.push_back("+"); arr.push_back("-"); arr.push_back("*");
	arr.push_back("/"); arr.push_back("%"); arr.push_back("sqrt");
	arr.push_back("degree"); arr.push_back("sin"); arr.push_back("cos");
	arr.push_back("tg"); arr.push_back("cos_a"); arr.push_back("sin_a"); arr.push_back("tg_a");
	std::string ans;
	int count = 0;
	while (true)
	{
		std::cout << "Choose math operation:\n['+', '-', '*', '/', '%', 'sqrt', 'degree', 'sin', 'cos', 'tg', 'sin_a', 'cos_a', 'tg_a']\n";
		std::cout << "Your choice: ";  std::cin >> ans;
		for (std::string x : arr)
		{
			if (ans != x) count += 1;
		}
		if (count != arr.size())
		{
			return ans;
		}
		else
		{
			std::cout << "Something wrong. Repeat.\n";
		}
	}
}


double result_of_operation(std::vector<double> arr, std::string op)
{
	double value;
	if (op == "sqrt") return sqrt(arr[0]);
	if (op == "degree")
	{
		int degr;
		std::cout << "Choose which degree one: "; std::cin >> degr;
		return pow(arr[0], degr);
	}
	if (op == "sin") return sin(arr[0]);
	if (op == "cos") return cos(arr[0]);
	if (op == "tg") return tan(arr[0]);
	if (op == "+") return arr[0] + arr[1];
	if (op == "-") return arr[0] - arr[1];
	if (op == "*") return arr[0] * arr[1];
	if (op == "sin_a") return sin(arr[0] * PI / 180);
	if (op == "cos_a") return cos(arr[0] * PI / 180);
	if (op == "tg_a") return tan(arr[0] * PI / 180);
	if (arr[1] != 0)
	{
		if (op == "/") return int(arr[0]) / int(arr[1]);
		if (op == "%") return int(arr[0]) % int(arr[1]);
	}
	else if (arr[1] == 0 && (op == "/" || op == "%"))
	{
		return double(false);
	}

}


int main()
{
	std::cout << "Hello! This is universal calculator v1.0" << "\n\n";
	for (; true;)
	{
		bool res = chooser();
		if (res)
		{
			std::string op = operation();
			std::vector <double> vec_val;
			vec_val = values(op);
			double result = result_of_operation(vec_val, op);
			if (result == 0.0) std::cout << "You can't divide by zero\n\n";
			else { std::cout << "The result is " << result << "\n\n"; }
		}
		else { break; }
	}
	return 0;
}