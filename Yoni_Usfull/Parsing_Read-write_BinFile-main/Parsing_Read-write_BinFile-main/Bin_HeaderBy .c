//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <time.h>
//#pragma warning (disable : 4996)
//
//typedef struct OskerActor
//{
//    int Index;
//    int Year;
//    int Age;
//    char Movie[1000];
//    char Name[1000];
//    struct OskerActor* Next;
//    struct OskerActor* Prev;
//}t_OskerActor;
//
//
//typedef struct OskerActor_Header
//{
//    int version;
//    int ActorCount;
//    char Reserved[1000];
//}t_OskerActor_Header;
//
//
////t_OskerActor* Tail = NULL;
////t_OskerActor* Head = NULL;
////t_OskerActor* previtem = NULL;
//
//struct Color
//{
//    char R;
//    char G;
//    char B;
//};
//
//int main()
//{
//    FILE* f;
//
//
//    //exsample
//    char* buffer = (char*)malloc(30000);
//    fread(buffer, 30000, 1, f);
//    buffer++;
//
//    // the same exsample
//    struct Color* buffer = (struct Color*)malloc(sizeof(struct Color)*100*100);
//    fread(buffer, 30000, 1, f);
//    buffer++;
//
//    
//    t_OskerActor_Header h;
//    h.version = 1;
//    h.ActorCount = 89;
//    fwrite(&h, sizeof(t_OskerActor_Header), 1, f);
//    for (int i = 0; i < 10; i++)
//    {
//
//    }
//   
//    return 0;
//}
//
//
