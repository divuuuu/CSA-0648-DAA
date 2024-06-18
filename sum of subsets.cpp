#include <stdio.h>
void printSubset(int subset[], int subsetSize) {
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void findSubsets(int set[], int subset[], int setSize, int subsetSize, int sum, int target, int startIndex) {
    if (sum == target) {
        printSubset(subset, subsetSize);
        return;
    }
    if (startIndex >= setSize || sum > target) {
        return;
    }
    subset[subsetSize] = set[startIndex];
    findSubsets(set, subset, setSize, subsetSize + 1, sum + set[startIndex], target, startIndex + 1);
    findSubsets(set, subset, setSize, subsetSize, sum, target, startIndex + 1);
}
int main() {
    int set[10],target,i,n;
    printf("enter no of elements:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&set[i]);
	}
	printf("enter target:");
	scanf("%d",&target);
    int subset[n];
    printf("Subsets of the given set that sum to %d are:\n", target);
    findSubsets(set, subset, n, 0, 0, target, 0);
    return 0;
}
