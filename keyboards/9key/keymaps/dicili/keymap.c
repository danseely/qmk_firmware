#include "9key.h"

// Tap Dance Declarations
enum {
  ENT_5 = 0,
  ZERO_7
};

// Macro Declarations
enum {
  DBL_0 = 0,
	EFF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,----------------------------------------------.
 * |  EFF                         |   2   |   3   |
 * |------------------------------+-------+-------|
 * |   4                          | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |------------------------------+-------+-------|
 * |  LSFT(LCTL(LGUI(KC_PAST)))  |   8   | 9/FN  | 7/0 = Dbl Tap 7 for 0  -  9/FN = Hold 9 for FN
 * `----------------------------------------------'
 */
[0] = KEYMAP( \
  M(EFF),       KC_2,      KC_3,       \
  KC_4,       TD(ENT_5), KC_6,       \
  LSFT(LCTL(LGUI(KC_PAST))), LSFT(LCTL(KC_POWER)),      LT(1, KC_9) \
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |  00   |   .   |       |
 * `-----------------------'
 */
[1] = KEYMAP( \
  KC_ESC,   KC_PLUS, KC_MINS, \
  KC_BSPC,  KC_ASTR, KC_SLSH, \
  M(DBL_0), KC_DOT,  KC_TRNS  \
)

};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
  [ZERO_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_0)
};

// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
      switch(id) {
          case DBL_0:
              SEND_STRING("00");
              return false;
          case EFF:
              SEND_STRING(":mid");
							wait_ms(32);
              SEND_STRING("d");
							wait_ms(32);
              SEND_STRING("le_finger");
              SEND_STRING(":");
              SEND_STRING(SS_TAP(X_ENT));
              return false;
      }
  }
  return MACRO_NONE;
};
void matrix_init_user(void) {
}
