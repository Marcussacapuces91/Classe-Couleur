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
  const byte l = getLuminance();
  if (l == 0) {
    fRed = 1;
    fGreen = 1;
    fBlue = 1;
  }
  fRed = min(unsigned(fRed) * aLum / l, 255);
  fGreen = min(unsigned(fGreen) * aLum / l, 255);
  fBlue = min(unsigned(fBlue) * aLum / l, 255);
  return *this;    
}

Couleur& Couleur::setFiltre(const byte aRed, const byte aGreen, const byte aBlue) {
  fRed = min(unsigned(fRed) * aRed / 255, 255);
  fGreen = min(unsigned(fGreen) * aGreen / 255, 255);
  fBlue = min(unsigned(fBlue) * aBlue / 255, 255);
  return *this;    
}

const Couleur Couleur::BLACK(0x000000);
const Couleur Couleur::RED(0xFF0000);
const Couleur Couleur::YELLOW(0xFFFF00);
const Couleur Couleur::LIME(0x00FF00);
const Couleur Couleur::GREEN(0x008000);
const Couleur Couleur::BLUE(0x0000FF);
const Couleur Couleur::VIOLET(0xEE82EE);
const Couleur Couleur::WHITE(0xFFFFFF);
const Couleur Couleur::GRAY(0x808080);

// Pink color
const Couleur Couleur::PINK(0xFFC0CB);
const Couleur Couleur::LIGHT_PINK(0xFFB6C1);
const Couleur Couleur::HOT_PINK(0xFF69B4);
const Couleur Couleur::DEEP_PINK(0xFF1493);
const Couleur Couleur::MEDIUM_VIOLET_RED(0xC71585);
const Couleur Couleur::PALE_VIOLET_RED(0xDB7093);

// Orange color
const Couleur Couleur::LIGHT_SALMON(0xFFA07A);
const Couleur Couleur::CORAL(0xFF7F50);
const Couleur Couleur::TOMATO(0xFF6347);
const Couleur Couleur::ORANGE_RED(0xFF4500);
const Couleur Couleur::DARK_ORANGE(0xFF8C00);
const Couleur Couleur::ORANGE(0xFFA500);

// Purple color
const Couleur Couleur::DARK_MAGENTA(0x8B008B);
const Couleur Couleur::PURPLE(0x800080);

// Blue color
const Couleur Couleur::LIGHT_BLUE(0xADD8E6);

// Brown color
const Couleur Couleur::CORNSILK(0xFFF8DC);
const Couleur Couleur::BLANCHED_ALMOND(0xFFEBCD);
const Couleur Couleur::BISQUE(0xFFE4C4);
const Couleur Couleur::NAVAJO_WHITE(0xFFDEAD);
const Couleur Couleur::WHEAT(0xF5DEB3);
const Couleur Couleur::BURLY_WOOD(0xDEB887);
const Couleur Couleur::TAN(0xD2B48C);
const Couleur Couleur::ROSY_BROWN(0xBC8F8F);
const Couleur Couleur::SANDY_BROWN(0xF4A460);
const Couleur Couleur::GOLDENROD(0xDAA520);
const Couleur Couleur::DARK_GOLDENROD(0xB8860B);
const Couleur Couleur::PERU(0xCD853F);
const Couleur Couleur::CHOCOLATE(0xD2691E);
const Couleur Couleur::SADDLE_BROWN(0x8B4513);
const Couleur Couleur::SIENNA(0xA0522D);
const Couleur Couleur::BROWN(0xA52A2A);
const Couleur Couleur::MAROON(0x800000);

