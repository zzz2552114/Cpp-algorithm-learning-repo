#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "小熊猫C++ 3.4配置成功！" << endl;
	cout << "编译器版本：" << __VERSION__ << endl;
	
	vector<int> v = {1, 2, 3, 4, 5};
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
