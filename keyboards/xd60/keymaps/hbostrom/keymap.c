#include QMK_KEYBOARD_H

enum custom_layers {
  _REMOTE,
  _LOCAL,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  REMOTE = SAFE_RANGE,
  LOCAL,
  LOWER,
  RAISE,
  I3LOC,
  I3REM
};

#define LALT_LBRC  LALT_T(KC_LBRC)
#define RALT_RBRC  RALT_T(KC_RBRC)
#define RCTL_EQL   RCTL_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_REMOTE] = LAYOUT_all(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     KC_6,    KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,    KC_EQL,  KC_BSPC, KC_NO, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,    KC_RBRC,          KC_BSLS, \
      I3REM,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,    KC_NO,            KC_ENT, \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,    KC_NO,   KC_RSFT, KC_NO, \
      KC_LCTL, LOWER,   LALT_LBRC,                          KC_SPC,                               RALT_RBRC, RCTL_EQL,   KC_NO,   LOWER,   RAISE \
  ),
  [_LOCAL] = LAYOUT_all(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     KC_6,    KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,    KC_EQL,  KC_BSPC, KC_NO, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,    KC_RBRC,          KC_BSLS, \
      I3LOC,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,    KC_NO,            KC_ENT, \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,    KC_NO,   KC_RSFT, KC_NO, \
      KC_LCTL, LOWER,   LALT_LBRC,                          KC_SPC,                               RALT_RBRC, RCTL_EQL,   KC_NO,   LOWER,   RAISE \
  ),
  [_LOWER] = LAYOUT_all(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,     KC_F12,  KC_DEL,  KC_NO, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______,          _______, \
      KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,   _______,   _______,    KC_NO,            _______, \
      KC_LSFT, KC_NO,   _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,   KC_END,    _______,    KC_NO,   KC_RSFT, KC_NO, \
      _______, _______, _______,                            _______,                              _______,   _______,    KC_NO,   _______, _______ \
  ),
  [_RAISE] = LAYOUT_all(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______, _______,  KC_NO, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______,          _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,            _______, \
      _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,   _______, KC_NO, \
      _______, _______, _______,                            _______,                              _______,   _______,    KC_NO,   _______, _______ \
  ),
  [_ADJUST] = LAYOUT_all(
      LOCAL,   REMOTE,  _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______, _______, KC_NO, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    _______,          _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,            _______, \
      _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,    KC_NO,   _______, KC_NO, \
      RESET,   _______, _______,                            _______,                              _______,   _______,    KC_NO,   _______, _______ \
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
        case I3LOC:
          if (record->event.pressed) {
            add_key(KC_LGUI);
            send_keyboard_report();
          } else {
            del_key(KC_LGUI);
            send_keyboard_report();
          }
          return false;
          break;
        case I3REM:
          if (record->event.pressed) {
            add_key(KC_LCTL);
            add_key(KC_LALT);
            add_key(KC_LGUI);
            send_keyboard_report();
          } else {
            del_key(KC_LCTL);
            del_key(KC_LALT);
            del_key(KC_LGUI);
            send_keyboard_report();
          }
          return false;
          break;
      }
    return true;
};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);
// const rgblight_segment_t PROGMEM local_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 12, HSV_PURPLE}
// );
const rgblight_segment_t PROGMEM remote_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CYAN}
);
const rgblight_segment_t PROGMEM local_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_WHITE}
);
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM custom_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//    local_layer,
    local_layer,
    remote_layer,
//    capslock_layer,
    lower_layer,
    raise_layer,
    adjust_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = custom_rgb_layers;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_LOCAL, layer_state_cmp(state, _LOCAL));
    rgblight_set_layer_state(_REMOTE, layer_state_cmp(state, _REMOTE));
    rgblight_set_layer_state(_LOWER, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
    return state;
}


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}


void matrix_scan_user(void) {
};

