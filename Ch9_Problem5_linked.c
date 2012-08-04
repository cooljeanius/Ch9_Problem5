/*
 *  Ch9_Problem5_linked.c
 *  Ch9_Problem5
 *
 *  Created by Eric Gallager on 8/4/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 *	This is meant to do the same thing as Ch9_Problem5_main.c, except it links against a separate library instead of building parts in.
 *	The main one is better, use that instead.
 *
 */

#include "libipv4address.h"

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
	printf("\n Continue doing this until you have entered all the addresses you want to enter. Once you are done, enter '0 0 0 0 none' to stop entering addresses. \n");
	while (number_of_zeroes != 4) {
		i++;
		printf("\n> "); // prompt
		IP[i] = scan_address(); // get input
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

