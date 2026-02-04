#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int verify(char * s1, char * s2) 
{
  char ver1[60] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i;
  int n1=strlen(s1);
  int n2=strlen(s2);

  // verifica daca caracterele din cele 2 siruri sunt in ver1
  for (i = 0; i < n1; i++) 
  {
    if (strchr(ver1, s1[i]) == NULL) 
    {
      return -1;
    }
  }
  for (i = 0; i < n2; i++) 
  {
    if (strchr(ver1, s2[i]) == NULL) 
    {
      return -1;
    }
  }
  return 1;
}


void extended_string(char * s1, char * s2, char * s3) 
{

  int l1 = strlen(s1);
  int l2 = strlen(s2);
  s3[0] = '\0';
  // adauga s1 in s3 fara a depasii limita
  while (strlen(s3) + l1 <= l2) {
    strcat(s3, s1);
  }
  // adauga restul caracterelor
  int l3 = strlen(s3);
  if(l2 % l1!= 0)
  {
    int a = 0,i;
    for(i = l3; i < l2; i++)
    {
      s3[i] = s1[a];
      a++;
    }
  }
  // pune terminatorul in ultima pozitie
  s3[l2] = '\0';

}

void lenght(char *s3, int *l, int i)
{
  // gaseste distanta dintre caracter si 'a'
  if(s3[i] >= 'a'&& s3[i] <= 'z')
  {
    *l = abs(s3[i] - 'a');
  }
  else if(s3[i] >= 'A' && s3[i] <= 'Z')
  {
  *l = 26 + abs('A' - s3[i]);
  }
}

char * codification(char * s2, char * s3) {
  int i;
  int l = 0;
  int l2 = strlen(s2);
  for (i = 0; i < l2; i++) 
  {
    // calculeaza distanta dintre caracterele din s3 si a 
    lenght(s3,&l,i);

    // muta caracterul la dreapta cu lungimea calculata
    if(s2[i] + l <= 'z' && s2[i] <= 'z' && s2[i] >= 'a')
    {
      // ramane la litere mici
      s2[i] = s2[i]+l; 
    }
    else if(s2[i] + l > 'z' + 26 && s2[i] >= 'a' && s2[i] <= 'z')
    {
      // face un ciclu si se intoarce la litere mici
      s2[i] = 'a' + (l - abs(('z' - s2[i])) - 27); 
    }
    else if(s2[i] + l >= 'z' && s2[i] >= 'a' && s2[i] <= 'z')
    {
      // muta de la litere mici la litere mari
      s2[i] = 'A' + (l-('z' - s2[i]) - 1);
    }
    else if(s2[i] + l <= 'Z' && s2[i] <= 'Z' &&s2[i] >= 'A')
    {
      s2[i] = s2[i] + l;
    }
    else if(s2[i] + l> 'Z' + 26 && s2[i] >= 'A' && s2[i] <= 'Z')
    {
      s2[i] = 'A' + (l - abs(('Z' - s2[i])) - 27);
    }
    else if(s2[i]+l > 'Z' && s2[i] >= 'A' && s2[i] <= 'Z')
    {
      s2[i] = 'a' + (l - ('Z' - s2[i]) - 1);
    }
  }

  s2[l2] = '\0' ;

  return s2;
}
int main() 
{

  char * s1 = (char * ) malloc(14000 * sizeof(char)); // cheia initiala
  char * s2 = (char * ) malloc(14000 * sizeof(char)); // textul
  char * s3 = (char * ) malloc(14000 * sizeof(char)); // noua cheie extinsa

  scanf("%s", s1);
  scanf("%s", s2);

  if (verify(s1, s2) == -1) 
  {
    printf("INVALID\n");

    //elibereaza memoria
    free(s1);
    free(s2);
    free(s3);
  } 
  else 
  {
    // prelungeste cheia in s3
    extended_string(s1, s2, s3);

    // codifica caracterele din s2
    codification(s2, s3);
    
    printf("%s\n", s2); // afiseaza rezultatul final

    // elibereaza memoria
    free(s1);
    free(s2);
    free(s3);
  }

  return 0;
}

