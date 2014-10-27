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
    if (drupal_strlen($message) > 65000) {
      // Messages that are too long may generate a PDO exception when calling t()
      // if Drupal tries to add them in `locales_source` table
      return format_string($message, $variables);
    }
    else {
      return t($message, $variables);
    }
  }

  /**
   * Disallow advanced rendering.
   */
  function allow_advanced_render() {
    return FALSE;
  }
}
