#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define LOWER 1
#define RAISE 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  y   |   |  t   |   Y  |   U  |   I  |   O  |   P  |  BS  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |  h   |   |  g   |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  n   |   |  b   |   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl| LGUI | LAlt | LOWER | LOWER |Space |   | enter| RAISE | RAISE |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */

  [BASE] = LAYOUT( \
    KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,KC_T,KC_Y,          KC_T,KC_Y,KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC, \
    KC_LCTRL,  KC_A,    KC_S,   KC_D,    KC_F,KC_G,KC_H,          KC_G,KC_H,KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,KC_B,KC_N,          KC_B, KC_N,KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  SFT_T(KC_ENT), \
    XXXXXXX,  KC_ESC, KC_RGUI, KC_LGUI, MO(LOWER), MO(LOWER), KC_SPC, KC_ENT, MO(RAISE), MO(RAISE), KC_LEFT, KC_DOWN, KC_DOWN, MO(GAME) \
  ),

  /* LOWER
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |  6   |   |  ]   |   7  |   8  |   9  |   0  |   -  |  ^   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |  F1  |  F2  |Muhen | Henk |      |  (   |   |  )   | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl| LGUI | LAlt | LOWER | LOWER |Space |   | enter| RAISE | RAISE |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [LOWER] = LAYOUT( \
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), _______, S(KC_7), S(KC_8), S(KC_9),    S(KC_0),   S(KC_MINS), S(KC_EQL), \
    _______, KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, _______,    _______, KC_LEFT, KC_MINS, KC_EQL, S(KC_LBRC), S(KC_RBRC), XXXXXXX, \
    _______, KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,_______,    _______, KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  SFT_T(KC_RO), \
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  /* RAISE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   !  |   "  |   #  |   $  |   %  |   &  |  [   |   |  ]   |   '  |   (  |   )  |   ~  |   =  |  ~   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |   +  |  *   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  \   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc |=>GAME|=>RAISE|  \   |
   * |      |      |      |      |~RAISE |RCtrl |Shift |   |Space |~LOWER |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [RAISE] = LAYOUT( \
    _______, KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  _______,       _______, KC_6,    KC_7,    KC_8,  KC_9,    KC_0, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, S(KC_7), KC_MINS    , S(KC_EQL), KC_LBRC,   KC_RBRC, S(KC_QUOT), \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RO), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______ \
  ),

  /* GAME
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc | ESC  |Space |Tab   |   |Back  |Enter | Del  |PrtSc |=>GAME|=>RAISE|  \   |
   * |      |      |      |      |      |      |      |   |Space |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [GAME] = LAYOUT( \
    _______,  _______,_______,   _______,_______,   _______,   _______,_______,_______,   _______,KC_PSCR, KC_HOME,_______,    KC_DEL, \
    _______,  _______,_______,   _______,_______,   _______,   _______,_______,_______,   _______,_______, KC_UP, KC_RGHT, KC_QUOT, \
    _______,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   S(KC_RBRC), S(KC_BSLS), KC_N,   KC_END,    KC_LEFT,  KC_DOWN,  KC_RGHT, SFT_T(KC_RO), \
    _______, _______, _______, KC_PSCR, KC_ESC, KC_SPC, KC_TAB,     KC_BSPC,    KC_ENT, KC_DELT, KC_LEFT,  KC_DOWN, _______, _______ \
  )
  /*
   * KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_RBRC,    KC_BSLS,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_UP,    KC_LBRC, \
   * KC_LALT,  KC_A,    KC_S,   KC_D,    KC_F,   KC_G,   S(KC_8),    S(KC_9),    KC_H,   KC_J,    KC_K,     KC_UP,    KC_RGHT, KC_QUOT, \
   * KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   S(KC_RBRC), S(KC_BSLS), KC_N,   KC_M,    KC_LEFT,  KC_DOWN,  KC_RGHT, SFT_T(KC_RO), \
   * KC_LCTRL, KC_LGUI, KC_APP, KC_PSCR, KC_ESC, KC_SPC, KC_TAB,     KC_BSPC,    KC_ENT, KC_DELT, KC_PSCR,  _______, _______, _______ \
   */

};
