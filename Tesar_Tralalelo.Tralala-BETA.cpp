#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void smrt() {
    cout << "Konec hry :( Nedostatek zdrojů nebo prohra.\n";
    exit(0);
}

void rozdelovac() {
    cout << "\n____________________________________________________________\n\n";
}

struct Hrdina {
    string jmeno;
    int level;
    int xp;
    int gold;
    int maxHp;
    int hp;
    int attack;
    int maxMana;
    int mana;
};

struct Nepritel {
    string jmeno;
    int maxHp;
    int hp;
    int damage;
    bool MiniBoss;
    bool Boss;
};

void vyber(Hrdina &pl);
void playerInfo(const Hrdina &pl);
void levelUp(Hrdina &pl);
int dropGold(bool always);
void souboj(Hrdina &pl, vector<Nepritel> enemies);
void vesnice(Hrdina &pl);
void obchod(Hrdina &pl);
void hospoda(Hrdina &pl);
void knihovna(Hrdina &pl);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));

    cout << "Vítám tě ve světě Tralelo Tralala\n";
    Hrdina pl;
    vyber(pl);
    rozdelovac();
    cout << "Včera jsi to přehnal s místní pálenkou v hospodě. Ze včerejška si nepamatuješ vůbec nic\n";
    cout << "Jdi za dobrodružtvím a zkus zjistit co se včera vlastně všechno stalo\n";
    cout << "Jako bonus po cestě máš šanci získat zlato a vylevelit svého hrdinu\n";
    rozdelovac();
    cout << "Probudil jsi se pod mostem.\n";
    cout << "Všiml jsi tě tamnější Hobo a myslí si, že se mu snažíš obsadit území\n";
    cout << "Hobo tě vyzval na souboj\n";

    souboj(pl, {{"Hobo", 5, 5, 2, false, false}});

    cout << "Pokud jsi zraňen nebo máš málo many tak projdi vesnici a v ní se zkus healnout\n";
    vesnice(pl);
    rozdelovac();

    cout << "Po cestě za dobrodružstvím jsi potkal dvojici hladových vlků\n";
    cout << "Vlkům jen tak neutečeš, obávám se, že budeš muset bojovat\n";

    Nepritel vlk = {"Hladový vlk Roberto", 4, 4, 3, false, false};
    Nepritel vlk2 = {"Hladový vlk Gertrůda", 5, 5, 2, false, false};

    souboj(pl, {{vlk, vlk2}});
    cout << "Gratuluji přežil jsi ;)!";
    cout << "Pokud jsi zraňen nebo máš málo many tak projdi vesnici a v ní se zkus healnout\n";
    cout << "Našel jsi na zemi 5 goldů\n";
    pl.gold = pl.gold+5;
    vesnice(pl);
    cout << "A sakra, když jsi procházel vesnicí tak si tě všimnuli bezdomovci. Což je problém protože chtějí tvojí hlavu vidět viset, jelikož jsi jim zabil kamaráda Hobo\n";
    cout << "Tři na jednoho, jsou to zbabělci ale věřím že to zvládneš;)\n";

    Nepritel bezdomovec1 = {"Bezdomovez Erik", 4, 4, 3, false, false};
    Nepritel bezdomovec2 = {"Bezdomovkyně Ludmila", 5, 5, 2, false, false};
    Nepritel bezdomovec3 = {"Bezdomovec Kocián", 5, 5, 2, false, false};
    souboj(pl, {{bezdomovec1, bezdomovec2, bezdomovec3}});

    cout << "Hezky pekně, tři na jednoho a stejně prohráli!!\n";
    cout << "Pokud jsi zraňen nebo máš málo many tak projdi vesnici a v ní se zkus healnout\n";
    vesnice(pl);

    cout << "Po cestě za dalším dobrodružstvím z pozarohu na tebe vyběhnul naštvaný Kozel\n";
    cout << "Jsi skřípnut v slepé uličce, takže se mu musíš postavit čelem:(\n";

    Nepritel kozel = {"Naštvaný zmutovaný Kozel(11)", 12, 12, 4, true, false};
    souboj(pl, {{kozel}});

    cout << "Když tě trefil kozel do hlavyy tak sis vzpoměl, že včera jsi nebyl sám.";
    cout << "Kolemjdoucí vesničan ti řekl, že jsi byl s princeznou. Víc bohužel neví.\n";
    cout << "Doporučil ti jít do cirkusu, že tam by ses mohl dozvědět více\n";
    cout << "Pokud jsi zraňen nebo máš málo many tak projdi vesnici a v ní se zkus healnout\n";
    vesnice(pl);
    cout << "Vypadá to, že to byla past. Asi jsi kolemjdoucímu něco provedl.\n ";
    cout << "V cirkuse na tebe vyběhlo deset Děsivých Klaunů!!!!!\n";
    for (int i = 0; i < 10; i++)
        souboj(pl, {{"Děsivý Klaun", 7, 7, 2, false, false}});

    cout << "Sice jich bylo deset ale tys to zvládl jako by tam nikdo nebyl:)\n";
    cout << "Ale nesmíš oslavovat předčasně. Mají v záloze Sneaky Golema, to už bude o chlup težší:(\n";
    Nepritel golem = {"Sneaky Golem", 14, 14, 5, true, false};
    souboj(pl, {{golem}});
    cout << "Pfffff, zapomněl jsem s kým mám tu čest se bavit;)\n ";
    cout << "Z posledního nádechu ti golem prozradil že princeznu u sebe drží Mlsnožrout Mystifex\n";
    cout << "Nedobrovolně ti prozradil, kde ho najdeš\n";
    cout << "Ale na jméno sis furt nevzpomněl:(\n";
    cout << "Z Golema vypadla tučná suma zlata, tak se pořádně připrav na Mystifexe\n";
    pl.gold=pl.gold+200;
    vesnice(pl);
    cout << "Je to tu, finální chvíle, všechno nebo nic\n";
    cout << "Držím palce\n";
    Nepritel Mystifex = {"Mystifex", 50, 50, 0, false, true};
    souboj(pl, {{Mystifex}});
    cout << "Gratuluji! Porazil jsi Mystifexe, postrach všech sladkostí, konečně zbydou sladkosti i na vesničany:).\n";
    cout << "Ale to hlavní. Musíš jít ještě osvobodit princeznu\n";
    rozdelovac();
    cout << "Když jsi přišel k žaláři tak ti to vše docvaklo. Není to princezna, kterou bys očekával\n";
    cout << "Včera večer jsi byl chlastat se svým chábrem a on na trhu ukradl kostým princezny\n";
    cout << "Ale bro je důležitější než jakákoliv hoe!!!!!!!\n";
    cout << "Poté co jsi ho osvobodil, tak zandal: Dneska druhý kolo!!\n";
    rozdelovac();
    cout << endl;
    rozdelovac();
    cout << endl;
    rozdelovac();
    cout << endl;
    cout << "Děkuji za dohraní mé hry:))))";
    cout << "Tralalelo Tralala BETA\n";
    cout << "Vytvořil:         Tomáš Tesař\n";
    cout << "Radil při tvorbě: Miloš Tesař\n";
    cout << "Pokračovaní?????\n";



    return 0;
}

void vyber(Hrdina &pl) {
    while (true) {
        bool run = true;
        while (run) {
            cout << "Vyber za koho budeš hrát:\n";
            cout << "1) Gundolf (HP=5, Atk=3, Mana=5)\n";
            cout << "2) Rytíř Gambrinus (HP=6, Atk=4, Mana=3)\n";
            cout << "3) Bambál (HP=4, Atk=2, Mana=8)\n";
            cout << ">> "; int v; cin >> v;
            switch (v) {
                case 1:
                    pl.jmeno = "Gundolf"; pl.maxHp = 5; pl.attack = 3; pl.maxMana = 5; run = false; break;
                case 2:
                    pl.jmeno = "Rytíř Gambrinus"; pl.maxHp = 6; pl.attack = 4; pl.maxMana = 3; run = false; break;
                case 3:
                    pl.jmeno = "Bambál"; pl.maxHp = 4; pl.attack = 2; pl.maxMana = 8; run = false; break;
                default:
                    cout << "Neplatná volba";
            }
            rozdelovac();
        }
        pl.hp = pl.maxHp;
        pl.mana = pl.maxMana;
        cout << "Zvolil jsi: " << pl.jmeno << " - HP:" << pl.hp << "/" << pl.maxHp
             << ", Atk:" << pl.attack << ", Mana:" << pl.mana << "/" << pl.maxMana << "\n";
        cout << "Chceš potvrdit volbu? 1 = Ano, jinak znovu >> "; int a; cin >> a;
        if (a == 1) break;
    }
    pl.level = 1; pl.xp = 0; pl.gold = 0;
}

void playerInfo(const Hrdina &pl) {
    rozdelovac();
    cout << "-- Info o hrdinovi --\n";
    cout << "Třída: " << pl.jmeno << ", Level: " << pl.level << ", XP: " << pl.xp << "\n";
    cout << "HP: " << pl.hp << "/" << pl.maxHp << ", Mana: " << pl.mana << "/" << pl.maxMana
         << ", Atk: " << pl.attack << ", Gold: " << pl.gold << "\n";
         rozdelovac();
}

void levelUp(Hrdina &pl) {
    int need = pl.level * 10;
    if (pl.xp >= need) {
        pl.xp -= need;
        pl.level++;
        pl.maxHp++;
        pl.hp = pl.maxHp;
        pl.attack++;
        pl.maxMana++;
        pl.mana = pl.maxMana;
        rozdelovac();
        cout << "Gratuluji! Dosáhl jsi levelu " << pl.level << ". Staty byly zvýšeny.\n";
        rozdelovac();
    }
}

int dropGold(bool always) {
    if (always) return rand() % 20 + 10;
    if (rand() % 2 == 0) return rand() % 10 + 1;
    return 0;
}

void souboj(Hrdina &pl, vector<Nepritel> enemies) {
    bool playerStarts = true;
    if (enemies[0].MiniBoss || enemies[0].Boss) playerStarts = false;


    bool ledovaPast = false;
    bool hadiPast = false;
    bool hadZneskodnen = false;
    bool mlsnaPast = false;

    cout << "Souboj: ";
    for (auto &e : enemies) cout << e.jmeno << " ";
    cout << "\n";

    while (pl.hp > 0 && !enemies.empty()) {
        for (auto &e : enemies) {
            if (!e.Boss) {
                cout << e.jmeno << " HP:" << e.hp << "/" << e.maxHp << "  ";
            }
        }
        if (!enemies.empty()) cout << "\n";

        if (playerStarts) {
            cout << "Tvůj tah - Zadej 1 pro standardní útok (" << pl.attack << " dmg)";
            if (pl.mana > 0) cout << ", 2 pro speciální (1 MP = +1 dmg)";
            if (mlsnaPast) cout << ", 3 pro mlsání (10 HP heal, -10 Max HP)";
            cout << " > ";
            int act; cin >> act;


            if (ledovaPast && (act == 1 || act == 2)) {
                cout << "Zmrazil jsi se na mrazivé pasti! Tah byl zrušen.\n";
                ledovaPast = false;
            }

            else if (mlsnaPast && act == 3) {
                pl.hp += 10;
                pl.maxHp -= 10;
                cout << "Snědl jsi dobroty! HP +10, Max HP -10.\n";
                mlsnaPast = false;
            }
            else {

                if (hadiPast && (act == 1 || act == 2)) {
                    if (rand() % 2 == 0) {
                        hadZneskodnen = true;
                        cout << "Had tě uštknul! Tvůj příští útok udělá jen 1 dmg.\n";
                        hadiPast = false;
                    } else {
                        cout << "Vyhnuln jsi se kousnutí hada.\n";
                    }
                }

                int dmg = 0;
                if (act == 2 && pl.mana > 0) { pl.mana--; dmg = pl.attack + 1; }
                else if (act == 1) dmg = pl.attack;

                if (hadZneskodnen) { dmg = 1; hadZneskodnen = false; }

                enemies[0].hp -= dmg;
                cout << "Úder nasadil " << dmg << " dmg nepříteli " << enemies[0].jmeno << "\n";
                if (enemies[0].hp <= 0) {
                    cout << enemies[0].jmeno << " Poražen!\n";
                    int g = dropGold(enemies[0].MiniBoss || enemies[0].Boss);
                    pl.gold += g;
                    pl.xp += 5;
                    cout << "+5 XP, +" << g << " gold.\n";
                    enemies.erase(enemies.begin());
                    levelUp(pl);
                }
            }
        }
        else {

            if (enemies[0].Boss && enemies[0].jmeno == "Mystifex") {
                int t = rand() % 3;
                if (t == 0) { ledovaPast = true; cout << "Mystifex položil mrazivou past.\n"; }
                else if (t == 1) { hadiPast = true; cout << "Mystifex položil past plnou hadů.\n"; }
                else { mlsnaPast = true; cout << "Mystifex položil mlsnou past.\n"; }
                int bonuses[] = {1, 2, 4, 6};
                int bonusDam = bonuses[rand() % 4];
                int dmg = 5 + bonusDam;
                pl.hp -= dmg;
                cout << "Mystifex tě uhodil za " << dmg << " dmg.\n";
                if (pl.hp <= 0) { smrt(); return; }
            }
            else {

                for (auto &e : enemies) {
                    pl.hp -= e.damage;
                    cout << e.jmeno << " Udeřil za " << e.damage << " dmg.\n";
                    if (pl.hp <= 0) { smrt(); return; }
                }
            }
        }
        playerStarts = !playerStarts;
    }

    cout << "Souboj byl ukončen. HP:" << pl.hp << "/" << pl.maxHp << ", Mana:" << pl.mana << "/" << pl.maxMana << "\n";
    rozdelovac();
}

void obchod(Hrdina &pl) {
    rozdelovac();
    cout << "--- Obchod ---\n";
    cout << "Máš: " << pl.gold << " goldů\n";
    cout << "1) Crazy Wolf (Full heal HP) (3 gold)\n";
    cout << "2) Řízek v chlebu (Zvýší max HP o 1) (6 gold)\n";
    cout << "3) Crazy MILCH shake (Zvýší útok o 1) (5 gold)\n";
    cout << "4) ULTRA Crejzáč (Zvýší max HP na 200) (100 gold)\n";
    cout << "5) Bageta stripsy (Zvýší útok o 5) (20 gold)\n";
    cout << "6) Zpet\n";
    int v; cin >> v;
    if (v == 1 && pl.gold >= 3) { pl.gold -= 3; pl.hp = pl.maxHp; cout << "HP doplněno.\n"; }
    else if (v == 2 && pl.gold >= 6) { pl.gold -= 6; pl.maxHp++; pl.hp = pl.maxHp; cout << "Max HP zvýšeno.\n"; }
    else if (v == 3 && pl.gold >=  5) { pl.gold -= 5; pl.attack++; cout << "Útočná síla zvýšena.\n"; }
    else if (v == 4 && pl.gold >= 200) { pl.gold -= 200; pl.maxHp = pl.maxHp =200; pl.hp = pl.maxHp; cout << "Max HP zvýšeno.\n"; }
    else if (v == 5 && pl.gold >= 20) { pl.gold -= 20; pl.attack= pl.attack+5; cout << "Útočná síla zvýšena o 5.\n"; }
    else if (v == 6){ cout << "Nashedanou\n"; }
    else cout << "Nedostatek goldů nebo špatná volba.\n";
    rozdelovac();
}

void hospoda(Hrdina &pl) {
    rozdelovac();
    cout << "--- Hospoda ---\n";
    if (pl.gold >= 5) { pl.gold -= 5; pl.hp = pl.maxHp; pl.mana = pl.maxMana;
        cout << "Odpočinek doplnil HP a manu.\n"; }
    else cout << "Potřebuješ 5 gold.\n";
    rozdelovac();
}

void knihovna(Hrdina &pl) {
    rozdelovac();
    cout << "--- Knihovna ---\n";
    if (pl.gold >= 3) { pl.gold -= 3; pl.xp += 10;
        cout << "Studium přidalo 10 XP.\n"; levelUp(pl); }
    else cout << "Potřebuješ 3 goldy.\n";
    rozdelovac();
}

void vesnice(Hrdina &pl) {
    rozdelovac();
    cout << "Vesnice - Máš přístup k službám.\n";
    while (true) {
        cout << "1) Obchod, 2) Hospoda, 3) Knihovna, 4) Stav hrdiny, 5) Vyrazit za dobrodružstvím > ";
        int v; cin >> v;
        if (v == 1) obchod(pl);
        else if (v == 2) hospoda(pl);
        else if (v == 3) knihovna(pl);
        else if (v == 4) playerInfo(pl);
        else break;
        rozdelovac();
    }
}

