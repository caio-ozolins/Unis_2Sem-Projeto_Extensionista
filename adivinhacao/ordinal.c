char *get_ordinal (char **ordinals, int value)
{
    value %= 100;  /* normalize values between 0-100 */

    if (3 < value && value < 21)
        return ordinals[3];

    switch (value % 10) {
        case 1 :
            return ordinals[0];
        case 2 :
            return ordinals[1];
        case 3 :
            return ordinals[2];
        default:
            return ordinals[3];
    }
}