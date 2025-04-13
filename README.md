#include <iostream>
using namespace std;

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
      cout << "Hromotluk muze aktivovat utok ktery utoci na vsechny nepritele v jeho blizkosti, tento utok ubere vsem nepretalum 5hp(stoji 3 many)--(splash damage)\n";
      cout << "Hromotluk se muze ovsem behem hry naucit nove utoky ci vylepsit ty zakladni\n";
      break;
  case 3:
      cout << "vybrali jste postavu Gundolf";
      cout << endl << endl;
      cout << "pocet hp - 110\n";
      cout << "kapacita many - 40\n";
      cout << endl;
      cout << "schopnosti: \n";
      //cout <<
      //cout <<
      //cout <<
      //cout <<
      //cout <<
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
}

 
