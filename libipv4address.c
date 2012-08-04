/*
 *  libipv4address.c
 *  Ch9_Problem5
 *
 *  Created by Eric Gallager on 8/4/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 */

#include "libipv4address.h"

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

// newline \n

