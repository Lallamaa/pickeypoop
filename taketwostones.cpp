#include <iostream>
using namespace std;

int main(){
	int stones;
	cin >> stones;
	cout << (stones % 2 == 1 ? "Alice" : "Bob") << endl;
	return 0;
}