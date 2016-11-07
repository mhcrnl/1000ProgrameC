#include <stdio.h>
#include <stdio.h>
int main(void) {
    int i = 3, j = i - 2;

    switch(i + 2) {
    case 1:
        j++;
    case 2:
        j++;
    default:
        j = 0;
    case 0:
        j++;
        break;
    }
    printf("%d",j);
    return 0;
}// Output: 1
