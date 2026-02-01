#include <stdio.h>
#include <string.h>

#define MAX_PRODUKTU 20
#define MAX_NAZEV 50

struct Produkt {
    char nazev[MAX_NAZEV];
    float cena;
    int pocet_kusu;
};

struct Produkt produkty[MAX_PRODUKTU];
int pocet = 0;

void menu() {
    printf("\n=== SKLADOVE HOSPODARSTVI ===\n");
    printf("1 - Vypis vsech produktu\n");
    printf("2 - Vyhledat podle nazvu\n");
    printf("3 - Vyhledat podle ceny\n");
    printf("4 - Zobrazit detail produktu\n");
    printf("5 - Pridat produkt\n");
    printf("6 - Upravit produkt\n");
    printf("7 - Odstranit produkt\n");
    printf("X - Ukoncit program\n");
    printf("\nVolba: ");
}

int main(void) {

    strcpy(produkty[0].nazev, "Notebook");
    produkty[0].cena = 15999.50;
    produkty[0].pocet_kusu = 5;

    strcpy(produkty[1].nazev, "Mys");
    produkty[1].cena = 299.90;
    produkty[1].pocet_kusu = 25;

    strcpy(produkty[2].nazev, "Klavesnice");
    produkty[2].cena = 1499.00;
    produkty[2].pocet_kusu = 12;

    strcpy(produkty[3].nazev, "Monitor");
    produkty[3].cena = 5499.00;
    produkty[3].pocet_kusu = 8;

    pocet = 4;

    char volba;
    printf("Vitejte v systemu skladoveho hospodarstvi!\n");

    while (1) {
        menu();
        scanf(" %c", &volba);

        switch (volba) {
            case '1': vypis_produkty(); break;
            case '2': vyhledej_nazev(); break;
            case '3': vyhledej_cenu(); break;
            case '4': zobraz_detail(); break;
            case '5': pridej_produkt(); break;
            case '6': uprav_produkt(); break;
            case '7': odeber_produkt(); break;
            case 'x':
            case 'X':
                printf("\nDekuji za pouziti. Nashledanou!\n");
                return 0;
            default:
                printf("\nNeplatna volba!\n");
        }
    }
}