package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class String10809 {

	public static void main(String[] args)throws IOException {
		

		ArrayList<Integer> chArr = new ArrayList<>();	
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				
		String strArr[] = br.readLine().split("");
	
		
		for(int i=0; i< strArr.length; i++) {
			chArr.add((int)strArr[i].charAt(0));
		}
		
		for(int i=0; i<chArr.size(); i++) {
			
			int a = 97;
			
			if(chArr.get(i)==a) {
				
			}
		}
		
		

		
	}

}
