#include <iostream>
using namespace std;

struct player{
    int hp = maxHp;
    int maxHp;
    if(vyber==1){
        maxHp=90;
    }else if(vyber==2){
        maxHp=150;
    }else{
        maxHp=110;
        }
    int mana;
    int maxMana;
    if(vyber==1){
        maxMana=50;
    }else if(vyber==2){
        maxMana=30;
    }else{
        maxMana=40;
        }
    bool zmrazen = false;
    bool otraven = false;
};

struct Mystifex{

    int hp = 200;
};

void MystifexFight(){
    Mystifex();
    string pasti[] = {"mraziva", "hadi", "mlsna"};

    while (player.hp > 0 && mystifex.hpHidden > 0) {
        cout << "\nMystifexova HP: ??? | Tva HP: " << player.hp << endl;

        int pastType = rand() % 3;
        cout << "Mystifex poklada past: " << pasti[pastType] << endl;

        int bonus = 0;
        int roll = rand() % 4;
        switch (roll) {
            case 0: bonus = 2;
             break;
            case 1: bonus = 4;
             break;
            case 2: bonus = 6;
             break;
            case 3: bonus = 1;
             break;
        }
        int totalDamage = 5 + bonus;
        player.hp -= totalDamage;
        cout << "Mystifex utoci za " << totalDamage << " poskozeni!\n";

        if (player.hp <= 0) break;

        if (player.frozen) {
            cout << "Jsi zmrzly. Tohle kolo nic nemuzes delat.\n";
            player.frozen = false;
        } else {
            cout << "Tve kolo. Chceš zautocit (a) nebo snist past (s)? ";
            char choice;
            cin >> choice;

            if (choice == 's' && pastType == 2) {
                cout << "Snedl jsi dobrutku. Healnul jsi se o 10 HP, prisel jsi o 10 max HP.\n";
                player.hp += 10;
                player.maxHp -= 10;
                if (player.hp > player.maxHp) player.hp = player.maxHp;
            } else {
                int dmg = player.poisoned ? 1 : 10;
                mystifex.hpHidden -= dmg;
                cout << "Utcis na Mystifexe za " << dmg << " poskozeni.\n";
            }
        }

        if (pastType == 0) {
            cout << "Mraziva past se aktivuje. Zmrzl jsi.\n";
            player.frozen = true;
        } else if (pastType == 1) {
            if (rand() % 2 == 0) {
                cout << "Had te ustknul! Tve utoky budou slabe.\n";
                player.poisoned = true;
            } else {
                cout << "Had si te nevsima, past zustava.\n";
            }
        } else if (pastType == 2 && choice != 'p') {
            cout << "Mystifex snedl svou vlastni past! Leci se o 10 HP.\n";
            mystifex.hpHidden += 10;
        }
    }

    if (player.hp <= 0) {
        cout << "\nZemrel jsi. Mystifex vitezi.\n";
    } else {
        cout << "\nZvitezil jsi. Mystifex prohral\n";
    }
}

void Bambal(){
    int vybeR;
 cout << "jaky utok chces provest: \n";
 cout << "1-obycejny utok; -2hp=1 mana(single attack)\n";
 cout << "2-sance na vyblokovani kouzlo opponenta; 35% sance na uspech= 5 many\n";
 cout << "3-stit; 10 many(muzes pouzit jednou za pet kol\n";
 cin >> vybeR;

}
void Hromotluk(){
    int vybeR;
  cout << "jaky utok chces provest: \n";
  cout << "1-utok mecem hrdosti; -3hp=1 mana(single attack)\n";
  cout << "2-aktivovat vetsi ostrost mece hrdosti; -15hp=8 many(single attack)\n";
  cout << "3-horlavost na meci hrdosti; -8hp a nepritel mu v pristim tahu ubere jakymkoliv utokem o 40% min hp(stoji 10 many)--(single attack)\n";
  cout << "4-utok na vsechny v jeho okoli; -5hp=3 many--(area damage)\n";
  cin >> vybeR;
}

void Gundolf(){
      cout << "jaky utok chces provest: \n";
      cout << "1-zakladni utok; -2hp=1mana(single attack)\n";
      cout << "2-double utok; -2x2hp=2mana(single attack)\n";
      cout << "3-jed na kudle; -4x4hp=4 many(single attack)\n";
      cout << "4-sekera; -10hp=8many(are damage)\n";
}
void bazina(){
    int odpoved;
    cout << "Nez jsi stihl zaklepat na chatku tak se sami otevreli dvere dovnitr.   \n";
    cout << "Kdyz jsi vesel dovnitr tak te privitala carodejnice a ma pro tebe navrh\n";
    cout << "Potrebuje do sveho lektvaru urcite suroviny. Kdyz ji tyto suroviny sezenes tak te odmeni jak penezma tak zkusenostma do boje\n";
    cout << "Beres jeji nabidku?\n";
    cout << "ano-1 / ne-0\n";
    cin >> odpoved;
    if (odpoved==1){
        cout << "Zde je seznam veci co carodejnice potrebuje: \n";
        cout << "Hrst kouzelneho rozmarajna ==> naleznes u Babky korenarky v blizkem meste.\n";
        cout << "Brasnu strelneho cerneho prachu ===> naleznes u zbrojnika v blizkem meste.\n" ;
        cout << "Jednu lahev nejsilnejsiho rumu na trhu ==> naleznes v hospode v blizkem meste.\n" ;
        cout << "Vytazek jedu z masozravky == > naleznes u zahradnika v blizkem meste.\n";
    }else
     cout << "Carodnejnice ti rekla ze ji jeste budes potrebovat ze uvidis.\n";
}
void bazinkADuel(){
   int bazinkA;
         cout << "Kdyz jsi prochazel bazinou tak z poza stromu na tebe vyskocil TRIPI TROPA. Co udelas?\n";
         cout << "1- Zaplatis mu 80 stribrnych.\n";
         cout << "2- Das s nim duel.\n";
         cin >> bazinkA;
    if(bazinkA == 1){
        if (stribrny <80){
            cout << "nedostatek stribrnych";
        }else {
         stribrny - 80;
         bazina();
        }
    }else
     if (vyber==1){
        Bambal();
        }else if (vyber==2){
         Hromotluk();
        }else
          Gundolf();



}
void rozdelovac(){
  cout << "________________________________________________________________________________________________________________________\n";

}
void rozcesti(){
    rozdelovac();
    cout<< "Jsi zpet na rozcesti\n";
    int rozcestiVyber=0;
     cout << "1- muzes jit po ceste doprava smer mesto.\n";
     cout << "2- muzes jit rovne smer bazina.\n";
     cout << "3- muzes jit do leva smer cerne skaly.\n";
     cin >> rozcestiVyber;
      rozdelovac();
     switch(rozcestiVyber){
     case 1:
int smer1;
         cout << "Dosel jsi k hranicim mesta a straznici ti rekli ze vstup do mesta stoji 40 stribrnych. Co udelas?\n" ;
         cout << "1- Zaplatis za vstup.\n";
         cout << "2- Vratis se na rozcesti.\n";
         cin >> smer1;
        if (smer1 == 1){
         cout << "Straze te pustili do mesta.\n";
        }else if (smer1 ==2){
          rozcesti();
           }else {
           cout << "Vyber z moznosti 1 nebo 2.\n";
           }
        break;
     case 2:
int smer2;
         cout << "Dosel jsi do baziny. Pred sebou vidis malou chatku a z jejiho komina se kouri. Co udelas?\n" ;
         cout << "1- Pujdes do chatky.\n";
         cout << "2- Vratis se na rozcesti.\n";
        break;
     case 3:
int smer3;
        //cout <<;
        //cout <<;
     default:
         cout<< "vyberte cislo v rozmezi 1-3";
     }
}
void mesto(){
}
void aktualniStav(){
  cout << stribrny << endl;
  cout << zlaty << endl;

}
int main(){
  cout<< "vitam te v tomto svete jmenem tralalelo tralala\n";
 int spokojenost;
  cout << "predtim nez zacnes hrat tak si musis vybrat za kterou postavu budes hrat: \n";
  cout << "1 - mag zvany Bambal\n";
  cout << "2 - ritir zvany Hromotluk\n";
  cout << "3 - trpaslik zvany Gundolf\n";

 do{
 if (spokojenost == 0){
    cout << "opakujte vyber postavy: \n";
 }
  cin >> vyber;
  cout << endl;
 switch(vyber){
  case 1:
      cout << "Vybrali jste postavu Bambal";
      cout << endl << endl;
      cout << "pocet hp - 90\n";
      cout << "kapacita many -- 50\n";
      cout << endl;
      cout << "schopnosti: \n";
      cout << "Bambaluv obycejny utok je jeho paprsek ocistce, ktery ubira 2hp (stoji 1 manu)--(single attack)";
      cout << "Bambal ma 35% sanci na to vyblokovat jakekoliv kouzlo mirene na neho (stoji 5 many)\n";
      cout << "Bambal muze jednou za 3 tahy snizit silu utoku jeho nepritele o 80% na jedno kolo (stoji 8 many)\n";
      cout << "Bambal muze jednou za pet kol aktivovat stit, tento stit se znici na jednu ranu ale ta rana neubere ani 1 hp Bambalovi (stoji 10 many)\n";
      cout << "Bambal se muze ovsem behem hry naucit nove kouzla ci vylepsit ty zakladni\n";
       rozdelovac();
    break;
  case 2:
      cout << "Vybrali jste postavu Hromotluk";
      cout << endl << endl;
      cout << "pocet hp - 150\n";
      cout << "kapacita many - 30\n";
      cout << endl;
      cout << "schopnosti: \n";
      cout << "Hromotlukuv zakladni utok je utok mecem hrdosti ktery ubira 3hp (stoji 1 manu)--(single attack)\n";
      cout << "Hromotluk muze jednou za tri kola aktivovat vetsi ostrost mece hrdosti a ubrat jednim utokem 15hp(stoji 8 many)--(single attack)\n";
      cout << "Hromotluk muze aktivovat horlavost na meci hrdosti a kdyz uderi nepritele tak mu ubere 8hp a nepritel mu v pristim tahu ubere jakymkoliv utokem o 40% min hp(stoji 10 many)--(single attack)\n";
      cout << "Hromotluk muze aktivovat utok ktery utoci na vsechny nepritele v jeho blizkosti, tento utok ubere vsem nepretalum 5hp(stoji 3 many)--(area damage)\n";
      cout << "Hromotluk se muze ovsem behem hry naucit nove utoky ci vylepsit ty zakladni\n";
       rozdelovac();
    break;
  case 3:
      cout << "vybrali jste postavu Gundolf";
      cout << endl << endl;
      cout << "pocet hp - 110\n";
      cout << "kapacita many - 40\n";
      cout << endl;
      cout << "schopnosti: \n";
      cout << "Gundolfuv zalkadni utok je bodnuti jeho kudlou ktera ubira 2hp (stoji 1 manu)--(single attack)\n";
      cout << "Gundolf muze jednou za dve kola aktivovat double utok kudlou a tim ubere 2x2hp (stoji 2 many)--(single attack)\n";
      cout << "Gundolf muze jednou za tri kola aktivovat jed na kudle ktera ubira 4x4hp (stoji 4 many)--(single attack)\n";
      cout << "Gundolf muze jednou za ctyri kola aktivovat sekeru kterou muze utocit na vsechny nepratele v mistosti, a vsem ubere za 10hp(stoji 8many)--(area damage)\n";
      cout << "Gundolf se muze ovsem behem hry naucit nove utoky ci vylepsit zalkadni\n";
       rozdelovac();
    break;

  default:
    cout<< "vyberte cislo v rozmezi 1-3";
  }

    cout << "jste spokojeni s vyberem (ano - 1/ne - 0)\n";
    cin >> spokojenost;
    cout << endl;
    if(spokojenost <0 || spokojenost >1){
    cout << "spatne zadana hodnota!!"<< endl;
    }
 }while(spokojenost == 0);
 int zybtecnyDotaz;
  cout << "jsi pripraven zacit  hrat?\n";
  cin >> zybtecnyDotaz;
      rozdelovac();
     cout << "doufam ze ano jelikoz nemas na vyber\n" ;

     cout << "Vcera jsi byl v hospode a od tretiho dzbanu piva si nic nepamatujes. Tvym prvnim ukolem je zjistit co se vcera vse stalo.\n";
     cout << "Probudil jsi se v lese na rozcesti.\n";
     cout << "Mas u sebe 1 zlaty a 50 stribrnych (1 zlaty = 100 stribrnych), mas full hp a full manu.\n";
      rozdelovac();
 int rozcestiVyber=0;
     cout << "1- muzes jit po ceste doprava smer mesto.\n";
     cout << "2- muzes jit rovne smer bazina.\n";
     cout << "3- ;muzes jit do leva smer cerne skaly.\n";
     cin >> rozcestiVyber;
      rozdelovac();
     switch(rozcestiVyber){
     case 1:
int smer1;
         cout << "Dosel jsi k hranicim mesta a straznici ti rekli ze vstup do mesta stoji 40 stribrnych. Co udelas?\n" ;
         cout << "1- Zaplatis za vstup.\n";
         cout << "2- Vratis se na rozcesti.\n";
         cin >> smer1;
        if (smer1 == 1){
         mesto();
        }else if (smer1 ==2){
          rozcesti();
           }else {
           cout << "Vyber z moznosti 1 nebo 2.\n";
           }
        break;
     case 2:
int smer2;
         cout << "Dosel jsi do baziny. Pred sebou vidis malou chatku a z jejiho komina se kouri. Co udelas?\n" ;
         cout << "1- Pujdes do chatky.\n";
         cout << "2- Vratis se na rozcesti.\n";
         cin >> smer2;
         if (smer2 == 1){
         bazinkADuel();

    }else if (smer2 ==2){
          rozcesti();
           }else{
             cout << "vyberte jednu z moznosti";
           }
        break;
     case 3:
int smer3;
        cout << "Dosel jsi az k cernym skalam. Před sebou vidis hluboky utes. Most pres tento utes je polorozpadli a cesta pres nej je prilis nebezpecna. Tudiz musis najit jinou cestu jak se dostat pres utes.\n";

     default:
      cout<< "vyberte cislo v rozmezi 1-3";
      }
     }

