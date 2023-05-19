/*
    This file holds the information for drawing Kirby on the Wio Terminal screen. There are many dimensions and colors defined.
    Most of the dimensions are scalable by changing the center point of Kirby's body and the radius of it. When Kirby is too small,
    some features will not appear, so be aware of that.

    Currently, Kirby is medium sized for the screen and is centered on the center point of the screen. The dimensions of the
    Wio Terminal LCD screen is 320 pixels by 240 pixels.

    The Kirby class has only one attribute of type TFT_eSPI. This is the variable that controls the LCD screen. It needs to be stored,
    otherwise we cannot draw Kirby on the screen.

    Kirby is capable of doing the following actions:
      - sleep: Kirby's default state is sleeping. Their eyes are closed, and there are "zzz"s on the screen;
      - stand: Kirby is standing with their arms around their body (as best as could be done given the drawing limitations);
      - start singing: Kirby opens their mouth and sings "La la la!" when there is music playing;
      - stop singing: Kirby closes their mouth and stops singing
*/

#ifndef _TFT_eSPI_
#define _TFT_eSPI_
#include "TFT_eSPI.h"
#endif

// Colors
#define BACKGROUND TFT_DARKCYAN
#define BODY_COLOR TFT_MAGENTA
#define FOOT_COLOR TFT_RED
#define EYE_COLOR TFT_BLACK
#define SHINE_COLOR TFT_WHITE
#define BLUSH_COLOR TFT_RED
#define MOUTH_COLOR TFT_BLACK

// Kirby is centered on the screen
// Body proportions
#define KIRBY_CENTER_X 160
#define KIRBY_CENTER_Y 120
#define KIRBY_RADIUS 65
#define SLEEP_BODY_RX KIRBY_RADIUS + 10
#define SLEEP_BODY_RY KIRBY_RADIUS - 10

// Feet proportions
#define LEFT_FOOT_X (KIRBY_CENTER_X - (KIRBY_RADIUS*4/5))
#define RIGHT_FOOT_X (KIRBY_CENTER_X + (KIRBY_RADIUS*4/5))
#define FOOT_Y (KIRBY_CENTER_Y + (KIRBY_RADIUS*4/5))
#define FOOT_RADIUS_X (KIRBY_RADIUS*2/3)
#define FOOT_RADIUS_Y (KIRBY_RADIUS/3)

// Hand proportions
#define LEFT_HAND_X (KIRBY_CENTER_X - KIRBY_RADIUS)
#define RIGHT_HAND_X (KIRBY_CENTER_X + KIRBY_RADIUS)
#define HAND_Y (KIRBY_CENTER_Y - (KIRBY_RADIUS/4))
#define HAND_RADIUS_X FOOT_RADIUS_X
#define HAND_RADIUS_Y (HAND_RADIUS_X/2)

// Black of the eye proportions
#define LEFT_EYE_X (KIRBY_CENTER_X - (KIRBY_RADIUS/3))
#define RIGHT_EYE_X (KIRBY_CENTER_X + (KIRBY_RADIUS/3))
#define EYE_Y (KIRBY_CENTER_Y - (KIRBY_RADIUS*2/5))
#define EYE_RY (KIRBY_RADIUS/3)
#define EYE_RX (EYE_RY/3)
#define SLEEP_L_EYE_X LEFT_EYE_X - (EYE_RY/2)
#define SLEEP_R_EYE_X RIGHT_EYE_X - (EYE_RY/2)

// Shine of the eye proportions
#define LEFT_SHINE_X (LEFT_EYE_X + 2)
#define RIGHT_SHINE_X (RIGHT_EYE_X + 2)
#define SHINE_Y (EYE_Y - (EYE_RY/2))
#define SHINE_RX (EYE_RX/2)
#define SHINE_RY (EYE_RY/2)

// Blush proportions
#define LEFT_BLUSH_X (LEFT_EYE_X - (EYE_RX + BLUSH_RX))
#define RIGHT_BLUSH_X (RIGHT_EYE_X + (EYE_RX + BLUSH_RX))
#define BLUSH_Y (EYE_Y + EYE_RY)
#define BLUSH_RX SHINE_RY
#define BLUSH_RY SHINE_RX

// Mouth proportions
#define MOUTH_X (KIRBY_CENTER_X)
#define MOUTH_Y (KIRBY_CENTER_Y + 10)
#define MOUTH_RADIUS (KIRBY_RADIUS/8)

class Kirby {
  private:
      TFT_eSPI tft;
  
  public:
      void sleep(TFT_eSPI tft) {
        tft.fillScreen(BACKGROUND);

        // Left foot
        tft.fillEllipse(LEFT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, FOOT_COLOR);

        // Right foot
        tft.fillEllipse(RIGHT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, FOOT_COLOR);

        // Left hand
        tft.fillEllipse(LEFT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, BODY_COLOR);

        // Right hand
        tft.fillEllipse(RIGHT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, BODY_COLOR);

        // Body
        tft.fillEllipse(KIRBY_CENTER_X, KIRBY_CENTER_Y, SLEEP_BODY_RX, SLEEP_BODY_RY, BODY_COLOR);

        // Left eye
        tft.fillRoundRect(SLEEP_L_EYE_X, EYE_Y, EYE_RY, EYE_RX, EYE_RX/2, EYE_COLOR);

        // Right eye
        tft.fillRoundRect(SLEEP_R_EYE_X, EYE_Y, EYE_RY, EYE_RX, EYE_RX/2, EYE_COLOR);

        // Left blush
        tft.fillEllipse(LEFT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, BLUSH_COLOR);

        // Right blush
        tft.fillEllipse(RIGHT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, BLUSH_COLOR);

        // Mouth
        tft.fillCircle(MOUTH_X, MOUTH_Y, MOUTH_RADIUS, MOUTH_COLOR);

        // "zzz" text
        tft.setTextColor(TFT_WHITE);
        tft.setTextSize(2.5);
        tft.drawString("z...zz...", 200, 20);
      }

      void stand(TFT_eSPI tft) {
        tft.fillScreen(BACKGROUND);

        // Left foot
        tft.fillEllipse(LEFT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, FOOT_COLOR);

        // Right foot
        tft.fillEllipse(RIGHT_FOOT_X, FOOT_Y, FOOT_RADIUS_X, FOOT_RADIUS_Y, FOOT_COLOR);

        // Left hand
        tft.fillEllipse(LEFT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, BODY_COLOR);

        // Right hand
        tft.fillEllipse(RIGHT_HAND_X, HAND_Y, HAND_RADIUS_X, HAND_RADIUS_Y, BODY_COLOR);

        // Body
        tft.fillCircle(KIRBY_CENTER_X, KIRBY_CENTER_Y, KIRBY_RADIUS, BODY_COLOR);

        // Left eye (black)
        tft.fillEllipse(LEFT_EYE_X, EYE_Y, EYE_RX, EYE_RY, EYE_COLOR);

        // Right eye (black)
        tft.fillEllipse(RIGHT_EYE_X, EYE_Y, EYE_RX, EYE_RY, EYE_COLOR);

        // Left shine
        tft.fillEllipse(LEFT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, SHINE_COLOR);

        // Right shine
        tft.fillEllipse(RIGHT_SHINE_X, SHINE_Y, SHINE_RX, SHINE_RY, SHINE_COLOR);

        // Left blush
        tft.fillEllipse(LEFT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, BLUSH_COLOR);

        // Right blush
        tft.fillEllipse(RIGHT_BLUSH_X, BLUSH_Y, BLUSH_RX, BLUSH_RY, BLUSH_COLOR);

        // Mouth
        tft.fillCircle(MOUTH_X, MOUTH_Y, MOUTH_RADIUS, MOUTH_COLOR);
      }

      void startSinging() {
        // Open mouth
        tft.fillCircle(MOUTH_X, MOUTH_Y, MOUTH_RADIUS, MOUTH_COLOR);

        // Singing text
        tft.setTextColor(TFT_WHITE);
        tft.setTextSize(2.5);
        tft.drawString("La la la!", 20, 20);
      }

      void stopSinging() {
        // Close mouth
        tft.fillCircle(MOUTH_X, MOUTH_Y, MOUTH_RADIUS, BODY_COLOR);

        // Draw closed mouth
        tft.fillRoundRect(MOUTH_X - (MOUTH_RADIUS/2), MOUTH_Y, MOUTH_RADIUS, 5, MOUTH_RADIUS/2, MOUTH_COLOR);

        // Get rid of song text
        tft.fillRect(0, 0, 140, 50, BACKGROUND);
      }
};