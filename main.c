#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a {
    double X,Y,sugar;
    char csillagasz[30];
} Krater;

typedef Krater kraterek[100];

int feladat01(kraterek tarol) {
    FILE* be;
    be = fopen("felszin_tpont.txt","r");
    char sor[50];
    int s_sz = 0;
    if(be == NULL) {
      printf("Fajkezelesi problema!");
      return 1;
    }
    while (fgets(sor,sizeof(sor),be)&&s_sz < 100) {
        sor[strcspn(sor,"\n")] = '\0';
        char* reszlet = strtok(sor,"\t");
        tarol[s_sz].X = atof(reszlet);
        reszlet = strtok(NULL,"\t");
        tarol[s_sz].Y = atof(reszlet);
        reszlet = strtok(NULL,"\t");
        tarol[s_sz].sugar = atof(reszlet);
        reszlet = strtok(NULL,"\t");
        strcpy(tarol[s_sz].csillagasz,reszlet);
        s_sz++;
    }
    fclose(be);
    return s_sz;
}

void feladat02(int s_sz) {
    printf("2. feladat:\n");
    printf("A kraterek szama: %d\n",s_sz);
}

void feladat03(kraterek tarol,int s_sz) {
    printf("3.feladat:\n");
    char be_csillagasz[50];
    printf("Kerem egy krater nevet: ");
    scanf("%s",be_csillagasz);
    int talalt = 0;
    for(int i=0;i<s_sz;i++) {
        if(strcmp(tarol[i].csillagasz,be_csillagasz) == 0) {
            printf("A(z) %s kozeppontja X=%.2lf Y=%.2lf sugara R=%.2lf.\n",tarol[i].csillagasz,tarol[i].X,tarol[i].Y,tarol[i].sugar);
            talalt = 1;
        }
    }
    if(!talalt) printf("Nincs ilyen nevu krater.");
}

int main()
{
    kraterek tarol;
    int sorok_szama = feladat01(tarol);
    /** printf("%d\n",sorok_szama);
    for(int i = 0; i<sorok_szama;i++) {
         printf("%.2lf %.2lf %.2lf %s\n",tarol[i].X,tarol[i].Y,tarol[i].sugar,tarol[i].csillagasz);
    }**/
    feladat02(sorok_szama);
    feladat03(tarol,sorok_szama);




    return 0;

}
