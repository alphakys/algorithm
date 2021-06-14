package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Boj2751 {
	
	public void arrSort(int[] arr) {
			
			
	}
	
	public static void main(String[] args)throws IOException {
		/*
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N];
		
		for(int i=0; i<N;i++) {
			int num = Integer.parseInt(br.readLine());
			arr[i] = num;
		}
		
		*/
		
	int ar[] = {2,4,6,8};
	int ar1[] = {10,5,7,9};
	
	int sort[] = new int[8];
	
	int size = ar.length;
	
	int f = 0;
	int p = 0;
	int i = 0;

	while(f<3 || p<3) {
		
	
			if(ar[f] > ar1[p]) {
				System.out.println("p--"+p);
				sort[i] = ar1[p];
				System.out.println("p:"+sort[i]);
				i++;p++; 
			}
			else{
				System.out.println("f--"+f);
				sort[i] = ar[f];
				System.out.println("f:"+sort[i]);
				i++;f++;
			}
		
	
	}
		
	
	
	
	
	
	
	}

}