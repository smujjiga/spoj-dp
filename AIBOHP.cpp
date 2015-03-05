/*
Author: Srikanth Mujjiga (smujjiga)
Date: 25.Feb.2015
Problem: 1021. Aibohphobia http://www.spoj.com/problems/AIBOHP/
Problem code: AIBOHP
Type: O(n^2) memoriesed DP
*/

#include <stdio.h>

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline int putchar_unlocked(char c) { return putchar(c); }
#endif


int min(int i,int j) {
	return i<j?i:j;
}

int mem[6110][6110];

int shortPalindrome(char *str, int i, int j) {
	if (i>j) return 0;
	if (mem[i][j] != -1) return mem[i][j];
	
	if (str[i] == str[j])
		return shortPalindrome(str,i+1,j-1);
	else {
		return (mem[i][j] = 1 + min(shortPalindrome(str,i+1,j), shortPalindrome(str,i,j-1)));
	}

}



int main_AIBOHP() {
	int t;
	scanf("%d",&t);

	char str[6110];
	char c;
	while(t--) {
		int n=0;
		c = 0;
		while (c < 33)
			c = getchar_unlocked();

		while(c != EOF && c != '\n') {
			str[n++] =  c;
			c = getchar_unlocked();
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			mem[i][j] = -1;

		printf("%d\n",shortPalindrome(str,0,n-1));
	}
	return 0;
}
