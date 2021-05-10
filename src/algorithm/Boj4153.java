package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj4153 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int[] arr = new int[3];
		
		while(true) {
			String[] str = br.readLine().split(" ");
			
			arr[0] = (Integer.parseInt(str[0])*Integer.parseInt(str[0]));
			arr[1] = (Integer.parseInt(str[1])*Integer.parseInt(str[1]));
			arr[2] = (Integer.parseInt(str[2])*Integer.parseInt(str[2]));
			
			if(arr[0]==0) {
				return;
			}
			else {
				
				if(arr[0]+arr[1]==arr[2]) {
					System.out.println("right");
				}else if(arr[1]+arr[2]==arr[0]) {
					System.out.println("right");
				}else if(arr[0]+arr[2]==arr[1]) {
					System.out.println("right");
				}else {
					System.out.println("wrong");
				}
			}
			
		}
		
	
	}

}
