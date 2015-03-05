/*
Author: Srikanth Mujjiga (smujjiga)
Date: 25.Feb.2015
Problem: 6219. EDIST http://www.spoj.com/problems/EDIST/
Problem code: EDIST
Type: O(n^2) Basic DP
*/

#include <stdio.h>
#include <string.h>
#include <climits>

namespace  EDISTns {
	int min(int i, int j) {
		return i<j?i:j;
	}
}

int sol[2010][2010];
int EDIST(char *A, int n, char *B, int m) {
	// sol[n][m]

	for (int i=0;i<=m;i++)
		sol[0][i] = i;

	for (int i=0;i<=n;i++)
		sol[i][0] = i;

	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			sol[i][j] = INT_MAX;

			// Replace
			sol[i][j] = EDISTns::min(sol[i][j], sol[i-1][j-1]+ (A[i-1] == B[j-1]?0:1));
			
			// Insert
			sol[i][j] = EDISTns::min(sol[i][j], sol[i][j-1]+1);

			// Delete
			sol[i][j] = EDISTns::min(sol[i][j], sol[i-1][j]+1);	
		}
	}

	return sol[n][m];
}


int main_EDIST() {
	int t;
	scanf("%d",&t);
	char *A = new char[2010];
	char *B = new char[2010];
	while (t--) {
		scanf("%s%s",A,B);
		printf("%d\n",EDIST(A,strlen(A),B,strlen(B)));

	}
	return 0;
}


/*
Input:

1
FOOD
MONEY 

Output:

4
*/