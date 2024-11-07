int num_len(int num) {
    int len = 0;
    if (num <= 0) {
        len++;
        num = -num;
    }
    while (num) {
        len++;
        num /= 10;
    }
    return len;
}

int num_len_unsigned(unsigned int num) {
    int len = 0;
    if (num == 0) return 1;  // Special case for 0
    while (num) {
        len++;
        num /= 10;
    }
    return len;
}

int num_len_hex(unsigned int num) {
    int len = 0;
    if (num == 0) return 1;  // Special case for 0
    while (num) {
        len++;
        num /= 16;
    }
    return len;
}
