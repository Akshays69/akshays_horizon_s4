#include<stdio.h>
#include<math.h>
int main(){
float x1,x2,y1,y2,d,i,a,t,time;
printf("enter the origin coordinates:-");
scanf(" %f, %f",&x1,&y1);
printf("enter the destination coordinates:-");
scanf(" %f ,%f",&x2,&y2);
printf("enter the initial velocity:-");
scanf(" %f",&i);
printf("enter the acceleration:-");
scanf(" %f",&a);
printf("enter top speed:-");
scanf(" %f",&t);


d= sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
printf("\n distance to destination:- %.2f",d);
printf("m");
float d1=(t*t-i*i)/(2*a);
if(d<d1)
{
     time=(-i+sqrt((i*i)+(2*a*d))/a);
}
else{
    float s1=d1;
    float time1= (t-i)/a;
    float s2=d-s1;
    float time2=s2/t;
    time=time1+time2;

}
printf("\n time required:- %.2f",time);
printf("seconds");
return 0;
}