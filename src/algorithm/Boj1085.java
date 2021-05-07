package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1085 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		String str[] = br.readLine().split(" ");
		
		int[] arr = new int[4];
		
		for(int i=0;i<arr.length;i++) {
			arr[i] = Integer.parseInt(str[i]);
		}
		int[] distance = new int[4];
		
		distance[0] = arr[2]-arr[0];
		distance[1] = arr[0];
		distance[2] = arr[3]-arr[1];
		distance[3] = arr[1];
		
		int min = distance[0];
		
		for(int j=1; j<4;j++) {
			
			if(min>distance[j]) {
				min = distance[j];
			}
		}
		
		System.out.println(min);
	}

}
