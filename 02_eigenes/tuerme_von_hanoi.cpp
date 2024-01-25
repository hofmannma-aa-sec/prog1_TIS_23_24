#include <stdio.h>
//#include

// Functionen deklarieren
int sort_tuerme(int turm_a[], int turm_b[], int turm_c[]);

int main(int argc, char const *argv[])
{
    int turm_a[5] = {6,5,4,0,0};
    int turm_b[5] = {1,0,0,0,0};
    int turm_c[5] = {3,2,0,0,0};
    sort_tuerme(turm_a, turm_b, turm_c);
    return 0;
}
int sort_tuerme(int turm_a[], int turm_b[], int turm_c[])
{
    
    if((turm_a == 0) && (turm_b == 0))
    {
       return turm_a, turm_b, turm_c;
    } 
        
    else
    {
         
        sort_tuerme(turm_a,turm_b, turm_c);
    }
        
}