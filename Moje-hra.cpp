#include <iostream>
using namespace std;

void rozdelovac(){
  cout << "________________________________________________________________________________________________________________________\n";

}
void rozcesti(){
     int vyber2;
     cout << "1- muzes jit po ceste doprava smer mesto.\n";
     cout << "2- muzes jit rovne smer bazina.\n";
     cout << "3- muzes jit do leva smer cerne skaly.\n";
     cin >> vyber2;
     }

int main(){
  cout<< "vitam te v tomto svete jmenem tralalelo tralala\n";
 int vyber=0, spokojenost;
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
     cout << "Mas u sebe 1 zlaty a 20 stribrnych (1 zlaty = 100 stribrnych), mas full hp a full manu.\n";
      rozdelovac();
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
          cout << "Jsi zpet na rozcesti.\n";
          rozcesti();
           }else {
           cout << "Vyber z moznosti 1 nebo 2.\n";
           }
        break;
     case 2:
         //cout << ;
         //cout << ;
        break;
     case 3:
        //cout <<;
        //cout <<;
     default:
         cout<< "vyberte cislo v rozmezi 1-3";
     }
}
