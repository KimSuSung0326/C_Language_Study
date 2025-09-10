#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* wordList[] = { "apple", "elephant", "tiger", "rabbit", "tree", "egg", "grape", "eagle", "rose", "ear" };
char userword[100];
char* inputUserword;
// 문자열 총 갯수
int count = sizeof(wordList) / sizeof(wordList[0]);

// 단어의 마지막 글자를 가져오는 함수
char getLastChar(char * word)
{
	int len = strlen(word);
	char lastChar = word[len - 1];
	//printf("lastchar : %c\n", lastChar);
	return lastChar;
}
// 사용자가 단어를 입력하기 위한 포인터
char* putuserWord() {
	printf("단어를 입력하세요: ");
	scanf_s("%s", userword, sizeof(userword));
	return userword;   // 입력 문자 반환
}

//문자열 리스트에서 마지막 문자와 같은거 찾는 함수
char* findAiWord()
{
	char lastchar = getLastChar(inputUserword); // 입력 단어의 마지막 글자

	for (int i = 0; i < count; i++) {   // <= 말고 < 사용
		if (wordList[i][0] == lastchar) { // 리스트 단어의 첫 글자와 비교
			return wordList[i];          // 맞으면 단어 반환
		}
	}
	return NULL; // 못 찾으면 NULL
}

// 마지막 글자 기반으로 5글자 단어 만들기
void makeWordFromLastChar(char lastChar, char* outputWord) {
	outputWord[0] = lastChar; // 첫 글자는 lastChar

	// 나머지 4글자는 랜덤 소문자 생성
	for (int i = 1; i < 5; i++) {
		outputWord[i] = 'a' + rand() % 26;
	}
	outputWord[5] = '\0'; // 문자열 종료

	return outputWord;
}

int main() 
{
	char AIWord[6];
	char AIWord2[6];
	while (1) {
		// 사용자가 단어 입력
		inputUserword = putuserWord();
		//printf("%s\n", inputUserword);
		// 단어의 마지막 글자를 찾기위한 함수
		//getLastChar(inputUserword);
		//char* AIword = findAiWord();
		//printf("AI:%s\n", AIword
		char lastchar = getLastChar(inputUserword);
	    makeWordFromLastChar(lastchar, AIWord);
		printf("AI가 만든 단어: %s\n", AIWord);
	}

}