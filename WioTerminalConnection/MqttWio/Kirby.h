#ifndef _TFT_eSPI_
#define _TFT_eSPI_
#include "TFT_eSPI.h"
#endif

// Kirby is centered on the screen

#define KIRBY_CENTER_X 160
#define KIRBY_CENTER_Y 120
#define KIRBY_RADIUS 65

#define LEFT_FOOT_X (KIRBY_CENTER_X - (KIRBY_RADIUS*4/5))
#define RIGHT_FOOT_X (KIRBY_CENTER_X + (KIRBY_RADIUS*4/5))
#define FOOT_Y (KIRBY_CENTER_Y + (KIRBY_RADIUS*4/5))
#define FOOT_RADIUS_X (KIRBY_RADIUS*2/3)
#define FOOT_RADIUS_Y (KIRBY_RADIUS/3)

#define LEFT_HAND_X (KIRBY_CENTER_X - KIRBY_RADIUS)
#define RIGHT_HAND_X (KIRBY_CENTER_X + KIRBY_RADIUS)
#define HAND_Y (KIRBY_CENTER_Y - (KIRBY_RADIUS/4))
#define HAND_RADIUS_X FOOT_RADIUS_X
#define HAND_RADIUS_Y (HAND_RADIUS_X/2)

#define LEFT_EYE_X (KIRBY_CENTER_X - (KIRBY_RADIUS/3))
#define RIGHT_EYE_X (KIRBY_CENTER_X + (KIRBY_RADIUS/3))
#define EYE_Y (KIRBY_CENTER_Y - (KIRBY_RADIUS*2/5))
#define EYE_RY (KIRBY_RADIUS/3)
#define EYE_RX (EYE_RY/3)

#define LEFT_SHINE_X (LEFT_EYE_X + 2)
#define RIGHT_SHINE_X (RIGHT_EYE_X + 2)
#define SHINE_Y (EYE_Y - (EYE_RY/2))
#define SHINE_RX (EYE_RX/2)
#define SHINE_RY (EYE_RY/2)

#define LEFT_BLUSH_X (LEFT_EYE_X - (EYE_RX + BLUSH_RX))
#define RIGHT_BLUSH_X (RIGHT_EYE_X + (EYE_RX + BLUSH_RX))
#define BLUSH_Y (EYE_Y + EYE_RY)
#define BLUSH_RX SHINE_RY
#define BLUSH_RY SHINE_RX

#define MOUTH_X (KIRBY_CENTER_X)
#define MOUTH_Y (KIRBY_CENTER_Y + 10)
#define MOUTH_RADIUS (KIRBY_RADIUS/8)

class Kirby {
  private:
      TFT_eSPI tft;
  
  public:
      Kirby(TFT_eSPI screen) {
        tft = screen;
      }

      void stand() {
        // Left foot
        tft.fillEllipse(LEFT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, TFT_RED);

        // Right foot
        tft.fillEllipse(RIGHT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, TFT_RED);

        // Left hand
        tft.fillEllipse(LEFT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, TFT_MAGENTA);

        // Right hand
        tft.fillEllipse(RIGHT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, TFT_MAGENTA);

        // Body
        tft.fillCircle(KIRBY_CENTER_X, KIRBY_CENTER_Y, KIRBY_RADIUS, TFT_MAGENTA);

        // Left eye (black)
        tft.fillEllipse(LEFT_EYE_X, EYE_Y, EYE_RX, EYE_RY, TFT_BLACK);

        // Right eye (black)
        tft.fillEllipse(RIGHT_EYE_X, EYE_Y, EYE_RX, EYE_RY, TFT_BLACK);

        // Left shine
        tft.fillEllipse(LEFT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, TFT_WHITE);

        // Right shine
        tft.fillEllipse(RIGHT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, TFT_WHITE);

        // Left blush
        tft.fillEllipse(LEFT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, TFT_RED);

        // Right blush
        tft.fillEllipse(RIGHT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, TFT_RED);

        // Mouth
        tft.fillCircle(MOUTH_X, MOUTH_Y, MOUTH_RADIUS, TFT_BLACK);
      }

      // void walk() {
      //   leftFootForward();
      //   delay(100);
      //   rightFootForward();
      //   delay(100);
      // }

      // void rightFootForward() {
      //     // Left foot
      //     tft.fillEllipse(LEFT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, TFT_RED);

      //     // Left hand
      //     tft.fillEllipse(LEFT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, TFT_MAGENTA);

      //     // Right hand
      //     tft.fillEllipse(RIGHT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, TFT_MAGENTA);

      //     // Body
      //     tft.fillCircle(KIRBY_CENTER_X, KIRBY_CENTER_Y, KIRBY_RADIUS, TFT_MAGENTA);

      //     // Right foot
      //     tft.fillEllipse(RIGHT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, TFT_RED);

      //     // Left eye (black)
      //     tft.fillEllipse(LEFT_EYE_X, EYE_Y, EYE_RX, EYE_RY, TFT_BLACK);

      //     // Right eye (black)
      //     tft.fillEllipse(RIGHT_EYE_X, EYE_Y, EYE_RX, EYE_RY, TFT_BLACK);

      //     // Left shine
      //     tft.fillEllipse(LEFT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, TFT_WHITE);

      //     // Right shine
      //     tft.fillEllipse(RIGHT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, TFT_WHITE);

      //     // Left blush
      //     tft.fillEllipse(LEFT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, TFT_RED);

      //     // Right blush
      //     tft.fillEllipse(RIGHT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, TFT_RED);

      //     // Mouth
      //     tft.fillCircle(MOUTH_X, MOUTH_Y, MOUTH_RADIUS, TFT_BLACK);
      // }

      // void leftFootForward() {
      //     // Right foot
      //     tft.fillEllipse(RIGHT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, TFT_RED);

      //     // Left hand
      //     tft.fillEllipse(LEFT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, TFT_MAGENTA);

      //     // Right hand
      //     tft.fillEllipse(RIGHT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, TFT_MAGENTA);

      //     // Body
      //     tft.fillCircle(KIRBY_CENTER_X, KIRBY_CENTER_Y, KIRBY_RADIUS, TFT_MAGENTA);

      //     // Left foot
      //     tft.fillEllipse(LEFT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, TFT_RED);

      //     // Left eye (black)
      //     tft.fillEllipse(LEFT_EYE_X, EYE_Y, EYE_RX, EYE_RY, TFT_BLACK);

      //     // Right eye (black)
      //     tft.fillEllipse(RIGHT_EYE_X, EYE_Y, EYE_RX, EYE_RY, TFT_BLACK);

      //     // Left shine
      //     tft.fillEllipse(LEFT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, TFT_WHITE);

      //     // Right shine
      //     tft.fillEllipse(RIGHT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, TFT_WHITE);

      //     // Left blush
      //     tft.fillEllipse(LEFT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, TFT_RED);

      //     // Right blush
      //     tft.fillEllipse(RIGHT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, TFT_RED);

      //     // Mouth
      //     tft.fillCircle(MOUTH_X, MOUTH_Y, MOUTH_RADIUS, TFT_BLACK);
      // }
};