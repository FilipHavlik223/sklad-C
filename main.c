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

void vypis_produkty() {
    printf("\n=== SEZNAM PRODUKTU ===\n");

    if (pocet == 0) {
        printf("Sklad je prazdny!\n");
        return;
    }

    printf("\nIndex | Nazev                | Cena      | Pocet kusu\n");
    printf("------+----------------------+-----------+-----------\n");

    for (int i = 0; i < pocet; i++) {
        printf("%-5d | %-20s | %9.2f | %9d\n",
               i + 1,
               produkty[i].nazev,
               produkty[i].cena,
               produkty[i].pocet_kusu);
    }
    printf("\n");
}

void vyhledej_nazev() {
    char hledany[MAX_NAZEV];
    int nalezeno = 0;

    printf("\nZadej nazev produktu: ");
    scanf("%s", hledany);

    for (int i = 0; i < pocet; i++) {
        if (strcmp(produkty[i].nazev, hledany) == 0) {
            printf("\nNalezeno na indexu %d\n", i + 1);
            printf("Nazev: %s\n", produkty[i].nazev);
            printf("Cena: %.2f Kc\n", produkty[i].cena);
            printf("Pocet kusu: %d ks\n", produkty[i].pocet_kusu);
            nalezeno = 1;
        }
    }

    if (!nalezeno) {
        printf("\nProdukt '%s' nebyl nalezen.\n", hledany);
    }
}

void vyhledej_cenu() {
    float od, do_ceny;
    int nalezeno = 0;

    printf("\nZadej minimalni cenu: ");
    scanf("%f", &od);
    printf("Zadej maximalni cenu: ");
    scanf("%f", &do_ceny);

    printf("\nIndex | Nazev                | Cena      | Pocet kusu\n");
    printf("------+----------------------+-----------+-----------\n");

    for (int i = 0; i < pocet; i++) {
        if (produkty[i].cena >= od && produkty[i].cena <= do_ceny) {
            printf("%-5d | %-20s | %9.2f | %9d\n",
                   i + 1,
                   produkty[i].nazev,
                   produkty[i].cena,
                   produkty[i].pocet_kusu);
            nalezeno = 1;
        }
    }

    if (!nalezeno) {
        printf("Zadny produkt v tomto cenovem rozmezi.\n");
    }
    printf("\n");
}

void zobraz_detail() {
    int index;

    printf("\nZadej index produktu: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= pocet) {
        printf("Neplatny index!\n");
        return;
    }

    printf("\n=== DETAIL PRODUKTU ===\n");
    printf("Index: %d\n", index + 1);
    printf("Nazev: %s\n", produkty[index].nazev);
    printf("Cena: %.2f Kc\n", produkty[index].cena);
    printf("Pocet kusu: %d ks\n", produkty[index].pocet_kusu);
    printf("Celkova hodnota: %.2f Kc\n",
           produkty[index].cena * produkty[index].pocet_kusu);
    printf("\n");
}

void pridej_produkt() {
    if (pocet >= MAX_PRODUKTU) {
        printf("Sklad je plny!\n");
        return;
    }

    printf("\n=== PRIDANI PRODUKTU ===\n");
    printf("Nazev: ");
    scanf("%s", produkty[pocet].nazev);

    printf("Cena: ");
    scanf("%f", &produkty[pocet].cena);

    printf("Pocet kusu: ");
    scanf("%d", &produkty[pocet].pocet_kusu);

    pocet++;
    printf("Produkt pridan.\n");
}

void uprav_produkt() {
    int index, volba;

    printf("\nZadej index produktu k uprave: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= pocet) {
        printf("Neplatny index!\n");
        return;
    }

    printf("\nUpravujes: %s\n", produkty[index].nazev);
    printf("1 - Nazev\n2 - Cena\n3 - Pocet kusu\n4 - Vse\n");
    printf("Vyber volbu: ");
    scanf("%d", &volba);

    if (volba == 1 || volba == 4) {
        printf("Novy nazev: ");
        scanf("%s", produkty[index].nazev);
    }

    if (volba == 2 || volba == 4) {
        printf("Nova cena: ");
        scanf("%f", &produkty[index].cena);
    }

    if (volba == 3 || volba == 4) {
        printf("Novy pocet kusu: ");
        scanf("%d", &produkty[index].pocet_kusu);
    }

    printf("Produkt upraven.\n");
}

void odeber_produkt() {
    int index;
    char odpoved;

    printf("\nZadej index produktu k odstraneni: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= pocet) {
        printf("Neplatny index!\n");
        return;
    }

    printf("Opravdu odstranit '%s'? (a/n): ", produkty[index].nazev);
    scanf(" %c", &odpoved);

    if (odpoved == 'a' || odpoved == 'A') {
        for (int i = index; i < pocet - 1; i++) {
            produkty[i] = produkty[i + 1];
        }
        pocet--;
        printf("Produkt odstranen.\n");
    } else {
        printf("Odstraneni zruseno.\n");
    }
}

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