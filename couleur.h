#ifndef __COULEUR_H__
#define __COULEUR_H__

#include "Arduino.h"   // Arduino defines

class Couleur {

private:
  byte fRed;
  byte fGreen;
  byte fBlue;
  
public:
  static const Couleur BLACK;
  static const Couleur MAROON;
  static const Couleur RED;
  static const Couleur ORANGE;
  static const Couleur YELLOW;
  static const Couleur GREEN;
  static const Couleur BLUE;
  static const Couleur VIOLET;
  static const Couleur WHITE;
  static const Couleur GRAY;

  Couleur();
  Couleur(const byte aRed, const byte aGreen, const byte aBlue);
  Couleur(const unsigned long aRVB);
  
  byte getLuminance() const;
  Couleur& setLuminance(const byte aLum);
  
  template <int R, int G, int B>
  static void afficher(const Couleur& aCouleur);
  
  template <int R, int G, int B>
  static void varier(const Couleur& aCouleur, const Couleur& bCouleur, const unsigned aDuree);
};

template <int R, int G, int B>
void Couleur::afficher(const Couleur& aCouleur) {
  analogWrite(R, aCouleur.fRed);
  analogWrite(G, aCouleur.fGreen);
  analogWrite(B, aCouleur.fBlue);
}

template <int R, int G, int B>
void Couleur::varier(const Couleur& aCouleur, const Couleur& bCouleur, const unsigned aDuree) {
  unsigned duree;
  unsigned delai;
  
  if (aDuree > 1000) {
    duree = aDuree;
    delai = 1000;
  } else if (aDuree > 100) {
    duree = aDuree * 10;
    delai = 100;
  } else if (aDuree > 10) {
    duree = aDuree * 100;
    delai = 10;
  } else {
    duree = aDuree * 1000;
    delai = 1;
  }
  
  for (unsigned coef = duree; coef > 0; --coef) {
    const int r = ((unsigned long)(aCouleur.fRed) * coef + (unsigned long)(bCouleur.fRed) * (duree - coef)) / duree;
    const byte v = ((unsigned long)(aCouleur.fGreen) * coef + (unsigned long)(bCouleur.fGreen) * (duree - coef)) / duree;
    const byte b = ((unsigned long)(aCouleur.fBlue) * coef + (unsigned long)(bCouleur.fBlue) * (duree - coef)) / duree;
if (false) {
    Serial.print(coef, HEX);
    Serial.print(" : (");
    Serial.print(aCouleur.fRed, HEX);
    Serial.print("->");
    Serial.print(bCouleur.fRed, HEX);
    Serial.print("),(");
    Serial.print(aCouleur.fGreen, HEX);
    Serial.print("->");
    Serial.print(bCouleur.fGreen, HEX);
    Serial.print("),(");
    Serial.print(aCouleur.fBlue, HEX);
    Serial.print("->");
    Serial.print(bCouleur.fBlue, HEX);
    Serial.print(") : ");
    Serial.print(r, HEX);
    Serial.print(",");
    Serial.print(v, HEX);
    Serial.print(",");
    Serial.println(b, HEX);
}
    afficher<R,G,B>(Couleur(r,v,b));
    delay(delai);      
  }
}

#endif // __COULEUR_H__
