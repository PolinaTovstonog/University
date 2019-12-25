#include <iostream>
#include "UserInterface.h"

using namespace std;

int main() {
	const auto user = new userInterface();
	user->interact();

	cout << endl;
	system("pause");
}