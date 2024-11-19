#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of movie (colored image)
//   durationCredits: duration in seconds of credit (black/white image)
//   fps: frames per second
//   unit: Unit of the output value. It could be 'bt' (byte), 'ko' (kilobits), 'mo' (megabits), 'go' (gigabits)
// Return value:
//   video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Vérification des paramètres
    if (w <= 0 || h <= 0 || durationMovie < 0 || durationCredits < 0 || fps <= 0 || unit == NULL) {
        return 0;
    }

    // Taille d'une image colorée en bytes
    float sizePerFrameColored = w * h * 3; // RGB: 3 bytes par pixel
    // Taille d'une image noir et blanc en bytes
    float sizePerFrameBW = w * h; // 1 byte par pixel

    // Nombre total de frames pour le film et les crédits
    int totalFramesMovie = durationMovie * fps;
    int totalFramesCredits = durationCredits * fps;

    // Taille totale des frames
    float totalSizeBytes = (totalFramesMovie * sizePerFrameColored) + (totalFramesCredits * sizePerFrameBW);

    // Conversion en fonction de l'unité
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBytes; // En bytes
    } else if (strcmp(unit, "ko") == 0) {
        return (totalSizeBytes * 8) / 1024; // En kilobits (1 byte = 8 bits, 1 kilobit = 1024 bits)
    } else if (strcmp(unit, "mo") == 0) {
        return (totalSizeBytes * 8) / (1024 * 1024); // En mégabits
    } else if (strcmp(unit, "go") == 0) {
        return (totalSizeBytes * 8) / (1024 * 1024 * 1024); // En gigabits
    } else {
        return 0; // Unité non valide
    }
}
