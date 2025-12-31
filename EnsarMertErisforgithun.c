#include <stdio.h>
#define MAX 50

float genelOrtalama(int notSayisi, int notlar[], float yuzdeEtki[])
{
    float toplam = 0;
    for(int i = 0; i < notSayisi; i++){
        toplam += notlar[i] * (yuzdeEtki[i] / 100);
    }
    return toplam;
}
float yuzdeToplami(int notSayisi, float yuzdeEtki[])
{
    float toplam = 0;
    for(int i = 0; i < notSayisi; i++)
        toplam += yuzdeEtki[i];
    return toplam;
}

int main(void){
    FILE *cfPtr;
    unsigned int notSayisi;
    char ders[MAX];
    int notlar[MAX];
    float yuzdeEtki[MAX];

    if((cfPtr = fopen("ortalama.txt", "w")) == NULL){
        puts("file cannot be opened");
        return 1;
    }
    
    else{
    printf("Ders adini ve kac not gireceginizi yaziniz: ");
    scanf("%49s %u", ders, &notSayisi);

    for(int i = 0; i < notSayisi; i++){
        printf("%d. notu giriniz: ", i+1);
        scanf("%d", &notlar[i]);
    }

    for(int i = 0; i < notSayisi; i++){
        printf("%d. notun ortalamanin yuzde kacini etkiledigini yaziniz: ", i+1);
        scanf("%f", &yuzdeEtki[i]);
    }

    float yuzdeToplam = yuzdeToplami(notSayisi, yuzdeEtki);
    if (yuzdeToplam != 100){
    printf("Yuzdelerin toplami %.1f ,100 olmali!\n", yuzdeToplam);
    return 1;
    }

    else{
    float AgenelOrtalama = genelOrtalama(notSayisi, notlar, yuzdeEtki);
    printf("Genel ortalama: %.1f\n", AgenelOrtalama);

    fprintf(cfPtr, "Ders: %s\n", ders);
    fprintf(cfPtr, "Genel ortalama: %.1f\n", AgenelOrtalama);
    if(AgenelOrtalama>=70){
        fprintf(cfPtr,"Güzel not böyle devam.");
    }
    else if(AgenelOrtalama<70 && AgenelOrtalama>30){
        fprintf(cfPtr,"Biraz daha fazla denemen lazım.");
    }
    else if(AgenelOrtalama<=30){
        fprintf(cfPtr,"Çok daha fazla çalışman lazım.");
    }
    }
    }
    fclose(cfPtr);

    return 0;
}