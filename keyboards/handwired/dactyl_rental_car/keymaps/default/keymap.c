#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUMBER 1
#define _SYMBOL 2
#define _NAV 3
// Fillers to make layering more clear

#define _______ KC_TRNS
#define CTRLESC MT(MOD_LCTL, KC_ESC)
#define CTRLENT MT(MOD_RCTL, KC_ENT)
#define NUMSPC LT(_NUMBER, KC_SPC)
#define SYMSPC LT(_SYMBOL, KC_SPC)
#define NAVSPC LT(_NAV, KC_SPC)
#define NUMESC LT(_NUMBER, KC_ESC)
#define SFTTAB MT(MOD_LSFT, KC_TAB)
#define SHFTSPC MT(MOD_RSFT, KC_SPC)
#define LSELECT LCTL(KC_A)
#define LSAVE LCTL(KC_S)
#define LUNDO LCTL(KC_Z)
#define LCUT LCTL(KC_X)
#define LCOPY LCTL(KC_C)
#define LPASTE LCTL(KC_V)
#define LFIND LCTL(KC_F)
#define CTLSHFT KC_RCTL || KC_RSFT
#define MOSYMB MO(_SYMBOL)
#define MONUMB MO(_NUMBER)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
  //|   Q    |   W    |   E    |   R    |   T    |                                   |   Y    |   U    |   I    |   O    |   P    |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|   A    |   S    |   D    |   F    |   G    |                                   |   H    |   J    |   K    |   L    |   ;    |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|   Z    |   X    |   C    |   V    |   B    |                                   |   N    |   M    |   ,    |   .    |   /    |
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
  //                                           | SYMBOL |  ALT   |   |  ALT   | SHIFT  |
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                   // |  NAV / | NUMBER |  SHIFT |   |  WIN   | CTRL   | SHIFT/ |
                                   // |  SPACE |        |        |   |        |        | SPACE  |
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘

[_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
                                                MOSYMB,  KC_LALT,     KC_RALT, KC_RSFT,
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                       NAVSPC,  MONUMB,  KC_LSFT,     KC_RGUI, KC_RCTL, SHFTSPC
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘
),

  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
  //|   ~    |   |    |        |        |        |                                   |   "    |   _    |   +    |   {    |   }    |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|   !    |   @    |   #    |   $    |   %    |                                   |   ^    |   &    |   *    |   (    |   )    |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|   `    |   \    |        |        |        |                                   |   '    |   -    |   =    |   [    |   ]    |
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
  //                                           |        |        |   |        |        |
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                   // |        |        |        |   |        |        |        |
                                   // |        |        |        |   |        |        |        |
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘


[_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_PIPE, _______, _______, _______,                                     KC_DQUO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_BSLS, _______, _______, _______,                                     KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
                                                _______, _______,     _______, _______,
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                       _______, _______, _______,     _______, _______, _______
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘
),

  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
  //|   F1   |   F2   |   F3   |   F4   |   F5   |                                   |   F6   |   F7   |   F8   |   F9   |   F10  |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|    1   |    2   |    3   |    4   |    5   |                                   |    6   |    7   |    8   |    9   |    0   |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |  F11   |                                   |   F12  |        |        |        |        |
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
  //                                           |        |        |   |        |        |
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                   // |        |        |        |   |        |        |        |
                                   // |        |        |        |   |        |        |        |
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘

[_NUMBER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_F11,                                      KC_F12,  _______, _______, _______, _______,
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
                                                _______, _______,     _______, _______,
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                       _______, _______, _______,     _______, _______, _______
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘
),
  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
  //|  ESC   |        |        |        | VOL +  |                                   |        |  HOME  |  END   | BKSPC  |  DEL   |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|  TAB   |        |        |        | VOL -  |                                   |   ←    |   ↓    |   ↑    |   →    |   ⮠    |
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        | MUTE   |                                   |        |  PGUP  |  PGDN  |        |  INS   |
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
  //                                           |        |        |   |        |        |
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                   // |        |        |        |   |        |        |        |
                                   // |        |        |        |   |        |        |        |
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘
[_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┐
     KC_TAB,  _______, _______, _______, KC_VOLU,                                     _______, KC_HOME, KC_END,  KC_BSPC, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  _______, _______, _______, KC_VOLD,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_MUTE,                                     _______, KC_PGUP, KC_PGDN, _______, KC_INS,
  //└────────┴────────┴────────┴────────┴──────┬─┴──────┬────────┐   ┌────────┬──────┴─┬──────┴────────┴────────┴────────┴────────┘
                                                _______, _______,     _______, _______,
                                   // ┌────────┴────────┼────────┘   └────────┴────────┼────────┐
                                       _______, _______, _______,     _______, _______, _______
                                   // └────────┴────────┴────────┘   └────────┴────────┴────────┘
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
