<?php

/**
 * @file
 * Views handler for displaying a log message.
 */

class feeds_views_handler_field_log_message extends views_handler_field {

  /**
   * Override parent::render().
   */
  function render($values) {
    $message = $values->{$this->field_alias};
    $variables = unserialize($values->{$this->aliases['variables']});
    //return t($message, $variables);
    // We do not use t() here anymore because sometimes the $message, in our
    // case, can be very big (in the case of some sql errors it also show the
    // original item that was imported which is huge sometimes) and it generates
    // an sql error because the source field in the locale table is too small
    // for it (it is blob).
    return format_string($message, $variables);
  }

  /**
   * Disallow advanced rendering.
   */
  function allow_advanced_render() {
    return FALSE;
  }
}
