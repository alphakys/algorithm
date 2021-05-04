package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class Boj2581 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int M = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		
		HashMap<Integer, Boolean> map = new HashMap<>();
		ArrayList<Integer> arr = new ArrayList<>();
		
		for(int j=M ; j<=N;j++) {
			
			for(int i=2;i<j; i++) {
				
				if((j%i)==0) {
					map.put(j, false);
					
					break;
				}
			}
			
			map.putIfAbsent(j, true);
			
		}
		
		int sum = 0;
		
		for(Entry<Integer, Boolean> entry : map.entrySet()) {
			int sosu = entry.getKey();
			
			if(entry.getValue()==true && sosu !=1) {
				
				arr.add(sosu);
				
				//System.out.println(sosu);
				sum += sosu;
				
			}
			
		}
		
		if(arr.isEmpty()) {
			System.out.println(-1);
		}else {
			System.out.println(sum);
		
			int min = arr.get(0);
		
			for(int sosu : arr) {
			
				if(min>sosu) {
					min = sosu;
				}
			}
		
			System.out.println(min);
		}
		
		
	}

}
