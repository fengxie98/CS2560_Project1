#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int ROW_COUNT  = 15;
static const int SEAT_COUNT = 30;

static void
clear_line(void)
{
	while(getchar() != '\n');
}

static void
get_seat_prices(double *prices)
{
	char buffer[256];
	int index = 0;

	while(index < ROW_COUNT) {
		bool ok = false;

		do {
			printf("Enter the seat price for row %02d: ", index + 1);
			fgets(buffer, 256, stdin);

			if(sscanf(buffer, "%lf", prices + index) == 1) {
				ok = true;
			}
			else {
				printf("Invalid price!\n");
			}
		} while(!ok);

		++index;
	}
}

static void
print_seating_chart(bool *seats)
{
	printf(
		"\t            Seats\n"
		"\t123456789012345678901234567890\n"
	);

	for(int i = 0; i < ROW_COUNT; ++i) {
		printf("Row %d\t", i + 1);

		for(int j = 0; j < SEAT_COUNT; ++j) {
			putchar(seats[i * ROW_COUNT + j] ? '*' : '#');
		}

		putchar('\n');
	}
}

static void
print_seat_availability(bool *seats)
{
	int seats_sold = 0;
	int seats_auditorium = ROW_COUNT * SEAT_COUNT;

	for(int i = 0; i < ROW_COUNT; ++i) {
		int row_seats = SEAT_COUNT;

		for(int j = 0; j < SEAT_COUNT; ++j) {
			if(seats[i * ROW_COUNT + j]) {
				--row_seats;
				++seats_sold;
				--seats_auditorium;
			}
		}

		printf("Seats left in Row %02d: %d\n", i + 1, row_seats);
	}

	printf(
		"\nTotal Seats Sold: %d\n"
		"Seats left in Auditorium: %d\n",
		seats_sold, seats_auditorium
	);
}

static void
print_total_sales(bool *seats, double *prices)
{
	double total_sales = 0.0;

	for(int i = 0; i < ROW_COUNT; ++i) {
		for(int j = 0; j < SEAT_COUNT; ++j) {
			if(seats[i * ROW_COUNT + j]) {
				total_sales += prices[i];
			}
		}
	}

	printf("Total Ticket Sales: %lf\n", total_sales);
}

static void
get_row_and_seat(int *prow, int *pseat)
{
	char buffer[256];
	bool ok = false;

	int row, seat;

	do {
		printf("Enter the row and seat numbers (ROW# SEAT#): ");
		fgets(buffer, 256, stdin);

		if(sscanf(buffer, "%u %u", &row, &seat) != 2) {
			printf("Invalid input!\n");
		}
		else if(row < 1 || row > ROW_COUNT || seat < 1 || seat > SEAT_COUNT) {
			printf("Invalid row and/or seat number!\n");
		}
		else {
			ok = true;
		}
	} while(!ok);

	*prow = row - 1;
	*pseat = seat - 1;
}

int
main(int argc, char *argv[])
{
	bool seats[ROW_COUNT * SEAT_COUNT];
	double prices[ROW_COUNT];
	bool done = false;

	printf(
		"Theater Seating Program\n"
		"Written by Feng Xie\n\n"
	);

	memset(seats, 0, ROW_COUNT * SEAT_COUNT * sizeof(bool));

	get_seat_prices(prices);
	print_seating_chart(seats);

	do {
		char buffer[256];

		printf(
			"\nEnter a command:\n"
			"  1. Buy Ticket\n"
			"  2. Check Total Ticket Sales\n"
			"  3. Check Seating\n"
			"  4. Quit Program\n"
			"Command: "
		);

		fgets(buffer, 256, stdin);

		if(buffer[1] != '\n') {
			printf("Invalid command!");
			continue;
		}

		switch(buffer[0]) {
			case '1': {
				int row = 0, seat = 0;

				get_row_and_seat(&row, &seat);

				seats[row * ROW_COUNT + seat] = true;

				print_seating_chart(seats);
				print_total_sales(seats, prices);
			} break;

			case '2': {
				print_total_sales(seats, prices);
			} break;

			case '3': {
				print_seat_availability(seats);
			} break;

			case '4': {
				done = true;
			} break;

			default: {
				printf("Invalid command!");
			} break;
		}
	} while(!done);

	return 0;
}

