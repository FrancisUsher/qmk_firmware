/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "daskb_ultimate.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT( 
		KC_F6,   -1,      KC_G,   -1,      -1,      KC_P0,   KC_SPC,  -1,      -1,       KC_LALT,  KC_H, KC_F4, KC_ESC, KC_F11,    KC_QUOT,   KC_PDOT, -1,      KC_UP,   \
		KC_K,    KC_L,    KC_F,   KC_S,    -1,      KC_P2,   KC_P1,   KC_RGUI, KC_RSFT,  -1,       KC_J, KC_D,  KC_A,   KC_BSLASH, KC_SCOLON, KC_P3,   -1,      KC_PENT, \
    KC_I,    KC_O,    KC_R,   KC_W,    KC_PAUS, KC_P8,   KC_P7,   -1,      -1,       KC_SLCK,  KC_U, KC_E,  KC_Q,   -1,        KC_P,      KC_P9,   -1,      KC_PPLS, \
		KC_COMM, KC_DOT,  KC_V,   KC_X,    KC_RCTL, KC_PSLS, KC_NLCK, -1,      -1,       -1,       KC_M, KC_C,  KC_Z,   KC_ENT,   -1,         KC_PAST, -1,      -1,      \
		KC_8,    KC_9,    KC_4,   KC_2,    KC_F5,   -1,      -1,      -1,      -1,       KC_PSCR,  KC_7, KC_3,  KC_1,   KC_F10,   KC_0,       KC_PGDN, -1,      KC_END,  \
		KC_EQL,  KC_F8,   KC_5,   KC_F1,   KC_LCTL, KC_INS,  KC_DEL,  -1,      -1,       -1,       KC_6, KC_F2, KC_GRV, KC_F9,    KC_MINS,    KC_PGUP, -1,      KC_HOME, \
		KC_RBRC, KC_F7,   KC_T,   KC_CAPS, -1,      KC_P5,   KC_P4,   -1,      KC_LSFT,  -1,       KC_Y, KC_F3, KC_TAB, KC_BSPC,  KC_LBRC,    KC_P6,   KC_LGUI, -1,      \
    -1,      KC_MENU, KC_B,   -1,      -1,      KC_RGHT, KC_DOWN, -1,      -1,       KC_RALT,  KC_N, -1,    -1,     KC_F12,   KC_SLSH,    KC_PMNS, -1,      KC_LEFT
	)
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
