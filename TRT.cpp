/*
Author: Srikanth Mujjiga (smujjiga)
Date: 21.Feb.2015
Problem: 740. Treats for the Cows http://www.spoj.com/problems/TRT/
Problem code: TRT
Type: O(n^2) memories dp
*/

#include <stdio.h>

int max(int i,int j) {
	return i>j?i:j;
}

int mem[2001][2001];

int solve(int *input, int h, int t, int day) {
	if (h>t) return 0;

	if (mem[h][t] != -1) return mem[h][t];
	else {
		return mem[h][t] = max((day*input[h])+solve(input, h+1,t,day+1),(day*input[t])+solve(input,h,t-1,day+1));
	}
}

int main() {
	int n,input[2010];
	scanf("%d",&n);

	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			mem[i][j] = -1;

	for(int i=0;i<n;i++)
		scanf("%d",&input[i]);

	printf("%d",solve(input,0,n-1,1));
	return 0;
}

/*
Example

Input:
5
1
3
1
5
2

Output:
43

*/
