#include <stdio.h>

int main()
{
    // vector de caractere folosit pentru a afisa
    // tipul operatiilor
    char a[4]={'+','-','*','/'};
    int v[32]={0},n,dim=1,i=31;
    unsigned int inst;
    scanf("%u",&inst);
    // memorarea bitilor variabilei "inst" in vectorul v
    while(inst>0)
    {
        v[i--]=inst%2;
        inst/=2;
    }
    // determinarea numarului de operatii
    n=v[0]*4+v[1]*2+v[2]+1;
    // afisarea numarului de operatii
    printf("%d ",n);
    // determinarea operatiilor, parcurgand pozitiile bitilor
    // corespunzatori acestora din doi in doi
    for(i=3;i<2*n+2;i+=2)
    {
        int op;
        op=v[i]*2+v[i+1];
        // afisarea operatiei decodate
        printf("%c ",a[op]);
    }
    // calcularea dimensiunii operandului
    int p=8;
    for(;i<=2*n+6;i++)
    {
        dim+=p*v[i];
        p/=2;
    }
    // afisarea dimensiunii operandului
    printf("%d\n",dim);
    return 0;
}
