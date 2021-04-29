package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1712 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		
		int[] cost = new int[3];
		
		for(int i=0;i<3;i++) {
			cost[i] = Integer.parseInt(str[i]);
		}
		
		if((cost[2]-cost[1])<1) {
			System.out.println(-1);
		}else {
			int answer = (cost[0]/(cost[2]-cost[1]))+1;
			System.out.println(answer);
		}
		
		
		


	}

}
