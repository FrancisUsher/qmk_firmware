#include QMK_KEYBOARD_H
#include "FrancisUsher.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define LAYOUT_crkbd LAYOUT

#define _QWERTY 0
#define _NUMBER 1
#define _SYMBOL 2
#define _NAV 3

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_NAVSP LT(_NAV, KC_SPC)
#define KC_NAVESC LT(_NAV, KC_ESC)
#define KC_SYMSP LT(_SYMBOL, KC_SPC)
#define KC_MONUM MO(_NUMBER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_crkbd_wrapper( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,   _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,  KC_BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_LSFT,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,  KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_LCTRL, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,  KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   KC_LALT, KC_MONUM,KC_NAVESC,    KC_SYMSP, KC_MONUM,  KC_RGUI\
                              //`--------------------'  `--------------------'
  ),

  [_NUMBER] = LAYOUT_crkbd_wrapper( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_F12, ________________NUMBER_L1__________________, ________________NUMBER_R1__________________, KC_F11,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, ________________NUMBER_L2__________________, ________________NUMBER_R2__________________, _______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, ________________NUMBER_L3__________________, ________________NUMBER_R3__________________, _______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _______, _______, _______,    _______, _______, _______ \
                              //`--------------------'  `--------------------'
  ),

  [_SYMBOL] = LAYOUT_crkbd_wrapper( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _______, _________________SYMBOL_L1_________________, ___________________BLANK___________________, _______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, _________________SYMBOL_L2_________________, ___________________BLANK___________________, _______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, _________________SYMBOL_L3_________________, ___________________BLANK___________________, _______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _______, _______, _______,    _______, _______, _______ \
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_crkbd_wrapper( \
  //,-----------------------------------------.                ,-----------------------------------------.
        KC_RST, _______, _______, _______, _______,  KC_VOLU,        _________________NAV_R1____________________,   KC_DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, _______, _______, _______, _______,  KC_VOLD,        _________________NAV_R2____________________,   KC_ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, _______, _______, _______, _______,  KC_MUTE,                  _______, _______, _______, _______, _______, _______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _______, _______, _______,    _______, _______, _______ \
                              //`--------------------'  `--------------------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
