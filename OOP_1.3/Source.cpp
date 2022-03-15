#include <iostream>
#include <string>
#include <sstream>
#include "LongLong.h"

using namespace std;

int main() {
	LongLong a;
	LongLong b;
	a = a.init(100010, 101);
	b = b.init(100011, 101);
	
	a.read();
	b.read();

	a.display();
	b.display();

	if (is_equal(a, b)) {
		cout << "a is equal to b" << endl;
	}
	else if (is_n_equal(a, b)) {
		if (is_bigger(a, b)) {
			cout << "a is bigger then b" << endl;
		}
		else {
			cout << "b is bigger then a" << endl;
		}
	}

}