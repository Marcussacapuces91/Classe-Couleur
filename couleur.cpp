#include "couleur.h"


Couleur::Couleur() :
  fRed(0),
  fGreen(0),
  fBlue(0) {
}

Couleur::Couleur(const byte aRed, const byte aGreen, const byte aBlue) :
  fRed(aRed),
  fGreen(aGreen),
  fBlue(aBlue) {
}

Couleur::Couleur(const unsigned long aRVB) :
  fRed((aRVB >> 16) & 0xFF), 
  fGreen((aRVB >> 8) & 0xFF), 
  fBlue(aRVB & 0xFF) {
}

byte Couleur::getLuminance() const {
  return (unsigned(fRed) * 3 + unsigned(fGreen) * 6  + unsigned(fBlue)) / 10;  
}

Couleur& Couleur::setLuminance(const byte aLum) {
  const unsigned l = getLuminance();
  if (l == 0) {
    fRed = 1;
    fGreen = 1;
    fBlue = 1;
  }
  fRed = unsigned(fRed) * aLum / l;
  fGreen = unsigned(fGreen) * aLum / l;
  fBlue = unsigned(fBlue) * aLum / l;
  return *this;    
}

const Couleur Couleur::BLACK(0x000000);
const Couleur Couleur::MAROON(0x800000);
const Couleur Couleur::RED(0xFF0000);
const Couleur Couleur::ORANGE(0xFFA500);
const Couleur Couleur::YELLOW(0xFFFF00);
const Couleur Couleur::GREEN(0x008000);
const Couleur Couleur::BLUE(0x0000FF);
const Couleur Couleur::VIOLET(0xEE82EE);
const Couleur Couleur::WHITE(0xFFFFFF);
const Couleur Couleur::GRAY(0x808080);

