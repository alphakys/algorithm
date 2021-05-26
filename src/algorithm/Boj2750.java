package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;

public class Boj2750 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N];
		
		for(int i=0;i<N;i++) {
			int num = Integer.parseInt(br.readLine());
			
			arr[i] = num;
		}
		Arrays.sort(arr);
		
		for(int n : arr) {
			System.out.println(n);
		}
		
	}

}
