#include "FrancisUsher.h"
#include QMK_KEYBOARD_H
#define LAYOUT_prime_e LAYOUT

#define _QWERTY 0
#define _NUMBER 1
#define _NAV 2

#define KC_NAVSP LT(_NAV, KC_SPC)
#define KC_NAVESC LT(_NAV, KC_ESC)
#define KC_CTLSP LCTL_T(KC_SPC)
#define KC_MONUM MO(_NUMBER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_prime_e_wrapper( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,   _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,  KC_LBRC, KC_RBRC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_ESC,   _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,  KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_LSFT,  _________________QWERTY_L3_________________, KC_MONUM, _________________QWERTY_R3_________________,  KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
     KC_LCTRL, KC_LALT,           KC_MONUM,KC_NAVSP,    KC_CTLSP, KC_MONUM,  KC_RGUI, KC_RCTL\
                              //`--------------------'  `--------------------'
  ),

  [_NUMBER] = LAYOUT_prime_e_wrapper( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _______, ________________NUMBER_L1__________________, ________________NUMBER_R1__________________, KC_F11, KC_F12, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_GRV,  ________________NUMBER_L2__________________, ________________NUMBER_R2__________________, KC_MINS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_TILD, ________________NUMBER_L3__________________, _______, ________________NUMBER_R3__________________, KC_UNDS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      _______, _______,           _______,_______,    _______, _______,  _______, _______\
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_prime_e_wrapper( \
  //,-----------------------------------------.                ,-----------------------------------------.
        KC_RST, _______, _______, _______, KC_BRIU,  KC_VOLU,        _________________NAV_R1_LONG_______________,  KC_BSPC, KC_DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, _______, _______, _______, KC_BRID,  KC_VOLD,        _________________NAV_R2____________________,   KC_ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, _______, _______, _______, _______,  KC_MUTE,        _______, _______, _______, KC_EQL, KC_PLUS, KC_BSLS, _______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      _______, _______,           _______,_______,    _______, _______,  _______, _______\
                              //`--------------------'  `--------------------'
  )
};

// void matrix_init_user(void) {
//   // set CapsLock LED to output and low
//   setPinOutput(B1);
//   writePinLow(B1);
//   // set NumLock LED to output and low
//   setPinOutput(B2);
//   writePinLow(B2);
//   // set ScrollLock LED to output and low
//   setPinOutput(B3);
//   writePinLow(B3);
// }

// void matrix_scan_user(void) {

// }


// void led_set_user(uint8_t usb_led) {
//   if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
//     writePinHigh(B2);
//   } else {
//     writePinLow(B2);
//   }
//   if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
//     writePinHigh(B1);
//   } else {
//     writePinLow(B1);
//   }
// /*
//   if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
//     writePinHigh(B3);
//   } else {
//     writePinLow(B3);
//   }*/

// }

// //function for layer indicator LED
// uint32_t layer_state_set_user(uint32_t state)
// {
//     if (biton32(state) == 1) {
//     writePinHigh(B3);
// 	} else {
// 		writePinLow(B3);
//     }
//     return state;
// }
