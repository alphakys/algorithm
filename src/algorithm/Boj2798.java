package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2798 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str[] = br.readLine().split(" ");
		
		int N = Integer.parseInt(str[0]);
		int M = Integer.parseInt(str[1]);
		
		String card[] = br.readLine().split(" ");
		
		int[] numArr = new int[N];
		
		for(int k=0; k<N; k++) {
			
			int num = Integer.parseInt(card[k]);
			numArr[k] = num; 
		}
		
		int max=0;
		
		for(int i=0; i<N-2; i++) {
			
			for(int j=i+1; j<N-1 ;j++) {
				
				for(int a=j+1; a<N ;a++) {
					
					int sum = numArr[i]+numArr[j] + numArr[a];
					
					if(sum==M) {
						max = sum;
						break;
					}else if(sum<M){
					
						if(sum>max) {
							max = sum;
						}
					
					}
					
				}
					
			}
		}
		
		System.out.println(max);
	
	}

}
