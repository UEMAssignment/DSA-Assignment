#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks < 1)
    {
        printf("Number of disks should be greater than or equal to 1.\n");
        return 1; // Exit with an error code
    }

    // Function call to solve Tower of Hanoi
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}
