package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1436 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String six = new String("666");
		String six1 = new String("66");
		
		int N = Integer.parseInt(br.readLine());
		//                                										   
		// 666 1666 2666 3666 4666 5666 7666 8666 9666 10666 6660 6661 6662 6663 6664 6665 6666 6667 6668 6669
		// 11666 12666 13666 14666 15666 16660 16661 16662 16663 16664 16665 16666 16667 16668 16669 17666 18666 19666 20666
		// 21666 22666 100666 101666 106660 1000666 1006660	
		String[] arr = new String[10000];
		arr[0] = "666";
		
		for(int i=1;i<=5000;i++) {
			arr[i] = i+six;
			
			
			//System.out.println(arr[i]);
		}
		
		
		for(int i=5001;i<=10000;i++) {
			arr[i] = i+six;
			
			for(int j=0;j<10;j++) {
				arr[i] = six1+j;
			}
			
			//System.out.println(arr[i]);
		}
	}

}
