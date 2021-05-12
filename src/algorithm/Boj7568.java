package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj7568 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		int[] weight = new int[N];
		int[] height = new int[N];
		
		for(int itr=0;itr<N;itr++) {
			
			String str[] = br.readLine().split(" ");
			weight[itr] = Integer.parseInt(str[0]);
			height[itr] = Integer.parseInt(str[1]);
			
		}
		
		
		for(int i=0;i<N;i++) {
			int count = 0;
			for(int j=0;j<N;j++) {
				
				if(weight[i]<weight[j] && height[i]<height[j]) {
					count++;
				}
			}
			
			sb.append(count+1).append(" ");
			
			
		}
		
		System.out.println(sb.toString());
		
	}

}
