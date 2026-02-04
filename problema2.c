#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 11001

struct pair 
{
    char *field;    // cuvantul ce trebuie inlocuit
    char *value;    // cuvantul nou
};

char *strdel(char *p, int wlenght, char **s3)
{
    char aux[strlen(*s3) + 1];
    // determina distanta de la cuvantul gasit in s3 la inceputul sirului s3 pentru a nu pierde pozitia dupa realocare
    int distanta_originala = p - *s3;

    // elimina cuvantul gasit
    strcpy(aux , p + wlenght);
    strcpy(p , aux);

    *s3 = (char *)realloc(*s3,(strlen(*s3)+1) * sizeof(char));
    // s3 pozitia lui p este updatata cu realocarea lui s3
    p = *s3 + distanta_originala; 

    return p;
}

char *strins(char *p, const char *wreplace, char **s3, int l1)
{
    char aux[strlen(*s3) + strlen(wreplace) + 1];

    // determina distanta de la pozitia lui p la inceputul sirului s3 pentru a nu pierde pozitia dupa realocare
    int distanta_originala = p - *s3;

    *s3 = (char *)realloc(*s3,(strlen(*s3)+strlen(wreplace) + 1 )* sizeof(char));
    p = *s3 + distanta_originala;

    // adauga noul cuvant
    strcpy(aux, p);
    strcpy(p, wreplace);
    strcat(p, aux);

    return p;
}


void init(struct pair **date, int n)
{
    // initializeaza structura date
    *date=(struct pair *)malloc(n * sizeof(struct pair ));

    if(*date == NULL) 
    {
    exit(1); 
    }
}

int verify( char *x,char *s3, int l1)
{
    char st;
    // dr devine prima pozitie dupa cuvant
    char dr=*(x +l1); 
    int ver_st=0, ver_dr=0;
    if(x == s3)
    {
    // daca cuvantul este la inceputul sirului st = '.' pentru a intra automat in if
    st = '.';
    }
    else
    {
    // st devine prima pozitie inante de cuvant
    st = *(x - 1); 
    }
    // verifica pozitia dinainte de cuvant
    if( st == ' ' || st == '.' || st == '!' || st == '?' || st == '!' || st == ':' || st == ';' || st == ',' || st == '\n')
    {
        ver_st=1;
    }

    // verifica pozitita de dupa cuvant
    if(dr==' ' || dr == '.' || dr == '!' || dr == '?' || dr == '!' || dr == ':' || dr == ';' || dr == '\0' || dr == ',' || dr == '\n') 
    {
        ver_dr = 1;
    }
    if(ver_dr == 1 && ver_st == 1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n,i;
    struct pair *date;
    char *s3;
    char *x=NULL;

    scanf("%d",&n);
    init(&date,n);

    for(i=0;i<n;i++)
    {
        // aloca cu o marima maxima N
        date[i].field = (char *)malloc(N* sizeof(char));
        date[i].value = (char *)malloc(N* sizeof(char));

        scanf("%s", date[i].field);
        scanf("%s", date[i].value);

        // realoca cu marimea exacta a sirului + terminator
        date[i].field = (char *)realloc(date[i].field , (strlen(date[i].field) + 1) * sizeof(char));
        date[i].value = (char *)realloc(date[i].value , (strlen(date[i].value) + 1) * sizeof(char));
        
    }

    // curata bufferul de \n pentru a citi bine s3
    scanf("\n"); 

    // aloca s3
    s3 = (char *)malloc(N * sizeof(char));
    fgets(s3, N, stdin);
    s3 = (char *)realloc(s3 , (strlen(s3)+1) * sizeof(char));

    for(i = 0; i < n; i++)
    {
        int l1 = strlen(date[i].field); 
        int l2 = strlen(date[i].value); 

        // cauta cuvantul in s3
        x = strstr(s3 , date[i].field);
    
        while(x != NULL )
        {
            if(verify(x, s3, l1))
            {
                // elimina cuvantul din pozitia gasita si realoca dinamic s3
                x = strdel(x, l1, &s3);
                // adauga cuvantul nou la pozitia data si realoca dinamic s3
                x = strins(x, date[i].value, &s3,l1);
                // cauta urmatoarea poztie
                x = strstr(x + l2, date[i].field);
            }
            else
            {
                x = strstr(x+1, date[i].field);
            }
        }
    }

    printf("%s", s3); 

    for (i = 0; i < n; i++) 
    {
        free(date[i].field);
        free(date[i].value);
    }

    free(date);
    free(s3);

    return 0;
}