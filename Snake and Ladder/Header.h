#include<fstream>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
//------------this function helps in start up for show -------
void Entry()
{
	system("color 3F");
	cout << "\n\n\t\t---------------------------------------------------------" << endl;
	cout << "\n\n\t\t\t---S"; Sleep(100); cout << "N"; Sleep(100); cout << "A"; Sleep(100); cout << "K"; Sleep(100); cout << "E"; Sleep(100); cout << " &"; Sleep(100); cout << " L"; Sleep(100); cout << "A"; Sleep(100); cout << "D"; Sleep(100); cout << "D"; Sleep(100); cout << "E"; Sleep(100); cout << "R---" << endl;
	cout << "\n\n\t\t--------------------------------------------------------" << endl;
	cout << "\n\n\t\t\tCredit: H"; Sleep(200); cout << "A"; Sleep(200); cout << "S"; Sleep(200); cout << "N"; Sleep(200); cout << "A"; Sleep(200); cout << "I"; Sleep(200); cout << "N"; Sleep(200); cout << "  R"; Sleep(200); cout << "I"; Sleep(200); cout << "A"; Sleep(200); cout << "Z";
	cout << "\n\t\t\tRoll No.:" << " "; Sleep(200); cout << "2"; Sleep(200); cout << "0"; Sleep(200); cout << "F"; Sleep(200); cout << "_"; Sleep(200); cout << "0"; Sleep(200); cout << "3"; Sleep(200); cout << "0"; Sleep(200); cout << "0"; Sleep(200);
	cout << "\n\n\n\t\t\tLoading";
	for (int i = 0; i < 8; i++)
	{
		Sleep(400);
		cout << ".";

	}
	system("cls");

}
//---------------------this function is for main menu---------------- 
void Main_menu()
{
	system("cls");
	system("color 27");
	cout << "\t\t\t<--Main Menu-->\n\n";
	cout << "\t\t1.Play game\n";
	cout << "\t\t2.credits\n";
	cout << "\t\t3.Rules\n";
	cout << "\t\t4.Records\n";
	cout << "\t\t5.Exit\n";
}
int Rndnum()
{
	return rand() % 6 + 1;
}
//--------------MAKING TABLE OF 10x10 
void table(int board[][10], int S, int& score)
{
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
			if (board[i][j] == 102)
			{
				cout << setw(8) << '@';
			}
			else if (board[i][j] == 103)
			{
				cout << setw(8) << '$';
			}
			else if (board[i][j] == 104)
			{
				cout << setw(8) << '&';
			}
			else if (board[i][j] == 105)
			{
				cout << setw(8) << '#';
			}
			else
			{
				if (board[i][j] == 8 || board[i][j] == 21 || board[i][j] == 33 || board[i][j] == 53 || board[i][j] == 79) {
					//---------------WRITING L WHERE IS LADDER 
					cout << setw(8) << "L";
				}
				else {
					if (board[i][j] == 27 || board[i][j] == 60 || board[i][j] == 73 || board[i][j] == 85 || board[i][j] == 99) {
						//---------------WRITING S WHERE IS SNAKE 
						cout << setw(8) << "S";
					}
					else {
						cout << setw(8) << board[i][j];
					}
				}
			}
		cout << endl;
		cout << endl;
	}
}
//-----------------------this helps to move the player 1 character from 0 to 100 depending on dices------------
void Move_P1(int board[][10], int& dice, int& dice1, int  S, int& player, bool& side1, int& t)
{
	int playeR = 102;
	if (side1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			side1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			side1 = true;
		}

	}
	if (side1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == playeR && side1 == true)
			{
				board[i][j] = t;
			}
		}
	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == player && side1 == true)
			{
				t = board[i][j];
				board[i][j] = playeR;
			}
		}
	}
}
//-----------------------this helps to move the player 2 character from 0 to 100 depending on dices------------
void Move_P2(int board[][10], int& dice, int& dice1, int  S, int& player, bool& side1, int& t)
{
	int playeR = 103;
	if (side1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			side1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			side1 = true;
		}

	}
	if (side1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == playeR && side1 == true)
			{

				board[i][j] = t;
			}
		}
	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == player && side1 == true)
			{
				t = board[i][j];
				board[i][j] = playeR;
			}
		}
	}
}
//-----------------------this helps to move the player 3 character from 0 to 100 depending on dices------------
void Move_P3(int board[][10], int& dice, int& dice1, int  S, int& player, bool& side1, int& t)
{
	int playeR = 104;
	if (side1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			side1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			side1 = true;
		}

	}
	if (side1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == playeR && side1 == true)
			{

				board[i][j] = t;
			}
		}
	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == player && side1 == true)
			{
				t = board[i][j];
				board[i][j] = playeR;
			}
		}
	}
}
//-----------------------this helps to move the player 4 character from 0 to 100 depending on dices------------
void Move_P4(int board[][10], int& dice, int& dice1, int  S, int& player, bool& side1, int& t)
{
	int playeR = 105;
	if (side1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			side1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			side1 = true;
		}

	}
	if (side1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == playeR && side1 == true)
			{

				board[i][j] = t;
			}
		}
	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == player && side1 == true)
			{
				t = board[i][j];
				board[i][j] = playeR;
			}
		}
	}
}
//------------this function increases or decreases the score as the player got the ladder and the snake
void LDR_SNK(int& sc)
{
	switch (sc)
	{
	case 8:
		sc = 16;
		break;
	case 21:
		sc = 43;
		break;
	case 33:
		sc = 86;
		break;
	case 53:
		sc = 70;
		break;
	case 79:
		sc = 98;
		break;
	case 27:
		sc =5;
		break;
	case 60:
		sc = 24;
		break;
	case 73:
		sc = 58;
		break;
	case 85:
		sc = 69;
		break;
	case 99:
		sc = 35;
		break;
	}
}
//--------------this is function informs the player when he got the snake or the ladder by displaying the message
void Snake_Ladder(int& sc)
{
	if (sc == 4 || sc == 19 || sc == 30 || sc == 50 || sc == 82)
	{
		cout << "Congrats!You got a Ladder\n";
		system("color A5");
		Sleep(1500);
		system("color F5");
	}
	else if (sc == 24 || sc == 60 || sc == 75 || sc == 89 || sc == 99)
	{
		cout << "Sad!You got a Snake\n";
		system("color C5");
		Sleep(1500);
		system("color F5");
	}
}
//--------------this function works when the two players comes on the same number then the 1st player comes to initial position
void Cover(int& pl1, int& pl2, int& pl3, int& pl4)
{
	if (pl1 == pl2 && pl1 != 100 && pl1 != 0)
	{
		pl2 = 0;
		cout << "You Kill Player\n";
	}
	if (pl1 == pl3 && pl1 != 100 && pl1 != 0)
	{
		pl3 = 0;
		cout << "You Kill Player\n";
	}
	if (pl1 == pl4 && pl1 != 100 && pl1 != 0)
	{
		pl4 = 0;
		cout << "You Kill Player\n";
	}
}
//----------------function to show the credits
void credits() {
	system("cls");
	system("color 3F");
	cout << setw(50) << "<--CREDITS-->\n";
	cout << "This Game is developed by Hasnain Riaz 20F-0300 student of BSE 1B of F.A.S.T CFD Campus under\nthe supervision of Sir Hannan Farooq\n";
}
//--------------function to run the whole player 1 turn------------------
void p1(char ply1[50], int& dice, int& dice1, int& Score1, int t[4], int board[][10], int S, bool side1[4], int& Score2, int& Score3, int& Score4, int location[4])
{
	char x = _getch();
	cout << ply1 << " Turn:-\t\tPress any key to roll Dices... \n" << endl;
	dice = Rndnum();

	x = _getch();
	LDR_SNK(Score1);
	cout << "Number on dice: " << dice << endl;
	if (dice == 6)
	{
		cout << "\nyou got extra turn\n";
		Move_P1(board, dice, dice1, S, Score1, side1[0], t[0]);
		table(board, S, Score1);
		x = _getch();
		dice1 = Rndnum();
		LDR_SNK(Score1);
		cout << "Number on dice2: " << dice1 << endl;
		while (dice1 == 6) {
			cout << "\nyou got extra turn\n";
			Move_P1(board, dice, dice1, S, Score1, side1[0], t[0]);
			table(board, S, Score1);
			x = _getch();
			dice1 = Rndnum();
			LDR_SNK(Score1);
			cout << "Number on dice2: " << dice1 << endl;
		}
	}
	else {
		dice1 = 0;
	}
	Move_P1(board, dice, dice1, S, Score1, side1[0], t[0]);
	Snake_Ladder(Score1);
	if (Score1 < 100)
	{
		cout << ply1 << " score: " << Score1 << endl;
	}
	if (Score1 >= 100 && Score2 < 100 && Score3 < 100 && Score4 < 100)
		//when player got first position---------------------
	{
		cout << ply1 << ":    Congratulations. You won the game.You are at 1st Position\n"; location[0] = 1;
	}
	if (Score2 >= 100 && Score3 < 100 && Score4 < 100 || Score3 >= 100 && Score2 < 100 && Score4 < 100 || Score4 >= 100 && Score3 < 100 && Score2 < 100)
	{
		if (Score1 >= 100)
		{
			cout << "    Congratulations, You got Second Position\n"; location[1] = 2;
		}
	}
	if (Score2 >= 100 && Score3 >= 100 && Score4 < 100 || Score3 >= 100 && Score2 < 100 && Score4 >= 100 || Score4 >= 100 && Score3 >= 100 && Score2 < 100)
	{
		if (Score1 >= 100)
		{
			cout << "   Congratulations, You got Third Position\n"; location[2] = 3;
		}
	}
	if (Score2 >= 100 && Score3 >= 100 && Score4 >= 100 && Score1 < 100)
	{
		cout << "   Sorry!You lose the Game\n"; location[3] = 4;
	}
	if (Score1 > 100)
	{
		Score1 = Score1 - (dice + dice1);
		cout << ply1 << " score: " << Score1 << endl;
	}
	table(board, S, Score1);
	Cover(Score1, Score2, Score3, Score4);
}
//--------------function to run the whole player 2 turn------------------
void p2(char ply2[50], int& dice, int& dice1, int& Score1, int t[4], int board[][10], int S, bool side1[4], int& Score2, int& Score3, int& Score4, int location[4])
{
	char x = _getch();
	cout << ply2 << " Turn:- \t\tPress any key to roll Dices...\n" << endl;
	dice = Rndnum();
	x = _getch();
	LDR_SNK(Score2);
	cout << "Number on dice:   " << dice << endl;
	if (dice == 6)
	{
		cout << "\nyou got extra turn\n";
		Move_P2(board, dice, dice1, S, Score2, side1[1], t[1]);
		table(board, S, Score2);
		x = _getch();
		dice1 = Rndnum();
		LDR_SNK(Score2);
		cout << "Number on dice2: " << dice1 << "\n" << endl;
		while (dice1 == 6) {
			cout << "\nyou got extra turn\n";
			Move_P2(board, dice, dice1, S, Score2, side1[1], t[1]);
			table(board, S, Score2);
			x = _getch();
			dice1 = Rndnum();
			LDR_SNK(Score2);
			cout << "Number on dice2: " << dice1 << "\n" << endl;
		}

	}
	else {
		dice1 = 0;
	}
	Move_P2(board, dice, dice1, S, Score2, side1[1], t[1]);
	Snake_Ladder(Score2);
	if (Score2 < 100)
	{
		cout << ply2 << " score: " << Score2 << endl;
	}
	if (Score2 >= 100 && Score1 < 100 && Score3 < 100 && Score4 < 100)
		//when player got first position---------------------
	{
		cout << ply2 << ":    Congratulations. You won the game.You are at 1st Position\n"; location[0] = 1;
	}
	if (Score1 >= 100 && Score3 < 100 && Score4 < 100 || Score3 >= 100 && Score1 < 100 && Score4 < 100 || Score4 >= 100 && Score3 < 100 && Score1 < 100)
	{
		if (Score2 >= 100)
			//when player got second position---------------------
		{
			cout << "   Congratulations, You got Second Position\n"; location[1] = 2;
		}
	}
	if (Score1 >= 100 && Score3 >= 100 && Score4 < 100 || Score3 >= 100 && Score1 < 100 && Score4 >= 100 || Score4 >= 100 && Score3 >= 100 && Score1 < 100)
	{
		if (Score2 >= 100)
			//when player got third position---------------------
		{
			cout << "    Congratulations, You got Third Position\n"; location[2] = 3;
		}
	}
	if (Score1 >= 100 && Score3 >= 100 && Score4 >= 100 && Score2 < 100)
	{
		cout << "   Sorry!You lose the Game\n"; location[3] = 4;
	}
	if (Score2 > 100)
	{
		Score2 = Score2 - (dice + dice1);
		cout << ply2 << " score: " << Score2 << endl;
	}

	table(board, S, Score2);
	Cover(Score2, Score1, Score3, Score4);
}
//--------------function to run the whole player 3 turn------------------
void p3(char ply3[50], int& dice, int& dice1, int& Score1, int t[4], int board[][10], int S, bool side1[4], int& Score2, int& Score3, int& Score4, int location[4])
{
	char x = _getch();
	cout << ply3 << " Turn:- \t\tPress any key to roll Dices...\n" << endl;
	dice = Rndnum();
	x = _getch();
	LDR_SNK(Score3);
	cout << "Number on dice:   " << dice << endl;
	if (dice == 6)
	{
		cout << "\nyou got extra turn\n";
		Move_P3(board, dice, dice1, S, Score3, side1[2], t[2]);
		table(board, S, Score3);
		x = _getch();
		dice1 = Rndnum();
		LDR_SNK(Score3);
		cout << "Number on dice2: " << dice1 << "\n" << endl;
		while (dice1 == 6) {
			cout << "\nyou got extra turn\n";
			Move_P3(board, dice, dice1, S, Score3, side1[2], t[2]);
			table(board, S, Score3);
			x = _getch();
			dice1 = Rndnum();
			LDR_SNK(Score3);
			cout << "Number on dice2: " << dice1 << "\n" << endl;
		}
	}
	else {
		dice1 = 0;
	}
	Move_P3(board, dice, dice1, S, Score3, side1[2], t[2]);
	Snake_Ladder(Score3);
	if (Score3 < 100)
	{
		cout << ply3 << " score: " << Score3 << endl;
	}
	if (Score3 >= 100 && Score2 < 100 && Score1 < 100 && Score4 < 100)
		//when player got first position---------------------
	{
		cout << ply3 << ":    Congratulations. You won the game.You are at 1st Position\n"; location[0] = 1;
	}
	if (Score2 >= 100 && Score1 < 100 && Score4 < 100 || Score1 >= 100 && Score2 < 100 && Score4 < 100 || Score4 >= 100 && Score1 < 100 && Score2 < 100)
	{
		if (Score3 >= 100)
			//when player got second position---------------------
		{
			cout << "   Congratulations, You got Second Position\n"; location[1] = 2;
		}
	}
	if (Score2 >= 100 && Score1 >= 100 && Score4 < 100 || Score2 >= 100 && Score1 < 100 && Score4 >= 100 || Score4 >= 100 && Score1 >= 100 && Score2 < 100)
	{
		if (Score3 >= 100)
			//when player got third position---------------------
		{
			cout << "   Congratulations, You got Third Position\n"; location[2] = 3;
		}
	}
	if (Score2 >= 100 && Score1 >= 100 && Score4 >= 100 && Score3 < 100)
	{
		cout << "   Sorry!You lose the Game\n"; location[3] = 4;
	}
	if (Score3 > 100)
	{
		Score3 = Score3 - (dice + dice1);
		cout << ply3 << " score: " << Score3 << endl;
	}

	table(board, S, Score3);
	Cover(Score3, Score2, Score1, Score4);
}
//--------------function to run the whole player 4 turn------------------
void p4(char ply4[50], int& dice, int& dice1, int& Score1, int t[4], int board[][10], int S, bool side1[4], int& Score2, int& Score3, int& Score4, int location[4])
{
	char x = _getch();
	cout << ply4 << " Turn:- \t\tPress any key to roll Dices..." << endl;
	dice = Rndnum();
	x = _getch();
	LDR_SNK(Score4);
	cout << "Number on dice:   " << dice << endl;
	if (dice == 6)
	{
		cout << "\nyou got extra turn\n";
		Move_P4(board, dice, dice1, S, Score4, side1[3], t[3]);
		table(board, S, Score4);
		x = _getch();
		dice1 = Rndnum();
		LDR_SNK(Score4);
		cout << "Number on dice2: " << dice1 << "\n" << endl;
		while (dice1 == 6) {
			cout << "\nyou got extra turn\n";
			Move_P4(board, dice, dice1, S, Score4, side1[3], t[3]);
			table(board, S, Score4);
			x = _getch();
			dice1 = Rndnum();
			LDR_SNK(Score4);
			cout << "Number on dice2: " << dice1 << "\n" << endl;
		}

	}
	else {
		dice1 = 0;
	}
	Move_P4(board, dice, dice1, S, Score4, side1[3], t[3]);
	Snake_Ladder(Score4);
	if (Score4 < 100)
	{
		cout << ply4 << " score:  " << Score4 << endl;
	}
	if (Score4 >= 100 && Score2 < 100 && Score3 < 100 && Score1 < 100)
		//when player got first position---------------------
	{
		cout << ply4 << ":    Congratulations. You won the game.You are at 1st Position\n"; location[0] = 1;
	}
	if (Score2 >= 100 && Score3 < 100 && Score1 < 100 || Score3 >= 100 && Score2 < 100 && Score1 < 100 || Score1 >= 100 && Score3 < 100 && Score2 < 100)
	{
		if (Score4 >= 100)
			//when player got second position---------------------
		{
			cout << "    Congratulations, You got Second Position\n"; location[1] = 2;
		}
	}
	if (Score2 >= 100 && Score3 >= 100 && Score1 < 100 || Score3 >= 100 && Score2 < 100 && Score1 >= 100 || Score1 >= 100 && Score3 >= 100 && Score2 < 100)
	{
		if (Score4 >= 100)
			//when player got third position---------------------
		{
			cout << "    Congratulations, You got Third Position\n"; location[2] = 3;
		}
	}
	if (Score2 >= 100 && Score3 >= 100 && Score1 >= 100 && Score4 < 100)
	{
		cout << "   Sorry!You lose the Game\n"; location[3] = 4;
	}
	if (Score4 > 100)
	{
		Score4 = Score4 - (dice + dice1);
		cout << ply4 << " score:  " << Score4 << endl;
	}

	table(board, S, Score4);
	Cover(Score4, Score2, Score3, Score1);
}
//--------------------this is function is for intructions to players---------------------
void instructions() {
	system("cls");
	system("color 3F");
	cout << setw(50) << "<--INSTRUCTIONS & RULES-->\n";
	cout << "\nFirst there will be Toss for the turn of player and they will assigned an character\n";
	cout << "Then the player which got the six numbers on the dice will start the game and kept on\n";
	cout << "throwing dice until he reaches the 100 position. There are five snakes and ladders if\n";
	cout << "If the player goes to the starting point of snake or ladder then he goes where the snake\n";
	cout << "and the ladder ends. The player who reaches 100 poition first will win the game if the player\n";
	cout << "goes on the location of any other player then the first player will come into his new position\n";

}
