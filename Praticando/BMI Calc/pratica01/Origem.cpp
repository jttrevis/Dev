#include <iostream>

using namespace std;



void main()
{
	float weight, height, bmi;

	cout << "Weight(kg), height(m): ";
	cin >> weight >> height;
	bmi = weight / (height * height);

	cout << "Your BMI is: " << bmi << endl;


	if (bmi < 18.5) {
		cout << "Underwieght";
	}
	else if (bmi > 35) {
		cout << "Overweight";
	}
	else {
		cout << "Normal Weight";
	}

	system("pause>0");
}