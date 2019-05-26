#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

void delay(int number_of_seconds)  { 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 
int main(int argc, const char * argv[]) {
  printf("\npid of the program: %d\n", getpid());
  delay(10000);
    FILE *fp;
    //FILE *fpR = fopen("story.txt", "r");
    fp = fopen("test.txt", "w");
    
    char ch;
    char* temp = (char *)malloc(25000 * sizeof(char));
    //char* tt = (char *)malloc(5 * sizeof(char));
    temp = "Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierreIl est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre Il est venu le temps des cathédrales Le monde est entré Dans un nouveau millénaire L'homme a voulu monter vers les étoiles Écrire son histoire Dans le verre ou dans la pierre\n";
    //checks if there is an error
    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    
    //writing on a file
    for (int i = 0; temp[i] != '\n'; i++) {
        fputc(temp[i], fp);
    }
    
    fclose(fp);
    
    fp = fopen("test.txt", "r");
    //reading and printing
    while( (ch = getc(fp)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(fp);
    return 0;
}
