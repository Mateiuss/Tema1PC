#include <stdio.h>

int main()
{
    // vector de caractere folosit pentru a afisa
    // tipul operatiilor
    char a[4]={'+','-','*','/'};
    int v[32]={0},op[8],operanzi[145]={0},n,i,dim=1,p=8,k=31,ln_op=-1;
    unsigned int inst;
    scanf("%u",&inst);
    // memorarea bitilor variabilei "inst" in vectorul v
    while(inst>0)
    {
        v[k--]=inst%2;
        inst/=2;
    }
    // determinarea numarului de operatii
    n=v[0]*4+v[1]*2+v[2]+1;
    // determinarea operatiilor, parcurgand pozitiile bitilor
    // corespunzatori acestora din doi in doi
    for(i=3;i<2*n+2;i+=2)
    {
        int operatie;
        operatie=v[i]*2+v[i+1];
        // memorarea operatiilor in vectorul "op"
        op[++ln_op]=operatie;
    }
    // calcularea dimensiunii operandului
    for(;i<=2*n+6;i++)
    {
        dim+=p*v[i];
        p/=2;
    }
    int nr_de_citit=((n+1)*dim)/16;
    if(((n+1)*dim)%16>0)
        nr_de_citit++;
    unsigned short nr;
    int w[145]={0},nw=-1;
    for(i=1;i<=nr_de_citit;i++)
    {
        scanf("%hu",&nr);
        int e[16]={0};
        int j=15;
        while(nr>0)
        {
            e[j--]=nr%2;
            nr/=2;
        }
        for(j=0;j<=15;j++)
            w[++nw]=e[j];
    }
    int dim_operanzi=0;
    for(int i=0;i<=16*nr_de_citit&&dim_operanzi<=ln_op+1;i++)
    {
        if((i+1)%dim==0)
        {
            p=1;
            for(int j=i;j>=i-dim+1;j--)
            {
                operanzi[dim_operanzi]+=w[j]*p;
                p*=2;
            }
            dim_operanzi++;
        }
    }
    dim_operanzi--;
    for(int i=0;i<=ln_op;i++)
    {
        if(a[op[i]]=='*')
        {
            operanzi[i+1]*=operanzi[i];
            operanzi[i]=-1;
        }
        else if(a[op[i]]=='/')
        {
            operanzi[i+1]=operanzi[i]/operanzi[i+1];
            operanzi[i]=-1;
        }
    }
    for(int i=0;i<=ln_op;i++)
    {
        if(a[op[i]]=='+')
        {
            int j=i;
            while(operanzi[j]==-1)
                j++;
            int q=j+1;
            while(operanzi[q]==-1)
                q++;
            operanzi[q]+=operanzi[j];
        }
        else if(a[op[i]]=='-')
        {
            int j=i;
            while(operanzi[j]==-1)
                j++;
            int q=j+1;
            while(operanzi[q]==-1)
                q++;
            operanzi[q]=operanzi[j]-operanzi[q];
        }
    }
    printf("%d\n",operanzi[ln_op+1]);
    return 0;
}
