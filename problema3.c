#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* (*functions)(char);

void generation(int seed,int lenght, char*s)
{

    int i;

    srand(seed);

    // randomizeaza lenght numere 
    for(i = 0;i < lenght; i++)
    {
        // face ca numarul random sa apartina intervalului [32,125]
        s[i] = rand()%(126 - 32) + 32;
    }

    s[lenght] = '\0';

}

 
char * codificare1(char a)
{
    static int v[130];
    int i;
    int x = v[(int)(a)];
    int digits = 0; // numarul de aparitii a caracterului din variabila a

    if(v[(int)(a)]==0)
    {
    // seteaza digits 1 pentru a intra in for
    digits = 1;
    }
    else
    {
        while(x!=0)
        {
            digits++;
            x = x/10;
        }
    }
    // aloca memorie pentru pointerul p, unde se va constui codificarea caracterului
    char *p = (char *)malloc((1 + digits + 1) * sizeof(char));
    *p = a; // pe prima pozitie este caracterul initial
    x = v[(int)(a)];

    // pe urmatoarele pozitii se adauga numarul de aparitii
    for(i = digits; i >= 1; i--)
    {
        *(p + i)= x %10 + '0';
        x = x/10;
    }

    *(p + digits + 1) = '\0';

    // adauga aparitia
    v[(int)(a)]++;

    return p;

}


char * codificare2(char a)
{

    int mask=32;
    int number_i=0; // numarul de biti 1
    char b;

    char *p=(char *)malloc(2*sizeof(char)+1);
    
    // neaga a 3-a si a 6-a pozitie a caracterului cu xor 2^3 + 2^6 = 72
    a = a ^ 72;
    b = a;

    // gaseste numarul de biti 1
    while(b != 0)
    {
        if(((int)b & 1) != 0) // face o comparatie si pentru ca 1 este 00000001 doar ultima pozitie conteaza
        {
            number_i++;
        }

        b=b>>1;
    }

    // facem operatia OR cu masca
    a = a | mask;
    // seteaza pozitia 0 cu 0 (a & 11111110)
    a = a & 254;

    *p = a; 
    *(p + 1) = number_i + '0';
    *(p + 2) = '\0';

    return p;

}

char * codificare3(char a)
{

    char *p=(char *)malloc(1*sizeof(char)+1);
    
    // daca este litere mica o face litera mare
    if(a >= 97 && a <= 122)
    {
        a = a - 32;
    }

    *p=a;
    *(p+1) = '\0';

    return p;

}

char * transform(functions codificari[], char *s, int lenght)
{
    int i,j,poz_s2=0;
    char *p;

    char *s2=(char *)malloc(1); // sirul ce va tine codificarile caracterelor din s
    *s2='\0';

    for(i=0;i<lenght;i++)
    {
        // randomizeaza intre cele 3 codificari
        p=codificari[rand()%3](s[i]);
        s2=(char *)realloc(s2,(poz_s2 + strlen(p) + 1)*sizeof(char));

        // adauga codificarea la s2
        for(j = 0; j < strlen(p); j++)
        {
            s2[poz_s2] = p[j];
            poz_s2++;
        }

        free(p);
    }
    s2[poz_s2] = '\0';

    return s2;

}

int main(){

    int seed,lenght;
    char *s;    // sirul generat
    char *password; // parola finala

    functions codificari[3]={codificare1,codificare2,codificare3};

    scanf("%d %d",&seed,&lenght);

    s=(char *)malloc((lenght+1)*sizeof(char));

    // genereaza stringul
    generation(seed, lenght, s);

    // codifica sirul generat
    password=transform(codificari, s, lenght);
    printf("%s", password);
    printf("\n");

    // elibereaza memoria
    free(password);
    free(s);


    return 0;
}