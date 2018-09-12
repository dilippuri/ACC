#include<stdio.h>
#include<float.h>
#include<stdlib.h>

#define ppp 10
int count = 0;
int count1 = 0;

struct line{
	int k;//label
	float m;//slope
	float b;//intercept
}lines[ppp];

struct point{//(x,y) pair
	float x;
	float y;
}points[ppp];


int compare(const struct line *a, const struct line *b)
{
    if (a->m < b->m) return -1;
    if (a->m == b->m) return 0;
    if (a->m > b->m) return 1;
}

struct point intersectPt(struct line l1, struct line l2){
	struct point pt;
	float m1,m2,c1,c2;
	m1=l1.m; m2=l2.m;
	c1=l1.b; c2=l2.b;
	if(m1==m2){
		pt.x = FLT_MAX;
		pt.y = FLT_MAX;
		return pt;
	}
	else{
		pt.x = (c1-c2)/(m2-m1);
		pt.y = m1*(pt.x) + c1;
		return pt;
	}
	
}
void addLine1(struct line l1){
	lines[count] = l1;
	count++;
}
void addLine2(struct line l1, struct line l2){
	if(l1.m != l2.m){
		struct point p,q;
		p = intersectPt(lines[0],lines[2]);
		lines[count] = l1;
		count++;
		lines[count] = l2;
		count++;
		points[count1]=p;
	}
	else{
		if(l1.b <= l2.b){
			lines[count]=l2;
			count++;
		}
		else{
			lines[count]=l1;
			count++;
		}
	}
}

void addLine3(struct line l1,struct line l2,struct line l3){
	struct line tlns[3];
	tlns[0]=l1; tlns[1]=l2; tlns[2]=l3;
	qsort(tlns, 3, sizeof(struct line), (int (*)(const void*, const void*)) compare);

	if(tlns[0].m != tlns[2].m){

		lines[count]=tlns[0];
		count++;

		struct point p,q;
		p = intersectPt(tlns[0],tlns[2]);
		q = intersectPt(tlns[0],tlns[1]);

		if(p.x > q.x){
			lines[count]=tlns[1];
			count++;
			lines[count]=tlns[2];
			count++;
			points[count1]=q;
			count1++;
			points[count1]=p;
			count1++;
		}
		else{
			lines[count]=tlns[2];
			count++;
			points[count1]=p;
			count1++;
		}
	}
	else{
		addLine2(tlns[0], tlns[2]);
	}
}

void addLine(struct line l){
	int i=count-1;
	while(i>1){
		if(l.m > lines[i].m){
			break;
		}
		i--;
	}
	if(count>=3){
		struct point cross = intersectPt(lines[i],l);
		if(cross.x > points[i-1].x){
			lines[count]=l;
			count++;
			points[count1]=cross;
			count1++;
		}
		else{
			int j=count1-1;
			while(cross.x < points[count-2].x && j>0){
				count--;j--;
			}
			count1 = count-1;
			lines[count]=l;
			count++;
			points[count1]=cross;
			count1++;
		}
	}
	else if(count==2){
		count=0;count1=0;
		addLine3(lines[0],lines[1],l);
	}
	else if(count==1){
		count=0;count1=0;
		addLine2(lines[0],l);
	}
	else{
		count=0;count1=0;
		addLine1(l);
	}

}

int main(){
	int n,i;
	printf("Enter no of lines: ");
	scanf("%d",&n);


	struct line lns[n];
	struct point pts[n];
/*	
	n=7;
	lns[0].m=-4;	lns[0].b=4;		lns[0].k=1;
	lns[1].m=-1.5;	lns[1].b=3;		lns[1].k=2;
	lns[2].m=-0.16667;	lns[2].b=1;	lns[2].k=3;
	lns[3].m=0.2;	lns[3].b=-1;	lns[3].k=4;
	lns[4].m=0.5;	lns[4].b=-2;	lns[4].k=5;
	lns[5].m=1;		lns[5].b=-10;	lns[5].k=6;
	lns[6].m=2;		lns[6].b=-2;	lns[6].k=7;

	n=3;
	lns[0].m=-5;	lns[0].b=10;	lns[0].k=1;
	lns[1].m=6;		lns[1].b=0;		lns[1].k=2;
	lns[2].m=0;		lns[2].b=3;		lns[2].k=3;

	n=4;
	lns[0].m=7;		lns[0].b=10;	lns[0].k=1;
	lns[1].m=3;		lns[1].b=2;		lns[1].k=2;
	lns[2].m=-3;	lns[2].b=3;		lns[2].k=3;
	lns[3].m=-7;	lns[2].b=5;		lns[2].k=3;
*/

	for(i=0;i<n;i++){
		float m,b,k;
		printf("Enter slope of line-%d: ",i);
		scanf("%f", &m);
		lns[i].m=m;
		printf("Enter intercept of line-%d: ",i);
		scanf("%f", &b);
		lns[i].b=b;
		lns[i].k=i;
	}



	printf("----------------------\n");
	for(i=0;i<n;i++){
		printf("l%d - m: %.1f, b: %.1f\n",lns[i].k, lns[i].m, lns[i].b);
	}
	qsort(lns, n, sizeof(struct line), (int (*)(const void*, const void*)) compare);

	printf("----------------------\n");

	addLine3(lns[0],lns[1],lns[2]);
for(i=3;i<n;i++){
/*	if(i==1){
	printf("send 1\n");
		addLine1(lns[0]);
	}
	else if(i==2){
	printf("send 2\n");
		addLine2(lns[0],lns[1]);
	}
	else if(i==3){
	printf("send 3\n");
		addLine3(lns[0],lns[1],lns[2]);
	}
	else{}
*/	
	addLine(lns[i]);
	qsort(lines, count-1, sizeof(struct line), (int (*)(const void*, const void*)) compare);
}
	for(i=0;i<count;i++){
		printf("l%d - m: %.2f, b: %.2f\n",lines[i].k, lines[i].m, lines[i].b);
	}
	printf("----------------------\n");
	for(i=0;i<count1;i++){
		printf("p%d - x: %.2f, y: %.2f\n",i, points[i].x, points[i].y);
	}
	printf("----------------------\n");
	return 0;
}
