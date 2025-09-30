#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct a {
    double X,Y,sugar;
    char nev[30];
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
        strcpy(tarol[s_sz].nev,reszlet);
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
    char be_nev[30];
    printf("Kerem egy krater nevet: ");
    scanf("%s",be_nev);
    int talalt = 0;
    int i = 0;
    while(i<s_sz && talalt !=1) {

        if(strcmp(tarol[i].nev,be_nev) == 0 ) {
            printf("A(z) %s kozeppontja X=%.2lf Y=%.2lf sugara R=%.2lf.\n",tarol[i].nev,tarol[i].X,tarol[i].Y,tarol[i].sugar);
            talalt = 1;

        } else {
            i++;
        }
    }

    if(!talalt) printf("Nincs ilyen nevu krater.\n");
}

void feladat04(kraterek tarol,int s_sz) {
    int ln_sugar = tarol[0].sugar;
    int ln_sugar_index = 0;
    for (int i =0;i<s_sz;i++) {
        if (tarol[i].sugar > ln_sugar) {
            ln_sugar = tarol[i].sugar;
            ln_sugar_index = i;
        }
    }

    printf("4.feladat:\n");
    printf("A legnagyobb krater neve es sugara: %s %.2lf\n",tarol[ln_sugar_index].nev,tarol[ln_sugar_index].sugar);

}

//5. feladat
double tavolsag(double x1,double x2,double y1,double y2) {
    return sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

void feladat06(kraterek tarol,int s_sz) {
    printf("6.feladat:\n");
    char be_nev[30];
    printf("Kerem egy krater nevet: ");
    scanf("%s",be_nev);
    int hol_van = 0;
    while (strcmp(tarol[hol_van].nev,be_nev)!=0) hol_van++;

    for (int i =0;i<s_sz;i++) {
        if (tarol[i].sugar > ln_sugar) {
            ln_sugar = tarol[i].sugar;
            ln_sugar_index = i;
        }
    }
}

int main()
{
    kraterek tarol;
    int sorok_szama = feladat01(tarol);
    /** printf("%d\n",sorok_szama);
    for(int i = 0; i<sorok_szama;i++) {
         printf("%.2lf %.2lf %.2lf %s\n",tarol[i].X,tarol[i].Y,tarol[i].sugar,tarol[i].nev);
    }**/
    feladat02(sorok_szama);
    feladat03(tarol,sorok_szama);
    feladat04(tarol,sorok_szama);



    return 0;

}
