package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1085 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(" ");
		
		int x = Integer.parseInt(arr[0]);
		int y = Integer.parseInt(arr[1]);
		int w = Integer.parseInt(arr[2]);
		int h = Integer.parseInt(arr[3]);
		
		int[] nums = {x, w-x, y, h-y};
	
		int min = nums[0];

		for(int i=1; i<4; i++) {
			
			if(min>nums[i]) {
				min = nums[i];
			}
		}
		
		System.out.println(min);
		
	}

}
