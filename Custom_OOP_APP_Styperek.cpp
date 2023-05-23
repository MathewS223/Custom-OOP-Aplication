#include <iostream>
#include <string>
using namespace std;

class champion {
public:
  string name;
  int strength = 0;
  int agility = 0;
  int stamina = 0;
  int charisma = 0;
  int hp = 100;
  int points = 20;

  friend ostream &operator<<(ostream &os, const champion &champ) {
    os << "Nazwa: " << champ.name << endl;
    os << "Siła: " << champ.strength << endl;
    os << "Zwinność: " << champ.agility << endl;
    os << "Wytrzymałość: " << champ.stamina << endl;
    os << "Charyzma: " << champ.charisma << endl;
    os << "Punkty życia: " << champ.hp << endl;
    os << "Dostępne punkty: " << champ.points << endl;
    return os;
  }
};

int main() {
  champion myChampion;

  cout << "KREATOR POSTACI | Dostępne punkty: " << myChampion.points << endl;

  cout << "Nazwij swoją postać: ";
  cin >> myChampion.name;

  cout << myChampion << endl;

  int number_chosen;

  while (myChampion.points > 0) {
    cout << "Rozdysponuj punkty siły: ";
    cin >> number_chosen;

    if (number_chosen > myChampion.points) {
      cout << "Podano nieprawidłową wartość punktów. Podaj wartość ponownie."
           << endl;
      continue;
    }

    myChampion.strength = number_chosen;
    myChampion.points -= number_chosen;
    cout << myChampion << endl;

    if (myChampion.points == 0) {
      break;
    }

    cout << "Rozdysponuj punkty zwinności: ";
    cin >> number_chosen;

    if (number_chosen > myChampion.points) {
      cout << "Podano nieprawidłową wartość punktów. Podaj wartość ponownie."
           << endl;
      myChampion.points += myChampion.strength;
      continue;
    }

    myChampion.agility = number_chosen;
    myChampion.points -= number_chosen;
    cout << myChampion << endl;

    if (myChampion.points == 0) {
      break;
    }

    cout << "Rozdysponuj punkty wytrzymałości: ";
    cin >> number_chosen;

    if (number_chosen > myChampion.points) {
      cout << "Podano nieprawidłową wartość punktów. Podaj wartość ponownie."
           << endl;
      myChampion.points += myChampion.strength + myChampion.agility;
      continue;
    }

    myChampion.stamina = number_chosen;
    myChampion.points -= number_chosen;
    cout << myChampion << endl;

    if (myChampion.points == 0) {
      break;
    }

    cout << "Rozdysponuj punkty charyzmy: ";
    cin >> number_chosen;

    if (number_chosen > myChampion.points) {
      cout << "Podano nieprawidłową wartość punktów. Podaj wartość ponownie."
           << endl;
      myChampion.points +=
          myChampion.strength + myChampion.agility + myChampion.stamina;
      continue;
    }

    myChampion.charisma = number_chosen;
    myChampion.points -= number_chosen;
    cout << myChampion << endl;

    if (myChampion.points == 0) {
      break;
    }

    cout << "Rozdysponuj punkty życia: ";
    cin >> number_chosen;

    if (number_chosen > myChampion.points) {
      cout << "Podano nieprawidłową wartość punktów. Podaj wartość ponownie."
           << endl;
      myChampion.points += myChampion.strength + myChampion.agility +
                           myChampion.stamina + myChampion.charisma;
      continue;
    }

    myChampion.hp += 10 * number_chosen;
    myChampion.points -= number_chosen;
    cout << myChampion << endl;
  }

  // Dalszy kod gry...

  return 0;
}
