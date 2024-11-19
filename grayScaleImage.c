#include "config/grayScaleImage.h"

// Parameters:
//   w: width of the image
//   h: height of the image
// Return value:
//   grayScale size of the image Bitmap (in bytes)
float grayScaleImage(int w, int h) {
    // Vérifier que les dimensions sont valides
    if (w <= 0 || h <= 0) {
        return 0; // Retourne 0 si les dimensions sont invalides
    }

    // Calculer la taille de l'image en bytes
    return (float)(w * h);
}
