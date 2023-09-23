#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void fwrite(int, string);
int fread(string);
bool checks(string, int);
int checkl(string,string, int);
int checkg(string, int, int);
bool checkb(int, int);
void addtocart(string, int, int, int);

struct cart
{
	string name;
	float price;
	int count;
};
struct Users
{
	string username;
	string password;
	int bonus;
	int credit;
	int shoppingN;
	cart scart[10];
} susers[10];
struct Goods
{
	string name;
	float price;
	int count;
} sgoods[10];

fstream fusers;
fstream fgoods;
int main()
{
	int n1 = 0, n2 = 0, un = 0, gn = 0, uk = 0, ua = 0, um = 0, a = 1;
	int Admins[10] = { 0 };
	int ninput1 = 0, ninput2 = 0;
	string input, input1, input2, input3, type;
	bool login = false, Admin = false;

	n1 = fread("users");
	n2 = fread("goods");

	while (true)
	{
		input = "";
		cin >> input;
		if (login == false) {
			if (input == "signup") {
				cin >> input1;
				cin >> input2;
				if (checks(input1,n1)) {
					susers[n1].username = input1;
					susers[n1].password = input2;
					susers[n1].bonus = susers[n1].credit = 0;
					n1++;
					fwrite(n1, "newusers");
					cout << "800" << endl;
					continue;
				}
				else {
					cout << "802" << endl;
					continue;
				}
			}
			else if (input == "login") {
				cin >> input1;
				cin >> input2;
				if (checkl(input1, input2, n1) == 0) {
					cout << "803" << endl;
					continue;
				}
				else if (checkl(input1, input2, n1) == 1) {
					cout << "804" << endl;
					continue;
				}
				else if (checkl(input1, input2, n1)==2) {
					for (int i = 0; i < n1; i++) {
						if (susers[i].username == input1) {
							un = i;
							break;
						}
					}
					login = true;
					for (int i = 0; i < a; i++) {
						if (Admins[i] == un) {
							Admin = true;
							break;
						}
					}
					cout << "800" << endl;
					continue;
				}
			}
			else if (input == "exit") {
				cout << "800";
				break;
			}
			else if (input == "codes") {
				cout << "800 : Successful" << endl;
				cout << "801 : Command not found or Invalid command" << endl;
				cout << "802 : Username already exists" << endl;
				cout << "803 : User not found" << endl;
				cout << "804 : Wrong password" << endl;
				cout << "805 : Unexpected error" << endl;
				cout << "806 : Invalid input" << endl;
				cout << "807 : Good not found" << endl;
				cout << "808 : Not enough good" << endl;
				cout << "809 : You cannot afford this good" << endl;
				cout << "810 : Bought succesful" << endl;
				cout << "811 : Cart is empty" << endl;
				cout << "812 : Bonus is zero" << endl;
				cout << "813 : Convert Unsuccessful" << endl;
				cout << "814 : Convert successful" << endl;
				continue;
			}
			else if (input == "code") {
				cin >> ninput1;
				switch (ninput1) {
				case 800:
					cout << "800 : Successful" << endl;
					break;
				case 801:
					cout << "801 : Command not found or Invalid command" << endl;
					break;
				case 802:
					cout << "802 : Username already exists" << endl;
					break;
				case 803:
					cout << "803 : User not found" << endl;
					break;
				case 804:
					cout << "804 : Wrong password" << endl;
					break;
				case 805:
					cout << "805 : Unexpected error" << endl;
					break;
				case 806:
					cout << "806 : Invalid input" << endl;
					break;
				case 807:
					cout << "807 : Good not found" << endl;
					break;
				case 808:
					cout << "808 : Not enough good" << endl;
					break;
				case 809:
					cout << "809 : You cannot afford this good" << endl;
					break;
				case 810:
					cout << "810 : Bought succesful" << endl;
					break;
					cout << "811 : Cart is empty" << endl;
					break;
				case 812:
					cout << "812 : Bonus is zero" << endl;
					break;
				case 813:
					cout << "813 : Convert Unsuccessful" << endl;
					break;
				case 814:
					cout << "814 : Convert successful" << endl;
					break;
				default:
					cout << "806" << endl;
					break;
				}
				continue;
			}
			else {
				getline(cin, input1);
				cout << "801" << endl;
				continue;
			}
		}
		if (login == true) {
			if (input == "signup" || input == "login") {
				getline(cin, input1);
				cout << "801" << endl;
				continue;
			}
			else if (input == "logout") {
				login = false;
				cout << "800" << endl;
				continue;
			}
			else if (input == "deposit") {
				cin >> ninput1;
				if (ninput1 > 0) {
					susers[un].credit = susers[un].credit + ninput1;
					cout << "800" << endl;
					continue;
				}
				else {
					cout << "806" << endl;
					continue;
				}
			}
			else if (input == "credit") {
				cout << susers[un].credit << endl;
				continue;
			}
			else if (input == "show_goods") {
				cout << "good name, price, count" << endl;
				for (int i = 0; i < n2; i++) {
					cout << sgoods[i].name << ", " << sgoods[i].price << ", " << sgoods[i].count << endl;
				}
				continue;
			}
			else if (input == "buy") {
				cin >> input1;
				cin >> ninput1;
				if (ninput1 <= 0) {
					cout << "806";
					continue;
				}
				else if (checkg(input1, ninput1, n2) == 0) {
					cout << "807" << endl;
					continue;
				}
				else if (checkg(input1, ninput1, n2) == 1) {
					cout << "808" << endl;
					continue;
				}
				else if (checkg(input1, ninput1, n2) == 2) {
					for (int i = 0; i < n2; i++) {
						if (sgoods[i].name == input1) {
							gn = i;
							break;
						}
					}
					if (susers[un].credit >= (ninput1 * sgoods[gn].price)) {
						sgoods[gn].count = sgoods[gn].count - ninput1;
						susers[un].credit = susers[un].credit - (ninput1 * sgoods[gn].price);
						susers[un].bonus = susers[un].bonus + (ninput1 * sgoods[gn].price) / 10;
						susers[un].shoppingN = susers[un].shoppingN + ninput1;
						addtocart(sgoods[gn].name, sgoods[gn].price, ninput1, un);
						cout << "810" << endl;
						continue;
					}
					else {
						cout << "809" << endl;
						continue;
					}
				}

			}
			else if (input == "save") {
				fwrite(n1, "newusers");
				fwrite(n2, "new_goods");
				cout << "800" << endl;
				continue;
			}
			else if (input == "show_cart") {
				if (susers[un].shoppingN > 0) {
					cout << "good name, price, count" << endl;
					for (int i = 0; susers[un].scart[i].price != 0; i++) {
						cout << susers[un].scart[i].name << ", " << susers[un].scart[i].price << ", " << susers[un].scart[i].count << endl;
					}
					continue;
				}
				else {
					cout << "811" << endl;
					continue;
				}
			}
			else if (input == "my_bonus") {
				if (susers[un].shoppingN > 0) {
					cout << susers[un].bonus << endl;
					continue;
				}
				else {
					cout << "812" << endl;
					continue;
				}
			}
			else if (input == "convert_bonus") {
				if (checkb(susers[un].bonus, n2)) {
					susers[un].credit = susers[un].credit + susers[un].bonus;
					susers[un].bonus = 0;
					cout << "814" << endl;
					continue;
				}
				else {
					cout << "813" << endl;
					continue;
				}
			}
			else if (input == "del_account") {
				if (un != 0) {
					uk = un;
					for (int i = 0; i < a; i++) {
						if (Admins[i] == uk) {
							ua = i;
							un = -1;
							break;
						}
					}
					int j = 0;
					for (int i = 0; i < (n1-1); i++) {
						if (i >= uk)
							j = i + 1;
						else
							j = i;
						susers[i].username = susers[j].username;
						susers[i].password = susers[j].password;
						susers[i].bonus = susers[j].bonus;
						susers[i].credit = susers[j].credit;
						susers[i].shoppingN = susers[j].shoppingN;
					}
					n1--;
					j = 0;
					if (un == -1) {
						for (int i = 0; i < (a - 1); i++) {
							if (i >= ua)
								j = i + 1;
							else
								j = i;
							Admins[i] = Admins[j];
						}
						a--;

					}
					
					cout << "800" << endl;
					login = false;
					continue;
				}
				else {
					cout << "806" << endl;
					continue;
				}
			}
			else if (input == "codes") {
				cout << "800 : Successful" << endl;
				cout << "801 : Command not found or Invalid command" << endl;
				cout << "802 : Username already exists" << endl;
				cout << "803 : User not found" << endl;
				cout << "804 : Wrong password" << endl;
				cout << "805 : Unexpected error" << endl;
				cout << "806 : Invalid input" << endl;
				cout << "807 : Good not found" << endl;
				cout << "808 : Not enough good" << endl;
				cout << "809 : You cannot afford this good" << endl;
				cout << "810 : Bought succesful" << endl;
				cout << "811 : Cart is empty" << endl;
				cout << "812 : Bonus is zero" << endl;
				cout << "813 : Convert Unsuccessful" << endl;
				cout << "814 : Convert successful" << endl;
				continue;
			}
			else if (input == "code") {
				cin >> ninput1;
				switch (ninput1) {
				case 800:
					cout << "800 : Successful" << endl;
					break;
				case 801:
					cout << "801 : Command not found or Invalid command" << endl;
					break;
				case 802:
					cout << "802 : Username already exists" << endl;
					break;
				case 803:
					cout << "803 : User not found" << endl;
					break;
				case 804:
					cout << "804 : Wrong password" << endl;
					break;
				case 805:
					cout << "805 : Unexpected error" << endl;
					break;
				case 806:
					cout << "806 : Invalid input" << endl;
					break;
				case 807:
					cout << "807 : Good not found" << endl;
					break;
				case 808:
					cout << "808 : Not enough good" << endl;
					break;
				case 809:
					cout << "809 : You cannot afford this good" << endl;
					break;
				case 810:
					cout << "810 : Bought succesful" << endl;
					break;
					cout << "811 : Cart is empty" << endl;
					break;
				case 812:
					cout << "812 : Bonus is zero" << endl;
					break;
				case 813:
					cout << "813 : Convert Unsuccessful" << endl;
					break;
				case 814:
					cout << "814 : Convert successful" << endl;
					break;
				default:
					cout << "806" << endl;
					break;
				}
				continue;
			}
			else if ((input == "show_users") && (Admin == true)) {
				cout << "username (type)" << endl;
				for (int i = 0; i < n1; i++) {
					type = "Member";
					for (int j = 0; j < a; j++) {
						if (Admins[j] == i)
							type = "Admin";
					}
					cout << susers[i].username << " (" << type << ")" << endl;
				}
				continue;
			}
			else if ((input == "user") && (Admin == true)) {
				cin >> input1;
				if (!checks(input1, n1)) {
					for (int i = 0; i < n1; i++) {
						if (susers[i].username == input1) {
							um = i;
							break;
						}
					}
					type = "Member";
					for (int j = 0; j < a; j++) {
						if (Admins[j] == um)
							type = "Admin";
					}
					cout << "username : " << susers[um].username << endl;
					cout << "pasword : " << susers[um].password << endl;
					cout << "bonus : " << susers[um].bonus << endl;
					cout << "credit : " << susers[um].credit << endl;
					cout << "The number of purchases : " << susers[um].shoppingN << endl;
					cout << "type : " << type << endl;
					continue;
				}
				else {
					cout << "803" << endl;
					continue;
				}
			}
			else if ((input == "kick") && (Admin == true)) {
				cin >> input1;
				if (!checks(input1, n1)) {
					for (int i = 0; i < n1; i++) {
						if (susers[i].username == input1) {
							uk = i;
							break;
						}
					}
					for (int i = 0; i < a; i++) {
						if (Admins[i] == uk) {
							uk = -1;
							break;
						}
					}
					if (uk == -1) {
						cout << "806" << endl;
						continue;
					}
					int j = 0;
					input2 = susers[un].username;
					for (int i = 0; i < (n1-1); i++) {
						if (i >= uk)
							j = i + 1;
						else
							j = i;
						susers[i].username = susers[j].username;
						susers[i].password = susers[j].password;
						susers[i].bonus = susers[j].bonus;
						susers[i].credit = susers[j].credit;
						susers[i].shoppingN = susers[j].shoppingN;
						if (susers[i].username == input2)
							un = i;
					}
					n1--;
					for (int i = 0; i < a; i++) {
						if (Admins[i] >= uk) {
							Admins[i] = Admins[i] - 1;
						}
					}
					cout << "800" << endl;
					continue;
				}
				else {
					cout << "803" << endl;
					continue;
				}
			}
			else if ((input == "set_admin") && (Admin == true)) {
				cin >> input1;
				if (!checks(input1, n1)) {
					for (int i = 0; i < n1; i++) {
						if (susers[i].username == input1) {
							ua = i;
							break;
						}
					}
					for (int i = 0; i < a; i++) {
						if (Admins[i] == ua) {
							ua = -1;
							break;
						}
					}
					if (ua == -1) {
						cout << "802" << endl;
						continue;
					}
					else {
						Admins[a] = ua;
						a++;
						cout << "800" << endl;
						continue;
					}
				}
				else {
					cout << "803" << endl;
					continue;
				}
			}
			else if ((input == "set_member") && (Admin == true) && (un == 0)) {
				cin >> input1;
				if (!checks(input1, n1)) {
					for (int i = 0; i < n1; i++) {
						if (susers[i].username == input1) {
							um = i;
							break;
						}
					}
					uk = 0;
					for (int i = 0; i < a; i++) {
						if (Admins[i] == um) {
							ua = i;
							uk = 1;
							break;
						}
					}
					if (uk == 0 || input1 == "Admin") {
						cout << "802" << endl;
						continue;
					}
					else {
						int j = 0;
						for (int i = 0; i < a; i++) {
							if (i >= ua)
								j = i + 1;
							else
								j = i;
							Admins[i] = Admins[j];
						}
						a--;
						cout << "800" << endl;
						continue;
					}
				}
				else {
					cout << "803" << endl;
					continue;
				}
			}
			else if ((input == "set_member") && (Admin == true) && (un != 0)) {
				getline(cin, input1);
				cout << "801" << endl;
				continue;
			}
			else if ((input == "change_price") && (Admin == true)) {
				cin >> input1;
				cin >> ninput1;
				if (checkg(input1, 0, n2) == 2) {
					for (int i = 0; i < n2; i++) {
						if (sgoods[i].name == input1) {
							gn = i;
							break;
						}
					}
					sgoods[gn].price = ninput1;
					cout << "800" << endl;
					continue;
				}
				else if (checkg(input1, 0, n2) == 0) {
					cout << "807" << endl;
					continue;
				}
			}
			else if ((input == "change_count") && (Admin == true)) {
				cin >> input1;
				cin >> ninput1;
				if (checkg(input1, 0, n2) == 2) {
					for (int i = 0; i < n2; i++) {
						if (sgoods[i].name == input1) {
							gn = i;
							break;
						}
					}
					sgoods[gn].count = ninput1;
					cout << "800" << endl;
					continue;
				}
				else if (checkg(input1, 0, n2) == 0) {
					cout << "807" << endl;
					continue;
				}
			}
			else if ((input == "change_count" || input == "change_price" || input == "set_member" || input == "set_admin" || input == "kick" || input == "show_users" || input == "user") && (Admin == false)) {
				getline(cin, input1);
				cout << "801" << endl;
				continue;
			}
			else if (input == "exit") {
				cout << "800";
				break;
			}
			else {
				getline(cin, input1);
				cout << "801" << endl;
				continue;
			}
		}
	}
}

void fwrite(int n, string s)
{
	string ss = s + ".txt";
	if (s == "users" || s == "newusers") {
		fusers.open(ss, ios::trunc | ios::out);
		for (int i = 0; i < n; i++) {
			fusers << susers[i].username << " ";
			fusers << susers[i].password << " ";
			fusers << susers[i].bonus << " ";
			fusers << susers[i].credit << " ";
			if ((i + 1) == n)
				fusers << susers[i].shoppingN;
			else
				fusers << susers[i].shoppingN << endl;
		}
		fusers.close();
	}
	else if (s == "goods_db" || s == "new_goods") {
		fgoods.open(ss, ios::trunc | ios::out);
		for (int i = 0; i < n; i++) {
			fgoods << sgoods[i].name << " ";
			fgoods << sgoods[i].price << " ";
			if ((i + 1) == n)
				fgoods << sgoods[i].count;
			else
				fgoods << sgoods[i].count << endl;	
		}
		fgoods.close();
	}
}
int fread(string s)
{
	int n = 0;
	if (s == "users") {
		fusers.open("users.txt");
		for (int i = 0; !fusers.eof(); i++) {
			fusers >> susers[i].username;
			fusers >> susers[i].password;
			fusers >> susers[i].bonus;
			fusers >> susers[i].credit;
			fusers >> susers[i].shoppingN;
			n++;
		}
		fusers.close();
		return n;
	}
	if (s == "goods") {
		fgoods.open("goods_db.txt", ios::in);
		for (int i = 0; !fgoods.eof(); i++) {
			fgoods >> sgoods[i].name;
			fgoods >> sgoods[i].price;
			fgoods >> sgoods[i].count;
			n++;
		}
		fgoods.close();
		return n;
	}
}
bool checks(string s,int n)
{
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (susers[i].username == s) {
			c = 1;
			break;
		}
	}
	if (c == 1)
		return false;
	else
		return true;
}
int checkl(string u,string p, int n)
{
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (susers[i].username == u) {
			c = 1;
			if (susers[i].password == p) {
				c = 2;
				break;
			}
		}
	}
	if (c == 0)
		return 0;
	else if (c==1)
		return 1;
	else if (c == 2)
		return 2;
}
int checkg(string s, int a, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++) {
		if (sgoods[i].name == s) {
			
			if (sgoods[i].count >= a) {
				return 2;
			}
			else {
				return 1;
			}
			break;
		}
	}
	if (i == n) {
		return 0;
	}
}
bool checkb(int a, int n)
{
	int min = 32767;
	for (int i = 0; i < n; i++) {
		if (sgoods[i].price <= min) {
			min = sgoods[i].price;
		}
	}
	if (min <= a)
		return true;
	else
		return false;
}
void addtocart(string s, int p, int c, int un)
{
	int i = 0, j = 0;
	while (susers[un].scart[i].name != "") {
		if (susers[un].scart[i].name == s) {
			if (susers[un].scart[i].price == p) {
				j = 2;
				break;
			}
			else {
				j = 1;
			}
		}
		i++;
	}
	if (j == 0 || j==1) {
		susers[un].scart[i].name = s;
		susers[un].scart[i].price = p;
		susers[un].scart[i].count = c;
	}
	else if (j == 2) {
		susers[un].scart[i].count = susers[un].scart[i].count + c;
	}
}