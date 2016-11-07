/**
	Author:		Mihai Cornel	Romania			    mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                Fedora 23	    Code::Blocks 16.01	gcc 5.3.1
	Copyright:	@2016
	Problem:
*/
#include <stdio.h>

int main(void) {
    int i = 3, j = i - 2;
    switch(i - 2) {
    case 1:
        j++;
    case 2:
        j++;
    case 0:
        j++;
        break;
    default:
        j = 0;
    }
    printf("%d",j);
    return 0;
} //OUT: 4
