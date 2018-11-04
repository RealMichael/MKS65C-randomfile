#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>



int populate(){
   int i = 0;
   //int rando = open("/dev/random",0_RDONLY);
   int rando = open("/dev/random", O_RDONLY);
  // while(i < 10){
     // read(rando, &res[i], sizeof(int));
    //  printf("Number %d: %d\n",i,res[i]);
  //  }
 //   return res;
 // }

	int reada = read(rando,&i,sizeof(int));
	close(rando);
	return i;
}




int main(){
    int ary[10];
    int ary2[10];
	   int i = 0;
	printf("Random Numbers\n");
	while(i < 10){
	ary[i] = populate();
	printf("Number %d: %d\n",i,ary[i]);
	i ++;
	}

	printf("Writing Numbers\n");
	int writer = open("test.txt",O_WRONLY);
	write(writer,ary,10 * sizeof(int));
	close(writer);

	printf("Reading Numbers\n");
	int writer2 = open("test.txt",O_WRONLY);
	read(writer2,ary2,10 * sizeof(int));
	close(writer2);

	printf("Verification\n");
	int i2 = 0;
	while(i2 < 10){
	printf("Number %d: %d\n",i2,ary[i2]);
	i2 ++;
	}

	
return 0;
}





