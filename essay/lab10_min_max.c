#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double Array[5]={3, 6, 1, 8, 12};
    int N=5;
    int i;
    double min_el=Array[0];
    int ind_min_el=0;
    for(i=1; i<N; i++)
    {
        if(min_el>Array[i])
        {
            min_el = Array[i];
            ind_min_el = i;
        };
    };
    printf("Minimum value in array is %f and its index is %d\n", min_el, ind_min_el);
    return 0;
}

// int main()
// {
//     double Array[5]={3, 6, 1, 8, 12};
//     int N=5;
//     int i;
//     double max_el=Array[0];
//     int ind_max_el=0;
//     for(i=1; i<N; i++)
//     {
//         if(max_el<Array[i])
//         {
//             max_el = Array[i];
//             ind_max_el = i;
//         };
//     }
//     printf("Maximum value in array is %f and its index is %d\n", max_el, ind_max_el);
//     return 0;
// }
