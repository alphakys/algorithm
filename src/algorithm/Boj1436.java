package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1436 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		//                            6    7										   16   17   18   19
		// 666 1666 2666 3666 4666 5666 6660 6661 6662 6663 6664 6665 6666 6667 6668 6669 7666 8666 9666 
		// 10666 11666 12666 13666 14666 15666 16660 16661 16662 16663 16664 16665 16666 16667 16668 16669 17666 18666 19666 
		
		if(N<7) {
			System.out.println();
		}
	}

}
