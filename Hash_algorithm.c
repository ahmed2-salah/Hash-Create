
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void Ahmed_alogrithm(uint8_t* message, size_t message_len, uint8_t* hash)
{
	int sum=0;
	int average=0;
	for(int j=0;j<256;j++)
	{
		sum+=message[j];
	}
	average=average+(sum/256);
	hash[0]=average+2;

	hash[0]=hash[0]+message[255]+message[46]+message[66]+2;
	hash[1]= hash[0]+(message[11]+1)+(message[1]-message[45])*2+(17+message[125])+(message[250]);
	hash[2]= hash[0]+hash[1]+hash[1]+(message[58]*3)+((message[11]+1)+(message[1]-message[45])*2+(17+message[125])+(message[250]));
	hash[3]= hash[0]+hash[2]+(message[31]+1)*(6+message[17])+hash[2];
	hash[4]= hash[0]+hash[3]+message[17]+(hash[1]+hash[2]-hash[3]);
	hash[5]= hash[0]+hash[4]/2+message[64]+13+(message[101]+5);
	hash[6]= hash[0]+hash[5]*2+(message[64]+message[77]+message[25]+hash[3]+message[240]+message[222]);
	hash[7]= hash[0]+hash[6]+(message[88]+127+hash[6])*2;
	hash[8]= hash[0]+hash[7]+message[66]+hash[1];
	hash[9]= hash[0]+hash[8]+message[22];
	hash[10]=hash[0]+hash[9]+message[19];
	hash[11]=hash[0]+hash[10]+message[91];
	hash[12]=hash[0]+hash[11]+message[100];
	hash[13]=hash[0]+hash[12]+message[120];
	hash[14]=hash[0]+hash[13]+message[150];
	hash[15]=hash[0]+hash[5]+hash[14]+message[111];



}
int main() {
	// Define the array
	uint8_t array[256]={  0x15,0x11 ,0x10 ,0x77 ,0x12 ,0x02,0x20 ,0x09 ,0x07 ,0x00,0x55,0x41 ,0x16 ,0x64 ,0x25 ,0x47
			,0x14 ,0x85 ,0x33 ,0x77 ,0x77 ,0x13 ,0x44 ,0x45 ,0x13 ,0x54 ,0x55 ,0x55 ,0x54 ,0x55 ,0x14 ,0x22
			,0x18 ,0x82 ,0x22 ,0x64 ,0x16 ,0x56 ,0x54 ,0x64 ,0x87 ,0x13 ,0x54 ,0x13 ,0x13 ,0x11 ,0x31 ,0x55
			,0x17 ,0x58 ,0x11 ,0x44 ,0x15 ,0x61 ,0x11 ,0x11 ,0x37 ,0x55 ,0x46 ,0x55 ,0x00 ,0x55 ,0x22 ,0x87
			,0x98 ,0x28 ,0x93 ,0x66 ,0x39 ,0x51 ,0x00 ,0x47 ,0x75 ,0x44 ,0x97 ,0x55 ,0x14 ,0x69 ,0x77 ,0x71
			,0x64 ,0x93 ,0x39 ,0x77 ,0x97 ,0x17 ,0x11 ,0x31 ,0x64 ,0x78 ,0x31 ,0x00 ,0x47 ,0x47 ,0x35 ,0x63
			,0x44 ,0x96 ,0x63 ,0x13 ,0x93 ,0x98 ,0x99 ,0x11 ,0x13 ,0x13 ,0x97 ,0x54 ,0x37 ,0x15 ,0x14 ,0x15
			,0x57 ,0x39 ,0x36 ,0x14 ,0x17 ,0x44 ,0x88 ,0x45 ,0x87 ,0x17 ,0x19 ,0x13 ,0x19 ,0x31 ,0x77 ,0x98
			,0x31 ,0x69 ,0x28 ,0x15 ,0x22 ,0x12 ,0x77 ,0x52 ,0x13 ,0x97 ,0x87 ,0x87 ,0x73 ,0x87 ,0x98 ,0x14
			,0x17 ,0x64 ,0x82 ,0x18 ,0x60 ,0x33 ,0x66 ,0x28 ,0x77 ,0x22 ,0x55 ,0x13 ,0x73 ,0x47 ,0x87 ,0x64
			,0x54 ,0x45 ,0x52 ,0x20 ,0x44 ,0x11 ,0x55 ,0x78 ,0x44 ,0x44 ,0x11 ,0x97 ,0x91 ,0x44 ,0x87 ,0x25
			,0x45 ,0x46 ,0x25 ,0x50 ,0x55 ,0x08 ,0x44 ,0x95 ,0x66 ,0x65 ,0x55 ,0x10 ,0x44 ,0x64 ,0x77 ,0x98
			,0x17 ,0x97 ,0x47 ,0x19 ,0x79 ,0x07 ,0x33 ,0x13 ,0x00 ,0x45 ,0x12 ,0x20 ,0x00 ,0x45 ,0x88 ,0x17
			,0x71 ,0x79 ,0x74 ,0x17 ,0x97 ,0x09 ,0x22 ,0x00 ,0x77 ,0x12 ,0x54 ,0x02 ,0x09 ,0x65 ,0x00 ,0x31
			,0x24 ,0x89 ,0x41 ,0x64 ,0x10 ,0x02 ,0x11 ,0x77 ,0x88 ,0x21 ,0x55 ,0x09 ,0x90 ,0x00 ,0x00 ,0x54
			,0x00 ,0x98 ,0x14 ,0x66 ,0x30 ,0x01 ,0x00 ,0x99 ,0x33 ,0x44 ,0x45 ,0x87 ,0x77 ,0x77 ,0x44 ,0x11
	};

	printf("Array before calculate hash..\n");
	for (int i = 0; i < 256; i++) {
		printf("%02X ", array[i]);  // %02X ensures two-digit hexadecimal representation
		if ((i + 1) % 16 == 0) {
			printf("\n");
			// Start a new line after every 16 elements
		}
	}
	printf("\n");
	printf("\n");
	/* Print the array*/
	// Create the hash
	uint8_t hash[16];
	Ahmed_alogrithm(array, 256, hash);



	// Print the hash
	printf("Hash: ");
	for (int i = 0; i < 16; i++) {
		printf("%02X ", hash[i]);
	}
	printf("\n");

	return 0;
}



