/*
 * Eric Gallager
 *
 * Assignment:
 * 
 * For this assignment You are to do Problem 5 in Chapter 9 on page 446.
 * The assignment is due on May 11th 2012
 * : Sample data 
 *	111.22.3.44    platte 
 *	555.66.7.88    wabash 
 *	111.22.5.66    green
 *	0.0.0.0     none
 * –;     struct address_t 
 * –;     scan_address()
 * –;     print_address()
 * –;     local_address() – return 1/0
 * 
 * *; Output
 * Machine platte and green are on the same local network.
 * 
 * ---
 *
 * Ch. 9 Problem 5 (C Program Design for Engineers, by Jeri R. Hanly & Elliot B. Koffman, p. 446):
 *
 * Numeric (IPv4) addresses for computers on the international network Internet are composed of four parts, separated by periods, of the form:
 *
 *	xx.yy.zz.mm
 * 
 * where xx, yy, zz, and mm are positive integers. Locally, computers are usually known by a nickname as well.
 * You are designing a program to process a list of Internet addresses, identifying all pairs of computers from the same locality.
 * Create a structure type called address_t with components for the four integers of an Internet address and a fifth component in which to store an associated nickname of 10 characters.
 * Your program should read a list of up to 100 addresses and nicknames terminated by a sentinel address of all zeros and a sentinel nickname.
 *
 * Sample Data: <see above>
 *
 * The program should display a list of messages identifying each pair of computers from the same locality -- that is, each pair of computers with matching values in the first two components of the address.
 * In the messages, the computers should be identified by their nicknames.
 *
 * Example Message: <see above>
 * 
 * Follow the messages by a display of the full list of addresses and nicknames. 
 * Include in your program a scan_address() function, a print_address() function, and a local_address() function.
 * Function local_address() should take two address structures as input parameters and return 1 (for true) if the addresses are on the same local network, and 0 (for false) otherwise.
 * 
 * Algorithm:
 * 
 * 1. Make a struct
 * 2. Make functions using the struct
 * 3. Get info to put into struct
 * 4. Compare parts of struct to test for equality
 * 5. Print structs that match
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_MAX_LENGTH 100

typedef struct {
	int first_digits; // xx.__.__.__
	int second_digits; // __.xx.__.__
	int third_digits; // __.__.xx.__
	int fourth_digits; // __.__.__.xx
	char nickname[STRING_MAX_LENGTH];
} IPv4_Address_t;

/*
 * Displays an IP Address
 */
void print_address(IPv4_Address_t IP); // prototype
void 
print_address(IPv4_Address_t IP) { // This function is needed so the IPv4_Address_t struct will have a way to be displayed
	printf("%d.%d.%d.%d ", IP.first_digits, IP.second_digits, IP.third_digits, IP.fourth_digits); // displays address in the __.__.__.__ format
	printf(" %s \n", IP.nickname); // Add nickname afterwards
}

/*
 * Gets an IP Address from user input
 */
IPv4_Address_t scan_address(void); // prototype
IPv4_Address_t 
scan_address(void) { // This function is needed to have a way to put data into the IPv4_Address_t struct
	IPv4_Address_t IP;
	scanf("%d%d%d%d%s", &IP.first_digits, &IP.second_digits, &IP.third_digits, &IP.fourth_digits, IP.nickname);
	return (IP);
}

/* 
 * Tests for same location
 * Return Values:
 *	0 => false
 *	1 => true
 */
int local_address(IPv4_Address_t IP1, IPv4_Address_t IP2); // prototype
int
local_address(IPv4_Address_t IP1, IPv4_Address_t IP2) { // takes 2 addresses and compares them
	int ret_value = 0;
	int first_first_digits = IP1.first_digits; // dirty hack to try to solve error message
	int first_second_digits = IP1.second_digits; // dirty hack to try to solve error message
	int second_first_digits = IP2.first_digits; // dirty hack to try to solve error message
	int second_second_digits = IP2.second_digits; // dirty hack to try to solve error message
	if ((first_first_digits == second_first_digits) && (first_second_digits == second_second_digits)) { // == returns 0 for false and 1 for true
		ret_value = 1; 
	} else {
		ret_value = 0;
	}
	return ret_value;
}
	
/*
 * Main function
 */
int main (int argc, const char * argv[]) {
	IPv4_Address_t IP[STRING_MAX_LENGTH]; // declare variable to use new struct
	int i = 0; // initialize loop-counter
	int number_of_zeroes = 0; // used as a flag for a while-loop
    printf("\n Message for security and/or debugging: \n This program's path is %s and it is running with %i argument(s). \n", argv[0], argc); // Statement for debugging
	printf("\n Enter the 4 parts of an IP address, separated by spaces instead of periods, and then enter a nickname for it> "); // prompt
	IP[i] = scan_address(); // get input
	// printf("\n IP[%i] = ", i); // Statement for debugging
	// print_address(IP[i]); // Statement for debugging
	printf("\n Continue doing this until you have entered all the addresses you want to enter. Once you are done, enter '0 0 0 0 none' to stop entering addresses. \n");
	while (number_of_zeroes != 4) {
		i++;
		printf("\n> "); // prompt
		IP[i] = scan_address(); // get input
		// printf("\n IP[%i] = ", i); // Statement for debugging
		// print_address(IP[i]); // Statement for debugging
		if (IP[i].first_digits == 0) {
			number_of_zeroes++;
		}
		if (IP[i].second_digits == 0) {
			number_of_zeroes++;
		}
		if (IP[i].third_digits == 0) {
			number_of_zeroes++;
		}
		if (IP[i].fourth_digits == 0) {
			number_of_zeroes++;
		}
		// printf("\n number_of_zeroes = %i \n", number_of_zeroes); // Statement for debugging
	}
	int j = 0; // initialize a second loop-counter
	for (j = 0; j <= i; j++) { // i is what the previous loop got up to, leave it as a reference point for where this one should stop
		printf("\n IP[%i] = ", j);
		print_address(IP[j]);
	}
	j = 0; // reset
	int k = 0; // initialize a third loop-counter
	int equality[i][i]; // output array
	int match_found = 0; // truth-flag
	for (j = 0; j <= i; j++) {
		for (k = 0; k <=i; k++) {
			if (equality[k][j] != 1) { // tells it to only test if the associative pair is not also a match, to prevent duplicates
				equality[j][k] = local_address(IP[j], IP[k]);
			}
			if ((equality[j][k] == 1) && (IP[j].nickname != "none") && (IP[k].nickname != "none") && (IP[j].nickname != IP[k].nickname)) { // test for truth of equality function (second and third conditions are to make sure the terminating null address is ignored, fourth condition is to make sure they aren't testing against themselves)
				printf("\n Machines %s and %s are on the same local network. \n", IP[j].nickname, IP[k].nickname); // print equal address nicknames if true
				match_found++;
			}
		}
	}
	printf("\n %i match(es) found. \n", match_found); // so something prints even if no matches are found
    return 0;
}

// newline \n

