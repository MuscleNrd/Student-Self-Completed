/*
Notice:
=======

THIS PROGRAM IS FOR EDUCATIONAL PURPOSES *ONLY*!

* It has not been adequately tested.
* It has not had error handling code included.
* It has not been optimized.

It is NOT a "ready to use" program! Study it! Then code
up your own program.

Maximum Length of Any Word: 30 chars + end of string char

THIS PROGRAM IS FOR EDUCATIONAL PURPOSES *ONLY*!

Adak, Sept. 23, 2013.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define C 31           //length of each row in the data array
#define BOXSIZE 100000 //number of strings in the smallest data array

//function definitions
int loadData(FILE *fp, char data[BOXSIZE][C]);
void merge2into1(char data[BOXSIZE][C], int boxNum);
void printIt(char data[BOXSIZE][C], int rowsLoaded);
void quicksort(char data[BOXSIZE][C], int lo, int hi);
void printBoxes(char data[BOXSIZE][C], int rowsLoaded);


/* This program is for educational purposes *ONLY*! */
int main(void) {
	int rowsLoaded, boxNum = 0;
	static char data[BOXSIZE][C]; //static arrays get memory
	FILE *fp;                     //from the much larger heap
	clock_t start, stop;
	printf("For those thinking of using KWay merging, the maximum number\n\
   \b\b\bof files that you can have open simultaneously, is: %d\n\n", FOPEN_MAX);

	start = clock();

	//open the raw data file 
	fp = fopen("in.txt", "r");
	if (!fp) {
		printf("Error! data file failed to open\n");
		return 1;
	}

	//start loading, sorting and writing out the box files
	printf(" Number of sorted box files created: %6d", boxNum);
	do {

		rowsLoaded = loadData(fp, data);

		quicksort(data, 0, rowsLoaded - 1);

		printBoxes(data, rowsLoaded);

		if (rowsLoaded>0)
			++boxNum;

		printf("\b\b\b\b\b\b%6d", boxNum);
		fflush(stdout);

	} while (rowsLoaded == BOXSIZE);
	printf("\n\n");
	fclose(fp);

	//box files are now all sorted and written out

	//merge them all into one final file
	merge2into1(data, boxNum);

	stop = clock();
	printf("Elapsed time: %f\n", (float)(stop - start) / CLOCKS_PER_SEC);
	return 0;
}
void merge2into1(char data[BOXSIZE][C], int boxNum) {
	FILE *fp1, *fp2, *fpOut;

	int tier = 0, go1 = 1, go2 = 1, orphan = 0;
	int files[1000] = { 0 };
	unsigned long int fileNum = 0, lowFileNum = 0;

	char filename1[25], filename2[25], oldFilename[25], s1[C], s2[C];

	files[0] = boxNum;
	do {

		do {
			//check your compiler, Pelles C has a limit of 33 chars
			//ultoa is not standard, but frequently included in compilers
			_ultoa(lowFileNum, filename1, 10);
			_ultoa(lowFileNum + 1, filename2, 10);
			strcat(filename1, ".dat");
			strcat(filename2, ".dat");

			fp1 = fopen(filename1, "r");
			fp2 = fopen(filename2, "r");
			fpOut = fopen("temp.dat", "w");

			if (!fp1) {
				printf("Error! Unable to open fp1 files for merging\n");
				printf("filename1:%s\n", filename1);
				exit(1);
			}
			//!fp2 happens regularly, when there is only 1 file left unmerged
			//at this merge level. This handles the orphan file      
			if (!fp2) {
				orphan = 1;
				strcpy(filename2, oldFilename);

				fp2 = fopen(filename2, "r"); //merge orphan file with oldFilename

				if (!fp2) { //still an error?
					printf("Error! Unable to open fp2 file for merging\n");
					exit(1);
				}
			}
			if (!fpOut) {
				printf("Error! Unable to open temp.dat, to write merge data\n");
				exit(1);
			}

			go1 = fscanf(fp1, "%s", s1);
			go2 = fscanf(fp2, "%s", s2);

			//this is the small main merge loop - fast!
			while (go1>0 && go2>0) {
				if ((strcmp(s1, s2))>0) {
					fprintf(fpOut, "%s\n", s2);
					go2 = fscanf(fp2, "%s", s2);
				}
				else {
					fprintf(fpOut, "%s\n", s1);
					go1 = fscanf(fp1, "%s", s1);
				}
			}

			//handle run outs of data, in either file
			if (go1>0 && go2<1) {
				while (go1>0) {
					fprintf(fpOut, "%s\n", s1);
					go1 = fscanf(fp1, "%s", s1);
				}
			}
			else if (go2>0 && go1<1) {
				while (go2>0) {
					fprintf(fpOut, "%s\n", s2);
					go2 = fscanf(fp2, "%s", s2);
				}
			}

			//both input files have been read. Close all three files.
			fclose(fp1);
			fclose(fp2);
			fclose(fpOut);

			remove(filename1); remove(filename2);
			//create file output name
			if (orphan) {
				rename("temp.dat", filename2);
			}
			else {
				_ultoa(fileNum, filename1, 10);
				strcat(filename1, ".dat");
				rename("temp.dat", filename1);
				strcpy(oldFilename, filename1);
			}

			++fileNum;
			lowFileNum += 2; //number of files merged so far, on lower level
							 //number of files merged so far, on current merge level
		} while (lowFileNum<files[tier]);

		if (orphan) {
			--fileNum;
			orphan = 0;
		}
		files[++tier] = fileNum;
		fileNum = 0;
		lowFileNum = 0;


	} while (files[tier]>1);
}
void printIt(char data[BOXSIZE][C], int rowsLoaded) { //print rows of data
	int i;
	for (i = 0; i<rowsLoaded; i++)
		printf("%s\n", data[i]);

	printf("\n\n");
}
//outputs the box files: 0.dat, 1.dat, etc.
void printBoxes(char data[BOXSIZE][C], int rowsLoaded) {
	int i;
	FILE *fpOut;
	static unsigned long int n = 0;
	char filename[25];

	_ultoa(n, filename, 10);
	strcat(filename, ".dat");

	fpOut = fopen(filename, "w");
	if (!fpOut) {
		printf("Error! data file failed to open\n");
		exit(1);
	}

	for (i = 0; i<rowsLoaded; i++) {
		fprintf(fpOut, "%s\n", data[i]);
	}
	fclose(fpOut);
	++n;
}

//quicksort Note: parameter hi, on the first call, should 
//be the highest valid index, not the size of the array
void quicksort(char data[BOXSIZE][C], int lo, int hi) {
	int i = lo, j = hi;
	char pivot[C], temp[C];
	strcpy(pivot, data[(lo + hi) / 2]);

	if (lo <= hi) return;

	// Partition the array 
	do {
		while ((strcmp(data[i], pivot))<0)i++;
		while ((strcmp(data[j], pivot))>0)j--;

		if (i <= j) {
			strcpy(temp, data[i]);
			strcpy(data[i], data[j]);
			strcpy(data[j], temp);
			i++;
			j--;
		}
	} while (i<j);

	//handles the smaller partition, first
	if (lo < j) quicksort(data, lo, j);
	if (i < hi) quicksort(data, i, hi);

}
//loads up the words, into the data  array
int loadData(FILE *fp, char data[BOXSIZE][C]) {
	int i = 0, n = 1;

	while (i<BOXSIZE && n>0) {
		n = fscanf(fp, "%s", data[i]);
		++i;
	}
	if (i<BOXSIZE)
		data[--i][0] = '\0';
	return i;
}

