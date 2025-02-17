#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "quantum.h"

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_F13   , KC_F14   , KC_F15   , KC_F16   , ____,
		KC_F17   , KC_F18   , KC_F19   , KC_F20   , ____,
		KC_F21   , KC_F22  , KC_F23  , KC_MUTE     , TO(1)
    ),
	[1] = LAYOUT(
		KC_F1   , KC_F2   , KC_F3   , KC_F4   , ____,
		KC_F5   , KC_F6   , KC_F7   , KC_F8   , ____,
		KC_F9   , KC_F10  , KC_F11  , KC_F12   , TO(0)
    ),
	// [2] = LAYOUT(
	// 	KC_CUT   , KC_COPY   , KC_PASTE   , KC_F4   , ____,
	// 	KC_F5   , KC_F6   , KC_F7   , KC_F8   , ____,
	// 	KC_F9   , KC_F10  , KC_F11  , KC_F12   , TO(3)
    // ),
	// [3] = LAYOUT(
	// 	KC_F1   , KC_F2   , KC_F3   , KC_F4   , ____,
	// 	KC_F5   , KC_F6   , KC_F7   , KC_F8   , ____,
	// 	KC_F9   , KC_F10  , KC_F11  , KC_F12   , TO(0)
    // ),


};

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    if(data[0] == 0xFC){
        switch (data[1]) {
            case 0x01:{
                // move to layer
                data[1] = 0xFD;
                layer_move(data[2]);
                break;
            }
            case 0x02:{
                // turn on layer
                data[1] = 0xFD;
                layer_on(data[2]);
                break;
            }
            case 0x03:{
                // turn off layer
                data[1] = 0xFD;
                layer_off(data[2]);
                break;
            }
        }
    }
    raw_hid_send(data, length);
}
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    // [2] =  { ENCODER_CCW_CW(KC_UNDO, KC_AGAIN) },
    // [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

/*code for not defined ENCODER_MAP_ENABLE
if ENCODER_MAP_ENABLE  not enable via and vial changing layout for rotary doesn't work
*/
#if !defined(ENCODER_MAP_ENABLE)
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } 
    return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } 
    return false;
}

#endif
