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

Couleur Couleur::changerLuminance(const byte aLum) const {
  const unsigned l = (fRed * 3 + fGreen * 6  + fBlue) / 10;
  Couleur r(unsigned(fRed) * aLum / l, unsigned(fGreen) * aLum / l, unsigned(fBlue) * aLum / l);
  return r;    
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

