
#include "fourier.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 MO(_FN3)
#define KC_SPFN1 LT(_FN1, KC_SPACE)
#define KC_TABFN3 LT(_FN3, KC_TAB)
#define KC_CTLESC MT(MOD_RCTL,KC_ESC)
#define KC_SHFTENT MT(MOD_RSFT,KC_ENT)
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
  TABFN3, Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,    ,BSPC,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
  CTLESC, A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,  QUOT   ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    LSFT   , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH, SHFTENT ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    LALT, LGUI ,FN2 ,    ,   FN1  ,  SPC   ,RGUI ,RALT , MNXT , MPLY
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN1] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
        , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,    ,    ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
         ,    ,VOLD,VOLU,    ,    ,    ,MINS,EQL,LBRC,RBRC,  BSLS   ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    APP   ,    ,    ,    ,    ,    ,    ,PGDN,PGUP,    ,    ,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    MPLY ,MNXT,     ,    ,        ,        ,LEFT , DOWN,  UP , RGHT
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN2] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
        ,EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,    ,    ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
         ,    ,    ,    ,   ,   ,    , UNDS,PLUS,LCBR,RCBR,   PIPE  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
           ,    ,    ,    ,   ,    ,    ,PGDN,PGUP,    ,    ,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
         ,    ,     ,    ,        ,        ,LEFT , DOWN,  UP , RGHT
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN3] = LAYOUT_kc(
//,----+----+----+----+----+----|----+----+----+----+----+----+----.
      ,    ,    ,    ,    ,    ,    ,PGDN,PGUP,    ,    ,    ,    ,
//|----`----`----`----`----`----|----`----`----`----`----`----`----|
       ,    ,    ,    ,   ,   ,LEFT, DOWN, UP ,RGHT,    ,         ,
//|-----`----`----`----`----`----|----`----`----`----`----`--------|
         ,    ,    ,    ,   ,    ,    ,PGDN,PGUP,    ,    ,      ,
//|-------`----`----`----`----`----|----`----`----`----`----`------|
       ,    ,     ,    ,        ,        ,LEFT , DOWN,  UP , RGHT
//`-----+----+-----+----+--------|--------+-----+-----+-----+------'
)

};
