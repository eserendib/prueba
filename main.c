#include <stdio.h>
#include <stdlib.h>
#define MAX 48
int main()
{
    int jug1,jug2,sortir=0,cartacodi;
    int qtt=0;
    int Vcarta[MAX];
    int Vbaraja[MAX];

    /// Funcion de codificar la carta
    cartacodi=codificacio(Vcarta);

    do
    {
        /// funcion pedir carta jug1
        jug1=demanarCarta(Vcarta,Vbaraja,qtt);

        jug2=demanarCarta(Vcarta,Vbaraja,qtt);

    }while(sortir!=0 || qtt==0);

    return 0;
}

int demanarCarta(int Vcarta[MAX],int Vbaraja[MAX],int qtt)
{
    int num=0;
    char palo;

        printf("\nPide el numero de la carta y el palo de la carta: ");
        scanf("%d%c",&num,&palo);

         while (num<1 || num>12 || palo!='C' && palo!='c' && palo!='O'&&palo!='o' && palo!='B' && palo!='b' && palo!='E' && palo!='e')
            {
                printf("\nEscribe un numero de la baraja bien con el palo correcto : ");
                scanf("%d%c",&num,&palo);
            }

        int i;
             for(i=0;i<qtt;i++)
            {
                num=Vcarta[i];
                palo=Vcarta[i];
                Vbaraja[i]=Vbaraja[i-1];
                qtt--;
            }

        return num,palo;

}








int codificacio(int Vcarta[MAX])
{
    int i;
    int carta=1; ///Empezamos la carta en el uno

    for(i=0;i<MAX;i++)
    {
        ///BASTOS
        if(i<12)
        {
            Vcarta[i]=100*0+carta;
            carta++;
        }
        /// Ponemos La carta otra vez a 1 para que vaya de 1 a 12

        if(i==12)carta=1;
        /// ESPADAS
        if(i>11 && i<24)
        {
            Vcarta[i]=100*1+carta;
            carta++;
        }

        if(i==24)carta=1;

        /// COPES
        if(i>23 && i<36)
        {
            Vcarta[i]=100*2+carta;
            carta++;
        }
        if(i==36)carta=1;

        /// OROS
        if(i>35 && i<MAX)
        {
            Vcarta[i]=100*3+carta;
            carta++;
        }
    }
    return i;
}
