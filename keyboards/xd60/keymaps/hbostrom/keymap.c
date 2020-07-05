#include QMK_KEYBOARD_H

enum custom_layers {
  _REMOTE,
  _LOCAL,
  _I3_REM,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  REMOTE = SAFE_RANGE,
  LOCAL,
//  I3_REM,
  LOWER,
  RAISE,
};

#define CC_1       LCAG(KC_1)
#define CC_2       LCAG(KC_2)
#define CC_3       LCAG(KC_3)
#define CC_4       LCAG(KC_4)
#define CC_5       LCAG(KC_5)
#define CC_6       LCAG(KC_6)
#define CC_7       LCAG(KC_7)
#define CC_8       LCAG(KC_8)
#define CC_9       LCAG(KC_9)
#define CC_0       LCAG(KC_0)
#define CC_MINS    LCAG(KC_MINS)
#define CC_EQL     LCAG(KC_EQL)
#define CC_BSPC    LCAG(KC_BSPC)
#define CC_TAB     LCAG(KC_TAB)
#define CC_Q       LCAG(KC_Q)
#define CC_W       LCAG(KC_W)
#define CC_E       LCAG(KC_E)
#define CC_R       LCAG(KC_R)
#define CC_T       LCAG(KC_T)
#define CC_Y       LCAG(KC_Y)
#define CC_U       LCAG(KC_U)
#define CC_I       LCAG(KC_I)
#define CC_O       LCAG(KC_O)
#define CC_P       LCAG(KC_P)
#define CC_LBRC    LCAG(KC_LBRC)
#define CC_RBRC    LCAG(KC_RBRC)
#define CC_BSLS    LCAG(KC_BSLS)
#define CC_A       LCAG(KC_A)
#define CC_S       LCAG(KC_S)
#define CC_D       LCAG(KC_D)
#define CC_F       LCAG(KC_F)
#define CC_G       LCAG(KC_G)
#define CC_H       LCAG(KC_H)
#define CC_J       LCAG(KC_J)
#define CC_K       LCAG(KC_K)
#define CC_L       LCAG(KC_L)
#define CC_SCLN    LCAG(KC_SCLN)
#define CC_QUOT    LCAG(KC_QUOT)
#define CC_ENT     LCAG(KC_ENT)
#define CC_LSFT    LCAG(KC_LSFT)
#define CC_Z       LCAG(KC_Z)
#define CC_X       LCAG(KC_X)
#define CC_C       LCAG(KC_C)
#define CC_V       LCAG(KC_V)
#define CC_B       LCAG(KC_B)
#define CC_N       LCAG(KC_N)
#define CC_M       LCAG(KC_M)
#define CC_COMM    LCAG(KC_COMM)
#define CC_DOT     LCAG(KC_DOT)
#define CC_SLSH    LCAG(KC_SLSH)
#define CC_RSFT    LCAG(KC_RSFT)

#define LSFT_TZ    LSFT_T(KC_Z)
#define LCTL_TX    LCTL_T(KC_X)
#define LT_2_C     LT(_LOWER, KC_C)
#define LALT_TV    LALT_T(KC_V)

#define RALT_TM    RALT_T(KC_M)
#define LT_2_COMM  LT(_LOWER, KC_COMM)
#define RCTL_TDOT  RCTL_T(KC_DOT)
#define RSFT_TSLSH RSFT_T(KC_SLSH)

// #define LT_1_QUOT  LT(1, KC_QUOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_REMOTE] = LAYOUT_all( /* L0 - QWERTY */
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     KC_6,    KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,    KC_EQL,  KC_BSPC, KC_NO, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,    KC_RBRC,          KC_BSLS, \
      MO(_I3_REM),KC_A, KC_S,    KC_D,    KC_F,   KC_G,     KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,    KC_NO,            KC_ENT, \
      KC_LSFT, KC_NO,   LSFT_TZ, LCTL_TX, LT_2_C, LALT_TV,  KC_B,    KC_N,    RALT_TM, LT_2_COMM, RCTL_TDOT, RSFT_TSLSH, KC_NO,   KC_RSFT, KC_NO, \
      KC_LCTL, LOWER,   KC_LALT,                            KC_SPC,                               KC_RALT,   KC_RCTL,    LOWER,   RAISE,   KC_NO \
  ),
  [_LOCAL] = LAYOUT_all( /* L0 - QWERTY */
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     KC_6,    KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,    KC_EQL,  KC_BSPC, KC_NO, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,    KC_RBRC,          KC_BSLS, \
      KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,  KC_QUOT,    KC_NO,            KC_ENT, \
      KC_LSFT, KC_NO,   LSFT_TZ, LCTL_TX, LT_2_C, LALT_TV,  KC_B,    KC_N,    RALT_TM, LT_2_COMM, RCTL_TDOT, RSFT_TSLSH, KC_NO,   KC_RSFT, KC_NO, \
      KC_LCTL, LOWER,   KC_LALT,                            KC_SPC,                               KC_RALT,   KC_RCTL,    LOWER,   RAISE,   KC_NO \
  ),
  [_I3_REM] = LAYOUT_all( /* L1 - I3 applies CtrlAltGui (LCAG) to keys */
      _______, CC_1,    CC_2,    CC_3,    CC_4,    CC_5,    CC_6,    CC_7,    CC_8,    CC_9,      CC_0,      CC_MINS,    CC_EQL,  CC_BSPC, KC_NO, \
      CC_TAB,  CC_Q,    CC_W,    CC_E,    CC_R,    CC_T,    CC_Y,    CC_U,    CC_I,    CC_O,      CC_P,      CC_LBRC,    CC_RBRC,          CC_BSLS, \
      _______, CC_A,    CC_S,    CC_D,    CC_F,    CC_G,    CC_H,    CC_J,    CC_K,    CC_L,      CC_SCLN,   CC_QUOT,    KC_NO,            CC_ENT, \
      CC_LSFT, KC_NO,   CC_Z,    CC_X,    CC_C,    CC_V,    CC_B,    CC_N,    CC_M,    CC_COMM,   CC_DOT,    CC_SLSH,    KC_NO,   CC_RSFT, KC_NO, \
      _______, _______, _______,                            _______,                              _______,   _______,    _______, _______, KC_NO \
  ),
  [_LOWER] = LAYOUT_all( /* L2 - Arrows */
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,     KC_F12,  KC_DEL,  KC_NO, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______,          _______, \
      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,   _______,   _______,    KC_NO,            _______, \
      KC_LSFT, KC_NO,   _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,   KC_END,    _______,    KC_NO,   KC_RSFT, KC_NO, \
      _______, _______, _______,                            _______,                              _______,   _______,    _______, _______, KC_NO \
  ),
  [_RAISE] = LAYOUT_all( /* L2 - Arrows */
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______, _______,  KC_NO, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______,          _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,            _______, \
      _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,   _______, KC_NO, \
      _______, _______, _______,                            _______,                              _______,   _______,    _______, _______, KC_NO \
  ),
  [_ADJUST] = LAYOUT_all( /* L2 - Arrows */
      LOCAL,   REMOTE,  _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______, _______, KC_NO, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______,          _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,            _______, \
      _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,   _______, KC_NO, \
      RESET,   _______, _______,                            _______,                              _______,   _______,    _______, _______, KC_NO \
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case REMOTE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_REMOTE);
          }
          return false;
          break;
        case LOCAL:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_LOCAL);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}       // Light 4 LEDs, starting with LED 6
);
const rgblight_segment_t PROGMEM remote_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CYAN}
);
const rgblight_segment_t PROGMEM local_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM i3_rem_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_GREEN}
);
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    local_layer,
    remote_layer,
    i3_rem_layer,
    lower_layer,
    raise_layer,
    adjust_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(_LOCAL, layer_state_cmp(state, _LOCAL));
    rgblight_set_layer_state(_REMOTE, layer_state_cmp(state, _REMOTE));
    rgblight_set_layer_state(_I3_REM, layer_state_cmp(state, _I3_REM));
    rgblight_set_layer_state(_LOWER, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}


// Loop
void matrix_scan_user(void) {
  // Empty
};

