<?php

/**
 * @file
 * Admin page callbacks for the password strength module.
 */

/**
 * Form builder for password strength form.
 *
 * @see system_settings_form()
 * @ingroup forms
 */
function password_strength_settings() {

  $config = config('password_strength.settings');
  $form['#config'] = 'password_strength.settings';
  $desc = t("Password strengths are measured and based both on the amount of entropy (randomness) in the password and an estimate of the amount of time it could take to crack the password using brute-force attempts. The estimated time to crack at each level is about two orders of magnitude greater than the next lower level, so a Weak password can be cracked nearly instantly, while a Very strong password might take years.");
  $form['description'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . $desc . '</p>',
  );
  $form['default_required_score'] = array(
    '#type' => 'select',
    '#title' => t('Minimum required password strength'),
    '#description' => t('The minimum strength required for user account passwords.'),
    '#default_value' => $config->get('default_required_score'),
    '#options' => password_strength_score_list(),
  );
  $form['default_required_score']['#options'][0] = t('disabled');
  $form['test'] = array(
    '#type' => 'fieldset',
    '#title' => 'Test password strength',
    '#description' => t('Try different passwords to see what strength they are.'),
    '#collapsible' => TRUE,
    '#collapsed' => $config->get('default_required_score'),
  );
  $form['test']['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password test'),
    '#attributes' => array(
      'class' => array('password-field'),
    ),
  );
  global $user;
  password_strength_form_password_js_attach($form['test']['password'], $user);

  $form['default_password_length'] = array(
    '#type' => 'number',
    '#title' => t('Minimum password length'),
    '#size' => 4,
    '#description' => t('The minimum password length in number of characters.'),
    '#default_value' => $config->get('default_password_length'),
  );

  return system_settings_form($form);
}
