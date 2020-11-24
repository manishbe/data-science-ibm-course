//crack trajectory
//1e-7 metres
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
double kf = 0.133;
double H = 0.75;
double x=0,y=1,yminus,yplus;
double value_y,value_yplus,value_yminus,p_y,p_yplus,p_yminus,p_max;
int num,upper=4,lower=1;
srand(time(0));

FILE *out=fopen("crack_probability.csv","w");
for(x=7.5;x<=100000;x=x+7.5)
{
num = (rand() % (upper - lower + 1)) + lower;

//value_y=-(y*y)/(4*kf*(pow(x,2*H)));
//p_y=(exp(value_y))/(sqrt((4*M_PI*kf*(pow(x,2*H)))));

yminus=y-7.5;
value_yminus=-(yminus*yminus)/(4*kf*(pow(x,2*H)));
p_yminus=(exp(value_yminus))/(sqrt((4*M_PI*kf*(pow(x,2*H)))));

//if(p_y < p_yminus)
//{
//y=yminus;
//p_max=p_yminus;
//}
//else y=y,p_max=p_y;

yplus=y+4.5;
value_yplus=-(yplus*yplus)/(4*kf*(pow(x,2*H)));
p_yplus=(exp(value_yplus))/(sqrt((4*M_PI*kf*(pow(x,2*H)))));

if(p_yminus < p_yplus)
{
y=yplus;
p_max=p_yplus;
}
else y=yminus,p_max=p_yminus;

fprintf(out,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\n",x,y,p_y,p_yminus,p_yplus,p_max,value_y,exp(value_y));
}
fclose(out);
}
