#include "demofunction.h"
#include <stdio.h>
#include <math.h>

float add(float a,float b){
    return a+b;
}

float subtract(float a,float b){
    return a-b;
}

float multiply(float a,float b){
    return a*b;
}

float divide(float a,float b){
    if (b==0){
        fprintf(stderr,"Error:Undefined...");
        return 0;
    }
return (float)a/b;
}

float modulus(float a,float b){
    int x=(int)a;
    int y=(int)b;
     if (y==0){
        fprintf(stderr,"Error:Undefined...");
        return 0;
    }
 return x%y;
}
