#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include"Header.h"//header file in which all functions are placed

using namespace std;
//Function prototype all the functions prototype are given here
void Entry();
void Main_menu();
int Rndnum();
void Move_P1(int[][10], int&, int&, int, int&, bool&, int&);
void Move_P2(int[][10], int&, int&, int, int&, bool&, int&);
void Move_P3(int[][10], int&, int&, int, int&, bool&, int&);
void Move_P4(int[][10], int&, int&, int, int&, bool&, int&);
void p1(char[50], int&, int&, int&, int[4], int[][10], int, bool[4], int&, int&, int&, int[4]);
void p2(char[50], int&, int&, int&, int[4], int[][10], int, bool[4], int&, int&, int&, int[4]);
void p3(char[50], int&, int&, int&, int[4], int[][10], int, bool[4], int&, int&, int&, int[4]);
void p4(char[50], int&, int&, int&, int[4], int[][10], int, bool[4], int&, int&, int&, int[4]);
void table(int[][10], int, int&);
void Cover(int&, int&, int&, int&);
void Snake_Ladder(int&);
void LDR_SNK(int&);
void credits();
void instructions();

//---------This is main function of program----------
int main()
{
	int Score1 = 0, Score2 = 0, Score3 = 0, Score4 = 0, t[4];
	int location1[4], location[4];
	bool roll[4] = { false };
	const int S = 10;
	int counter = 100;
	bool last = false; const int S1 = 50;
	int dice, dice1;
	char ply1[S1], ply2[S1], ply3[S1], ply4[S1];
	int board[S][S], toss1, toss2, toss3, toss4;
	char repeat = '0', key; {}
	int record1 = 0, record2 = 0, record3 = 0, record4 = 0;
	ofstream myfile;
	ifstream file;
	char g;
	Entry();//function calling for beautiful startup
	while (repeat == '0') {
		Main_menu();//this function  calling is for main menu
		int num;
		cin >> num;//taking input from user
		char x = _getch();
		{
			switch (num)
			{
			case 1: {

				system("cls");//for clearing whole output screen
				system("color E4");//for changing console backgroud and foreground color 
				cout << "Enter name of Player 1:";
				cin.ignore();
				cin.getline(ply1, S1);
				cout << "Enter name of Player 2:";
				cin.getline(ply2, S1);//getting name in array
				cout << "Enter name of Player 3:";
				cin.getline(ply3, S1);
				cout << "Enter name of Player 4:";
				cin.getline(ply4, S1);
				cout << "\n\n\t\tWelcome to My Game Snake and Ladder\n\n\n";
				cout << "\n\tPress any key to continue...\n";
				//---------------Toss------------------
				system("color F5");
				srand(time(0));
				toss1 = rand() % 4 + 1;
				toss2 = rand() % 4 + 1;
				while (toss2 == toss1) {
					toss2 = rand() % 4 + 1;
				}
				toss3 = rand() % 4 + 1;
				while (toss3 == toss1 || toss3 == toss2) {
					toss3 = rand() % 4 + 1;
				}
				toss4 = rand() % 4 + 1;
				while (toss4 == toss1 || toss4 == toss2 || toss4 == toss3) {
					toss4 = rand() % 4 + 1;
				}
				//------------------ 1st player turn
				if (toss1 == 1) {
					cout << endl << ply1 << " has " << toss1 << "st turn\n";
				}
				if (toss1 == 2) {
					cout << endl << ply1 << " has " << toss1 << "nd turn\n";
				}
				if (toss1 == 3) {
					cout << endl << ply1 << " has " << toss1 << "rd turn\n";
				}
				if (toss1 == 4) {
					cout << endl << ply1 << " has " << toss1 << "th turn\n";
				}
				//---------------player 2 turns
				if (toss2 == 1) {
					cout << endl << ply2 << " has " << toss2 << "st turn\n";
				}
				if (toss2 == 2) {
					cout << endl << ply2 << " has " << toss2 << "nd turn\n";
				}
				if (toss2 == 3) {
					cout << endl << ply2 << " has " << toss2 << "rd turn\n";
				}
				if (toss2 == 4) {
					cout << endl << ply2 << " has " << toss2 << "th turn\n";
				}
				//---------------player 3 turns
				if (toss3 == 1) {
					cout << endl << ply3 << " has " << toss3 << "st turn\n";
				}
				if (toss3 == 2) {
					cout << endl << ply3 << " has " << toss3 << "nd turn\n";
				}
				if (toss3 == 3) {
					cout << endl << ply3 << " has " << toss3 << "rd turn\n";
				}
				if (toss3 == 4) {
					cout << endl << ply3 << " has " << toss3 << "th turn\n";
				}
				//--------------player 4 turns
				if (toss4 == 1) {
					cout << endl << ply4 << " has " << toss4 << "st turn\n";
				}
				if (toss4 == 2) {
					cout << endl << ply4 << " has " << toss4 << "nd turn\n";
				}
				if (toss4 == 3) {
					cout << endl << ply4 << " has " << toss4 << "rd turn\n";
				}
				if (toss4 == 4) {
					cout << endl << ply4 << " has " << toss4 << "th turn\n";
				}
				//------------assigning characters to players------------ 
				cout << "\n" << ply1 << " has " << '@' << " character\n";
				cout << ply2 << " has " << '$' << " character\n";
				cout << ply3 << " has " << '&' << " character\n";
				cout << ply4 << " has " << '#' << " character\n\n\n";
				//------------For table to prin in inverse form-----------
				for (int i = 0; i < S; i++)
				{
					if (i == 0)
					{
						for (int j = 0; j < S; j++)
						{
							board[i][j] = counter;
							--counter;
						}
					}
					else if (i % 2 == 0)
					{
						counter = counter - 11;
						for (int j = 0; j < S; j++)
						{
							board[i][j] = counter;
							--counter;
						}
					}
					else if (i % 2 != 0)
					{
						counter = counter - 9;
						for (int j = 0; j < S; j++)
						{
							board[i][j] = counter;
							++counter;
						}
					}
				}
				table(board, S, Score4);
				srand(time(0));
				cout << "Start your Game\n";
				myfile.open("record.txt", ios::out);
				while (Score1 < 100 && Score2 < 100 && Score3 < 100 || Score1 < 100 && Score2 < 100 && Score4 < 100 || Score1 < 100 && Score3 < 100 && Score4 < 100 || Score2 < 100 && Score3 < 100 && Score4 < 100)
				{
					for (int n = 1; n <= 4; n++) {
						if (toss1 == n) {
							if (Score1 < 101) {
								//------------------calling player1 function in which player 1 takes his turn
								p1(ply1, dice, dice1, Score1, t, board, S, roll, Score2, Score3, Score4, location);
								record1++;
							}
						}
						if (toss2 == n) {
							if (Score2 < 101) {
								//------------------calling player2 function in which player 2 takes his turn
								p2(ply2, dice, dice1, Score1, t, board, S, roll, Score2, Score3, Score4, location);
								record2++;
							}
						}
						if (toss3 == n) {
							if (Score3 < 101) {
								//------------------calling player3 function in which player 3 takes his turn
								p3(ply3, dice, dice1, Score1, t, board, S, roll, Score2, Score3, Score4, location);
								record3++;
							}
						}
						if (toss4 == n) {
							if (Score4 < 101) {
								//------------------calling player3 function in which player 3 takes his turn
								p4(ply4, dice, dice1, Score1, t, board, S, roll, Score2, Score3, Score4, location);
								record4++;
							}
						}
					}
					cout << "		Start Next Turn\t\t\tPress any key... \n" << endl;
					x = _getch();
					system("cls");
					table(board, S, Score4);
				}
			}
				  myfile << record1 << "\n";
				  myfile << record2 << "\n";
				  myfile << record3 << "\n";
				  myfile << record4 << "\n";
				  myfile.close();
				  break;
			case 2:
				credits();
				cout << "\nPress any key to return back to main menu\n";
				repeat = '0';
				key = _getch();
				break;

			case 3:
				instructions();
				cout << "\nPress any key to return back to main menu\n";
				repeat = '0';
				key = _getch();
				break;
			case 4:
				//----------record------------
				system("cls");
				system("color 3F");
				cout << setw(50) << "\t\t<--RECORD-->\n";
				file.open("record.txt", ios::in);
				while (!file.eof()) {
					file.get(g);
					cout << g;
				}
				file.close();
				cout << "\nPress any key to return back to main menu\n";
				repeat = '0';
				key = _getch();
				break;

			case 5:
				system("cls");
				cout << "\n\n\n\t\t>---------Good Bye---------<\n\n\n";
				repeat = '1';
				break;
			default:
				cout << "\nPlease Enter the valid number\n";
			}
		}
	}
	system("pause");
	return 0;
}

