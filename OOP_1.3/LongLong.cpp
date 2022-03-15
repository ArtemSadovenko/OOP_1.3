#include "LongLong.h"


void LongLong::set_high(long  a){
	high = a;
}

void LongLong::set_low(long a){
	low = a;
}

long LongLong::get_high() {
	return high;
}

long LongLong::get_low() {
	return low;
}

LongLong LongLong::init(long int high_0, long int low_0) {
	LongLong a;
	a.high = high_0;
	a.low = low_0;
	int mas[21];
	int* q = mas;
	a.convert(a, q);
	for (int i = 0; i < 21; i++) {
		if ((q[i] != 1 && q[i] != 0) || low < 0) {
			cout << "Wrong input" << endl;
			return a;		
		}
	}
	return a;
}

void LongLong::read() {
	long h;
	long l;
	cout << "Enter high: "; cin >> h;
	cout << "Enter low: "; cin >> l;
	high = h;
	low = l;

	LongLong a;
	a.set_high(h);
	a.set_low(l);

	int mas[21];
	int* q = mas;
	a.convert(a, q);
	for (int i = 0; i < 21; i++) {
		if ((q[i] != 1 && q[i] != 0) || low < 0) {
			cout << "Wrong input" << endl;
			break;
		}
	}
	
}

void LongLong::display() const {
	cout << ToString() ;
}

void LongLong::convert(LongLong one, int* a) {
	LongLong two = one;

	if (two.high < 0) {
		two.high *= -1;
		a[0] = 1;
	}
	else {
		a[0] = 0;
	}

	for (int i = 20; i >= 11; i--) {
		if (two.low == 0) {
			for (int j = i; j >= 11; j--) {
				a[j] = 0;
			}
			break;
		}
		else if (two.low % 10 == 1) {
			a[i] = 1;
		}
		else if (two.low % 10 == 0) {
			a[i] = 0;
		}
		two.low /= 10;
	}

	for (int i = 10; i > 0; i--) {
		if (two.high == 0) {
			for (int j = i; j > 0; j--) {
				a[j] = 0;
			}
			break;
		}
		else if (two.high % 10 == 1) {
			a[i] = 1;
		}
		else if (two.high % 10 == 0) {
			a[i] = 0;
		}
		two.high /= 10;
	}

}

void LongLong::unconvert(LongLong one, int* a) {
	long high_here = 0;
	long low_here = 0;

	for (int i = 10; i > 0; i--) {
		if (a[i] == 1) {
			high_here += pow(10, 10 - i);
		}
	}

	for (int i = 20; i >= 11; i--) {
		if (a[i] == 1) {
			low_here += pow(10, 20 - i);
		}
	}

	if (a[0] == 1) {
		high_here *= -1;
	}

	/*cout << high_here << endl;
	cout << low_here << endl;
	
	one.set_high(high_here);
	one.set_low(low_here);*/

	high = high_here;
	low = low_here;
}

bool is_equal(LongLong first, LongLong second) {
	
	return first.high == second.high && first.low == second.low;
}

bool is_n_equal(LongLong first, LongLong second){
	return !is_equal(first, second);
}

bool is_bigger(LongLong first, LongLong second) {
	return first.high > second.high || (first.high == second.high && first.low > second.low);
}

string LongLong::ToString() const {
	stringstream sout; 
	sout << "high = " << high << endl <<
	 "low = " << low << endl;
	return sout.str();
}