#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;
	//If number of stone left is odd, Alice win
	//If number of stone left is even, Alice win
	cout << (n % 2 == 1 ? "Alice" : "Bob") << endl;
	return 0;
    
}