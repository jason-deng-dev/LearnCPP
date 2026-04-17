#include <string>
#include <iostream>


struct Monster {
  enum MonsterType {
    ogre,
  dragon,
  orc,
  giantSpider,
  slime,

  };
  MonsterType type{};
  std::string name{};
  int health{};
};

constexpr std::string_view getMonsterType(Monster::MonsterType type) {
  switch (type) {
    case Monster::ogre:
      return "Ogre";
    case Monster::dragon:
      return "Dragon";
    case Monster::orc:
      return "Orc";
    case Monster::giantSpider:
      return "Giant Spider";
    case Monster::slime:
      return "Slime";
    default:
      return "???";
  }
}


void printMonster(Monster& m) {
  std::cout << "This " << getMonsterType(m.type) << " named " << m.name
            << " has " << m.health << " hp. \n";
}

int main() {
  Monster ogre{Monster::ogre, "Torg", 145};
  Monster slime{Monster::giantSpider, "BLurp", 23};
  printMonster(ogre);
  printMonster(slime);

  return 0;
}
