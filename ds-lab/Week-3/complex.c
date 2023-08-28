/* Implement Complex numbers using structures. Write functions to add, multiply, subtract two complex numbers. */
#include <stdio.h>

// Define a structure for complex numbers
struct Complex {
    double real;
    double imaginary;
};

// Function to add two complex numbers
struct Complex addComplex(const struct Complex* c1, const struct Complex* c2) {
    struct Complex result;
    result.real = c1->real + c2->real;
    result.imaginary = c1->imaginary + c2->imaginary;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtractComplex(const struct Complex* c1, const struct Complex* c2) {
    struct Complex result;
    result.real = c1->real - c2->real;
    result.imaginary = c1->imaginary - c2->imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(const struct Complex* c1, const struct Complex* c2) {
    struct Complex result;
    result.real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    result.imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
    return result;
}

int main() {
    struct Complex num1 = {3.0, 4.0};
    struct Complex num2 = {1.0, 2.0};

    struct Complex sum = addComplex(&num1, &num2);
    struct Complex difference = subtractComplex(&num1, &num2);
    struct Complex product = multiplyComplex(&num1, &num2);

    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imaginary);
    printf("Difference: %.2f + %.2fi\n", difference.real, difference.imaginary);
    printf("Product: %.2f + %.2fi\n", product.real, product.imaginary);

    return 0;
}
