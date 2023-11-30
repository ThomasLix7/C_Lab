#include <iostream>

using namespace std;

int main() {
	int quant;
	int choice;

	int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;

	int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;

	int Total_rooms = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0;

	cout << "\n\t Quantity of items we have ";
	cout << "\n Rooms avaliable: ";
	cin >> Qrooms;
	cout << "\n Pasta avaliable: ";
	cin >> Qpasta;
	cout << "\n Burger avaliable: ";
	cin >> Qburger;
	cout << "\n Noodles avaliable: ";
	cin >> Qnoodles;
	cout << "\n Shake avaliable: ";
	cin >> Qshake;
	cout << "\n Chicken avaliable: ";
	cin >> Qchicken;

m:
	cout << "\n\t\t\t Please select from the menu: ";
	cout << "\n\n1) Rooms";
	cout << "\n2) Pasta";
	cout << "\n3) Burger";
	cout << "\n4) Noodles";
	cout << "\n5) Shake";
	cout << "\n6) Chicken";
	cout << "\n7) Information Regarding sales and collection";
	cout << "\n8) Exit";

	cout << "\n\n Please Enter your choice: ";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "\n\n The number of rooms you want: ";
		cin >> quant;
		if (Qrooms - Srooms >= quant) {
			Srooms = Srooms + quant;
			Total_rooms = Total_rooms + quant * 600;
			cout << "\n\n\t\t" << quant << " room/rooms have been allotted to you!";
		}
		else
			cout << "\n\tOnly" << Qrooms - Srooms << " rooms remaining in hotel!";
		break;
	case 2:
		cout << "\n\n The number of Pasta you want: ";
		cin >> quant;
		if (Qpasta - Spasta >= quant) {
			Spasta = Spasta + quant;
			Total_pasta = Total_pasta + quant * 10;
			cout << "\n\n\t\t" << quant << " pasta has been ordered!";
		}
		else
			cout << "\n\tOnly" << Qpasta - Spasta << " pastas remaining in hotel!";
		break;
	case 3:
		cout << "\n\n The number of Burger you want: ";
		cin >> quant;
		if (Qburger - Sburger >= quant) {
			Sburger = Sburger + quant;
			Total_burger = Total_burger + quant * 5;
			cout << "\n\n\t\t" << quant << " burger has been ordered!";
		}
		else
			cout << "\n\tOnly" << Qburger - Sburger << " burgers remaining in hotel!";
		break;
	case 4:
		cout << "\n\n The number of Noodle you want: ";
		cin >> quant;
		if (Qnoodles - Snoodles >= quant) {
			Snoodles = Snoodles + quant;
			Total_noodles = Total_noodles + quant * 15;
			cout << "\n\n\t\t" << quant << " noodles has been ordered!";
		}
		else
			cout << "\n\tOnly" << Qnoodles - Snoodles << " noodles remaining in hotel!";
		break;
	case 5:
		cout << "\n\n The number of Shake you want: ";
		cin >> quant;
		if (Qshake - Sshake >= quant) {
			Sshake = Sshake + quant;
			Total_shake = Total_shake + quant * 3;
			cout << "\n\n\t\t" << quant << " shake has been ordered!";
		}
		else
			cout << "\n\tOnly" << Qshake - Sshake << " shakes remaining in hotel!";
		break;
	case 6:
		cout << "\n\n The number of Chicken you want: ";
		cin >> quant;
		if (Qchicken - Schicken >= quant) {
			Schicken = Schicken + quant;
			Total_chicken = Total_chicken + quant * 15;
			cout << "\n\n\t\t" << quant << " chicken has been ordered!";
		}
		else
			cout << "\n\tOnly" << Qchicken - Schicken << " chicken remaining in hotel!";
		break;
	case 7:
		cout << "\n\t Details of sales and collection :";
		cout << "\n\n Number of rooms we had: " << Qrooms;
		cout << "\n\n Number of rooms we allotted: " << Srooms;
		cout << "\n\n Remaining rooms: " << Qrooms - Srooms;
		cout << "\n\n Total collection of rooms for the day: " << Total_rooms;

		cout << "\n\n Number of pastas we had: " << Qpasta;
		cout << "\n\n Number of pastas we sold: " << Spasta;
		cout << "\n\n Remaining pastas: " << Qpasta - Spasta;
		cout << "\n\n Total collection of pastas for the day: " << Total_pasta;

		cout << "\n\n Number of burgers we had: " << Qburger;
		cout << "\n\n Number of burgers we sold: " << Sburger;
		cout << "\n\n Remaining burgers: " << Qburger - Sburger;
		cout << "\n\n Total collection of burgers for the day: " << Total_burger;

		cout << "\n\n Number of noodles we had: " << Qnoodles;
		cout << "\n\n Number of noodles we sold: " << Snoodles;
		cout << "\n\n Remaining noodles: " << Qnoodles - Snoodles;
		cout << "\n\n Total collection of noodles for the day: " << Total_noodles;

		cout << "\n\n Number of shakes we had: " << Qshake;
		cout << "\n\n Number of shakes we sold: " << Sshake;
		cout << "\n\n Remaining shakes: " << Qshake - Sshake;
		cout << "\n\n Total collection of shake for the day: " << Total_shake;

		cout << "\n\n Number of chicken we had: " << Qchicken;
		cout << "\n\n Number of chicken we sold: " << Schicken;
		cout << "\n\n Remaining chicken: " << Qchicken - Schicken;
		cout << "\n\n Total collection of chicken for the day: " << Total_chicken;

		cout << "\n\n Total collection for the day: " << Total_rooms + Total_pasta + Total_burger + Total_noodles + Total_shake + Total_chicken;
		break;
	case 8:
		exit(0);
	default:
		cout << "\n Please select the number in the menu!";
	}
	goto m;
}