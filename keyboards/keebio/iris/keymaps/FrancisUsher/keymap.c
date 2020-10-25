#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUMBER 1
#define _SYMBOL 2
#define SFTTAB MT(MOD_LSFT, KC_TAB)
#define NUMSPC LT(_NUMBER, KC_SPC)
#define SYMSPC LT(_SYMBOL, KC_SPC)
#define ONE_CTL OSM(MOD_LCTL)
#define ONE_ALT OSM(MOD_RALT)
#define ONE_GUI OSM(MOD_LGUI)
#define ONE_SFT OSM(MOD_RSFT)
#define LSELECT LCTL(KC_A)
#define LSAVE LCTL(KC_S)
#define LUNDO LCTL(KC_Z)
#define LCUT LCTL(KC_X)
#define LCOPY LCTL(KC_C)
#define LPASTE LCTL(KC_V)
#define LOPNTAB LCTL(KC_T)
#define LCLSTAB LCTL(KC_W)
#define LPRFNCS LCTL(KC_P)
#define LOPNWIN LCTL(KC_N)
#define LFIND LCTL(KC_F)
#define SFCLENT MT(MOD_LSFT | MOD_LCTL, KC_ENT)


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBER,
  SYMBOL,
  RS_OSFT, // SYMBOL hold, one-shot shift tap
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ONE_CTL,          KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    ONE_SFT, SFTTAB,  SYMSPC,                    NUMSPC,  KC_BSPC, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LSELECT, LSAVE,   _______, LFIND,   _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LUNDO,   LCUT,    LCOPY,   LPASTE,  KC_GRV,  _______,          _______, KC_TILD, KC_UNDS, KC_DQUO, KC_LCBR, KC_RCBR, KC_PLUS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   SFCLENT, KC_DEL,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, KC_GRV,  KC_MINS, KC_QUOT, KC_LBRC, KC_RBRC, KC_EQL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_ESC,  SFCLENT,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

uint16_t time_on_pressed;

void matrix_init_user(void) {
  time_on_pressed = 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RS_OSFT:
      if (record->event.pressed) {
            layer_on(_SYMBOL);
            time_on_pressed = record->event.time;
        } else {
            layer_off(_SYMBOL);
            if (TIMER_DIFF_16(record->event.time, time_on_pressed) < TAPPING_TERM) {
                set_oneshot_mods(MOD_LSFT);
            }
            time_on_pressed = 0;
        }
      return false;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_W, KC_J) {
      SEND_STRING(SS_LGUI(SS_TAP(X_DOWN)));
    }
    SEQ_TWO_KEYS(KC_W, KC_K) {
      SEND_STRING(SS_LGUI(SS_TAP(X_UP)));
    }
  }
}
