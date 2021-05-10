package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Boj3099 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int[] rect = new int[3];
		int[] rect1 = new int[3];
		
		ArrayList<Integer> arr = new ArrayList<>(4);
		ArrayList<Integer> arr1 = new ArrayList<>(4);
		
		for(int i=0; i<3; i++) {
			String str[] = br.readLine().split(" ");
			arr.add(Integer.parseInt(str[0]));
			arr1.add(Integer.parseInt(str[1]));
		
		}
		
		int equal = arr.get(0);
		if(arr.removeIf(n -> (equal-n==0))) {
			
			
			if(arr.size()==2) {
				sb.append(equal).append(" ");
			}else {
				sb.append(arr.get(0)).append(" ");
			}
		}
		
		int equal1 = arr1.get(0);
		if(arr1.removeIf(n -> (equal1-n==0))) {
			
			
			if(arr1.size()==2) {
				sb.append(equal1);
			}else {
				sb.append(arr1.get(0));
			}
		}
		
		
		
		System.out.println(sb.toString());
		
			
	}

}
