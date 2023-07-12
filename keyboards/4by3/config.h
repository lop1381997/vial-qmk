#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFFFF
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    hirlu  
#define PRODUCT         4by3

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { B3, B2, B6 }
#define MATRIX_COL_PINS { B1, F7, F6, F5, E6 }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define VIAL_KEYBOARD_UID {0x53, 0xC6, 0xFB, 0x9F, 0x62, 0x8F, 0x28, 0x48}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

// encoder
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }
#define ENCODER_RESOLUTION 4
