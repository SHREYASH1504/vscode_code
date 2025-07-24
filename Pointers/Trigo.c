#include <stdio.h>
#include <math.h>
void normalise(double *p)
{
    int multiplier = *p / M_PI;
    *p -= M_PI * multiplier;
    if (multiplier % 2)
        *p -= (M_PI);
}
int main()
{
    double angle, originalAngle;
    printf("Give the angle in radians : ");
    scanf("%lf", &angle);
    originalAngle = angle;
    normalise(&angle);
    double sine = 0, cosine = 0;
    int i = 1;
    double terms = angle, termc = 1;
    int count = 0;
    while (fabs(terms) >= 0.0000001)
    {
        sine += terms;
        if ((count % 2) == 1)
            terms *= -1;
        count++;
        i += 2;
        terms *= (angle * angle) / (i * (i - 1));
        if ((count % 2) == 1)
            terms *= -1;
    }
    count = 0;
    i = 0;
    while (fabs(termc) >= 0.0000001)
    {
        cosine += termc;
        if ((count % 2) == 1)
            termc *= -1;
        count++;
        i += 2;
        termc *= (angle * angle) / (i * (i - 1));
        if ((count % 2) == 1)
            termc *= -1;
    }
    printf("\n\nsin(x) My program answer : %lf", sine);
    printf("\nsin(x) Library fn answer : %lf", sin(originalAngle));
    printf("\n\ncos(x) My program answer : %lf", cosine);
    printf("\ncos(x) Library fn answer : %lf", cos(originalAngle));
    return 0;
}