#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)

typedef struct OskerActor
{
    int Index;
    int Year;
    int Age;
    int Popolarity;
    char Movie[1000];
    char Name[1000];
    struct OskerActor* Next;
    struct OskerActor* Prev;
}t_OskerActor;

typedef struct OskerActor_Header
{
    int version;
    int ItemCount;
    char Reserved[1000];
}t_OskerActor_Header;


t_OskerActor* Tail = NULL;
t_OskerActor* Head = NULL;
t_OskerActor* previtem = NULL;
int ItemCount = 0;

void AddItem(int Index, int Year, int Age, char Movie[1000], char Name[1000])
{

    t_OskerActor* curr = NULL;


    curr = (t_OskerActor*)malloc(sizeof(t_OskerActor));
    curr->Index = Index;
    curr->Year = Year;
    curr->Age = Age;
    curr->Popolarity = 0;
    strcpy(curr->Movie, Movie);
    strcpy(curr->Name, Name);
    ItemCount++;

    if (Head == NULL) {
        //EventLogval("added the First number to the list", number);
        Head = curr;
        Tail = curr;
        curr->Prev = NULL;
        curr->Next = NULL;
        previtem = curr;
    }
    else
    {
        //EventLogval("added a number to the list", number);
        curr->Next = NULL;
        curr->Prev = previtem;
        previtem->Next = curr;
        Tail = curr;
        previtem = curr;
    }
}

void LoadFile()
{
    char str[1000];
    char index[1000];
    char year[1000];
    char Age[1000];
    char Name[1000];
    char Movie[1000];
    char* token = strtok(str, ",");

    FILE* f = fopen("parsing_W.txt", "r");
    if (f) {

        fgets(str, 1000, f);

        while (fgets(str, 1000, f) != NULL)
        {

            token = strtok(str, ",");
            strcpy(index, token);
            token = strtok(NULL, ",");
            strcpy(year, token);
            token = strtok(NULL, ",");
            strcpy(Age, token);
            token = strtok(NULL, ",");
            strcpy(Name, token);
            token = strtok(NULL, ",");
            strcpy(Movie, token);
            AddItem(atoi(index), atoi(year), atoi(Age), Movie, Name);
        }
    }
}

void Printlist()
{
    t_OskerActor* currentItem1 = Head;
    t_OskerActor* printL = Head;

    while (printL->Next != NULL)
    {
        printL = currentItem1;
        currentItem1 = currentItem1->Next;
        printf("#%d\n popolarity : %d\n year : %d\n age : %d\n name : %s\n movie : %s\n\n", printL->Index, printL->Popolarity, printL->Year, printL->Age, printL->Name, printL->Movie);
    }
    printf("\nin the list you have:%d items\n\n", ItemCount);
}

void PrintAllMoviesForYear(int Year)
{
    t_OskerActor* currentItem1 = Head;
    t_OskerActor* printL = Head;

    while (printL->Next != NULL)
    {
        printL = currentItem1;
        currentItem1 = currentItem1->Next;

        if (printL->Year == Year) {
            printf("#%d\n name : %s\n\n", printL->Index, printL->Name);
        }
    }
}

void GetMovieByIndex(Index)
{
    t_OskerActor* currentItem1 = Head;
    t_OskerActor* printL = Head;

    while (printL->Next != NULL)
    {
        printL = currentItem1;
        currentItem1 = currentItem1->Next;

        if (printL->Index == Index) {
            printf("#%d\n year : %d\n age : %d\n name : %s\n movie : %s\n\n", printL->Index, printL->Year, printL->Age, printL->Name, printL->Movie);
        }
    }

}

void Replace(t_OskerActor* item)
{
    if (item == NULL) {
        //EventLogval("No need to swap", 0);
        return;
    }

    t_OskerActor* CopyList = NULL;
    t_OskerActor* NextItem;
    t_OskerActor* List;

    CopyList = (t_OskerActor*)malloc(sizeof(t_OskerActor));

    List = item;
    CopyList->Next = item->Next;
    CopyList->Prev = item->Prev;
    NextItem = item->Next;


    if (item == Tail) {
        // EventLogval("No need to swap", item->num);
        return;
    }
    else if (List == Head && NextItem == Tail)
    {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList->Prev;
        NextItem->Next = List;
        Tail = List;
        Head = NextItem;
    }
    else if (item == Head) {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList->Prev;
        NextItem->Next = List;
        List->Next->Prev = List;
        Head = NextItem;
    }
    else if (item == Tail->Prev)
    {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList->Prev;
        NextItem->Next = List;
        NextItem->Prev->Next = NextItem;
        if (Tail == NextItem) {
            Tail = List;
        }
    }
    else
    {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList->Prev;
        NextItem->Next = List;
        NextItem->Prev->Next = NextItem;
        List->Next->Prev = List;

    }
    free(CopyList);
}

void New_Best_Shaiker_BubleSort()
{

    int Bublecounter = 1;

    t_OskerActor* curr = Head;

    if (!curr/* !curr = curr!=NULL*/) {
        //EventLog("the list is empty");
        return;
    }

    t_OskerActor* CheckItem = Head->Next;

    t_OskerActor* CopyHead = NULL;
    t_OskerActor* CopyTail = NULL;

    //EventLog("Start sorting");
    while (Bublecounter != 0)
    {
        curr = Head;
        CheckItem = Head->Next;

        while (Bublecounter != 0)
        {
            Bublecounter = 0;

            while (CheckItem != NULL && curr->Next != CopyTail)
            {
                if (curr->Popolarity > CheckItem->Popolarity) {
                    Replace(curr);
                    CheckItem = curr->Next;
                    Bublecounter++;
                }
                else
                {
                    curr = curr->Next;
                    CheckItem = CheckItem->Next;
                }
            }
            CopyTail = curr;
            curr = curr->Prev;
            CheckItem = curr->Prev;


            while (CheckItem != NULL && curr->Prev != CopyHead)
            {
                if (curr->Popolarity < CheckItem->Popolarity) {
                    Replace(CheckItem);
                    CheckItem = curr->Prev;
                    Bublecounter++;
                }
                else
                {
                    curr = curr->Prev;
                    CheckItem = CheckItem->Prev;
                }
            }
            CopyHead = curr;
            curr = curr->Next;
            CheckItem = curr->Next;

        }
    }
    //EventLog("End sorting");

}


void UpdatePopolarity(int index)
{
    t_OskerActor* currentItem1 = Head;
    t_OskerActor* UpdateP = Head;

    while (UpdateP->Next != NULL)
    {
        UpdateP = currentItem1;
        currentItem1 = currentItem1->Next;

        if (UpdateP->Index == index) {
            UpdateP->Popolarity++;
            break;
        }
    }
}

void Run()
{
    time_t j = time(NULL);
    srand(j);


    for (int i = 0; i < 10000; i++)
    {
        UpdatePopolarity(rand() % 1000);
    }
}

void Save(char FileName[100])
{
    t_OskerActor_Header* H = (t_OskerActor_Header*)malloc(sizeof(t_OskerActor_Header));
    H->version = 1;
    H->ItemCount = ItemCount;

    t_OskerActor* list = (t_OskerActor*)malloc(sizeof(t_OskerActor));
    list = Head;

    FILE* f1 = fopen(FileName, "wb");
    if (f1) {

        int write = fwrite(H, sizeof(t_OskerActor_Header), 1, f1);
        if (write == NULL) {
            //error
        }

        for (int i = 0; i < ItemCount; i++)
        {
            write = fwrite(list, sizeof(t_OskerActor), 1, f1);
            if (!write) {
                //error
            }
            list = list->Next;
        }



        fclose(f1);
        free(H);
    }
    else
    {
        //error
    }


}

void FreeList()
{
    t_OskerActor* currentItem1 = Head;
    t_OskerActor* printL = Head;

    while (currentItem1 != NULL)
    {
        printL = currentItem1;
        currentItem1 = currentItem1->Next;
        free(printL);
    }
}

void ReadFile(char FileName[100])
{
    t_OskerActor_Header* H = (t_OskerActor_Header*)malloc(sizeof(t_OskerActor_Header));
    t_OskerActor* curr = (t_OskerActor*)malloc(sizeof(t_OskerActor));
    FreeList();
    Head = NULL;
    Tail = NULL;
    ItemCount = 0;

    FILE* f1 = fopen(FileName, "rb");
    if (f1) {

        int read = fread(H, sizeof(t_OskerActor_Header), 1, f1);
        printf("Heder:: version:%d Itemcount:%d\n\n", H->version, H->ItemCount);
        if (read == NULL) {
            //error
        }
        for (int i = 0; i < H->ItemCount; i++)
        {
            read = fread(curr, sizeof(t_OskerActor), 1, f1);
            if (!read) {
                //error
            }
            AddItem(curr->Index, curr->Year, curr->Age, curr->Movie, curr->Name);
        }
        fclose(f1);
        free(H);
        free(curr);
    }
    else
    {
        //error
    }
}

void PrintHighestPop()
{
    t_OskerActor* printL = Tail;

    printf("#%d\n popolarity : %d\n year : %d\n age : %d\n name : %s\n movie : %s\n\n", printL->Index, printL->Popolarity, printL->Year, printL->Age, printL->Name, printL->Movie);
}



int main()
{

    //task 5

    LoadFile();
    //New_Best_Shaiker_BubleSort();
    //Printlist();

    Save("hen6.bin");

    ReadFile("hen6.bin");


    //LoadFile();
    //Run();
    //New_Best_Shaiker_BubleSort();

    Printlist();

    //PrintHighestPop();

    return 0;
}





////task 1
//char str[100] = "123,456,789,1,2,3,4,5,6,7,2000";
//char* token = strtok(str, ",");
//int sum = 0;
//int num;

//while (token != NULL)
//{
//    num = atoi(token);
//    sum = sum + num;
//    token = strtok(NULL, ",");  
//}
//    printf("%d", sum);





////task 2
//char str[100];
//gets(str);
//char* token = strtok(str, " ");


//while (token != NULL)
//{
//    printf("%s\n", token);
//    token = strtok(NULL, " ");  
//}




////task 3
//char str[100];
//gets(str);
//char* token = strtok(str, " ");

//printf("%s\n", token);
//token = strtok(NULL, " ");

//while (token != NULL)
//{
//    printf("%s ", token);
//    token = strtok(NULL, " ");
//}




////task 4
/*char str[1000];
char index[1000];
char year[1000];
char Age[1000];
char Name[1000];
char Movie[1000];
char* token = strtok(str, ",");

FILE* f = fopen("parsing_W.txt", "r");
if (f) {

    fgets(str, 1000, f);

    while (fgets(str, 1000, f) != NULL)
    {

        token = strtok(str, ",");
        strcpy(index, token);
        token = strtok(NULL, ",");
        strcpy(year,token);
        token = strtok(NULL, ",");
        strcpy(Age,token);
        token = strtok(NULL, ",");
        strcpy(Name,token);
        token = strtok(NULL, ",");
        strcpy(Movie,token);
        printf("The Oskar Goes to:%s at:%s Movie:%s", Name, year, Movie);

    }
}*/