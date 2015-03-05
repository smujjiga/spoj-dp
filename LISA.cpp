/*
Author: Srikanth Mujjiga (smujjiga)
Date: 27.Feb.2015
Problem: 364. Pocket Money http://www.spoj.com/problems/EDIST/
Problem code: LISA
Type: O(n^3) Matrix chain multiplication 
*/

#include <stdio.h>
#include <string.h>
#include <climits>

namespace LISA {
int min(int i, int j) {
	return i<j?i:j;
}

int max(int i,int j) {
	return i>j?i:j;
}
}

unsigned int calc(unsigned int i, unsigned int j, char c) {
	if (c=='+')
		return i+j;
	else
		return i*j;
}


void find(char *input, int n, unsigned int &a, unsigned int &b) {
	unsigned int maxsol[110][110], minsol[110][110];

	for (int i=0;i<n;i+=2) 
		maxsol[i][i] = minsol[i][i] = input[i]-'0';

	for (int i=2;i<n;i+=2) {
		for (int j=(i-2);j>=0;j-=2) {
			maxsol[j][i] = INT_MIN;
			minsol[j][i] = INT_MAX;

			for (int k=(i-2);k>=j;k-=2) {
				maxsol[j][i] = LISA::max(maxsol[j][i], calc(maxsol[j][k],maxsol[k+2][i],input[k+1]));
				minsol[j][i] = LISA::min(minsol[j][i], calc(minsol[j][k],minsol[k+2][i],input[k+1]));
			}
		}
	}

	a = maxsol[0][n-1];
	b = minsol[0][n-1];

}

int main_LISA () {
	int t;
	char input[110];
	unsigned int maxsol,minsol;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",&input);
		find(input,strlen(input),maxsol,minsol);
		printf("%d %d\n", maxsol, minsol);
	}
	return 0;
}
