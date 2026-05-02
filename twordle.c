//Brandon Lu
//Project 10
#define SIZE 5
#define mys "mystery.txt"
#include <stdio.h>
#include <stdbool.h>

void getword(FILE* ptr,int row, int col, char mysword[][col]);
int guessnum(int col, int row, char mysword[][col]);
void word(int col, int row, char mysword[][col]);
void redo(int col, int row, int guess, char mysword[][col]);
void checkcorrect (int col, int row, char mysword[][col]);
bool win(int col, int row, char mysword[][col]);
bool lose(int guess);
void display(int col, int row, char mysword[][col]);
int main(){
	FILE* ptr;
	int row = 7;
	int col = 6;
	int guess;
	bool wresult;
	bool lresult;
	char mysword[7][6];
	getword(ptr, row, col, mysword);
	guess = guessnum(col, row, mysword);
	lose(guess);
	return 0;
}
void getword(FILE* ptr,int row, int col, char mysword[][col]){
	ptr = fopen(mys, "r");
	
	if(ptr == NULL){
		printf("Error Opening File\n");
		return;
	}
	
	for(col = 0; col < SIZE; col++){
		fscanf(ptr, "%c", &mysword[0][col]);
	}
	mysword[0][5] = '\0';
	fclose(ptr);
	return;
}
int guessnum(int col, int row, char mysword[][col]){
	int guess;
	for (guess = 1; guess < 7; guess++){
		row = guess;
		printf("Guess %d! Enter your guess:", guess);
		word(col, row, mysword);
		printf("\n");
		redo(col, row, guess, mysword);
		checkcorrect(col, row, mysword);
		display(col, row, mysword);
		if(win(col, row, mysword) == true){
			return guess;
		}
	}
	return guess;

}
void word(int col, int row, char mysword[][col]){
	scanf("%s", mysword[row]);
	return;
}
void redo(int col, int row, int guess, char mysword[][col]){
	int mfive;
	for(mfive = 0; mysword[row][mfive] != '\0'; mfive++){
	}
	if(mfive != SIZE){
		printf("Please Enter a 5 letter word: ");
		scanf("%s", mysword[row]);
		redo(col, row, guess, mysword);
		return;
	}
	for (col = 0; col < SIZE; col++){
		if(mysword[row][col] < 'a' || mysword[row][col] > 'z'){
			printf("Please reenter in lowercase characters");
			scanf("%s", mysword[row]);
			col = -1;
		}
	}
	return;
}
void checkcorrect (int col, int row, char mysword[][col]){
	for (col = 0; col < SIZE; col++){
		if (mysword[row][col] == mysword[0][col]){
			mysword[row][col] -= 32;
		}
	}
	return;
}
bool win(int col, int row, char mysword[][col]){
	int same = 0;
	bool result = false;
	for(col = 0; col < SIZE; col++){
		if(mysword[row][col] == mysword[0][col] - 32){
			same++;
		}
	}
	if(same == SIZE){
		printf("You Win!\n");
		result = true;
	}
	return result;
}		
bool lose(int guess){
	bool result = false;
	if(guess == 7){
		printf("You Lose!\n");
		result = true;
	}
	return result;
}
void display(int col, int row, char mysword[][col]){
	int index;
	printf("===============================\n");
	printf("%s\n", mysword[row]);
	for(col = 0; col < SIZE; col++){
		int space = 0;
		for(index = 0; index < SIZE; index++){
			if((mysword[row][col] == mysword[0][index] || mysword[row][col] == mysword[0][index] - 32) && col != index){
			space++;
			}
		}
		if(space > 0){
			printf("^");
		}
		else{
			printf(" ");
		}
	}
	printf("\n");
	return;
}
	

	
	
