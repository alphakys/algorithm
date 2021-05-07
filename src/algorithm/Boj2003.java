package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2003 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		
		int N= Integer.parseInt(str[0]);
		int M= Integer.parseInt(str[1]);
		
		String[] num = br.readLine().split(" ");
		
		int[] arr = new int[N];
		
		for(int i=0; i<arr.length; i++) {
			arr[i] = Integer.parseInt(num[i]);
		}
		
		int start= 0;
		int end = 0;
		
		int sum=0;
		int count = 0;
		
		for(int i=0;i<=arr.length;i++) {
			start = arr[i];
			sum+=start;
			System.out.println("start"+start);
			for(int j=i+1; j<=arr.length;j++) {
				
				sum+=end;
				System.out.println("i:"+i+" j:"+j);
				System.out.println("sum:"+sum);
				if(sum==M) {
					count++;
					sum=0;
					end=0;
					break;
				}
				else if(sum>M) {
					sum=0;
					
					break;
				}
				else {
					end=0;
					end +=arr[j];
				}
			}
		}
		System.out.println("count:"+count);
	}

}
