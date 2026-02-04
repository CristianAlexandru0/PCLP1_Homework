*******************************************************************************
* TEMA 1 - PC & LP1                                                           *
* Student: Cristian Alexandru Catalin                                         *
* Grupa:   312CC                                                              *
*******************************************************************************

===============================================================================
  [ CUPRINS TEMA 1 ]
===============================================================================
  1. problema1.c - Criptarea parolelor: Cifrul Vigenere
  2. problema2.c - Completarea automata a datelor (AutoFill) 
  3. problema3.c - Generarea parolelor sigure
===============================================================================


-------------------------------------------------------------------------------
  [ PROBLEMA 1.C ]
-------------------------------------------------------------------------------
  Durata de implementare: 2.5 ore
  Implementarea unui algoritm de criptare bazat pe Cifrul Vigenere
 
  ~ int main()
      se citesc datele problemei
      se apeleaza functiile {verify(), extended_string(), codification()}
      se afiseaza sirul codificat
    
  ~ int verify()
      se verifica daca cele 2 siruri citite contin doar litere
    
  ~ void extended_string()
      se face un nou sir in care se prelungeste cheia initiala 
      pana la lungimea textului
    
  ~ void lenght()
      se calculeaza lungimea de la caracterul respectiv la 'a'
    
  ~ char *codification()
      se apeleaza functia lenght pentru fiecare caracter din cheie
      se muta la dreapta ciclic litera din text cu lungimea returnata de lenght()
      se returnreaza sirul s2 codificat


-------------------------------------------------------------------------------
  [ PROBLEMA 2.C ]
-------------------------------------------------------------------------------
  Durata de implementare 3-3.5 ore
  Implementează funcționalitatea de AutoFill
      
  ~ int main()
      se citesc datele
      se aloca dinamic
      se cauta sirul ce trebuie inlocuit in text si respecta verify() 
      de cate ori apare in text
      se apeleaza functiile {verify(), strdel(), strins()}
      eliberam memoria
       
  ~ char *strdel()
      elimina sirul ce trebuie inlocuit
      retunreaza pozitia la primul caracter dupa pozitia stearsa
      
  ~ char *strdel()
      se declara un vector auxiliar (aux)
      elimina sirul ce trebuie inlocuit
      retunreaza pozitia la primul caracter dupa pozitia stearsa
      
  ~ char *strins()
      se declara un vector auxiliar (aux)
      adauga noul cuvant
      returneaza pozitia de început al șirului inserat
      
  ~ void init()
      initializeaza structura de date
      
  ~ int verify()
      verifica daca parametrii din fata si din spatele cuvantului 
      sunt corespunzatori


-------------------------------------------------------------------------------
  [ PROBLEMA 3.C ]
-------------------------------------------------------------------------------
  Durata de implementare 4.5 ore
  Implementează un sistem de generare a parolelor pornind de la un seed 
  numeric și o lungime data
        
  ~ int main()
      se declara variabilele si sirul se aloca dinamic
      se apeleaza functia {transform()}
      se afiseaza parola dupa codificari, returnata de functia transform
      se elibereaza memoria
        
  ~ void generation()
      seteaza seed-ul pentru generarea de numere
      randomizeaza un numar si este adus in intervalul [32, 125]
      
  ~ char *codificari1()
      se declara un nou sir p
      se calculeaza numarul de cifre a aparitiei carcaterului
      se alocă dinamic memorie: caracterul + nr_cifre + 1 
      pe prima pozitie a sirului se pune caracetrul initial
      si pe restul numarul de aparitii
    
  ~ char *codificari2()
      se declara un nou sir p
      se declara maska=32 si number_i (numarul de aparitii de biti 1)
      se neaga a 3-a si a 6-a pozitie cu xor
      se gaseste numarul de biti 1
      se face operatia de OR cu maska
      se seteaza poztia 0 cu 10 (caracter & 11111110)
      se pune pe prima pozitie in sir caracterul nou
      se pune pe a doua pozitie numarul de biti 1
      
  ~ char *codificari3()
      se declara un nou sir p
      daca caracterul transmis prin parametru este litera mica, 
      se transforma in litera mare
      daca caracterul nu este litera mica ramane neschimbat
      pe prima pozitie a sirului se pune caracterul respectiv
      
  ~ char *trasnform()
      se declara un nou sir (s2) si se aloca dinamic
      se apeleaza functiile {codificare1(), codificare2(), codificare3()} 
      cu ajutorul unui vector de pointeri la functii
      fiecarui caracter din sirul initial i se aplica o codificare aleatorie
      se adauga sirul returnat din functiile de codificari noului sir (s2)
      returneaza sirul nou codificat

*******************************************************************************
