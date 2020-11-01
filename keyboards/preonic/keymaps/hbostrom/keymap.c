/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *

  #include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

typedef union {
  uint32_t raw;
  struct {
    bool remote:1;
  };
} user_config_t;
user_config_t user_config;

#define IS_REMOTE()   (user_config.remote)

enum custom_keycodes {
  LOCAL = SAFE_RANGE,
  REMOTE,
  LOWER,
  RAISE,
  ADJUST,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;


enum {
    SINGLE_HOLD = 1,
    DOUBLE_HOLD
};

// Tap dance enums
enum {
    MODSFT,
    CTLSFT
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

void modsft_finished(qk_tap_dance_state_t *state, void *user_data);
void modsft_reset(qk_tap_dance_state_t *state, void *user_data);

void ctlsft_finished(qk_tap_dance_state_t *state, void *user_data);
void ctlsft_reset(qk_tap_dance_state_t *state, void *user_data);

#define TD_MSFT TD(MODSFT)
#define TD_CSFT TD(CTLSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TD_MSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    TD_CSFT,  LOWER,  KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, _______, _______, _______, _______, _______,          _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_BSPC,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MSTP, KC_MPRV,                            KC_MPLY, KC_MNXT, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LOCAL,   REMOTE,  _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, RESET,            RESET,   _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
      return SINGLE_HOLD;
    } else if (state->count == 2) {
      return DOUBLE_HOLD;
    }
   return 8;
}

static tap modsft_state = {
    .is_press_action = true,
    .state = 0
};

void modsft_finished(qk_tap_dance_state_t *state, void *user_data) {
  modsft_state.state = cur_dance(state);
  switch (modsft_state.state) {
    case SINGLE_HOLD:
      if(IS_REMOTE()){
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
      } else {
        register_code(KC_LGUI);
      }
      break;
    case DOUBLE_HOLD:
      register_code(KC_LSFT);
      if(IS_REMOTE()){
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
      } else {
        register_code(KC_LGUI);
      }
      break;
  }
}

void modsft_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (modsft_state.state) {
    case SINGLE_HOLD:
      if(IS_REMOTE()){
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
      }
      break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      if(IS_REMOTE()){
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
      }
      break;
  }
  modsft_state.state = 0;
}

static tap ctlsft_state = {
    .is_press_action = true,
    .state = 0
};

void ctlsft_finished(qk_tap_dance_state_t *state, void *user_data) {
  ctlsft_state.state = cur_dance(state);
  switch (ctlsft_state.state) {
    case SINGLE_HOLD:
      register_code(KC_LCTL);
      break;
    case DOUBLE_HOLD:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      break;
  }
}

void ctlsft_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (ctlsft_state.state) {
    case SINGLE_HOLD:
      unregister_code(KC_LCTL);
      break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      break;
  }
  ctlsft_state.state = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [MODSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, modsft_finished, modsft_reset),
    [CTLSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctlsft_finished, ctlsft_reset)
};

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOCAL:
      if (record->event.pressed) {
        user_config.remote = false;
        eeconfig_update_user(user_config.raw);
      }
      return false;
      break;
    case REMOTE:
      if (record->event.pressed) {
        user_config.remote = true;
        eeconfig_update_user(user_config.raw);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}


 */

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

typedef union {
  uint32_t raw;
  struct {
    bool remote:1;
  };
} user_config_t;
user_config_t user_config;

#define IS_REMOTE()   (user_config.remote)

enum custom_keycodes {
  LOCAL = SAFE_RANGE,
  REMOTE,
  LOWER,
  RAISE,
  ADJUST,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;


enum {
    SINGLE_HOLD = 1,
    DOUBLE_HOLD
};

// Tap dance enums
enum {
    MODSFT,
    CTLSFT
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

void modsft_finished(qk_tap_dance_state_t *state, void *user_data);
void modsft_reset(qk_tap_dance_state_t *state, void *user_data);

void ctlsft_finished(qk_tap_dance_state_t *state, void *user_data);
void ctlsft_reset(qk_tap_dance_state_t *state, void *user_data);

#define TD_MSFT TD(MODSFT)
#define TD_CSFT TD(CTLSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_preonic_grid(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TD_MSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, TD_CSFT,  LOWER,  KC_ENT,  KC_SPC,  RAISE,   KC_RALT, _______, _______, _______
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_LOWER] =  LAYOUT_preonic_grid(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, KC_BSPC,  _______, _______, _______, _______, _______
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT_preonic_grid(
     KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______,
     _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, _______, _______, _______, _______, _______, _______, _______,
     _______, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_preonic_grid(
     LOCAL,   REMOTE,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
     _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
     RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
  )

};

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
      return SINGLE_HOLD;
    } else if (state->count == 2) {
      return DOUBLE_HOLD;
    }
   return 8;
}

static tap modsft_state = {
    .is_press_action = true,
    .state = 0
};

void modsft_finished(qk_tap_dance_state_t *state, void *user_data) {
  modsft_state.state = cur_dance(state);
  switch (modsft_state.state) {
    case SINGLE_HOLD:
      if(IS_REMOTE()){
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
      } else {
        register_code(KC_LGUI);
      }
      break;
    case DOUBLE_HOLD:
      register_code(KC_LSFT);
      if(IS_REMOTE()){
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
      } else {
        register_code(KC_LGUI);
      }
      break;
  }
}

void modsft_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (modsft_state.state) {
    case SINGLE_HOLD:
      if(IS_REMOTE()){
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
      }
      break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      if(IS_REMOTE()){
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
      }
      break;
  }
  modsft_state.state = 0;
}

static tap ctlsft_state = {
    .is_press_action = true,
    .state = 0
};

void ctlsft_finished(qk_tap_dance_state_t *state, void *user_data) {
  ctlsft_state.state = cur_dance(state);
  switch (ctlsft_state.state) {
    case SINGLE_HOLD:
      register_code(KC_LCTL);
      break;
    case DOUBLE_HOLD:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      break;
  }
}

void ctlsft_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (ctlsft_state.state) {
    case SINGLE_HOLD:
      unregister_code(KC_LCTL);
      break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      break;
  }
  ctlsft_state.state = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [MODSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, modsft_finished, modsft_reset),
    [CTLSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctlsft_finished, ctlsft_reset)
};

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOCAL:
      if (record->event.pressed) {
        user_config.remote = false;
        eeconfig_update_user(user_config.raw);
      }
      return false;
      break;
    case REMOTE:
      if (record->event.pressed) {
        user_config.remote = true;
        eeconfig_update_user(user_config.raw);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
