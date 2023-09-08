#include <stdio.h>

struct CountsBySoH {
    int healthy;
    int exchange;
    int failed;
};

struct CountsBySoH countBatteriesByHealth(int presentCapacities[], int numBatteries) {
    struct CountsBySoH counts;
    counts.healthy = 0;
    counts.exchange = 0;
    counts.failed = 0;

    for (int i = 0; i < numBatteries; i++) {
        int presentCapacity = presentCapacities[i];
        double soh = ((double)presentCapacity / 120.0) * 100.0; // Assuming rated capacity is 120 Ah

        if (soh > 80.0) {
            counts.healthy++;
        } else if (soh >= 65.0) {
            counts.exchange++;
        } else {
            counts.failed++;
        }
    }

    return counts;
}

void testBucketingByHealth() {
    printf("Counting batteries by SoH...\n");
    int presentCapacities[] = {115, 118, 80, 95, 91, 77};
    int numBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
    struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numBatteries);

    if (counts.healthy == 2 && counts.exchange == 3 && counts.failed == 1) {
        printf("Tests passed successfully.\n");
    } else {
        printf("Tests failed.\n");
    }
}

int main() {
    testBucketingByHealth();
    return 0;
}

