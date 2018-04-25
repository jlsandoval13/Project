/*
 * Project.c
 *
 *  Created on: Apr 23, 2018
 *      Author: Dexter Jager
 */
#include <stdio.h>
#define boolean int
#define true 1
#define false 0

char tSeats [15][30] = {}; //Total seats
double price [15] = {0}; //Ticket price
double tickets = 0; //
int sold = 0; //Total tickets sold
int available = 15*30; //Total tickets available

void MainMenu();
void prices();
void seats();
void sales();
void seating();
void purchase();
void clear();
int validInt();

int main()
{
	MainMenu();
	return 0;
}

void MainMenu()
{
	clear();
	char choice;
	boolean ticpri = false;
	while( choice != '6')
	{
		printf("Main Menu \nSelect one of the following options to begin. ( 1 - 6 )\n");
		printf("1. Set Ticket Prices\n");
		printf("2. View Ticket Sales\n");
		printf("3. View Available Seats\n");
		printf("4. Purchase Tickets\n");
		printf("5. Clear Theater Seats\n");
		printf("6. Quit\n");

		choice = getchar();
		scanf("%*c");
		switch(choice){
		case '1':
			prices();
			ticpri = true;
			break;
		case '2':
			sales();
			break;
		case '3':
			seating();
			printf("A total of %d seats are available",available );
			seats();
			break;
		case '4':
			if(ticpri == false)
				printf("No prices have been set for the tickets. Try again after Ticket Pricing has been updated.");
			else
				purchase();
			break;
		case '5':
			clear();
			break;
		case'6':
			printf("\nProgram has been exited.");
			break;
		default:
			printf("\nInvalid choice has been made. Please try again");
			break;
		}
	}
}

void prices()
{
	double p;
	printf("\nEnter ticket prices for each row.\n");
	for( int x = 0; x < 15; x++ )
	{
		p = 0;
		printf("Price for Row %d: $", x+1);
		if( scanf("%1lf",&p) && p > 0)
			printf("Invalid input. Close and try again.");

		price[x] = p;
	}
	printf("All rows have ticket prices.");
}

void seats()
{
	int total = 0;
	for( int l = 0; l < 15; l++)
	{
		for( int m = 0; m < 30; m++)
		{
			if( tSeats[l][m] == '-')
				total ++;
		}
		printf("Row: %d, %d seats are left at %.2f",l+1,total,price[l]);
		total = 0;
	}
}

void sales()
{
	printf("The total amount from ticket sales is %.2f", tickets);
}

void seating()
{
	printf("Seats: 123456789012345678901234567890");
	for( int i = 0; i < 15; i++)
	{
		printf("\nRow %d :",i+1);
		for( int j = 0; j < 30; j++)
			printf("%c",tSeats[i][j]);
	}
}

void purchase()
{
	seating();
	double tot = 0;
	int ticket = 0;
	ticket = validInt("Enter a number of tickets to purchase: ", available);
	for( int a = 0; a < ticket; a++)
	{
		int row = 0;
		int seat = 0;

		tSeats[row][seat] = '*';
		sold ++;
		available --;
		tot += price[row];
	}
	printf("Your total is $%.2f",tot);
	tickets += tot;
}

int validInt(char direction[], int min, int max)
{
	int a = 0;
	printf("%s",direction);
	if(scanf("%d", &a) && a > min && a <= max)
		printf("hi");
	else
		printf("Invalid input");
	scanf("%*c");
	return a;
}

void clear()
{
	for( int a = 0; a < 15; a++ )
		for( int b = 0; b < 30; b++)
			tSeats[a][b] = '-';
}
