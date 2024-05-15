code



#include<stdio.h> #include<stdlib.h> #include<math.h> int main(){
int RequestQueue[15],n,i,j,k,initial,temp,max,tracks,disklocation,TotalHeadmovement; int direction;
printf("Enter the Number of tracks:");

scanf("%d",&tracks);

printf("Enter total number of Requests:"); scanf("%d",&n);
printf("Enter the request Queue:");

for(i=0;i<n;i++){

scanf("%d",&RequestQueue[i]); max=RequestQueue[i];
}



int first=RequestQueue[0];

printf("Enter the initial position of Head:"); scanf("%d",&initial);
printf("Enter the direction:Choose 1-Left or Choose 2-Right:");

scanf("%d",&direction);



RequestQueue[n]=initial; n=n+1;


for(i=0;i<n;i++){ for(j=i;j<n;j++){
if(RequestQueue[i]>RequestQueue[j]){

temp=RequestQueue[i]; RequestQueue[i]=RequestQueue[j];  RequestQueue[j]=temp;
}

}

}





for(i=0;i<n;i++){

if(initial==RequestQueue[i]){ disklocation=i;
break;

}

}

switch(direction){ case 1:
{

for(j=disklocation;j>=0;j--){

printf("%d-->",RequestQueue[j]);

}

printf("0-->");

for(k=disklocation+1;k<n;k++){

printf("%d-->",RequestQueue[k]);

}

TotalHeadmovement= (initial)+max;

printf("\nTotal Head Movement is:%d",TotalHeadmovement);

}

break;



case 2:

{

for(j=disklocation;j<n;j++){

printf("%d-->",RequestQueue[j]);

}

printf("%d-->",tracks-1);

for(k=disklocation-1;k>=0;k--){

printf("%d-->",RequestQueue[k]);

}

TotalHeadmovement= (tracks-1-initial)+(tracks-1-RequestQueue[0]); printf("\nTotal Head Movement is:%d",TotalHeadmovement);
}

break;



default:

printf("Enter Valid choice!!!!"); break;


}



return 0;

}
