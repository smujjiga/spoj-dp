/*
Author: Srikanth Mujjiga (smujjiga)
Date: 24.Mar.2015
Problem: 39. Piggy-Bank http://www.spoj.com/problems/PIGBANK/
Problem code: PIGBANK
Type: O(n^2) coin change
*/

#include <stdio.h>
#include <climits>

namespace PIGBANK {
int min(int i,int j) {
	return i<j?i:j;
}
}

	int *sol = new int[10010];
		int v[510],w[510];

int main_PIGBANK() {
	int t,f,e,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&e,&f,&n);
		for (int i=0;i<n;i++)
			scanf("%d%d",&v[i],&w[i]);
		
		sol[0] = 0;
		for (int i=1;i<=(f-e);i++) {
			sol[i] = INT_MAX;
			for (int j=0;j<n;j++) {
				if (w[j] <= i && sol[i-w[j]] != INT_MAX) 
					sol[i] = PIGBANK::min(sol[i], sol[i-w[j]]+v[j]);
			}
		}

		if (sol[f-e] == INT_MAX)
			printf("This is impossible.\n");
		else 
			printf("The minimum amount of money in the piggy-bank is %d.\n",sol[f-e]);
	}
	return 0;
}

/*
Sample Input:

3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4

Sample output:

The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.
*/
