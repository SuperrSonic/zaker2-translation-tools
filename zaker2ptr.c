/* Copyright (c) 2023-2024 Diego A.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * COMPILE GUIDE
 *
 * APP BUILD
 * C:\MinGW\bin\gcc "C:\makai.c" -o "C:\makai.exe" icon.res
 *
 * ICON BUILD
 * C:\MinGW\bin\windres "C:\my.rc" -O coff -o "C:\my.res"
*/

// This stuff here is unused
typedef struct _PTRData
{
	uint32_t table[0x1400/4]; //all pointers, first relevant ptr at 0x14 AKA ptr 6
	//uint32_t padding;
	//u8 strings[0];
} PTRData;

PTRData * zaker_main_tbl = NULL;

uint32_t swap_uint32(uint32_t val)
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

static const char proj[] = "PROJECT ZAKR2";

const char name[] = "Diego A.";
const char atk[] = "CHAOS CONTROL";
const char quote1[] = "The time-space rift is expanding... There's no more time, I need to hurry.";
const char quote2[] = "Sounds good but you should know only the Power Rangers can control the Mega Voyager.";
const char quote3[] = "Step aside Mercury, it's not you I'm after!";

const char spell1[] = "Zaker";
const char spell2[] = "Rashield";
const char spell3[] = "Jikerdor";
const char spell4[] = "Bao Zakeruga";
const char spell5[] = "Zakeruga";
const char spell6[] = "Rauzaruk";
const char spell7[] = "Zaguruzemu";

const char rando0[] = "Sparkling Wide Pressure";
const char rando1[] = "Exodia the Forbidden One";
const char rando2[] = "VOLCAN 300";

const char end1[] = "You foolish man, I am a Jito-Ryo master. Allow me to reunite you with your ancestors.";
const char end2[] = "Don't even try unless you've learned the Amakakeru Ryu no Hirameki.";
const char end3[] = "Jump on panel number one, it will take you to panels two and three.";

int main (int argc, char *argv[])
{
  int i = 0;
  int x = 0;
  int fullLimit = 0;
  int halfLimit = 0;
  int halfLimit1 = 0; // for recording game string len
  int fullLimit1 = 0;
  bool lineBroke = false;
  //int checksum = 0;

#if 1
  //if(checksum != 0xf095) {
   //  printf("\n\n");
   //  printf("An error has been detected.\n");
   //  printf("You do not have enough power-from-within!\n");
   //  return 0;
  //}
#endif

  printf("\n\n");
  printf("~ Zatch Bell! Electric Arena 2 - Pointer Updater ~  by %s\n\n\n", name);
  
  FILE *f = NULL;

  if(argc > 1) {
    for(i = 1; i < argc; i++) {
			// Try to open the first argument as a file
			f = fopen(argv[i], "r+b"); //without b 0x0A values get 0x0D added
			if(f == NULL)
				printf("Failed to open file!\nAre you reading the right spell book?\n\n");
			else {
				// Get the total file size
				fseek(f, 0, SEEK_END);
				uint32_t total = ftell(f);
				fseek(f, 0, SEEK_SET);
			//	size_t res = fread(zaker_main_tbl, 1, 0x1400, f);
				
				uint32_t strings = 0;
				fread(&strings, 1, 4, f);
				
				printf("Opened file with size: 0x%X, first pointer at offset 0x%X.\n", total, strings);
				printf("Scanning file for strings...\n");
				
				uint32_t string_cnt = strings;
				
				// Go to the first used pointer
				int cnt = 0;
				int p = 0;
				//for(p = 0x14; p < 0x13EC; p+=4) {
				for(p = 0x14; p < (string_cnt - 0x14); p+=4) {
					fseek(f, p, SEEK_SET);       //seek to pointer
					fread(&strings, 1, 4, f);    //read pointer
					fseek(f, strings, SEEK_SET); //seek to string
					fread(&strings, 1, 4, f);    //read first byte
					if(strings != 0)             //if it's not null it's a string
						++cnt;
				}
				printf("Found %d strings!\n", cnt);
				// Original script should be 1270 strings
				// while EA2 features new strings
				
				printf("Updating pointers...\n");
				// Now loop to update the pointers
				bool isNulo = false;
				uint32_t ptrPos = 0x18;
				uint8_t val = 0;
				uint32_t strPos = 0;
				for(strPos = (string_cnt + 0x14); strPos < total; ++strPos) {
				//for(p = 0x1414; p < 0xC814; ++p) {
					fseek(f, strPos, SEEK_SET);      //seek to first used string
					fread(&val, 1, 1, f);            //read byte to see if it's the same string
					
					//printf("Value: 0x%X\n", val);
					//printf("PTR POSITION: 0x%X\n", ptrPos);
					
					if(ptrPos > (string_cnt - 4)) {
						// Due to the null bytes at the end it will always exceed
						//printf("Exceeded pointer table limit!\n");
						break;
					}
					
					//if(isNulo && val != 0) { //apparently the double zeros are pointed to
					if(isNulo) {
						fseek(f, ptrPos, SEEK_SET);
						fwrite(&strPos, 1, 4, f);
						isNulo = false;
						
						ptrPos += 4;
					//	printf("WrotePointer: 0x%X\n", val);
					}
					
					if(val == 0)
						isNulo = true;
				}
				printf("Finished!\n");
			}
      }

	//free(zaker_main_tbl);
	fclose(f);
  }
  else
  {
     printf("USAGE: zaker2ptr.exe script.bin\n");
     printf("It will automatically scan every string and update the corresponding pointer.\n");
  }

  printf("\n");

  return 0;
}
