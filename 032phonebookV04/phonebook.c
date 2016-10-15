/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc version 5.4.0
 *          Fedora 23       Code::Blocks 16.01  gcc version 5.3.1
 ================================================================*/

 #include "phonebook.h"

 char lThePassword[1024], lBuffer[1024];

void Phone()
{
    char response;
    while(response != '9') {
        printf("\t\t__PHONEBOOK PROGRAM__\n"
               "\t (1) Add new contact.  \n"
               "\t (2) Delete contact.   \n"
               "\t (3) Modify contact.   \n"
               "\t (4) Search contact.   \n"
               "\t (5) Print contact.    \n"
               "\t (6) Load an existing phonebook.    \n"
               "\t (7) Save.             \n"
               "\t (8) Delete All        \n"
               "\t (9) Exit              \n"
               "\t >>>>> "
               );
        response = getchar();
        switch(response){
            case '1':
                add(NULL);
                //clearScrean();
                break;
            case '2':
                del_Entrys();
                break;
            case '3':
                Modify();
                break;
            case '4':
                Search();
                break;
            case '5':
                tinyfd_messageBox(lThePassword, lBuffer, "ok/yes", "info", 0);
                printall();
                break;
            case '6':
                LoadV01();
                break;
            case '7':
                Save();
                break;
            case '8':
                deleteAll();
                break;
            case '9': exit(0);break;
            default: printf("\n\t Wrong Command!\n");
        }
    }
}

void printall()
{
    int i;
    for(i=0; i<Num_Entries;i++){
        printf("Contact #%d\n", i+1);
        print_user(Entries[i]);
    }
    if(i==0) printf("NO CONTATS!\n");
    //system("PAUSE");
}

void Save()
{
    fflush(stdin);
    char fileName[16];
    printf("Enter the name of file to save to:\n");
    readString(fileName);
    strcat(fileName, ".txt");
    FILE *F = fopen(fileName, "w");
    fprintf(F, "%d,%d\n", len_Entries, Num_Entries);
    int i;
    for(i=0; i<Num_Entries; i++){
        fprintf(F,"%s,", Entries[i].last_name);
        fprintf(F,"%s,", Entries[i].first_name);
        fprintf(F,"%s,", Entries[i].street_address);
        fprintf(F,"%s,", Entries[i].city);
        fprintf(F,"%s\n", Entries[i].phone_number);
    }
    fclose(F);
    printf("Saved successfully.\n");
    sleep(20);
}
/**< 19. Incarca datele dintr-o fila introdusa de la tastatura Ex.(data) la care
se adauga terminatia .txt */
void Load()
{
    fflush(stdin);
    char fileName[16];
    printf("Enter name of file to load from:\n");
    readString(fileName);
    strcat(fileName, ".txt");
    FILE *F = fopen(fileName, "r");
    if(F==NULL){
        printf("File does not exist.\n");
        sleep(10);
        return;
    }
    fscanf(F, "%d,%d\n", &(len_Entries), &(Num_Entries));
    if(Num_Entries == 0){
        printf("Loading unsuccessful.\n");
        sleep(10);
        return;
    }
    printf("Loading successful.\n");
    sleep(10);
    Entries = malloc((len_Entries)*sizeof(USER));
    int i;
    for(i=0; i<Num_Entries; i++){
        fscanf(F, "%[^,],", (Entries[i].last_name));
        fscanf(F, "%[^,],", (Entries[i].first_name));
        fscanf(F, "%[^,],", (Entries[i].street_address));
        fscanf(F, "%[^,],", (Entries[i].city));
        fscanf(F, "%[^\n]\n", (Entries[i].phone_number));
    }
    fclose(F);
}
/**< 19(A). Incarcarea datelor dintr-o fila cu tinyfiledialogs */
int LoadV01(){
    /**< Variabile locale  */
    FILE *fp;
    char const *lTheOpenFileName;
    char const *lFilterPatterns[2] = {"*.txt", "*.text"};
    /**< tinyfiledialogs - openfiledialog selectarea filei si verificarea existentei acesteia */
    lTheOpenFileName = tinyfd_openFileDialog("Sa citim datele din fisierul: ", " ", 2,
                                             lFilterPatterns, NULL, 0);
    if(!lTheOpenFileName){
        tinyfd_messageBox("Error", "Open file name is NULL.", "ok", "error", 1);
        return 1;
    }
    /**< Deschiderea filei selectate pentru citire si verificarea acesteia */
    fp = fopen(lTheOpenFileName, "r");
    if(!fp){
        tinyfd_messageBox("Error", "Nu se poate citi din fila!", "ok", "error", 1);
        return(1);
    }
    fscanf(fp, "%d,%d\n", &(len_Entries), &(Num_Entries));
    if(Num_Entries == 0){
        printf("Loading unsuccessful.\n");
        sleep(10);
        return (1);
    }
    printf("Incarcarea fisierului efectuata cu succes!\n");
    Entries = malloc((len_Entries)*sizeof(USER));
    int i;
    for(i=0; i<Num_Entries; i++){
        fscanf(fp, "%[^,],", (Entries[i].last_name));
        fscanf(fp, "%[^,],", (Entries[i].first_name));
        fscanf(fp, "%[^,],", (Entries[i].street_address));
        fscanf(fp, "%[^,],", (Entries[i].city));
        fscanf(fp, "%[^\n]\n", (Entries[i].phone_number));
    }
    fclose(fp);
}

void del_Entrys()
{
    char last_name[16], first_name[16];
    printf("Enter last name: \n");
    readString(last_name);
    printf("Enter first name: \n");
    readString(first_name);
    int index = Finder(last_name, first_name);
    if(index == -1){printf("Contact not found!!!\n"); return; }
    else{
        int i =index;
        int Choose;
        while(!strcmp(Entries[index].last_name, last_name) && !strcmp(Entries[index].first_name, first_name) &&
              index < Num_Entries){
                printf("Contact #%d\n", index+1);
                print_user(Entries[index]);
                index++;
              }
            printf("Which contact do you want to delete? \n if you don`t want to delete enter '0'.\n");
            do{
                scanf("%d", &Choose);
                Choose -=1;
                if(Choose == -1) return;
                if(Choose < 0 || Choose > index -1 ||Choose<i) printf("Wrong input.\n");
            } while(Choose < 0 || Choose > index -1 ||Choose<i);
            Shifter_left(Choose, Num_Entries);
            Num_Entries--;
            printf("\nContact deleted.\n");
    }
}

void Search()
{
    fflush(stdin);
    char last_name[16];
    printf("Enter last Name: \n");
    scanf("%s", last_name);
    int i = Finder(last_name, NULL);
    if(i==-1){printf("NO contact with last name: %s\n", last_name); return;}
    while(!strcmp(Entries[i].last_name, last_name) && i<Num_Entries){
        printf("Contact #%d\n", i+1);
        print_user(Entries[i]);
        i++;
    }
    //system("PAUSE");
}

void Modify()
{
    char last_name[16], first_name[16];
    printf("Enter Last Name: \n");
    readString(last_name);
    printf("Enter First Name: \n");
    readString(first_name);
    int index = Finder(last_name, first_name);
    if(index == -1){printf("CONTACT NOT FOUND !!!\n"); return;}
    else {
        int i = index;
        int Choose;
        while(!strcmp(Entries[index].last_name, last_name) && !strcmp(Entries[index].first_name, first_name) &&
              index< Num_Entries){
                printf("Contact #%d\n", index+1);
                print_user(Entries[index]);
                index++;
              }
            printf("Wich contact do you want to modify?\n if you don`t want to modify enter '0'.\n");
            do{
                scanf("%d", &Choose);
                Choose-=1;
                if(Choose == -1) return;
                if(Choose<0 || Choose>index-1 || Choose<i)
                    printf("Wrong input. \n");
            } while (Choose<0 || Choose>index-1 || Choose<i);
            USER m;
            set_User(&m);
            Shifter_left(Choose, Num_Entries);
            Num_Entries--;
            add(&m);
    }
}

void Shifter_left(int index, int num_element)
{
    int i;
    for(i = index; i<num_element-2; i++){
        Entries[i] = Entries[i-1];
    }
}


void print_user(USER u)
{
    printf("First name: %s\n", u.first_name);
    printf("Last Name: %s\n", u.last_name);
    printf("City: %s\n", u.city);
    printf("Address: %s\n", u.street_address);
    printf("Phone Number: %s\n\n", u.phone_number);
}

int Finder(char *last_name, char *first_name)
{
    int i;
    if(Num_Entries <= 0) return -1;
    if(first_name == NULL){
        for(i=0; i<Num_Entries; i++)
            if(!strcmp(Entries[i].last_name, last_name))
                return i;
        } else {
            for(i=0; i<Num_Entries; i++)
                if(!strcmp(Entries[i].first_name, first_name)&& !strcmp(Entries[i].last_name, last_name))
                    return i;
        }
    return -1;
}

void deleteAll()
{
    Num_Entries = 0, len_Entries =0;
    Entries = NULL;
    printf("All Contacts deleted.\n");
    system("PAUSE");
}

void add(USER *u)
{
    Num_Entries++;
    if(u==NULL){
        u = (USER*)malloc(sizeof(USER));
        set_User(u);
    }
    Dynamic_Allocation();
    int index = place_finder(*u);
    Shifter_Right(index, Num_Entries);
    Entries[index] = *u;
    system("PAUSE");
}

void set_User(USER *user)
{
    printf("ENTER FIRST NAME:\n");
    readString(user->first_name);
    printf("ENTER LAST NAME:\n");
    readString(user->last_name);
    printf("ENTER PHONE NUMBER: \n");
    readNum(user->phone_number);
    printf("ENTER STREAT ADDRESS: \n");
    readString(user->street_address);
    printf("ENTER CITY: \n");
    readString(user->city);
}

void readNum(char *str)
{
    int i=0;
    readString(str);
    if(!(str[0]==' '&& str[1]=='\0'))
        for(; str[i]!='\0'; i++)
    if(str[i]<'0' || str[i]>'9'){
        printf("Please enter numbers only: \n");
        readNum(str);
    }
    return;
}

void Dynamic_Allocation()
{
    if(Num_Entries == 1){
        Entries = (USER*)malloc(2*sizeof(USER));
        len_Entries = 2;
    } else if(Num_Entries >= len_Entries -2){
        USER *E = malloc(2*(len_Entries)*sizeof(USER));
        if(E != NULL){
            int i;
            for(i=0; i<Num_Entries; i++){
                E[i] = Entries[i];
            }
            free(Entries);
            Entries = E;
            len_Entries = 2*(len_Entries);
        } else {
            printf("MEMORY ERROR!!!");
            Num_Entries--;
            exit(-1);
        }
    }
}

int place_finder(USER u)
{
    int i= 0;
    if(Num_Entries > 1){
        while(strcmp(Entries[i].last_name, u.last_name) == -1 && i<Num_Entries-1) i++;
        while(strcmp(Entries[i].last_name, u.last_name) == 0 &&
              strcmp(Entries[i].first_name, u.first_name)== -1 &&
               i<Num_Entries-1) i++;
        while(strcmp(Entries[i].last_name, u.last_name) == 0 &&
              strcmp(Entries[i].first_name, u.first_name)== 0 &&
              strcmp(Entries[i].phone_number, u.phone_number)==-1 &&
               i<Num_Entries-1) i++;
    }
    return i;
}

void readString(char *str)
{
    fflush(stdin);
    gets(str);
    char response;
    condition:{
        int i, f1=0, f2=0, n=strlen(str);
        if(strlen(str)<1) {f1=1;}
        for(i=0; i<n; i++){ if(str[i]==' '){f1=1;}else {f1=0;}}
        for(i=0; i<n; i++)
            if(!((str[i] >='a'&&str[i]<='z') || (str[i]>='A'&&str[i]<='Z') || (str[i]>='0'&&str[i]<='9') ||
                 str[i]==' ' || str[i]==',')) f2=1;
        while(f1||f2){
            if(f1){printf("You left this field blank.\n");}
            if(f2 && !f1){printf("You can only enter (a-z) or (A-Z) or (0-9) or \",\".\n");}
            printf("Are you sure you want to continue?(y/n).\n");
            response = getchar();
            switch(response){
                case 'Y': case 'y': if(f1){*str = ' '; *(str+1)='\0';} return;
                case 'N': case 'n': printf("Enter again:\n"); gets(str); gets(str); goto condition; break;
                default: printf("Please enter only (y/n). \n");
            }
        }

    }
}


void Shifter_Right(int index, int  num_element)
{
    int i;
    if(index < num_element-1)
        for(i=1; i< num_element-index; i++){
            Entries[num_element -i] = Entries[num_element-1-i];
    }
}

void clearScrean()
{
    for(int i=0; i<25; i++){
        printf("\n");
    }
}
