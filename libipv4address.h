/*
 *  libipv4address.h
 *  Ch9_Problem5
 *
 *  Created by Eric Gallager on 8/4/12.
 *  Copyright 2012 George Washington University. All rights reserved.
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
extern void print_address(IPv4_Address_t IP); // prototype: This function is needed so the IPv4_Address_t struct will have a way to be displayed

/*
 * Gets an IP Address from user input
 */
extern IPv4_Address_t scan_address(void); // prototype: This function is needed to have a way to put data into the IPv4_Address_t struct

/* 
 * Tests for same location
 * Return Values:
 *	0 => false
 *	1 => true
 */
extern int local_address(IPv4_Address_t IP1, IPv4_Address_t IP2); // prototype: takes 2 addresses and compares them

// newline \n

