
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

#define GRAVITY 16            // 1.62 m/s² * 10 (scaled by 10)
#define TIME_STEP 10          // 1.0 seconds * 10
#define MAX_THRUST 50         // 5.0 * 10
#define SAFE_LANDING_SPEED 50 // 5.0 m/s * 10

int main()
{
    int altitude = 1000; // 100.0 meters * 10
    int velocity = 0;    // m/s * 10
    int fuel = 500;      // 50.0 units * 10
    int thrust = 0;      // 0.0 to 5.0 * 10
    int step = 0;

    int acceleration = 0;

    clrscr();
    printf("=== Lunar Lander ===\n");
    printf("Altitude: %d.%d m | Fuel: %d.%d units\n\n", altitude / 10, altitude % 10, fuel / 10, fuel % 10);
    printf("Step|ALT  |VEL  |Fuel\n");
    while (altitude > 0)
    {
        printf("%4d ", ++step);
        printf("%3d.%d %3d.%d %2d.%d ",
               altitude / 10, altitude % 10, velocity / 10, velocity % 10, fuel / 10, fuel % 10);

        if (fuel > 0)
        {
            printf("Burn?->");
            scanf("%d", &thrust);

            if (thrust < 0)
                thrust = 0;
            if (thrust > MAX_THRUST)
                thrust = MAX_THRUST;
            if (thrust > fuel)
                thrust = fuel;
        }
        else
        {
            printf("Out of fuel!\n");
            thrust = 0;
        }

        fuel -= thrust;
        acceleration = GRAVITY - thrust; // acceleration scaled by 10
        velocity += acceleration * TIME_STEP / 10;
        altitude -= velocity * TIME_STEP / 10;

        if (altitude < 0)
            altitude = 0;
    }

    printf("\n*** Landing Results ***\n");
    printf("Final velocity: %d.%d m/s\n", velocity / 10, velocity % 10);
    if (velocity <= SAFE_LANDING_SPEED)
    {
        printf("Safe landing!\n");
    }
    else
    {
        printf("Crash landing. Impact too fast!\n");
    }

    return 0;
}
