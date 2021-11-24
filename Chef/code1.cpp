// #include<bits/stdc++.h>
// using namespace std;

// class prod
// {
// private:
// 	int code;
// 	float p;
// 	int qty;

// public:
// 	void assign()
// 	{
// 		cin >> code >> p >> qty;

// 	}
// 	void show();

// };

// void prod::show()
// {
// 	// prod a;
// 	// code += 23;
// 	// p -= 5.0;
// 	// qty *= 3;
// 	cout << code << endl;
// 	cout << p << endl;
// 	cout << qty << endl;

// }

// return 0;
// int main()
// {
// 	prod a, b;
// 	a.assign();
// 	a.show();
// 	b.assign();
// 	b.show();

// }

#include <bits/stdc++.h>
using namespace std;

class emp
{
	int sal;
	float net;

public:
	void calc(int, float)
	{
		cout << "salary: " << sal << endl;
		cout << "Net Worth: " << net << endl;
	}
};

void emp::calc(int a, float b)
{
	cin >> a;
	cin >> b;
}

int main()
{
	emp e;
	e.calc();
}
