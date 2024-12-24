#include <stdio.h>

// Συνάρτηση add που λαμβάνει δείκτες σε τρεις ακέραιους και επιστρέφει το άθροισμά τους
int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x, y, z;

    // Εισαγωγή τριών ακέραιων αριθμών
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    // Κλήση της add() και εκτύπωση του αποτελέσματος
    int sum = add(&x, &y, &z);
    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, sum);

    return 0;
}
