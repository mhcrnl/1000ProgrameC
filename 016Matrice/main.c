// Jonathan Chin
// Rotates a 2D array from file. This only works if the array is a square matrix. There will be checks to ensure this.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **generateRandom();
int  **readFile(int **array);
void displayArray(int **array);
int validateInput();
int **rotateLeft(int **array);
int **rotateRight(int **array);
void controlArray(int **array);

//globals used to keep track of size of array
int row=3;
int col=3;

int main(){

    int **array=NULL;

    int response;

    int dimensionResponse;
    printf("Welcome to Rotate Array!\n");

    while(1){
        printf("What would you like to do?\n");
        printf("1.Read and display 2D array from file, display and rotate it.\n");
        printf("2. Specify dimensions and generate random 2D array to display and rotate it.\n");
        printf("3. Quit\n");
        //validates input to prevent crashing when a char or string is entered
        response = validateInput();

        switch(response){
            case 1:
                array=readFile(array);
                displayArray(array);
                controlArray(array);

                break;
            case 2:
                printf("Speicify the row and column dimensions of your 2D array.\n");
                dimensionResponse = validateInput();
                array = generateRandom(dimensionResponse);
                displayArray(array);
                controlArray(array);

                break;
            case 3:
                printf("Goodbye!");
                return 0;
            default:
                printf("Please enter a valid number.\n");
                break;

        }

    }

    return 0;
}

//reads the array.txt file for the array data
int **readFile(int **array){

    FILE *ifp = fopen("array.txt", "r");
    int i;
    int j;
    fscanf(ifp, "%d %d", &row, &col);
    array = malloc(row * sizeof(int));
    for(i=0; i<row; i++){
        array[i] = malloc(col * sizeof(int));
    }
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            fscanf(ifp, "%d", &array[i][j]);

        }

    }
    fclose(ifp);
    return array;


}

//powerful function to validate input
int validateInput(){
    char bet[10];
    int temp;
    int value;
    char ignore;

    fgets(bet, 8, stdin);
    temp = sscanf(bet, "%d %c", &value, &ignore);
    if(temp==1){
        return value;
    }
    else{
        return -1;
    }
}

//displays the 2D array
void displayArray(int **array){

    int i;
    int j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

//rotates array left by rotating each individual array index one at a time.
//This is more efficient space wise then making a new array.
int **rotateLeft(int **array){

    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;

    int xStart1=0;
    int yStart1=0;
    int xStart2=0;
    int yStart2=col-1;
    int xStart3=row-1;
    int yStart3=col-1;
    int xStart4=row-1;
    int yStart4=0;

    //how many layers of sides until the center is reached
    int layers;
    //temp storage
    int temp;
    int temp2;


    for(layers=0; layers<(row/2); layers++){

        for(x1=xStart1, y1=yStart1, x2=xStart2, y2=yStart2, x3=xStart3, y3=yStart3, x4=xStart4, y4=yStart4; x1<row-1; x1++, y4++, x3--, y2--){
            //swapping four corners first
            temp=array[x4][y4];
            array[x4][y4]=array[x1][y1];
            temp2 = array[x3][y3];
            array[x3][y3]=temp;
            array[x1][y1]=array[x2][y2];
            array[x2][y2]=temp2;

        }
        xStart1++;
        yStart1++;
        xStart2++;
        yStart2--;
        xStart3--;
        yStart3--;
        xStart4--;
        yStart4++;
    }

    return array;
}

//rotates array right
int **rotateRight(int **array){

    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;

    int xStart1=0;
    int yStart1=0;
    int xStart2=0;
    int yStart2=col-1;
    int xStart3=row-1;
    int yStart3=col-1;
    int xStart4=row-1;
    int yStart4=0;

    //how many layers of sides until the center is reached
    int layers;
    //temp storage
    int temp;
    int temp2;


    for(layers=0; layers<(row/2); layers++){

        for(x1=xStart1, y1=yStart1, x2=xStart2, y2=yStart2, x3=xStart3, y3=yStart3, x4=xStart4, y4=yStart4; y1<col-1; y1++, x2++, y3--, x4--){
            //swapping four corners first
            temp=array[x2][y2];
            array[x2][y2]=array[x1][y1];
            temp2 = array[x3][y3];
            array[x3][y3]=temp;
            array[x1][y1]=array[x4][y4];
            array[x4][y4]=temp2;

        }
        xStart1++;
        yStart1++;
        xStart2++;
        yStart2--;
        xStart3--;
        yStart3--;
        xStart4--;
        yStart4++;
    }

    return array;
}

//uses the dimensions specified by the user to generate a random array of 0-9
int **generateRandom(int dimension){
    srand(time(NULL));
    int i;
    int j;
    int **array;
    row = dimension;
    col = dimension;
    array = malloc(dimension * sizeof(int));

    for(i=0; i<dimension; i++){
        array[i] = malloc(dimension * sizeof(int));
    }
    for(i=0; i<dimension; i++){
        for(j=0; j<dimension; j++){
            int r = rand()%10;
            array[i][j]= r;

        }
    }
    return array;


}

//allow users to control the array by rotating it left or right
void controlArray(int **array){

    int exit = 0;
    char secondResponse;

    printf("Type 'l' or 'r' to rotate left or right or type 'q' to quit.");
    while(exit!=1){
        scanf("%c", &secondResponse);
        //needed to read in extra input
        getchar();
        switch(secondResponse){
            case 'l':
                array=rotateLeft(array);
                displayArray(array);
                break;
            case 'r':
                array=rotateRight(array);
                displayArray(array);
                break;
            case 'q':
                exit=1;
                break;
            default:
                break;
        }
    }

}
