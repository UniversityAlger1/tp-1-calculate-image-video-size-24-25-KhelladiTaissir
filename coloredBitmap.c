#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' (bits), 'ko' (kilobits), 'mo' (megabits), 'go' (gigabits)
// Return value:
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Vérifier que les dimensions sont valides
    if (w <= 0 || h <= 0 || unit == NULL) {
        return 0;
    }

    // Taille totale en octets (3 bytes par pixel pour RGB)
    float sizeInBytes = (float)(w * h * 3);

    // Conversion en fonction de l'unité
    if (strcmp(unit, "bt") == 0) {
        // Convertir en bits (1 byte = 8 bits)
        return sizeInBytes * 8;
    } else if (strcmp(unit, "ko") == 0) {
        // Convertir en kilobits (1 kilobit = 1024 bits)
        return (sizeInBytes * 8) / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        // Convertir en mégabits (1 mégabit = 1024 * 1024 bits)
        return (sizeInBytes * 8) / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        // Convertir en gigabits (1 gigabit = 1024 * 1024 * 1024 bits)
        return (sizeInBytes * 8) / (1024 * 1024 * 1024);
    } else {
        // Si l'unité est inconnue, retourner 0
        return 0;
    }
}
