#include <iostream>


int m1(int& f) {

	//char* mm = new char[strlen(b)] ;
	//mm = b;
	unsigned int k = f;
	//mm = b;
	return k;
}

void main() {
	char a[] = "g11";
	if (isalpha(a[1])) {
		std::cout << "yes";
	}
	char g = 'f';
	int j = -10;
	std::cout << m1(j);
	//delete[] a;
}