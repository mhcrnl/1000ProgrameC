// utilizare escape sequences

#include <stdio.h>

int main()
{

    printf("\aInvatam sa folosim \"Escape Sequences\"!\n");
    printf("Introduceti un numar:________\b\b\b\b\b\b\b\b");

    int nr;
    scanf ("%d", &nr);
    printf("\aAti introdus numarul %d \t", nr);

    return 0;
}

/*

\a	07	Alarm (Beep, Bell)
\b	08	Backspace
\f	0C	Formfeed
\n	0A	Newline (Line Feed); see notes below
\r	0D	Carriage Return
\t	09	Horizontal Tab
\v	0B	Vertical Tab
\\	5C	Backslash
\'	27	Single quotation mark
\"	22	Double quotation mark
\?	3F	Question mark


*/
