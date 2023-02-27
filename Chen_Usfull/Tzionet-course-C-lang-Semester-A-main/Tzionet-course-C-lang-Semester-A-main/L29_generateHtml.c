//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <time.h>
//#pragma warning (disable : 4996)
//
//int main() {
//
//	//FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L29 - haim 220922\\textFromC.html", "w");
//	//if (f == NULL) {
//	//	//error
//	//}
//	//else {
//	//	fputs("<html>", f);
//	//	fputs("<head>", f);
//	//	fputs("<title> hi </title>", f);
//	//	fputs("</head>", f);
//	//	fputs("<body>", f);
//	//	fputs("<table>", f);
//	//	fputs("<tr>", f);
//	//	fputs("<td> 1 </td>", f);
//	//	fputs("<td> 2 </td>", f);
//	//	fputs("</tr>", f);
//	//	fputs("</table>", f);
//	//	fputs("<img alt=\"pic\" src=\"https://www.enjpg.com/img/2020/pretty-8.jpg\"/>", f);
//	//	fputs("</body>", f);
//	//	fputs("</html>", f);	
//	//}
//	//fclose(f);
//
////----------------------------------------------------------------------
//
//	//FILE* f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L29 - haim 220922\\textFromC1.html", "w");
//	//if (f1 == NULL) {
//	//	//error
//	//}
//	//else {
//	//	fputs("<html>", f1);
//	//	fputs("<head>", f1);
//	//	fputs("<title> hi </title>", f1);
//	//	fputs("</head>", f1);
//	//	fputs("<body>", f1);
//	//	for (int i = 0; i < 20; i++) {
//	//		fputs("<img alt=\"pic\" src=\"https://www.enjpg.com/img/2020/pretty-8.jpg\"/>", f1);
//	//	}
//	//	fputs("</body>", f1);
//	//	fputs("</html>", f1);
//	//}
//	//fclose(f1);
//
////----------------------------------------------------------------------
//
//	//printf("please enter an image link:");
//	//char imageLink[1000];
//	//char imageLable[1000];
//	//scanf("%s", imageLink);
//	//sprintf(imageLable, "<img alt=\"pic\" src=\"%s\"/>", imageLink);
//	//
//	//FILE* f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L29 - haim 220922\\textFromC2.html", "w");
//	//if (f1 == NULL) {
//	//	//error
//	//}
//	//else {
//	//	fputs("<html>", f1);
//	//	fputs("<head>", f1);
//	//	fputs("<title> hi </title>", f1);
//	//	fputs("</head>", f1);
//	//	fputs("<body bgcolor=\"green\">", f1);
//	//	fputs("<div>", f1);
//	//	fputs(imageLable, f1);
//	//	fputs("</div>", f1);
//	//	fputs("</body>", f1);
//	//	fputs("</html>", f1);
//	//}
//	//fclose(f1);
//
////----------------------------------------------------------------------
//
//	//printf("please enter an image link:");
//	//char imageLink[1000];
//	//char imageLable[1000];
//	//scanf("%s", imageLink);
//	//sprintf(imageLable, "<img height=\"100\" width=\"100\" alt=\"pic\" src=\"%s\"/>", imageLink);
//
//	//printf("please enter a number:");
//	//int imgNum;
//	//scanf("%d", &imgNum);
//
//	//FILE* f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L29 - haim 220922\\textFromC3.html", "w");
//	//if (f1 == NULL) {
//	//	//error
//	//}
//	//else {
//	//	fputs("<html>", f1);
//	//	fputs("<head>", f1);
//	//	fputs("<title> hi </title>", f1);
//	//	fputs("</head>", f1);
//	//	fputs("<body>", f1);
//	//	for (int i = 0; i < imgNum; i++) {
//	//		fputs("<div style=\"background-color:aquamarine\" >", f1);
//	//	    fputs(imageLable, f1);
//	//	    fputs("</div>", f1);
//	//	}
//	//	fputs("</body>", f1);
//	//	fputs("</html>", f1);
//	//}
//	//fclose(f1);
//
////----------------------------------------------------------------------
//
//    printf("please enter an image link:");
//	char imageLink[1000];
//	char imageLable[1000];
//	scanf("%s", imageLink);
//	sprintf(imageLable, "<img height=\"100\" width=\"100\" alt=\"pic\" src=\"%s\"/>", imageLink);
//
//	printf("please enter a number:");
//	int imgNum;
//	scanf("%d", &imgNum);
//
//	FILE* f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L29 - haim 220922\\textFromC4.html", "w");
//	if (f1 == NULL) {
//		//error
//	}
//	else {
//		fputs("<html>", f1);
//		fputs("<head>", f1);
//		fputs("<title> hi </title>", f1);
//		fputs("</head>", f1);
//		fputs("<body>", f1);
//		for (int i = 0; i < imgNum; i++) {
//			fputs("<div style=\"background-color:aquamarine\" >", f1);
//		    fputs(imageLable, f1);
//		    fputs("</div>", f1);
//		}
//		fputs("</body>", f1);
//		fputs("</html>", f1);
//	}
//	fclose(f1);
//
//
//	return 0;
//}
//
//
