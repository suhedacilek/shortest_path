#include <stdio.h>

int find_path (int matrix[][12] , int , int);
int r_move (int matrix[][12] , int , int , int);
int l_move (int matrix[][12] , int , int , int);
int u_move (int matrix[][12] , int , int , int);
int d_move (int matrix[][12] , int , int , int);

int find_path (int matrix[][12] , int x , int y){
	
	int counter = 0 ;
	int c_move = 0 ;
	
	if ( matrix [x + 1][y] == 1)                   
		counter = d_move(matrix , x , y , c_move );
		
	else if ( matrix [x][y + 1] == 1)
		counter = r_move(matrix , x , y , c_move); 
		
	return counter;
		
}
int d_move(int d_path [][12] , int d1 , int d2 , int d_count){
	
	
	if(d1 == 5) 
		return 0;  
	if(d1 + 1 == 5 && d2 == 11) {
		printf("%d  step is the shortest path  \n" , d1 + 1); 
		return 1;
	}
	if (d_path [d1 + 2][d2] != 1 && d_path [d1 + 1][d2 + 1] != 1 && d_path [d1 + 1][d2 - 1] != 1 ) 
		return 0; // Eðer koþullar saðlanmýyorsa 0 dönüyor.
	
	d1++; d_count++; 

	if (d_path [d1 + 1][d2] == 1) .
		if(d_move(d_path ,d1 ,d2 ,d_count) > 0){ 
			printf("%d,%d\n",d1,d2);
		return d_count;  
		}
	
	
	if (d_path [d1][d2 + 1] == 1) 
		if(r_move(d_path ,d1 ,d2 ,d_count) > 0){
			printf("%d,%d\n",d1,d2);
			return d_count;
		}
			
	
	if (d_path [d1][d2 - 1] == 1) 
		if(l_move(d_path ,d1 ,d2 ,d_count) > 0){
			printf("%d,%d\n",d1,d2);
		return d_count;
	
		}
			
	return 0;
}

int r_move(int r_path [][12] ,int r1 ,int r2 ,int r_count )
{
	
	if (r2 == 11) 
		return 0 ;
	if (r1 == 5 && r2 + 1 == 11){ 
		printf("%d  step is the shortest path \n", ++r_count) ; 
			return 1;
	}
		
	if (r_path [r1][r2 + 2] != 1 && r_path [r1 + 1][r2 + 1] != 1 && r_path [r1 - 1][r2 + 1] != 1 )
		return 0;
	
	r2++; r_count++;
	
	if (r_path [r1 + 1][r2] == 1)
		if(d_move(r_path ,r1 ,r2 ,r_count) > 0) {
				printf("%d,%d\n",r1,r2);
		return r_count ;

		}
		
	
	if (r_path [r1][r2 + 1] == 1)
		if(r_move(r_path ,r1 ,r2 ,r_count) > 0 ){
				printf("%d,%d\n",r1,r2);
		return r_count ;
		}
	
	if (r_path [r1 - 1][r2] == 1)
		if(u_move(r_path ,r1 ,r2 ,r_count) > 0 ){
			printf("%d,%d\n",r1,r2);
		return r_count ;
		}
			
	return 0;
}

int l_move(int l_path [][12] ,int l1 ,int l2 ,int l_count )
{
	
	if (l2 == 0 )
		return 0;
	if (l_path [l1][l2 - 2] != 1 && l_path [l1 - 1][l2 - 1] != 1 && l_path [l1 + 1][l2 - 1] != 1 )
		return 0;
	
	l2--; l_count++;
	
	if (l_path [l1 + 1] [l2] == 1)
		if(d_move(l_path ,l1 ,l2 ,l_count) > 0 ) {
			printf("%d,%d\n",l1,l2);
		return l_count ;
		}
		
	if (l_path [l1] [l2 - 1] == 1)
		if(l_move(l_path ,l1 ,l2 ,l_count) > 0 ){
			printf("%d,%d\n",l1,l2);
		return l_count;
		}
			
	if (l_path [l1 - 1] [l2] == 1)
		if(u_move(l_path ,l1 ,l2 ,l_count ) > 0 ) {
			printf("%d,%d\n",l1,l2);
		return l_count;
		}		
	return 0;
}

int u_move(int u_path [][12] ,int u1 ,int u2 ,int u_count )
{
	
	if ( u1 == 0 ) 
		return 0;
	if (u_path [u1 - 2][u2] != 1 && u_path [u1 - 1][u2 + 1] != 1 && u_path [u1 - 1][u2 - 1] != 1 )
		return 0;
	
	u1--; u_count++; 
	
	if (u_path [u1] [u2 + 1] == 1)
		if(r_move(u_path ,u1 ,u2 ,u_count) > 0 ){
				printf("%d,%d\n",u1,u2);
	    return u_count;
		}
		
	if (u_path [u1] [u2 - 1] == 1)
		if(l_move(u_path ,u1 ,u2 ,u_count ) > 0 ){
				printf("%d,%d\n",u1,u2);
		return u_count;
		}
		
	if (u_path [u1 - 1] [u2] == 1)
		if(u_move(u_path ,u1 ,u2 ,u_count) > 0 ) {
			printf("%d,%d\n",u1,u2);
		return u_count;
		}
	return 0;

}
	
int main(){
	int a = 0 , b = 0 , m , n; 
	int myMatrix[6][12] = {{1,0,1,1,1,0,0,1,0,1,1,0}
			    , {1,0,1,1,1,1,1,0,1,0,0,0} 
			    , {1,1,1,1,1,1,1,0,1,0,1,0}
	             	    , {0,1,0,1,0,1,0,1,1,1,1,1} 
			    , {0,1,0,1,1,1,1,1,0,0,0,1} 
			    , {1,1,1,0,1,1,1,1,1,1,1,1}};
	for(m = 0; m < 6; m++){
		for( n = 0; n < 12; n++){
			printf("%d " , myMatrix[m][n]);
		}
	
	printf("\n ");
	}
	find_path(myMatrix , a , b); 

}


