#include <stdio.h> 
#include <stdlib.h>  
#include <math.h>

//Alexander Kourtev, FA, kurs 1, 011220040, Zadacha za Dami izpulnena s backtracking na ezik C

int a[30]; //suhranqva mqstoto na koeto e postavene na damata
int count=0; //broi resheniq

void main() //main funkciqta s koqto opredelqme obshtiq broi na damite i saotvetno razmera na shahmatnata duska (moje da se napravi i s fiksirano chislo, bez vuvezhdane ot klaviaturata)
{
 int n;
 printf("\nVuvedete broi na damite\n");
 scanf("%d",&n);
 queen(n);
 printf("\nObsht broi resheniq=%d\n\nVsichki resheniq moje da vidite po-gore.",count);
 return 0;
}


int place(int pos) //funkciq za postavqne na damata
{
    int i;
    for(i=1; i<pos; i++) //zapochvame ot red 1
    {
        if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos)))) //proverka za dama pod udar v sushtiq red
        return 0;
        //abs - This function returns the absolute value of an integer.
    }
    return 1; //oznachava che damata moje da bude postavena v saotvetniq red i kolona
}

void print_sol(int n) //funkciq za izvejdane na reshenieto
{
    int i, j;
    count++;
    printf("\n\nReshenie #%d: \n", count);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i]==j) //sformirane na shahmatnata duska s '*' za prazno pole i 'Q' za dama
            printf("Q\t");
            else
            printf("*\t");
        }
        printf("\n");
    }
}


void queen(int n) //backtracking funkciq za postavqne na damite
{
    int k=1; //nomer na damata
    a[k]=0;  //suhranqva value of column (kolonata na shahmatnata duska)
    while(k!=0)
    {
        do
        {
            a[k]++; //sledvashta kolona
        } 
        while((a[k]<=n)&&!place(k)); //ako ne mojem da postavim dama na place(k) produlzhava do loop
        if(a[k]<=n)
        {
            if(k==n) //proverka dali sme postavili vsichki dami
            print_sol(n); //print solution
            else
            {
                k++;
                a[k]=0; //column value = 0
            }
        }
        else 
        k--; 
    }
   
}


