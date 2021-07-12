package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Boj1316 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int count=0;
		int[] arr = new int[26];
		
		for(int i=0; i<N; i++) {
			System.out.println("오니?");
			int a = br.read();
		
			while(a>96) {
				arr[a-97]++;
				sb.append((char)a);
				a = br.read();
			}
			
			for(int q : arr) {
				System.out.println(q);
			}
			
			int len = arr.length;
			String s = sb.toString();
	
			for(int j=0; j<len; j++) {
				if(arr[j]>1) {
					char c = (char)(j+97);
					int check = s.indexOf(c, s.indexOf(c)+1);
					int index = s.indexOf(c);
					//System.out.println(c);
					//System.out.println("index:"+index);
					//System.out.println("check:"+check);
					if(index+1 !=check) {
						count++;
						
					}
					System.out.println("count:"+count);
				}
				
			}
			for(int v=0;v<26;v++) {
				arr[v]=0;
			}
		}		
		System.out.println(N-count);
		
	}

}
