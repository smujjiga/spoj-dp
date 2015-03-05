/*
Author: Srikanth Mujjiga (smujjiga)
Date: 27.Feb.2015
Problem: 345. Mixtures http://www.spoj.com/problems/MIXTURES
Problem code: MIXTURES
Type: O(n^3) Matrix chain multiplication 
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

#define MOD(x) ((x)%100)

int Mixtures(int *input, int n) {
	int mix[110][110];
	int smoke[110][110];

	for (int i=0;i<n;i++) {
		mix[i][i] = input[i];
		smoke[i][i] = 0;
	}

	mix[0][1] = MOD(input[0]+input[1]);
	smoke[0][1] = input[0] * input[1];
	
	for (int i=2;i<n;i++) {
		//cout<<"\n";
		for (int j=i-1;j>=0;j--) {
			smoke[j][i] = INT_MAX;
			for (int k=j;k<i;k++) {
				int s = mix[j][k]*mix[k+1][i] + smoke[j][k] + smoke[k+1][i];
				int m = MOD(mix[j][k]+mix[k+1][i]);

				//printf("(%d,%d,%d) => (%d,%d) ",j,k,i,s,m);

				if (smoke[j][i] > s) {
						smoke[j][i] = s;
						mix[j][i] = m;
				}
			}
		}
	}

	return smoke[0][n-1];
}

int main_MIXTURES() {
	int n;
	int input[110];
	while(scanf("%d",&n) > 0) {
		for (int i=0;i<n;i++)
			scanf("%d",&input[i]);
		printf("%d\n",Mixtures(input,n));
	}
	return 0;
}

/*
Input:
2
18 19
3
40 60 20

Output:
342
2400
*/
