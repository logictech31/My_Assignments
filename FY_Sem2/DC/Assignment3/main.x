struct values {
    float num1;
    float num2;
    char operation;
};

program compute {
    version COMPUTE_VERSION {
        float ADD(values) = 1;
        float SUB(values) = 2;
        float DIV(values) = 3;
        float MUL(values) = 4;
    } = 6;
} = 0x03589032;