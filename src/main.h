int check_user_input(char *input);

// supporting enum for fn check_user_input()
enum check_user_input_state
{
    DIGITS,
    DECIMAL,
    EXPONENT_SIGN,
    EXPONENT,
};
