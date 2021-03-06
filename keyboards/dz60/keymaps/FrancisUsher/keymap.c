#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define KC_LSPC LT(1, KC_SPC)
#define KC_FN1 MO(1)
#define KC_FN2 TG(2)
#define KC_FND TG(2)
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0
* ,-----------------------------------------------------------------------------------------.
* |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Bkspc    |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \     |
* |-----------------------------------------------------------------------------------------+
* |  Esc    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift  | Del |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  GUI |  Alt |      Space (hold for FN)        |   Alt  |  FN   |  GUI  |  Ctrl  |
* `-----------------------------------------------------------------------------------------'
*/

	LAYOUT(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_DEL,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LSPC, KC_LSPC, KC_LSPC, KC_RALT, TT(2), KC_NO, KC_RGUI, KC_RCTL),



 /* Layer 1
* ,-----------------------------------------------------------------------------------------.
* |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |     |
* |-----------------------------------------------------------------------------------------+
* |      |    |    |     |      |    |     |  HOME  |  UP | END | PGUP |    |      |        |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |      |     |     |    |  LEFT  | DWN | RGHT | PGDN  |     |        |
* |-----------------------------------------------------------------------------------------+
* |           |  _  |  +  |  (  |  )  |    |    |     |     |     |      |    |       |     |
* |-----------------------------------------------------------------------------------------+
* |       |      |       |                                         |        |      |        |
* `-----------------------------------------------------------------------------------------'
*/


	LAYOUT(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, RESET,
		BL_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______,
		BL_INC,  RGB_VAI, RGB_VAD, RGB_SAI, RGB_SAD, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______,
		_______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______),

/* Layer 2 for DotA
* ,-----------------------------------------------------------------------------------------.
* |  Esc  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Bkspc  |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \     |
* |-----------------------------------------------------------------------------------------+
* |  Esc    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift  | Del |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  GUI |  Alt |      Space                     |   Alt | Default |  GUI  |  Ctrl  |
* `-----------------------------------------------------------------------------------------'
*/

	LAYOUT(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_DEL,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_FN2, KC_NO, KC_RGUI, KC_RCTL),

};
