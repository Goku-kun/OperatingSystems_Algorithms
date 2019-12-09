import java.lang.*;
import java.util.*;

class fibo extends Thread {
		static int i;
		static int f[]=new int[50];
		public fibo(int i) {
			this.i = i;
		}
  	public void run() {

  		if(i==0) {
	  		f[i]=0;
  		}
  		else if(i==1) {
	  		f[i]=1;
  		}
  		else {
   			f[i]=f[i-1]+f[i-2];
  		}
  }

	public static void main(String args[]) {
  	System.out.println("Enter number for the fibonnaci sequence to be printed:");
  	Scanner sc = new Scanner(System.in);
  	int n = sc.nextInt();
  	fibo fo[] = new fibo[n];
  	System.out.println("Fibonnaci Series is as follows:");
  	for(i=0; i<n; i++) {
    	fo[i]= new fibo(i);
			fo[i].start();
			try {
				fo[i].join();
			} catch(Exception e) {
			}
  	}
  	for(i=0; i<n; i++) {
	   	System.out.println(f[i]);
  	}
	}
}
