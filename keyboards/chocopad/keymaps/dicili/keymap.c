#include QMK_KEYBOARD_H

#define _BASE 0

#define _______ KC_TRNS

enum custom_keycodes {
    WIN_TOP_LEFT = SAFE_RANGE,
    WIN_TOP_RIGHT,
    WIN_BOTTOM_LEFT,
    WIN_BOTTOM_LEFT_TALL,
    WIN_BOTTOM_RIGHT,
    WIN_BOTTOM_RIGHT_TALL,
    WIN_FULL_SCREEN,
    WIN_FULL_CENTER,
    WIN_SMALL_CENTER,
    WIN_LEFT,
    WIN_RIGHT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case WIN_TOP_LEFT:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING("i");
                return false;
            case WIN_TOP_RIGHT:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING("o");
                return false;
            case WIN_BOTTOM_LEFT:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING(",");
                return false;
            case WIN_BOTTOM_LEFT_TALL:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING(SS_LSFT(","));
                return false;
            case WIN_BOTTOM_RIGHT:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING(".");
                return false;
            case WIN_BOTTOM_RIGHT_TALL:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING(SS_LSFT("."));
                return false;
            case WIN_FULL_SCREEN:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING(SS_TAP(X_ENTER));
                return false;
            case WIN_FULL_CENTER:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING(" ");
                return false;
            case WIN_SMALL_CENTER:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING(SS_LSFT("j"));
                return false;
            case WIN_LEFT:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING("h");
                return false;
            case WIN_RIGHT:
                SEND_STRING(SS_LCTRL("s"));
                wait_ms(10);
                SEND_STRING("l");
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [_BASE] = KC_KEYMAP(
  //,----+----+----+----.
     // PGUP,HOME, UP ,END ,
  //|----+----+----+----|
     // PGDN,LEFT,DOWN,RGHT,
  //|----+----+----+----|
      // X2 ,VOLU,MPLY,MPRV,
  //|----+----+----+----|
      // X1 ,VOLD,MUTE,MNXT
  //`----+----+----+----'
  // ),

  [_BASE] = LAYOUT_ortho_4x4(
  //,----+-------+----+----.
     WIN_TOP_LEFT,KC_NO,   KC_NO,WIN_TOP_RIGHT,
  //|----+-------+----+----|
     WIN_LEFT,KC_NO,   WIN_FULL_SCREEN,WIN_RIGHT,
  //|----+-------+----+----|
      WIN_BOTTOM_LEFT_TALL,WIN_SMALL_CENTER,  WIN_FULL_CENTER,WIN_BOTTOM_RIGHT_TALL,
  //|----+-------+----+----|
      WIN_BOTTOM_LEFT,KC_NO,KC_NO,WIN_BOTTOM_RIGHT
  //`----+-------+----+----'
  )

};
