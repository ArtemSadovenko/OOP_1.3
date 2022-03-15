#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class LongLong
{
private:
	long int high;
	long int low;
public:
	LongLong init(long int high_0, long int low_0);

	void read();
	void display() const;

	string ToString() const;

	void set_high(long a);
	void set_low(long  a);

	long get_high();
	long get_low();

	void convert(LongLong one, int* a);
	void unconvert(LongLong one, int* a);

	friend bool is_equal (LongLong first, LongLong second);
	friend bool is_n_equal(LongLong first, LongLong second);
	friend bool is_bigger(LongLong first, LongLong second);
};

