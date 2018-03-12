/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb.h"

#define BASE 0
#define HHKB 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |----------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+------|
     | `        | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | Play |
     |----------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+------|
     | Tab/Layer| Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |      |
     |----------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+------|
     | Ctr/Esc  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |      |
     |----------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+------|
     | Shift    | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |      |
     |----------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+------|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt |
            |------+------+-----------------------+------+------|
    */

  [BASE] = KEYMAP(  //  default layer
  KC_GRV,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,    KC_BSLS,  KC_MPLY, \
  LT(HHKB,KC_TAB),   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,   KC_BSPC,          \
  MT(MOD_RCTL,KC_ESC),  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                      \
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  MO(HHKB),                    \
                    KC_LALT,  KC_LGUI,  /*        */ KC_SPC,      KC_RGUI,  KC_RALT),



    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+-----+----+-----+------+-----+-----+-----+-----+-------+-------+-----|
      |      | F1  | F2  | F3  | F4  | F5 | F6  | F7   | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+-----+----+-----+------+-----+-----+-----+-----+-------+-------+-----|
      | Caps | Rwnd| Play| Next|     |    |     | PgD  | PgU |     |     |     |       |       |     |
      |------+-----+-----+-----+-----+----+-----+------+-----+-----+-----+-----+-------+-------+-----|
      |      |     | VoD | VoU | Mut |    | Lef | Down | Up  | Rgt |     |     | Enter |       |     |
      |------+-----+-----+-----+-----+----+-----+------+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |     |    |     |      |     |     |     |     |       |       |     |
      |------+-----+-----+-----+-----+----+-----+------+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

  [HHKB] = KEYMAP(
  KC_CAPS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL, \
  KC_TRNS,  KC_MRWD,  KC_MPLY,  KC_MNXT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_PGUP,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,          \
  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    \
  KC_TRNS,  KC_APP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS)};


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
