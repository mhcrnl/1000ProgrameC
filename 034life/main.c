    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
           int input;
           while(scanf("%d",&input)==1)
       {
               if(input==42)
                   break;
               else
                   printf("%d\n",input);
       }
       return 0;
    }
